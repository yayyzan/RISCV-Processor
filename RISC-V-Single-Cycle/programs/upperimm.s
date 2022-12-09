# ....TEST FOR LOAD UPPER IMMEDIATE......
lui a1, 0xfffff     a1 = fffff000
lui a2, 0x12345     a2 = 12345000

# ......TEST FOR ADD UPPER IMM......
auipc a3, 0x00000   a3 = 00000008
auipc a4, 0xff000   a4 = ff00000c