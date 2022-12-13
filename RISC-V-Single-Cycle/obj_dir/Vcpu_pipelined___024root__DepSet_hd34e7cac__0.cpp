// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_pipelined.h for the primary calling header

#include "verilated.h"

#include "Vcpu_pipelined___024root.h"

extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_h002bc909_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_h98b37967_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_h7df63985_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_h9cbb3ab4_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_hdc58851d_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_h994bf866_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_hcc157c6e_0;
extern const VlUnpacked<CData/*2:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_hed7deaaf_0;

VL_INLINE_OPT void Vcpu_pipelined___024root___sequent__TOP__0(Vcpu_pipelined___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root___sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    SData/*12:0*/ __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0;
    SData/*12:0*/ __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v1;
    CData/*7:0*/ __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v1;
    SData/*12:0*/ __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v2;
    CData/*7:0*/ __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v2;
    SData/*12:0*/ __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v3;
    CData/*7:0*/ __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v3;
    // Body
    __Vdlyvset__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0 = 0U;
    vlSelf->cpu_pipelined__DOT__read_dataW = vlSelf->cpu_pipelined__DOT__read_dataM;
    vlSelf->a0W = vlSelf->cpu_pipelined__DOT__a0M;
    vlSelf->cpu_pipelined__DOT__rdW = vlSelf->cpu_pipelined__DOT__rdM;
    vlSelf->cpu_pipelined__DOT__pcwritemuxW = vlSelf->cpu_pipelined__DOT__pcwritemuxM;
    vlSelf->cpu_pipelined__DOT__resultsrcW = vlSelf->cpu_pipelined__DOT__resultsrcM;
    vlSelf->cpu_pipelined__DOT__regwriteW = vlSelf->cpu_pipelined__DOT__regwriteM;
    vlSelf->cpu_pipelined__DOT__jbmuxE = ((~ (IData)(vlSelf->cpu_pipelined__DOT__pcsrcE)) 
                                          & (IData)(vlSelf->cpu_pipelined__DOT__jbmuxD));
    vlSelf->cpu_pipelined__DOT__pcplusfourW = vlSelf->cpu_pipelined__DOT__pcplusfourM;
    vlSelf->cpu_pipelined__DOT__aluresultW = vlSelf->cpu_pipelined__DOT__aluresultM;
    vlSelf->cpu_pipelined__DOT__funct3M = vlSelf->cpu_pipelined__DOT__funct3E;
    vlSelf->cpu_pipelined__DOT__alusrcE = ((~ (IData)(vlSelf->cpu_pipelined__DOT__pcsrcE)) 
                                           & (IData)(vlSelf->cpu_pipelined__DOT__alusrcD));
    vlSelf->cpu_pipelined__DOT__write_dataM = vlSelf->cpu_pipelined__DOT__rd2E;
    if (vlSelf->cpu_pipelined__DOT__memwriteM) {
        __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0 
            = (0xffU & vlSelf->cpu_pipelined__DOT__memory__DOT__ramin);
        __Vdlyvset__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0 
            = (0x1ffcU & vlSelf->cpu_pipelined__DOT__aluresultM);
        __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v1 
            = (0xffU & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramin 
                        >> 8U));
        __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v1 
            = (0x1fffU & ((IData)(1U) + (0x1ffcU & vlSelf->cpu_pipelined__DOT__aluresultM)));
        __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v2 
            = (0xffU & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramin 
                        >> 0x10U));
        __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v2 
            = (0x1fffU & ((IData)(2U) + (0x1ffcU & vlSelf->cpu_pipelined__DOT__aluresultM)));
        __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v3 
            = (vlSelf->cpu_pipelined__DOT__memory__DOT__ramin 
               >> 0x18U);
        __Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v3 
            = (0x1fffU & ((IData)(3U) + (0x1ffcU & vlSelf->cpu_pipelined__DOT__aluresultM)));
    }
    vlSelf->cpu_pipelined__DOT__addupperE = ((~ (IData)(vlSelf->cpu_pipelined__DOT__pcsrcE)) 
                                             & (IData)(vlSelf->cpu_pipelined__DOT__addupperD));
    if (__Vdlyvset__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0) {
        vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array[__Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0] 
            = __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v0;
        vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array[__Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v1] 
            = __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v1;
        vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array[__Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v2] 
            = __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v2;
        vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array[__Vdlyvdim0__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v3] 
            = __Vdlyvval__cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array__v3;
    }
    vlSelf->cpu_pipelined__DOT__a0M = vlSelf->cpu_pipelined__DOT__a0E;
    vlSelf->cpu_pipelined__DOT__rdM = vlSelf->cpu_pipelined__DOT__rdE;
    vlSelf->cpu_pipelined__DOT__pcwritemuxM = vlSelf->cpu_pipelined__DOT__pcwritemuxE;
    vlSelf->cpu_pipelined__DOT__resultsrcM = vlSelf->cpu_pipelined__DOT__resultsrcE;
    vlSelf->cpu_pipelined__DOT__regwriteM = vlSelf->cpu_pipelined__DOT__regwriteE;
    vlSelf->cpu_pipelined__DOT__pcplusfourM = vlSelf->cpu_pipelined__DOT__pcplusfourE;
    vlSelf->cpu_pipelined__DOT__memwriteM = vlSelf->cpu_pipelined__DOT__memwriteE;
    vlSelf->cpu_pipelined__DOT__aluresultM = vlSelf->cpu_pipelined__DOT__aluresultE;
    if (vlSelf->cpu_pipelined__DOT__pcsrcE) {
        vlSelf->cpu_pipelined__DOT__opcodeE = 0U;
        vlSelf->cpu_pipelined__DOT__immextE = 0U;
        vlSelf->cpu_pipelined__DOT__aluctrlE = 0U;
        vlSelf->cpu_pipelined__DOT__pcE = 0U;
        vlSelf->cpu_pipelined__DOT__rd1E = 0U;
    } else {
        vlSelf->cpu_pipelined__DOT__opcodeE = (0x7fU 
                                               & vlSelf->cpu_pipelined__DOT__instrD);
        vlSelf->cpu_pipelined__DOT__immextE = vlSelf->cpu_pipelined__DOT__immextD;
        vlSelf->cpu_pipelined__DOT__aluctrlE = ((2U 
                                                 & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                                  ? 0xfU
                                                  : 
                                                 ((0x18U 
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
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop))
                                                  ? 
                                                 ((4U 
                                                   & ((~ 
                                                       (vlSelf->cpu_pipelined__DOT__instrD 
                                                        >> 0xeU)) 
                                                      << 2U)) 
                                                  | (3U 
                                                     & (vlSelf->cpu_pipelined__DOT__instrD 
                                                        >> 0xdU)))
                                                  : 0U));
        vlSelf->cpu_pipelined__DOT__pcE = vlSelf->cpu_pipelined__DOT__pcD;
        vlSelf->cpu_pipelined__DOT__rd1E = vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
            [(0x1fU & (vlSelf->cpu_pipelined__DOT__instrD 
                       >> 0xfU))];
    }
    vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc 
        = ((IData)(vlSelf->cpu_pipelined__DOT__addupperE)
            ? vlSelf->cpu_pipelined__DOT__pcE : vlSelf->cpu_pipelined__DOT__rd1E);
    vlSelf->cpu_pipelined__DOT__pcwritemuxE = ((~ (IData)(vlSelf->cpu_pipelined__DOT__pcsrcE)) 
                                               & (IData)(vlSelf->cpu_pipelined__DOT__pcwritemuxD));
    vlSelf->cpu_pipelined__DOT__resultsrcE = ((~ (IData)(vlSelf->cpu_pipelined__DOT__pcsrcE)) 
                                              & (IData)(vlSelf->cpu_pipelined__DOT__resultsrcD));
    vlSelf->cpu_pipelined__DOT__regwriteE = ((~ (IData)(vlSelf->cpu_pipelined__DOT__pcsrcE)) 
                                             & (IData)(vlSelf->cpu_pipelined__DOT__regwriteD));
    if (vlSelf->cpu_pipelined__DOT__pcsrcE) {
        vlSelf->cpu_pipelined__DOT__funct3E = 0U;
        vlSelf->cpu_pipelined__DOT__rd2E = 0U;
    } else {
        vlSelf->cpu_pipelined__DOT__funct3E = (7U & 
                                               (vlSelf->cpu_pipelined__DOT__instrD 
                                                >> 0xcU));
        vlSelf->cpu_pipelined__DOT__rd2E = vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
            [(0x1fU & (vlSelf->cpu_pipelined__DOT__instrD 
                       >> 0x14U))];
    }
    vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2 
        = ((IData)(vlSelf->cpu_pipelined__DOT__alusrcE)
            ? vlSelf->cpu_pipelined__DOT__immextE : vlSelf->cpu_pipelined__DOT__rd2E);
    vlSelf->cpu_pipelined__DOT__aluresultE = ((8U & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                               ? ((4U 
                                                   & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                     ? vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2
                                                     : 0U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc, 
                                                                   (0x1fU 
                                                                    & vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2))
                                                     : 0U))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                     - vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2))))
                                               : ((4U 
                                                   & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                     ? 
                                                    (vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                     & vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)
                                                     : 
                                                    (vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                     | vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                     ? 
                                                    ((0x1fU 
                                                      >= vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)
                                                      ? 
                                                     (vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                      >> vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)
                                                      : 0U)
                                                     : 
                                                    (vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                     ^ vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                     ? 
                                                    (vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                     < vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)
                                                     : 
                                                    VL_LTS_III(32, vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc, vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                                                     ? 
                                                    ((0x1fU 
                                                      >= vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)
                                                      ? 
                                                     (vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                      << vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)
                                                      : 0U)
                                                     : 
                                                    (vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc 
                                                     + vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2)))));
    vlSelf->cpu_pipelined__DOT__memwriteE = ((~ (IData)(vlSelf->cpu_pipelined__DOT__pcsrcE)) 
                                             & (IData)(vlSelf->cpu_pipelined__DOT__memwriteD));
    vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
        = ((vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array
            [(0x1fffU & ((IData)(3U) + (0x1ffcU & vlSelf->cpu_pipelined__DOT__aluresultM)))] 
            << 0x18U) | ((vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array
                          [(0x1fffU & ((IData)(2U) 
                                       + (0x1ffcU & vlSelf->cpu_pipelined__DOT__aluresultM)))] 
                          << 0x10U) | ((vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array
                                        [(0x1fffU & 
                                          ((IData)(1U) 
                                           + (0x1ffcU 
                                              & vlSelf->cpu_pipelined__DOT__aluresultM)))] 
                                        << 8U) | vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array
                                       [(0x1ffcU & vlSelf->cpu_pipelined__DOT__aluresultM)])));
    vlSelf->cpu_pipelined__DOT__execute__DOT__eq = 
        (1U & ((4U == (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                ? (0U != vlSelf->cpu_pipelined__DOT__aluresultE)
                : vlSelf->cpu_pipelined__DOT__aluresultE));
    vlSelf->cpu_pipelined__DOT__read_dataM = ((4U & (IData)(vlSelf->cpu_pipelined__DOT__funct3M))
                                               ? ((2U 
                                                   & (IData)(vlSelf->cpu_pipelined__DOT__funct3M))
                                                   ? vlSelf->cpu_pipelined__DOT__memory__DOT__ramout
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->cpu_pipelined__DOT__funct3M))
                                                    ? 
                                                   ((2U 
                                                     & vlSelf->cpu_pipelined__DOT__aluresultM)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->cpu_pipelined__DOT__aluresultM)
                                                      ? 0U
                                                      : 
                                                     (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                      >> 0x10U))
                                                     : 
                                                    ((1U 
                                                      & vlSelf->cpu_pipelined__DOT__aluresultM)
                                                      ? 
                                                     (0xffffU 
                                                      & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                         >> 8U))
                                                      : 
                                                     (0xffffU 
                                                      & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout)))
                                                    : 
                                                   ((2U 
                                                     & vlSelf->cpu_pipelined__DOT__aluresultM)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->cpu_pipelined__DOT__aluresultM)
                                                      ? 
                                                     (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                      >> 0x18U)
                                                      : 
                                                     (0xffU 
                                                      & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                         >> 0x10U)))
                                                     : 
                                                    ((1U 
                                                      & vlSelf->cpu_pipelined__DOT__aluresultM)
                                                      ? 
                                                     (0xffU 
                                                      & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                         >> 8U))
                                                      : 
                                                     (0xffU 
                                                      & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout)))))
                                               : ((2U 
                                                   & (IData)(vlSelf->cpu_pipelined__DOT__funct3M))
                                                   ? vlSelf->cpu_pipelined__DOT__memory__DOT__ramout
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->cpu_pipelined__DOT__funct3M))
                                                    ? 
                                                   ((2U 
                                                     & vlSelf->cpu_pipelined__DOT__aluresultM)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->cpu_pipelined__DOT__aluresultM)
                                                      ? 0U
                                                      : 
                                                     (((- (IData)(
                                                                  (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                   >> 0x1fU))) 
                                                       << 0x10U) 
                                                      | (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                         >> 0x10U)))
                                                     : 
                                                    ((1U 
                                                      & vlSelf->cpu_pipelined__DOT__aluresultM)
                                                      ? 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                      >> 0x17U)))) 
                                                       << 0x10U) 
                                                      | (0xffffU 
                                                         & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                            >> 8U)))
                                                      : 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                      >> 0xfU)))) 
                                                       << 0x10U) 
                                                      | (0xffffU 
                                                         & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout))))
                                                    : 
                                                   ((2U 
                                                     & vlSelf->cpu_pipelined__DOT__aluresultM)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->cpu_pipelined__DOT__aluresultM)
                                                      ? 
                                                     (((- (IData)(
                                                                  (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                   >> 0x1fU))) 
                                                       << 8U) 
                                                      | (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                         >> 0x18U))
                                                      : 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                      >> 0x17U)))) 
                                                       << 8U) 
                                                      | (0xffU 
                                                         & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                            >> 0x10U))))
                                                     : 
                                                    ((1U 
                                                      & vlSelf->cpu_pipelined__DOT__aluresultM)
                                                      ? 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                      >> 0xfU)))) 
                                                       << 8U) 
                                                      | (0xffU 
                                                         & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                            >> 8U)))
                                                      : 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelf->cpu_pipelined__DOT__memory__DOT__ramout 
                                                                      >> 7U)))) 
                                                       << 8U) 
                                                      | (0xffU 
                                                         & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout)))))));
    vlSelf->cpu_pipelined__DOT__memory__DOT__ramin 
        = ((0U == (IData)(vlSelf->cpu_pipelined__DOT__funct3M))
            ? ((2U & vlSelf->cpu_pipelined__DOT__aluresultM)
                ? ((1U & vlSelf->cpu_pipelined__DOT__aluresultM)
                    ? ((vlSelf->cpu_pipelined__DOT__write_dataM 
                        << 0x18U) | (0xffffffU & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout))
                    : ((0xff000000U & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout) 
                       | ((0xff0000U & (vlSelf->cpu_pipelined__DOT__write_dataM 
                                        << 0x10U)) 
                          | (0xffffU & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout))))
                : ((1U & vlSelf->cpu_pipelined__DOT__aluresultM)
                    ? ((0xffff0000U & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout) 
                       | ((0xff00U & (vlSelf->cpu_pipelined__DOT__write_dataM 
                                      << 8U)) | (0xffU 
                                                 & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout)))
                    : ((0xffffff00U & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout) 
                       | (0xffU & vlSelf->cpu_pipelined__DOT__write_dataM))))
            : ((1U == (IData)(vlSelf->cpu_pipelined__DOT__funct3M))
                ? ((2U & vlSelf->cpu_pipelined__DOT__aluresultM)
                    ? ((1U & vlSelf->cpu_pipelined__DOT__aluresultM)
                        ? 0U : ((vlSelf->cpu_pipelined__DOT__write_dataM 
                                 << 0x10U) | (0xffffU 
                                              & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout)))
                    : ((1U & vlSelf->cpu_pipelined__DOT__aluresultM)
                        ? ((0xff000000U & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout) 
                           | ((0xffff00U & (vlSelf->cpu_pipelined__DOT__write_dataM 
                                            << 8U)) 
                              | (0xffU & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout)))
                        : ((0xffff0000U & vlSelf->cpu_pipelined__DOT__memory__DOT__ramout) 
                           | (0xffffU & vlSelf->cpu_pipelined__DOT__write_dataM))))
                : vlSelf->cpu_pipelined__DOT__write_dataM));
    if (vlSelf->cpu_pipelined__DOT__pcsrcE) {
        vlSelf->cpu_pipelined__DOT__pcD = 0U;
        vlSelf->cpu_pipelined__DOT__a0E = vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
            [0xaU];
        vlSelf->cpu_pipelined__DOT__rdE = 0U;
        vlSelf->cpu_pipelined__DOT__pcplusfourE = 0U;
        vlSelf->cpu_pipelined__DOT__instrD = 0U;
    } else {
        vlSelf->cpu_pipelined__DOT__pcD = vlSelf->cpu_pipelined__DOT__pcF;
        vlSelf->cpu_pipelined__DOT__a0E = vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array
            [0xaU];
        vlSelf->cpu_pipelined__DOT__rdE = vlSelf->cpu_pipelined__DOT__rdD;
        vlSelf->cpu_pipelined__DOT__pcplusfourE = vlSelf->cpu_pipelined__DOT__pcplusfourD;
        vlSelf->cpu_pipelined__DOT__instrD = ((vlSelf->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                               [(0xfffU 
                                                 & vlSelf->cpu_pipelined__DOT__pcF)] 
                                               << 0x18U) 
                                              | ((vlSelf->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array
                                                  [
                                                  (0xfffU 
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
                                                    [
                                                    (0xfffU 
                                                     & ((IData)(3U) 
                                                        + vlSelf->cpu_pipelined__DOT__pcF))])));
    }
    vlSelf->cpu_pipelined__DOT__pcF = ((IData)(vlSelf->rst)
                                        ? 0xbfc00000U
                                        : vlSelf->cpu_pipelined__DOT__fetch__DOT__pcountunit__DOT__next_pc);
    vlSelf->cpu_pipelined__DOT__pcplusfourD = ((IData)(vlSelf->cpu_pipelined__DOT__pcsrcE)
                                                ? 0U
                                                : vlSelf->cpu_pipelined__DOT__pcplusfourF);
    vlSelf->cpu_pipelined__DOT__pcplusfourF = ((IData)(vlSelf->rst)
                                                ? 0xbfc00000U
                                                : ((IData)(4U) 
                                                   + vlSelf->cpu_pipelined__DOT__fetch__DOT__pcountunit__DOT__next_pc));
    vlSelf->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop 
        = (((((0x33U == (0x7fU & vlSelf->cpu_pipelined__DOT__instrD)) 
              | (0x13U == (0x7fU & vlSelf->cpu_pipelined__DOT__instrD))) 
             | (0x37U == (0x7fU & vlSelf->cpu_pipelined__DOT__instrD))) 
            << 1U) | ((0x37U == (0x7fU & vlSelf->cpu_pipelined__DOT__instrD)) 
                      | (0x63U == (0x7fU & vlSelf->cpu_pipelined__DOT__instrD))));
    vlSelf->cpu_pipelined__DOT__rdD = (0x1fU & (vlSelf->cpu_pipelined__DOT__instrD 
                                                >> 7U));
    __Vtableidx1 = (0x7fU & vlSelf->cpu_pipelined__DOT__instrD);
    vlSelf->cpu_pipelined__DOT__regwriteD = Vcpu_pipelined__ConstPool__TABLE_h002bc909_0
        [__Vtableidx1];
    vlSelf->cpu_pipelined__DOT__alusrcD = Vcpu_pipelined__ConstPool__TABLE_h98b37967_0
        [__Vtableidx1];
    vlSelf->cpu_pipelined__DOT__memwriteD = Vcpu_pipelined__ConstPool__TABLE_h7df63985_0
        [__Vtableidx1];
    vlSelf->cpu_pipelined__DOT__resultsrcD = Vcpu_pipelined__ConstPool__TABLE_h9cbb3ab4_0
        [__Vtableidx1];
    vlSelf->cpu_pipelined__DOT__jbmuxD = Vcpu_pipelined__ConstPool__TABLE_hdc58851d_0
        [__Vtableidx1];
    vlSelf->cpu_pipelined__DOT__pcwritemuxD = Vcpu_pipelined__ConstPool__TABLE_h994bf866_0
        [__Vtableidx1];
    vlSelf->cpu_pipelined__DOT__addupperD = Vcpu_pipelined__ConstPool__TABLE_hcc157c6e_0
        [__Vtableidx1];
    vlSelf->cpu_pipelined__DOT__decode__DOT__immsrcD 
        = Vcpu_pipelined__ConstPool__TABLE_hed7deaaf_0
        [__Vtableidx1];
    vlSelf->cpu_pipelined__DOT__pcsrcE = ((0x67U <= (IData)(vlSelf->cpu_pipelined__DOT__opcodeE)) 
                                          | ((0x63U 
                                              == (IData)(vlSelf->cpu_pipelined__DOT__opcodeE)) 
                                             & (((~ (IData)(vlSelf->cpu_pipelined__DOT__execute__DOT__eq)) 
                                                 & (((0U 
                                                      == (IData)(vlSelf->cpu_pipelined__DOT__funct3E)) 
                                                     | (5U 
                                                        == (IData)(vlSelf->cpu_pipelined__DOT__funct3E))) 
                                                    | (7U 
                                                       == (IData)(vlSelf->cpu_pipelined__DOT__funct3E)))) 
                                                | ((IData)(vlSelf->cpu_pipelined__DOT__execute__DOT__eq) 
                                                   & (((1U 
                                                        == (IData)(vlSelf->cpu_pipelined__DOT__funct3E)) 
                                                       | (4U 
                                                          == (IData)(vlSelf->cpu_pipelined__DOT__funct3E))) 
                                                      | (6U 
                                                         == (IData)(vlSelf->cpu_pipelined__DOT__funct3E)))))));
    vlSelf->cpu_pipelined__DOT__fetch__DOT__pcountunit__DOT__next_pc 
        = ((IData)(vlSelf->cpu_pipelined__DOT__pcsrcE)
            ? ((IData)(vlSelf->cpu_pipelined__DOT__jbmuxE)
                ? vlSelf->cpu_pipelined__DOT__aluresultE
                : (vlSelf->cpu_pipelined__DOT__pcE 
                   + vlSelf->cpu_pipelined__DOT__immextE))
            : ((IData)(4U) + vlSelf->cpu_pipelined__DOT__pcF));
    vlSelf->cpu_pipelined__DOT__immextD = ((4U & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__immsrcD))
                                            ? ((2U 
                                                & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__immsrcD))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__immsrcD))
                                                    ? 0U
                                                    : 
                                                   (((- (IData)(
                                                                (vlSelf->cpu_pipelined__DOT__instrD 
                                                                 >> 0x1fU))) 
                                                     << 0x14U) 
                                                    | ((0xff000U 
                                                        & vlSelf->cpu_pipelined__DOT__instrD) 
                                                       | ((0x800U 
                                                           & (vlSelf->cpu_pipelined__DOT__instrD 
                                                              >> 9U)) 
                                                          | (0x7feU 
                                                             & (vlSelf->cpu_pipelined__DOT__instrD 
                                                                >> 0x14U)))))))
                                            : ((2U 
                                                & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__immsrcD))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__immsrcD))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelf->cpu_pipelined__DOT__instrD 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | ((0x800U 
                                                        & (vlSelf->cpu_pipelined__DOT__instrD 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (vlSelf->cpu_pipelined__DOT__instrD 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (vlSelf->cpu_pipelined__DOT__instrD 
                                                                >> 7U)))))
                                                    : 
                                                   (((- (IData)(
                                                                (vlSelf->cpu_pipelined__DOT__instrD 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | ((0xfe0U 
                                                        & (vlSelf->cpu_pipelined__DOT__instrD 
                                                           >> 0x14U)) 
                                                       | (0x1fU 
                                                          & (vlSelf->cpu_pipelined__DOT__instrD 
                                                             >> 7U)))))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->cpu_pipelined__DOT__decode__DOT__immsrcD))
                                                    ? 
                                                   (0xfffff000U 
                                                    & vlSelf->cpu_pipelined__DOT__instrD)
                                                    : 
                                                   (((- (IData)(
                                                                (vlSelf->cpu_pipelined__DOT__instrD 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | (vlSelf->cpu_pipelined__DOT__instrD 
                                                       >> 0x14U)))));
}

VL_INLINE_OPT void Vcpu_pipelined___024root___sequent__TOP__1(Vcpu_pipelined___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root___sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v0;
    CData/*4:0*/ __Vdlyvdim0__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1;
    IData/*31:0*/ __Vdlyvval__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1;
    CData/*0:0*/ __Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1;
    // Body
    __Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v0 = 0U;
    __Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1 = 0U;
    if (vlSelf->trigger) {
        __Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v0 = 1U;
    }
    if (((IData)(vlSelf->cpu_pipelined__DOT__regwriteW) 
         & (0U != (IData)(vlSelf->cpu_pipelined__DOT__rdW)))) {
        __Vdlyvval__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1 
            = ((1U == (((IData)(vlSelf->cpu_pipelined__DOT__pcwritemuxW) 
                        << 1U) | (IData)(vlSelf->cpu_pipelined__DOT__resultsrcW)))
                ? vlSelf->cpu_pipelined__DOT__read_dataW
                : ((2U == (((IData)(vlSelf->cpu_pipelined__DOT__pcwritemuxW) 
                            << 1U) | (IData)(vlSelf->cpu_pipelined__DOT__resultsrcW)))
                    ? vlSelf->cpu_pipelined__DOT__pcplusfourW
                    : vlSelf->cpu_pipelined__DOT__aluresultW));
        __Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1 = 1U;
        __Vdlyvdim0__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1 
            = vlSelf->cpu_pipelined__DOT__rdW;
    }
    if (__Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v0) {
        vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[9U] = 1U;
    }
    if (__Vdlyvset__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1) {
        vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[__Vdlyvdim0__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1] 
            = __Vdlyvval__cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array__v1;
    }
}

void Vcpu_pipelined___024root___eval(Vcpu_pipelined___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vcpu_pipelined___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (((~ (IData)(vlSelf->clk)) & (IData)(vlSelf->__Vclklast__TOP__clk))) {
        Vcpu_pipelined___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vcpu_pipelined___024root___eval_debug_assertions(Vcpu_pipelined___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
