**Summary**
===============
During this project, I am responsible for writing instruction program and assembly code for both based RISC-V and pipeline one, fetch top file for pipeline and test PDF/memory program given by the professor. I learned how to apply different instructions such as jal, jalr, li. Moreover, i understood how to allocate register for different kind of instruction and how to add NOPs to prevent data hazard. Learning from my group members, I learn to use git hub, e.g how to use branches. Most importantly, I got an idea of how to reach a collaboration between hardware system verilog and software assembly code, and how to turn real life question like f1 lighting problem into software assembly code which pushed processor to execute.

**F1 program**
===============
*Mistakes I make*
---
[first version](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/b729439c5efaafb7403d7246b0daee35be9df5a9)       
[second version](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/3e5111693d40770459a0d84224b31ceccd3720a9)    
[final version](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/2a080f7dbeb930370d448e8442b5645e9184811e)


When I was designing F1 program, i had made several mistakes and made a number of changes to make the code better. 

<li>I made the LFSR random number generation loop running only one time during each f1 lighting process for the first time. Communicating with Omar, i realized that if it runs only one time each process, the racers will estimate what is the next delay time which is not fair for a game. I changed it before the trigger branch so that it will continuously run before trigger being one.</li>

<li>For the LFSR, I ignore the fact that we only need 4 bits of LFSR which is automatically generated to 32 bits, adding an ANDI 4 instruction to keep the only last four bits.</li>

<li>I allocated only one register for the lighting output a0 through the shift 1 and add 1 instruction first time. Obviously, this will make the lowest light not lighting after the first left side shift 1 instruction. Then, i add another register t1 to store the first left side shift a0 then return back to a0 after addi 1 instruction. Therefore, when the next time a0 changes, all lights light up together instead of the upper lights light up firstly. One reflection i got is to be careful with small difference.</li>

<li>I only set the a0 output to 0 in the final of the second version which will creats failure when jumping to LFSR again to run the second time. I should set changing values to 0 so that they can be used again for the next running, or the value the program use the second time is the generated value of the first running.</li>

<li>I use only base instruction for first version; however using pseudoinstrucion makes the program look more simple. Reviewing lecture slide 6 page 29. Then, I update some base instruction into pseudoinstruction that is more simplified. Also realizing that x0 register always has value of 0, I don’t have to set a initialized value of 0. Moreover, whenever I do not want to store pc address for JALR instruction, I can store it in x0 which acts like not storing since register x0 will always be 0.</li>

*Pseudoinstruction I use:*
---

| base instruction | pseudoinstruction |
| ----------- | ----------- |
| jalr x0(zero), 0(x1) | ret |
| jal x0, offset | j offset |
| jal x1, offset | jal offset |
| beq rs, x0, offset | beqz rs, offset |
| bne rs, x0, offset | bnez rs, offset |
| addi  rd, zero, imm12 | li rd, imm12 |


*Instruction list:*   
--- 
|list|
| ----- | 
| Addi rd, rs, 0 |
| Add  rd, rs1, rs2 |
| Slli  rd, rs1, shamt |
| Srli  rd, rs1, shamt |
| Andi  rd, rs1, imm12 |
| Xor  rd, rs1, rs2 |
| li rd, imm12 |
| Bne  rs1, rs2, imm12 |
| Bnez  rs1, offset |
| Beqz  rs1, offset |
| Jal  offset |
| J offset |
| Ret |

*[Single-cycled f1 program](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/2a080f7dbeb930370d448e8442b5645e9184811e) description*
---

The single-cycle F1 program is carry out in following steps:

1. It firstly initialized value needed through whole program by using Li instruction.

2. It has a LFSR loop to rolling and generating the random number for delaying with polynomial 1 + $x^3$ + $x^4$  until the trigger, which is stored in the x9 register in hardware, equals to 1(a beqz branch). I apply ANDI to extract the x3 and x4 and shift both them to the right most. Then, using XOR to get the final bits for new LFSR number and add it to the one which has shifted previous IFSR number left by 1 bit, giving out the final IFSR number. The trigger will goes to 1 each time the user press the button as Omar set the vbdSetMode to 1.

3. Then, it goes to light up the light and it will jump to the only subroutine “counter” to run 15 cycles to count approximately 1 second each time. The LIGHTING loop runs until a0 output equals to 255(s3), which means all eight lights are lit.

4. After all lights are on, the delay loop starts that it will run the “counter” t0 times, which is the random number  generated in LFSR loop. It keeps branching to delay loop until a4 equals to t0.

5. Finally, it sets output a0, trigger s1, and counter a4 in delay loop to 0 as those three values are changing when running this time but should be 0 next time running the F1 program. Then it jumps without conditions to the LFSR loop and wait for next time the trigger equals to 1.

While testing, lights light up sequentially after triggered and close after a random time.

*[Pipelined f1 program.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/c36f099e80862f1d37aeb35fbb8289a7ac0aaccd) / [Pipelined f1 program.hex](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/c9d345aec947b4e34a7931bd814e76b62fe8d42d) description*
---

For the F1 program of pipeline, we design it to have only NOP for data hazard. Yi design the [top file cpu_pipelined](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/6784647e81bda93975e9b77a5be15296729e5d90), [yi's personal statement](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Yi%20Zhang's%20Personal%20Statement.md) to check whether PCSRC equals to one, which representing that a jump or branch instruction is executed, and reset value in register. Therefore, NOP for control hazard is redundant. Whenever there is a afterward rs(input) register uses a rd(output) register in previsousIn regard to other parts, they are the same to the single-cycle F1 program logic. While testing, the lights light up as the single cycle one.

**[Fetch file](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/7ba581c5911c501cff88eaf138a18b861f359f99)**
===============

After finishing single-cycled one, I was responsible for making the fetch file for pipelined CPU. The fetch file is combining PCOUNTUNIT and INSTRMEM to make a top file. After informed by Omar that the JBMUX module is moved from PCOUNTUNIT to EXECUTE.sv which is created by OMAR (see [Omar’s personal statement](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Omar_Alkhatib_Personal_Statement.md) creating execute block part), so it directly choose which address jump instruction outputs, JAL or JALR.  Since the fetch top file is just combining what we have already together, I could replace PCOUNTUNIT and INSTRMEM with new fetch.sv in the CPU single-cycled top file to test it and it works well without bugs.

**Test the PDF file** 
===============
[single cycle PDF testing videos](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/tree/main/test%20for%20cpu/singlecyled%20PDF%20reference%20test)

[pipelined PDF testing videos](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/tree/main/test%20for%20cpu/pipelined%20PDF%20reference%20test)

In order to compare whether our results are the same to the The PDF program test results is what we expect, I searched for expected graph for sine, triangle, gaussian and noisy sine PDF. The test graph is generated on vbuddy by <code>vbdBar(cpu->a0_output)</code>.


|![expected graph for sine](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/expected%20pdf%20images/sine%20PDF%20graph.jpeg) | ![single cycle graph on vbuddy for sine](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/tested%20images%20for%20single%20cycle%20pdf/sine%20pdf.jpeg) | pipelined ![graph on vbuddy for sine](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/tested%20images%20for%20pipelined%20pdf/sine%20pdf.jpeg) |

If the graph for generated sine wave is not clear, there is highlighted ones. |[single cycle pdf highlighted graph](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/pdf%20images%20with%20highlight/single%20cycle%20sine%20pdf.jpeg) |[pipelined pdf highlighted graph](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/pdf%20images%20with%20highlight/pipelined%20sine%20pdf.jpeg) |
Obviously, both single cycle and pipelined pdf gragh has a shape of valley, matching to the expected graph online. 



![expected graph for triangle](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/expected%20pdf%20images/triangle%20PDF%20graph.jpeg)
single cycle![graph on vbuddy for triangle](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/tested%20images%20for%20single%20cycle%20pdf/triangle%20pdf.jpeg) 
pipelined![graph on vbuddy for triangle](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/tested%20images%20for%20pipelined%20pdf/triangle%20pdf.jpeg) 

If the graph for generated triangle wave is not clear, there is highlighted ones. [single cycle pdf highlighted graph](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/pdf%20images%20with%20highlight/single%20cycle%20triangle%20pdf.jpeg) [pipelined pdf highlighted graph](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/pdf%20images%20with%20highlight/pipelined%20triangle%20pdf.jpeg) Obviously, both single cycle and pipelined pdf gragh generate a triangular wave, matching to the expected graph online.




![expected graph for gaussian](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/expected%20pdf%20images/gaussian%20PDF%20graph.jpeg)
single cycle![graph on vbuddy for gaussian](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/tested%20images%20for%20single%20cycle%20pdf/gaussian%20pdf.jpeg) 
pipelined![graph on vbuddy for gaussian](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/tested%20images%20for%20pipelined%20pdf/gaussian%20pdf.jpeg) 

Obviously, both single cycle and pipelined pdf gragh has a shape of a mountain, matching to the expected graph online.




![expected graph for noisy sine](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/expected%20pdf%20images/noisy%20sine%20PDF%20graph.jpeg) 
single cycle![graph on vbuddy for noisy sine](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/tested%20images%20for%20single%20cycle%20pdf/noisy%20pdf.jpeg)
pipelined![graph on vbuddy for noisy sine](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/image/tested%20images%20for%20pipelined%20pdf/noisy%20sine%20pdf.jpeg)

Obviously, both single cycle and pipelined pdf gragh has a shape of valley with lot of fluctuations because of noise, matching to the expected graph online.


**Improve if do it again**
===============

If I were to design the program again, I will make the IFSR loop free to load in any kind of random number polynomial. As it is now designed to be 1 + $x^3$ + $x^4$ , the new instruction program can execute other pseudo random binary sequence and generate other sequence of time of delay to suit different requirements of users. Assumably, it will make the registers act like parameters. Also, I wish to lean more about how to implement cache next time.

**Reflection**
===============

Thanks to Omar, Yazan and Yi, I learned a lot from them not only on knowledge of CPU and using git hub, but also on how to communicate with others. Omar’s organization plays a big role in team collaboration. It is the best team I have met and I am excited to cooperate with them again next time. Being responsible for different tasks also allows me to learn different stuff.
