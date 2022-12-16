# **Omar Alkhatib's Personal Statement** #

CID: 02109422

## Managing Git Repo

After a brief discussion with my group I decided to be the one in charge of managing the repo given to us by the GTA. I also recommended that we use branches this time around . This was quite a burden initially since it was my first time using branches properly on git. We had to use the command `git reset –hard HEAD~1` multiple times in order to reset the repo and start working again. After spending a whole day setting up git and learning how to use it properly, we had 4 feature branches ([alu](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/82a8489421e220bc3df2fe53f8ced5c1770456ab), [memory](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/2fffed370549b334e01a9ba23df020d71425a64d), [program-instructions](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/5955954ffe500b9a5e5611464dca7a6e818e8345), [control unit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/f11e79c60f5d61e01e21d47564e88a5bb7ffa80d)) set up and ready to go.


Keeping the git clean wasn’t too difficult afterwards, I became quite comfortable using git and understood merging and rebasing worked. This becomes clear after the [hash](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/a3c7d04a35839a5ee8bb1fb5dfcc6f963e1f2ee7) where we can more activity on the git hub tree (clean-up and test).

## Working On Alu  

I was tasked with making the ALU and testing it. This was quit straight forward for the most part. I needed to use the 3 bit signal `aluctrl` to determine the operation being done. In addition to the signal `alusrc` to determine the second operand. Before implementing it on code, I created the truth table shown below.


| OpCode | funct7 | funct3 | assembly | Operation|
| ------ | ------ | ------ | --------- | --------- |
| 51(R) | 0 | 000 | add rd, rs1, rs2 | `rd = rs1 + rs2`|
| 51(R) | 1 | 000 | sub rd, rs1, rs2 | `rd = rs1 - rs2`|
| 19(I) | x | 000 | addi rd, rs1, imm | `rd = rs1 + SignExt(imm)`|
| 51(R) or 19(I) | x | 001 | sll rd, rs1, op2 | `rd = rs1 << op2`|
| 51(R) or 19(I) | x | 010 | slt rd, rs1, op2 | `rd = (rs1 < op2)`|
| 51(R) or 19(I) | x | 011 | sltu rd, rs1, op2 | `rd = unsigned((rs1 < op2))`|
| 51(R) or 19(I) | x | 100 | xor rd, rs1, op2 | `rd = rs1 ^ op2`|
| 51(R) or 19(I) | 0 | 101 | srl rd, rs1, op2 | `rd = rs1 >> op2[4:0]`|
| 51(R) or 19(I) | 1 | 101 | sra rd, rs1, op2 | `rd = rs1 >>> op2[4:0]`|
| 51(R) or 19(I) | x | 110 | or rd, rs1, op2 | `rd = rs1 \|\| op2` |
| 51(R) or 19(I) | x | 111 | and rd, rs1, op2 | `rd = rs1 & op2`|

---

Note that the assembly would change slightly for `opcode == 19`, the instruction mnemonics are the same followed by the letter " I ".  

From the table I deduced that `op2 = (alusrc) ? signExt(Imm) : rs2`.

The table also shows that a fourth bit is needed for `[3:0] aluctrl` differentiate between the operations of sub/add, srl/sra and srli/srai.  

After noticing this, I contacted Yazan who was working on the control unit and we agreed to assign `aluctrl = {funct7, funct3}` where necessary, otherwise the fourth bit would be 0. This allowed me to implement the operations in code as shown on the [alu branch](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/96479783efc632defadd505dbafcb4c755586247).

Note that an extra operation was added later on for the implementation of LUI instruction, hence it required that the immediate pass through the ALU unchanged. This can be seen in [commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/92216f2bf91c8612541c05464feb8a5d01cae838). (Done by Yazan ayyoub)


As for branches, I set the `eq` flag to a different value based on the branch instruction being executed. A truth table for these values can be seen below.


|instruction|aluctrl|operation|eq|  
|-----------|-------|---------|--|
beq |0100 | xor rd, rs1, rs2|eq = (aluout != 0)|
bne |0100 | xor rd, rs1, rs2|eq = (aluout != 0)|
blt |0010 | slt rd, rs1, rs2|eq = aluout[0]|
bge |0010 | slt rd, rs1, rs2|eq = aluout[0]|
bltu |0011 | sltu rd, rs1, rs2|eq = aluout[0]|
bgeu |0011 | sltu rd, rs1, rs2|eq = aluout[0]|  

`eq` would then be taken back into the control unit where some logic is preformed to set the value of pcsrc. The logic for that was discussed between Yazan and I, however it was implemented inside the control unit by [Yazan Ayyoub](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Yazan_README.md).

Note that the above design was finalized in this [commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/c07bdf2bf7064690c91ec2e7478983f44b769413). Previous commits on the Alu branch had errors.

## Method of testing

Most of the CPU was tested with the use of display statements. These proved to be easier to use than debugging the CPU using Gtkwave. Hence it allowed me to easily select the values I wanted to display and print them in any format required. The general format of the display statements used is:

```verilog
  always_ff @ (posedge clk) begin
    $display("STRING1: %h", signal 1, " STRING2: %h, signal 2");
  end
```
These took some time to create however once they were made, it proved

By displaying the value of a signal on every clock cycle, it allowed me to trace through my test programs with relative ease. The use of displays proved to be advantageous in comparison the use of GTKwave for two main reasons.

* Speed:
  Although it takes some more time to type out the display statements initially, using them afterwards was much faster than debugging through the waveform.
  (Since we only needed to comment/uncomment the display statement).

* Clarity:
  Printing the values vertically with the instruction immediately under the signal made it easier to see how the signals were changing. Although this was not the case for the pipelined CPU since the instruction Fetched was written to the register displayed after 5 cycles. However the same applied for the waveform.

Over all, I found Displaying the signals to be easier, and it was the main method used to debug and verify that the CPU and/or the modules were working.

## Method of testing and verifying Alu

The Alu was tested and verified locally by inputting a clk signal into the alu module and using the display statement above. I was able to test the alu operations individually by using separate test bench, the relevant code is shown below:

``` cpp
    std::cout << "cycle: " << simcyc;
    if (simcyc == 0) {alu->aluop1 = 1; alu->regop2 = 1; alu->alusrc = 0;} // 2
    if (simcyc == 1) {alu->aluctrl = 8; alu->aluop1 = 1; alu->regop2 = -1; alu->alusrc = 0;} // 2
    if (simcyc == 2) {alu->aluctrl = 1; alu->aluop1 = 1; alu->regop2 = 1; alu->alusrc = 0;} // 2
    if (simcyc == 3) {alu->aluctrl = 2; alu->aluop1 = 1; alu->regop2 = 1; alu->alusrc = 1;} // 1 > 0, false return 0  
    if (simcyc == 4) {alu->aluctrl = 3; alu->aluop1 = 1; alu->regop2 = -1; alu->alusrc = 0;} //return 1 (1 < fff)
    if (simcyc == 5) {alu->aluctrl = 4; alu->aluop1 = 1; alu->regop2 = 1; alu->alusrc = 0;} // 0
    if (simcyc == 6) {alu->aluctrl = 5; alu->aluop1 = 2; alu->regop2 = 1; alu->alusrc = 0;} // 1
    if (simcyc == 7) {alu->aluctrl = 13; alu->aluop1 = -2; alu->regop2 = 1; alu->alusrc = 0;} // -1  
    if (simcyc == 8) {alu->aluctrl = 6; alu->aluop1 = 1; alu->regop2 = 0; alu->alusrc = 0;} // 1
    if (simcyc == 9) {alu->aluctrl = 7; alu->aluop1 = 1; alu->regop2 = 0; alu->alusrc = 0;} // 0
```

The expected output is commented to the side of the code.

Initially the output was incorrect because, `eq` was incorrectly set due to mistype in the combinational logic of branch (See line 41, [commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/c07bdf2bf7064690c91ec2e7478983f44b769413))

However more importantly, I found that I misunderstood the `<` operator in system Verilog. Initially I thought the operator would naturally compare signed values. Thus it understood `0xfffffff = -1`. That is not the case in system Verilog. The operator will treat the values as unsigned at all times. After some research I found that I could typecast using `signed'()` to inform system Verilog to treat the value as a signed number. Lastly, I found that arithmetic shift right was preforming a logical shift right. This was also fixed using the `signed'()` typecast. See [commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/c07bdf2bf7064690c91ec2e7478983f44b769413).

Note that the srai only shifts `aluop1` by the bottom 5 bits of aluop2. This was changed in the same [commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/c07bdf2bf7064690c91ec2e7478983f44b769413) linked above, however was not changed for srli until it was noticed as a bug [later](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/b7b38948d396d2d0f0669f5431219fad9915f1b3).

The final alu does output the correct values as shown below:

![Aluresult](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/aluresult.png)
Thus verifying that the alu is indeed working correctly.

## Creating the top level module
After all the modules were created, I took the task of assembling the whole CPU together. This was done during one of the lab sessions hence some people are co-authored in the commits. See branch [test](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/tree/test).

The wiring is mainly straight forward and follows the diagram from lecture 6. (Link below)

[Cpu diagram From Slides](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/cpulecture6.png)

The diagram is missing 3 key multiplexers needed for the implementation of Upper and jump instructions. These are shown below.
![NewCpuDiagram](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/implementedcpu.png)

The first multiplexer is has the select input `addupper` and was added by Yazan. (See his [readme](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Yazan_README.md))

The second multiplexor is used to implement jump instructions. `pcwritemux` controls the result being written to the register file. This will assign result to the signal
`PCplus4` when the a jump instruction is being executed. (Hence preforming the operation `rd = pc + 4`).  

The last multiplexor `jbmux` is used to assign the correct pctarget to the instruction memory. This is needed for `jalr` since the target jump address is not relative to the current program counter in a `jalr` instruction (See [lecture 6](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/lect6slide64.PNG)). Thus it needs to be assigned to `rs1 + signExt(Imm)`, which is the output of the alu.  

Initially to test the CPU, we did not have a complete thorough program. Instead we used 3 programs, each test a specific section of the CPU.

Note that the expected output is commented inside each program. The program assembly has been hyperlinked to each test.  

([upper.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/RISC-V-Single-Cycle/programs/upperimm.s)) This was tested by Yazan Ayyoub, see his personal [Yazan](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Yazan_README.md).

([memoryprog.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/RISC-V-Single-Cycle/programs/memoryprog.s))
This was tested on jie's [README](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Jie's%20Personal%20Statement.md).

<!-- Output:
![img1](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/memoryprog1.png)

![img2](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image//memoryprog2.png) -->

The reference program is a code that is a combination of unit tests. It was created by myself and [Yazan](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Yazan_README.md) in order to test all of our branch instructions, some of the memory instructions and some alu instructions.

The section (lines 1 to 14) test that our branch instructions do not branch when they are not supposed to. The next section tests is copied from the memoryprog. The final section (lines 33 to 61) ensures hat our branches branch correctly. This is done by constantly skipping over the instruction addi a4, zero, 99. This allowed us to check that the branch test passed simply by looking at the value of a4 at the end of the program.

This program was our initial attempt to create a program to test most/all instructions in the cpu. It was later used to develop the whole.s program.
The Output of the [reference_program](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/RISC-V-Single-Cycle/programs/reference.s)
is shown below:

<div>
  <img src="https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/reference1.png" width = "800px" />
  <br/><br/>
</div>

<div>
  <img src="https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/reference2.png" width = "800px" />
  <br/><br/>
</div>

<div>
  <img src="https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/reference1.png" width = "800px" />
  <br/><br/>
</div>

The [whole.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/RISC-V-Single-Cycle/programs/whole.s). (his was tested by Yi, see his personal [Yi](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Yi%20Zhang's%20Personal%20Statement.md))

By combining all three tests into one [whole.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/RISC-V-Single-Cycle/programs/whole.s) I was able to use some registers as flags to immediately verify if the instructions tested are working.  

s4: 0 --> 1 indicates that Upper passed <br/>

s5: 0 --> 1 indicates that No-branch test passed <br/>

s7: 0 --> 1 Inidcates that the branch test passed <br/>

Note that the memory test does not pass automatically. In order to verify that the memory was working, the user must look at the values in a0 up to a6 and check that they match the expected values. The test will wait (By jumping in its place) until the user verifies that the tests has passed. If the values are correct, the user can press trigger to move onto the next test, otherwise we can terminate the program by pressing `ctrl+c`.


The alu is not tested through the whole program, it was tested separately using `alu.test` ([alu.test](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Single-Cycle-Cpu/RISC-V-Single-Cycle/programs/alu.s)). I found that testing the CPU on the fly using trigger as done for memory was difficult since I would need to display more registers. Instead, I separated the ALU test and ran it on a separate program. Similar to the memory test, the program will load values into registers s4 to s7 and a0 to a6 and its up to the user to check that the values loaded are correct.


## Creating execute Block
After the single cycle CPU was completed, we decided to split the work for pipelining the CPU according to stages. I was assigned the execute stage.  
The execute stage does not have modules other than the alu, hence I created a sub-top module `execute.sv` and instantiated the alu inside it.  
The key idea in the execute module was the addition of all the jump logic into it. Originally `pcsrc` was determined by the control unit. However, as shown in [lecture 8](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/lecture8diagram.png), this is not the case in a pipelined CPU.

In order to implement these changes, Yazan and I agreed on how to move the logic from the control unit to the execute block. This involved identifying which signals needed propagate to the execute stage. Further more, I organized a meeting with Yi (Who was wiring the CPU) explaining this change and a meeting with Jie (Who was working on the fetch stage) to inform him which multiplexers will be moved to the execute phase and how this will effect the fetch module.  

These changes are shown in on the [execute](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/af2348619291a7808cdae863558feac66d8c8ac4) branch.

In order to replicate this method of testing. It is advised to run the program until termination (Usually done by jumping to the same place, hence the Program counter stops changing). Then terminating the process run on terminal `ctrl + c` to stop printing. The user can then freely analyse he signals.

## Creating the make.sh script
In order to make it easier for users to run programs on both cores, I created a shell script that compiles `.s` files and runs them on the Vbuddy immediately. This took heavy inspiration from the [Makefile](https://github.com/EIE2-IAC-Labs/Project_Brief/blob/main/src/Makefile) in the project brief. Most of the commands are copied straight from he [Makefile](https://github.com/EIE2-IAC-Labs/Project_Brief/blob/main/src/Makefile), However the key additions are:

1. The use of `sed -i "s/\$readmemh(.*/$replacement/" ./RTL/instrmem.sv`. This is used to replace the file being read inside the instruction memory module with the new `.hex` that as created.

2. The use of `./init.sh` to immediately run the program on the vbuddy.

Note that this was done with significant help from [Shuyuan Liu](https://github.com/shuyuan-liu).
## Reflection

I was generally satisfied with how the team worked. I think we all communicated effectively and conveyed our messages to each other quickly. I do not have any complaints from that regard and would be happy to work with this same team in the future. Most of the coordination was done by myself, however I hope that the team was satisfied with my actions. If I was to repeat the project I would have loved to have more time to implement more features into the CPU.
