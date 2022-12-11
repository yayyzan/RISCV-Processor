module cpu_pipelined #(
    parameter WIDTH = 32
) (
    input logic trigger,clk,rst,
    output logic [WIDTH-1:0] a0_outputW
);

  logic [WIDTH-1:0] pcF;
  logic [WIDTH-1:0] instrF;

  fetch fetch (
      .clk(clk),
      .rst(rst),
      .pcsrc(pcsrcE),
      .jumpaddress(pctargetE),    //*to keep consistant, change jumpaddress to pctarget in fetch will be better
      .pc(pcF),
      .instruction(instrF)
  );
  
  logic [WIDTH-1:0] pcD;
  logic [WIDTH-1:0] instrF;
  logic [WIDTH-1:0] pcplus4D;

  always_ff @(posedge clk) begin
    if (!pcsrcE) begin           //if doing jump or branch, skip the following instruction by resetting fetch part
      instrD <= instrF;
      pcD <= pcF;
      pcplus4D <= pcF + 4;
    end
    else begin
      insD <= 0;
      pcD <= 0;
      pcplus4D <= 0;
    end
  end

endmodule
