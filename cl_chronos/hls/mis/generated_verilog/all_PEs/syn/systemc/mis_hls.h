// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _mis_hls_HH_
#define _mis_hls_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "mis_hls_mul_32ns_bkb.h"
#include "mis_hls_l1_V_m_axi.h"

namespace ap_rtl {

template<unsigned int C_M_AXI_L1_V_ADDR_WIDTH = 32,
         unsigned int C_M_AXI_L1_V_ID_WIDTH = 1,
         unsigned int C_M_AXI_L1_V_AWUSER_WIDTH = 1,
         unsigned int C_M_AXI_L1_V_DATA_WIDTH = 32,
         unsigned int C_M_AXI_L1_V_WUSER_WIDTH = 1,
         unsigned int C_M_AXI_L1_V_ARUSER_WIDTH = 1,
         unsigned int C_M_AXI_L1_V_RUSER_WIDTH = 1,
         unsigned int C_M_AXI_L1_V_BUSER_WIDTH = 1>
struct mis_hls : public sc_module {
    // Port declarations 58
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst_n;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_in< sc_lv<132> > task_in;
    sc_out< sc_lv<136> > task_out_V_TDATA;
    sc_out< sc_logic > task_out_V_TVALID;
    sc_in< sc_logic > task_out_V_TREADY;
    sc_out< sc_logic > m_axi_l1_V_AWVALID;
    sc_in< sc_logic > m_axi_l1_V_AWREADY;
    sc_out< sc_uint<C_M_AXI_L1_V_ADDR_WIDTH> > m_axi_l1_V_AWADDR;
    sc_out< sc_uint<C_M_AXI_L1_V_ID_WIDTH> > m_axi_l1_V_AWID;
    sc_out< sc_lv<8> > m_axi_l1_V_AWLEN;
    sc_out< sc_lv<3> > m_axi_l1_V_AWSIZE;
    sc_out< sc_lv<2> > m_axi_l1_V_AWBURST;
    sc_out< sc_lv<2> > m_axi_l1_V_AWLOCK;
    sc_out< sc_lv<4> > m_axi_l1_V_AWCACHE;
    sc_out< sc_lv<3> > m_axi_l1_V_AWPROT;
    sc_out< sc_lv<4> > m_axi_l1_V_AWQOS;
    sc_out< sc_lv<4> > m_axi_l1_V_AWREGION;
    sc_out< sc_uint<C_M_AXI_L1_V_AWUSER_WIDTH> > m_axi_l1_V_AWUSER;
    sc_out< sc_logic > m_axi_l1_V_WVALID;
    sc_in< sc_logic > m_axi_l1_V_WREADY;
    sc_out< sc_uint<C_M_AXI_L1_V_DATA_WIDTH> > m_axi_l1_V_WDATA;
    sc_out< sc_uint<C_M_AXI_L1_V_DATA_WIDTH/8> > m_axi_l1_V_WSTRB;
    sc_out< sc_logic > m_axi_l1_V_WLAST;
    sc_out< sc_uint<C_M_AXI_L1_V_ID_WIDTH> > m_axi_l1_V_WID;
    sc_out< sc_uint<C_M_AXI_L1_V_WUSER_WIDTH> > m_axi_l1_V_WUSER;
    sc_out< sc_logic > m_axi_l1_V_ARVALID;
    sc_in< sc_logic > m_axi_l1_V_ARREADY;
    sc_out< sc_uint<C_M_AXI_L1_V_ADDR_WIDTH> > m_axi_l1_V_ARADDR;
    sc_out< sc_uint<C_M_AXI_L1_V_ID_WIDTH> > m_axi_l1_V_ARID;
    sc_out< sc_lv<8> > m_axi_l1_V_ARLEN;
    sc_out< sc_lv<3> > m_axi_l1_V_ARSIZE;
    sc_out< sc_lv<2> > m_axi_l1_V_ARBURST;
    sc_out< sc_lv<2> > m_axi_l1_V_ARLOCK;
    sc_out< sc_lv<4> > m_axi_l1_V_ARCACHE;
    sc_out< sc_lv<3> > m_axi_l1_V_ARPROT;
    sc_out< sc_lv<4> > m_axi_l1_V_ARQOS;
    sc_out< sc_lv<4> > m_axi_l1_V_ARREGION;
    sc_out< sc_uint<C_M_AXI_L1_V_ARUSER_WIDTH> > m_axi_l1_V_ARUSER;
    sc_in< sc_logic > m_axi_l1_V_RVALID;
    sc_out< sc_logic > m_axi_l1_V_RREADY;
    sc_in< sc_uint<C_M_AXI_L1_V_DATA_WIDTH> > m_axi_l1_V_RDATA;
    sc_in< sc_logic > m_axi_l1_V_RLAST;
    sc_in< sc_uint<C_M_AXI_L1_V_ID_WIDTH> > m_axi_l1_V_RID;
    sc_in< sc_uint<C_M_AXI_L1_V_RUSER_WIDTH> > m_axi_l1_V_RUSER;
    sc_in< sc_lv<2> > m_axi_l1_V_RRESP;
    sc_in< sc_logic > m_axi_l1_V_BVALID;
    sc_out< sc_logic > m_axi_l1_V_BREADY;
    sc_in< sc_lv<2> > m_axi_l1_V_BRESP;
    sc_in< sc_uint<C_M_AXI_L1_V_ID_WIDTH> > m_axi_l1_V_BID;
    sc_in< sc_uint<C_M_AXI_L1_V_BUSER_WIDTH> > m_axi_l1_V_BUSER;
    sc_out< sc_lv<64> > undo_log_entry_V_TDATA;
    sc_out< sc_logic > undo_log_entry_V_TVALID;
    sc_in< sc_logic > undo_log_entry_V_TREADY;
    sc_signal< sc_logic > ap_var_for_const0;
    sc_signal< sc_logic > ap_var_for_const6;
    sc_signal< sc_lv<1> > ap_var_for_const1;
    sc_signal< sc_lv<32> > ap_var_for_const2;
    sc_signal< sc_lv<3> > ap_var_for_const3;
    sc_signal< sc_lv<2> > ap_var_for_const4;
    sc_signal< sc_lv<4> > ap_var_for_const5;
    sc_signal< sc_lv<4> > ap_var_for_const7;


    // Module declarations
    mis_hls(sc_module_name name);
    SC_HAS_PROCESS(mis_hls);

    ~mis_hls();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    mis_hls_l1_V_m_axi<0,32,32,5,16,16,16,16,C_M_AXI_L1_V_ID_WIDTH,C_M_AXI_L1_V_ADDR_WIDTH,C_M_AXI_L1_V_DATA_WIDTH,C_M_AXI_L1_V_AWUSER_WIDTH,C_M_AXI_L1_V_ARUSER_WIDTH,C_M_AXI_L1_V_WUSER_WIDTH,C_M_AXI_L1_V_RUSER_WIDTH,C_M_AXI_L1_V_BUSER_WIDTH,C_M_AXI_L1_V_TARGET_ADDR,C_M_AXI_L1_V_USER_VALUE,C_M_AXI_L1_V_PROT_VALUE,C_M_AXI_L1_V_CACHE_VALUE>* mis_hls_l1_V_m_axi_U;
    mis_hls_mul_32ns_bkb<1,5,32,32,64>* mis_hls_mul_32ns_bkb_U1;
    regslice_both<136>* regslice_both_task_out_V_U;
    regslice_both<64>* regslice_both_undo_log_entry_V_U;
    sc_signal< sc_logic > ap_rst_n_inv;
    sc_signal< sc_lv<67> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<1> > initialized_V;
    sc_signal< sc_lv<32> > base_flags_V;
    sc_signal< sc_lv<32> > total_v_V;
    sc_signal< sc_lv<32> > base_neighbor_V;
    sc_signal< sc_lv<32> > base_degree_V;
    sc_signal< sc_logic > task_out_V_TDATA_blk_n;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_lv<1> > icmp_ln887_fu_456_p2;
    sc_signal< sc_lv<1> > icmp_ln887_1_fu_461_p2;
    sc_signal< sc_logic > ap_CS_fsm_state14;
    sc_signal< sc_lv<1> > icmp_ln887_1_reg_980;
    sc_signal< sc_lv<1> > icmp_ln887_2_fu_504_p2;
    sc_signal< sc_logic > ap_CS_fsm_state15;
    sc_signal< sc_lv<1> > icmp_ln879_reg_956;
    sc_signal< sc_lv<1> > icmp_ln887_2_reg_989;
    sc_signal< sc_logic > ap_CS_fsm_state42;
    sc_signal< sc_logic > ap_CS_fsm_state43;
    sc_signal< sc_logic > ap_CS_fsm_state65;
    sc_signal< sc_logic > ap_CS_fsm_state66;
    sc_signal< sc_lv<1> > icmp_ln887_4_reg_1130;
    sc_signal< sc_logic > ap_CS_fsm_state56;
    sc_signal< sc_lv<1> > icmp_ln887_3_fu_778_p2;
    sc_signal< sc_lv<1> > icmp_ln887_5_fu_809_p2;
    sc_signal< sc_logic > ap_CS_fsm_state67;
    sc_signal< sc_lv<1> > icmp_ln879_4_reg_1069;
    sc_signal< sc_lv<1> > icmp_ln887_5_reg_1144;
    sc_signal< sc_logic > l1_V_blk_n_AR;
    sc_signal< sc_lv<1> > initialized_V_load_load_fu_351_p1;
    sc_signal< sc_logic > l1_V_blk_n_R;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_logic > ap_CS_fsm_state16;
    sc_signal< sc_logic > ap_CS_fsm_state23;
    sc_signal< sc_logic > l1_V_blk_n_AW;
    sc_signal< sc_logic > ap_CS_fsm_state25;
    sc_signal< sc_logic > l1_V_blk_n_W;
    sc_signal< sc_logic > ap_CS_fsm_state26;
    sc_signal< sc_logic > l1_V_blk_n_B;
    sc_signal< sc_logic > ap_CS_fsm_state31;
    sc_signal< sc_lv<1> > icmp_ln879_1_reg_1003;
    sc_signal< sc_lv<1> > icmp_ln883_reg_1020;
    sc_signal< sc_logic > ap_CS_fsm_state32;
    sc_signal< sc_logic > ap_CS_fsm_state39;
    sc_signal< sc_logic > ap_CS_fsm_state41;
    sc_signal< sc_logic > ap_CS_fsm_state47;
    sc_signal< sc_lv<1> > icmp_ln879_2_reg_1029;
    sc_signal< sc_lv<1> > icmp_ln879_3_reg_1050;
    sc_signal< sc_logic > ap_CS_fsm_state48;
    sc_signal< sc_logic > ap_CS_fsm_state55;
    sc_signal< sc_logic > ap_CS_fsm_state58;
    sc_signal< sc_logic > undo_log_entry_V_TDATA_blk_n;
    sc_signal< sc_logic > ap_CS_fsm_state27;
    sc_signal< sc_logic > l1_V_AWVALID;
    sc_signal< sc_logic > l1_V_AWREADY;
    sc_signal< sc_lv<32> > l1_V_AWADDR;
    sc_signal< sc_logic > l1_V_WVALID;
    sc_signal< sc_logic > l1_V_WREADY;
    sc_signal< sc_lv<32> > l1_V_WDATA;
    sc_signal< sc_logic > l1_V_ARVALID;
    sc_signal< sc_logic > l1_V_ARREADY;
    sc_signal< sc_lv<32> > l1_V_ARADDR;
    sc_signal< sc_logic > l1_V_RVALID;
    sc_signal< sc_logic > l1_V_RREADY;
    sc_signal< sc_lv<32> > l1_V_RDATA;
    sc_signal< sc_logic > l1_V_RLAST;
    sc_signal< sc_lv<1> > l1_V_RID;
    sc_signal< sc_lv<1> > l1_V_RUSER;
    sc_signal< sc_lv<2> > l1_V_RRESP;
    sc_signal< sc_logic > l1_V_BVALID;
    sc_signal< sc_logic > l1_V_BREADY;
    sc_signal< sc_lv<2> > l1_V_BRESP;
    sc_signal< sc_lv<1> > l1_V_BID;
    sc_signal< sc_lv<1> > l1_V_BUSER;
    sc_signal< sc_lv<32> > grp_fu_320_p4;
    sc_signal< sc_lv<32> > reg_345;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_lv<1> > icmp_ln879_fu_430_p2;
    sc_signal< sc_logic > ap_CS_fsm_state54;
    sc_signal< bool > ap_block_state1_io;
    sc_signal< sc_lv<1> > initialized_V_load_reg_901;
    sc_signal< sc_lv<32> > l1_V_addr_read_reg_939;
    sc_signal< sc_lv<32> > l1_V_addr_3_read_reg_944;
    sc_signal< sc_lv<4> > task_in_ttype_V_load_fu_421_p4;
    sc_signal< sc_lv<4> > task_in_ttype_V_load_reg_949;
    sc_signal< sc_lv<33> > ret_V_fu_440_p2;
    sc_signal< sc_lv<33> > ret_V_reg_966;
    sc_signal< sc_lv<32> > v_V_fu_446_p2;
    sc_signal< sc_lv<32> > v_V_reg_971;
    sc_signal< bool > ap_predicate_op146_write_state13;
    sc_signal< bool > ap_predicate_op154_write_state13;
    sc_signal< bool > ap_block_state13_io;
    sc_signal< sc_lv<136> > sext_ln177_fu_494_p1;
    sc_signal< sc_lv<136> > sext_ln177_1_fu_533_p1;
    sc_signal< sc_lv<32> > grp_fu_329_p2;
    sc_signal< bool > ap_block_state14_io;
    sc_signal< sc_lv<1> > icmp_ln879_1_fu_538_p2;
    sc_signal< bool > ap_predicate_op159_write_state15;
    sc_signal< bool > ap_block_state15_io;
    sc_signal< sc_lv<32> > l1_V_addr_4_reg_1007;
    sc_signal< sc_lv<32> > current_flag_V_reg_1014;
    sc_signal< sc_lv<1> > icmp_ln883_fu_567_p2;
    sc_signal< sc_logic > ap_CS_fsm_state24;
    sc_signal< sc_lv<64> > tmp_2_fu_591_p4;
    sc_signal< bool > ap_block_state26_io;
    sc_signal< sc_lv<1> > icmp_ln879_2_fu_601_p2;
    sc_signal< bool > ap_predicate_op192_writeresp_state31;
    sc_signal< bool > ap_block_state31;
    sc_signal< sc_lv<32> > grp_fu_336_p4;
    sc_signal< sc_lv<32> > vid_V_reg_1033;
    sc_signal< sc_lv<32> > l1_V_addr_5_reg_1038;
    sc_signal< sc_lv<32> > cur_flag_V_reg_1045;
    sc_signal< sc_lv<1> > icmp_ln879_3_fu_630_p2;
    sc_signal< sc_logic > ap_CS_fsm_state40;
    sc_signal< sc_lv<30> > trunc_ln1503_1_fu_635_p1;
    sc_signal< sc_lv<30> > trunc_ln1503_1_reg_1054;
    sc_signal< sc_lv<64> > tmp_3_fu_653_p4;
    sc_signal< bool > ap_block_state42_io;
    sc_signal< sc_lv<136> > sext_ln177_2_fu_676_p1;
    sc_signal< sc_lv<1> > icmp_ln879_4_fu_681_p2;
    sc_signal< bool > ap_predicate_op230_writeresp_state47;
    sc_signal< bool > ap_block_state47;
    sc_signal< sc_lv<32> > l1_V_addr_6_reg_1079;
    sc_signal< sc_lv<32> > i_V_fu_714_p4;
    sc_signal< sc_lv<32> > i_V_reg_1085;
    sc_signal< sc_logic > ap_CS_fsm_state51;
    sc_signal< sc_lv<33> > ret_V_4_fu_741_p2;
    sc_signal< sc_lv<33> > ret_V_4_reg_1100;
    sc_signal< sc_lv<32> > n_V_reg_1105;
    sc_signal< sc_lv<34> > zext_ln177_1_fu_747_p1;
    sc_signal< sc_lv<34> > zext_ln177_1_reg_1111;
    sc_signal< sc_lv<32> > ngh_cnt_V_fu_766_p3;
    sc_signal< sc_lv<32> > ngh_cnt_V_reg_1116;
    sc_signal< sc_lv<64> > grp_fu_731_p2;
    sc_signal< sc_lv<64> > ret_V_5_reg_1122;
    sc_signal< sc_lv<1> > icmp_ln887_4_fu_783_p2;
    sc_signal< bool > ap_predicate_op284_write_state56;
    sc_signal< bool > ap_block_state56_io;
    sc_signal< sc_lv<33> > add_ln544_fu_800_p2;
    sc_signal< sc_lv<33> > add_ln544_reg_1134;
    sc_signal< sc_lv<32> > child_ts_V_1_fu_806_p1;
    sc_signal< sc_lv<32> > child_ts_V_1_reg_1139;
    sc_signal< sc_lv<136> > sext_ln177_4_fu_826_p1;
    sc_signal< sc_lv<32> > l1_V_addr_7_reg_1153;
    sc_signal< sc_logic > ap_CS_fsm_state57;
    sc_signal< sc_lv<136> > sext_ln177_3_fu_871_p1;
    sc_signal< sc_lv<32> > ngh_cnt_V_1_fu_881_p2;
    sc_signal< bool > ap_block_state66_io;
    sc_signal< sc_lv<32> > base_flags_V_loc_0_reg_280;
    sc_signal< sc_lv<32> > total_v_V_loc_0_reg_290;
    sc_signal< sc_lv<32> > ap_phi_mux_child_object_V_phi_fu_303_p4;
    sc_signal< sc_lv<32> > child_object_V_reg_300;
    sc_signal< sc_lv<32> > t_V_1_reg_310;
    sc_signal< sc_lv<64> > sext_ln544_fu_557_p1;
    sc_signal< sc_lv<64> > sext_ln544_1_fu_620_p1;
    sc_signal< sc_lv<64> > sext_ln544_2_fu_704_p1;
    sc_signal< sc_lv<64> > add_ln544_1_fu_834_p2;
    sc_signal< sc_lv<64> > p_Val2_s_fu_134;
    sc_signal< sc_lv<64> > p_Result_s_fu_470_p5;
    sc_signal< sc_lv<64> > p_Val2_1_fu_138;
    sc_signal< sc_lv<64> > p_Result_2_fu_848_p5;
    sc_signal< sc_lv<32> > grp_fu_329_p0;
    sc_signal< sc_lv<33> > zext_ln115_fu_436_p1;
    sc_signal< sc_lv<33> > zext_ln887_fu_452_p1;
    sc_signal< sc_lv<132> > tmp_fu_482_p5;
    sc_signal< sc_lv<64> > p_Result_1_fu_509_p5;
    sc_signal< sc_lv<64> > trunc_ln176_fu_520_p1;
    sc_signal< sc_lv<132> > tmp_1_fu_523_p4;
    sc_signal< sc_lv<34> > lhs_V_fu_543_p1;
    sc_signal< sc_lv<34> > rhs_V_fu_547_p1;
    sc_signal< sc_lv<34> > ret_V_1_fu_551_p2;
    sc_signal< sc_lv<30> > trunc_ln1503_fu_572_p1;
    sc_signal< sc_lv<30> > tmp_9_fu_576_p4;
    sc_signal< sc_lv<30> > add_ln1503_fu_585_p2;
    sc_signal< sc_lv<34> > lhs_V_1_fu_606_p1;
    sc_signal< sc_lv<34> > rhs_V_1_fu_610_p1;
    sc_signal< sc_lv<34> > ret_V_2_fu_614_p2;
    sc_signal< sc_lv<30> > tmp_s_fu_639_p4;
    sc_signal< sc_lv<30> > add_ln1503_1_fu_648_p2;
    sc_signal< sc_lv<64> > trunc_ln176_1_fu_664_p1;
    sc_signal< sc_lv<132> > tmp_4_fu_667_p4;
    sc_signal< sc_lv<34> > lhs_V_2_fu_690_p1;
    sc_signal< sc_lv<34> > rhs_V_2_fu_694_p1;
    sc_signal< sc_lv<34> > ret_V_3_fu_698_p2;
    sc_signal< sc_lv<32> > grp_fu_731_p0;
    sc_signal< sc_lv<32> > grp_fu_731_p1;
    sc_signal< sc_lv<32> > zext_ln177_fu_737_p0;
    sc_signal< sc_lv<33> > zext_ln177_fu_737_p1;
    sc_signal< sc_lv<32> > empty_fu_750_p0;
    sc_signal< sc_lv<34> > empty_fu_750_p1;
    sc_signal< sc_lv<32> > empty_9_fu_760_p0;
    sc_signal< sc_lv<1> > empty_8_fu_754_p2;
    sc_signal< sc_lv<32> > empty_9_fu_760_p2;
    sc_signal< sc_lv<32> > ngh_cnt_V_fu_766_p2;
    sc_signal< sc_lv<34> > sext_ln887_fu_774_p1;
    sc_signal< sc_lv<33> > sext_ln544_3_fu_792_p1;
    sc_signal< sc_lv<33> > sext_ln544_4_fu_796_p1;
    sc_signal< sc_lv<64> > trunc_ln176_2_fu_813_p1;
    sc_signal< sc_lv<132> > tmp_6_fu_816_p5;
    sc_signal< sc_lv<64> > sext_ln544_5_fu_831_p1;
    sc_signal< sc_lv<132> > tmp_5_fu_860_p5;
    sc_signal< sc_logic > grp_fu_731_ce;
    sc_signal< sc_logic > ap_CS_fsm_state52;
    sc_signal< sc_logic > ap_CS_fsm_state53;
    sc_signal< sc_logic > regslice_both_task_out_V_U_apdone_blk;
    sc_signal< sc_logic > regslice_both_undo_log_entry_V_U_apdone_blk;
    sc_signal< bool > ap_block_state67;
    sc_signal< bool > ap_predicate_op306_write_state67;
    sc_signal< bool > ap_block_state67_io;
    sc_signal< sc_lv<67> > ap_NS_fsm;
    sc_signal< bool > ap_block_state43_io;
    sc_signal< sc_lv<136> > task_out_V_TDATA_int;
    sc_signal< sc_logic > task_out_V_TVALID_int;
    sc_signal< sc_logic > task_out_V_TREADY_int;
    sc_signal< sc_logic > regslice_both_task_out_V_U_vld_out;
    sc_signal< sc_lv<64> > undo_log_entry_V_TDATA_int;
    sc_signal< sc_logic > undo_log_entry_V_TVALID_int;
    sc_signal< sc_logic > undo_log_entry_V_TREADY_int;
    sc_signal< sc_logic > regslice_both_undo_log_entry_V_U_vld_out;
    sc_signal< sc_lv<64> > grp_fu_731_p00;
    sc_signal< sc_lv<64> > grp_fu_731_p10;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<67> ap_ST_fsm_state1;
    static const sc_lv<67> ap_ST_fsm_state2;
    static const sc_lv<67> ap_ST_fsm_state3;
    static const sc_lv<67> ap_ST_fsm_state4;
    static const sc_lv<67> ap_ST_fsm_state5;
    static const sc_lv<67> ap_ST_fsm_state6;
    static const sc_lv<67> ap_ST_fsm_state7;
    static const sc_lv<67> ap_ST_fsm_state8;
    static const sc_lv<67> ap_ST_fsm_state9;
    static const sc_lv<67> ap_ST_fsm_state10;
    static const sc_lv<67> ap_ST_fsm_state11;
    static const sc_lv<67> ap_ST_fsm_state12;
    static const sc_lv<67> ap_ST_fsm_state13;
    static const sc_lv<67> ap_ST_fsm_state14;
    static const sc_lv<67> ap_ST_fsm_state15;
    static const sc_lv<67> ap_ST_fsm_state16;
    static const sc_lv<67> ap_ST_fsm_state17;
    static const sc_lv<67> ap_ST_fsm_state18;
    static const sc_lv<67> ap_ST_fsm_state19;
    static const sc_lv<67> ap_ST_fsm_state20;
    static const sc_lv<67> ap_ST_fsm_state21;
    static const sc_lv<67> ap_ST_fsm_state22;
    static const sc_lv<67> ap_ST_fsm_state23;
    static const sc_lv<67> ap_ST_fsm_state24;
    static const sc_lv<67> ap_ST_fsm_state25;
    static const sc_lv<67> ap_ST_fsm_state26;
    static const sc_lv<67> ap_ST_fsm_state27;
    static const sc_lv<67> ap_ST_fsm_state28;
    static const sc_lv<67> ap_ST_fsm_state29;
    static const sc_lv<67> ap_ST_fsm_state30;
    static const sc_lv<67> ap_ST_fsm_state31;
    static const sc_lv<67> ap_ST_fsm_state32;
    static const sc_lv<67> ap_ST_fsm_state33;
    static const sc_lv<67> ap_ST_fsm_state34;
    static const sc_lv<67> ap_ST_fsm_state35;
    static const sc_lv<67> ap_ST_fsm_state36;
    static const sc_lv<67> ap_ST_fsm_state37;
    static const sc_lv<67> ap_ST_fsm_state38;
    static const sc_lv<67> ap_ST_fsm_state39;
    static const sc_lv<67> ap_ST_fsm_state40;
    static const sc_lv<67> ap_ST_fsm_state41;
    static const sc_lv<67> ap_ST_fsm_state42;
    static const sc_lv<67> ap_ST_fsm_state43;
    static const sc_lv<67> ap_ST_fsm_state44;
    static const sc_lv<67> ap_ST_fsm_state45;
    static const sc_lv<67> ap_ST_fsm_state46;
    static const sc_lv<67> ap_ST_fsm_state47;
    static const sc_lv<67> ap_ST_fsm_state48;
    static const sc_lv<67> ap_ST_fsm_state49;
    static const sc_lv<67> ap_ST_fsm_state50;
    static const sc_lv<67> ap_ST_fsm_state51;
    static const sc_lv<67> ap_ST_fsm_state52;
    static const sc_lv<67> ap_ST_fsm_state53;
    static const sc_lv<67> ap_ST_fsm_state54;
    static const sc_lv<67> ap_ST_fsm_state55;
    static const sc_lv<67> ap_ST_fsm_state56;
    static const sc_lv<67> ap_ST_fsm_state57;
    static const sc_lv<67> ap_ST_fsm_state58;
    static const sc_lv<67> ap_ST_fsm_state59;
    static const sc_lv<67> ap_ST_fsm_state60;
    static const sc_lv<67> ap_ST_fsm_state61;
    static const sc_lv<67> ap_ST_fsm_state62;
    static const sc_lv<67> ap_ST_fsm_state63;
    static const sc_lv<67> ap_ST_fsm_state64;
    static const sc_lv<67> ap_ST_fsm_state65;
    static const sc_lv<67> ap_ST_fsm_state66;
    static const sc_lv<67> ap_ST_fsm_state67;
    static const sc_lv<32> ap_const_lv32_0;
    static const bool ap_const_boolean_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<32> ap_const_lv32_29;
    static const sc_lv<32> ap_const_lv32_2A;
    static const sc_lv<32> ap_const_lv32_40;
    static const sc_lv<32> ap_const_lv32_41;
    static const sc_lv<32> ap_const_lv32_37;
    static const sc_lv<32> ap_const_lv32_42;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<32> ap_const_lv32_16;
    static const sc_lv<32> ap_const_lv32_18;
    static const sc_lv<32> ap_const_lv32_19;
    static const sc_lv<32> ap_const_lv32_1E;
    static const sc_lv<32> ap_const_lv32_1F;
    static const sc_lv<32> ap_const_lv32_26;
    static const sc_lv<32> ap_const_lv32_28;
    static const sc_lv<32> ap_const_lv32_2E;
    static const sc_lv<32> ap_const_lv32_2F;
    static const sc_lv<32> ap_const_lv32_36;
    static const sc_lv<32> ap_const_lv32_39;
    static const sc_lv<32> ap_const_lv32_1A;
    static const int C_M_AXI_L1_V_TARGET_ADDR;
    static const int C_M_AXI_L1_V_USER_VALUE;
    static const int C_M_AXI_L1_V_PROT_VALUE;
    static const int C_M_AXI_L1_V_CACHE_VALUE;
    static const int C_M_AXI_DATA_WIDTH;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_35;
    static const bool ap_const_boolean_0;
    static const sc_lv<32> ap_const_lv32_17;
    static const sc_lv<32> ap_const_lv32_27;
    static const sc_lv<32> ap_const_lv32_32;
    static const sc_lv<32> ap_const_lv32_38;
    static const sc_lv<64> ap_const_lv64_3;
    static const sc_lv<64> ap_const_lv64_4;
    static const sc_lv<64> ap_const_lv64_5;
    static const sc_lv<64> ap_const_lv64_1;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<2> ap_const_lv2_0;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<4> ap_const_lv4_F;
    static const sc_lv<32> ap_const_lv32_44;
    static const sc_lv<32> ap_const_lv32_63;
    static const sc_lv<32> ap_const_lv32_20;
    static const sc_lv<32> ap_const_lv32_3F;
    static const sc_lv<32> ap_const_lv32_43;
    static const sc_lv<33> ap_const_lv33_7;
    static const sc_lv<4> ap_const_lv4_2;
    static const sc_lv<64> ap_const_lv64_0;
    static const sc_lv<4> ap_const_lv4_1;
    static const sc_lv<32> ap_const_lv32_61;
    static const sc_lv<32> ap_const_lv32_3D;
    static const sc_lv<36> ap_const_lv36_4;
    static const sc_lv<4> ap_const_lv4_4;
    static const sc_lv<32> ap_const_lv32_64;
    static const sc_lv<32> ap_const_lv32_83;
    static const sc_lv<32> ap_const_lv32_33;
    static const sc_lv<32> ap_const_lv32_34;
    // Thread declarations
    void thread_ap_var_for_const0();
    void thread_ap_var_for_const6();
    void thread_ap_var_for_const1();
    void thread_ap_var_for_const2();
    void thread_ap_var_for_const3();
    void thread_ap_var_for_const4();
    void thread_ap_var_for_const5();
    void thread_ap_var_for_const7();
    void thread_ap_clk_no_reset_();
    void thread_add_ln1503_1_fu_648_p2();
    void thread_add_ln1503_fu_585_p2();
    void thread_add_ln544_1_fu_834_p2();
    void thread_add_ln544_fu_800_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state12();
    void thread_ap_CS_fsm_state13();
    void thread_ap_CS_fsm_state14();
    void thread_ap_CS_fsm_state15();
    void thread_ap_CS_fsm_state16();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state23();
    void thread_ap_CS_fsm_state24();
    void thread_ap_CS_fsm_state25();
    void thread_ap_CS_fsm_state26();
    void thread_ap_CS_fsm_state27();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state31();
    void thread_ap_CS_fsm_state32();
    void thread_ap_CS_fsm_state39();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state40();
    void thread_ap_CS_fsm_state41();
    void thread_ap_CS_fsm_state42();
    void thread_ap_CS_fsm_state43();
    void thread_ap_CS_fsm_state47();
    void thread_ap_CS_fsm_state48();
    void thread_ap_CS_fsm_state51();
    void thread_ap_CS_fsm_state52();
    void thread_ap_CS_fsm_state53();
    void thread_ap_CS_fsm_state54();
    void thread_ap_CS_fsm_state55();
    void thread_ap_CS_fsm_state56();
    void thread_ap_CS_fsm_state57();
    void thread_ap_CS_fsm_state58();
    void thread_ap_CS_fsm_state65();
    void thread_ap_CS_fsm_state66();
    void thread_ap_CS_fsm_state67();
    void thread_ap_CS_fsm_state8();
    void thread_ap_CS_fsm_state9();
    void thread_ap_block_state13_io();
    void thread_ap_block_state14_io();
    void thread_ap_block_state15_io();
    void thread_ap_block_state1_io();
    void thread_ap_block_state26_io();
    void thread_ap_block_state31();
    void thread_ap_block_state42_io();
    void thread_ap_block_state43_io();
    void thread_ap_block_state47();
    void thread_ap_block_state56_io();
    void thread_ap_block_state66_io();
    void thread_ap_block_state67();
    void thread_ap_block_state67_io();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_phi_mux_child_object_V_phi_fu_303_p4();
    void thread_ap_predicate_op146_write_state13();
    void thread_ap_predicate_op154_write_state13();
    void thread_ap_predicate_op159_write_state15();
    void thread_ap_predicate_op192_writeresp_state31();
    void thread_ap_predicate_op230_writeresp_state47();
    void thread_ap_predicate_op284_write_state56();
    void thread_ap_predicate_op306_write_state67();
    void thread_ap_ready();
    void thread_ap_rst_n_inv();
    void thread_child_ts_V_1_fu_806_p1();
    void thread_empty_8_fu_754_p2();
    void thread_empty_9_fu_760_p0();
    void thread_empty_9_fu_760_p2();
    void thread_empty_fu_750_p0();
    void thread_empty_fu_750_p1();
    void thread_grp_fu_320_p4();
    void thread_grp_fu_329_p0();
    void thread_grp_fu_329_p2();
    void thread_grp_fu_336_p4();
    void thread_grp_fu_731_ce();
    void thread_grp_fu_731_p0();
    void thread_grp_fu_731_p00();
    void thread_grp_fu_731_p1();
    void thread_grp_fu_731_p10();
    void thread_i_V_fu_714_p4();
    void thread_icmp_ln879_1_fu_538_p2();
    void thread_icmp_ln879_2_fu_601_p2();
    void thread_icmp_ln879_3_fu_630_p2();
    void thread_icmp_ln879_4_fu_681_p2();
    void thread_icmp_ln879_fu_430_p2();
    void thread_icmp_ln883_fu_567_p2();
    void thread_icmp_ln887_1_fu_461_p2();
    void thread_icmp_ln887_2_fu_504_p2();
    void thread_icmp_ln887_3_fu_778_p2();
    void thread_icmp_ln887_4_fu_783_p2();
    void thread_icmp_ln887_5_fu_809_p2();
    void thread_icmp_ln887_fu_456_p2();
    void thread_initialized_V_load_load_fu_351_p1();
    void thread_l1_V_ARADDR();
    void thread_l1_V_ARVALID();
    void thread_l1_V_AWADDR();
    void thread_l1_V_AWVALID();
    void thread_l1_V_BREADY();
    void thread_l1_V_RREADY();
    void thread_l1_V_WDATA();
    void thread_l1_V_WVALID();
    void thread_l1_V_blk_n_AR();
    void thread_l1_V_blk_n_AW();
    void thread_l1_V_blk_n_B();
    void thread_l1_V_blk_n_R();
    void thread_l1_V_blk_n_W();
    void thread_lhs_V_1_fu_606_p1();
    void thread_lhs_V_2_fu_690_p1();
    void thread_lhs_V_fu_543_p1();
    void thread_ngh_cnt_V_1_fu_881_p2();
    void thread_ngh_cnt_V_fu_766_p2();
    void thread_ngh_cnt_V_fu_766_p3();
    void thread_p_Result_1_fu_509_p5();
    void thread_p_Result_2_fu_848_p5();
    void thread_p_Result_s_fu_470_p5();
    void thread_ret_V_1_fu_551_p2();
    void thread_ret_V_2_fu_614_p2();
    void thread_ret_V_3_fu_698_p2();
    void thread_ret_V_4_fu_741_p2();
    void thread_ret_V_fu_440_p2();
    void thread_rhs_V_1_fu_610_p1();
    void thread_rhs_V_2_fu_694_p1();
    void thread_rhs_V_fu_547_p1();
    void thread_sext_ln177_1_fu_533_p1();
    void thread_sext_ln177_2_fu_676_p1();
    void thread_sext_ln177_3_fu_871_p1();
    void thread_sext_ln177_4_fu_826_p1();
    void thread_sext_ln177_fu_494_p1();
    void thread_sext_ln544_1_fu_620_p1();
    void thread_sext_ln544_2_fu_704_p1();
    void thread_sext_ln544_3_fu_792_p1();
    void thread_sext_ln544_4_fu_796_p1();
    void thread_sext_ln544_5_fu_831_p1();
    void thread_sext_ln544_fu_557_p1();
    void thread_sext_ln887_fu_774_p1();
    void thread_task_in_ttype_V_load_fu_421_p4();
    void thread_task_out_V_TDATA_blk_n();
    void thread_task_out_V_TDATA_int();
    void thread_task_out_V_TVALID();
    void thread_task_out_V_TVALID_int();
    void thread_tmp_1_fu_523_p4();
    void thread_tmp_2_fu_591_p4();
    void thread_tmp_3_fu_653_p4();
    void thread_tmp_4_fu_667_p4();
    void thread_tmp_5_fu_860_p5();
    void thread_tmp_6_fu_816_p5();
    void thread_tmp_9_fu_576_p4();
    void thread_tmp_fu_482_p5();
    void thread_tmp_s_fu_639_p4();
    void thread_trunc_ln1503_1_fu_635_p1();
    void thread_trunc_ln1503_fu_572_p1();
    void thread_trunc_ln176_1_fu_664_p1();
    void thread_trunc_ln176_2_fu_813_p1();
    void thread_trunc_ln176_fu_520_p1();
    void thread_undo_log_entry_V_TDATA_blk_n();
    void thread_undo_log_entry_V_TDATA_int();
    void thread_undo_log_entry_V_TVALID();
    void thread_undo_log_entry_V_TVALID_int();
    void thread_v_V_fu_446_p2();
    void thread_zext_ln115_fu_436_p1();
    void thread_zext_ln177_1_fu_747_p1();
    void thread_zext_ln177_fu_737_p0();
    void thread_zext_ln177_fu_737_p1();
    void thread_zext_ln887_fu_452_p1();
    void thread_ap_NS_fsm();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif