// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_pipelined.h for the primary calling header

#include "verilated.h"

#include "Vcpu_pipelined___024root.h"

VL_ATTR_COLD void Vcpu_pipelined___024root___initial__TOP__0(Vcpu_pipelined___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root___initial__TOP__0\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h5e37a5af__0;
    // Body
    vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i = 0x1000U;
    while (VL_GTS_III(32, 0x2000U, vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i)) {
        vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array[(0x1fffU 
                                                                      & vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i)] = 0U;
        vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i);
    }
    VL_WRITEF("Loading rom.\n");
    __Vtemp_h5e37a5af__0[0U] = 0x2e686578U;
    __Vtemp_h5e37a5af__0[1U] = 0x732f6631U;
    __Vtemp_h5e37a5af__0[2U] = 0x6772616dU;
    __Vtemp_h5e37a5af__0[3U] = 0x2f70726fU;
    __Vtemp_h5e37a5af__0[4U] = 0x2eU;
    VL_READMEM_N(true, 8, 4096, 3217031168, VL_CVT_PACK_STR_NW(5, __Vtemp_h5e37a5af__0)
                 ,  &(vlSelf->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array)
                 , 3217031168, ~0ULL);
    VL_WRITEF("Program written to ROM successfully\n");
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[1U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[2U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[3U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[4U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[5U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[6U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[7U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[8U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[9U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0xaU] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0xbU] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0xcU] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0xdU] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0xeU] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0xfU] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x10U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x11U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x12U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x13U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x14U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x15U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x16U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x17U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x18U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x19U] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x1aU] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x1bU] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x1cU] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x1dU] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x1eU] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[0x1fU] = 0U;
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__unnamedblk1__DOT__i = 0x20U;
}

extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_h002bc909_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_h98b37967_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_h7df63985_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_h9cbb3ab4_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_hdc58851d_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_h994bf866_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_hcc157c6e_0;
extern const VlUnpacked<CData/*2:0*/, 128> Vcpu_pipelined__ConstPool__TABLE_hed7deaaf_0;

VL_ATTR_COLD void Vcpu_pipelined___024root___settle__TOP__0(Vcpu_pipelined___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root___settle__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    // Body
    vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc 
        = ((IData)(vlSelf->cpu_pipelined__DOT__addupperE)
            ? vlSelf->cpu_pipelined__DOT__pcE : vlSelf->cpu_pipelined__DOT__rd1E);
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
    vlSelf->cpu_pipelined__DOT__execute__DOT__eq = 
        (1U & ((4U == (IData)(vlSelf->cpu_pipelined__DOT__aluctrlE))
                ? (0U != vlSelf->cpu_pipelined__DOT__aluresultE)
                : vlSelf->cpu_pipelined__DOT__aluresultE));
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
}

VL_ATTR_COLD void Vcpu_pipelined___024root___eval_initial(Vcpu_pipelined___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root___eval_initial\n"); );
    // Body
    Vcpu_pipelined___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vcpu_pipelined___024root___eval_settle(Vcpu_pipelined___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root___eval_settle\n"); );
    // Body
    Vcpu_pipelined___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vcpu_pipelined___024root___final(Vcpu_pipelined___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root___final\n"); );
}

VL_ATTR_COLD void Vcpu_pipelined___024root___ctor_var_reset(Vcpu_pipelined___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_pipelined___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->trigger = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->a0W = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__pcF = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__pcplusfourF = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__pcD = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__instrD = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__pcplusfourD = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__regwriteD = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__resultsrcD = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__memwriteD = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__alusrcD = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__addupperD = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__jbmuxD = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__pcwritemuxD = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__immextD = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__rdD = VL_RAND_RESET_I(5);
    vlSelf->cpu_pipelined__DOT__regwriteE = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__addupperE = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__alusrcE = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__memwriteE = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__resultsrcE = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__jbmuxE = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__pcwritemuxE = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__a0E = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__rd1E = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__rd2E = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__immextE = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__pcE = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__pcplusfourE = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__opcodeE = VL_RAND_RESET_I(7);
    vlSelf->cpu_pipelined__DOT__rdE = VL_RAND_RESET_I(5);
    vlSelf->cpu_pipelined__DOT__aluctrlE = VL_RAND_RESET_I(4);
    vlSelf->cpu_pipelined__DOT__funct3E = VL_RAND_RESET_I(3);
    vlSelf->cpu_pipelined__DOT__aluresultE = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__pcsrcE = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__regwriteM = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__resultsrcM = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__memwriteM = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__pcwritemuxM = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__aluresultM = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__write_dataM = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__pcplusfourM = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__a0M = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__rdM = VL_RAND_RESET_I(5);
    vlSelf->cpu_pipelined__DOT__funct3M = VL_RAND_RESET_I(3);
    vlSelf->cpu_pipelined__DOT__read_dataM = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__regwriteW = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__resultsrcW = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__pcwritemuxW = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__read_dataW = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__aluresultW = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__pcplusfourW = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__rdW = VL_RAND_RESET_I(5);
    vlSelf->cpu_pipelined__DOT__fetch__DOT__pcountunit__DOT__next_pc = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->cpu_pipelined__DOT__decode__DOT__immsrcD = VL_RAND_RESET_I(3);
    vlSelf->cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop = VL_RAND_RESET_I(2);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->cpu_pipelined__DOT__decode__DOT__rfD__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->cpu_pipelined__DOT__execute__DOT__eq = VL_RAND_RESET_I(1);
    vlSelf->cpu_pipelined__DOT__execute__DOT__rfpc = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2 = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__memory__DOT__ramout = VL_RAND_RESET_I(32);
    vlSelf->cpu_pipelined__DOT__memory__DOT__ramin = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<8192; ++__Vi0) {
        vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->cpu_pipelined__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
