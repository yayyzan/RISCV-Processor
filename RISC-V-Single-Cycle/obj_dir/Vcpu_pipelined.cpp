// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_pipelined.h for the primary calling header

#include "Vcpu_pipelined.h"
#include "Vcpu_pipelined__Syms.h"

//==========

void Vcpu_pipelined::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcpu_pipelined::eval\n"); );
    Vcpu_pipelined__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("RTL/cpu_pipelined.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcpu_pipelined::_eval_initial_loop(Vcpu_pipelined__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("RTL/cpu_pipelined.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vcpu_pipelined::_sequent__TOP__2(Vcpu_pipelined__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined::_sequent__TOP__2\n"); );
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v1;
    CData/*7:0*/ __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v2;
    CData/*7:0*/ __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v3;
    IData/*16:0*/ __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0;
    IData/*16:0*/ __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v1;
    IData/*16:0*/ __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v2;
    IData/*16:0*/ __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v3;
    // Body
    __Vdlyvset__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0 = 0U;
    vlTOPp->cpu_pipelined__DOT__read_dataW = vlTOPp->cpu_pipelined__DOT__read_dataM;
    vlTOPp->a0W = vlTOPp->cpu_pipelined__DOT__a0M;
    vlTOPp->cpu_pipelined__DOT__rdW = vlTOPp->cpu_pipelined__DOT__rdM;
    vlTOPp->cpu_pipelined__DOT__pcwritemuxW = vlTOPp->cpu_pipelined__DOT__pcwritemuxM;
    vlTOPp->cpu_pipelined__DOT__resultsrcW = vlTOPp->cpu_pipelined__DOT__resultsrcM;
    vlTOPp->cpu_pipelined__DOT__regwriteW = vlTOPp->cpu_pipelined__DOT__regwriteM;
    vlTOPp->cpu_pipelined__DOT__jbmuxE = ((~ (IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)) 
                                          & (IData)(vlTOPp->cpu_pipelined__DOT__jbmuxD));
    vlTOPp->cpu_pipelined__DOT__pcplusfourW = vlTOPp->cpu_pipelined__DOT__pcplusfourM;
    vlTOPp->cpu_pipelined__DOT__aluresultW = vlTOPp->cpu_pipelined__DOT__aluresultM;
    vlTOPp->cpu_pipelined__DOT__opcodeE = ((IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)
                                            ? 0U : 
                                           (0x7fU & vlTOPp->cpu_pipelined__DOT__instrD));
    vlTOPp->cpu_pipelined__DOT__funct3M = vlTOPp->cpu_pipelined__DOT__funct3E;
    vlTOPp->cpu_pipelined__DOT__immextE = ((IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)
                                            ? 0U : vlTOPp->cpu_pipelined__DOT__immextD);
    vlTOPp->cpu_pipelined__DOT__alusrcE = ((~ (IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)) 
                                           & (IData)(vlTOPp->cpu_pipelined__DOT__alusrcD));
    vlTOPp->cpu_pipelined__DOT__write_dataM = vlTOPp->cpu_pipelined__DOT__rd2E;
    if (vlTOPp->cpu_pipelined__DOT__memwriteM) {
        __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0 
            = (0xffU & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramin);
        __Vdlyvset__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0 
            = (0x1fffcU & vlTOPp->cpu_pipelined__DOT__aluresultM);
        __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v1 
            = (0xffU & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramin 
                        >> 8U));
        __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v1 
            = (0x1ffffU & ((IData)(1U) + (0x1fffcU 
                                          & vlTOPp->cpu_pipelined__DOT__aluresultM)));
        __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v2 
            = (0xffU & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramin 
                        >> 0x10U));
        __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v2 
            = (0x1ffffU & ((IData)(2U) + (0x1fffcU 
                                          & vlTOPp->cpu_pipelined__DOT__aluresultM)));
        __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v3 
            = (0xffU & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramin 
                        >> 0x18U));
        __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v3 
            = (0x1ffffU & ((IData)(3U) + (0x1fffcU 
                                          & vlTOPp->cpu_pipelined__DOT__aluresultM)));
    }
    vlTOPp->cpu_pipelined__DOT__addupperE = ((~ (IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)) 
                                             & (IData)(vlTOPp->cpu_pipelined__DOT__addupperD));
    if (vlTOPp->cpu_pipelined__DOT__pcsrcE) {
        vlTOPp->cpu_pipelined__DOT__aluctrlE = 0U;
        vlTOPp->cpu_pipelined__DOT__pcE = 0U;
        vlTOPp->cpu_pipelined__DOT__rd1E = 0U;
    } else {
        vlTOPp->cpu_pipelined__DOT__aluctrlE = ((2U 
                                                 & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                                  ? 0xfU
                                                  : 
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
                                                  | (7U 
                                                     & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                        >> 0xcU))))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                                  ? 
                                                 ((4U 
                                                   & ((~ 
                                                       (vlTOPp->cpu_pipelined__DOT__instrD 
                                                        >> 0xeU)) 
                                                      << 2U)) 
                                                  | (3U 
                                                     & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                        >> 0xdU)))
                                                  : 0U));
        vlTOPp->cpu_pipelined__DOT__pcE = vlTOPp->cpu_pipelined__DOT__pcD;
        vlTOPp->cpu_pipelined__DOT__rd1E = vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
            [(0x1fU & (vlTOPp->cpu_pipelined__DOT__instrD 
                       >> 0xfU))];
    }
    if (__Vdlyvset__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0) {
        vlTOPp->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array[__Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0] 
            = __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0;
        vlTOPp->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array[__Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v1] 
            = __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v1;
        vlTOPp->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array[__Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v2] 
            = __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v2;
        vlTOPp->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array[__Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v3] 
            = __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v3;
    }
    vlTOPp->cpu_pipelined__DOT__a0M = vlTOPp->cpu_pipelined__DOT__a0E;
    vlTOPp->cpu_pipelined__DOT__rdM = vlTOPp->cpu_pipelined__DOT__rdE;
    vlTOPp->cpu_pipelined__DOT__pcwritemuxM = vlTOPp->cpu_pipelined__DOT__pcwritemuxE;
    vlTOPp->cpu_pipelined__DOT__resultsrcM = vlTOPp->cpu_pipelined__DOT__resultsrcE;
    vlTOPp->cpu_pipelined__DOT__regwriteM = vlTOPp->cpu_pipelined__DOT__regwriteE;
    vlTOPp->cpu_pipelined__DOT__pcplusfourM = vlTOPp->cpu_pipelined__DOT__pcplusfourE;
    if (vlTOPp->cpu_pipelined__DOT__pcsrcE) {
        vlTOPp->cpu_pipelined__DOT__funct3E = 0U;
        vlTOPp->cpu_pipelined__DOT__rd2E = 0U;
    } else {
        vlTOPp->cpu_pipelined__DOT__funct3E = (7U & 
                                               (vlTOPp->cpu_pipelined__DOT__instrD 
                                                >> 0xcU));
        vlTOPp->cpu_pipelined__DOT__rd2E = vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
            [(0x1fU & (vlTOPp->cpu_pipelined__DOT__instrD 
                       >> 0x14U))];
    }
    vlTOPp->cpu_pipelined__DOT__memwriteM = vlTOPp->cpu_pipelined__DOT__memwriteE;
    vlTOPp->cpu_pipelined__DOT__aluresultM = vlTOPp->cpu_pipelined__DOT__aluresultE;
    vlTOPp->cpu_pipelined__DOT__pcD = ((IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)
                                        ? 0U : vlTOPp->cpu_pipelined__DOT__pcF);
    vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc 
        = ((IData)(vlTOPp->cpu_pipelined__DOT__addupperE)
            ? vlTOPp->cpu_pipelined__DOT__pcE : vlTOPp->cpu_pipelined__DOT__rd1E);
    if (vlTOPp->cpu_pipelined__DOT__pcsrcE) {
        vlTOPp->cpu_pipelined__DOT__a0E = vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
            [0xaU];
        vlTOPp->cpu_pipelined__DOT__rdE = 0U;
    } else {
        vlTOPp->cpu_pipelined__DOT__a0E = vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
            [0xaU];
        vlTOPp->cpu_pipelined__DOT__rdE = vlTOPp->cpu_pipelined__DOT__rdD;
    }
    vlTOPp->cpu_pipelined__DOT__pcwritemuxE = ((~ (IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)) 
                                               & (IData)(vlTOPp->cpu_pipelined__DOT__pcwritemuxD));
    vlTOPp->cpu_pipelined__DOT__resultsrcE = ((~ (IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)) 
                                              & (IData)(vlTOPp->cpu_pipelined__DOT__resultsrcD));
    vlTOPp->cpu_pipelined__DOT__regwriteE = ((~ (IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)) 
                                             & (IData)(vlTOPp->cpu_pipelined__DOT__regwriteD));
    vlTOPp->cpu_pipelined__DOT__pcplusfourE = ((IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)
                                                ? 0U
                                                : vlTOPp->cpu_pipelined__DOT__pcplusfourD);
    vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2 
        = ((IData)(vlTOPp->cpu_pipelined__DOT__alusrcE)
            ? vlTOPp->cpu_pipelined__DOT__immextE : vlTOPp->cpu_pipelined__DOT__rd2E);
    vlTOPp->cpu_pipelined__DOT__aluresultE = ((8U & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                               ? ((4U 
                                                   & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                     ? vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2
                                                     : 0U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc, 
                                                                   (0x1fU 
                                                                    & vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2))
                                                     : 0U))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                     ? 0U
                                                     : 
                                                    (vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                     - vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2))))
                                               : ((4U 
                                                   & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                     ? 
                                                    (vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                     & vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)
                                                     : 
                                                    (vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                     | vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                     ? 
                                                    ((0x1fU 
                                                      >= vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)
                                                      ? 
                                                     (vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                      >> vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)
                                                      : 0U)
                                                     : 
                                                    (vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                     ^ vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                     ? 
                                                    (vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                     < vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)
                                                     : 
                                                    VL_LTS_III(32,32,32, vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc, vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                                                     ? 
                                                    ((0x1fU 
                                                      >= vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)
                                                      ? 
                                                     (vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                      << vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)
                                                      : 0U)
                                                     : 
                                                    (vlTOPp->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                     + vlTOPp->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)))));
    vlTOPp->cpu_pipelined__DOT__instrD = ((IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)
                                           ? 0U : (
                                                   (vlTOPp->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                                    [
                                                    (0xfffU 
                                                     & vlTOPp->cpu_pipelined__DOT__pcF)] 
                                                    << 0x18U) 
                                                   | ((vlTOPp->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
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
                                                             + vlTOPp->cpu_pipelined__DOT__pcF))]))));
    vlTOPp->cpu_pipelined__DOT__memwriteE = ((~ (IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)) 
                                             & (IData)(vlTOPp->cpu_pipelined__DOT__memwriteD));
    vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
        = ((vlTOPp->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array
            [(0x1ffffU & ((IData)(3U) + (0x1fffcU & vlTOPp->cpu_pipelined__DOT__aluresultM)))] 
            << 0x18U) | ((vlTOPp->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array
                          [(0x1ffffU & ((IData)(2U) 
                                        + (0x1fffcU 
                                           & vlTOPp->cpu_pipelined__DOT__aluresultM)))] 
                          << 0x10U) | ((vlTOPp->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array
                                        [(0x1ffffU 
                                          & ((IData)(1U) 
                                             + (0x1fffcU 
                                                & vlTOPp->cpu_pipelined__DOT__aluresultM)))] 
                                        << 8U) | vlTOPp->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array
                                       [(0x1fffcU & vlTOPp->cpu_pipelined__DOT__aluresultM)])));
    vlTOPp->cpu_pipelined__DOT__execute__DOT__eq = 
        (1U & ((4U == (IData)(vlTOPp->cpu_pipelined__DOT__aluctrlE))
                ? (0U != vlTOPp->cpu_pipelined__DOT__aluresultE)
                : vlTOPp->cpu_pipelined__DOT__aluresultE));
    vlTOPp->cpu_pipelined__DOT__read_dataM = ((4U & (IData)(vlTOPp->cpu_pipelined__DOT__funct3M))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->cpu_pipelined__DOT__funct3M))
                                                   ? vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->cpu_pipelined__DOT__funct3M))
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->cpu_pipelined__DOT__aluresultM)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->cpu_pipelined__DOT__aluresultM)
                                                      ? 0U
                                                      : 
                                                     (0xffffU 
                                                      & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                         >> 0x10U)))
                                                     : 
                                                    ((1U 
                                                      & vlTOPp->cpu_pipelined__DOT__aluresultM)
                                                      ? 
                                                     (0xffffU 
                                                      & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                         >> 8U))
                                                      : 
                                                     (0xffffU 
                                                      & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout)))
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->cpu_pipelined__DOT__aluresultM)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->cpu_pipelined__DOT__aluresultM)
                                                      ? 
                                                     (0xffU 
                                                      & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                         >> 0x18U))
                                                      : 
                                                     (0xffU 
                                                      & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                         >> 0x10U)))
                                                     : 
                                                    ((1U 
                                                      & vlTOPp->cpu_pipelined__DOT__aluresultM)
                                                      ? 
                                                     (0xffU 
                                                      & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                         >> 8U))
                                                      : 
                                                     (0xffU 
                                                      & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout)))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->cpu_pipelined__DOT__funct3M))
                                                   ? vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->cpu_pipelined__DOT__funct3M))
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->cpu_pipelined__DOT__aluresultM)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->cpu_pipelined__DOT__aluresultM)
                                                      ? 0U
                                                      : 
                                                     ((0xffff0000U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                         >> 0x1fU)))) 
                                                          << 0x10U)) 
                                                      | (0xffffU 
                                                         & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                            >> 0x10U))))
                                                     : 
                                                    ((1U 
                                                      & vlTOPp->cpu_pipelined__DOT__aluresultM)
                                                      ? 
                                                     ((0xffff0000U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                         >> 0x17U)))) 
                                                          << 0x10U)) 
                                                      | (0xffffU 
                                                         & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                            >> 8U)))
                                                      : 
                                                     ((0xffff0000U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                         >> 0xfU)))) 
                                                          << 0x10U)) 
                                                      | (0xffffU 
                                                         & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout))))
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->cpu_pipelined__DOT__aluresultM)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->cpu_pipelined__DOT__aluresultM)
                                                      ? 
                                                     ((0xffffff00U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                         >> 0x1fU)))) 
                                                          << 8U)) 
                                                      | (0xffU 
                                                         & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                            >> 0x18U)))
                                                      : 
                                                     ((0xffffff00U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                         >> 0x17U)))) 
                                                          << 8U)) 
                                                      | (0xffU 
                                                         & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                            >> 0x10U))))
                                                     : 
                                                    ((1U 
                                                      & vlTOPp->cpu_pipelined__DOT__aluresultM)
                                                      ? 
                                                     ((0xffffff00U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                         >> 0xfU)))) 
                                                          << 8U)) 
                                                      | (0xffU 
                                                         & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                            >> 8U)))
                                                      : 
                                                     ((0xffffff00U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & (vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                         >> 7U)))) 
                                                          << 8U)) 
                                                      | (0xffU 
                                                         & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout)))))));
    vlTOPp->cpu_pipelined__DOT__memory__DOT__ramin 
        = ((0U == (IData)(vlTOPp->cpu_pipelined__DOT__funct3M))
            ? ((2U & vlTOPp->cpu_pipelined__DOT__aluresultM)
                ? ((1U & vlTOPp->cpu_pipelined__DOT__aluresultM)
                    ? ((0xff000000U & (vlTOPp->cpu_pipelined__DOT__write_dataM 
                                       << 0x18U)) | 
                       (0xffffffU & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout))
                    : ((0xff000000U & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout) 
                       | ((0xff0000U & (vlTOPp->cpu_pipelined__DOT__write_dataM 
                                        << 0x10U)) 
                          | (0xffffU & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout))))
                : ((1U & vlTOPp->cpu_pipelined__DOT__aluresultM)
                    ? ((0xffff0000U & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout) 
                       | ((0xff00U & (vlTOPp->cpu_pipelined__DOT__write_dataM 
                                      << 8U)) | (0xffU 
                                                 & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout)))
                    : ((0xffffff00U & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout) 
                       | (0xffU & vlTOPp->cpu_pipelined__DOT__write_dataM))))
            : ((1U == (IData)(vlTOPp->cpu_pipelined__DOT__funct3M))
                ? ((2U & vlTOPp->cpu_pipelined__DOT__aluresultM)
                    ? ((1U & vlTOPp->cpu_pipelined__DOT__aluresultM)
                        ? 0U : ((0xffff0000U & (vlTOPp->cpu_pipelined__DOT__write_dataM 
                                                << 0x10U)) 
                                | (0xffffU & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout)))
                    : ((1U & vlTOPp->cpu_pipelined__DOT__aluresultM)
                        ? ((0xff000000U & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout) 
                           | ((0xffff00U & (vlTOPp->cpu_pipelined__DOT__write_dataM 
                                            << 8U)) 
                              | (0xffU & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout)))
                        : ((0xffff0000U & vlTOPp->cpu_pipelined__DOT__memory__DOT__ramout) 
                           | (0xffffU & vlTOPp->cpu_pipelined__DOT__write_dataM))))
                : vlTOPp->cpu_pipelined__DOT__write_dataM));
    vlTOPp->cpu_pipelined__DOT__pcplusfourD = ((IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)
                                                ? 0U
                                                : vlTOPp->cpu_pipelined__DOT__pcplusfourF);
    vlTOPp->cpu_pipelined__DOT__pcF = ((IData)(vlTOPp->rst)
                                        ? 0xbfc00000U
                                        : vlTOPp->cpu_pipelined__DOT__fetch__DOT__pcountunit__DOT__next_pc);
    vlTOPp->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop 
        = (((((0x33U == (0x7fU & vlTOPp->cpu_pipelined__DOT__instrD)) 
              | (0x13U == (0x7fU & vlTOPp->cpu_pipelined__DOT__instrD))) 
             | (0x37U == (0x7fU & vlTOPp->cpu_pipelined__DOT__instrD))) 
            << 1U) | ((0x37U == (0x7fU & vlTOPp->cpu_pipelined__DOT__instrD)) 
                      | (0x63U == (0x7fU & vlTOPp->cpu_pipelined__DOT__instrD))));
    vlTOPp->cpu_pipelined__DOT__rdD = (0x1fU & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                >> 7U));
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->cpu_pipelined__DOT__instrD);
    vlTOPp->cpu_pipelined__DOT__regwriteD = vlTOPp->__Vtable1_cpu_pipelined__DOT__regwriteD
        [vlTOPp->__Vtableidx1];
    vlTOPp->cpu_pipelined__DOT__alusrcD = vlTOPp->__Vtable1_cpu_pipelined__DOT__alusrcD
        [vlTOPp->__Vtableidx1];
    vlTOPp->cpu_pipelined__DOT__memwriteD = vlTOPp->__Vtable1_cpu_pipelined__DOT__memwriteD
        [vlTOPp->__Vtableidx1];
    vlTOPp->cpu_pipelined__DOT__resultsrcD = vlTOPp->__Vtable1_cpu_pipelined__DOT__resultsrcD
        [vlTOPp->__Vtableidx1];
    vlTOPp->cpu_pipelined__DOT__jbmuxD = vlTOPp->__Vtable1_cpu_pipelined__DOT__jbmuxD
        [vlTOPp->__Vtableidx1];
    vlTOPp->cpu_pipelined__DOT__pcwritemuxD = vlTOPp->__Vtable1_cpu_pipelined__DOT__pcwritemuxD
        [vlTOPp->__Vtableidx1];
    vlTOPp->cpu_pipelined__DOT__addupperD = vlTOPp->__Vtable1_cpu_pipelined__DOT__addupperD
        [vlTOPp->__Vtableidx1];
    vlTOPp->cpu_pipelined__DOT__decode__DOT__immsrcD 
        = vlTOPp->__Vtable1_cpu_pipelined__DOT__decode__DOT__immsrcD
        [vlTOPp->__Vtableidx1];
    vlTOPp->cpu_pipelined__DOT__pcsrcE = ((0x67U <= (IData)(vlTOPp->cpu_pipelined__DOT__opcodeE)) 
                                          | ((0x63U 
                                              == (IData)(vlTOPp->cpu_pipelined__DOT__opcodeE)) 
                                             & (((~ (IData)(vlTOPp->cpu_pipelined__DOT__execute__DOT__eq)) 
                                                 & (((0U 
                                                      == (IData)(vlTOPp->cpu_pipelined__DOT__funct3E)) 
                                                     | (5U 
                                                        == (IData)(vlTOPp->cpu_pipelined__DOT__funct3E))) 
                                                    | (7U 
                                                       == (IData)(vlTOPp->cpu_pipelined__DOT__funct3E)))) 
                                                | ((IData)(vlTOPp->cpu_pipelined__DOT__execute__DOT__eq) 
                                                   & (((1U 
                                                        == (IData)(vlTOPp->cpu_pipelined__DOT__funct3E)) 
                                                       | (4U 
                                                          == (IData)(vlTOPp->cpu_pipelined__DOT__funct3E))) 
                                                      | (6U 
                                                         == (IData)(vlTOPp->cpu_pipelined__DOT__funct3E)))))));
    vlTOPp->cpu_pipelined__DOT__immextD = ((4U & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__immsrcD))
                                            ? ((2U 
                                                & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__immsrcD))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__immsrcD))
                                                    ? 0U
                                                    : 
                                                   ((0xfff00000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                                       >> 0x1fU)))) 
                                                        << 0x14U)) 
                                                    | ((0xff000U 
                                                        & vlTOPp->cpu_pipelined__DOT__instrD) 
                                                       | ((0x800U 
                                                           & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                              >> 9U)) 
                                                          | (0x7feU 
                                                             & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                                >> 0x14U)))))))
                                            : ((2U 
                                                & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__immsrcD))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__immsrcD))
                                                    ? 
                                                   ((0xfffff000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                                       >> 0x1fU)))) 
                                                        << 0xcU)) 
                                                    | ((0x800U 
                                                        & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                                >> 7U)))))
                                                    : 
                                                   ((0xfffff000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                                       >> 0x1fU)))) 
                                                        << 0xcU)) 
                                                    | ((0xfe0U 
                                                        & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                           >> 0x14U)) 
                                                       | (0x1fU 
                                                          & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                             >> 7U)))))
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->cpu_pipelined__DOT__decode__DOT__immsrcD))
                                                    ? 
                                                   (0xfffff000U 
                                                    & vlTOPp->cpu_pipelined__DOT__instrD)
                                                    : 
                                                   ((0xfffff000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                                       >> 0x1fU)))) 
                                                        << 0xcU)) 
                                                    | (0xfffU 
                                                       & (vlTOPp->cpu_pipelined__DOT__instrD 
                                                          >> 0x14U))))));
    vlTOPp->cpu_pipelined__DOT__pcplusfourF = ((IData)(vlTOPp->rst)
                                                ? 0xbfc00000U
                                                : ((IData)(4U) 
                                                   + vlTOPp->cpu_pipelined__DOT__fetch__DOT__pcountunit__DOT__next_pc));
    vlTOPp->cpu_pipelined__DOT__fetch__DOT__pcountunit__DOT__next_pc 
        = ((IData)(vlTOPp->cpu_pipelined__DOT__pcsrcE)
            ? ((IData)(vlTOPp->cpu_pipelined__DOT__jbmuxE)
                ? vlTOPp->cpu_pipelined__DOT__aluresultE
                : (vlTOPp->cpu_pipelined__DOT__pcE 
                   + vlTOPp->cpu_pipelined__DOT__immextE))
            : ((IData)(4U) + vlTOPp->cpu_pipelined__DOT__pcF));
}

VL_INLINE_OPT void Vcpu_pipelined::_sequent__TOP__3(Vcpu_pipelined__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined::_sequent__TOP__3\n"); );
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v0;
    CData/*4:0*/ __Vdlyvdim0__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1;
    CData/*0:0*/ __Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1;
    IData/*31:0*/ __Vdlyvval__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1;
    // Body
    __Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v0 = 0U;
    __Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1 = 0U;
    if (vlTOPp->trigger) {
        __Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v0 = 1U;
    }
    if (((IData)(vlTOPp->cpu_pipelined__DOT__regwriteW) 
         & (0U != (IData)(vlTOPp->cpu_pipelined__DOT__rdW)))) {
        __Vdlyvval__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1 
            = ((1U == (((IData)(vlTOPp->cpu_pipelined__DOT__pcwritemuxW) 
                        << 1U) | (IData)(vlTOPp->cpu_pipelined__DOT__resultsrcW)))
                ? vlTOPp->cpu_pipelined__DOT__read_dataW
                : ((2U == (((IData)(vlTOPp->cpu_pipelined__DOT__pcwritemuxW) 
                            << 1U) | (IData)(vlTOPp->cpu_pipelined__DOT__resultsrcW)))
                    ? vlTOPp->cpu_pipelined__DOT__pcplusfourW
                    : vlTOPp->cpu_pipelined__DOT__aluresultW));
        __Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1 = 1U;
        __Vdlyvdim0__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1 
            = vlTOPp->cpu_pipelined__DOT__rdW;
    }
    if (__Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v0) {
        vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[9U] = 1U;
    }
    if (__Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1) {
        vlTOPp->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[__Vdlyvdim0__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1] 
            = __Vdlyvval__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1;
    }
}

void Vcpu_pipelined::_eval(Vcpu_pipelined__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined::_eval\n"); );
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vcpu_pipelined::_change_request(Vcpu_pipelined__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined::_change_request\n"); );
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vcpu_pipelined::_change_request_1(Vcpu_pipelined__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined::_change_request_1\n"); );
    Vcpu_pipelined* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcpu_pipelined::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
