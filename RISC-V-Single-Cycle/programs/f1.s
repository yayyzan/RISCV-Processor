# initialize required value
addi t0, zero, 1      # t0 is the random number generated in lfsr)
addi s3, zero, 255    # a0, the output, equals to s3(255), then all lights are on

lfsr_loop:
    andi a1, t0, 0x8
    andi a2, t0, 0x4
    slli t0, t0, 1  # shift t0 leftside 1 unit and store it in a3
    srli a1, a1, 3  # shift a1 to the right most
    srli a2, a2, 2  # shift a2 to the right most
    xor a3, a1, a2  # a1 xor a2
    add t0, t0, a3  # t0 is the new random number for delaying
    andi t0, t0, 0xF # ignore bits before the final 4
    beq s1, zero, lfsr_loop # go next only when s9(x9) equals to 1, or it goes to lfsr loop again

lighting_loop:
    jal  ra, counter
    slli t1, a0, 1                 
    addi a0, t1, 1       # shift 1 and add 1 to light up the next light
    bne  a0, s3, lighting_loop      # go next step when a0 = s3(255). For each loop, one lights goes on

# when random number is generated, start the delay loop  
t0delay_loop:   
    jal  ra, counter
    addi a4, a4, 1     
    bne  a4, t0, t0delay_loop

addi a0, zero, 0   # close all light
addi a4, zero, 0
jal a5, lfsr_loop

#the counter loop that counts one second (the subroutine using JAL)
counter:
    addi t2, zero, 10 # count 28 cycles for 1 second delay
counter_loop:
    addi t2, t2, -1
    bne t2, zero, counter_loop 
    jalr a5, ra, 0x0