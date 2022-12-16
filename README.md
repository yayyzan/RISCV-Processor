
# **Using Pipelined CPU**

The Read me file includes instructions on how to replicate our tests and view the same results we achieved, in addition to instructions on how to run the other programs. Please ensure you have modified the script correctly if you are running `./make.sh` on Mac


## Replicating F1 Program [f1.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/programs/f1.s)
1. Ensure that the trigger is low before running the program and use vbdSetMode(1)
2. Ensure relevant lines are uncommented (lines 46 to 48) in [cpu_tb.cpp](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/cpu_tb.cpp)
3. run `./make.sh programs/f1.s`
4. Use trigger to start the sequence

## Replicating Whole Test [whole.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/programs/whole.s)
1. Ensure that the trigger is low before running the program and use vbdSetMode(1)
2. Ensure relevant lines are uncommented (lines 46 to 48) in [cpu_tb.cpp](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/cpu_tb.cpp)
3. Ensure `$display()` are uncommented in [cpu_pipelined.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/RTL/cpu_pipelined.sv) (lines 199 to 201) and [rf.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/RTL/rf.sv) (line 28)
4. Run `./make.sh programs/whole.s`
5. Registers s4 to s7 and a0 to a6 will be displayed on terminal
6. If s4 and s5 become 1 and the values of the registers stop changing. Compare the values in the registers to the values commented in [whole.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/programs/whole.s) under the program test
7. If the values are correct, press trigger to continue testing.
8. If `a4` remains `0x1e` and does not change to `0x63` and s7 becomes 1 then program ran successfully.

## Replicating Alu Test [alu.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/programs/alu.s)
1. Ensure that the trigger is low before running the program and use vbdSetMode(1)
2. Ensure relevant lines are uncommented (lines 46 to 48) in [cpu_tb.cpp](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/cpu_tb.cpp)
3. Ensure `$display()` are uncommented in [cpu_pipelined.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/RTL/cpu_pipelined.sv) (lines 199 to 201) and [rf.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/RTL/rf.sv) (line 28)
4. Run `./make.sh programs/alu.s`
5. Registers s4 to s7 and a0 to a6 will be displayed on terminal
6. Compare the values in the registers to those commented out in [alu.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/programs/alu.s), if they are correct then the program ran successfully


## Replicating PDF [pdf.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/programs/pdf.s)
1. Comment out all `$display()` statements in [cpu_pipelined.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/RTL/cpu_pipelined.sv) (lines 199 to 201) and [rf.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/RTL/rf.sv) (line 28)
2. Comment out lines 46 to 48 in [cpu_tb.cpp](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/cpu_tb.cpp)
3. Uncomment line 43 in [cpu_tb.cpp](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/cpu_tb.cpp)
4. Load a memory file from the mem directory into ram. The `$readmemh()` line is already present in ram and is offset by the correct value, simply change the name of the `.mem` in the statement
5. run `./make.sh program/pdf.s`
6. The Vbuddy should plot the pdf on the screen within a few seconds

## Replicating Counter [counter.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/programs/counter.s)
1. Ensure relevant lines are uncommented (lines 46 to 48) in [cpu_tb.cpp](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/cpu_tb.cpp)
2. run `./make.sh programs/counter.s` (Will count from 0xf0 to 0xfe and repeat)

## Running Your own programs
1. Modify the test bench for your program.
2. move `yourprogram.s` to the programs folder.
3. run `./make.sh programs/yourprogram.s`

The make file will assemble the .s file, create a formatted to little endian .hex file and load it into the instruction rom.

## **Note Regarding trigger**

Trigger is **wired directly** to s1 in the register file as shown below:
```systemverilog
  if (trigger) begin
    rf_array[9] <= {{31'b0}, 1'b1};
  end
```
Please be mindful of this when creating an assembly program.

## **Note regarding [Instruction memory](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/RTL/instrmem.sv)**

Do **NOT** Add multiple `$readmemh()` lines inside the instruction memory module. This is due to the way the `sed` command in the `make` shell script is used. 

## Running `./make.sh` on Mac
Note that the `./make` script was run on Ubuntu Linux 22.04 and on the GNU version of sed. This may very for different operating systems. For Mac, note the following:

Ensure that you are using the GNU version of `awk`, this can be done by running `brew install gawk`. In addition, modify the `sed` command on line 17 (from the `make.sh`) from:
`sed -i "s/\$readmemh(.*/$replacement/" ./RTL/instrmem.sv` to
`sed -i '' "s/\$readmemh(.*/$replacement/" ./RTL/instrmem.sv`

This is needed because Mac uses the BSD version of `sed` which understand the `-i` option slightly differently. See [Stack Overflow](https://stackoverflow.com/questions/21242932/sed-i-may-not-be-used-with-stdin-on-mac-os-x)
