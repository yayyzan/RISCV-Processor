// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu_pipelined__Syms.h"


void Vcpu_pipelined___024root__trace_chg_sub_0(Vcpu_pipelined___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vcpu_pipelined___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root__trace_chg_top_0\n"); );
    // Init
    Vcpu_pipelined___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu_pipelined___024root*>(voidSelf);
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vcpu_pipelined___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vcpu_pipelined___024root__trace_chg_sub_0(Vcpu_pipelined___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+1,(vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+2,(vlSelf->cpu_pipelined__DOT__pcF),32);
        bufp->chgIData(oldp+3,(((vlSelf->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                 [(0xfffU & vlSelf->cpu_pipelined__DOT__pcF)] 
                                 << 0x18U) | ((vlSelf->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                               [(0xfffU 
                                                 & ((IData)(1U) 
                                                    + vlSelf->cpu_pipelined__DOT__pcF))] 
                                               << 0x10U) 
                                              | ((vlSelf->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                                  [
                                                  (0xfffU 
                                                   & ((IData)(2U) 
                                                      + vlSelf->cpu_pipelined__DOT__pcF))] 
                                                  << 8U) 
                                                 | vlSelf->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                                 [(0xfffU 
                                                   & ((IData)(3U) 
                                                      + vlSelf->cpu_pipelined__DOT__pcF))])))),32);
        bufp->chgIData(oldp+4,(vlSelf->cpu_pipelined__DOT__pcplusfourF),32);
        bufp->chgIData(oldp+5,(vlSelf->cpu_pipelined__DOT__pcD),32);
        bufp->chgIData(oldp+6,(vlSelf->cpu_pipelined__DOT__instrD),32);
        bufp->chgIData(oldp+7,(vlSelf->cpu_pipelined__DOT__pcplusfourD),32);
        bufp->chgBit(oldp+8,(vlSelf->cpu_pipelined__DOT__regwriteD));
        bufp->chgBit(oldp+9,(vlSelf->cpu_pipelined__DOT__resultsrcD));
        bufp->chgBit(oldp+10,(vlSelf->cpu_pipelined__DOT__memwriteD));
        bufp->chgBit(oldp+11,(vlSelf->cpu_pipelined__DOT__alusrcD));
        bufp->chgBit(oldp+12,(vlSelf->cpu_pipelined__DOT__addupperD));
        bufp->chgBit(oldp+13,(vlSelf->cpu_pipelined__DOT__jbmuxD));
        bufp->chgBit(oldp+14,(vlSelf->cpu_pipelined__DOT__pcwritemuxD));
        bufp->chgIData(oldp+15,(vlSelf->cpu_pipelined__DOT__immextD),32);
        bufp->chgCData(oldp+16,((0x7fU & vlSelf->cpu_pipelined__DOT__instrD)),7);
        bufp->chgCData(oldp+17,(vlSelf->cpu_pipelined__DOT__rdD),5);
        bufp->chgCData(oldp+18,(((2U & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
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
                                      ? ((4U & ((~ 
                                                 (vlSelf->cpu_pipelined__DOT__instrD 
                                                  >> 0xeU)) 
                                                << 2U)) 
                                         | (3U & (vlSelf->cpu_pipelined__DOT__instrD 
                                                  >> 0xdU)))
                                      : 0U))),4);
        bufp->chgCData(oldp+19,((7U & (vlSelf->cpu_pipelined__DOT__instrD 
                                       >> 0xcU))),3);
        bufp->chgBit(oldp+20,(vlSelf->cpu_pipelined__DOT__regwriteE));
        bufp->chgBit(oldp+21,(vlSelf->cpu_pipelined__DOT__addupperE));
        bufp->chgBit(oldp+22,(vlSelf->cpu_pipelined__DOT__alusrcE));
        bufp->chgBit(oldp+23,(vlSelf->cpu_pipelined__DOT__memwriteE));
        bufp->chgBit(oldp+24,(vlSelf->cpu_pipelined__DOT__resultsrcE));
        bufp->chgBit(oldp+25,(vlSelf->cpu_pipelined__DOT__jbmuxE));
        bufp->chgBit(oldp+26,(vlSelf->cpu_pipelined__DOT__pcwritemuxE));
        bufp->chgIData(oldp+27,(vlSelf->cpu_pipelined__DOT__a0E),32);
        bufp->chgIData(oldp+28,(vlSelf->cpu_pipelined__DOT__rd1E),32);
        bufp->chgIData(oldp+29,(vlSelf->cpu_pipelined__DOT__rd2E),32);
        bufp->chgIData(oldp+30,(vlSelf->cpu_pipelined__DOT__immextE),32);
        bufp->chgIData(oldp+31,(vlSelf->cpu_pipelined__DOT__pcE),32);
        bufp->chgIData(oldp+32,(vlSelf->cpu_pipelined__DOT__pcplusfourE),32);
        bufp->chgCData(oldp+33,(vlSelf->cpu_pipelined__DOT__opcodeE),7);
        bufp->chgCData(oldp+34,(vlSelf->cpu_pipelined__DOT__rdE),5);
        bufp->chgCData(oldp+35,(vlSelf->cpu_pipelined__DOT__aluctrlE),4);
        bufp->chgCData(oldp+36,(vlSelf->cpu_pipelined__DOT__funct3E),3);
        bufp->chgIData(oldp+37,(((IData)(vlSelf->cpu_pipelined__DOT__jbmuxE)
                                  ? vlSelf->cpu_pipelined__DOT__aluresultE
                                  : (vlSelf->cpu_pipelined__DOT__pcE 
                                     + vlSelf->cpu_pipelined__DOT__immextE))),32);
        bufp->chgIData(oldp+38,(vlSelf->cpu_pipelined__DOT__aluresultE),32);
        bufp->chgBit(oldp+39,(vlSelf->cpu_pipelined__DOT__pcsrcE));
        bufp->chgBit(oldp+40,(vlSelf->cpu_pipelined__DOT__regwriteM));
        bufp->chgBit(oldp+41,(vlSelf->cpu_pipelined__DOT__resultsrcM));
        bufp->chgBit(oldp+42,(vlSelf->cpu_pipelined__DOT__memwriteM));
        bufp->chgBit(oldp+43,(vlSelf->cpu_pipelined__DOT__pcwritemuxM));
        bufp->chgIData(oldp+44,(vlSelf->cpu_pipelined__DOT__aluresultM),32);
        bufp->chgIData(oldp+45,(vlSelf->cpu_pipelined__DOT__write_dataM),32);
        bufp->chgIData(oldp+46,(vlSelf->cpu_pipelined__DOT__pcplusfourM),32);
        bufp->chgIData(oldp+47,(vlSelf->cpu_pipelined__DOT__a0M),32);
        bufp->chgCData(oldp+48,(vlSelf->cpu_pipelined__DOT__rdM),5);
        bufp->chgCData(oldp+49,(vlSelf->cpu_pipelined__DOT__funct3M),3);
        bufp->chgIData(oldp+50,(vlSelf->cpu_pipelined__DOT__read_dataM),32);
        bufp->chgBit(oldp+51,(vlSelf->cpu_pipelined__DOT__regwriteW));
        bufp->chgBit(oldp+52,(vlSelf->cpu_pipelined__DOT__resultsrcW));
        bufp->chgBit(oldp+53,(vlSelf->cpu_pipelined__DOT__pcwritemuxW));
        bufp->chgIData(oldp+54,(vlSelf->cpu_pipelined__DOT__read_dataW),32);
        bufp->chgIData(oldp+55,(vlSelf->cpu_pipelined__DOT__aluresultW),32);
        bufp->chgIData(oldp+56,(vlSelf->cpu_pipelined__DOT__pcplusfourW),32);
        bufp->chgCData(oldp+57,(vlSelf->cpu_pipelined__DOT__rdW),5);
        bufp->chgIData(oldp+58,(((1U == (((IData)(vlSelf->cpu_pipelined__DOT__pcwritemuxW) 
                                          << 1U) | (IData)(vlSelf->cpu_pipelined__DOT__resultsrcW)))
                                  ? vlSelf->cpu_pipelined__DOT__read_dataW
                                  : ((2U == (((IData)(vlSelf->cpu_pipelined__DOT__pcwritemuxW) 
                                              << 1U) 
                                             | (IData)(vlSelf->cpu_pipelined__DOT__resultsrcW)))
                                      ? vlSelf->cpu_pipelined__DOT__pcplusfourW
                                      : vlSelf->cpu_pipelined__DOT__aluresultW))),32);
        bufp->chgBit(oldp+59,((1U & (vlSelf->cpu_pipelined__DOT__instrD 
                                     >> 0x1eU))));
        bufp->chgCData(oldp+60,(vlSelf->cpu_pipelined__DOT__decode__DOT__immsrcD),3);
        bufp->chgIData(oldp+61,((vlSelf->cpu_pipelined__DOT__instrD 
                                 >> 7U)),25);
        bufp->chgCData(oldp+62,((0x1fU & (vlSelf->cpu_pipelined__DOT__instrD 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+63,((0x1fU & (vlSelf->cpu_pipelined__DOT__instrD 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+64,(vlSelf->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop),2);
        bufp->chgBit(oldp+65,(vlSelf->cpu_pipelined__DOT__execute__DOT__eq));
        bufp->chgIData(oldp+66,(vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc),32);
        bufp->chgIData(oldp+67,(vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2),32);
        bufp->chgIData(oldp+68,(vlSelf->cpu_pipelined__DOT__fetch__DOT__pcountunit__DOT__next_pc),32);
        bufp->chgCData(oldp+69,((3U & vlSelf->cpu_pipelined__DOT__aluresultM)),2);
        bufp->chgIData(oldp+70,((0xfffffffcU & vlSelf->cpu_pipelined__DOT__aluresultM)),32);
        bufp->chgIData(oldp+71,(vlSelf->cpu_pipelined__DOT__memory__DOT__ramout),32);
        bufp->chgIData(oldp+72,(vlSelf->cpu_pipelined__DOT__memory__DOT__ramin),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+73,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
                                [0xaU]),32);
        bufp->chgIData(oldp+74,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0]),32);
        bufp->chgIData(oldp+75,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[1]),32);
        bufp->chgIData(oldp+76,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[2]),32);
        bufp->chgIData(oldp+77,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[3]),32);
        bufp->chgIData(oldp+78,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[4]),32);
        bufp->chgIData(oldp+79,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[5]),32);
        bufp->chgIData(oldp+80,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[6]),32);
        bufp->chgIData(oldp+81,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[7]),32);
        bufp->chgIData(oldp+82,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[8]),32);
        bufp->chgIData(oldp+83,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[9]),32);
        bufp->chgIData(oldp+84,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[10]),32);
        bufp->chgIData(oldp+85,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[11]),32);
        bufp->chgIData(oldp+86,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[12]),32);
        bufp->chgIData(oldp+87,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[13]),32);
        bufp->chgIData(oldp+88,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[14]),32);
        bufp->chgIData(oldp+89,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[15]),32);
        bufp->chgIData(oldp+90,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[16]),32);
        bufp->chgIData(oldp+91,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[17]),32);
        bufp->chgIData(oldp+92,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[18]),32);
        bufp->chgIData(oldp+93,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[19]),32);
        bufp->chgIData(oldp+94,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[20]),32);
        bufp->chgIData(oldp+95,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[21]),32);
        bufp->chgIData(oldp+96,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[22]),32);
        bufp->chgIData(oldp+97,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[23]),32);
        bufp->chgIData(oldp+98,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[24]),32);
        bufp->chgIData(oldp+99,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[25]),32);
        bufp->chgIData(oldp+100,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[26]),32);
        bufp->chgIData(oldp+101,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[27]),32);
        bufp->chgIData(oldp+102,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[28]),32);
        bufp->chgIData(oldp+103,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[29]),32);
        bufp->chgIData(oldp+104,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[30]),32);
        bufp->chgIData(oldp+105,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[31]),32);
    }
    bufp->chgBit(oldp+106,(vlSelf->trigger));
    bufp->chgBit(oldp+107,(vlSelf->clk));
    bufp->chgBit(oldp+108,(vlSelf->rst));
    bufp->chgIData(oldp+109,(vlSelf->a0W),32);
    bufp->chgIData(oldp+110,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
                             [(0x1fU & (vlSelf->cpu_pipelined__DOT__instrD 
                                        >> 0xfU))]),32);
    bufp->chgIData(oldp+111,(vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
                             [(0x1fU & (vlSelf->cpu_pipelined__DOT__instrD 
                                        >> 0x14U))]),32);
}

void Vcpu_pipelined___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root__trace_cleanup\n"); );
    // Init
    Vcpu_pipelined___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu_pipelined___024root*>(voidSelf);
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
