lui a0, 0x1ee10
nop
nop
srai a0, a0, 16
addi t0, zero, 1

alutest:
    addi s5, a0, 0x10 #s5: 00001ef1
    nop
    nop
    sub s6, s5, t0 #s6: 00001ef0
    nop
    nop
    slli s7, s6, 24 #s7:f0000000
    nop
    nop
    srai a0, s7, 4 #a0: ff0000000
    nop
    nop
    srli a1, a0, 4 #a1: 0ff00000
    and a2, s5, 1 #a2: 00000001
    nop
    xor a3, a1, a1 #a3:0 
    or a4, a2, a2 #a4: 1
    slt a5, a1, a0 #a5: 0
    sltiu a6, a1, -1 # a6:1 

end:
    j end