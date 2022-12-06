#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vloadmem.h"
#include <cstdio>
#define MAX_SIM_CYC 100

int main(int argc, char **argv, char **env) {
  int cycle;     // simulation clock count

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vloadmem* top = new Vloadmem;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("loadmem.vcd");

  // initialize simulation input 
  top->addrmode = 0;
  top->selectbytes = 0;
  top->ramout = 0x34fc78da;

  // run simulation for MAX_SIM_CYC clock cycles
  for (cycle=0; cycle<MAX_SIM_CYC; cycle++) {
    
    if (cycle == 5){
      top->addrmode = 0;
      top->selectbytes = 1;
    } //test load byte 

    if (cycle == 10){
      top->addrmode = 1;
      top->selectbytes = 2;
    } //test load half
   
    top->eval ();
    tfp->dump (cycle);

    if (Verilated::gotFinish()) 
      exit(0);
  }

  tfp->close(); 
  printf("Exiting\n");
  exit(0);
}
