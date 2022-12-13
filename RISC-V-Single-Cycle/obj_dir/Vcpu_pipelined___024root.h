// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcpu_pipelined.h for the primary calling header

#ifndef VERILATED_VCPU_PIPELINED___024ROOT_H_
#define VERILATED_VCPU_PIPELINED___024ROOT_H_  // guard

#include "verilated.h"

class Vcpu_pipelined__Syms;

class Vcpu_pipelined___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(trigger,0,0);
        VL_IN8(rst,0,0);
        CData/*0:0*/ cpu_pipelined__DOT__regwriteD;
        CData/*0:0*/ cpu_pipelined__DOT__resultsrcD;
        CData/*0:0*/ cpu_pipelined__DOT__memwriteD;
        CData/*0:0*/ cpu_pipelined__DOT__alusrcD;
        CData/*0:0*/ cpu_pipelined__DOT__addupperD;
        CData/*0:0*/ cpu_pipelined__DOT__jbmuxD;
        CData/*0:0*/ cpu_pipelined__DOT__pcwritemuxD;
        CData/*4:0*/ cpu_pipelined__DOT__rdD;
        CData/*0:0*/ cpu_pipelined__DOT__regwriteE;
        CData/*0:0*/ cpu_pipelined__DOT__addupperE;
        CData/*0:0*/ cpu_pipelined__DOT__alusrcE;
        CData/*0:0*/ cpu_pipelined__DOT__memwriteE;
        CData/*0:0*/ cpu_pipelined__DOT__resultsrcE;
        CData/*0:0*/ cpu_pipelined__DOT__jbmuxE;
        CData/*0:0*/ cpu_pipelined__DOT__pcwritemuxE;
        CData/*6:0*/ cpu_pipelined__DOT__opcodeE;
        CData/*4:0*/ cpu_pipelined__DOT__rdE;
        CData/*3:0*/ cpu_pipelined__DOT__aluctrlE;
        CData/*2:0*/ cpu_pipelined__DOT__funct3E;
        CData/*0:0*/ cpu_pipelined__DOT__pcsrcE;
        CData/*0:0*/ cpu_pipelined__DOT__regwriteM;
        CData/*0:0*/ cpu_pipelined__DOT__resultsrcM;
        CData/*0:0*/ cpu_pipelined__DOT__memwriteM;
        CData/*0:0*/ cpu_pipelined__DOT__pcwritemuxM;
        CData/*4:0*/ cpu_pipelined__DOT__rdM;
        CData/*2:0*/ cpu_pipelined__DOT__funct3M;
        CData/*0:0*/ cpu_pipelined__DOT__regwriteW;
        CData/*0:0*/ cpu_pipelined__DOT__resultsrcW;
        CData/*0:0*/ cpu_pipelined__DOT__pcwritemuxW;
        CData/*4:0*/ cpu_pipelined__DOT__rdW;
        CData/*2:0*/ cpu_pipelined__DOT__decode__DOT__immsrcD;
        CData/*1:0*/ cpu_pipelined__DOT__decode__DOT__ctrlunitD__DOT__aluop;
        CData/*0:0*/ cpu_pipelined__DOT__execute__DOT__eq;
        CData/*0:0*/ __Vclklast__TOP__clk;
        VL_OUT(a0W,31,0);
        IData/*31:0*/ cpu_pipelined__DOT__pcF;
        IData/*31:0*/ cpu_pipelined__DOT__pcplusfourF;
        IData/*31:0*/ cpu_pipelined__DOT__pcD;
        IData/*31:0*/ cpu_pipelined__DOT__instrD;
        IData/*31:0*/ cpu_pipelined__DOT__pcplusfourD;
        IData/*31:0*/ cpu_pipelined__DOT__immextD;
        IData/*31:0*/ cpu_pipelined__DOT__a0E;
        IData/*31:0*/ cpu_pipelined__DOT__rd1E;
        IData/*31:0*/ cpu_pipelined__DOT__rd2E;
        IData/*31:0*/ cpu_pipelined__DOT__immextE;
        IData/*31:0*/ cpu_pipelined__DOT__pcE;
        IData/*31:0*/ cpu_pipelined__DOT__pcplusfourE;
        IData/*31:0*/ cpu_pipelined__DOT__aluresultE;
        IData/*31:0*/ cpu_pipelined__DOT__aluresultM;
        IData/*31:0*/ cpu_pipelined__DOT__write_dataM;
        IData/*31:0*/ cpu_pipelined__DOT__pcplusfourM;
        IData/*31:0*/ cpu_pipelined__DOT__a0M;
        IData/*31:0*/ cpu_pipelined__DOT__read_dataM;
        IData/*31:0*/ cpu_pipelined__DOT__read_dataW;
        IData/*31:0*/ cpu_pipelined__DOT__aluresultW;
        IData/*31:0*/ cpu_pipelined__DOT__pcplusfourW;
        IData/*31:0*/ cpu_pipelined__DOT__fetch__DOT__pcountunit__DOT__next_pc;
        IData/*31:0*/ cpu_pipelined__DOT__decode__DOT__rfD__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ cpu_pipelined__DOT__execute__DOT__rfpc;
        IData/*31:0*/ cpu_pipelined__DOT__execute__DOT__alu__DOT__aluop2;
        IData/*31:0*/ cpu_pipelined__DOT__memory__DOT__ramout;
    };
    struct {
        IData/*31:0*/ cpu_pipelined__DOT__memory__DOT__ramin;
        IData/*31:0*/ cpu_pipelined__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i;
        VlUnpacked<CData/*7:0*/, 4096> cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array;
        VlUnpacked<IData/*31:0*/, 32> cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array;
        VlUnpacked<CData/*7:0*/, 131072> cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vcpu_pipelined__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcpu_pipelined___024root(Vcpu_pipelined__Syms* symsp, const char* name);
    ~Vcpu_pipelined___024root();
    VL_UNCOPYABLE(Vcpu_pipelined___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
