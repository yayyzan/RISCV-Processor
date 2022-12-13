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
  vbdHeader("whole test");
  vbdSetMode(1);  // set one shot mode for whole test


  for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++) {

    for (tick = 0; tick < 2; tick++) {
      tfp->dump (2*simcyc+tick);
      cpu_pipelined->clk = !cpu_pipelined->clk;
      cpu_pipelined->eval ();
    }
    vbdCycle(simcyc);
    vbdBar(cpu_pipelined->a0W);
    cpu_pipelined->trigger = vbdFlag() || vbdGetkey() == 't';
    // std::cout << cpu_pipelined->a0_output << std::endl;
    // std::stringstream stream;
    // stream << std::hex << cpu_pipelined->a0_output;
    // std::string result(stream.str());

    // std::cout << "a0out:  " << result << std::endl;


    if (Verilated::gotFinish())  exit(0);
  }

    vbdClose();     
    tfp->close(); 
    exit(0);
}
