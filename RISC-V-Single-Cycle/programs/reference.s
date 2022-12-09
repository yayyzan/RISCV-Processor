#......INITIALIZE A1 TO 1......

addi a1, zero, 1

#......TEST 1 FOR BRANCH INSTRUCTIONS, BRANCHES SHOULDNT OCCUR......
#......A BRANCH TO IJUMP (INCORRECT JUMP) WOULD SET A4 TO 0x63......
#......A1 = 1, ZERO = 0...... 

beq a1, zero, ijump         #a1 != zero, no jump 
bne zero, zero, ijump       #zero = zero, no jump 
blt a1, zero, ijump         #a1 > zero, no jump 
bge zero, a1, ijump         #zero < a1, no jump 
bltu a1, zero, ijump        #a1 unsigned > zero unsigned, no jump 
bgeu zero, a1, ijump        #zero unsigned < a1 unsigned, no jump 

#......TO SET A2 TO A 32 BIT WORD A LOAD INSTRUCTION CAN BE USED......
#......MAKE SURE TO SET A2 TO A WORD THAT STARTS WITH 1 (MSB = 1), RAM[0] MUST BE INITIALIZED TO THAT WORD......

lw a2, 0(zero)

#......TEST FOR ALU INSTRUCTIONS......

srai a2, a2, 1              #should append a 1 as a msb because msb of a2 is 1, tests right arth shift instruction
slli a2, a2, 1              #should bring back a2 to its original value
slt a2, a2, zero            #should set a2 to 1 due to signed interpretation. a2 msb = 1 (negative) and is therefore less than 0
sltu a2, a2, zero           #should set a2 to 0 due to unsigned interpretation. a2 msb = 1 (positive and > 0)

#......TEST 2 FOR BRANCH INSTRUCTIONS, BRANCHES SHOULD OCCUR......
#......IF AT ANY POINT A4 IS SET TO 0x63, TEST IS UNSUCCESSFUL......
#......IF A3 IS SET TO 0x10 THEN BRANCH TEST SUCCESSFUL......
#......A2 = 0, A1 = 1, ZERO = 0......

beq a2, zero, passed1           #a2 = zero, branch to passed1 should occur 
addi a4, zero, 99

passed1:
bne a1, a2, passed2             #a1 != a2, branch to passed2 should occur
addi a4, zero, 99

passed2:
blt a2, a1, passed3             #a2 < a1, branch to passed3 should occur
addi a4, zero, 99

passed3:
bge a1, a2, passed4             #a1 > a2, branch to passed4 should occur
addi a4, zero, 99

passed4:
bltu a2, a1, passed5            #a2 unsigned < a1 unsigned, branch to passed5 should occur
addi a4, zero, 99

passed5:   
bgeu a1, a2, passed6            #a1 unsigned > a2 unsigned, branch to passed6 should occur to finalize test 
addi a4, zero, 99

passed6:
addi a3, zero, 16               #a3 set to 0x10 to show successful branch test

#......END: CONSTANTLY JUMP TO END T0 CONCLUDE TEST......

end:
j end           #by ending the program, we refrain from ever setting a4 to 0x63

#......IJUMP (INCORRECT JUMP) SETS A4 TO 0x63 WHICH SHOWS SOMETHING WRONG HAS OCCURED......

ijump:
addi a4, zero, 99   