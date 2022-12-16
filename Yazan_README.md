# **Yazan Ayyoub README 02120810**

 As we delegated tasks, I took responsibility of making the control unit, upper immediate instructions, and eventually the decode stage of the pipelined CPU. I also worked on cleaning up the processor and testing the F1 program. 

 For your information, I do not show as a contributor on the repo. That is because I made my commits with a [generic email](./iac%20ss%20yazan%20/generic%20email.png) that is not shared with my account. My contributions do show, but are not linked to my account. A rookie mistake I learned from.

# 1 Final Control Unit Implementation

## 1.1 General

The base control unit had many case statements which I didn’t find ideal. [Find base control unit here.](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/21955df0744b9a0c4724f46077c0f6ace53c8808)

I felt that some of the control signals could be determined separately in one always comb block using gates. Some signals were implemented in case statements because their gate implementation was lengthy. Upon doing that, the control unit looked less packed, and cleaner.

Instead of developing two modules, one for the main decoder, and another for ALU decoding, then needing to combine the two, I put both decoders in one module, using two always comb blocks.

[Find final control unit here (single cycle)](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Single-Cycle-Cpu/RISC-V-Single-Cycle/RTL/controlunit.sv)
</br>

[Find final control unit here (pipelined)](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/RTL/controlunit.sv)

-------
## 1.2 Control signal implementation

To be convenient and clear, I renamed opcodes as follows
```
  logic rg = opcode == 51;
  logic imm = opcode == 19;
  logic load = opcode == 3;
  logic store = opcode == 35;
  logic branch = opcode == 99;
  logic ldupper = opcode == 55;
  logic aupper = opcode == 23;
  logic jalr = opcode == 103; 
  logic jal = opcode == 111;
```
------
### 1.2.1 Main decoder
------

**1. Signals that depend on opcode only**

| Opcode | regwrite | alusrc | memwrite | resultsrc | jbmux | pcwritemux | addupper | immsrc[2:0] |
|--------|---------|---------|----------|-----------|------|------------|----------|--------|
|51 (rg) | 1 | 0 | 0 | 0 | 0 | 0 | 0 | XXX |
|19 (imm) | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 000 |
|3 (load) | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 000 |
|35 (store) | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 010 |
|99 (branch) | 0 | 0 | 0  | 0 | 0 | 0 | 0 | 011 |
|55 (ldupper) | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 001 |
|23 (aupper) | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 001 |
|103 (jalr) | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 100 |
|111 (jal) | 1 | 0 | 0 | 0 | 0 | 1 | 0 | 100 |

I set immsrc to 3 bits rather than 2 bits. Reason being that there were not enough bits to cover all 5 immediate variations : store, (imm, load), (ldupper, aupper), (jalr, jal), and branch.

**- New signals**

1. `jbmux = jalr = opcode == 103;`

jbmux is the select of the [jump multiplexer](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Omar_Alkhatib_Personal_Statement.md) used for the JALR instruction. The multiplexer is needed because JALR is not realtive to PC. It sets PC = regop1 + imm, which is the output of the ALU.

2. `pcwritemux = jalr | jal = opcode == 103 | opcode == 111;`

Pcwritemux signal selects which data to write the registers with. Either PC + 4 for either jump instruction, or result.

3. `addupper = aupper = opcode == 23;`

Addupper is a control signal such that, when 0, aluop1 equals regop1, and when 1, aluop1 is PC. Therefore, it only checks for an add upper immediate instruction. Upper immediate implementation will be discussed later as I was the one who implemented it.

**2. pcsrc Implementation**

``` 
case(opcode)
      99: pcsrc = eq ? (funct3 == 1 | funct3 == 4 | funct3 == 6) : (funct3 == 0 | funct3 == 5 | funct3 == 7);
      103: pcsrc = 1;
      111: pcsrc = 1;
    default: pcsrc = 0;
    endcase
```
Since jumps are unconditional, pcsrc is 1 for any jump instruction. However, branches are conditional and since EQ (zero flag) goes back into the control unit, we can check if a condition has been met depending on funct3 and its respective EQ value. If so, the branch will occur as pcsrc will be set to 1.
_____
### 1.2.2 ALU decoder 
_____

| Intsurction | Respective ALUop [1:0] |
| ----------- | -----------------------|
| Branch | 01 |
| Rg or Imm | 10 |
| Load Upper | 11 |
| Otherwise (Load/Store/Add Upper/JALR)| 00|  

`wire [1:0] aluop = {(rg | imm | ldupper), (ldupper | branch)};`

Aluop is used to decode for aluctrl. In some cases, aluctrl would only depend on aluop, but in others like branch and reg/imm, it also depends on fucnt3 and funct7, each case is shown below.

1. If aluop == 00, aluctrl = 0000

This is for any instruction which requires adding in the ALU. 

2. If aluop == 01, aluctrl = `{1'b0, !funct3[2], funct3[2], funct3[1]};`

In this case, I coordianted with Omar the ALU operations we wanted to run to test conditions for specific branch instructions. 

Instead of using case statements ([which is what I have initially done](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/fb0cc745cba002d63521529853805f94dbd98f61)), I found an elegant way of finding aluctrl depending on the funct3 value using concatenation.

| Branch (funct3)| ALU operation (aluctrl)| Why?|
|----------------|------------------------|-----|
| beq (000)  | xor (0100)             | xor is great for checking equality, aluout is 0 if equal, greater than 0 if not equal.
| bne (001)    | xor (0100)             | Same as above
| blt (100)   | slt  (0010)             |slt is used to check if aluop1 is less than aluop2, aluout is 1 if less, 0 otherwise.
| bge (101)    | slt (0010)             | Same as above
| bltu (110)   | sltu (0011)            | sltu checks if unsigned aluop1 is less than unsigned aluop2, aluout is 1 if less, 0 otherwise.
| bgeu (111)  | sltu (0011)            | Same as above
 
The following shows the approach I have taken if aluop == 01.

- aluctrl[3] is always 1'b0. This can be seen. [Karnaugh map](./iac%20ss%20yazan%20/aluctrl%5B3%5D.jpg)
- aluctrl[2] is only 1 when BEQ or BNE. What differentiates those branches from all others is func3[2] which is 0 for BEQ and BNE and 1 for the rest. [Karnaugh map](./iac%20ss%20yazan%20/aluctrl%5B2%5D.jpg)
- aluctrl[1] is only 1 when the branch is not a BEQ or BNE, which means either SLT or SLTU. So funct3[2] is used again. [Karnaugh map](./iac%20ss%20yazan%20/aluctrl%5B1%5D.jpg)
- Lastly, aluctrl [0] should only be 1 for an SLTU branch (BLTU, BGEU). What differentiates those from the rest is funct3[1]. It is 1 for BLTU and BGEU and 0 otherwise. [Karnaugh map](./iac%20ss%20yazan%20/aluctrl%5B0%5D.jpg)

3. If aluop == 10, aluctrl = `{funct7 & ((imm & funct3 == 3'h5) | (rg  & (funct3 == 3'h5 | funct3 == 3'h0))), funct3}; `

Omar and I decided to concatonate funct7 and funct3, depending on funct3, if a Rg or Imm instruction is called.

Aluctrl checks to see if funct3 equals 000 or 101 for Rg instructions. If so, funct7 is concatenated with funct3 to form aluctrl. The same happens for Imm instructions, but it only checks if funct3 is equal to 101.

4. If aluop == 11, aluctrl = `1111 (15)`

For load upper immediate instructions, aluop was set to 11. This sets aluctrl to 1111, which is a [new ALU operation](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/92216f2bf91c8612541c05464feb8a5d01cae838) added for load upper immediate instructions. This will be explained in the upper immediate section.

------
## 1.3 Process of developing control unit (single cycle)

1. [Updated base control unit, removing case statements, and shortening logic](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/fb0cc745cba002d63521529853805f94dbd98f61)

2. [Fixed implementation of aluop. Also fixed and simplified aluctrl implementation](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/db3bf914b7baa3dce9d947512ea7b6fc2002f00f). Integrated rg and imm instructions into one aluop value. I also fixed an error in the aluctrl case statement for aluop = 01, where default could never be met due to lack of bits.

3. [Removed addrmode redundancy in control unit, and top level module](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/284538969d34b405d41465eae0ee01d6db74958d). addrmode was equal to funct3 and was passed to the memory in the top level. Instead, I passed funct3 directly.

4. [Added necessary upper immediate signals to control unit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/7d80178122fab5d2e2c336d1fcdfaa0f4a0e5f3d)

5. [Made final simplifications and clarifications in control unit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/8e67cd2ff5da8024d235ddb599a54dcf5066b3be). Renamed opcodes, simplified logic, made control unit more readable.

------
## 1.4 Testing the control unit

To test the control unit, I tested the programs we have built. I used a display statment when the output is incorrrect to see what each signal is set to with each instruction.

The display statement (please refer to [Omar's statement](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Omar_Alkhatib_Personal_Statement.md)) I used to debug is as follows

``` 
 always_ff @(posedge clk) begin
    $display("eq: %h", eq, " regwrite: %h", regwrite, " aluctrl: %b", aluctrl, " alusrc: %h", alusrc, " pcsrc: %h", pcsrc, " aluop: %b", aluop, "\n");
  end
```

The display statement needs to be clocked to see the changes sequentially.

I tested memory related signals with [memory.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/cleanup/RISC-V-Single-Cycle/programs/memoryprog.assembly), and alu related signals with [alu.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Single-Cycle-Cpu/RISC-V-Single-Cycle/programs/alu.s). To test branch related signals, I built a [reference program](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/decode/RISC-V-Single-Cycle/programs/reference.s) with [Omar](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Omar_Alkhatib_Personal_Statement.md) which tests each branch instruction, as well as some alu and memory instructions. When we reached the end, the tests were merged, along with the upper imm test I made, into one called [whole.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Single-Cycle-Cpu/RISC-V-Single-Cycle/programs/whole.s) (tested by [Yi](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Yi%20Zhang's%20Personal%20Statement.md)). 

# 2 Decode Block Implementation (For Pipelining)

## 2.1 Necessary changes

To implement the decode stage, I worked on a branch called decode. 

In the decode branch, I changed the register file so that it writes on a negative clock edge.

I also removed pcsrc and eq from the control unit as those would be determined in the execute stage.

Lastly, I built a top level module with signals/wires represented as `signal_nameD`. I instantiated the new control unit, register file, and sign extender unit (immediate formatter). I then connected the relevent wires together to form the [decode top level](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Pipelined-Cpu/RISC-V-Pipelined/RTL/decode.sv) block of the pipelined CPU.
# 3 Upper Immediate Implementation

## 3.1 Load upper

An issue I faced was that, to write a register, the data must pass through the ALU.

I saw two solutions to this:

1. [Bypass the ALU using a MUX](./iac%20ss%20yazan%20/solution1.jpg) with one input being result (either aluout or ramout or PC+4), and the other immop. The output would be a wire going to wd. This would allow for immop (upper immediate) to be directly written into the registers, bypassing the ALU, if a lui is called.

2. [Making a new ALU operation](./iac%20ss%20yazan%20/solution2.jpeg) (buffer) in which aluop2 is passed as the output. This allows immop (upp imm) to travel through the ALU, to then be written into the registers. So no bypassing happens in this case.

I chose solution 2 because it outweighs solution 1 in pipelining. If solution 1 was picked, nops would have to be added to the program and the MUX would need its output to travel through the stages.

In solution 2, a load upper instruction runs like an ALU instruction and that minimizes nop usage and functionality errors. Also, new control signals are not needed.

Aluctrl was set to be 1111 and aluop = 11 in the case of load upper immediate such that

If aluop == 11, `aluctrl == 1111`;

If aluctrl == 1111, `aluout = aluop2;`

-----
## 3.2 Add upper

To implement add upper, [a new multiplexer was required](./iac%20ss%20yazan%20/addupper.jpeg). I placed it between the ALU and regop1. It takes the current PC value and regop1 as inputs. The output was added in the top-level module as interm_rfpc and is wired to aluop1.

A new select from control was needed and called addupper, which sets the MUX's output to PC when 1. By doing that, aluop1 can equal PC and an upper immediate can be added from aluop2. Aluctrl is equal to 0000 in this case.

------
## 3.3 Control signals for upper immediate instructions


|Control Signal| Add Upper | Load Upper |
|--------------|-----------|------------|
|regwrite| 1 | 1 |
|alusrc| 1 |  1 |
|aluop [1:0]| 00| 11 |
|aluctrl[3:0]| 0000 (add) | 1111 (aluout = aluop2)|
|memwrite| 0 | 0 |
|resultsrc| 0| 0|
|jbmux|0| 0|
|pcwritemux| 0 | 0 |
|pcsrc| 0| 0 |
|immsrc [2:0] | 001 | 001|
|addupper| 1 | 0 |

----
## 3.4 Process of developing upper immediate instructions


1. [Implemented new ALU instruction for Load Upp Imm](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/92216f2bf91c8612541c05464feb8a5d01cae838)
2. [Implemented new control changes](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/7d80178122fab5d2e2c336d1fcdfaa0f4a0e5f3d)
3. [Added relevant MUX in top-level, set its output to aluop1](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/556b719992640cf71c76940e1601c0e3f8cf126a)
4. [Tested Upper Immediate instructions using a simple program called upperimm.assebly](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/a3848533ea8df6e73beacad28f26c1eb3b77b141)

------
## 3.5 Testing upper immediate


The following program was tested
```
  ....TEST FOR LOAD UPPER IMM......
lui a1, 0xfffff     a1 = fffff000
lui a2, 0x12345     a2 = 12345000

......TEST FOR ADD UPPER IMM......
auipc a3, 0x00000   a3 = 00000008
auipc a4, 0xff000   a4 = ff00000c
```
The following was the output

![upper imm test](./iac%20ss%20yazan%20/upperimmtest.png)

To see the outputs of this test, I used the display method in system verilog.

`$display(" a0:%h \t", a0 ," a1: %h\t", rf_array[11], " a2: %h\t", rf_array[12], "a3: %h\t", rf_array[13], "a4: %h\t", rf_array[14]);`

Please see [Omars](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Omar_Alkhatib_Personal_Statement.md) personal statement for more information about display statements.

# 4 Reflection

- I am very happy with the team I worked with, and would have no problem working with them again. I felt that we planned and communicated effectively.

- Learning an HDL will be helpful in the future. I can see myself using System Verilog to simulate any digital/hardware design, considering that I found it relatively easy to work with.

- I felt that this project developed my approach to constructing logic in digital systems. I feel stronger in breaking down a problem to find a logical solution, expecially because I made the control unit.

- Learning the command line: I see myself always using the command line, even after completing the CPU, due to its convenience and simplicity.

- Learning how to use Git/GitHub: I found Git to be very convenient for group work as it allows members to work in sync. I see myself using it in the future, even for personal projects.

--------
## 4.1 What I would do differently

- I would try not to overload the repository with branches unless necessary. This didn't affect us as much, but did cause confusion at times.

- I would not implement upper immediate instructions in the cleanup branch because that has caused some confusion. I should have made a new branch which is conventially more suitable.

- I would try to minimize the amount of [unnecessary comments](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/4724db8d71daf9d79114a76b3db90f10f4f8bf80) I make in code. This makes everything look cleaner.

- I overused Git on the terminal: I would make all my changes, big or small, locally, then `add`, `commit`, `push`. I should have utilized the GitHub interface for minor changes as that would have been easier and quicker.

- Lastly, I would add more to the CPU, an example would be data cache.
 

