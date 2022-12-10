
module pcountunit #(
    parameter WIDTH = 32
) (
    input logic pcsrc, clk, rst, jbmux,
    input logic [WIDTH-1:0] jumpaddress,
    output logic [WIDTH-1:0] pc,
    output logic [WIDTH-1:0] pc_plus4  // newly added output for register
);

  logic [WIDTH-1:0] next_pc;
  logic [WIDTH-1:0] branch_pc;

  initial begin
    assign branch_pc = 32'hBFC00000;
  end

  always_comb begin
    branch_pc = jbmux ? jumpaddress : pc + jumpaddress;
    next_pc   = pcsrc ? branch_pc : pc + 4;
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
