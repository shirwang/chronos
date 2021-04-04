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
Associated Filename: array_io.c
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

#include "math.h"
#include <string.h>

#define INITIAL_ENQUEUE_TASK 0
#define EXCLUDE_TASK 1
#define TASK_TASK 2
#define FILTER_TASK 3
#define ENQUEUER_TASK 4


void mis_hls (task_t task_in, hls::stream<task_t>* task_out, ap_uint<32>* l1, hls::stream<undo_log_t>* undo_log_entry) {
#pragma HLS PIPELINE II=15 enable_flush rewind
#pragma HLS INTERFACE axis port=undo_log_entry
#pragma HLS DATA_PACK variable=undo_log_entry
#pragma HLS INTERFACE m_axi depth=1000 port=l1
#pragma HLS DATA_PACK variable=task_in
#pragma HLS INTERFACE axis port=task_out
#pragma HLS DATA_PACK variable=task_out

	// HLS Does not support 64-bit addr
	// https://forums.xilinx.com/t5/Vivado-High-Level-Synthesis-HLS/Simple-question-how-to-get-64bit-addresses-on-ALL-AXI-busses/td-p/669669

	int i;

	static ap_uint<1> initialized = 0;
	static ap_int<32> base_flags;
	static ap_int<32> base_neighbor;
	static ap_int<32> base_degree;
	static ap_uint<32> total_v;

	if (!initialized) {
		initialized = 1;
		base_flags = l1[3];
		base_neighbor = l1[4];
		base_degree = l1[5];
		total_v = l1[1];
		//printf("base %d %d\n", base_offset, base_neighbor);
	}

	////////////////////////////// MIS //////////////////////////////
	if (task_in.ttype == INITIAL_ENQUEUE_TASK) {
		ap_uint<32> start_v = task_in.args.range(31,0);
		//enqueue 7 exclude tasks
	    ap_uint<32> v;
	    for (v = start_v; v < start_v+7; v++) {
	        if (v < total_v) {
	            //enqueue children task
				ap_uint<64> args_2;
				args_2.range(31,0) = v;
				task_t child = {v+1, v, TASK_TASK, args_2};
				task_out->write(child);
	        }
	    }
	    //enqueue 1 enqueuer task
	    if (v < total_v) {
	        //enqueue children task
			ap_uint<64> args_2;
			args_2.range(31,0) = v;
			task_t child = {task_in.ts, task_in.object, INITIAL_ENQUEUE_TASK, args_2};
			task_out->write(child);
	    }
	}
	if (task_in.ttype == EXCLUDE_TASK) {
		ap_uint<32> vid = task_in.object;
		ap_uint<32> ngh = task_in.args.range(31,0);
		if (l1[base_flags+ngh] != 2) {
			ap_uint<32> current_flag = l1[base_flags+ngh];
			l1[base_flags+ngh] = 2;
			// update undo log
			undo_log_t ulog;
			ulog.addr = (base_flags + ngh) << 2;
			ulog.data = current_flag;
			undo_log_entry->write(ulog);
		}
	}
	if (task_in.ttype == TASK_TASK) {
		ap_uint<32> vid = task_in.object;
		if (l1[base_flags +vid] == 0) {
			// update value
			l1[base_flags +vid] = 1;
			// update undo log
			undo_log_t ulog;
			ulog.addr = (base_flags + vid) << 2;
			ulog.data = 0;
			undo_log_entry->write(ulog);
			//enqueue children task
			ap_uint<64> args_2;
			args_2.range(31,0) = 0;
			args_2.range(63,32) = vid;
			task_t child = {task_in.ts, task_in.object, ENQUEUER_TASK, args_2};
			task_out->write(child);
		}
	}
	if (task_in.ttype == FILTER_TASK) {
		//this task is not used
	}
	if (task_in.ttype == ENQUEUER_TASK) {
		ap_uint<32> vid = task_in.object;
		ap_uint<32> start_n = task_in.args.range(31,0);
		ap_uint<32> i = task_in.args.range(63,32);

		ap_int<32> n = l1[base_degree +vid];
		ap_int<32> ngh_cnt;

	    //enqueue 7 exclude tasks
	    for (ngh_cnt = start_n; ngh_cnt < start_n+7; ngh_cnt++) {
	        if (ngh_cnt < n) {
	            ap_uint<32> ngh = l1[base_neighbor + i*total_v + ngh_cnt];
	        	//enqueue children task
	        	ap_uint<64> args_2;
	        	args_2.range(31,0) = ngh;
				task_t child = {task_in.ts, ngh, EXCLUDE_TASK, args_2};
				task_out->write(child);
	        }
	    }
	    //enqueue 1 enqueuer task
	    if (ngh_cnt < n) {
	    	//enqueue children task
			ap_uint<64> args_2;
			args_2.range(31,0) = ngh_cnt;
			args_2.range(63,32) = i;
			task_t child = {task_in.ts, task_in.object, ENQUEUER_TASK, args_2};
			task_out->write(child);
	    }
	}
}











