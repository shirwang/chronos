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

/*******************************************************************************
Vendor: Xilinx
Associated Filename: array_io_test.c
Purpose: Vivado HLS tutorial example
Device: All
Revision History: March 1, 2013 - initial release

*******************************************************************************
Copyright 2008 - 2013 Xilinx, Inc. All rights reserved.

This file contains confidential and proprietary information of Xilinx, Inc. and
is protected under U.S. and international copyright and other intellectual
property laws.

DISCLAIMER
This disclaimer is not a license and does not grant any rights to the materials
distributed herewith. Except as otherwise provided in a valid license issued to
you by Xilinx, and to the maximum extent permitted by applicable law:
(1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL FAULTS, AND XILINX
HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY,
INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, OR
FITNESS FOR ANY PARTICULAR PURPOSE; and (2) Xilinx shall not be liable (whether
in contract or tort, including negligence, or under any other theory of
liability) for any loss or damage of any kind or nature related to, arising under
or in connection with these materials, including for any direct, or any indirect,
special, incidental, or consequential loss or damage (including loss of data,
profits, goodwill, or any type of loss or damage suffered as a result of any
action brought by a third party) even if such damage or loss was reasonably
foreseeable or Xilinx had been advised of the possibility of the same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-safe, or for use in any
application requiring fail-safe performance, such as life-support or safety
devices or systems, Class III medical devices, nuclear facilities, applications
related to the deployment of airbags, or any other applications that could lead
to death, personal injury, or severe property or environmental damage
(individually and collectively, "Critical Applications"). Customer asresultes the
sole risk and liability of any use of Xilinx products in Critical Applications,
subject only to applicable laws and regulations governing limitations on product
liability.

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE AT
ALL TIMES.

*******************************************************************************/
#include "mis.h"

#include "queue"

struct compare_node {
	bool operator() (const task_t &a, const task_t &b) const {
		return a.ts > b.ts;
	}
};

int main () {

	// Create input data
  task_t task_in = {0,0,0,0};
  hls::stream<undo_log_t> undo_log_entry;

  int i;


  std::priority_queue<task_t, std::vector<task_t>, compare_node > pq;

  ap_uint<32> mem[1024] = {0};
  FILE* fp = fopen("mis_graph", "r");
  printf("File %p\n", fp);

  // i=0;
  // while (!feof(fp)){
	 //  fscanf(fp, "%8x\n", &mem[i]);
	 //  //printf("File len %d %d\n", i, mem[i]);
	 //  i++;
  // }
     
  fseek (fp , 0 , SEEK_END);
  long lSize = ftell (fp);
  printf("File %p size %ld\n", fp, lSize);
  rewind (fp);
  fread( (void*) mem, 1, lSize, fp);
  for (int i=0;i<16;i++) {
      printf("headers %d %x \n", i, mem[i]);
  }
  fclose(fp);

  task_t initial_task = {0,0,0,0};
  pq.push(initial_task);

  while(!pq.empty()) {
	  task_t task_in = pq.top();
	  pq.pop();
	  printf("Dequeue (%d,%d)\n", int(task_in.ts), int(task_in.object));

	  hls::stream<task_t> task_out;
	  mis_hls(task_in, &task_out, mem, &undo_log_entry);

	  task_t out;
	  while(!task_out.empty()) {
		  out = task_out.read();
		  pq.push(out);
		  printf("\t Enqueue: (%d,%d)\n", int(out.ts), int(out.object));
	  }
  }

	// Return 0 if the test passes
  return 0;
}
