module loadmem #(
  parameter D_WIDTH = 32
)(
  input logic [D_WIDTH-1:0]ramout,
  input logic [2:0] addrmode,
  input logic [1:0] selectbytes, //instruction[1:0]%4 in cpu.sv
  output logic [D_WIDTH-1:0] dout
);

  always_comb begin
    case(addrmode)
      3'b000: //load byte signed
        case(selectbytes) //{{5'd24{ramout[selectbytes*8 + 7]}}, ramout[selectbytes*8 + 7:selectbytes*8]};
          2'b00: dout = {{5'd24{ramout[7]}}, ramout[7:0]}; //select byte 00
          2'b01: dout = {{5'd24{ramout[15]}}, ramout[15:8]}; //select byte 01
          2'b10: dout = {{5'd24{ramout[23]}}, ramout[23:16]}; //select byte 10
          2'b11: dout = {{5'd24{ramout[31]}}, ramout[31:24]}; //select byte 11
        endcase

      3'b001: //load half signed
        case(selectbytes) //dout = (selectbytes!=3)?{{5'd16{ramout[selectbytes*8 + 15]}}, ramout[selectbytes*8 + 15:selectbytes*8]}:0;
          2'b00: dout = {{5'd16{ramout[15]}}, ramout[15:0]}; //select byte 00
          2'b01: dout = {{5'd16{ramout[23]}}, ramout[23:8]}; //select byte 01
          2'b10: dout = {{5'd16{ramout[31]}}, ramout[31:16]}; //select byte 10
          2'b11: dout = 0; //complete all cases
        endcase

      3'b100: //load byte unsigned
        case(selectbytes) //dout = {{5'd24{0}}, ramout[selectbits*8 + 7:selectbits*8]};
          2'b00: dout = {{5'd24{1'b0}}, ramout[7:0]}; //select byte 00
          2'b01: dout = {{5'd24{1'b0}}, ramout[15:8]}; //select byte 01
          2'b10: dout = {{5'd24{1'b0}}, ramout[23:16]}; //select byte 10
          2'b11: dout = {{5'd24{1'b0}}, ramout[31:24]}; //select byte 11
        endcase

      3'b101: //load half unsigned
        case(selectbytes) //dout = (selectbits!=3)?{{4'd16{ramout[selectbits*8 + 15]}}, ramout[selectbits*8 + 15:selectbits*8]}:0
          2'b00: dout = {{5'd16{1'b0}}, ramout[15:0]}; //select byte 00
          2'b01: dout = {{5'd16{1'b0}}, ramout[23:8]}; //select byte 01
          2'b10: dout = {{5'd16{1'b0}}, ramout[31:16]}; //select byte 10
          2'b11: dout = 0; //complete all cases
        endcase

      3'b010: dout = ramout; //load word

      default: begin
        dout = ramout; //load word
      end
    endcase
  end
  
endmodule
