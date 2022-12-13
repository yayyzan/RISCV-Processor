uppertest:
   lui a1, 0x12345
   lui t3, 0xff000
   addi t3, t3, 0xc
   auipc a3, 0xff000   #a3 = 0000000c
   bne a3, t3, upper_failed
   jal ra, upper_passed

no_jump_test:
    beq a1, zero, ijump         #a1 != zero, no jump 
    bne zero, zero, ijump       #zero = zero, no jump 
    blt a1, zero, ijump         #a1 > zero, no jump 
    bge zero, a1, ijump         #zero < a1, no jump 
    bltu a1, zero, ijump        #a1 unsigned > zero unsigned, no jump 
    bgeu zero, a1, ijump        #zero unsigned < a1 unsigned, no jump
    jal ra, no_jump_passed

memtest:
    li a0, 0x1ee10000 # a0: 1ee1000
    srai a0, a0, 16   # a0: 00001ee1
    sh a0, 0xE(zero)  # stores 1ee10000 at 0xc in memory
    sh a0, 0xC(zero)  # stores 1ee11ee1 at 0xc in memory
    lw a1, 0xC(zero)  # a1: 1ee11ee1
    lhu a2, 0xD(zero) # a2: e11e 
    lh a3, 0xD(zero)  # a3: ffffe11e
    lb a4, 0xF(zero)  # a4: 0000001e
    sw a3, 0x10(zero) # stores ffff1ee1 at 0x10 in memory
    lw a6, 0x10(zero) # a6: ffff1ee1

wait_for_check:
    beqz s1, wait_for_check #check registers manually, if correct press trigger to continue
    jal ra, memtest_passed
    sub s1, s1, s1

jump_test:
    addi a2, zero, 0
    addi a1, zero, 0x1
	beq a2, zero, passed1           #a2 = zero, branch to passed1 should occur 
	j ijump

passed1:
    bne a1, a2, passed2             #a1 != a2, branch to passed2 should occur
    j ijump

passed2:
    blt a2, a1, passed3             #a2 < a1, branch to passed3 should occur
    j ijump    

passed3:
    bge a1, a2, passed4             #a1 > a2, branch to passed4 should occur
    j ijump

passed4:
    bltu a2, a1, passed5            #a2 unsigned < a1 unsigned, branch to passed5 should occur
    j ijump

passed5:   
    bgeu a1, a2, passed6            #a1 unsigned > a2 unsigned, branch to passed6 should occur to finalize test 
    j ijump  

passed6:
    addi a3, zero, 16               #a3 set to 0x10 to show successful branch test
    
end:
  j end
    
upper_passed:
    addi s4, zero, 1
    ret
    
no_jump_passed:
    addi s5, zero, 1
    ret
    
memtest_passed:
    addi s6, zero, 1
    ret

ijump:
    addi a4, zero, 99 
    j ijump

upper_failed:
    addi a4, zero, 98
    j upper_failed
