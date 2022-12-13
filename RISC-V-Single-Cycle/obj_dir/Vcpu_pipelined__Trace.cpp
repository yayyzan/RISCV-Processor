// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu_pipelined__Syms.h"


void Vcpu_pipelined::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vcpu_pipelined__Syms* __restrict vlSymsp = static_cast<Vcpu_pipelined__Syms*>(userp);
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vcpu_pipelined::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vcpu_pipelined__Syms* __restrict vlSymsp = static_cast<Vcpu_pipelined__Syms*>(userp);
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgIData(oldp+0,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__unnamedblk1__DOT__i),32);
            tracep->chgIData(oldp+1,(vlTOPp->cpu_pipelined__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+2,(vlTOPp->cpu_pipelined__DOT__pcF),32);
            tracep->chgIData(oldp+3,(((vlTOPp->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                       [(0xfffU & vlTOPp->cpu_pipelined__DOT__pcF)] 
                                       << 0x18U) | 
                                      ((vlTOPp->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                        [(0xfffU & 
                                          ((IData)(1U) 
                                           + vlTOPp->cpu_pipelined__DOT__pcF))] 
                                        << 0x10U) | 
                                       ((vlTOPp->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                         [(0xfffU & 
                                           ((IData)(2U) 
                                            + vlTOPp->cpu_pipelined__DOT__pcF))] 
                                         << 8U) | vlTOPp->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                        [(0xfffU & 
                                          ((IData)(3U) 
                                           + vlTOPp->cpu_pipelined__DOT__pcF))])))),32);
            tracep->chgIData(oldp+4,(vlTOPp->cpu_pipelined__DOT__pcplusfourF),32);
            tracep->chgIData(oldp+5,(vlTOPp->cpu_pipelined__DOT__pcD),32);
            tracep->chgIData(oldp+6,(vlTOPp->cpu_pipelined__DOT__instrD),32);
            tracep->chgIData(oldp+7,(vlTOPp->cpu_pipelined__DOT__pcplusfourD),32);
            tracep->chgBit(oldp+8,(vlTOPp->cpu_pipelined__DOT__regwriteD));
            tracep->chgBit(oldp+9,(vlTOPp->cpu_pipelined__DOT__resultsrcD));
            tracep->chgBit(oldp+10,(vlTOPp->cpu_pipelined__DOT__memwriteD));
            tracep->chgBit(oldp+11,(vlTOPp->cpu_pipelined__DOT__alusrcD));
            tracep->chgBit(oldp+12,(vlTOPp->cpu_pipelined__DOT__addupperD));
            tracep->chgBit(oldp+13,(vlTOPp->cpu_pipelined__DOT__jbmuxD));
            tracep->chgBit(oldp+14,(vlTOPp->cpu_pipelined__DOT__pcwritemuxD));
            tracep->chgIData(oldp+15,(vlTOPp->cpu_pipelined__DOT__immextD),32);
            tracep->chgCData(oldp+16,((0x7fU & vlTOPp->cpu_pipelined__DOT__instrD)),7);
            tracep->chgCData(oldp+17,(vlTOPp->cpu_pipelined__DOT__rdD),5);
            tracep->chgCData(oldp+18,(((2U & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                        ? ((1U & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                            ? 0xfU : 
                                           ((0x18U 
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
                                            | (7U & 
                                               (vlTOPp->cpu_pipelined__DOT__instrD 
                                                >> 0xcU))))
                                        : ((1U & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                            ? ((4U 
                                                & ((~ 
                                                    (vlTOPp->cpu_pipelined__DOT__instrD 
                                                     >> 0xeU)) 
                                                   << 2U)) 
                                               | (3U 
                                                  & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                     >> 0xdU)))
                                            : 0U))),4);
            tracep->chgCData(oldp+19,((7U & (vlTOPp->cpu_pipelined__DOT__instrD 
                                             >> 0xcU))),3);
            tracep->chgBit(oldp+20,(vlTOPp->cpu_pipelined__DOT__regwriteE));
            tracep->chgBit(oldp+21,(vlTOPp->cpu_pipelined__DOT__addupperE));
            tracep->chgBit(oldp+22,(vlTOPp->cpu_pipelined__DOT__alusrcE));
            tracep->chgBit(oldp+23,(vlTOPp->cpu_pipelined__DOT__memwriteE));
            tracep->chgBit(oldp+24,(vlTOPp->cpu_pipelined__DOT__resultsrcE));
            tracep->chgBit(oldp+25,(vlTOPp->cpu_pipelined__DOT__jbmuxE));
            tracep->chgBit(oldp+26,(vlTOPp->cpu_pipelined__DOT__pcwritemuxE));
            tracep->chgIData(oldp+27,(vlTOPp->cpu_pipelined__DOT__a0E),32);
            tracep->chgIData(oldp+28,(vlTOPp->cpu_pipelined__DOT__rd1E),32);
            tracep->chgIData(oldp+29,(vlTOPp->cpu_pipelined__DOT__rd2E),32);
            tracep->chgIData(oldp+30,(vlTOPp->cpu_pipelined__DOT__immextE),32);
            tracep->chgIData(oldp+31,(vlTOPp->cpu_pipelined__DOT__pcE),32);
            tracep->chgIData(oldp+32,(vlTOPp->cpu_pipelined__DOT__pcplusfourE),32);
            tracep->chgCData(oldp+33,(vlTOPp->cpu_pipelined__DOT__opcodeE),7);
            tracep->chgCData(oldp+34,(vlTOPp->cpu_pipelined__DOT__rdE),5);
            tracep->chgCData(oldp+35,(vlTOPp->cpu_pipelined__DOT__aluctrlE),4);
            tracep->chgCData(oldp+36,(vlTOPp->cpu_pipelined__DOT__funct3E),3);
            tracep->chgIData(oldp+37,(((IData)(vlTOPp->cpu_pipelined__DOT__jbmuxE)
                                        ? vlTOPp->cpu_pipelined__DOT__aluresultE
                                        : (vlTOPp->cpu_pipelined__DOT__pcE 
                                           + vlTOPp->cpu_pipelined__DOT__immextE))),32);
            tracep->chgIData(oldp+38,(vlTOPp->cpu_pipelined__DOT__aluresultE),32);
            tracep->chgBit(oldp+39,(vlTOPp->cpu_pipelined__DOT__pcsrcE));
            tracep->chgBit(oldp+40,(vlTOPp->cpu_pipelined__DOT__regwriteM));
            tracep->chgBit(oldp+41,(vlTOPp->cpu_pipelined__DOT__resultsrcM));
            tracep->chgBit(oldp+42,(vlTOPp->cpu_pipelined__DOT__memwriteM));
            tracep->chgBit(oldp+43,(vlTOPp->cpu_pipelined__DOT__pcwritemuxM));
            tracep->chgIData(oldp+44,(vlTOPp->cpu_pipelined__DOT__aluresultM),32);
            tracep->chgIData(oldp+45,(vlTOPp->cpu_pipelined__DOT__write_dataM),32);
            tracep->chgIData(oldp+46,(vlTOPp->cpu_pipelined__DOT__pcplusfourM),32);
            tracep->chgIData(oldp+47,(vlTOPp->cpu_pipelined__DOT__a0M),32);
            tracep->chgCData(oldp+48,(vlTOPp->cpu_pipelined__DOT__rdM),5);
            tracep->chgCData(oldp+49,(vlTOPp->cpu_pipelined__DOT__funct3M),3);
            tracep->chgIData(oldp+50,(vlTOPp->cpu_pipelined__DOT__read_dataM),32);
            tracep->chgBit(oldp+51,(vlTOPp->cpu_pipelined__DOT__regwriteW));
            tracep->chgBit(oldp+52,(vlTOPp->cpu_pipelined__DOT__resultsrcW));
            tracep->chgBit(oldp+53,(vlTOPp->cpu_pipelined__DOT__pcwritemuxW));
            tracep->chgIData(oldp+54,(vlTOPp->cpu_pipelined__DOT__read_dataW),32);
            tracep->chgIData(oldp+55,(vlTOPp->cpu_pipelined__DOT__aluresultW),32);
            tracep->chgIData(oldp+56,(vlTOPp->cpu_pipelined__DOT__pcplusfourW),32);
            tracep->chgCData(oldp+57,(vlTOPp->cpu_pipelined__DOT__rdW),5);
            tracep->chgIData(oldp+58,(((1U == (((IData)(vlTOPp->cpu_pipelined__DOT__pcwritemuxW) 
                                                << 1U) 
                                               | (IData)(vlTOPp->cpu_pipelined__DOT__resultsrcW)))
                                        ? vlTOPp->cpu_pipelined__DOT__read_dataW
                                        : ((2U == (
                                                   ((IData)(vlTOPp->cpu_pipelined__DOT__pcwritemuxW) 
                                                    << 1U) 
                                                   | (IData)(vlTOPp->cpu_pipelined__DOT__resultsrcW)))
                                            ? vlTOPp->cpu_pipelined__DOT__pcplusfourW
                                            : vlTOPp->cpu_pipelined__DOT__aluresultW))),32);
            tracep->chgIData(oldp+59,(vlTOPp->cpu_pipelined__DOT__fetch__DOT__pcountunit__DOT__next_pc),32);
            tracep->chgBit(oldp+60,((1U & (vlTOPp->cpu_pipelined__DOT__instrD 
                                           >> 0x1eU))));
            tracep->chgCData(oldp+61,(vlTOPp->cpu_pipelined__DOT__decode__DOT__immsrcD),3);
            tracep->chgIData(oldp+62,((0x1ffffffU & 
                                       (vlTOPp->cpu_pipelined__DOT__instrD 
                                        >> 7U))),25);
            tracep->chgCData(oldp+63,((0x1fU & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+64,((0x1fU & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                >> 0x14U))),5);
            tracep->chgCData(oldp+65,(vlTOPp->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop),2);
            tracep->chgBit(oldp+66,(vlTOPp->cpu_pipelined__DOT__execute__DOT__eq));
            tracep->chgIData(oldp+67,(vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc),32);
            tracep->chgIData(oldp+68,(vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2),32);
            tracep->chgCData(oldp+69,((3U & vlTOPp->cpu_pipelined__DOT__aluresultM)),2);
            tracep->chgIData(oldp+70,((0xfffffffcU 
                                       & vlTOPp->cpu_pipelined__DOT__aluresultM)),32);
            tracep->chgIData(oldp+71,(vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout),32);
            tracep->chgIData(oldp+72,(vlTOPp->cpu_pipelined__DOT__memory__DOT__ramin),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+73,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
                                      [0xaU]),32);
            tracep->chgIData(oldp+74,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0]),32);
            tracep->chgIData(oldp+75,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[1]),32);
            tracep->chgIData(oldp+76,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[2]),32);
            tracep->chgIData(oldp+77,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[3]),32);
            tracep->chgIData(oldp+78,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[4]),32);
            tracep->chgIData(oldp+79,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[5]),32);
            tracep->chgIData(oldp+80,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[6]),32);
            tracep->chgIData(oldp+81,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[7]),32);
            tracep->chgIData(oldp+82,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[8]),32);
            tracep->chgIData(oldp+83,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[9]),32);
            tracep->chgIData(oldp+84,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[10]),32);
            tracep->chgIData(oldp+85,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[11]),32);
            tracep->chgIData(oldp+86,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[12]),32);
            tracep->chgIData(oldp+87,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[13]),32);
            tracep->chgIData(oldp+88,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[14]),32);
            tracep->chgIData(oldp+89,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[15]),32);
            tracep->chgIData(oldp+90,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[16]),32);
            tracep->chgIData(oldp+91,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[17]),32);
            tracep->chgIData(oldp+92,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[18]),32);
            tracep->chgIData(oldp+93,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[19]),32);
            tracep->chgIData(oldp+94,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[20]),32);
            tracep->chgIData(oldp+95,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[21]),32);
            tracep->chgIData(oldp+96,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[22]),32);
            tracep->chgIData(oldp+97,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[23]),32);
            tracep->chgIData(oldp+98,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[24]),32);
            tracep->chgIData(oldp+99,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[25]),32);
            tracep->chgIData(oldp+100,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[26]),32);
            tracep->chgIData(oldp+101,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[27]),32);
            tracep->chgIData(oldp+102,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[28]),32);
            tracep->chgIData(oldp+103,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[29]),32);
            tracep->chgIData(oldp+104,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[30]),32);
            tracep->chgIData(oldp+105,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[31]),32);
        }
        tracep->chgBit(oldp+106,(vlTOPp->trigger));
        tracep->chgBit(oldp+107,(vlTOPp->clk));
        tracep->chgBit(oldp+108,(vlTOPp->rst));
        tracep->chgIData(oldp+109,(vlTOPp->a0W),32);
        tracep->chgIData(oldp+110,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
                                   [(0x1fU & (vlTOPp->cpu_pipelined__DOT__instrD 
                                              >> 0xfU))]),32);
        tracep->chgIData(oldp+111,(vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
                                   [(0x1fU & (vlTOPp->cpu_pipelined__DOT__instrD 
                                              >> 0x14U))]),32);
    }
}

void Vcpu_pipelined::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vcpu_pipelined__Syms* __restrict vlSymsp = static_cast<Vcpu_pipelined__Syms*>(userp);
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
