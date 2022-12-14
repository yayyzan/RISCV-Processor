module controlunit (
    input logic [6:0] opcode, 
    input logic [2:0] funct3,
    input logic funct7, eq, 
    output logic regwrite, alusrc, memwrite, resultsrc, pcwritemux, jbmux, addupper, pcsrc,
    output logic [3:0] aluctrl,
    output logic [2:0] immsrc
);

  logic rg = opcode == 51; 
  logic imm = opcode == 19; 
  logic load = opcode == 3;
  logic store = opcode == 35;
  logic branch = opcode == 99;
  logic ldupper = opcode == 55;
  logic aupper = opcode == 23;
  logic jalr = opcode == 103; 
  logic jal = opcode == 111;
  
  wire [1:0] aluop = {(rg | imm | ldupper), (ldupper | branch)};

  always_comb begin // main decoder
    regwrite = !store & !branch; 
    alusrc = !rg & !branch & !jal;
    memwrite = store; 
    resultsrc = load; 
    jbmux = jalr;  // selects which address pc should jump to
    pcwritemux = jalr | jal; // chooses between writing register with PC+4 or result from alu or load instruction
    addupper = aupper;

    case (opcode) 
      19:   immsrc = 0;  // imm
      3:    immsrc = 0;  // load
      35:   immsrc = 2;  // store
      99:   immsrc = 3;  // branch
      55:   immsrc = 1;  // upp imm (load)
      23:   immsrc = 1;  // upp imm (add)
      default:  immsrc = 4;  // jump
    endcase

    case(opcode)
      99: pcsrc = eq ? (funct3 == 1 | funct3 == 4 | funct3 == 6) : (funct3 == 0 | funct3 == 5 | funct3 == 7); //branch
      103: pcsrc = 1; // jump
      111: pcsrc = 1; // jump 
      default: pcsrc = 0;
    endcase
  end

  always_comb begin // aluctrl
    case (aluop)
      0: aluctrl = 0; // load or store or add upper
      1: aluctrl = {1'b0, !funct3[2], funct3[2], funct3[1]}; // branch
      2: aluctrl = {funct7 & ((imm & funct3 == 5) | (rg & (funct3 == 5| funct3 == 0))), funct3}; // reg or imm
      3: aluctrl = 15; //load upper
      default: aluctrl = 9;
    endcase
  end

  // always_ff @(posedge clk) begin
  //   $display("eq: %h", eq, " regwrite: %h", regwrite, " aluctrl: %b", aluctrl, " alusrc: %h",
  //            alusrc, " pcsrc: %h", pcsrc, " aluop: %b", aluop, "\n");
  // end

endmodule
