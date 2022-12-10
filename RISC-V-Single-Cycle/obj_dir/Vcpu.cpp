// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu.h for the primary calling header

#include "Vcpu.h"
#include "Vcpu__Syms.h"

//==========

void Vcpu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcpu::eval\n"); );
    Vcpu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("RTL/cpu.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcpu::_eval_initial_loop(Vcpu__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("RTL/cpu.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vcpu::_sequent__TOP__2(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_sequent__TOP__2\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__cpu__DOT__registerfile__DOT__rf_array__v0;
    CData/*4:0*/ __Vdlyvdim0__cpu__DOT__registerfile__DOT__rf_array__v1;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__registerfile__DOT__rf_array__v1;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__memory__DOT__ram__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__memory__DOT__ram__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__memory__DOT__ram__DOT__ram_array__v1;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__memory__DOT__ram__DOT__ram_array__v2;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__memory__DOT__ram__DOT__ram_array__v3;
    SData/*12:0*/ __Vdlyvdim0__cpu__DOT__memory__DOT__ram__DOT__ram_array__v0;
    SData/*12:0*/ __Vdlyvdim0__cpu__DOT__memory__DOT__ram__DOT__ram_array__v1;
    SData/*12:0*/ __Vdlyvdim0__cpu__DOT__memory__DOT__ram__DOT__ram_array__v2;
    SData/*12:0*/ __Vdlyvdim0__cpu__DOT__memory__DOT__ram__DOT__ram_array__v3;
    IData/*31:0*/ __Vdlyvval__cpu__DOT__registerfile__DOT__rf_array__v1;
    // Body
    __Vdlyvset__cpu__DOT__memory__DOT__ram__DOT__ram_array__v0 = 0U;
    __Vdlyvset__cpu__DOT__registerfile__DOT__rf_array__v0 = 0U;
    __Vdlyvset__cpu__DOT__registerfile__DOT__rf_array__v1 = 0U;
    vlTOPp->pc_plus4 = ((IData)(vlTOPp->rst) ? 0xbfc00000U
                         : ((IData)(4U) + vlTOPp->cpu__DOT__fetch__DOT__pcountunit__DOT__next_pc));
    if ((0x23U == (0x7fU & vlTOPp->cpu__DOT__interm_ins))) {
        __Vdlyvval__cpu__DOT__memory__DOT__ram__DOT__ram_array__v0 
            = (0xffU & vlTOPp->cpu__DOT__memory__DOT__ramin);
        __Vdlyvset__cpu__DOT__memory__DOT__ram__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__cpu__DOT__memory__DOT__ram__DOT__ram_array__v0 
            = (0x1ffcU & vlTOPp->cpu__DOT__interm_aluout);
        __Vdlyvval__cpu__DOT__memory__DOT__ram__DOT__ram_array__v1 
            = (0xffU & (vlTOPp->cpu__DOT__memory__DOT__ramin 
                        >> 8U));
        __Vdlyvdim0__cpu__DOT__memory__DOT__ram__DOT__ram_array__v1 
            = (0x1fffU & ((IData)(1U) + (0x1ffcU & vlTOPp->cpu__DOT__interm_aluout)));
        __Vdlyvval__cpu__DOT__memory__DOT__ram__DOT__ram_array__v2 
            = (0xffU & (vlTOPp->cpu__DOT__memory__DOT__ramin 
                        >> 0x10U));
        __Vdlyvdim0__cpu__DOT__memory__DOT__ram__DOT__ram_array__v2 
            = (0x1fffU & ((IData)(2U) + (0x1ffcU & vlTOPp->cpu__DOT__interm_aluout)));
        __Vdlyvval__cpu__DOT__memory__DOT__ram__DOT__ram_array__v3 
            = (0xffU & (vlTOPp->cpu__DOT__memory__DOT__ramin 
                        >> 0x18U));
        __Vdlyvdim0__cpu__DOT__memory__DOT__ram__DOT__ram_array__v3 
            = (0x1fffU & ((IData)(3U) + (0x1ffcU & vlTOPp->cpu__DOT__interm_aluout)));
    }
    if (vlTOPp->trigger) {
        __Vdlyvset__cpu__DOT__registerfile__DOT__rf_array__v0 = 1U;
    }
    if ((((((((0x13U == (0x7fU & vlTOPp->cpu__DOT__interm_ins)) 
              | (3U == (0x7fU & vlTOPp->cpu__DOT__interm_ins))) 
             | (0x33U == (0x7fU & vlTOPp->cpu__DOT__interm_ins))) 
            | (0x67U <= (0x7fU & vlTOPp->cpu__DOT__interm_ins))) 
           | (0x17U == (0x7fU & vlTOPp->cpu__DOT__interm_ins))) 
          | (0x37U == (0x7fU & vlTOPp->cpu__DOT__interm_ins))) 
         & (0U != (0x1fU & (vlTOPp->cpu__DOT__interm_ins 
                            >> 7U))))) {
        __Vdlyvval__cpu__DOT__registerfile__DOT__rf_array__v1 
            = ((0x67U <= (0x7fU & vlTOPp->cpu__DOT__interm_ins))
                ? ((IData)(4U) + vlTOPp->cpu__DOT__prog_addr)
                : vlTOPp->cpu__DOT__result);
        __Vdlyvset__cpu__DOT__registerfile__DOT__rf_array__v1 = 1U;
        __Vdlyvdim0__cpu__DOT__registerfile__DOT__rf_array__v1 
            = (0x1fU & (vlTOPp->cpu__DOT__interm_ins 
                        >> 7U));
    }
    if (__Vdlyvset__cpu__DOT__memory__DOT__ram__DOT__ram_array__v0) {
        vlTOPp->cpu__DOT__memory__DOT__ram__DOT__ram_array[__Vdlyvdim0__cpu__DOT__memory__DOT__ram__DOT__ram_array__v0] 
            = __Vdlyvval__cpu__DOT__memory__DOT__ram__DOT__ram_array__v0;
        vlTOPp->cpu__DOT__memory__DOT__ram__DOT__ram_array[__Vdlyvdim0__cpu__DOT__memory__DOT__ram__DOT__ram_array__v1] 
            = __Vdlyvval__cpu__DOT__memory__DOT__ram__DOT__ram_array__v1;
        vlTOPp->cpu__DOT__memory__DOT__ram__DOT__ram_array[__Vdlyvdim0__cpu__DOT__memory__DOT__ram__DOT__ram_array__v2] 
            = __Vdlyvval__cpu__DOT__memory__DOT__ram__DOT__ram_array__v2;
        vlTOPp->cpu__DOT__memory__DOT__ram__DOT__ram_array[__Vdlyvdim0__cpu__DOT__memory__DOT__ram__DOT__ram_array__v3] 
            = __Vdlyvval__cpu__DOT__memory__DOT__ram__DOT__ram_array__v3;
    }
    if (__Vdlyvset__cpu__DOT__registerfile__DOT__rf_array__v0) {
        vlTOPp->cpu__DOT__registerfile__DOT__rf_array[9U] = 1U;
    }
    if (__Vdlyvset__cpu__DOT__registerfile__DOT__rf_array__v1) {
        vlTOPp->cpu__DOT__registerfile__DOT__rf_array[__Vdlyvdim0__cpu__DOT__registerfile__DOT__rf_array__v1] 
            = __Vdlyvval__cpu__DOT__registerfile__DOT__rf_array__v1;
    }
    vlTOPp->a0_output = vlTOPp->cpu__DOT__registerfile__DOT__rf_array
        [0xaU];
    vlTOPp->cpu__DOT__prog_addr = ((IData)(vlTOPp->rst)
                                    ? 0xbfc00000U : vlTOPp->cpu__DOT__fetch__DOT__pcountunit__DOT__next_pc);
    vlTOPp->cpu__DOT__interm_ins = ((vlTOPp->cpu__DOT__fetch__DOT__instrmem__DOT__rom_array
                                     [(0xfffU & vlTOPp->cpu__DOT__prog_addr)] 
                                     << 0x18U) | ((
                                                   vlTOPp->cpu__DOT__fetch__DOT__instrmem__DOT__rom_array
                                                   [
                                                   (0xfffU 
                                                    & ((IData)(1U) 
                                                       + vlTOPp->cpu__DOT__prog_addr))] 
                                                   << 0x10U) 
                                                  | ((vlTOPp->cpu__DOT__fetch__DOT__instrmem__DOT__rom_array
                                                      [
                                                      (0xfffU 
                                                       & ((IData)(2U) 
                                                          + vlTOPp->cpu__DOT__prog_addr))] 
                                                      << 8U) 
                                                     | vlTOPp->cpu__DOT__fetch__DOT__instrmem__DOT__rom_array
                                                     [
                                                     (0xfffU 
                                                      & ((IData)(3U) 
                                                         + vlTOPp->cpu__DOT__prog_addr))])));
    vlTOPp->cpu__DOT__interm_rfpc = ((0x17U == (0x7fU 
                                                & vlTOPp->cpu__DOT__interm_ins))
                                      ? vlTOPp->cpu__DOT__prog_addr
                                      : vlTOPp->cpu__DOT__registerfile__DOT__rf_array
                                     [(0x1fU & (vlTOPp->cpu__DOT__interm_ins 
                                                >> 0xfU))]);
    vlTOPp->cpu__DOT__rf_dout2 = vlTOPp->cpu__DOT__registerfile__DOT__rf_array
        [(0x1fU & (vlTOPp->cpu__DOT__interm_ins >> 0x14U))];
    vlTOPp->cpu__DOT__ctrlunit__DOT__aluop = (((((0x33U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->cpu__DOT__interm_ins)) 
                                                 | (0x13U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->cpu__DOT__interm_ins))) 
                                                | (0x37U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__interm_ins))) 
                                               << 1U) 
                                              | ((0x37U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->cpu__DOT__interm_ins)) 
                                                 | (0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->cpu__DOT__interm_ins))));
    vlTOPp->cpu__DOT__interm_immsrc = ((0x40U & vlTOPp->cpu__DOT__interm_ins)
                                        ? ((0x20U & vlTOPp->cpu__DOT__interm_ins)
                                            ? ((0x10U 
                                                & vlTOPp->cpu__DOT__interm_ins)
                                                ? 4U
                                                : (
                                                   (8U 
                                                    & vlTOPp->cpu__DOT__interm_ins)
                                                    ? 4U
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->cpu__DOT__interm_ins)
                                                     ? 4U
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->cpu__DOT__interm_ins)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->cpu__DOT__interm_ins)
                                                       ? 3U
                                                       : 4U)
                                                      : 4U))))
                                            : 4U) : 
                                       ((0x20U & vlTOPp->cpu__DOT__interm_ins)
                                         ? ((0x10U 
                                             & vlTOPp->cpu__DOT__interm_ins)
                                             ? ((8U 
                                                 & vlTOPp->cpu__DOT__interm_ins)
                                                 ? 4U
                                                 : 
                                                ((4U 
                                                  & vlTOPp->cpu__DOT__interm_ins)
                                                  ? 
                                                 ((2U 
                                                   & vlTOPp->cpu__DOT__interm_ins)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__interm_ins)
                                                    ? 1U
                                                    : 4U)
                                                   : 4U)
                                                  : 
                                                 ((2U 
                                                   & vlTOPp->cpu__DOT__interm_ins)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__interm_ins)
                                                    ? 7U
                                                    : 4U)
                                                   : 4U)))
                                             : ((8U 
                                                 & vlTOPp->cpu__DOT__interm_ins)
                                                 ? 4U
                                                 : 
                                                ((4U 
                                                  & vlTOPp->cpu__DOT__interm_ins)
                                                  ? 4U
                                                  : 
                                                 ((2U 
                                                   & vlTOPp->cpu__DOT__interm_ins)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__interm_ins)
                                                    ? 2U
                                                    : 4U)
                                                   : 4U))))
                                         : ((0x10U 
                                             & vlTOPp->cpu__DOT__interm_ins)
                                             ? ((8U 
                                                 & vlTOPp->cpu__DOT__interm_ins)
                                                 ? 4U
                                                 : 
                                                ((4U 
                                                  & vlTOPp->cpu__DOT__interm_ins)
                                                  ? 
                                                 ((2U 
                                                   & vlTOPp->cpu__DOT__interm_ins)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__interm_ins)
                                                    ? 1U
                                                    : 4U)
                                                   : 4U)
                                                  : 
                                                 ((2U 
                                                   & vlTOPp->cpu__DOT__interm_ins)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__interm_ins)
                                                    ? 0U
                                                    : 4U)
                                                   : 4U)))
                                             : ((8U 
                                                 & vlTOPp->cpu__DOT__interm_ins)
                                                 ? 4U
                                                 : 
                                                ((4U 
                                                  & vlTOPp->cpu__DOT__interm_ins)
                                                  ? 4U
                                                  : 
                                                 ((2U 
                                                   & vlTOPp->cpu__DOT__interm_ins)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__interm_ins)
                                                    ? 0U
                                                    : 4U)
                                                   : 4U))))));
    vlTOPp->cpu__DOT__interm_aluctrl = ((2U & (IData)(vlTOPp->cpu__DOT__ctrlunit__DOT__aluop))
                                         ? ((1U & (IData)(vlTOPp->cpu__DOT__ctrlunit__DOT__aluop))
                                             ? 0xfU
                                             : ((0x18U 
                                                 & ((vlTOPp->cpu__DOT__interm_ins 
                                                     >> 0x1bU) 
                                                    & ((((0x13U 
                                                          == 
                                                          (0x7fU 
                                                           & vlTOPp->cpu__DOT__interm_ins)) 
                                                         & (5U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->cpu__DOT__interm_ins 
                                                                >> 0xcU)))) 
                                                        | ((0x33U 
                                                            == 
                                                            (0x7fU 
                                                             & vlTOPp->cpu__DOT__interm_ins)) 
                                                           & ((5U 
                                                               == 
                                                               (7U 
                                                                & (vlTOPp->cpu__DOT__interm_ins 
                                                                   >> 0xcU))) 
                                                              | (0U 
                                                                 == 
                                                                 (7U 
                                                                  & (vlTOPp->cpu__DOT__interm_ins 
                                                                     >> 0xcU)))))) 
                                                       << 3U))) 
                                                | (7U 
                                                   & (vlTOPp->cpu__DOT__interm_ins 
                                                      >> 0xcU))))
                                         : ((1U & (IData)(vlTOPp->cpu__DOT__ctrlunit__DOT__aluop))
                                             ? ((4U 
                                                 & ((~ 
                                                     (vlTOPp->cpu__DOT__interm_ins 
                                                      >> 0xeU)) 
                                                    << 2U)) 
                                                | (3U 
                                                   & (vlTOPp->cpu__DOT__interm_ins 
                                                      >> 0xdU)))
                                             : 0U));
    vlTOPp->cpu__DOT__interm_immop = ((4U & (IData)(vlTOPp->cpu__DOT__interm_immsrc))
                                       ? ((2U & (IData)(vlTOPp->cpu__DOT__interm_immsrc))
                                           ? 0U : (
                                                   (1U 
                                                    & (IData)(vlTOPp->cpu__DOT__interm_immsrc))
                                                    ? 0U
                                                    : 
                                                   ((0xfff00000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->cpu__DOT__interm_ins 
                                                                       >> 0x1fU)))) 
                                                        << 0x14U)) 
                                                    | ((0xff000U 
                                                        & vlTOPp->cpu__DOT__interm_ins) 
                                                       | ((0x800U 
                                                           & (vlTOPp->cpu__DOT__interm_ins 
                                                              >> 9U)) 
                                                          | (0x7feU 
                                                             & (vlTOPp->cpu__DOT__interm_ins 
                                                                >> 0x14U)))))))
                                       : ((2U & (IData)(vlTOPp->cpu__DOT__interm_immsrc))
                                           ? ((1U & (IData)(vlTOPp->cpu__DOT__interm_immsrc))
                                               ? ((0xfffff000U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->cpu__DOT__interm_ins 
                                                                     >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | ((0x800U 
                                                      & (vlTOPp->cpu__DOT__interm_ins 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & (vlTOPp->cpu__DOT__interm_ins 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlTOPp->cpu__DOT__interm_ins 
                                                              >> 7U)))))
                                               : ((0xfffff000U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->cpu__DOT__interm_ins 
                                                                     >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | ((0xfe0U 
                                                      & (vlTOPp->cpu__DOT__interm_ins 
                                                         >> 0x14U)) 
                                                     | (0x1fU 
                                                        & (vlTOPp->cpu__DOT__interm_ins 
                                                           >> 7U)))))
                                           : ((1U & (IData)(vlTOPp->cpu__DOT__interm_immsrc))
                                               ? (0xfffff000U 
                                                  & vlTOPp->cpu__DOT__interm_ins)
                                               : ((0xfffff000U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->cpu__DOT__interm_ins 
                                                                     >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | (0xfffU 
                                                     & (vlTOPp->cpu__DOT__interm_ins 
                                                        >> 0x14U))))));
    vlTOPp->cpu__DOT__alu__DOT__aluop2 = (((((((3U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->cpu__DOT__interm_ins)) 
                                               | (0x13U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->cpu__DOT__interm_ins))) 
                                              | (0x23U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->cpu__DOT__interm_ins))) 
                                             | (0x67U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->cpu__DOT__interm_ins))) 
                                            | (0x17U 
                                               == (0x7fU 
                                                   & vlTOPp->cpu__DOT__interm_ins))) 
                                           | (0x37U 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__interm_ins)))
                                           ? vlTOPp->cpu__DOT__interm_immop
                                           : vlTOPp->cpu__DOT__rf_dout2);
    vlTOPp->cpu__DOT__interm_aluout = ((8U & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                        ? ((4U & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                            ? ((2U 
                                                & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                                    ? vlTOPp->cpu__DOT__alu__DOT__aluop2
                                                    : 0U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                                    ? 
                                                   VL_SHIFTRS_III(32,32,5, vlTOPp->cpu__DOT__interm_rfpc, 
                                                                  (0x1fU 
                                                                   & vlTOPp->cpu__DOT__alu__DOT__aluop2))
                                                    : 0U))
                                            : ((2U 
                                                & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                                    ? 0U
                                                    : 
                                                   (vlTOPp->cpu__DOT__interm_rfpc 
                                                    - vlTOPp->cpu__DOT__alu__DOT__aluop2))))
                                        : ((4U & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                            ? ((2U 
                                                & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                                    ? 
                                                   (vlTOPp->cpu__DOT__interm_rfpc 
                                                    & vlTOPp->cpu__DOT__alu__DOT__aluop2)
                                                    : 
                                                   (vlTOPp->cpu__DOT__interm_rfpc 
                                                    | vlTOPp->cpu__DOT__alu__DOT__aluop2))
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                                    ? 
                                                   ((0x1fU 
                                                     >= vlTOPp->cpu__DOT__alu__DOT__aluop2)
                                                     ? 
                                                    (vlTOPp->cpu__DOT__interm_rfpc 
                                                     >> vlTOPp->cpu__DOT__alu__DOT__aluop2)
                                                     : 0U)
                                                    : 
                                                   (vlTOPp->cpu__DOT__interm_rfpc 
                                                    ^ vlTOPp->cpu__DOT__alu__DOT__aluop2)))
                                            : ((2U 
                                                & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                                    ? 
                                                   (vlTOPp->cpu__DOT__interm_rfpc 
                                                    < vlTOPp->cpu__DOT__alu__DOT__aluop2)
                                                    : 
                                                   VL_LTS_III(32,32,32, vlTOPp->cpu__DOT__interm_rfpc, vlTOPp->cpu__DOT__alu__DOT__aluop2))
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                                    ? 
                                                   ((0x1fU 
                                                     >= vlTOPp->cpu__DOT__alu__DOT__aluop2)
                                                     ? 
                                                    (vlTOPp->cpu__DOT__interm_rfpc 
                                                     << vlTOPp->cpu__DOT__alu__DOT__aluop2)
                                                     : 0U)
                                                    : 
                                                   (vlTOPp->cpu__DOT__interm_rfpc 
                                                    + vlTOPp->cpu__DOT__alu__DOT__aluop2)))));
    vlTOPp->cpu__DOT__interm_eq = (1U & ((4U == (IData)(vlTOPp->cpu__DOT__interm_aluctrl))
                                          ? (0U != vlTOPp->cpu__DOT__interm_aluout)
                                          : vlTOPp->cpu__DOT__interm_aluout));
    vlTOPp->cpu__DOT__memory__DOT__ramout = ((vlTOPp->cpu__DOT__memory__DOT__ram__DOT__ram_array
                                              [(0x1fffU 
                                                & ((IData)(3U) 
                                                   + 
                                                   (0x1ffcU 
                                                    & vlTOPp->cpu__DOT__interm_aluout)))] 
                                              << 0x18U) 
                                             | ((vlTOPp->cpu__DOT__memory__DOT__ram__DOT__ram_array
                                                 [(0x1fffU 
                                                   & ((IData)(2U) 
                                                      + 
                                                      (0x1ffcU 
                                                       & vlTOPp->cpu__DOT__interm_aluout)))] 
                                                 << 0x10U) 
                                                | ((vlTOPp->cpu__DOT__memory__DOT__ram__DOT__ram_array
                                                    [
                                                    (0x1fffU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x1ffcU 
                                                         & vlTOPp->cpu__DOT__interm_aluout)))] 
                                                    << 8U) 
                                                   | vlTOPp->cpu__DOT__memory__DOT__ram__DOT__ram_array
                                                   [
                                                   (0x1ffcU 
                                                    & vlTOPp->cpu__DOT__interm_aluout)])));
    vlTOPp->cpu__DOT__memory__DOT__ramin = ((0U == 
                                             (7U & 
                                              (vlTOPp->cpu__DOT__interm_ins 
                                               >> 0xcU)))
                                             ? ((2U 
                                                 & vlTOPp->cpu__DOT__interm_aluout)
                                                 ? 
                                                ((1U 
                                                  & vlTOPp->cpu__DOT__interm_aluout)
                                                  ? 
                                                 ((0xff000000U 
                                                   & (vlTOPp->cpu__DOT__rf_dout2 
                                                      << 0x18U)) 
                                                  | (0xffffffU 
                                                     & vlTOPp->cpu__DOT__memory__DOT__ramout))
                                                  : 
                                                 ((0xff000000U 
                                                   & vlTOPp->cpu__DOT__memory__DOT__ramout) 
                                                  | ((0xff0000U 
                                                      & (vlTOPp->cpu__DOT__rf_dout2 
                                                         << 0x10U)) 
                                                     | (0xffffU 
                                                        & vlTOPp->cpu__DOT__memory__DOT__ramout))))
                                                 : 
                                                ((1U 
                                                  & vlTOPp->cpu__DOT__interm_aluout)
                                                  ? 
                                                 ((0xffff0000U 
                                                   & vlTOPp->cpu__DOT__memory__DOT__ramout) 
                                                  | ((0xff00U 
                                                      & (vlTOPp->cpu__DOT__rf_dout2 
                                                         << 8U)) 
                                                     | (0xffU 
                                                        & vlTOPp->cpu__DOT__memory__DOT__ramout)))
                                                  : 
                                                 ((0xffffff00U 
                                                   & vlTOPp->cpu__DOT__memory__DOT__ramout) 
                                                  | (0xffU 
                                                     & vlTOPp->cpu__DOT__rf_dout2))))
                                             : ((1U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->cpu__DOT__interm_ins 
                                                     >> 0xcU)))
                                                 ? 
                                                ((2U 
                                                  & vlTOPp->cpu__DOT__interm_aluout)
                                                  ? 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__interm_aluout)
                                                   ? 0U
                                                   : 
                                                  ((0xffff0000U 
                                                    & (vlTOPp->cpu__DOT__rf_dout2 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & vlTOPp->cpu__DOT__memory__DOT__ramout)))
                                                  : 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__interm_aluout)
                                                   ? 
                                                  ((0xff000000U 
                                                    & vlTOPp->cpu__DOT__memory__DOT__ramout) 
                                                   | ((0xffff00U 
                                                       & (vlTOPp->cpu__DOT__rf_dout2 
                                                          << 8U)) 
                                                      | (0xffU 
                                                         & vlTOPp->cpu__DOT__memory__DOT__ramout)))
                                                   : 
                                                  ((0xffff0000U 
                                                    & vlTOPp->cpu__DOT__memory__DOT__ramout) 
                                                   | (0xffffU 
                                                      & vlTOPp->cpu__DOT__rf_dout2))))
                                                 : vlTOPp->cpu__DOT__rf_dout2));
    vlTOPp->cpu__DOT__interm_loadout = ((0x4000U & vlTOPp->cpu__DOT__interm_ins)
                                         ? ((0x2000U 
                                             & vlTOPp->cpu__DOT__interm_ins)
                                             ? vlTOPp->cpu__DOT__memory__DOT__ramout
                                             : ((0x1000U 
                                                 & vlTOPp->cpu__DOT__interm_ins)
                                                 ? 
                                                ((2U 
                                                  & vlTOPp->cpu__DOT__interm_aluout)
                                                  ? 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__interm_aluout)
                                                   ? 0U
                                                   : 
                                                  (0xffffU 
                                                   & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                      >> 0x10U)))
                                                  : 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__interm_aluout)
                                                   ? 
                                                  (0xffffU 
                                                   & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                      >> 8U))
                                                   : 
                                                  (0xffffU 
                                                   & vlTOPp->cpu__DOT__memory__DOT__ramout)))
                                                 : 
                                                ((2U 
                                                  & vlTOPp->cpu__DOT__interm_aluout)
                                                  ? 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__interm_aluout)
                                                   ? 
                                                  (0xffU 
                                                   & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                      >> 0x18U))
                                                   : 
                                                  (0xffU 
                                                   & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                      >> 0x10U)))
                                                  : 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__interm_aluout)
                                                   ? 
                                                  (0xffU 
                                                   & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                      >> 8U))
                                                   : 
                                                  (0xffU 
                                                   & vlTOPp->cpu__DOT__memory__DOT__ramout)))))
                                         : ((0x2000U 
                                             & vlTOPp->cpu__DOT__interm_ins)
                                             ? vlTOPp->cpu__DOT__memory__DOT__ramout
                                             : ((0x1000U 
                                                 & vlTOPp->cpu__DOT__interm_ins)
                                                 ? 
                                                ((2U 
                                                  & vlTOPp->cpu__DOT__interm_aluout)
                                                  ? 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__interm_aluout)
                                                   ? 0U
                                                   : 
                                                  ((0xffff0000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                                      >> 0x1fU)))) 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                         >> 0x10U))))
                                                  : 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__interm_aluout)
                                                   ? 
                                                  ((0xffff0000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                                      >> 0x17U)))) 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                         >> 8U)))
                                                   : 
                                                  ((0xffff0000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                                      >> 0xfU)))) 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & vlTOPp->cpu__DOT__memory__DOT__ramout))))
                                                 : 
                                                ((2U 
                                                  & vlTOPp->cpu__DOT__interm_aluout)
                                                  ? 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__interm_aluout)
                                                   ? 
                                                  ((0xffffff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                                      >> 0x1fU)))) 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                         >> 0x18U)))
                                                   : 
                                                  ((0xffffff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                                      >> 0x17U)))) 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                         >> 0x10U))))
                                                  : 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__interm_aluout)
                                                   ? 
                                                  ((0xffffff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                                      >> 0xfU)))) 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                         >> 8U)))
                                                   : 
                                                  ((0xffffff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->cpu__DOT__memory__DOT__ramout 
                                                                      >> 7U)))) 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & vlTOPp->cpu__DOT__memory__DOT__ramout)))))));
    vlTOPp->cpu__DOT__result = ((3U == (0x7fU & vlTOPp->cpu__DOT__interm_ins))
                                 ? vlTOPp->cpu__DOT__interm_loadout
                                 : vlTOPp->cpu__DOT__interm_aluout);
    if ((0x67U == (0x7fU & vlTOPp->cpu__DOT__interm_ins))) {
        vlTOPp->cpu__DOT__jump_addr = vlTOPp->cpu__DOT__result;
        vlTOPp->cpu__DOT__fetch__DOT__pcountunit__DOT__branch_pc 
            = vlTOPp->cpu__DOT__jump_addr;
    } else {
        vlTOPp->cpu__DOT__jump_addr = vlTOPp->cpu__DOT__interm_immop;
        vlTOPp->cpu__DOT__fetch__DOT__pcountunit__DOT__branch_pc 
            = (vlTOPp->cpu__DOT__prog_addr + vlTOPp->cpu__DOT__jump_addr);
    }
    vlTOPp->cpu__DOT__fetch__DOT__pcountunit__DOT__next_pc 
        = (((0x67U <= (0x7fU & vlTOPp->cpu__DOT__interm_ins)) 
            | ((0x63U == (0x7fU & vlTOPp->cpu__DOT__interm_ins)) 
               & (((~ (IData)(vlTOPp->cpu__DOT__interm_eq)) 
                   & (((0U == (7U & (vlTOPp->cpu__DOT__interm_ins 
                                     >> 0xcU))) | (5U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->cpu__DOT__interm_ins 
                                                       >> 0xcU)))) 
                      | (7U == (7U & (vlTOPp->cpu__DOT__interm_ins 
                                      >> 0xcU))))) 
                  | ((IData)(vlTOPp->cpu__DOT__interm_eq) 
                     & (((1U == (7U & (vlTOPp->cpu__DOT__interm_ins 
                                       >> 0xcU))) | 
                         (4U == (7U & (vlTOPp->cpu__DOT__interm_ins 
                                       >> 0xcU)))) 
                        | (6U == (7U & (vlTOPp->cpu__DOT__interm_ins 
                                        >> 0xcU))))))))
            ? vlTOPp->cpu__DOT__fetch__DOT__pcountunit__DOT__branch_pc
            : ((IData)(4U) + vlTOPp->cpu__DOT__prog_addr));
}

void Vcpu::_eval(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vcpu::_change_request(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_change_request\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vcpu::_change_request_1(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_change_request_1\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcpu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
