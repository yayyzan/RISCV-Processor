# README Team 30

## Contribution Table

|                                                             |                       Single Cycle CPU                       |           Organizing  and Testing Single Cycle CPU           |                        Pipelined CPU                         |     Organizing and Verifying Single Cycle/Pipelined CPU      |
| :---------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
|                        Timeline/Hash                        | [21955df](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/21955df0744b9a0c4724f46077c0f6ace53c8808) -> [8919291](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/89192910a1afa450296f68368f86ad30b38684b8) | [a3c7d04](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/a3c7d04a35839a5ee8bb1fb5dfcc6f963e1f2ee7) -> [2a080f7](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/2a080f7dbeb930370d448e8442b5645e9184811e) | [61206de](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/61206deee06dc28fb537f1757ab7d1d56d22d560) -> [79d68bd]() | [420b215](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/420b215d528a5c794136f1f35410769d56073832) -> [8e67cd2](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/commit/8e67cd2ff5da8024d235ddb599a54dcf5066b3be) |
| Omar Alkhatib ([SsagatroNN](https://github.com/SsagatroNN)) |                             Alu                              |                             Top                              |                           Execute                            |                   Create Whole/Alu Program                   |
|  Yi Zhang ([Yi-Zhang-IC](https://github.com/Yi-Zhang-IC))   |                         Data Memory                          |                         Data Memory                          |                             Top                              |                    Test Whole/Alu Program                    |
|   Jie Chen ([3136321049](https://github.com/3136321049))    |                Program Counter and F1 program                |                           F1 program                        |                            Fetch                             |                   Test Memory/PDF Program                    |
|    Yazan Ayyoub ([yayyzan](https://github.com/yayyzan))     |                         Control Unit                         |                         Control Unit                         |                            Decode                            |                       Test F1 Program                        |

## Contribution Table by branches

|Branch | Omar Alkhatib | Yi Zhang | Jie Chen | Yazan Ayyoub|
|-------|---------------|----------|----------|-------------|
|Pipelined-Cpu|x|x|x|x|
|Single-Cycle-Cpu|x|x|x|x|
|singlecycle_pdf_test| | |*|
|pipeline_pdf_test| | | *|
|verifying_pipeline|x| *|
|single_cycle_alu_test|x| *|
|pipeline_alu_test| x| *
|pipelinetest| x| *|
|execute| *| ||x|
|decode| | ||*|
|fetch| | |*| 
|test| *| x| | x|
|program-instruction| | |*|
|cleanup| x| ||*|
|alu| *| |
|controlunit| |||*|
|memory| | *|


## Description of CPU and Achievement
You will find in the repository our final single-cycle CPU in the [Single-Cycle-Cpu](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/tree/Single-Cycle-Cpu) branch. You can find our final pipelined CPU in the [Pipelined-Cpu](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/tree/Pipelined-Cpu) branch. Our tests and verification process can be found on the main branch.

Our approach as a team was to split each stage into features. Each feature is assigned a branch where the person delegated that feature can work as they wish. Upon completion, we decided that a meeting should be set to merge that branch into another relevant branch. If unavailable to meet, we, conventionally, make a pull request for other team members to view the changes.

Adding to the base processor called for efficient communication between team members. Upon meeting multiple times, the team has reached a consensus with regards to how every instruction would be implemented. This allowed for a standard which the team had to meet when implementing anything in the CPU, limiting clashes and future issues. This indeed worked for us.

Thanks to Git and GitHub, we managed to share our work, fix others work, and plan effectively, allowing us to build the CPU in a coordinated, and effective manner.

Throughout our work you will find unique contributions from all team members. A general simplification is shown in the following.

- Load and Store implementation in memory required the addition of new modules to create a top level memory module. This is better explained in [Yi's personal statement](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Yi%20Zhang's%20Personal%20Statement.md).

- Our J-type instruction implementation, which was completed by [Yazan (control)]() and [Omar (top)](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Omar_Alkhatib_Personal_Statement.md), required the addition of two multiplexers and control signals.

- The implementation of branch instructions required changes in control signals as well as ALU operation. Please see [Omars's personal statment](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Omar_Alkhatib_Personal_Statement.md) for ALU implementation, and [Yazan's personal statement]() for changes in control unit.

- The implementation of the F1 program required a unique approach of subroutines and jumps/branches which is further explained in [Jie's personal statement](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Jie's%20Personal%20Statement.md).

- The implementation of upper immediate instructions required the addition of a new multiplexer and alu operation. Upper immediate was done by [Yazan]().

- Testing our CPU was made easier by using `$display` statements in specific modules. These were implemented by [Omar](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Omar_Alkhatib_Personal_Statement.md).

- The addition of nops to all test programs made, as well as reference programs, completed by [Jie](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Jie's%20Personal%20Statement.md).

- The final verification process required a more complete and exhaustive implementation. This was completed by [Yi](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Yi%20Zhang's%20Personal%20Statement.md) and [Jie](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Jie's%20Personal%20Statement.md).

- The Addition of a make shell script to run our tests and use the cpu's for your own programs with ease. ([Omar Al-khatib](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Omar_Alkhatib_Personal_Statement.md)).

As we built the CPU, test programs were made: [memory.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/cleanup/RISC-V-Single-Cycle/programs/memoryprog.assembly)(tested and explained by [Jie](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Jie's%20Personal%20Statement.md)), [alu.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Single-Cycle-Cpu/RISC-V-Single-Cycle/programs/alu.s)(tested and verified by [Yi](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Yi%20Zhang's%20Personal%20Statement.md)), [counter.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Single-Cycle-Cpu/RISC-V-Single-Cycle/programs/counter.s)(Results shown in [test for cpu](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/tree/main/test%20for%20cpu/countertests)), [reference.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/RISC-V-Single-Cycle/programs/reference.s) (tested and verified by [Yazan]() and [Omar](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Omar_Alkhatib_Personal_Statement.md)) and lastly [whole.s](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/Single-Cycle-Cpu/RISC-V-Single-Cycle/programs/whole.s) (tested and verified by [Yi](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/blob/main/Yi%20Zhang's%20Personal%20Statement.md)). We ran these tests while building the CPU, and also upon completing it. Upon verification, we went on to testing the [pdf](https://github.com/EIE2-IAC-Labs/Project_Brief/tree/main/reference) program provided and the F1 program (Reslts shown in [test for cpu](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-30/tree/main/test%20for%20cpu/countertests) for both cores).
