#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vcpu_pipelined.h"
#include <iostream>
#include <iomanip>

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 1000000000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int lights = 0; // state to toggle LED lights

  Verilated::commandArgs(argc, argv);
  
  // init cpu_pipelined verilog instance
  Vcpu_pipelined * cpu_pipelined = new Vcpu_pipelined;
  
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  cpu_pipelined->trace (tfp, 99);
  tfp->open ("whole.vcd");

  cpu_pipelined->clk = 0;
  cpu_pipelined->rst = 0;

  if (vbdOpen()!=1) return(-1);
  vbdHeader("Pipelined Cpu");
  vbdSetMode(1);


  for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++) {

    for (tick = 0; tick < 2; tick++) {
      tfp->dump (2*simcyc+tick);
      cpu_pipelined->clk = !cpu_pipelined->clk;
      cpu_pipelined->eval ();
    }

    //Uncomment the following line for pdf.s
    // if(simcyc > 900000 && simcyc % 15 == 0) vbdPlot(cpu_pipelined->a0W, 0, 255);
    
    // Uncomment the following Lines for F1, Alu test, Whole Test, Ensure that they are commented for pdf program
    // cpu_pipelined->trigger = vbdFlag();
    // vbdBar(cpu_pipelined->a0W);
    // vbdCycle(simcyc);

    if (Verilated::gotFinish())  exit(0);
  }

    vbdClose();     
    tfp->close(); 
    exit(0);
}
