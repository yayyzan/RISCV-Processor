// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu_pipelined__Syms.h"


VL_ATTR_COLD void Vcpu_pipelined___024root__trace_init_sub__TOP__0(Vcpu_pipelined___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+107,"trigger", false,-1);
    tracep->declBit(c+108,"clk", false,-1);
    tracep->declBit(c+109,"rst", false,-1);
    tracep->declBus(c+110,"a0W", false,-1, 31,0);
    tracep->pushNamePrefix("cpu_pipelined ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+107,"trigger", false,-1);
    tracep->declBit(c+108,"clk", false,-1);
    tracep->declBit(c+109,"rst", false,-1);
    tracep->declBus(c+110,"a0W", false,-1, 31,0);
    tracep->declBus(c+3,"pcF", false,-1, 31,0);
    tracep->declBus(c+4,"instrF", false,-1, 31,0);
    tracep->declBus(c+5,"pcplusfourF", false,-1, 31,0);
    tracep->declBus(c+6,"pcD", false,-1, 31,0);
    tracep->declBus(c+7,"instrD", false,-1, 31,0);
    tracep->declBus(c+8,"pcplusfourD", false,-1, 31,0);
    tracep->declBit(c+9,"regwriteD", false,-1);
    tracep->declBit(c+10,"resultsrcD", false,-1);
    tracep->declBit(c+11,"memwriteD", false,-1);
    tracep->declBit(c+12,"alusrcD", false,-1);
    tracep->declBit(c+13,"addupperD", false,-1);
    tracep->declBit(c+14,"jbmuxD", false,-1);
    tracep->declBit(c+15,"pcwritemuxD", false,-1);
    tracep->declBus(c+74,"a0D", false,-1, 31,0);
    tracep->declBus(c+111,"rd1D", false,-1, 31,0);
    tracep->declBus(c+112,"rd2D", false,-1, 31,0);
    tracep->declBus(c+16,"immextD", false,-1, 31,0);
    tracep->declBus(c+17,"opcodeD", false,-1, 6,0);
    tracep->declBus(c+18,"rdD", false,-1, 4,0);
    tracep->declBus(c+19,"aluctrlD", false,-1, 3,0);
    tracep->declBus(c+20,"funct3D", false,-1, 2,0);
    tracep->declBit(c+21,"regwriteE", false,-1);
    tracep->declBit(c+22,"addupperE", false,-1);
    tracep->declBit(c+23,"alusrcE", false,-1);
    tracep->declBit(c+24,"memwriteE", false,-1);
    tracep->declBit(c+25,"resultsrcE", false,-1);
    tracep->declBit(c+26,"jbmuxE", false,-1);
    tracep->declBit(c+27,"pcwritemuxE", false,-1);
    tracep->declBus(c+28,"a0E", false,-1, 31,0);
    tracep->declBus(c+29,"rd1E", false,-1, 31,0);
    tracep->declBus(c+30,"rd2E", false,-1, 31,0);
    tracep->declBus(c+31,"immextE", false,-1, 31,0);
    tracep->declBus(c+32,"pcE", false,-1, 31,0);
    tracep->declBus(c+33,"pcplusfourE", false,-1, 31,0);
    tracep->declBus(c+34,"opcodeE", false,-1, 6,0);
    tracep->declBus(c+35,"rdE", false,-1, 4,0);
    tracep->declBus(c+36,"aluctrlE", false,-1, 3,0);
    tracep->declBus(c+37,"funct3E", false,-1, 2,0);
    tracep->declBus(c+38,"pctargetE", false,-1, 31,0);
    tracep->declBus(c+39,"aluresultE", false,-1, 31,0);
    tracep->declBit(c+40,"pcsrcE", false,-1);
    tracep->declBit(c+41,"regwriteM", false,-1);
    tracep->declBit(c+42,"resultsrcM", false,-1);
    tracep->declBit(c+43,"memwriteM", false,-1);
    tracep->declBit(c+44,"pcwritemuxM", false,-1);
    tracep->declBus(c+45,"aluresultM", false,-1, 31,0);
    tracep->declBus(c+46,"write_dataM", false,-1, 31,0);
    tracep->declBus(c+47,"pcplusfourM", false,-1, 31,0);
    tracep->declBus(c+48,"a0M", false,-1, 31,0);
    tracep->declBus(c+49,"rdM", false,-1, 4,0);
    tracep->declBus(c+50,"funct3M", false,-1, 2,0);
    tracep->declBus(c+51,"read_dataM", false,-1, 31,0);
    tracep->declBit(c+52,"regwriteW", false,-1);
    tracep->declBit(c+53,"resultsrcW", false,-1);
    tracep->declBit(c+54,"pcwritemuxW", false,-1);
    tracep->declBus(c+55,"read_dataW", false,-1, 31,0);
    tracep->declBus(c+56,"aluresultW", false,-1, 31,0);
    tracep->declBus(c+57,"pcplusfourW", false,-1, 31,0);
    tracep->declBus(c+58,"rdW", false,-1, 4,0);
    tracep->declBus(c+59,"resultW", false,-1, 31,0);
    tracep->pushNamePrefix("decode ");
    tracep->declBus(c+59,"wd3D", false,-1, 31,0);
    tracep->declBus(c+7,"instrD", false,-1, 31,0);
    tracep->declBit(c+52,"we3D", false,-1);
    tracep->declBit(c+108,"clk", false,-1);
    tracep->declBit(c+107,"triggerD", false,-1);
    tracep->declBus(c+58,"ad3D", false,-1, 4,0);
    tracep->declBit(c+9,"regwriteD", false,-1);
    tracep->declBit(c+10,"resultsrcD", false,-1);
    tracep->declBit(c+11,"memwriteD", false,-1);
    tracep->declBit(c+12,"alusrcD", false,-1);
    tracep->declBit(c+13,"addupperD", false,-1);
    tracep->declBit(c+14,"jbmuxD", false,-1);
    tracep->declBit(c+15,"pcwritemuxD", false,-1);
    tracep->declBus(c+19,"aluctrlD", false,-1, 3,0);
    tracep->declBus(c+16,"immopD", false,-1, 31,0);
    tracep->declBus(c+111,"rd1D", false,-1, 31,0);
    tracep->declBus(c+112,"rd2D", false,-1, 31,0);
    tracep->declBus(c+74,"a0D", false,-1, 31,0);
    tracep->declBus(c+18,"rdD", false,-1, 4,0);
    tracep->declBit(c+60,"funct7D", false,-1);
    tracep->declBus(c+61,"immsrcD", false,-1, 2,0);
    tracep->declBus(c+20,"funct3D", false,-1, 2,0);
    tracep->declBus(c+17,"opcodeD", false,-1, 6,0);
    tracep->declBus(c+62,"signextinD", false,-1, 24,0);
    tracep->declBus(c+63,"ad1D", false,-1, 4,0);
    tracep->declBus(c+64,"ad2D", false,-1, 4,0);
    tracep->pushNamePrefix("ctrlunitD ");
    tracep->declBus(c+17,"opcode", false,-1, 6,0);
    tracep->declBus(c+20,"funct3", false,-1, 2,0);
    tracep->declBit(c+60,"funct7", false,-1);
    tracep->declBit(c+9,"regwrite", false,-1);
    tracep->declBit(c+12,"alusrc", false,-1);
    tracep->declBit(c+11,"memwrite", false,-1);
    tracep->declBit(c+10,"resultsrc", false,-1);
    tracep->declBit(c+15,"pcwritemux", false,-1);
    tracep->declBit(c+14,"jbmux", false,-1);
    tracep->declBit(c+13,"addupper", false,-1);
    tracep->declBus(c+19,"aluctrl", false,-1, 3,0);
    tracep->declBus(c+61,"immsrc", false,-1, 2,0);
    tracep->declBus(c+65,"aluop", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("rfD ");
    tracep->declBus(c+114,"A_WIDTH", false,-1, 31,0);
    tracep->declBus(c+113,"D_WIDTH", false,-1, 31,0);
    tracep->declBit(c+108,"clk", false,-1);
    tracep->declBit(c+52,"we3", false,-1);
    tracep->declBit(c+107,"trigger", false,-1);
    tracep->declBus(c+63,"ad1", false,-1, 4,0);
    tracep->declBus(c+64,"ad2", false,-1, 4,0);
    tracep->declBus(c+58,"ad3", false,-1, 4,0);
    tracep->declBus(c+59,"wd3", false,-1, 31,0);
    tracep->declBus(c+74,"a0", false,-1, 31,0);
    tracep->declBus(c+111,"rd1", false,-1, 31,0);
    tracep->declBus(c+112,"rd2", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+75+i*1,"rf_array", true,(i+0), 31,0);
    }
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+1,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("signexD ");
    tracep->declBus(c+62,"instruction", false,-1, 31,7);
    tracep->declBus(c+61,"immsrc", false,-1, 2,0);
    tracep->declBus(c+16,"immop", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("execute ");
    tracep->declBus(c+113,"D_WIDTH", false,-1, 31,0);
    tracep->declBit(c+23,"alusrc", false,-1);
    tracep->declBus(c+36,"aluctrl", false,-1, 3,0);
    tracep->declBus(c+29,"rf_dout1", false,-1, 31,0);
    tracep->declBus(c+31,"immop", false,-1, 31,0);
    tracep->declBus(c+30,"regop2", false,-1, 31,0);
    tracep->declBus(c+34,"opcode", false,-1, 6,0);
    tracep->declBus(c+37,"funct3", false,-1, 2,0);
    tracep->declBit(c+26,"jbmux", false,-1);
    tracep->declBus(c+32,"prog_addr", false,-1, 31,0);
    tracep->declBit(c+22,"addupper", false,-1);
    tracep->declBus(c+38,"jumpaddress", false,-1, 31,0);
    tracep->declBus(c+39,"aluout", false,-1, 31,0);
    tracep->declBit(c+40,"pcsrc", false,-1);
    tracep->declBit(c+66,"eq", false,-1);
    tracep->declBus(c+67,"rfpc", false,-1, 31,0);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+113,"D_WIDTH", false,-1, 31,0);
    tracep->declBit(c+23,"alusrc", false,-1);
    tracep->declBus(c+36,"aluctrl", false,-1, 3,0);
    tracep->declBus(c+67,"aluop1", false,-1, 31,0);
    tracep->declBus(c+31,"immop", false,-1, 31,0);
    tracep->declBus(c+30,"regop2", false,-1, 31,0);
    tracep->declBus(c+39,"aluout", false,-1, 31,0);
    tracep->declBit(c+66,"eq", false,-1);
    tracep->declBus(c+68,"aluop2", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("fetch ");
    tracep->declBus(c+113,"A_WIDTH", false,-1, 31,0);
    tracep->declBit(c+40,"pcsrc", false,-1);
    tracep->declBit(c+108,"clk", false,-1);
    tracep->declBit(c+109,"rst", false,-1);
    tracep->declBus(c+38,"jumpaddress", false,-1, 31,0);
    tracep->declBus(c+4,"dout", false,-1, 31,0);
    tracep->declBus(c+3,"pc", false,-1, 31,0);
    tracep->declBus(c+5,"pc_plus4", false,-1, 31,0);
    tracep->pushNamePrefix("instrmem ");
    tracep->declBus(c+113,"A_WIDTH", false,-1, 31,0);
    tracep->declBus(c+115,"D_WIDTH", false,-1, 31,0);
    tracep->declBus(c+3,"address", false,-1, 31,0);
    tracep->declBus(c+4,"dout", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcountunit ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+40,"pcsrc", false,-1);
    tracep->declBit(c+108,"clk", false,-1);
    tracep->declBit(c+109,"rst", false,-1);
    tracep->declBus(c+38,"jumpaddress", false,-1, 31,0);
    tracep->declBus(c+3,"pc", false,-1, 31,0);
    tracep->declBus(c+5,"pc_plus4", false,-1, 31,0);
    tracep->declBus(c+69,"next_pc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("memory ");
    tracep->declBus(c+113,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+113,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+108,"clk", false,-1);
    tracep->declBit(c+43,"write_enable", false,-1);
    tracep->declBus(c+50,"addrmode", false,-1, 2,0);
    tracep->declBus(c+70,"selectbytes", false,-1, 1,0);
    tracep->declBus(c+46,"write_data", false,-1, 31,0);
    tracep->declBus(c+71,"address", false,-1, 31,0);
    tracep->declBus(c+51,"read_data", false,-1, 31,0);
    tracep->declBus(c+72,"ramout", false,-1, 31,0);
    tracep->declBus(c+73,"ramin", false,-1, 31,0);
    tracep->pushNamePrefix("loadmem ");
    tracep->declBus(c+113,"D_WIDTH", false,-1, 31,0);
    tracep->declBus(c+50,"addrmode", false,-1, 2,0);
    tracep->declBus(c+70,"selectbytes", false,-1, 1,0);
    tracep->declBus(c+72,"ramout", false,-1, 31,0);
    tracep->declBus(c+51,"read_data", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ram ");
    tracep->declBus(c+113,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+115,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+108,"clk", false,-1);
    tracep->declBit(c+43,"write_enable", false,-1);
    tracep->declBus(c+71,"address", false,-1, 31,0);
    tracep->declBus(c+73,"ramin", false,-1, 31,0);
    tracep->declBus(c+72,"ramout", false,-1, 31,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+2,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("storemem ");
    tracep->declBus(c+113,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+50,"addrmode", false,-1, 2,0);
    tracep->declBus(c+70,"selectbytes", false,-1, 1,0);
    tracep->declBus(c+72,"ramout", false,-1, 31,0);
    tracep->declBus(c+46,"write_data", false,-1, 31,0);
    tracep->declBus(c+73,"ramdin", false,-1, 31,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vcpu_pipelined___024root__trace_init_top(Vcpu_pipelined___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root__trace_init_top\n"); );
    // Body
    Vcpu_pipelined___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vcpu_pipelined___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcpu_pipelined___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcpu_pipelined___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vcpu_pipelined___024root__trace_register(Vcpu_pipelined___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vcpu_pipelined___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vcpu_pipelined___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vcpu_pipelined___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vcpu_pipelined___024root__trace_full_sub_0(Vcpu_pipelined___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vcpu_pipelined___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root__trace_full_top_0\n"); );
    // Init
    Vcpu_pipelined___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu_pipelined___024root*>(voidSelf);
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vcpu_pipelined___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vcpu_pipelined___024root__trace_full_sub_0(Vcpu_pipelined___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+2,(vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+3,(vlSelf->cpu_pipelined__DOT__pcF),32);
    bufp->fullIData(oldp+4,(((vlSelf->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                              [(0xfffU & vlSelf->cpu_pipelined__DOT__pcF)] 
                              << 0x18U) | ((vlSelf->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                            [(0xfffU 
                                              & ((IData)(1U) 
                                                 + vlSelf->cpu_pipelined__DOT__pcF))] 
                                            << 0x10U) 
                                           | ((vlSelf->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                               [(0xfffU 
                                                 & ((IData)(2U) 
                                                    + vlSelf->cpu_pipelined__DOT__pcF))] 
                                               << 8U) 
                                              | vlSelf->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                              [(0xfffU 
                                                & ((IData)(3U) 
                                                   + vlSelf->cpu_pipelined__DOT__pcF))])))),32);
    bufp->fullIData(oldp+5,(vlSelf->cpu_pipelined__DOT__pcplusfourF),32);
    bufp->fullIData(oldp+6,(vlSelf->cpu_pipelined__DOT__pcD),32);
    bufp->fullIData(oldp+7,(vlSelf->cpu_pipelined__DOT__instrD),32);
    bufp->fullIData(oldp+8,(vlSelf->cpu_pipelined__DOT__pcplusfourD),32);
    bufp->fullBit(oldp+9,(vlSelf->cpu_pipelined__DOT__regwriteD));
    bufp->fullBit(oldp+10,(vlSelf->cpu_pipelined__DOT__resultsrcD));
    bufp->fullBit(oldp+11,(vlSelf->cpu_pipelined__DOT__memwriteD));
    bufp->fullBit(oldp+12,(vlSelf->cpu_pipelined__DOT__alusrcD));
    bufp->fullBit(oldp+13,(vlSelf->cpu_pipelined__DOT__addupperD));
    bufp->fullBit(oldp+14,(vlSelf->cpu_pipelined__DOT__jbmuxD));
    bufp->fullBit(oldp+15,(vlSelf->cpu_pipelined__DOT__pcwritemuxD));
    bufp->fullIData(oldp+16,(vlSelf->cpu_pipelined__DOT__immextD),32);
    bufp->fullCData(oldp+17,((0x7fU & vlSelf->cpu_pipelined__DOT__instrD)),7);
    bufp->fullCData(oldp+18,(vlSelf->cpu_pipelined__DOT__rdD),5);
    bufp->fullCData(oldp+19,(((2U & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                               ? ((1U & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                   ? 0xfU : ((0x18U 
                                              & ((vlSelf->cpu_pipelined__DOT__instrD 
                                                  >> 0x1bU) 
                                                 & (((IData)(
                                                             (0x5013U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->cpu_pipelined__DOT__instrD))) 
                                                     | ((0x33U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelf->cpu_pipelined__DOT__instrD)) 
                                                        & ((5U 
                                                            == 
                                                            (7U 
                                                             & (vlSelf->cpu_pipelined__DOT__instrD 
                                                                >> 0xcU))) 
                                                           | (0U 
                                                              == 
                                                              (7U 
                                                               & (vlSelf->cpu_pipelined__DOT__instrD 
                                                                  >> 0xcU)))))) 
                                                    << 3U))) 
                                             | (7U 
                                                & (vlSelf->cpu_pipelined__DOT__instrD 
                                                   >> 0xcU))))
                               : ((1U & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                   ? ((4U & ((~ (vlSelf->cpu_pipelined__DOT__instrD 
                                                 >> 0xeU)) 
                                             << 2U)) 
                                      | (3U & (vlSelf->cpu_pipelined__DOT__instrD 
                                               >> 0xdU)))
                                   : 0U))),4);
    bufp->fullCData(oldp+20,((7U & (vlSelf->cpu_pipelined__DOT__instrD 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+21,(vlSelf->cpu_pipelined__DOT__regwriteE));
    bufp->fullBit(oldp+22,(vlSelf->cpu_pipelined__DOT__addupperE));
    bufp->fullBit(oldp+23,(vlSelf->cpu_pipelined__DOT__alusrcE));
    bufp->fullBit(oldp+24,(vlSelf->cpu_pipelined__DOT__memwriteE));
    bufp->fullBit(oldp+25,(vlSelf->cpu_pipelined__DOT__resultsrcE));
    bufp->fullBit(oldp+26,(vlSelf->cpu_pipelined__DOT__jbmuxE));
    bufp->fullBit(oldp+27,(vlSelf->cpu_pipelined__DOT__pcwritemuxE));
    bufp->fullIData(oldp+28,(vlSelf->cpu_pipelined__DOT__a0E),32);
    bufp->fullIData(oldp+29,(vlSelf->cpu_pipelined__DOT__rd1E),32);
    bufp->fullIData(oldp+30,(vlSelf->cpu_pipelined__DOT__rd2E),32);
    bufp->fullIData(oldp+31,(vlSelf->cpu_pipelined__DOT__immextE),32);
    bufp->fullIData(oldp+32,(vlSelf->cpu_pipelined__DOT__pcE),32);
    bufp->fullIData(oldp+33,(vlSelf->cpu_pipelined__DOT__pcplusfourE),32);
    bufp->fullCData(oldp+34,(vlSelf->cpu_pipelined__DOT__opcodeE),7);
    bufp->fullCData(oldp+35,(vlSelf->cpu_pipelined__DOT__rdE),5);
    bufp->fullCData(oldp+36,(vlSelf->cpu_pipelined__DOT__aluctrlE),4);
    bufp->fullCData(oldp+37,(vlSelf->cpu_pipelined__DOT__funct3E),3);
    bufp->fullIData(oldp+38,(((IData)(vlSelf->cpu_pipelined__DOT__jbmuxE)
                               ? vlSelf->cpu_pipelined__DOT__aluresultE
                               : (vlSelf->cpu_pipelined__DOT__pcE 
                                  + vlSelf->cpu_pipelined__DOT__immextE))),32);
    bufp->fullIData(oldp+39,(vlSelf->cpu_pipelined__DOT__aluresultE),32);
    bufp->fullBit(oldp+40,(vlSelf->cpu_pipelined__DOT__pcsrcE));
    bufp->fullBit(oldp+41,(vlSelf->cpu_pipelined__DOT__regwriteM));
    bufp->fullBit(oldp+42,(vlSelf->cpu_pipelined__DOT__resultsrcM));
    bufp->fullBit(oldp+43,(vlSelf->cpu_pipelined__DOT__memwriteM));
    bufp->fullBit(oldp+44,(vlSelf->cpu_pipelined__DOT__pcwritemuxM));
    bufp->fullIData(oldp+45,(vlSelf->cpu_pipelined__DOT__aluresultM),32);
    bufp->fullIData(oldp+46,(vlSelf->cpu_pipelined__DOT__write_dataM),32);
    bufp->fullIData(oldp+47,(vlSelf->cpu_pipelined__DOT__pcplusfourM),32);
    bufp->fullIData(oldp+48,(vlSelf->cpu_pipelined__DOT__a0M),32);
    bufp->fullCData(oldp+49,(vlSelf->cpu_pipelined__DOT__rdM),5);
    bufp->fullCData(oldp+50,(vlSelf->cpu_pipelined__DOT__funct3M),3);
    bufp->fullIData(oldp+51,(vlSelf->cpu_pipelined__DOT__read_dataM),32);
    bufp->fullBit(oldp+52,(vlSelf->cpu_pipelined__DOT__regwriteW));
    bufp->fullBit(oldp+53,(vlSelf->cpu_pipelined__DOT__resultsrcW));
    bufp->fullBit(oldp+54,(vlSelf->cpu_pipelined__DOT__pcwritemuxW));
    bufp->fullIData(oldp+55,(vlSelf->cpu_pipelined__DOT__read_dataW),32);
    bufp->fullIData(oldp+56,(vlSelf->cpu_pipelined__DOT__aluresultW),32);
    bufp->fullIData(oldp+57,(vlSelf->cpu_pipelined__DOT__pcplusfourW),32);
    bufp->fullCData(oldp+58,(vlSelf->cpu_pipelined__DOT__rdW),5);
    bufp->fullIData(oldp+59,(((1U == (((IData)(vlSelf->cpu_pipelined__DOT__pcwritemuxW) 
                                       << 1U) | (IData)(vlSelf->cpu_pipelined__DOT__resultsrcW)))
                               ? vlSelf->cpu_pipelined__DOT__read_dataW
                               : ((2U == (((IData)(vlSelf->cpu_pipelined__DOT__pcwritemuxW) 
                                           << 1U) | (IData)(vlSelf->cpu_pipelined__DOT__resultsrcW)))
                                   ? vlSelf->cpu_pipelined__DOT__pcplusfourW
                                   : vlSelf->cpu_pipelined__DOT__aluresultW))),32);
    bufp->fullBit(oldp+60,((1U & (vlSelf->cpu_pipelined__DOT__instrD 
                                  >> 0x1eU))));
    bufp->fullCData(oldp+61,(vlSelf->cpu_pipelined__DOT__decode__DOT__immsrcD),3);
    bufp->fullIData(oldp+62,((vlSelf->cpu_pipelined__DOT__instrD 
                              >> 7U)),25);
    bufp->fullCData(oldp+63,((0x1fU & (vlSelf->cpu_pipelined__DOT__instrD 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+64,((0x1fU & (vlSelf->cpu_pipelined__DOT__instrD 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+65,(vlSelf->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop),2);
    bufp->fullBit(oldp+66,(vlSelf->cpu_pipelined__DOT__execute__DOT__eq));
    bufp->fullIData(oldp+67,(vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc),32);
    bufp->fullIData(oldp+68,(vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2),32);
    bufp->fullIData(oldp+69,(vlSelf->cpu_pipelined__DOT__fetch__DOT__pcountunit__DOT__next_pc),32);
    bufp->fullCData(oldp+70,((3U & vlSelf->cpu_pipelined__DOT__aluresultM)),2);
    bufp->fullIData(oldp+71,((0xfffffffcU & vlSelf->cpu_pipelined__DOT__aluresultM)),32);
    bufp->fullIData(oldp+72,(vlSelf->cpu_pipelined__DOT__memory__DOT__ramout),32);
    bufp->fullIData(oldp+73,(vlSelf->cpu_pipelined__DOT__memory__DOT__ramin),32);
    bufp->fullIData(oldp+74,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
                             [0xaU]),32);
    bufp->fullIData(oldp+75,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0]),32);
    bufp->fullIData(oldp+76,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[1]),32);
    bufp->fullIData(oldp+77,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[2]),32);
    bufp->fullIData(oldp+78,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[3]),32);
    bufp->fullIData(oldp+79,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[4]),32);
    bufp->fullIData(oldp+80,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[5]),32);
    bufp->fullIData(oldp+81,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[6]),32);
    bufp->fullIData(oldp+82,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[7]),32);
    bufp->fullIData(oldp+83,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[8]),32);
    bufp->fullIData(oldp+84,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[9]),32);
    bufp->fullIData(oldp+85,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[10]),32);
    bufp->fullIData(oldp+86,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[11]),32);
    bufp->fullIData(oldp+87,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[12]),32);
    bufp->fullIData(oldp+88,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[13]),32);
    bufp->fullIData(oldp+89,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[14]),32);
    bufp->fullIData(oldp+90,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[15]),32);
    bufp->fullIData(oldp+91,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[16]),32);
    bufp->fullIData(oldp+92,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[17]),32);
    bufp->fullIData(oldp+93,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[18]),32);
    bufp->fullIData(oldp+94,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[19]),32);
    bufp->fullIData(oldp+95,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[20]),32);
    bufp->fullIData(oldp+96,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[21]),32);
    bufp->fullIData(oldp+97,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[22]),32);
    bufp->fullIData(oldp+98,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[23]),32);
    bufp->fullIData(oldp+99,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[24]),32);
    bufp->fullIData(oldp+100,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[25]),32);
    bufp->fullIData(oldp+101,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[26]),32);
    bufp->fullIData(oldp+102,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[27]),32);
    bufp->fullIData(oldp+103,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[28]),32);
    bufp->fullIData(oldp+104,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[29]),32);
    bufp->fullIData(oldp+105,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[30]),32);
    bufp->fullIData(oldp+106,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[31]),32);
    bufp->fullBit(oldp+107,(vlSelf->trigger));
    bufp->fullBit(oldp+108,(vlSelf->clk));
    bufp->fullBit(oldp+109,(vlSelf->rst));
    bufp->fullIData(oldp+110,(vlSelf->a0W),32);
    bufp->fullIData(oldp+111,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
                              [(0x1fU & (vlSelf->cpu_pipelined__DOT__instrD 
                                         >> 0xfU))]),32);
    bufp->fullIData(oldp+112,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
                              [(0x1fU & (vlSelf->cpu_pipelined__DOT__instrD 
                                         >> 0x14U))]),32);
    bufp->fullIData(oldp+113,(0x20U),32);
    bufp->fullIData(oldp+114,(5U),32);
    bufp->fullIData(oldp+115,(8U),32);
}
