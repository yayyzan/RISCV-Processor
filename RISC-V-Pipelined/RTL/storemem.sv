module storemem #(
    parameter DATA_WIDTH = 32
)(
    input  logic [           2:0] addrmode,
    input  logic [           1:0] selectbytes,
    input  logic [DATA_WIDTH-1:0] ramout, write_data,     //output of ram and write data from register
    output logic [DATA_WIDTH-1:0] ramdin        //input of ram
);

  always_comb begin
    case (addrmode)
      3'b000:  // store byte
      case (selectbytes)
        2'b00: ramdin = {ramout[31:8], write_data[7:0]};  // select first byte
        2'b01: ramdin = {ramout[31:16], write_data[7:0], ramout[7:0]};  // select second byte
        2'b10: ramdin = {ramout[31:24], write_data[7:0], ramout[15:0]};  // select third byte
        2'b11: ramdin = {write_data[7:0], ramout[23:0]};  // select fourth byte
      endcase

      3'b001:
      case (selectbytes)  // store half
        2'b00: ramdin = {ramout[31:16], write_data[15:0]};  // select first byte
        2'b01: ramdin = {ramout[31:24], write_data[15:0], ramout[7:0]};  // select second byte
        2'b10: ramdin = {write_data[15:0], ramout[15:0]};  // select third byte
        2'b11: ramdin = 0;  // complete all cases
      endcase

      3'b010: ramdin = write_data;  // store word

      default: begin
        ramdin = write_data;  // store word
      end
    endcase
  end

endmodule
