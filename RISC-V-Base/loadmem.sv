module loadmem #(
    parameter D_WIDTH = 32
) (
    input  logic [        2:0] addrmode,
    input  logic [        1:0] selectbytes,  //instruction[1:0]%4 in cpu.sv
    input  logic [D_WIDTH-1:0] ramout,
    output logic [D_WIDTH-1:0] read_data
);

  always_comb begin
    case (addrmode)
      3'b000: begin  //load byte signed
        case(selectbytes) //read_data = {{5'd24{ramout[selectbytes*8 + 7]}}, ramout[selectbytes*8 + 7:selectbytes*8]};
          2'b00: read_data = {{5'd24{ramout[7]}}, ramout[7:0]};  //select byte 00
          2'b01: read_data = {{5'd24{ramout[15]}}, ramout[15:8]};  //select byte 01
          2'b10: read_data = {{5'd24{ramout[23]}}, ramout[23:16]};  //select byte 10
          2'b11: read_data = {{5'd24{ramout[31]}}, ramout[31:24]};  //select byte 11
        endcase
      end
      3'b001: begin  //load half signed
        case(selectbytes) //read_data = (selectbytes!=3)?{{5'd16{ramout[selectbytes*8 + 15]}}, ramout[selectbytes*8 + 15:selectbytes*8]}:0;
          2'b00: read_data = {{5'd16{ramout[15]}}, ramout[15:0]};  //select byte 00
          2'b01: read_data = {{5'd16{ramout[23]}}, ramout[23:8]};  //select byte 01
          2'b10: read_data = {{5'd16{ramout[31]}}, ramout[31:16]};  //select byte 10
          2'b11: read_data = 0;  //complete all cases
        endcase
      end
      3'b100: begin  //load byte unsigned
        case (selectbytes)  //read_data = {{5'd24{0}}, ramout[selectbits*8 + 7:selectbits*8]};
          2'b00: read_data = {{24'b0}, ramout[7:0]};  //select byte 00
          2'b01: read_data = {{24'b0}, ramout[15:8]};  //select byte 01
          2'b10: read_data = {{24'b0}, ramout[23:16]};  //select byte 10
          2'b11: read_data = {{24'b0}, ramout[31:24]};  //select byte 11
        endcase
      end
      3'b101: begin  //load half unsigned
        case(selectbytes) //read_data = (selectbits!=3)?{{4'd16{ramout[selectbits*8 + 15]}}, ramout[selectbits*8 + 15:selectbits*8]}:0
          2'b00: read_data = {{16'b0}, ramout[15:0]};  //select byte 00
          2'b01: read_data = {{16'b0}, ramout[23:8]};  //select byte 01
          2'b10: read_data = {{16'b0}, ramout[31:16]};  //select byte 10
          2'b11: read_data = 0;  //complete all cases
        endcase
      end
      3'b010: read_data = ramout;  //load word

      default: begin
        read_data = ramout;  //load word
      end
    endcase
  end

  // always_ff @(posedge clk) begin
  //   $display("read_data: %h", read_data, " ramout: %h", ramout);
  // end

endmodule
