// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCPU_PIPELINED__SYMS_H_
#define VERILATED_VCPU_PIPELINED__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vcpu_pipelined.h"

// INCLUDE MODULE CLASSES
#include "Vcpu_pipelined___024root.h"

// SYMS CLASS (contains all model state)
class Vcpu_pipelined__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vcpu_pipelined* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vcpu_pipelined___024root       TOP;

    // CONSTRUCTORS
    Vcpu_pipelined__Syms(VerilatedContext* contextp, const char* namep, Vcpu_pipelined* modelp);
    ~Vcpu_pipelined__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
