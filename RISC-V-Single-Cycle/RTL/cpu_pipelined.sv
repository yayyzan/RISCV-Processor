module cpu_pipelined #(
    parameter WIDTH = 32
) (
    input logic trigger,clk,rst,
    output logic [WIDTH-1:0] a0_outputW
);

  logic [WIDTH-1:0] pcF;
  logic [WIDTH-1:0] instructionF;

  fetch fetch (
      .clk(clk),
      .rst(rst),
      .pcsrc(pcsrcE),
      .jumpaddress(pctargetE),    //*to keep consistant, change jumpaddress to pctarget in fetch will be better
      .pc(pcF),
      .instruction(instructionF)
  );

endmodule
