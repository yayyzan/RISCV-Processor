module alu #(
    parameter D_WIDTH = 32
) (
    input logic alusrc,
    input logic [3:0] aluctrl,
    input logic [D_WIDTH-1:0] aluop1, immop, regop2,
    output logic [D_WIDTH-1:0] aluout,
    output logic eq
);

  logic [D_WIDTH-1:0] aluop2;

  always_comb begin
    aluop2  = alusrc ? immop : regop2;

    case (aluctrl)
      4'b0000: aluout = aluop1 + aluop2;
      4'b1000: aluout = aluop1 - aluop2;
      4'b0001: aluout = aluop1 << aluop2;  //shift left logic
      4'b0010: aluout = {{31'b0}, {(signed'(aluop1) < signed'(aluop2))}}; //set less than
      4'b0011: aluout = {{31'b0}, {(aluop1 < aluop2)}};  //set less than uns
      4'b0100: aluout = aluop1 ^ aluop2;
      4'b0101: aluout = aluop1 >> aluop2;  //shift right logical 
      4'b1101: aluout = $signed(aluop1) >>> aluop2[4:0];  // shift right arr
      4'b0110: aluout = aluop1 | aluop2;
      4'b0111: aluout = aluop1 & aluop2;
      4'b1111: aluout = aluop2;
      default: aluout = 0;
    endcase
  end

  always_comb begin
    case (aluctrl)
      4'b0100: eq = (aluout != 0);
      4'b0010: eq = aluout[0];
      default: eq = aluout[0];
    endcase
  end

endmodule

