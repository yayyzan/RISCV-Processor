// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcpu_pipelined.h"
#include "Vcpu_pipelined__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vcpu_pipelined::Vcpu_pipelined(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcpu_pipelined__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , trigger{vlSymsp->TOP.trigger}
    , rst{vlSymsp->TOP.rst}
    , a0W{vlSymsp->TOP.a0W}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcpu_pipelined::Vcpu_pipelined(const char* _vcname__)
    : Vcpu_pipelined(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcpu_pipelined::~Vcpu_pipelined() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vcpu_pipelined___024root___eval_initial(Vcpu_pipelined___024root* vlSelf);
void Vcpu_pipelined___024root___eval_settle(Vcpu_pipelined___024root* vlSelf);
void Vcpu_pipelined___024root___eval(Vcpu_pipelined___024root* vlSelf);
#ifdef VL_DEBUG
void Vcpu_pipelined___024root___eval_debug_assertions(Vcpu_pipelined___024root* vlSelf);
#endif  // VL_DEBUG
void Vcpu_pipelined___024root___final(Vcpu_pipelined___024root* vlSelf);

static void _eval_initial_loop(Vcpu_pipelined__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vcpu_pipelined___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vcpu_pipelined___024root___eval_settle(&(vlSymsp->TOP));
        Vcpu_pipelined___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vcpu_pipelined::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcpu_pipelined::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcpu_pipelined___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vcpu_pipelined___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vcpu_pipelined::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vcpu_pipelined::final() {
    Vcpu_pipelined___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcpu_pipelined::hierName() const { return vlSymsp->name(); }
const char* Vcpu_pipelined::modelName() const { return "Vcpu_pipelined"; }
unsigned Vcpu_pipelined::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vcpu_pipelined::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vcpu_pipelined___024root__trace_init_top(Vcpu_pipelined___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcpu_pipelined___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu_pipelined___024root*>(voidSelf);
    Vcpu_pipelined__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vcpu_pipelined___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vcpu_pipelined___024root__trace_register(Vcpu_pipelined___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vcpu_pipelined::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vcpu_pipelined::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vcpu_pipelined___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
