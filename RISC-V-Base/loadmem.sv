module loadmem #(
    parameter D_WIDTH = 32
)(
    input logic [D_WIDTH-1:0]ramout,
    input logic [2:0] addrmode,
    input logic [1:0] selectbits, //instruction[1:0]%4 in cpu.sv
    output logic [D_WIDTH-1:0] dout
);

    always_comb begin
        case (addrmode)
            3'b000: dout = {{5'd24{ramout[selectbits*8 + 7]}}, ramout[selectbits*8 + 7:selectbits*8]};//load byte
            3'b100: dout = {{5'd24{0}}, ramout[selectbits*8 + 7:selectbits*8]};//load byte unsigned
            3'b001: dout = (selectbits!=3)?{{5'd8{ramout[selectbits*8 + 15]}}, ramout[selectbits*8 + 15:selectbits*8]}:0;//load half
            3'b101: dout = (selectbits!=3)?{{5'd8{ramout[selectbits*8 + 15]}}, ramout[selectbits*8 + 15:selectbits*8]}:0;//load half unsigned
            3'b010: dout = ramout;//load word
            default: begin
                    dout = ramout;//load word
            end
        endcase
    end

endmodule
