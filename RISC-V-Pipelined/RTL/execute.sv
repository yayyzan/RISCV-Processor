module execute #(
    parameter D_WIDTH = 32
) (
    // input logic clk,
    input logic alusrc,
    input logic [3:0] aluctrl,
    input logic [D_WIDTH-1:0] rf_dout1,
    input logic [D_WIDTH-1:0] immop,
    input logic [D_WIDTH-1:0] regop2,
    input logic [6:0] opcode,
    input logic [2:0] funct3,
    input logic jbmux,
    input logic [D_WIDTH-1:0] prog_addr,
    input logic addupper,
    output logic [D_WIDTH-1:0] jumpaddress,
    output logic [D_WIDTH-1:0] aluout,
    output logic pcsrc

);

  logic eq;
  logic [D_WIDTH-1:0] rfpc;
  assign rfpc = addupper ? prog_addr : rf_dout1;
  
  alu alu (
      .alusrc(alusrc),
      .aluctrl(aluctrl),
      .aluop1(rfpc),
      .immop(immop),
      .regop2(regop2),
      .aluout(aluout),
      .eq(eq)
  );

  always_comb begin
    jumpaddress = jbmux ? aluout : prog_addr + immop;
    case(opcode)
      99: pcsrc = eq ? (funct3 == 1 | funct3 == 4 | funct3 == 6) : (funct3 == 0 | funct3 == 5 | funct3 == 7); //branch
      103: pcsrc = 1; // jump
      111: pcsrc = 1; // jump 
      default: pcsrc = 0;
    endcase
  end

  // always_ff @(posedge clk) begin
  //   $display("pcsrc: %b", pcsrc, " eq: %b", eq, " jumpaddr: %h", jumpaddress);
  // end

endmodule
