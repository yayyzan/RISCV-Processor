module fetch #(
  parameter A_WIDTH = 32
) (
    input logic pcsrc, clk, rst, 
    input logic [A_WIDTH-1:0] jumpaddress,      
    output [A_WIDTH-1:0] dout,                  //instruction mem out
    output [A_WIDTH-1:0] pc,
    output [A_WIDTH-1:0] pc_plus4
);

pcountunit pcountunit(
  .pcsrc(pcsrc),
  .clk(clk),
  .rst(rst),
  .jumpaddress(jumpaddress),
  .pc(pc),
  .pc_plus4(pc_plus4)
);

instrmem instrmem(
  .address(pc),
  .dout(dout)          // output intruction memory
);

endmodule
