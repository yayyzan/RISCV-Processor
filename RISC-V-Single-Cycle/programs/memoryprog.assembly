......USE ADDI AS SHOWN BELOW UNTIL A0 = 1EE1......

addi a0, zero, 0xff
addi a0, a0, 0xff
addi a0, a0, 0xff
addi a0, a0, 0xff
addi a0, a0, 0xff
addi a0, a0, 0xff
addi a0, a0, 0xff 
.
.
.
addi a0, a0, 0xff           a0 = 00001ee1

......TEST MAJORITY OF LOAD AND STORE INSTRUCTIONS AS FOLLOWS......

sh a0, 0xE(zero)            ram[f]  ram[e]  ram[d]  ram[c]   WORD ADDRESS 
                              1e      e1      00      00          0xC
sh a0, 0xC(zero)            ram[f]  ram[e]  ram[d]  ram[c]   WORD ADDRESS 
                              1e      e1      1e      e1          0xC

lw a1, 0xC(zero)            a1 should equal 1ee11ee1
lhu a2, 0xD(zero)           a2 should equal 0000e11e (since it is an unsigned interpretation)
lh a2, 0xD(zero)            a2 should equal ffffe11e (since it is a signed interpretation)
lb a3, 0xF(zero)            a3 should equal 0000001e 

sw a2, 0x10(zero)           ram[13]  ram[12]  ram[11]  ram[10]  WORD ADDRESS 
                              ff        ff      e1        1e        0x10

lw a3, 0x10(zero)           a3 should become equal to a2,  a3 = ffffe11e