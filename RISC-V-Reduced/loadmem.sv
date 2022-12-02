module loadmem #(
    parameters D_WIDTH = 32,

) (
    input logic [D_WIDTH-1:0]ramout,
    input logic [2:0] addrmode,
    input logic [1:0] selectbits,
    output logic [D_WIDTH-1:0] dout
);




endmodule



// if 00 select byte 0, if 01, select byte 1
//addr, half word, word, or byte, 000 (bytes) and select byte 01, output = signex(byte 1)
//addr 001 (select half word), select byte = 01, output = signext(byte 3, byte 2)