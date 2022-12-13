// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCPU_PIPELINED_H_
#define _VCPU_PIPELINED_H_  // guard

#include "verilated_heavy.h"

//==========

class Vcpu_pipelined__Syms;
class Vcpu_pipelined_VerilatedVcd;


//----------

VL_MODULE(Vcpu_pipelined) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(trigger,0,0);
    VL_IN8(rst,0,0);
    VL_OUT(a0W,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
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
    IData/*31:0*/ cpu_pipelined__DOT__memory__DOT__ramin;
    IData/*31:0*/ cpu_pipelined__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i;
    CData/*7:0*/ cpu_pipelined__DOT__fetch__DOT__instrmem__DOT__rom_array[4096];
    IData/*31:0*/ cpu_pipelined__DOT__decode__DOT__rfD__DOT__rf_array[32];
    CData/*7:0*/ cpu_pipelined__DOT__memory__DOT__ram__DOT__ram_array[131072];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*6:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vm_traceActivity[3];
    static CData/*0:0*/ __Vtable1_cpu_pipelined__DOT__regwriteD[128];
    static CData/*0:0*/ __Vtable1_cpu_pipelined__DOT__alusrcD[128];
    static CData/*0:0*/ __Vtable1_cpu_pipelined__DOT__memwriteD[128];
    static CData/*0:0*/ __Vtable1_cpu_pipelined__DOT__resultsrcD[128];
    static CData/*0:0*/ __Vtable1_cpu_pipelined__DOT__jbmuxD[128];
    static CData/*0:0*/ __Vtable1_cpu_pipelined__DOT__pcwritemuxD[128];
    static CData/*0:0*/ __Vtable1_cpu_pipelined__DOT__addupperD[128];
    static CData/*2:0*/ __Vtable1_cpu_pipelined__DOT__decode__DOT__immsrcD[128];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcpu_pipelined__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcpu_pipelined);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcpu_pipelined(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcpu_pipelined();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcpu_pipelined__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcpu_pipelined__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcpu_pipelined__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vcpu_pipelined__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcpu_pipelined__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vcpu_pipelined__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcpu_pipelined__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vcpu_pipelined__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vcpu_pipelined__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vcpu_pipelined__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vcpu_pipelined__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
