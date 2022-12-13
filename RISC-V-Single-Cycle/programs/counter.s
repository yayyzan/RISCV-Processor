main:
    addi t1, zero, 0xff; # t1 = zero + 0xff
    addi a0, zero, 0x0; # a0 = zero + 0x0

mloop:
    addi a1, zero, 0xf0; # a1 = zero + 0xf0
    
iloop:
    addi a0, a1, 0; # a0 = a1 + 0
    addi a1, a1, 1; # a1 = a1 + 1
    bne a1, t1, iloop # if a1 != t1 then iloop
    bne t1, zero, mloop # if t1 != zero then mloop
    