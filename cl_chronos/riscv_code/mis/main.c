/** $lic$
 * Copyright (C) 2014-2019 by Massachusetts Institute of Technology
 *
 * This file is part of the Chronos FPGA Acceleration Framework.
 *
 * Chronos is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, version 2.
 *
 * If you use this framework in your research, we request that you reference
 * the Chronos paper ("Chronos: Efficient Speculative Parallelism for
 * Accelerators", Abeydeera and Sanchez, ASPLOS-25, March 2020), and that
 * you send us a citation of your work.
 *
 * Chronos is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "../include/chronos.h"

// The location pointing to the base of each of the arrays
// const int ADDR_BASE_DATA = 5 << 2;
// const int ADDR_BASE_EDGE_OFFSET = 3 << 2;
// const int ADDR_BASE_NEIGHBORS = 4 << 2;

// const int ADDR_INIT_BASE_OFFSET = 8 << 2;
// const int ADDR_INIT_BASE_NEIGHBORS = 9 << 2;
// const int use_seq_number = 1;

//shirley: don't know how this works
const int ADDR_BASE_FLAGS = 3 << 2;
const int ADDR_BASE_NEIGHBORS = 4 << 2;
const int ADDR_BASE_DEGREE = 5 << 2;
const int ADDR_TOTAL_V = 1 << 2;


// int* gate_state;
// int* edge_offset;
// int* edge_neighbors;

// int* init_edge_neighbors;
// int* init_edge_offset;

// namespace mis {
// Global variables to reduce the number of task args
// typedef long intT;

// struct vertex {
//   long* Neighbors;
//   long degree;
//   void del() {free(Neighbors);}
//   vertex(long* N, long d) : Neighbors(N), degree(d) {}
// };

int* Flags;
//vertex* G;
//long** Neighbors;
int* Neighbors; //total_v * total_v
int* degree;
unsigned int total_v;
// }

// #define DES_TASK  0
// #define ENQUEUER_TASK  1

#define INITIAL_ENQUEUE_TASK 0
#define EXCLUDE_TASK 1
#define TASK_TASK 2
#define FILTER_TASK 3
#define ENQUEUER_TASK 4

void initial_enqueuer_task(uint ts, uint comp, uint start_v) {
    //enqueue 7 exclude tasks
    unsigned int v;
    for (v = start_v; v < start_v+7; v++) {
        if (v < total_v) {
            enq_task_arg1(TASK_TASK, v+1, v/*comp*/, v);
        }
    }
    //enqueue 1 enqueuer task
    if (v < total_v) {
        enq_task_arg1(INITIAL_ENQUEUE_TASK, ts, comp /*comp*/, v);
    }
}

void enqueuer_task(uint ts, uint comp, uint start_n, uint i) {
    int n = degree[i];
    int* neighbors = Neighbors + i*total_v;

    int ngh_cnt;

    //enqueue 7 exclude tasks
    for (ngh_cnt = start_n; ngh_cnt < start_n+7; ngh_cnt++) {
        if (ngh_cnt < n) {
            int ngh = neighbors[ngh_cnt];
            enq_task_arg1(EXCLUDE_TASK, ts, ngh /*comp*/, Flags + ngh);
        }
    }
    //enqueue 1 enqueuer task
    if (ngh_cnt < n) {
        enq_task_arg2(ENQUEUER_TASK, ts, comp /*comp*/, ngh_cnt, i);
    }
}

//shirley: TASK!
// inline void excludeIfNotFG(swarm::Timestamp, char* flag) {
inline void excludeIfNotFG(uint ts, uint comp, char* flag) {
  if (*flag != 2) {
    undo_log_write(&(*flag), *flag);
    *flag = 2;
  }
}

//shirley: TASK! 
//inline void task(swarm::Timestamp ts, uint i) {
inline void task(uint ts, uint comp, uint i) {
  if (Flags[i] == 0) {
    undo_log_write(&(Flags[i]), Flags[i]);
    Flags[i] = 1;

    //long n = G[i].degree;
    //long* neighbors = G[i].Neighbors;
    //long n = degree[i];
    //long* neighbors = Neighbors + i*total_v;

    enq_task_arg2(ENQUEUER_TASK, ts, comp /*comp*/, 0, i);


    // swarm::enqueue_all<EnqFlags(NOHINT | MAYSPEC)>(
    //         neighbors, neighbors + n, [] (swarm::Timestamp ts, long ngh) {
    //   enq_task_arg1(EXCLUDE_TASK, ts, ngh /*comp*/,
    //                   //{(reinterpret_cast<uintptr_t>(&Flags[ngh]) / 64), 1 << 6}, 
    //                   Flags + ngh);
    //   //swarm::enqueue(excludeIfNotFG, ts, vertex_hint(ngh), mis::Flags + ngh);
    // }, ts);
  } else if (Flags[i] == 2) {
    // vertex is already excluded.
  } else {
    //DEBUG("Incorrectly revisited an already included vertex");
  }
}

//shirley: TASK! not used...
//inline void filter(swarm::Timestamp, uint i, swarm::Timestamp dts) {
inline void filter(uint ts, uint comp, uint i, uint dts) {
  if (Flags[i] == 0) {
    enq_task_arg1(TASK_TASK, dts, i/*comp*/, i);
    //swarm::enqueue(task, dts, EnqFlags(SAMEHINT | MAYSPEC), i);
  } else {
    // We filtered out an excluded vertex using ordering (ts) less strict than
    // the deterministic ordering (dts).
  }
}

void main() {
    chronos_init();

    //shirley: don't know how this works
    Flags = (int*) ((*(int *) (ADDR_BASE_FLAGS))<<2) ;
    Neighbors = (int*) ((*(int *)(ADDR_BASE_NEIGHBORS))<<2) ;
    degree  = (int*) ((*(int *)(ADDR_BASE_DEGREE))<<2) ;
    total_v  = *(uint *)(ADDR_TOTAL_V) ;

    while (1) {
        uint ttype, ts, object, arg0, arg1;
        deq_task_arg1(&ttype, &ts, &object, &arg0);
        switch(ttype) {
            case INITIAL_ENQUEUE_TASK:
                initial_enqueuer_task(ts, object, arg0);
                break;
            case EXCLUDE_TASK:
                excludeIfNotFG(ts, object, arg0);
                break;
            case TASK_TASK:
                task(ts, object, arg0);
                break;
            case FILTER_TASK:
                filter(ts, object, arg0, arg1);
                break;
            case ENQUEUER_TASK:
                enqueuer_task(ts, object, arg0, arg1);
                break;
            default:
                break;
        }
        finish_task();
    }
}
