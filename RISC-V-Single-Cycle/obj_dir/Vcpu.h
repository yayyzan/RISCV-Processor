// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCPU_H_
#define _VCPU_H_  // guard

#include "verilated_heavy.h"

//==========

class Vcpu__Syms;
class Vcpu_VerilatedVcd;


//----------

VL_MODULE(Vcpu) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(trigger,0,0);
    VL_IN8(rst,0,0);
    VL_OUT(a0_output,31,0);
    VL_OUT(pc_plus4,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*3:0*/ cpu__DOT__interm_aluctrl;
    CData/*2:0*/ cpu__DOT__interm_immsrc;
    CData/*0:0*/ cpu__DOT__interm_eq;
    CData/*1:0*/ cpu__DOT__ctrlunit__DOT__aluop;
    IData/*31:0*/ cpu__DOT__rf_dout2;
    IData/*31:0*/ cpu__DOT__interm_immop;
    IData/*31:0*/ cpu__DOT__prog_addr;
    IData/*31:0*/ cpu__DOT__interm_ins;
    IData/*31:0*/ cpu__DOT__interm_aluout;
    IData/*31:0*/ cpu__DOT__interm_loadout;
    IData/*31:0*/ cpu__DOT__jump_addr;
    IData/*31:0*/ cpu__DOT__interm_rfpc;
    IData/*31:0*/ cpu__DOT__result;
    IData/*31:0*/ cpu__DOT__fetch__DOT__pcountunit__DOT__next_pc;
    IData/*31:0*/ cpu__DOT__fetch__DOT__pcountunit__DOT__branch_pc;
    IData/*31:0*/ cpu__DOT__alu__DOT__aluop2;
    IData/*31:0*/ cpu__DOT__registerfile__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ cpu__DOT__memory__DOT__ramout;
    IData/*31:0*/ cpu__DOT__memory__DOT__ramin;
    IData/*31:0*/ cpu__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i;
    CData/*7:0*/ cpu__DOT__fetch__DOT__instrmem__DOT__rom_array[4096];
    IData/*31:0*/ cpu__DOT__registerfile__DOT__rf_array[32];
    CData/*7:0*/ cpu__DOT__memory__DOT__ram__DOT__ram_array[8192];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcpu__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcpu);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcpu(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcpu();
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
    static void _eval_initial_loop(Vcpu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcpu__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcpu__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vcpu__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcpu__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vcpu__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
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
