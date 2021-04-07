// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="mis_hls,hls_ip_2019_2,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=1,HLS_INPUT_PART=xc7k160t-fbg484-1,HLS_INPUT_CLOCK=4.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=3.500000,HLS_SYN_LAT=-1,HLS_SYN_TPT=none,HLS_SYN_MEM=2,HLS_SYN_DSP=0,HLS_SYN_FF=786,HLS_SYN_LUT=937,HLS_VERSION=2019_2}" *)

module mis_hls (
        ap_clk,
        ap_rst_n,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        task_in,
        task_out_V_TDATA,
        task_out_V_TVALID,
        task_out_V_TREADY,
        m_axi_l1_V_AWVALID,
        m_axi_l1_V_AWREADY,
        m_axi_l1_V_AWADDR,
        m_axi_l1_V_AWID,
        m_axi_l1_V_AWLEN,
        m_axi_l1_V_AWSIZE,
        m_axi_l1_V_AWBURST,
        m_axi_l1_V_AWLOCK,
        m_axi_l1_V_AWCACHE,
        m_axi_l1_V_AWPROT,
        m_axi_l1_V_AWQOS,
        m_axi_l1_V_AWREGION,
        m_axi_l1_V_AWUSER,
        m_axi_l1_V_WVALID,
        m_axi_l1_V_WREADY,
        m_axi_l1_V_WDATA,
        m_axi_l1_V_WSTRB,
        m_axi_l1_V_WLAST,
        m_axi_l1_V_WID,
        m_axi_l1_V_WUSER,
        m_axi_l1_V_ARVALID,
        m_axi_l1_V_ARREADY,
        m_axi_l1_V_ARADDR,
        m_axi_l1_V_ARID,
        m_axi_l1_V_ARLEN,
        m_axi_l1_V_ARSIZE,
        m_axi_l1_V_ARBURST,
        m_axi_l1_V_ARLOCK,
        m_axi_l1_V_ARCACHE,
        m_axi_l1_V_ARPROT,
        m_axi_l1_V_ARQOS,
        m_axi_l1_V_ARREGION,
        m_axi_l1_V_ARUSER,
        m_axi_l1_V_RVALID,
        m_axi_l1_V_RREADY,
        m_axi_l1_V_RDATA,
        m_axi_l1_V_RLAST,
        m_axi_l1_V_RID,
        m_axi_l1_V_RUSER,
        m_axi_l1_V_RRESP,
        m_axi_l1_V_BVALID,
        m_axi_l1_V_BREADY,
        m_axi_l1_V_BRESP,
        m_axi_l1_V_BID,
        m_axi_l1_V_BUSER,
        undo_log_entry_V_TDATA,
        undo_log_entry_V_TVALID,
        undo_log_entry_V_TREADY
);

parameter    ap_ST_fsm_state1 = 12'd1;
parameter    ap_ST_fsm_state2 = 12'd2;
parameter    ap_ST_fsm_state3 = 12'd4;
parameter    ap_ST_fsm_state4 = 12'd8;
parameter    ap_ST_fsm_state5 = 12'd16;
parameter    ap_ST_fsm_state6 = 12'd32;
parameter    ap_ST_fsm_state7 = 12'd64;
parameter    ap_ST_fsm_state8 = 12'd128;
parameter    ap_ST_fsm_state9 = 12'd256;
parameter    ap_ST_fsm_state10 = 12'd512;
parameter    ap_ST_fsm_state11 = 12'd1024;
parameter    ap_ST_fsm_state12 = 12'd2048;
parameter    C_M_AXI_L1_V_ID_WIDTH = 1;
parameter    C_M_AXI_L1_V_ADDR_WIDTH = 32;
parameter    C_M_AXI_L1_V_DATA_WIDTH = 32;
parameter    C_M_AXI_L1_V_AWUSER_WIDTH = 1;
parameter    C_M_AXI_L1_V_ARUSER_WIDTH = 1;
parameter    C_M_AXI_L1_V_WUSER_WIDTH = 1;
parameter    C_M_AXI_L1_V_RUSER_WIDTH = 1;
parameter    C_M_AXI_L1_V_BUSER_WIDTH = 1;
parameter    C_M_AXI_L1_V_TARGET_ADDR = 0;
parameter    C_M_AXI_L1_V_USER_VALUE = 0;
parameter    C_M_AXI_L1_V_PROT_VALUE = 0;
parameter    C_M_AXI_L1_V_CACHE_VALUE = 3;
parameter    C_M_AXI_DATA_WIDTH = 32;

parameter C_M_AXI_L1_V_WSTRB_WIDTH = (32 / 8);
parameter C_M_AXI_WSTRB_WIDTH = (32 / 8);
parameter    ap_const_lv64_0 = 64'd0;

input   ap_clk;
input   ap_rst_n;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [131:0] task_in;
output  [135:0] task_out_V_TDATA;
output   task_out_V_TVALID;
input   task_out_V_TREADY;
output   m_axi_l1_V_AWVALID;
input   m_axi_l1_V_AWREADY;
output  [C_M_AXI_L1_V_ADDR_WIDTH - 1:0] m_axi_l1_V_AWADDR;
output  [C_M_AXI_L1_V_ID_WIDTH - 1:0] m_axi_l1_V_AWID;
output  [7:0] m_axi_l1_V_AWLEN;
output  [2:0] m_axi_l1_V_AWSIZE;
output  [1:0] m_axi_l1_V_AWBURST;
output  [1:0] m_axi_l1_V_AWLOCK;
output  [3:0] m_axi_l1_V_AWCACHE;
output  [2:0] m_axi_l1_V_AWPROT;
output  [3:0] m_axi_l1_V_AWQOS;
output  [3:0] m_axi_l1_V_AWREGION;
output  [C_M_AXI_L1_V_AWUSER_WIDTH - 1:0] m_axi_l1_V_AWUSER;
output   m_axi_l1_V_WVALID;
input   m_axi_l1_V_WREADY;
output  [C_M_AXI_L1_V_DATA_WIDTH - 1:0] m_axi_l1_V_WDATA;
output  [C_M_AXI_L1_V_WSTRB_WIDTH - 1:0] m_axi_l1_V_WSTRB;
output   m_axi_l1_V_WLAST;
output  [C_M_AXI_L1_V_ID_WIDTH - 1:0] m_axi_l1_V_WID;
output  [C_M_AXI_L1_V_WUSER_WIDTH - 1:0] m_axi_l1_V_WUSER;
output   m_axi_l1_V_ARVALID;
input   m_axi_l1_V_ARREADY;
output  [C_M_AXI_L1_V_ADDR_WIDTH - 1:0] m_axi_l1_V_ARADDR;
output  [C_M_AXI_L1_V_ID_WIDTH - 1:0] m_axi_l1_V_ARID;
output  [7:0] m_axi_l1_V_ARLEN;
output  [2:0] m_axi_l1_V_ARSIZE;
output  [1:0] m_axi_l1_V_ARBURST;
output  [1:0] m_axi_l1_V_ARLOCK;
output  [3:0] m_axi_l1_V_ARCACHE;
output  [2:0] m_axi_l1_V_ARPROT;
output  [3:0] m_axi_l1_V_ARQOS;
output  [3:0] m_axi_l1_V_ARREGION;
output  [C_M_AXI_L1_V_ARUSER_WIDTH - 1:0] m_axi_l1_V_ARUSER;
input   m_axi_l1_V_RVALID;
output   m_axi_l1_V_RREADY;
input  [C_M_AXI_L1_V_DATA_WIDTH - 1:0] m_axi_l1_V_RDATA;
input   m_axi_l1_V_RLAST;
input  [C_M_AXI_L1_V_ID_WIDTH - 1:0] m_axi_l1_V_RID;
input  [C_M_AXI_L1_V_RUSER_WIDTH - 1:0] m_axi_l1_V_RUSER;
input  [1:0] m_axi_l1_V_RRESP;
input   m_axi_l1_V_BVALID;
output   m_axi_l1_V_BREADY;
input  [1:0] m_axi_l1_V_BRESP;
input  [C_M_AXI_L1_V_ID_WIDTH - 1:0] m_axi_l1_V_BID;
input  [C_M_AXI_L1_V_BUSER_WIDTH - 1:0] m_axi_l1_V_BUSER;
input  [63:0] undo_log_entry_V_TDATA;
input   undo_log_entry_V_TVALID;
output   undo_log_entry_V_TREADY;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg undo_log_entry_V_TREADY;

 reg    ap_rst_n_inv;
(* fsm_encoding = "none" *) reg   [11:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg   [0:0] initialized_V;
reg   [31:0] total_v_V;
reg    task_out_V_TDATA_blk_n;
wire    ap_CS_fsm_state10;
wire   [0:0] icmp_ln887_fu_211_p2;
wire   [0:0] icmp_ln887_1_fu_216_p2;
wire    ap_CS_fsm_state11;
reg   [0:0] icmp_ln887_1_reg_349;
wire   [0:0] icmp_ln887_2_fu_259_p2;
wire    ap_CS_fsm_state12;
reg   [0:0] icmp_ln879_reg_320;
reg   [0:0] icmp_ln887_2_reg_358;
reg    l1_V_blk_n_AR;
wire   [0:0] initialized_V_load_load_fu_140_p1;
reg    l1_V_blk_n_R;
wire    ap_CS_fsm_state8;
wire    l1_V_AWREADY;
wire    l1_V_WREADY;
reg    l1_V_ARVALID;
wire    l1_V_ARREADY;
wire   [31:0] l1_V_ARADDR;
wire    l1_V_RVALID;
reg    l1_V_RREADY;
wire   [31:0] l1_V_RDATA;
wire    l1_V_RLAST;
wire   [0:0] l1_V_RID;
wire   [0:0] l1_V_RUSER;
wire   [1:0] l1_V_RRESP;
wire    l1_V_BVALID;
wire   [1:0] l1_V_BRESP;
wire   [0:0] l1_V_BID;
wire   [0:0] l1_V_BUSER;
reg    ap_block_state1_io;
reg   [0:0] initialized_V_load_reg_300;
reg   [31:0] l1_V_addr_read_reg_315;
wire   [0:0] icmp_ln879_fu_176_p2;
wire    ap_CS_fsm_state9;
wire   [31:0] start_v_V_fu_182_p4;
wire   [32:0] ret_V_fu_195_p2;
reg   [32:0] ret_V_reg_335;
wire   [31:0] v_V_fu_201_p2;
reg   [31:0] v_V_reg_340;
reg    ap_predicate_op59_write_state10;
reg    ap_predicate_op67_write_state10;
reg    ap_block_state10_io;
wire  signed [135:0] sext_ln177_fu_249_p1;
wire  signed [135:0] sext_ln177_1_fu_288_p1;
wire   [31:0] grp_fu_133_p2;
reg    ap_block_state11_io;
reg   [31:0] total_v_V_loc_0_reg_113;
wire   [31:0] ap_phi_mux_child_object_V_phi_fu_126_p4;
reg   [31:0] child_object_V_reg_123;
reg   [63:0] p_Val2_s_fu_84;
wire   [63:0] p_Result_s_fu_225_p5;
reg   [31:0] grp_fu_133_p0;
wire   [3:0] task_in_ttype_V_load_fu_167_p4;
wire   [32:0] zext_ln115_fu_191_p1;
wire   [32:0] zext_ln887_fu_207_p1;
wire   [131:0] tmp_fu_237_p5;
wire   [63:0] p_Result_1_fu_264_p5;
wire   [63:0] trunc_ln176_fu_275_p1;
wire   [131:0] tmp_1_fu_278_p4;
wire    regslice_both_task_out_V_U_apdone_blk;
reg    ap_predicate_op72_write_state12;
reg    ap_block_state12_io;
reg   [11:0] ap_NS_fsm;
reg   [135:0] task_out_V_TDATA_int;
reg    task_out_V_TVALID_int;
wire    task_out_V_TREADY_int;
wire    regslice_both_task_out_V_U_vld_out;
wire    regslice_both_undo_log_entry_V_U_apdone_blk;
wire   [63:0] undo_log_entry_V_TDATA_int;
wire    undo_log_entry_V_TVALID_int;
wire    regslice_both_undo_log_entry_V_U_ack_in;

// power-on initialization
initial begin
#0 ap_CS_fsm = 12'd1;
#0 initialized_V = 1'd0;
#0 total_v_V = 32'd0;
end

mis_hls_l1_V_m_axi #(
    .CONSERVATIVE( 0 ),
    .USER_DW( 32 ),
    .USER_AW( 32 ),
    .USER_MAXREQS( 5 ),
    .NUM_READ_OUTSTANDING( 16 ),
    .NUM_WRITE_OUTSTANDING( 16 ),
    .MAX_READ_BURST_LENGTH( 16 ),
    .MAX_WRITE_BURST_LENGTH( 16 ),
    .C_M_AXI_ID_WIDTH( C_M_AXI_L1_V_ID_WIDTH ),
    .C_M_AXI_ADDR_WIDTH( C_M_AXI_L1_V_ADDR_WIDTH ),
    .C_M_AXI_DATA_WIDTH( C_M_AXI_L1_V_DATA_WIDTH ),
    .C_M_AXI_AWUSER_WIDTH( C_M_AXI_L1_V_AWUSER_WIDTH ),
    .C_M_AXI_ARUSER_WIDTH( C_M_AXI_L1_V_ARUSER_WIDTH ),
    .C_M_AXI_WUSER_WIDTH( C_M_AXI_L1_V_WUSER_WIDTH ),
    .C_M_AXI_RUSER_WIDTH( C_M_AXI_L1_V_RUSER_WIDTH ),
    .C_M_AXI_BUSER_WIDTH( C_M_AXI_L1_V_BUSER_WIDTH ),
    .C_TARGET_ADDR( C_M_AXI_L1_V_TARGET_ADDR ),
    .C_USER_VALUE( C_M_AXI_L1_V_USER_VALUE ),
    .C_PROT_VALUE( C_M_AXI_L1_V_PROT_VALUE ),
    .C_CACHE_VALUE( C_M_AXI_L1_V_CACHE_VALUE ))
mis_hls_l1_V_m_axi_U(
    .AWVALID(m_axi_l1_V_AWVALID),
    .AWREADY(m_axi_l1_V_AWREADY),
    .AWADDR(m_axi_l1_V_AWADDR),
    .AWID(m_axi_l1_V_AWID),
    .AWLEN(m_axi_l1_V_AWLEN),
    .AWSIZE(m_axi_l1_V_AWSIZE),
    .AWBURST(m_axi_l1_V_AWBURST),
    .AWLOCK(m_axi_l1_V_AWLOCK),
    .AWCACHE(m_axi_l1_V_AWCACHE),
    .AWPROT(m_axi_l1_V_AWPROT),
    .AWQOS(m_axi_l1_V_AWQOS),
    .AWREGION(m_axi_l1_V_AWREGION),
    .AWUSER(m_axi_l1_V_AWUSER),
    .WVALID(m_axi_l1_V_WVALID),
    .WREADY(m_axi_l1_V_WREADY),
    .WDATA(m_axi_l1_V_WDATA),
    .WSTRB(m_axi_l1_V_WSTRB),
    .WLAST(m_axi_l1_V_WLAST),
    .WID(m_axi_l1_V_WID),
    .WUSER(m_axi_l1_V_WUSER),
    .ARVALID(m_axi_l1_V_ARVALID),
    .ARREADY(m_axi_l1_V_ARREADY),
    .ARADDR(m_axi_l1_V_ARADDR),
    .ARID(m_axi_l1_V_ARID),
    .ARLEN(m_axi_l1_V_ARLEN),
    .ARSIZE(m_axi_l1_V_ARSIZE),
    .ARBURST(m_axi_l1_V_ARBURST),
    .ARLOCK(m_axi_l1_V_ARLOCK),
    .ARCACHE(m_axi_l1_V_ARCACHE),
    .ARPROT(m_axi_l1_V_ARPROT),
    .ARQOS(m_axi_l1_V_ARQOS),
    .ARREGION(m_axi_l1_V_ARREGION),
    .ARUSER(m_axi_l1_V_ARUSER),
    .RVALID(m_axi_l1_V_RVALID),
    .RREADY(m_axi_l1_V_RREADY),
    .RDATA(m_axi_l1_V_RDATA),
    .RLAST(m_axi_l1_V_RLAST),
    .RID(m_axi_l1_V_RID),
    .RUSER(m_axi_l1_V_RUSER),
    .RRESP(m_axi_l1_V_RRESP),
    .BVALID(m_axi_l1_V_BVALID),
    .BREADY(m_axi_l1_V_BREADY),
    .BRESP(m_axi_l1_V_BRESP),
    .BID(m_axi_l1_V_BID),
    .BUSER(m_axi_l1_V_BUSER),
    .ACLK(ap_clk),
    .ARESET(ap_rst_n_inv),
    .ACLK_EN(1'b1),
    .I_ARVALID(l1_V_ARVALID),
    .I_ARREADY(l1_V_ARREADY),
    .I_ARADDR(l1_V_ARADDR),
    .I_ARID(1'd0),
    .I_ARLEN(32'd1),
    .I_ARSIZE(3'd0),
    .I_ARLOCK(2'd0),
    .I_ARCACHE(4'd0),
    .I_ARQOS(4'd0),
    .I_ARPROT(3'd0),
    .I_ARUSER(1'd0),
    .I_ARBURST(2'd0),
    .I_ARREGION(4'd0),
    .I_RVALID(l1_V_RVALID),
    .I_RREADY(l1_V_RREADY),
    .I_RDATA(l1_V_RDATA),
    .I_RID(l1_V_RID),
    .I_RUSER(l1_V_RUSER),
    .I_RRESP(l1_V_RRESP),
    .I_RLAST(l1_V_RLAST),
    .I_AWVALID(1'b0),
    .I_AWREADY(l1_V_AWREADY),
    .I_AWADDR(32'd0),
    .I_AWID(1'd0),
    .I_AWLEN(32'd0),
    .I_AWSIZE(3'd0),
    .I_AWLOCK(2'd0),
    .I_AWCACHE(4'd0),
    .I_AWQOS(4'd0),
    .I_AWPROT(3'd0),
    .I_AWUSER(1'd0),
    .I_AWBURST(2'd0),
    .I_AWREGION(4'd0),
    .I_WVALID(1'b0),
    .I_WREADY(l1_V_WREADY),
    .I_WDATA(32'd0),
    .I_WID(1'd0),
    .I_WUSER(1'd0),
    .I_WLAST(1'b0),
    .I_WSTRB(4'd0),
    .I_BVALID(l1_V_BVALID),
    .I_BREADY(1'b0),
    .I_BRESP(l1_V_BRESP),
    .I_BID(l1_V_BID),
    .I_BUSER(l1_V_BUSER)
);

regslice_both #(
    .DataWidth( 136 ))
regslice_both_task_out_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(task_out_V_TDATA_int),
    .vld_in(task_out_V_TVALID_int),
    .ack_in(task_out_V_TREADY_int),
    .data_out(task_out_V_TDATA),
    .vld_out(regslice_both_task_out_V_U_vld_out),
    .ack_out(task_out_V_TREADY),
    .apdone_blk(regslice_both_task_out_V_U_apdone_blk)
);

regslice_both #(
    .DataWidth( 64 ))
regslice_both_undo_log_entry_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(undo_log_entry_V_TDATA),
    .vld_in(undo_log_entry_V_TVALID),
    .ack_in(regslice_both_undo_log_entry_V_U_ack_in),
    .data_out(undo_log_entry_V_TDATA_int),
    .vld_out(undo_log_entry_V_TVALID_int),
    .ack_out(1'b0),
    .apdone_blk(regslice_both_undo_log_entry_V_U_apdone_blk)
);

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_state11_io) & (1'b1 == ap_CS_fsm_state11))) begin
        child_object_V_reg_123 <= grp_fu_133_p2;
    end else if (((1'b1 == ap_CS_fsm_state9) & (icmp_ln879_fu_176_p2 == 1'd1))) begin
        child_object_V_reg_123 <= {{task_in[99:68]}};
    end
end

always @ (posedge ap_clk) begin
    if (((initialized_V_load_reg_300 == 1'd0) & (1'b1 == ap_CS_fsm_state9))) begin
        total_v_V_loc_0_reg_113 <= l1_V_addr_read_reg_315;
    end else if ((~((ap_start == 1'b0) | (1'b1 == ap_block_state1_io)) & (1'b1 == ap_CS_fsm_state1) & (initialized_V_load_load_fu_140_p1 == 1'd1))) begin
        total_v_V_loc_0_reg_113 <= total_v_V;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state9)) begin
        icmp_ln879_reg_320 <= icmp_ln879_fu_176_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_state10_io) & (1'b1 == ap_CS_fsm_state10) & (icmp_ln887_fu_211_p2 == 1'd1))) begin
        icmp_ln887_1_reg_349 <= icmp_ln887_1_fu_216_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln887_fu_211_p2 == 1'd0) & (1'b0 == ap_block_state10_io) & (1'b1 == ap_CS_fsm_state10))) begin
        icmp_ln887_2_reg_358 <= icmp_ln887_2_fu_259_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((~((ap_start == 1'b0) | (1'b1 == ap_block_state1_io)) & (initialized_V == 1'd0) & (1'b1 == ap_CS_fsm_state1))) begin
        initialized_V <= 1'd1;
    end
end

always @ (posedge ap_clk) begin
    if ((~((ap_start == 1'b0) | (1'b1 == ap_block_state1_io)) & (1'b1 == ap_CS_fsm_state1))) begin
        initialized_V_load_reg_300 <= initialized_V;
    end
end

always @ (posedge ap_clk) begin
    if (((l1_V_RVALID == 1'b1) & (1'b1 == ap_CS_fsm_state8))) begin
        l1_V_addr_read_reg_315 <= l1_V_RDATA;
        total_v_V <= l1_V_RDATA;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_state10_io) & (1'b1 == ap_CS_fsm_state10) & (icmp_ln887_1_fu_216_p2 == 1'd1) & (icmp_ln887_fu_211_p2 == 1'd1))) begin
        p_Val2_s_fu_84 <= p_Result_s_fu_225_p5;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state9) & (icmp_ln879_fu_176_p2 == 1'd1))) begin
        ret_V_reg_335 <= ret_V_fu_195_p2;
        v_V_reg_340 <= v_V_fu_201_p2;
    end
end

always @ (*) begin
    if ((~((1'b1 == ap_block_state12_io) | (regslice_both_task_out_V_U_apdone_blk == 1'b1)) & (1'b1 == ap_CS_fsm_state12))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if ((~((1'b1 == ap_block_state12_io) | (regslice_both_task_out_V_U_apdone_blk == 1'b1)) & (1'b1 == ap_CS_fsm_state12))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state11)) begin
        grp_fu_133_p0 = child_object_V_reg_123;
    end else if ((1'b1 == ap_CS_fsm_state10)) begin
        grp_fu_133_p0 = ap_phi_mux_child_object_V_phi_fu_126_p4;
    end else begin
        grp_fu_133_p0 = 'bx;
    end
end

always @ (*) begin
    if ((~((ap_start == 1'b0) | (1'b1 == ap_block_state1_io)) & (initialized_V == 1'd0) & (1'b1 == ap_CS_fsm_state1))) begin
        l1_V_ARVALID = 1'b1;
    end else begin
        l1_V_ARVALID = 1'b0;
    end
end

always @ (*) begin
    if (((l1_V_RVALID == 1'b1) & (1'b1 == ap_CS_fsm_state8))) begin
        l1_V_RREADY = 1'b1;
    end else begin
        l1_V_RREADY = 1'b0;
    end
end

always @ (*) begin
    if (((initialized_V == 1'd0) & (1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        l1_V_blk_n_AR = m_axi_l1_V_ARREADY;
    end else begin
        l1_V_blk_n_AR = 1'b1;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state8)) begin
        l1_V_blk_n_R = m_axi_l1_V_RVALID;
    end else begin
        l1_V_blk_n_R = 1'b1;
    end
end

always @ (*) begin
    if ((((1'b1 == ap_CS_fsm_state12) & (icmp_ln887_2_reg_358 == 1'd1) & (icmp_ln879_reg_320 == 1'd1)) | ((1'b1 == ap_CS_fsm_state11) & (icmp_ln887_1_reg_349 == 1'd1)) | ((icmp_ln887_fu_211_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state10) & (icmp_ln887_2_fu_259_p2 == 1'd1)) | ((1'b1 == ap_CS_fsm_state10) & (icmp_ln887_1_fu_216_p2 == 1'd1) & (icmp_ln887_fu_211_p2 == 1'd1)))) begin
        task_out_V_TDATA_blk_n = task_out_V_TREADY_int;
    end else begin
        task_out_V_TDATA_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state10)) begin
        if ((ap_predicate_op67_write_state10 == 1'b1)) begin
            task_out_V_TDATA_int = sext_ln177_1_fu_288_p1;
        end else if ((ap_predicate_op59_write_state10 == 1'b1)) begin
            task_out_V_TDATA_int = sext_ln177_fu_249_p1;
        end else begin
            task_out_V_TDATA_int = 'bx;
        end
    end else begin
        task_out_V_TDATA_int = 'bx;
    end
end

always @ (*) begin
    if ((((ap_predicate_op67_write_state10 == 1'b1) & (1'b0 == ap_block_state10_io) & (1'b1 == ap_CS_fsm_state10)) | ((ap_predicate_op59_write_state10 == 1'b1) & (1'b0 == ap_block_state10_io) & (1'b1 == ap_CS_fsm_state10)))) begin
        task_out_V_TVALID_int = 1'b1;
    end else begin
        task_out_V_TVALID_int = 1'b0;
    end
end

always @ (*) begin
    if (((undo_log_entry_V_TVALID == 1'b1) & (regslice_both_undo_log_entry_V_U_ack_in == 1'b1))) begin
        undo_log_entry_V_TREADY = 1'b1;
    end else begin
        undo_log_entry_V_TREADY = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if ((~((ap_start == 1'b0) | (1'b1 == ap_block_state1_io)) & (1'b1 == ap_CS_fsm_state1) & (initialized_V_load_load_fu_140_p1 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state9;
            end else if ((~((ap_start == 1'b0) | (1'b1 == ap_block_state1_io)) & (initialized_V == 1'd0) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            ap_NS_fsm = ap_ST_fsm_state3;
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state5 : begin
            ap_NS_fsm = ap_ST_fsm_state6;
        end
        ap_ST_fsm_state6 : begin
            ap_NS_fsm = ap_ST_fsm_state7;
        end
        ap_ST_fsm_state7 : begin
            ap_NS_fsm = ap_ST_fsm_state8;
        end
        ap_ST_fsm_state8 : begin
            if (((l1_V_RVALID == 1'b1) & (1'b1 == ap_CS_fsm_state8))) begin
                ap_NS_fsm = ap_ST_fsm_state9;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state8;
            end
        end
        ap_ST_fsm_state9 : begin
            if (((1'b1 == ap_CS_fsm_state9) & (icmp_ln879_fu_176_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state10;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state12;
            end
        end
        ap_ST_fsm_state10 : begin
            if (((icmp_ln887_fu_211_p2 == 1'd0) & (1'b0 == ap_block_state10_io) & (1'b1 == ap_CS_fsm_state10))) begin
                ap_NS_fsm = ap_ST_fsm_state12;
            end else if (((1'b0 == ap_block_state10_io) & (1'b1 == ap_CS_fsm_state10) & (icmp_ln887_fu_211_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state11;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state10;
            end
        end
        ap_ST_fsm_state11 : begin
            if (((1'b0 == ap_block_state11_io) & (1'b1 == ap_CS_fsm_state11))) begin
                ap_NS_fsm = ap_ST_fsm_state10;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state11;
            end
        end
        ap_ST_fsm_state12 : begin
            if ((~((1'b1 == ap_block_state12_io) | (regslice_both_task_out_V_U_apdone_blk == 1'b1)) & (1'b1 == ap_CS_fsm_state12))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state12;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state10 = ap_CS_fsm[32'd9];

assign ap_CS_fsm_state11 = ap_CS_fsm[32'd10];

assign ap_CS_fsm_state12 = ap_CS_fsm[32'd11];

assign ap_CS_fsm_state8 = ap_CS_fsm[32'd7];

assign ap_CS_fsm_state9 = ap_CS_fsm[32'd8];

always @ (*) begin
    ap_block_state10_io = (((task_out_V_TREADY_int == 1'b0) & (ap_predicate_op67_write_state10 == 1'b1)) | ((task_out_V_TREADY_int == 1'b0) & (ap_predicate_op59_write_state10 == 1'b1)));
end

always @ (*) begin
    ap_block_state11_io = ((task_out_V_TREADY_int == 1'b0) & (icmp_ln887_1_reg_349 == 1'd1));
end

always @ (*) begin
    ap_block_state12_io = ((task_out_V_TREADY_int == 1'b0) & (ap_predicate_op72_write_state12 == 1'b1));
end

always @ (*) begin
    ap_block_state1_io = ((initialized_V == 1'd0) & (l1_V_ARREADY == 1'b0));
end

assign ap_phi_mux_child_object_V_phi_fu_126_p4 = child_object_V_reg_123;

always @ (*) begin
    ap_predicate_op59_write_state10 = ((icmp_ln887_1_fu_216_p2 == 1'd1) & (icmp_ln887_fu_211_p2 == 1'd1));
end

always @ (*) begin
    ap_predicate_op67_write_state10 = ((icmp_ln887_fu_211_p2 == 1'd0) & (icmp_ln887_2_fu_259_p2 == 1'd1));
end

always @ (*) begin
    ap_predicate_op72_write_state12 = ((icmp_ln887_2_reg_358 == 1'd1) & (icmp_ln879_reg_320 == 1'd1));
end

always @ (*) begin
    ap_rst_n_inv = ~ap_rst_n;
end

assign grp_fu_133_p2 = (grp_fu_133_p0 + 32'd1);

assign icmp_ln879_fu_176_p2 = ((task_in_ttype_V_load_fu_167_p4 == 4'd0) ? 1'b1 : 1'b0);

assign icmp_ln887_1_fu_216_p2 = ((child_object_V_reg_123 < total_v_V_loc_0_reg_113) ? 1'b1 : 1'b0);

assign icmp_ln887_2_fu_259_p2 = ((v_V_reg_340 < total_v_V_loc_0_reg_113) ? 1'b1 : 1'b0);

assign icmp_ln887_fu_211_p2 = ((zext_ln887_fu_207_p1 < ret_V_reg_335) ? 1'b1 : 1'b0);

assign initialized_V_load_load_fu_140_p1 = initialized_V;

assign l1_V_ARADDR = 64'd1;

assign p_Result_1_fu_264_p5 = {{ap_const_lv64_0[63:32]}, {v_V_reg_340}};

assign p_Result_s_fu_225_p5 = {{p_Val2_s_fu_84[63:32]}, {child_object_V_reg_123}};

assign ret_V_fu_195_p2 = (zext_ln115_fu_191_p1 + 33'd7);

assign sext_ln177_1_fu_288_p1 = $signed(tmp_1_fu_278_p4);

assign sext_ln177_fu_249_p1 = $signed(tmp_fu_237_p5);

assign start_v_V_fu_182_p4 = {{task_in[99:68]}};

assign task_in_ttype_V_load_fu_167_p4 = {{task_in[67:64]}};

assign task_out_V_TVALID = regslice_both_task_out_V_U_vld_out;

assign tmp_1_fu_278_p4 = {{{p_Result_1_fu_264_p5}, {4'd0}}, {trunc_ln176_fu_275_p1}};

assign tmp_fu_237_p5 = {{{{p_Result_s_fu_225_p5}, {4'd2}}, {child_object_V_reg_123}}, {grp_fu_133_p2}};

assign trunc_ln176_fu_275_p1 = task_in[63:0];

assign v_V_fu_201_p2 = (start_v_V_fu_182_p4 + 32'd7);

assign zext_ln115_fu_191_p1 = start_v_V_fu_182_p4;

assign zext_ln887_fu_207_p1 = child_object_V_reg_123;

endmodule //mis_hls
