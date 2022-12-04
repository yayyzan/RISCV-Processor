module storemem #(
  parameter D_WIDTH = 32
)(
  input logic [2:0]          addrmode, 
  input logic [1:0]          selectbytes,
  input logic [D_WIDTH-1:0]  ramdout,    //output of ram
  input logic [D_WIDTH-1:0]  write_data, //write data from register
  output logic [D_WIDTH-1:0] ramdin      //input of ram
);

  always_comb begin
    case (addrmode)
      3'b000:                                                             // store byte
        case(selectbytes)
          2'b00: ramdin = {ramdout[31:8],write_data[7:0]};                // select first byte
          2'b01: ramdin = {ramdout[31:16],write_data[7:0],ramdout[7:0]};  // select second byte
          2'b10: ramdin = {ramdout[31:24],write_data[7:0],ramdout[15:0]}; // select third byte
          2'b11: ramdin = {write_data[7:0],ramdout[23:0]};                // select fourth byte
        endcase

      3'b001:
        case(selectbytes)                                                 // store half
          2'b00: ramdin = {ramdout[31:16],write_data[15:0]};              // select first byte
          2'b01: ramdin = {ramdout[31:24],write_data[15:0],ramdout[7:0]}; // select second byte
          2'b10: ramdin = {write_data[15:0],ramdout[15:0]};               // select third byte
          2'b11: ramdin = 0;                                              // complete all cases
        endcase

      3'b010: ramdin = write_data;                                        // store word

      default: begin
        ramdin = write_data;                                              // store word
      end
    endcase
  end

endmodule
