// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu__Syms.h"


//======================

void Vcpu::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vcpu::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vcpu::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vcpu::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vcpu::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+72,"trigger", false,-1);
        tracep->declBit(c+73,"clk", false,-1);
        tracep->declBit(c+74,"rst", false,-1);
        tracep->declBus(c+75,"a0_output", false,-1, 31,0);
        tracep->declBus(c+76,"cpu WIDTH", false,-1, 31,0);
        tracep->declBit(c+72,"cpu trigger", false,-1);
        tracep->declBit(c+73,"cpu clk", false,-1);
        tracep->declBit(c+74,"cpu rst", false,-1);
        tracep->declBus(c+75,"cpu a0_output", false,-1, 31,0);
        tracep->declBus(c+3,"cpu rf_dout1", false,-1, 31,0);
        tracep->declBus(c+4,"cpu rf_dout2", false,-1, 31,0);
        tracep->declBus(c+5,"cpu interm_immop", false,-1, 31,0);
        tracep->declBus(c+6,"cpu prog_addr", false,-1, 31,0);
        tracep->declBus(c+7,"cpu interm_ins", false,-1, 31,0);
        tracep->declBus(c+8,"cpu interm_aluout", false,-1, 31,0);
        tracep->declBus(c+9,"cpu interm_loadout", false,-1, 31,0);
        tracep->declBus(c+10,"cpu interm_wdrf", false,-1, 31,0);
        tracep->declBus(c+11,"cpu jump_addr", false,-1, 31,0);
        tracep->declBus(c+12,"cpu interm_rfpc", false,-1, 31,0);
        tracep->declBus(c+13,"cpu result", false,-1, 31,0);
        tracep->declBus(c+14,"cpu interm_opcode", false,-1, 6,0);
        tracep->declBus(c+15,"cpu interm_aluctrl", false,-1, 3,0);
        tracep->declBus(c+16,"cpu interm_funct3", false,-1, 2,0);
        tracep->declBus(c+17,"cpu interm_immsrc", false,-1, 2,0);
        tracep->declBit(c+18,"cpu interm_funct7", false,-1);
        tracep->declBit(c+19,"cpu interm_alusrc", false,-1);
        tracep->declBit(c+20,"cpu interm_pcsrc", false,-1);
        tracep->declBit(c+21,"cpu interm_eq", false,-1);
        tracep->declBit(c+22,"cpu write_en", false,-1);
        tracep->declBit(c+23,"cpu interm_memwrite", false,-1);
        tracep->declBit(c+24,"cpu interm_resultsrc", false,-1);
        tracep->declBit(c+25,"cpu interm_jbmux", false,-1);
        tracep->declBit(c+26,"cpu interm_pcwritemux", false,-1);
        tracep->declBit(c+27,"cpu interm_addupper", false,-1);
        tracep->declBus(c+14,"cpu ctrlunit opcode", false,-1, 6,0);
        tracep->declBus(c+16,"cpu ctrlunit funct3", false,-1, 2,0);
        tracep->declBit(c+18,"cpu ctrlunit funct7", false,-1);
        tracep->declBit(c+21,"cpu ctrlunit eq", false,-1);
        tracep->declBit(c+22,"cpu ctrlunit regwrite", false,-1);
        tracep->declBit(c+19,"cpu ctrlunit alusrc", false,-1);
        tracep->declBit(c+20,"cpu ctrlunit pcsrc", false,-1);
        tracep->declBit(c+23,"cpu ctrlunit memwrite", false,-1);
        tracep->declBit(c+24,"cpu ctrlunit resultsrc", false,-1);
        tracep->declBit(c+26,"cpu ctrlunit pcwritemux", false,-1);
        tracep->declBit(c+25,"cpu ctrlunit jbmux", false,-1);
        tracep->declBit(c+27,"cpu ctrlunit addupper", false,-1);
        tracep->declBus(c+15,"cpu ctrlunit aluctrl", false,-1, 3,0);
        tracep->declBus(c+17,"cpu ctrlunit immsrc", false,-1, 2,0);
        tracep->declBus(c+28,"cpu ctrlunit aluop", false,-1, 1,0);
        tracep->declBus(c+76,"cpu programcounter WIDTH", false,-1, 31,0);
        tracep->declBit(c+20,"cpu programcounter pcsrc", false,-1);
        tracep->declBit(c+73,"cpu programcounter clk", false,-1);
        tracep->declBit(c+74,"cpu programcounter rst", false,-1);
        tracep->declBit(c+25,"cpu programcounter jbmux", false,-1);
        tracep->declBus(c+11,"cpu programcounter jumpaddress", false,-1, 31,0);
        tracep->declBus(c+6,"cpu programcounter pc", false,-1, 31,0);
        tracep->declBus(c+29,"cpu programcounter next_pc", false,-1, 31,0);
        tracep->declBus(c+30,"cpu programcounter branch_pc", false,-1, 31,0);
        tracep->declBus(c+76,"cpu programmem A_WIDTH", false,-1, 31,0);
        tracep->declBus(c+77,"cpu programmem D_WIDTH", false,-1, 31,0);
        tracep->declBus(c+6,"cpu programmem address", false,-1, 31,0);
        tracep->declBus(c+7,"cpu programmem dout", false,-1, 31,0);
        tracep->declBus(c+31,"cpu sgnextend instruction", false,-1, 31,7);
        tracep->declBus(c+17,"cpu sgnextend immsrc", false,-1, 2,0);
        tracep->declBus(c+5,"cpu sgnextend immop", false,-1, 31,0);
        tracep->declBus(c+76,"cpu alu D_WIDTH", false,-1, 31,0);
        tracep->declBit(c+19,"cpu alu alusrc", false,-1);
        tracep->declBus(c+15,"cpu alu aluctrl", false,-1, 3,0);
        tracep->declBus(c+12,"cpu alu aluop1", false,-1, 31,0);
        tracep->declBus(c+5,"cpu alu immop", false,-1, 31,0);
        tracep->declBus(c+4,"cpu alu regop2", false,-1, 31,0);
        tracep->declBus(c+8,"cpu alu aluout", false,-1, 31,0);
        tracep->declBit(c+21,"cpu alu eq", false,-1);
        tracep->declBus(c+32,"cpu alu aluop2", false,-1, 31,0);
        tracep->declBus(c+78,"cpu registerfile A_WIDTH", false,-1, 31,0);
        tracep->declBus(c+76,"cpu registerfile D_WIDTH", false,-1, 31,0);
        tracep->declBit(c+73,"cpu registerfile clk", false,-1);
        tracep->declBit(c+22,"cpu registerfile we3", false,-1);
        tracep->declBit(c+72,"cpu registerfile trigger", false,-1);
        tracep->declBus(c+33,"cpu registerfile ad1", false,-1, 4,0);
        tracep->declBus(c+34,"cpu registerfile ad2", false,-1, 4,0);
        tracep->declBus(c+35,"cpu registerfile ad3", false,-1, 4,0);
        tracep->declBus(c+10,"cpu registerfile wd3", false,-1, 31,0);
        tracep->declBus(c+75,"cpu registerfile a0", false,-1, 31,0);
        tracep->declBus(c+3,"cpu registerfile rd1", false,-1, 31,0);
        tracep->declBus(c+4,"cpu registerfile rd2", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+36+i*1,"cpu registerfile rf_array", true,(i+0), 31,0);}}
        tracep->declBus(c+1,"cpu registerfile unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+76,"cpu memory ADDRESS_WIDTH", false,-1, 31,0);
        tracep->declBus(c+76,"cpu memory DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+73,"cpu memory clk", false,-1);
        tracep->declBit(c+23,"cpu memory write_enable", false,-1);
        tracep->declBus(c+16,"cpu memory addrmode", false,-1, 2,0);
        tracep->declBus(c+68,"cpu memory selectbytes", false,-1, 1,0);
        tracep->declBus(c+4,"cpu memory write_data", false,-1, 31,0);
        tracep->declBus(c+69,"cpu memory address", false,-1, 31,0);
        tracep->declBus(c+9,"cpu memory read_data", false,-1, 31,0);
        tracep->declBus(c+70,"cpu memory ramout", false,-1, 31,0);
        tracep->declBus(c+71,"cpu memory ramin", false,-1, 31,0);
        tracep->declBus(c+76,"cpu memory storemem DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+16,"cpu memory storemem addrmode", false,-1, 2,0);
        tracep->declBus(c+68,"cpu memory storemem selectbytes", false,-1, 1,0);
        tracep->declBus(c+70,"cpu memory storemem ramout", false,-1, 31,0);
        tracep->declBus(c+4,"cpu memory storemem write_data", false,-1, 31,0);
        tracep->declBus(c+71,"cpu memory storemem ramdin", false,-1, 31,0);
        tracep->declBus(c+76,"cpu memory ram ADDRESS_WIDTH", false,-1, 31,0);
        tracep->declBus(c+77,"cpu memory ram DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+73,"cpu memory ram clk", false,-1);
        tracep->declBit(c+23,"cpu memory ram write_enable", false,-1);
        tracep->declBus(c+69,"cpu memory ram address", false,-1, 31,0);
        tracep->declBus(c+71,"cpu memory ram ramin", false,-1, 31,0);
        tracep->declBus(c+70,"cpu memory ram ramout", false,-1, 31,0);
        tracep->declBus(c+2,"cpu memory ram unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+76,"cpu memory loadmem D_WIDTH", false,-1, 31,0);
        tracep->declBus(c+16,"cpu memory loadmem addrmode", false,-1, 2,0);
        tracep->declBus(c+68,"cpu memory loadmem selectbytes", false,-1, 1,0);
        tracep->declBus(c+70,"cpu memory loadmem ramout", false,-1, 31,0);
        tracep->declBus(c+9,"cpu memory loadmem read_data", false,-1, 31,0);
    }
}

void Vcpu::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vcpu::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vcpu::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->cpu__DOT__registerfile__DOT__unnamedblk1__DOT__i),32);
        tracep->fullIData(oldp+2,(vlTOPp->cpu__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i),32);
        tracep->fullIData(oldp+3,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array
                                  [(0x1fU & (vlTOPp->cpu__DOT__interm_ins 
                                             >> 0xfU))]),32);
        tracep->fullIData(oldp+4,(vlTOPp->cpu__DOT__rf_dout2),32);
        tracep->fullIData(oldp+5,(vlTOPp->cpu__DOT__interm_immop),32);
        tracep->fullIData(oldp+6,(vlTOPp->cpu__DOT__prog_addr),32);
        tracep->fullIData(oldp+7,(vlTOPp->cpu__DOT__interm_ins),32);
        tracep->fullIData(oldp+8,(vlTOPp->cpu__DOT__interm_aluout),32);
        tracep->fullIData(oldp+9,(vlTOPp->cpu__DOT__interm_loadout),32);
        tracep->fullIData(oldp+10,(((0x67U <= (0x7fU 
                                               & vlTOPp->cpu__DOT__interm_ins))
                                     ? ((IData)(4U) 
                                        + vlTOPp->cpu__DOT__prog_addr)
                                     : vlTOPp->cpu__DOT__result)),32);
        tracep->fullIData(oldp+11,(vlTOPp->cpu__DOT__jump_addr),32);
        tracep->fullIData(oldp+12,(vlTOPp->cpu__DOT__interm_rfpc),32);
        tracep->fullIData(oldp+13,(vlTOPp->cpu__DOT__result),32);
        tracep->fullCData(oldp+14,((0x7fU & vlTOPp->cpu__DOT__interm_ins)),7);
        tracep->fullCData(oldp+15,(vlTOPp->cpu__DOT__interm_aluctrl),4);
        tracep->fullCData(oldp+16,((7U & (vlTOPp->cpu__DOT__interm_ins 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+17,(vlTOPp->cpu__DOT__interm_immsrc),3);
        tracep->fullBit(oldp+18,((1U & (vlTOPp->cpu__DOT__interm_ins 
                                        >> 0x1eU))));
        tracep->fullBit(oldp+19,(((((((3U == (0x7fU 
                                              & vlTOPp->cpu__DOT__interm_ins)) 
                                      | (0x13U == (0x7fU 
                                                   & vlTOPp->cpu__DOT__interm_ins))) 
                                     | (0x23U == (0x7fU 
                                                  & vlTOPp->cpu__DOT__interm_ins))) 
                                    | (0x67U == (0x7fU 
                                                 & vlTOPp->cpu__DOT__interm_ins))) 
                                   | (0x17U == (0x7fU 
                                                & vlTOPp->cpu__DOT__interm_ins))) 
                                  | (0x37U == (0x7fU 
                                               & vlTOPp->cpu__DOT__interm_ins)))));
        tracep->fullBit(oldp+20,(((0x67U <= (0x7fU 
                                             & vlTOPp->cpu__DOT__interm_ins)) 
                                  | ((0x63U == (0x7fU 
                                                & vlTOPp->cpu__DOT__interm_ins)) 
                                     & (((~ (IData)(vlTOPp->cpu__DOT__interm_eq)) 
                                         & (((0U == 
                                              (7U & 
                                               (vlTOPp->cpu__DOT__interm_ins 
                                                >> 0xcU))) 
                                             | (5U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->cpu__DOT__interm_ins 
                                                    >> 0xcU)))) 
                                            | (7U == 
                                               (7U 
                                                & (vlTOPp->cpu__DOT__interm_ins 
                                                   >> 0xcU))))) 
                                        | ((IData)(vlTOPp->cpu__DOT__interm_eq) 
                                           & (((1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->cpu__DOT__interm_ins 
                                                    >> 0xcU))) 
                                               | (4U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->cpu__DOT__interm_ins 
                                                      >> 0xcU)))) 
                                              | (6U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->cpu__DOT__interm_ins 
                                                     >> 0xcU))))))))));
        tracep->fullBit(oldp+21,(vlTOPp->cpu__DOT__interm_eq));
        tracep->fullBit(oldp+22,(((((((0x13U == (0x7fU 
                                                 & vlTOPp->cpu__DOT__interm_ins)) 
                                      | (3U == (0x7fU 
                                                & vlTOPp->cpu__DOT__interm_ins))) 
                                     | (0x33U == (0x7fU 
                                                  & vlTOPp->cpu__DOT__interm_ins))) 
                                    | (0x67U <= (0x7fU 
                                                 & vlTOPp->cpu__DOT__interm_ins))) 
                                   | (0x17U == (0x7fU 
                                                & vlTOPp->cpu__DOT__interm_ins))) 
                                  | (0x37U == (0x7fU 
                                               & vlTOPp->cpu__DOT__interm_ins)))));
        tracep->fullBit(oldp+23,((0x23U == (0x7fU & vlTOPp->cpu__DOT__interm_ins))));
        tracep->fullBit(oldp+24,((3U == (0x7fU & vlTOPp->cpu__DOT__interm_ins))));
        tracep->fullBit(oldp+25,((0x67U == (0x7fU & vlTOPp->cpu__DOT__interm_ins))));
        tracep->fullBit(oldp+26,((0x67U <= (0x7fU & vlTOPp->cpu__DOT__interm_ins))));
        tracep->fullBit(oldp+27,((0x17U == (0x7fU & vlTOPp->cpu__DOT__interm_ins))));
        tracep->fullCData(oldp+28,(vlTOPp->cpu__DOT__ctrlunit__DOT__aluop),2);
        tracep->fullIData(oldp+29,(vlTOPp->cpu__DOT__programcounter__DOT__next_pc),32);
        tracep->fullIData(oldp+30,(vlTOPp->cpu__DOT__programcounter__DOT__branch_pc),32);
        tracep->fullIData(oldp+31,((0x1ffffffU & (vlTOPp->cpu__DOT__interm_ins 
                                                  >> 7U))),25);
        tracep->fullIData(oldp+32,(vlTOPp->cpu__DOT__alu__DOT__aluop2),32);
        tracep->fullCData(oldp+33,((0x1fU & (vlTOPp->cpu__DOT__interm_ins 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+34,((0x1fU & (vlTOPp->cpu__DOT__interm_ins 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+35,((0x1fU & (vlTOPp->cpu__DOT__interm_ins 
                                             >> 7U))),5);
        tracep->fullIData(oldp+36,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0]),32);
        tracep->fullIData(oldp+37,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[1]),32);
        tracep->fullIData(oldp+38,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[2]),32);
        tracep->fullIData(oldp+39,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[3]),32);
        tracep->fullIData(oldp+40,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[4]),32);
        tracep->fullIData(oldp+41,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[5]),32);
        tracep->fullIData(oldp+42,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[6]),32);
        tracep->fullIData(oldp+43,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[7]),32);
        tracep->fullIData(oldp+44,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[8]),32);
        tracep->fullIData(oldp+45,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[9]),32);
        tracep->fullIData(oldp+46,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[10]),32);
        tracep->fullIData(oldp+47,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[11]),32);
        tracep->fullIData(oldp+48,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[12]),32);
        tracep->fullIData(oldp+49,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[13]),32);
        tracep->fullIData(oldp+50,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[14]),32);
        tracep->fullIData(oldp+51,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[15]),32);
        tracep->fullIData(oldp+52,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[16]),32);
        tracep->fullIData(oldp+53,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[17]),32);
        tracep->fullIData(oldp+54,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[18]),32);
        tracep->fullIData(oldp+55,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[19]),32);
        tracep->fullIData(oldp+56,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[20]),32);
        tracep->fullIData(oldp+57,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[21]),32);
        tracep->fullIData(oldp+58,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[22]),32);
        tracep->fullIData(oldp+59,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[23]),32);
        tracep->fullIData(oldp+60,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[24]),32);
        tracep->fullIData(oldp+61,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[25]),32);
        tracep->fullIData(oldp+62,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[26]),32);
        tracep->fullIData(oldp+63,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[27]),32);
        tracep->fullIData(oldp+64,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[28]),32);
        tracep->fullIData(oldp+65,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[29]),32);
        tracep->fullIData(oldp+66,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[30]),32);
        tracep->fullIData(oldp+67,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[31]),32);
        tracep->fullCData(oldp+68,((3U & vlTOPp->cpu__DOT__interm_aluout)),2);
        tracep->fullIData(oldp+69,((0xfffffffcU & vlTOPp->cpu__DOT__interm_aluout)),32);
        tracep->fullIData(oldp+70,(vlTOPp->cpu__DOT__memory__DOT__ramout),32);
        tracep->fullIData(oldp+71,(vlTOPp->cpu__DOT__memory__DOT__ramin),32);
        tracep->fullBit(oldp+72,(vlTOPp->trigger));
        tracep->fullBit(oldp+73,(vlTOPp->clk));
        tracep->fullBit(oldp+74,(vlTOPp->rst));
        tracep->fullIData(oldp+75,(vlTOPp->a0_output),32);
        tracep->fullIData(oldp+76,(0x20U),32);
        tracep->fullIData(oldp+77,(8U),32);
        tracep->fullIData(oldp+78,(5U),32);
    }
}
