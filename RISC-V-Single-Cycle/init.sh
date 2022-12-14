# cleanup
rm -rf obj_dir
rm -f *.vcd

# run Verilator to translate Verilog into C++, including C++ testbench
verilator -IRTL -Wall --cc --trace cpu.sv --exe cpu_tb.cpp

# build C++ project via make automatically generated by Verilator
make -j -C obj_dir/ -f Vcpu.mk Vcpu

# run executable simulation file
echo "\nRunning simulation"
obj_dir/Vcpu
echo "\nSimulation completed"

