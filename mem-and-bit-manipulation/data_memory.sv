module data_memory #(
  parameter ADDRESS_WIDTH = 32,
            DATA_WIDTH = 32
)(  
    input  logic                     clk,   
    input  logic                     write_enable,   
    input  logic [              2:0] addrmode,
    input  logic [              1:0] selectbytes,
    input  logic [   DATA_WIDTH-1:0] write_data,   //write data from register
    input  logic [ADDRESS_WIDTH-1:0] address,
    output logic [ADDRESS_WIDTH-1:0] read_data
);

logic [DATA_WIDTH-1:0]ramout;
logic [DATA_WIDTH-1:0]ramin;

storemem storemem(
  .addrmode(addrmode),
  .selectbytes(selectbytes),
  .ramout(ramout),
  .write_data(write_data),
  .ramdin(ramin)
);

ram ram(
  .clk(clk),
  .write_enable(write_enable),
  .address(address),
  .ramin(ramin),
  .ramout(ramout)
);

loadmem loadmem(
  .addrmode(addrmode),
  .selectbytes(selectbytes),
  .ramout(ramout),
  .read_data(read_data)
);

endmodule
