
module pcountunit #(
    parameter WIDTH = 32
) (
    input logic pcsrc, clk, rst,
    input logic [WIDTH-1:0] jumpaddress,
    output logic [WIDTH-1:0] pc,
    output logic [WIDTH-1:0] pc_plus4  // newly added output for register
);

  logic [WIDTH-1:0] next_pc;

  always_comb begin
    next_pc   = pcsrc ? jumpaddress : pc + 4;
  end

  always_ff @(posedge clk) begin
    if (rst) begin 
      pc <= 32'hBFC00000;
      pc_plus4 <=  32'hBFC00000;
    end 
    else begin
       pc <= next_pc;
       pc_plus4 <= next_pc+4;
    end
  end



endmodule
