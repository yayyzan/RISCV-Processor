// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu_pipelined__Syms.h"


//======================

void Vcpu_pipelined::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vcpu_pipelined::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcpu_pipelined__Syms* __restrict vlSymsp = static_cast<Vcpu_pipelined__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vcpu_pipelined::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vcpu_pipelined::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vcpu_pipelined__Syms* __restrict vlSymsp = static_cast<Vcpu_pipelined__Syms*>(userp);
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vcpu_pipelined::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vcpu_pipelined__Syms* __restrict vlSymsp = static_cast<Vcpu_pipelined__Syms*>(userp);
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+107,"trigger", false,-1);
        tracep->declBit(c+108,"clk", false,-1);
        tracep->declBit(c+109,"rst", false,-1);
        tracep->declBus(c+110,"a0W", false,-1, 31,0);
        tracep->declBus(c+113,"cpu_pipelined WIDTH", false,-1, 31,0);
        tracep->declBit(c+107,"cpu_pipelined trigger", false,-1);
        tracep->declBit(c+108,"cpu_pipelined clk", false,-1);
        tracep->declBit(c+109,"cpu_pipelined rst", false,-1);
        tracep->declBus(c+110,"cpu_pipelined a0W", false,-1, 31,0);
        tracep->declBus(c+3,"cpu_pipelined pcF", false,-1, 31,0);
        tracep->declBus(c+4,"cpu_pipelined instrF", false,-1, 31,0);
        tracep->declBus(c+5,"cpu_pipelined pcplusfourF", false,-1, 31,0);
        tracep->declBus(c+6,"cpu_pipelined pcD", false,-1, 31,0);
        tracep->declBus(c+7,"cpu_pipelined instrD", false,-1, 31,0);
        tracep->declBus(c+8,"cpu_pipelined pcplusfourD", false,-1, 31,0);
        tracep->declBit(c+9,"cpu_pipelined regwriteD", false,-1);
        tracep->declBit(c+10,"cpu_pipelined resultsrcD", false,-1);
        tracep->declBit(c+11,"cpu_pipelined memwriteD", false,-1);
        tracep->declBit(c+12,"cpu_pipelined alusrcD", false,-1);
        tracep->declBit(c+13,"cpu_pipelined addupperD", false,-1);
        tracep->declBit(c+14,"cpu_pipelined jbmuxD", false,-1);
        tracep->declBit(c+15,"cpu_pipelined pcwritemuxD", false,-1);
        tracep->declBus(c+74,"cpu_pipelined a0D", false,-1, 31,0);
        tracep->declBus(c+111,"cpu_pipelined rd1D", false,-1, 31,0);
        tracep->declBus(c+112,"cpu_pipelined rd2D", false,-1, 31,0);
        tracep->declBus(c+16,"cpu_pipelined immextD", false,-1, 31,0);
        tracep->declBus(c+17,"cpu_pipelined opcodeD", false,-1, 6,0);
        tracep->declBus(c+18,"cpu_pipelined rdD", false,-1, 4,0);
        tracep->declBus(c+19,"cpu_pipelined aluctrlD", false,-1, 3,0);
        tracep->declBus(c+20,"cpu_pipelined funct3D", false,-1, 2,0);
        tracep->declBit(c+21,"cpu_pipelined regwriteE", false,-1);
        tracep->declBit(c+22,"cpu_pipelined addupperE", false,-1);
        tracep->declBit(c+23,"cpu_pipelined alusrcE", false,-1);
        tracep->declBit(c+24,"cpu_pipelined memwriteE", false,-1);
        tracep->declBit(c+25,"cpu_pipelined resultsrcE", false,-1);
        tracep->declBit(c+26,"cpu_pipelined jbmuxE", false,-1);
        tracep->declBit(c+27,"cpu_pipelined pcwritemuxE", false,-1);
        tracep->declBus(c+28,"cpu_pipelined a0E", false,-1, 31,0);
        tracep->declBus(c+29,"cpu_pipelined rd1E", false,-1, 31,0);
        tracep->declBus(c+30,"cpu_pipelined rd2E", false,-1, 31,0);
        tracep->declBus(c+31,"cpu_pipelined immextE", false,-1, 31,0);
        tracep->declBus(c+32,"cpu_pipelined pcE", false,-1, 31,0);
        tracep->declBus(c+33,"cpu_pipelined pcplusfourE", false,-1, 31,0);
        tracep->declBus(c+34,"cpu_pipelined opcodeE", false,-1, 6,0);
        tracep->declBus(c+35,"cpu_pipelined rdE", false,-1, 4,0);
        tracep->declBus(c+36,"cpu_pipelined aluctrlE", false,-1, 3,0);
        tracep->declBus(c+37,"cpu_pipelined funct3E", false,-1, 2,0);
        tracep->declBus(c+38,"cpu_pipelined pctargetE", false,-1, 31,0);
        tracep->declBus(c+39,"cpu_pipelined aluresultE", false,-1, 31,0);
        tracep->declBit(c+40,"cpu_pipelined pcsrcE", false,-1);
        tracep->declBit(c+41,"cpu_pipelined regwriteM", false,-1);
        tracep->declBit(c+42,"cpu_pipelined resultsrcM", false,-1);
        tracep->declBit(c+43,"cpu_pipelined memwriteM", false,-1);
        tracep->declBit(c+44,"cpu_pipelined pcwritemuxM", false,-1);
        tracep->declBus(c+45,"cpu_pipelined aluresultM", false,-1, 31,0);
        tracep->declBus(c+46,"cpu_pipelined write_dataM", false,-1, 31,0);
        tracep->declBus(c+47,"cpu_pipelined pcplusfourM", false,-1, 31,0);
        tracep->declBus(c+48,"cpu_pipelined a0M", false,-1, 31,0);
        tracep->declBus(c+49,"cpu_pipelined rdM", false,-1, 4,0);
        tracep->declBus(c+50,"cpu_pipelined funct3M", false,-1, 2,0);
        tracep->declBus(c+51,"cpu_pipelined read_dataM", false,-1, 31,0);
        tracep->declBit(c+52,"cpu_pipelined regwriteW", false,-1);
        tracep->declBit(c+53,"cpu_pipelined resultsrcW", false,-1);
        tracep->declBit(c+54,"cpu_pipelined pcwritemuxW", false,-1);
        tracep->declBus(c+55,"cpu_pipelined read_dataW", false,-1, 31,0);
        tracep->declBus(c+56,"cpu_pipelined aluresultW", false,-1, 31,0);
        tracep->declBus(c+57,"cpu_pipelined pcplusfourW", false,-1, 31,0);
        tracep->declBus(c+58,"cpu_pipelined rdW", false,-1, 4,0);
        tracep->declBus(c+59,"cpu_pipelined resultW", false,-1, 31,0);
        tracep->declBus(c+113,"cpu_pipelined fetch A_WIDTH", false,-1, 31,0);
        tracep->declBit(c+40,"cpu_pipelined fetch pcsrc", false,-1);
        tracep->declBit(c+108,"cpu_pipelined fetch clk", false,-1);
        tracep->declBit(c+109,"cpu_pipelined fetch rst", false,-1);
        tracep->declBus(c+38,"cpu_pipelined fetch jumpaddress", false,-1, 31,0);
        tracep->declBus(c+4,"cpu_pipelined fetch dout", false,-1, 31,0);
        tracep->declBus(c+3,"cpu_pipelined fetch pc", false,-1, 31,0);
        tracep->declBus(c+5,"cpu_pipelined fetch pc_plus4", false,-1, 31,0);
        tracep->declBus(c+113,"cpu_pipelined fetch pcountunit WIDTH", false,-1, 31,0);
        tracep->declBit(c+40,"cpu_pipelined fetch pcountunit pcsrc", false,-1);
        tracep->declBit(c+108,"cpu_pipelined fetch pcountunit clk", false,-1);
        tracep->declBit(c+109,"cpu_pipelined fetch pcountunit rst", false,-1);
        tracep->declBus(c+38,"cpu_pipelined fetch pcountunit jumpaddress", false,-1, 31,0);
        tracep->declBus(c+3,"cpu_pipelined fetch pcountunit pc", false,-1, 31,0);
        tracep->declBus(c+5,"cpu_pipelined fetch pcountunit pc_plus4", false,-1, 31,0);
        tracep->declBus(c+60,"cpu_pipelined fetch pcountunit next_pc", false,-1, 31,0);
        tracep->declBus(c+113,"cpu_pipelined fetch instrmem A_WIDTH", false,-1, 31,0);
        tracep->declBus(c+114,"cpu_pipelined fetch instrmem D_WIDTH", false,-1, 31,0);
        tracep->declBus(c+3,"cpu_pipelined fetch instrmem address", false,-1, 31,0);
        tracep->declBus(c+4,"cpu_pipelined fetch instrmem dout", false,-1, 31,0);
        tracep->declBus(c+59,"cpu_pipelined decode wd3D", false,-1, 31,0);
        tracep->declBus(c+7,"cpu_pipelined decode instrD", false,-1, 31,0);
        tracep->declBit(c+52,"cpu_pipelined decode we3D", false,-1);
        tracep->declBit(c+108,"cpu_pipelined decode clk", false,-1);
        tracep->declBit(c+107,"cpu_pipelined decode triggerD", false,-1);
        tracep->declBus(c+58,"cpu_pipelined decode ad3D", false,-1, 4,0);
        tracep->declBit(c+9,"cpu_pipelined decode regwriteD", false,-1);
        tracep->declBit(c+10,"cpu_pipelined decode resultsrcD", false,-1);
        tracep->declBit(c+11,"cpu_pipelined decode memwriteD", false,-1);
        tracep->declBit(c+12,"cpu_pipelined decode alusrcD", false,-1);
        tracep->declBit(c+13,"cpu_pipelined decode addupperD", false,-1);
        tracep->declBit(c+14,"cpu_pipelined decode jbmuxD", false,-1);
        tracep->declBit(c+15,"cpu_pipelined decode pcwritemuxD", false,-1);
        tracep->declBus(c+19,"cpu_pipelined decode aluctrlD", false,-1, 3,0);
        tracep->declBus(c+16,"cpu_pipelined decode immopD", false,-1, 31,0);
        tracep->declBus(c+111,"cpu_pipelined decode rd1D", false,-1, 31,0);
        tracep->declBus(c+112,"cpu_pipelined decode rd2D", false,-1, 31,0);
        tracep->declBus(c+74,"cpu_pipelined decode a0D", false,-1, 31,0);
        tracep->declBus(c+18,"cpu_pipelined decode rdD", false,-1, 4,0);
        tracep->declBit(c+61,"cpu_pipelined decode funct7D", false,-1);
        tracep->declBus(c+62,"cpu_pipelined decode immsrcD", false,-1, 2,0);
        tracep->declBus(c+20,"cpu_pipelined decode funct3D", false,-1, 2,0);
        tracep->declBus(c+17,"cpu_pipelined decode opcodeD", false,-1, 6,0);
        tracep->declBus(c+63,"cpu_pipelined decode signextinD", false,-1, 24,0);
        tracep->declBus(c+64,"cpu_pipelined decode ad1D", false,-1, 4,0);
        tracep->declBus(c+65,"cpu_pipelined decode ad2D", false,-1, 4,0);
        tracep->declBus(c+17,"cpu_pipelined decode ctrlunitD opcode", false,-1, 6,0);
        tracep->declBus(c+20,"cpu_pipelined decode ctrlunitD funct3", false,-1, 2,0);
        tracep->declBit(c+61,"cpu_pipelined decode ctrlunitD funct7", false,-1);
        tracep->declBit(c+9,"cpu_pipelined decode ctrlunitD regwrite", false,-1);
        tracep->declBit(c+12,"cpu_pipelined decode ctrlunitD alusrc", false,-1);
        tracep->declBit(c+11,"cpu_pipelined decode ctrlunitD memwrite", false,-1);
        tracep->declBit(c+10,"cpu_pipelined decode ctrlunitD resultsrc", false,-1);
        tracep->declBit(c+15,"cpu_pipelined decode ctrlunitD pcwritemux", false,-1);
        tracep->declBit(c+14,"cpu_pipelined decode ctrlunitD jbmux", false,-1);
        tracep->declBit(c+13,"cpu_pipelined decode ctrlunitD addupper", false,-1);
        tracep->declBus(c+19,"cpu_pipelined decode ctrlunitD aluctrl", false,-1, 3,0);
        tracep->declBus(c+62,"cpu_pipelined decode ctrlunitD immsrc", false,-1, 2,0);
        tracep->declBus(c+66,"cpu_pipelined decode ctrlunitD aluop", false,-1, 1,0);
        tracep->declBus(c+115,"cpu_pipelined decode rfD A_WIDTH", false,-1, 31,0);
        tracep->declBus(c+113,"cpu_pipelined decode rfD D_WIDTH", false,-1, 31,0);
        tracep->declBit(c+108,"cpu_pipelined decode rfD clk", false,-1);
        tracep->declBit(c+52,"cpu_pipelined decode rfD we3", false,-1);
        tracep->declBit(c+107,"cpu_pipelined decode rfD trigger", false,-1);
        tracep->declBus(c+64,"cpu_pipelined decode rfD ad1", false,-1, 4,0);
        tracep->declBus(c+65,"cpu_pipelined decode rfD ad2", false,-1, 4,0);
        tracep->declBus(c+58,"cpu_pipelined decode rfD ad3", false,-1, 4,0);
        tracep->declBus(c+59,"cpu_pipelined decode rfD wd3", false,-1, 31,0);
        tracep->declBus(c+74,"cpu_pipelined decode rfD a0", false,-1, 31,0);
        tracep->declBus(c+111,"cpu_pipelined decode rfD rd1", false,-1, 31,0);
        tracep->declBus(c+112,"cpu_pipelined decode rfD rd2", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+75+i*1,"cpu_pipelined decode rfD rf_array", true,(i+0), 31,0);}}
        tracep->declBus(c+1,"cpu_pipelined decode rfD unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+63,"cpu_pipelined decode signexD instruction", false,-1, 31,7);
        tracep->declBus(c+62,"cpu_pipelined decode signexD immsrc", false,-1, 2,0);
        tracep->declBus(c+16,"cpu_pipelined decode signexD immop", false,-1, 31,0);
        tracep->declBus(c+113,"cpu_pipelined execute D_WIDTH", false,-1, 31,0);
        tracep->declBit(c+108,"cpu_pipelined execute clk", false,-1);
        tracep->declBit(c+23,"cpu_pipelined execute alusrc", false,-1);
        tracep->declBus(c+36,"cpu_pipelined execute aluctrl", false,-1, 3,0);
        tracep->declBus(c+29,"cpu_pipelined execute rf_dout1", false,-1, 31,0);
        tracep->declBus(c+31,"cpu_pipelined execute immop", false,-1, 31,0);
        tracep->declBus(c+30,"cpu_pipelined execute regop2", false,-1, 31,0);
        tracep->declBus(c+34,"cpu_pipelined execute opcode", false,-1, 6,0);
        tracep->declBus(c+37,"cpu_pipelined execute funct3", false,-1, 2,0);
        tracep->declBit(c+26,"cpu_pipelined execute jbmux", false,-1);
        tracep->declBus(c+32,"cpu_pipelined execute prog_addr", false,-1, 31,0);
        tracep->declBit(c+22,"cpu_pipelined execute addupper", false,-1);
        tracep->declBus(c+38,"cpu_pipelined execute jumpaddress", false,-1, 31,0);
        tracep->declBus(c+39,"cpu_pipelined execute aluout", false,-1, 31,0);
        tracep->declBit(c+40,"cpu_pipelined execute pcsrc", false,-1);
        tracep->declBit(c+67,"cpu_pipelined execute eq", false,-1);
        tracep->declBus(c+68,"cpu_pipelined execute rfpc", false,-1, 31,0);
        tracep->declBus(c+113,"cpu_pipelined execute alu D_WIDTH", false,-1, 31,0);
        tracep->declBit(c+23,"cpu_pipelined execute alu alusrc", false,-1);
        tracep->declBus(c+36,"cpu_pipelined execute alu aluctrl", false,-1, 3,0);
        tracep->declBus(c+68,"cpu_pipelined execute alu aluop1", false,-1, 31,0);
        tracep->declBus(c+31,"cpu_pipelined execute alu immop", false,-1, 31,0);
        tracep->declBus(c+30,"cpu_pipelined execute alu regop2", false,-1, 31,0);
        tracep->declBus(c+39,"cpu_pipelined execute alu aluout", false,-1, 31,0);
        tracep->declBit(c+67,"cpu_pipelined execute alu eq", false,-1);
        tracep->declBus(c+69,"cpu_pipelined execute alu aluop2", false,-1, 31,0);
        tracep->declBus(c+113,"cpu_pipelined memory ADDRESS_WIDTH", false,-1, 31,0);
        tracep->declBus(c+113,"cpu_pipelined memory DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+108,"cpu_pipelined memory clk", false,-1);
        tracep->declBit(c+43,"cpu_pipelined memory write_enable", false,-1);
        tracep->declBus(c+50,"cpu_pipelined memory addrmode", false,-1, 2,0);
        tracep->declBus(c+70,"cpu_pipelined memory selectbytes", false,-1, 1,0);
        tracep->declBus(c+46,"cpu_pipelined memory write_data", false,-1, 31,0);
        tracep->declBus(c+71,"cpu_pipelined memory address", false,-1, 31,0);
        tracep->declBus(c+51,"cpu_pipelined memory read_data", false,-1, 31,0);
        tracep->declBus(c+72,"cpu_pipelined memory ramout", false,-1, 31,0);
        tracep->declBus(c+73,"cpu_pipelined memory ramin", false,-1, 31,0);
        tracep->declBus(c+113,"cpu_pipelined memory storemem DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+50,"cpu_pipelined memory storemem addrmode", false,-1, 2,0);
        tracep->declBus(c+70,"cpu_pipelined memory storemem selectbytes", false,-1, 1,0);
        tracep->declBus(c+72,"cpu_pipelined memory storemem ramout", false,-1, 31,0);
        tracep->declBus(c+46,"cpu_pipelined memory storemem write_data", false,-1, 31,0);
        tracep->declBus(c+73,"cpu_pipelined memory storemem ramdin", false,-1, 31,0);
        tracep->declBus(c+113,"cpu_pipelined memory ram ADDRESS_WIDTH", false,-1, 31,0);
        tracep->declBus(c+114,"cpu_pipelined memory ram DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+108,"cpu_pipelined memory ram clk", false,-1);
        tracep->declBit(c+43,"cpu_pipelined memory ram write_enable", false,-1);
        tracep->declBus(c+71,"cpu_pipelined memory ram address", false,-1, 31,0);
        tracep->declBus(c+73,"cpu_pipelined memory ram ramin", false,-1, 31,0);
        tracep->declBus(c+72,"cpu_pipelined memory ram ramout", false,-1, 31,0);
        tracep->declBus(c+2,"cpu_pipelined memory ram unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+113,"cpu_pipelined memory loadmem D_WIDTH", false,-1, 31,0);
        tracep->declBus(c+50,"cpu_pipelined memory loadmem addrmode", false,-1, 2,0);
        tracep->declBus(c+70,"cpu_pipelined memory loadmem selectbytes", false,-1, 1,0);
        tracep->declBus(c+72,"cpu_pipelined memory loadmem ramout", false,-1, 31,0);
        tracep->declBus(c+51,"cpu_pipelined memory loadmem read_data", false,-1, 31,0);
    }
}

void Vcpu_pipelined::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vcpu_pipelined::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vcpu_pipelined__Syms* __restrict vlSymsp = static_cast<Vcpu_pipelined__Syms*>(userp);
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vcpu_pipelined::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vcpu_pipelined__Syms* __restrict vlSymsp = static_cast<Vcpu_pipelined__Syms*>(userp);
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__unnamedblk1__DOT__i),32);
        tracep->fullIData(oldp+2,(vlTOPp->cpu_pipelined__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i),32);
        tracep->fullIData(oldp+3,(vlTOPp->cpu_pipelined__DOT__pcF),32);
        tracep->fullIData(oldp+4,(((vlTOPp->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                    [(0xfffU & vlTOPp->cpu_pipelined__DOT__pcF)] 
                                    << 0x18U) | ((vlTOPp->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                                  [
                                                  (0xfffU 
                                                   & ((IData)(1U) 
                                                      + vlTOPp->cpu_pipelined__DOT__pcF))] 
                                                  << 0x10U) 
                                                 | ((vlTOPp->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                                     [
                                                     (0xfffU 
                                                      & ((IData)(2U) 
                                                         + vlTOPp->cpu_pipelined__DOT__pcF))] 
                                                     << 8U) 
                                                    | vlTOPp->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                                    [
                                                    (0xfffU 
                                                     & ((IData)(3U) 
                                                        + vlTOPp->cpu_pipelined__DOT__pcF))])))),32);
        tracep->fullIData(oldp+5,(vlTOPp->cpu_pipelined__DOT__pcplusfourF),32);
        tracep->fullIData(oldp+6,(vlTOPp->cpu_pipelined__DOT__pcD),32);
        tracep->fullIData(oldp+7,(vlTOPp->cpu_pipelined__DOT__instrD),32);
        tracep->fullIData(oldp+8,(vlTOPp->cpu_pipelined__DOT__pcplusfourD),32);
        tracep->fullBit(oldp+9,(vlTOPp->cpu_pipelined__DOT__regwriteD));
        tracep->fullBit(oldp+10,(vlTOPp->cpu_pipelined__DOT__resultsrcD));
        tracep->fullBit(oldp+11,(vlTOPp->cpu_pipelined__DOT__memwriteD));
        tracep->fullBit(oldp+12,(vlTOPp->cpu_pipelined__DOT__alusrcD));
        tracep->fullBit(oldp+13,(vlTOPp->cpu_pipelined__DOT__addupperD));
        tracep->fullBit(oldp+14,(vlTOPp->cpu_pipelined__DOT__jbmuxD));
        tracep->fullBit(oldp+15,(vlTOPp->cpu_pipelined__DOT__pcwritemuxD));
        tracep->fullIData(oldp+16,(vlTOPp->cpu_pipelined__DOT__immextD),32);
        tracep->fullCData(oldp+17,((0x7fU & vlTOPp->cpu_pipelined__DOT__instrD)),7);
        tracep->fullCData(oldp+18,(vlTOPp->cpu_pipelined__DOT__rdD),5);
        tracep->fullCData(oldp+19,(((2U & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                     ? ((1U & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                         ? 0xfU : (
                                                   (0x18U 
                                                    & ((vlTOPp->cpu_pipelined__DOT__instrD 
                                                        >> 0x1bU) 
                                                       & ((((0x13U 
                                                             == 
                                                             (0x7fU 
                                                              & vlTOPp->cpu_pipelined__DOT__instrD)) 
                                                            & (5U 
                                                               == 
                                                               (7U 
                                                                & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                                   >> 0xcU)))) 
                                                           | ((0x33U 
                                                               == 
                                                               (0x7fU 
                                                                & vlTOPp->cpu_pipelined__DOT__instrD)) 
                                                              & ((5U 
                                                                  == 
                                                                  (7U 
                                                                   & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                                      >> 0xcU))) 
                                                                 | (0U 
                                                                    == 
                                                                    (7U 
                                                                     & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                                        >> 0xcU)))))) 
                                                          << 3U))) 
                                                   | (7U 
                                                      & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                         >> 0xcU))))
                                     : ((1U & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                         ? ((4U & (
                                                   (~ 
                                                    (vlTOPp->cpu_pipelined__DOT__instrD 
                                                     >> 0xeU)) 
                                                   << 2U)) 
                                            | (3U & 
                                               (vlTOPp->cpu_pipelined__DOT__instrD 
                                                >> 0xdU)))
                                         : 0U))),4);
        tracep->fullCData(oldp+20,((7U & (vlTOPp->cpu_pipelined__DOT__instrD 
                                          >> 0xcU))),3);
        tracep->fullBit(oldp+21,(vlTOPp->cpu_pipelined__DOT__regwriteE));
        tracep->fullBit(oldp+22,(vlTOPp->cpu_pipelined__DOT__addupperE));
        tracep->fullBit(oldp+23,(vlTOPp->cpu_pipelined__DOT__alusrcE));
        tracep->fullBit(oldp+24,(vlTOPp->cpu_pipelined__DOT__memwriteE));
        tracep->fullBit(oldp+25,(vlTOPp->cpu_pipelined__DOT__resultsrcE));
        tracep->fullBit(oldp+26,(vlTOPp->cpu_pipelined__DOT__jbmuxE));
        tracep->fullBit(oldp+27,(vlTOPp->cpu_pipelined__DOT__pcwritemuxE));
        tracep->fullIData(oldp+28,(vlTOPp->cpu_pipelined__DOT__a0E),32);
        tracep->fullIData(oldp+29,(vlTOPp->cpu_pipelined__DOT__rd1E),32);
        tracep->fullIData(oldp+30,(vlTOPp->cpu_pipelined__DOT__rd2E),32);
        tracep->fullIData(oldp+31,(vlTOPp->cpu_pipelined__DOT__immextE),32);
        tracep->fullIData(oldp+32,(vlTOPp->cpu_pipelined__DOT__pcE),32);
        tracep->fullIData(oldp+33,(vlTOPp->cpu_pipelined__DOT__pcplusfourE),32);
        tracep->fullCData(oldp+34,(vlTOPp->cpu_pipelined__DOT__opcodeE),7);
        tracep->fullCData(oldp+35,(vlTOPp->cpu_pipelined__DOT__rdE),5);
        tracep->fullCData(oldp+36,(vlTOPp->cpu_pipelined__DOT__aluctrlE),4);
        tracep->fullCData(oldp+37,(vlTOPp->cpu_pipelined__DOT__funct3E),3);
        tracep->fullIData(oldp+38,(((IData)(vlTOPp->cpu_pipelined__DOT__jbmuxE)
                                     ? vlTOPp->cpu_pipelined__DOT__aluresultE
                                     : (vlTOPp->cpu_pipelined__DOT__pcE 
                                        + vlTOPp->cpu_pipelined__DOT__immextE))),32);
        tracep->fullIData(oldp+39,(vlTOPp->cpu_pipelined__DOT__aluresultE),32);
        tracep->fullBit(oldp+40,(vlTOPp->cpu_pipelined__DOT__pcsrcE));
        tracep->fullBit(oldp+41,(vlTOPp->cpu_pipelined__DOT__regwriteM));
        tracep->fullBit(oldp+42,(vlTOPp->cpu_pipelined__DOT__resultsrcM));
        tracep->fullBit(oldp+43,(vlTOPp->cpu_pipelined__DOT__memwriteM));
        tracep->fullBit(oldp+44,(vlTOPp->cpu_pipelined__DOT__pcwritemuxM));
        tracep->fullIData(oldp+45,(vlTOPp->cpu_pipelined__DOT__aluresultM),32);
        tracep->fullIData(oldp+46,(vlTOPp->cpu_pipelined__DOT__write_dataM),32);
        tracep->fullIData(oldp+47,(vlTOPp->cpu_pipelined__DOT__pcplusfourM),32);
        tracep->fullIData(oldp+48,(vlTOPp->cpu_pipelined__DOT__a0M),32);
        tracep->fullCData(oldp+49,(vlTOPp->cpu_pipelined__DOT__rdM),5);
        tracep->fullCData(oldp+50,(vlTOPp->cpu_pipelined__DOT__funct3M),3);
        tracep->fullIData(oldp+51,(vlTOPp->cpu_pipelined__DOT__read_dataM),32);
        tracep->fullBit(oldp+52,(vlTOPp->cpu_pipelined__DOT__regwriteW));
        tracep->fullBit(oldp+53,(vlTOPp->cpu_pipelined__DOT__resultsrcW));
        tracep->fullBit(oldp+54,(vlTOPp->cpu_pipelined__DOT__pcwritemuxW));
        tracep->fullIData(oldp+55,(vlTOPp->cpu_pipelined__DOT__read_dataW),32);
        tracep->fullIData(oldp+56,(vlTOPp->cpu_pipelined__DOT__aluresultW),32);
        tracep->fullIData(oldp+57,(vlTOPp->cpu_pipelined__DOT__pcplusfourW),32);
        tracep->fullCData(oldp+58,(vlTOPp->cpu_pipelined__DOT__rdW),5);
        tracep->fullIData(oldp+59,(((1U == (((IData)(vlTOPp->cpu_pipelined__DOT__pcwritemuxW) 
                                             << 1U) 
                                            | (IData)(vlTOPp->cpu_pipelined__DOT__resultsrcW)))
                                     ? vlTOPp->cpu_pipelined__DOT__read_dataW
                                     : ((2U == (((IData)(vlTOPp->cpu_pipelined__DOT__pcwritemuxW) 
                                                 << 1U) 
                                                | (IData)(vlTOPp->cpu_pipelined__DOT__resultsrcW)))
                                         ? vlTOPp->cpu_pipelined__DOT__pcplusfourW
                                         : vlTOPp->cpu_pipelined__DOT__aluresultW))),32);
        tracep->fullIData(oldp+60,(vlTOPp->cpu_pipelined__DOT__fetch__DOT__pcountunit__DOT__next_pc),32);
        tracep->fullBit(oldp+61,((1U & (vlTOPp->cpu_pipelined__DOT__instrD 
                                        >> 0x1eU))));
        tracep->fullCData(oldp+62,(vlTOPp->cpu_pipelined__DOT__decode__DOT__immsrcD),3);
        tracep->fullIData(oldp+63,((0x1ffffffU & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                  >> 7U))),25);
        tracep->fullCData(oldp+64,((0x1fU & (vlTOPp->cpu_pipelined__DOT__instrD 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+65,((0x1fU & (vlTOPp->cpu_pipelined__DOT__instrD 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+66,(vlTOPp->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop),2);
        tracep->fullBit(oldp+67,(vlTOPp->cpu_pipelined__DOT__execute__DOT__eq));
        tracep->fullIData(oldp+68,(vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc),32);
        tracep->fullIData(oldp+69,(vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2),32);
        tracep->fullCData(oldp+70,((3U & vlTOPp->cpu_pipelined__DOT__aluresultM)),2);
        tracep->fullIData(oldp+71,((0xfffffffcU & vlTOPp->cpu_pipelined__DOT__aluresultM)),32);
        tracep->fullIData(oldp+72,(vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout),32);
        tracep->fullIData(oldp+73,(vlTOPp->cpu_pipelined__DOT__memory__DOT__ramin),32);
        tracep->fullIData(oldp+74,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
                                   [0xaU]),32);
        tracep->fullIData(oldp+75,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0]),32);
        tracep->fullIData(oldp+76,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[1]),32);
        tracep->fullIData(oldp+77,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[2]),32);
        tracep->fullIData(oldp+78,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[3]),32);
        tracep->fullIData(oldp+79,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[4]),32);
        tracep->fullIData(oldp+80,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[5]),32);
        tracep->fullIData(oldp+81,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[6]),32);
        tracep->fullIData(oldp+82,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[7]),32);
        tracep->fullIData(oldp+83,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[8]),32);
        tracep->fullIData(oldp+84,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[9]),32);
        tracep->fullIData(oldp+85,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[10]),32);
        tracep->fullIData(oldp+86,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[11]),32);
        tracep->fullIData(oldp+87,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[12]),32);
        tracep->fullIData(oldp+88,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[13]),32);
        tracep->fullIData(oldp+89,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[14]),32);
        tracep->fullIData(oldp+90,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[15]),32);
        tracep->fullIData(oldp+91,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[16]),32);
        tracep->fullIData(oldp+92,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[17]),32);
        tracep->fullIData(oldp+93,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[18]),32);
        tracep->fullIData(oldp+94,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[19]),32);
        tracep->fullIData(oldp+95,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[20]),32);
        tracep->fullIData(oldp+96,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[21]),32);
        tracep->fullIData(oldp+97,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[22]),32);
        tracep->fullIData(oldp+98,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[23]),32);
        tracep->fullIData(oldp+99,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[24]),32);
        tracep->fullIData(oldp+100,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[25]),32);
        tracep->fullIData(oldp+101,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[26]),32);
        tracep->fullIData(oldp+102,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[27]),32);
        tracep->fullIData(oldp+103,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[28]),32);
        tracep->fullIData(oldp+104,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[29]),32);
        tracep->fullIData(oldp+105,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[30]),32);
        tracep->fullIData(oldp+106,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[31]),32);
        tracep->fullBit(oldp+107,(vlTOPp->trigger));
        tracep->fullBit(oldp+108,(vlTOPp->clk));
        tracep->fullBit(oldp+109,(vlTOPp->rst));
        tracep->fullIData(oldp+110,(vlTOPp->a0W),32);
        tracep->fullIData(oldp+111,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
                                    [(0x1fU & (vlTOPp->cpu_pipelined__DOT__instrD 
                                               >> 0xfU))]),32);
        tracep->fullIData(oldp+112,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
                                    [(0x1fU & (vlTOPp->cpu_pipelined__DOT__instrD 
                                               >> 0x14U))]),32);
        tracep->fullIData(oldp+113,(0x20U),32);
        tracep->fullIData(oldp+114,(8U),32);
        tracep->fullIData(oldp+115,(5U),32);
    }
}
