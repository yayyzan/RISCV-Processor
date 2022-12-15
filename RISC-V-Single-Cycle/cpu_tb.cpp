#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vcpu.h"
#include <iostream>
#include <iomanip>

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 10000000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int lights = 0; // state to toggle LED lights

  Verilated::commandArgs(argc, argv);
  
  // init cpu verilog instance
  Vcpu * cpu = new Vcpu;
  
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  cpu->trace (tfp, 99);
  tfp->open ("alu.vcd");

  cpu->clk = 0;
  cpu->rst = 0;

  if (vbdOpen()!=1) return(-1);
  vbdHeader("whole test");
  vbdSetMode(1);  // set one shot mode for whole test

  
  for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++) {

    for (tick = 0; tick < 2; tick++) {
      tfp->dump (2*simcyc+tick);
      cpu->clk = !cpu->clk;
      cpu->eval ();
    }

    //Uncomment the following line for pdf.s
    // if(simcyc > 900000 && simcyc % 5 == 0) vbdPlot(cpu->a0_output, 0, 255);

    // Uncomment the following lines for F1, Alu test, Whole test. Ensure that they are commented for pdf program
    // vbdCycle(simcyc);
    // vbdBar(cpu->a0_output);
    // cpu->trigger = vbdFlag() || vbdGetkey() == 't';

    if (Verilated::gotFinish())  exit(0);
  }

    vbdClose();     
    tfp->close(); 
    exit(0);
}
