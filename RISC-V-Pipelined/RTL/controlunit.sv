module controlunit (
    input logic [6:0] opcode,
    input logic [2:0] funct3,
    input logic funct7, 
    output logic regwrite, alusrc, memwrite, resultsrc, pcwritemux, jbmux, addupper,
    output logic [3:0] aluctrl,
    output logic [2:0] immsrc
);

  wire [1:0] aluop = {(opcode == 7'h33 | opcode == 7'h13 | opcode == 7'h37), (opcode == 7'h37 | opcode == 7'h63)};

  always_comb begin
    regwrite = opcode == 7'h13 | opcode == 7'h03 | opcode == 7'h33 | opcode >= 7'h67 | opcode == 7'h17 | opcode == 7'h37; 
    alusrc = opcode == 7'h03 | opcode == 7'h13 | opcode == 7'h23 | opcode == 7'h67 | opcode == 7'h17 | opcode == 7'h37; 
    memwrite = opcode == 7'h23;  
    resultsrc = opcode == 7'h03; 
    jbmux = opcode == 7'h67; // selects which address pc should jump to
    pcwritemux = opcode >= 7'h67; // chooses between writing register with PC+4 or result from alu or load instruction
    addupper = opcode == 7'h17;
    case (opcode) 
      7'h13:   immsrc = 3'h0;  // imm
      7'h03:   immsrc = 3'h0;  // load
      7'h23:   immsrc = 3'h2;  // store
      7'h63:   immsrc = 3'h3;  // branch
      7'h33:   immsrc = 3'h7;  // reg
      7'h37:   immsrc = 3'h1;  // upp imm (load)
      7'h17:   immsrc = 3'h1;  // upp imm (add)
      default: immsrc = 3'h4;  // jump
    endcase
  end

  always_comb begin // aluctrl
    case (aluop)
      2'h0: aluctrl = 4'h0; // load and store and add upper
      2'h1: aluctrl = {1'h0, !funct3[2], funct3[2], funct3[1]}; // branch
      2'h2: aluctrl = {funct7 & ((opcode == 7'h13 & funct3 == 3'h5) | (opcode == 7'h33 & (funct3 == 3'h5 | funct3 == 3'h0))), funct3}; // reg or imm
      2'h3: aluctrl = 4'hf; //load upper
      default: aluctrl = 4'h9;
    endcase
  end
    
  // always_ff @(posedge clk) begin
  //   $display("eq: %h", eq, " regwrite: %h", regwrite, " aluctrl: %b", aluctrl, " alusrc: %h",
  //            alusrc, " pcsrc: %h", pcsrc, " aluop: %b", aluop, "\n");
  // end

endmodule
