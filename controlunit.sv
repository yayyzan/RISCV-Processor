module controlunit(
    input logic eq, funct7, // funct7 extracted from instruction, eq from alu
    input logic [2:0] funct3, // fucnt3 extracted from instruction
    input logic [6:0] opcode, // opcode extracted from instruction
    output logic pcsrc, resultsrc, memwrite, alusrc, regwrite, jbmux, pcwritemux, 
    output logic [2:0] immsrc, addrmode,
    output logic [3:0] aluctrl
);

wire [1:0] aluop = {(opcode == 7'h33 | opcode == 7'h13), (opcode == 7'h63 | opcode == 7'h13)};

// aluop tells the decoder which alu instruction is taking place. 01 for B-type, 10 for R-type, 11 for I-type, 00 otherwise, for example load

always_comb begin
    regwrite = opcode == 7'h13 | opcode == 7'h03 | opcode == 7'h33 | opcode >= 7'h67; // will be 1 for either jump instruction, R-type, I-type, and load instructions
    alusrc = opcode == 7'h03 | opcode == 7'h13 | opcode == 7'h23 | opcode == 7'h67; // will be 1 for any I-type, load, and store instruction. But only 1 for jalr from the jump instructions because an immediate offset exists
    memwrite = opcode == 7'h23; // only for for store instructions
    resultsrc = opcode == 7'h03; // only one for load instructions, otherwise 0 and result is taken from alu
    pcsrc = opcode >= 7'h67 | (opcode == 7'h63 & ((!eq & (funct3 == 3'h0 | funct3 == 3'h5 | funct3 == 3'h7)) | (eq & (funct3 == 3'h1 | funct3 == 3'h4 | funct3 == 3'h6)))); // pcsrc depends on alu implementation of eq. funct3 must be integrated to distingush between instructions called for each branch and the respective value of eq. pcsrc will also be one for either jump instruction
    jbmux = opcode == 7'h67; // select for jalr only. 1 for jalr instruction as immediate offset exixts
    pcwritemux = opcode >= 7'h67; // chooses between writing register with PC+4 or result from alu or load instruction
    addrmode = funct3; // addressing mode for load and store instructions. This is sufficient
    case (opcode) // chooses immsrc depending on instruction type
      7'h13 : immsrc = 3'h0; // imm
      7'h03 : immsrc = 3'h0; // load
      7'h23 : immsrc = 3'h2; // store
      7'h63 : immsrc = 3'h3; // branch
      7'h33 : immsrc = 3'h7; // reg
      default: immsrc = 3'h4; // jump
    endcase
end

always_comb begin // aluop decided previously, depending on type of instruction and the respective funct3 value, aluctrl is determined
    case (aluop)
        2'h0 : aluctrl = 4'h0; // load and store
        2'h1 : case (funct3[2]) // branch funct3[2] is only needed
            1'h0 : aluctrl = 4'h4; // xor to test equality
            1'h1 : aluctrl = 4'h2; // slt to test less than signed
            default: aluctrl = 4'h3; // slt unsigned to test less than unsigned
        endcase 
        2'h2 : case (funct3) // reg
            3'h0 : aluctrl = {funct7, 3'h0}; // 1000 (sub) if funct7 is 1, else 0 (add)
            3'h5 : aluctrl = {funct7, 3'h5}; // 1101 (shift right arth) if funct7 is 1, else 101 (shift right log)
        default: aluctrl = {1'h0, funct3}; // no longer dependant on funct7
        endcase
    default: case (funct3) // imm
    3'h5 : aluctrl = {funct7, 3'h5}; // 1101 (shift right arth) if funct7 is 1, else 101 (shift right log).
    default: aluctrl = {1'h0, funct3}; // no longer dependant on funct6
    endcase
endcase
end

endmodule
