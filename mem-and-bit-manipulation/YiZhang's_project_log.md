# iac-riscv-cw-30, Yi Zhang's project log book of constructing memory  
<br/>

### 02/12/2022
Initialized the git repo with branches for each feature with our team.  

After a discussion of assigning tasks to each person, I am now responsible for data memory.  

Looked at verilator --help and create check.sh to help find syntax error.  

Designed the instructions for all types of load and store with omar.  

Since we should not do bit manipulation inside the ram, I am going to make seperate module to do bit manipulation for loadmem and storemem. The design is shown as below.  

![design for memory and bit manipulation](./pictures/datamemory.png)

<br/>

### 03/12/2022
Attempted to use expression for cases in system verilog, but realised we are not allowed to do so after testing with check.sh.  

![error image](./pictures/expression_error.png)  

Use case in case to solve the problem. The loadmem file is corrected with no syntax error and verified by check.sh.  
<br/>

### 04/12/2022
Corrected an error in loadmem.
