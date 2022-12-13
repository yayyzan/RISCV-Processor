// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_pipelined.h for the primary calling header

#include "verilated.h"

#include "Vcpu_pipelined__Syms.h"
#include "Vcpu_pipelined___024root.h"

void Vcpu_pipelined___024root___ctor_var_reset(Vcpu_pipelined___024root* vlSelf);

Vcpu_pipelined___024root::Vcpu_pipelined___024root(Vcpu_pipelined__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vcpu_pipelined___024root___ctor_var_reset(this);
}

void Vcpu_pipelined___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vcpu_pipelined___024root::~Vcpu_pipelined___024root() {
}
