#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;



#define MAGIC_OP 0xdead

int* Flags;
int* Neighbors; //total_v * total_v
int* degree;
unsigned int total_v;

void insert_neighbor(int me, int my_neighbor) {
   int* nghs = Neighbors + me*total_v;
   for (unsigned int i = 0; i < total_v; i++) {
      if (nghs[i] == -1) {
         nghs[i] = my_neighbor;
         break;
      }
   }
}

bool neighbor_exist(int me, int my_neighbor) {
   int* nghs = Neighbors + me*total_v;
   bool exists = false;
   for (unsigned int i = 0; i < total_v; i++) {
      if (nghs[i] == -1) {
         break;
      }
      if (nghs[i] == my_neighbor) {
         exists = true;
         break;
      }
   }
   return exists;
}

int main()
{
   total_v = 10;
   double prob_edge = 0.6;
   // int total_e = (total_v * (total_v - 1) / 2) * prob;

   Flags = (int*) malloc(total_v * sizeof(int));
   memset(Flags, 0, total_v * sizeof(int));

   degree = (int*) malloc(total_v * sizeof(int));
   memset(degree, 0, total_v * sizeof(int));

   Neighbors = (int*) malloc(total_v * total_v * sizeof(int));
   for (unsigned int v = 0; v < (total_v * total_v); v++) {
      *(Neighbors+v) = -1;
   }

   // generate random edges
   srand (1755);
   double randnum;
   for (unsigned int v_row = 0; v_row < total_v; v_row++) {
      for (unsigned int v_col = 0; v_col < total_v; v_col++) {
         if (v_row == v_col) {
            continue;
         }
         randnum = rand() % 100;
         if (randnum < 100*prob_edge) {
            //add edge
            //check if already exist
            bool exist = neighbor_exist(v_row, v_col);
            if (!exist) {
               degree[v_row]++;
               degree[v_col]++;
               insert_neighbor(v_row, v_col);
               insert_neighbor(v_col, v_row);
            }

         }
      }
   }

   //print to file
   FILE* fp;
   char out_file[50] = "mis_graph";
   fp = fopen(out_file, "wb");
   printf("Writing file %s %p\n", out_file, fp);

   // all offsets are in units of uint32_t ( 4 bytes). i.e 16 per cache line

   int SIZE_FLAGS = ((total_v+15)/16)*16;
   int SIZE_NEIGHBORS = ((total_v*total_v+15)/16)*16;
   int SIZE_DEGREE = ((total_v+15)/16)*16;

   int BASE_FLAGS = 16;
   int BASE_NEIGHBORS = BASE_FLAGS + SIZE_FLAGS;
   int BASE_DEGREE = BASE_NEIGHBORS + SIZE_NEIGHBORS;

   int BASE_END = BASE_DEGREE + SIZE_DEGREE;

   uint32_t* data = (uint32_t*) calloc(BASE_END, sizeof(uint32_t));

   data[0] = MAGIC_OP;
   data[1] = numV;
   data[2] = 0;// numE;
   data[3] = BASE_FLAGS;
   data[4] = BASE_NEIGHBORS;
   data[5] = BASE_DEGREE;
   data[6] = 0;// BASE_GROUND_TRUTH;
   data[7] = 0;// startNode;
   data[8] = BASE_END;

   for (int i=0;i<9;i++) {
      printf("header %d: %d\n", i, data[i]);
   }

   for (int i=0;i<total_v;i++) {
      data[BASE_FLAGS +i] = 0;
      data[BASE_DEGREE +i] = degree[i];
   }

   for (int i=0;i<total_v*total_v;i++) {
      data[ BASE_NEIGHBORS +i ] = Neighbors[i];
   }

   printf("Writing file \n");
   fwrite(data, 4, BASE_END, fp);
   /*
   for (int i=0;i<BASE_END;i++) {
      fprintf(fp, "%08x\n", data[i]);
   } */
   fclose(fp);


   //calculate solution
   FILE* fp_result;
   char result_file[50] = "mis_graph_solution";
   fp_result = fopen(result_file, "wb");
   printf("Writing solution file %s %p\n", result_file, fp_result);

   //calculate result
   for (unsigned int v = 0; v < total_v; v++) {
      if (Flags[v] == 0) {
         Flags[v] = 1;
         int* my_nghs = Neighbors + v*total_v;
         for (unsigned int i = 0; i < degree[v]; i++) {
            if (Flags[my_nghs[i]] == 1) {
               printf("ERROR! My neighbor is also 1?!\n");
            }
            Flags[my_nghs[i]] = 2;
         }
      }
   }

   printf("sizeof(int) = %d\n", sizeof(int));
   fwrite(Flags, sizeof(int), total_v, fp_result);

   fclose(fp_result);

   //printing generated graph
   printf("DEGREES\n");
   for (unsigned int v = 0; v < total_v; v++) {
      printf("%d ", degree[v]);
   }
   printf("\n");
   printf("NEIGHBORS\n");
   for (unsigned int v = 0; v < total_v; v++) {
      for (unsigned int vv = 0; vv < total_v; vv++) {
         printf("%d ", Neighbors[v*total_v+vv]);
      }
      printf("\n");
   }
   printf("\n");


   // Checks if valid maximal independent set
   printf("VALIDATING RESULTS\n");
   for (unsigned int v = 0; v < total_v; v++) {
      if (Flags[v] == 0) {
         printf("ERROR: unvisited vertex %d!\n", v);
      }
      if (Flags[v] == 1) {
         int* my_nghs = Neighbors + v*total_v;
         for (unsigned int i = 0; i < degree[v]; i++) {
            if (Flags[my_nghs[i]] == 1) {
               printf("ERROR! Me: %d, My neighbor %d is also 1?!\n", v, my_nghs[i]);
            }
            if (Flags[my_nghs[i]] != 2) {
               printf("ERROR! Me: %d, my neighbor %d is not 2?!\n", v, my_nghs[i]);
            }
         }
      }
      if (Flags[v] == 2) {
         bool found_ngh = false;
         int* my_nghs = Neighbors + v*total_v;
         for (unsigned int i = 0; i < degree[v]; i++) {
            if (Flags[my_nghs[i]] == 1) {
               found_ngh = true;
               break;
            }
         }
         if (!found_ngh) {
            printf("ERROR! excluded vertex %d with no included neighbor\n", v);
         }
      }
   }

   free(data);
   free(Flags);
   free(Neighbors);
   free(degree);
   
}