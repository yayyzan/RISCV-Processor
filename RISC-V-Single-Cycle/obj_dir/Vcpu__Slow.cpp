// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu.h for the primary calling header

#include "Vcpu.h"
#include "Vcpu__Syms.h"

//==========

VL_CTOR_IMP(Vcpu) {
    Vcpu__Syms* __restrict vlSymsp = __VlSymsp = new Vcpu__Syms(this, name());
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcpu::__Vconfigure(Vcpu__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vcpu::~Vcpu() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vcpu::_initial__TOP__1(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_initial__TOP__1\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*159:0*/ __Vtemp2[5];
    // Body
    vlTOPp->cpu__DOT__fetch__DOT__pcountunit__DOT__branch_pc = 0xbfc00000U;
    vlTOPp->cpu__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i = 0x1000U;
    while (VL_GTS_III(1,32,32, 0x2000U, vlTOPp->cpu__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i)) {
        vlTOPp->cpu__DOT__memory__DOT__ram__DOT__ram_array[(0x1fffU 
                                                            & vlTOPp->cpu__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i)] = 0U;
        vlTOPp->cpu__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlTOPp->cpu__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i);
    }
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[1U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[2U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[3U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[4U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[5U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[6U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[7U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[8U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[9U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0xaU] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0xbU] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0xcU] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0xdU] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0xeU] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0xfU] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x10U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x11U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x12U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x13U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x14U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x15U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x16U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x17U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x18U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x19U] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x1aU] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x1bU] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x1cU] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x1dU] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x1eU] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0x1fU] = 0U;
    vlTOPp->cpu__DOT__registerfile__DOT__unnamedblk1__DOT__i = 0x20U;
    VL_WRITEF("Loading rom.\n");
    __Vtemp2[0U] = 0x2e686578U;
    __Vtemp2[1U] = 0x732f6631U;
    __Vtemp2[2U] = 0x6772616dU;
    __Vtemp2[3U] = 0x2f70726fU;
    __Vtemp2[4U] = 0x2eU;
    VL_READMEM_N(true, 8, 4096, 3217031168, VL_CVT_PACK_STR_NW(5, __Vtemp2)
                 , vlTOPp->cpu__DOT__fetch__DOT__instrmem__DOT__rom_array
                 , 3217031168, ~0ULL);
    VL_WRITEF("Program written to ROM successfully\n");
}

void Vcpu::_settle__TOP__3(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_settle__TOP__3\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->a0_output = vlTOPp->cpu__DOT__registerfile__DOT__rf_array
        [0xaU];
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

void Vcpu::_eval_initial(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_initial\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vcpu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::final\n"); );
    // Variables
    Vcpu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcpu::_eval_settle(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_settle\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vcpu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_ctor_var_reset\n"); );
    // Body
    trigger = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    a0_output = VL_RAND_RESET_I(32);
    pc_plus4 = VL_RAND_RESET_I(32);
    cpu__DOT__rf_dout2 = VL_RAND_RESET_I(32);
    cpu__DOT__interm_immop = VL_RAND_RESET_I(32);
    cpu__DOT__prog_addr = VL_RAND_RESET_I(32);
    cpu__DOT__interm_ins = VL_RAND_RESET_I(32);
    cpu__DOT__interm_aluout = VL_RAND_RESET_I(32);
    cpu__DOT__interm_loadout = VL_RAND_RESET_I(32);
    cpu__DOT__jump_addr = VL_RAND_RESET_I(32);
    cpu__DOT__interm_rfpc = VL_RAND_RESET_I(32);
    cpu__DOT__result = VL_RAND_RESET_I(32);
    cpu__DOT__interm_aluctrl = VL_RAND_RESET_I(4);
    cpu__DOT__interm_immsrc = VL_RAND_RESET_I(3);
    cpu__DOT__interm_eq = VL_RAND_RESET_I(1);
    cpu__DOT__ctrlunit__DOT__aluop = VL_RAND_RESET_I(2);
    cpu__DOT__fetch__DOT__pcountunit__DOT__next_pc = VL_RAND_RESET_I(32);
    cpu__DOT__fetch__DOT__pcountunit__DOT__branch_pc = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<4096; ++__Vi0) {
            cpu__DOT__fetch__DOT__instrmem__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }}
    cpu__DOT__alu__DOT__aluop2 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            cpu__DOT__registerfile__DOT__rf_array[__Vi0] = VL_RAND_RESET_I(32);
    }}
    cpu__DOT__registerfile__DOT__unnamedblk1__DOT__i = 0;
    cpu__DOT__memory__DOT__ramout = VL_RAND_RESET_I(32);
    cpu__DOT__memory__DOT__ramin = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<8192; ++__Vi0) {
            cpu__DOT__memory__DOT__ram__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }}
    cpu__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i = 0;
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
