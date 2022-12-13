// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu__Syms.h"


void Vcpu::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vcpu::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgIData(oldp+0,(vlTOPp->cpu__DOT__registerfile__DOT__unnamedblk1__DOT__i),32);
            tracep->chgIData(oldp+1,(vlTOPp->cpu__DOT__memory__DOT__ram__DOT__unnamedblk1__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+2,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array
                                     [(0x1fU & (vlTOPp->cpu__DOT__interm_ins 
                                                >> 0xfU))]),32);
            tracep->chgIData(oldp+3,(vlTOPp->cpu__DOT__rf_dout2),32);
            tracep->chgIData(oldp+4,(vlTOPp->cpu__DOT__interm_immop),32);
            tracep->chgIData(oldp+5,(vlTOPp->cpu__DOT__prog_addr),32);
            tracep->chgIData(oldp+6,(vlTOPp->cpu__DOT__interm_ins),32);
            tracep->chgIData(oldp+7,(vlTOPp->cpu__DOT__interm_aluout),32);
            tracep->chgIData(oldp+8,(vlTOPp->cpu__DOT__interm_loadout),32);
            tracep->chgIData(oldp+9,(((0x67U <= (0x7fU 
                                                 & vlTOPp->cpu__DOT__interm_ins))
                                       ? ((IData)(4U) 
                                          + vlTOPp->cpu__DOT__prog_addr)
                                       : vlTOPp->cpu__DOT__result)),32);
            tracep->chgIData(oldp+10,(vlTOPp->cpu__DOT__jump_addr),32);
            tracep->chgIData(oldp+11,(vlTOPp->cpu__DOT__interm_rfpc),32);
            tracep->chgIData(oldp+12,(vlTOPp->cpu__DOT__result),32);
            tracep->chgCData(oldp+13,((0x7fU & vlTOPp->cpu__DOT__interm_ins)),7);
            tracep->chgCData(oldp+14,(vlTOPp->cpu__DOT__interm_aluctrl),4);
            tracep->chgCData(oldp+15,((7U & (vlTOPp->cpu__DOT__interm_ins 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+16,(vlTOPp->cpu__DOT__interm_immsrc),3);
            tracep->chgBit(oldp+17,((1U & (vlTOPp->cpu__DOT__interm_ins 
                                           >> 0x1eU))));
            tracep->chgBit(oldp+18,(((((((3U == (0x7fU 
                                                 & vlTOPp->cpu__DOT__interm_ins)) 
                                         | (0x13U == 
                                            (0x7fU 
                                             & vlTOPp->cpu__DOT__interm_ins))) 
                                        | (0x23U == 
                                           (0x7fU & vlTOPp->cpu__DOT__interm_ins))) 
                                       | (0x67U == 
                                          (0x7fU & vlTOPp->cpu__DOT__interm_ins))) 
                                      | (0x17U == (0x7fU 
                                                   & vlTOPp->cpu__DOT__interm_ins))) 
                                     | (0x37U == (0x7fU 
                                                  & vlTOPp->cpu__DOT__interm_ins)))));
            tracep->chgBit(oldp+19,(((0x67U <= (0x7fU 
                                                & vlTOPp->cpu__DOT__interm_ins)) 
                                     | ((0x63U == (0x7fU 
                                                   & vlTOPp->cpu__DOT__interm_ins)) 
                                        & (((~ (IData)(vlTOPp->cpu__DOT__interm_eq)) 
                                            & (((0U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->cpu__DOT__interm_ins 
                                                     >> 0xcU))) 
                                                | (5U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->cpu__DOT__interm_ins 
                                                       >> 0xcU)))) 
                                               | (7U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->cpu__DOT__interm_ins 
                                                      >> 0xcU))))) 
                                           | ((IData)(vlTOPp->cpu__DOT__interm_eq) 
                                              & (((1U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->cpu__DOT__interm_ins 
                                                       >> 0xcU))) 
                                                  | (4U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__interm_ins 
                                                         >> 0xcU)))) 
                                                 | (6U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->cpu__DOT__interm_ins 
                                                        >> 0xcU))))))))));
            tracep->chgBit(oldp+20,(vlTOPp->cpu__DOT__interm_eq));
            tracep->chgBit(oldp+21,(((((((0x13U == 
                                          (0x7fU & vlTOPp->cpu__DOT__interm_ins)) 
                                         | (3U == (0x7fU 
                                                   & vlTOPp->cpu__DOT__interm_ins))) 
                                        | (0x33U == 
                                           (0x7fU & vlTOPp->cpu__DOT__interm_ins))) 
                                       | (0x67U <= 
                                          (0x7fU & vlTOPp->cpu__DOT__interm_ins))) 
                                      | (0x17U == (0x7fU 
                                                   & vlTOPp->cpu__DOT__interm_ins))) 
                                     | (0x37U == (0x7fU 
                                                  & vlTOPp->cpu__DOT__interm_ins)))));
            tracep->chgBit(oldp+22,((0x23U == (0x7fU 
                                               & vlTOPp->cpu__DOT__interm_ins))));
            tracep->chgBit(oldp+23,((3U == (0x7fU & vlTOPp->cpu__DOT__interm_ins))));
            tracep->chgBit(oldp+24,((0x67U == (0x7fU 
                                               & vlTOPp->cpu__DOT__interm_ins))));
            tracep->chgBit(oldp+25,((0x67U <= (0x7fU 
                                               & vlTOPp->cpu__DOT__interm_ins))));
            tracep->chgBit(oldp+26,((0x17U == (0x7fU 
                                               & vlTOPp->cpu__DOT__interm_ins))));
            tracep->chgCData(oldp+27,(vlTOPp->cpu__DOT__ctrlunit__DOT__aluop),2);
            tracep->chgIData(oldp+28,(vlTOPp->cpu__DOT__programcounter__DOT__next_pc),32);
            tracep->chgIData(oldp+29,(vlTOPp->cpu__DOT__programcounter__DOT__branch_pc),32);
            tracep->chgIData(oldp+30,((0x1ffffffU & 
                                       (vlTOPp->cpu__DOT__interm_ins 
                                        >> 7U))),25);
            tracep->chgIData(oldp+31,(vlTOPp->cpu__DOT__alu__DOT__aluop2),32);
            tracep->chgCData(oldp+32,((0x1fU & (vlTOPp->cpu__DOT__interm_ins 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+33,((0x1fU & (vlTOPp->cpu__DOT__interm_ins 
                                                >> 0x14U))),5);
            tracep->chgCData(oldp+34,((0x1fU & (vlTOPp->cpu__DOT__interm_ins 
                                                >> 7U))),5);
            tracep->chgIData(oldp+35,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[0]),32);
            tracep->chgIData(oldp+36,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[1]),32);
            tracep->chgIData(oldp+37,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[2]),32);
            tracep->chgIData(oldp+38,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[3]),32);
            tracep->chgIData(oldp+39,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[4]),32);
            tracep->chgIData(oldp+40,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[5]),32);
            tracep->chgIData(oldp+41,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[6]),32);
            tracep->chgIData(oldp+42,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[7]),32);
            tracep->chgIData(oldp+43,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[8]),32);
            tracep->chgIData(oldp+44,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[9]),32);
            tracep->chgIData(oldp+45,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[10]),32);
            tracep->chgIData(oldp+46,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[11]),32);
            tracep->chgIData(oldp+47,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[12]),32);
            tracep->chgIData(oldp+48,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[13]),32);
            tracep->chgIData(oldp+49,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[14]),32);
            tracep->chgIData(oldp+50,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[15]),32);
            tracep->chgIData(oldp+51,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[16]),32);
            tracep->chgIData(oldp+52,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[17]),32);
            tracep->chgIData(oldp+53,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[18]),32);
            tracep->chgIData(oldp+54,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[19]),32);
            tracep->chgIData(oldp+55,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[20]),32);
            tracep->chgIData(oldp+56,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[21]),32);
            tracep->chgIData(oldp+57,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[22]),32);
            tracep->chgIData(oldp+58,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[23]),32);
            tracep->chgIData(oldp+59,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[24]),32);
            tracep->chgIData(oldp+60,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[25]),32);
            tracep->chgIData(oldp+61,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[26]),32);
            tracep->chgIData(oldp+62,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[27]),32);
            tracep->chgIData(oldp+63,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[28]),32);
            tracep->chgIData(oldp+64,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[29]),32);
            tracep->chgIData(oldp+65,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[30]),32);
            tracep->chgIData(oldp+66,(vlTOPp->cpu__DOT__registerfile__DOT__rf_array[31]),32);
            tracep->chgCData(oldp+67,((3U & vlTOPp->cpu__DOT__interm_aluout)),2);
            tracep->chgIData(oldp+68,((0xfffffffcU 
                                       & vlTOPp->cpu__DOT__interm_aluout)),32);
            tracep->chgIData(oldp+69,(vlTOPp->cpu__DOT__memory__DOT__ramout),32);
            tracep->chgIData(oldp+70,(vlTOPp->cpu__DOT__memory__DOT__ramin),32);
        }
        tracep->chgBit(oldp+71,(vlTOPp->trigger));
        tracep->chgBit(oldp+72,(vlTOPp->clk));
        tracep->chgBit(oldp+73,(vlTOPp->rst));
        tracep->chgIData(oldp+74,(vlTOPp->a0_output),32);
    }
}

void Vcpu::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
