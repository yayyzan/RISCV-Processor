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
  logic [WIDTH-1:0] instrD;
  logic [WIDTH-1:0] pcplus4D;

  always_ff @(posedge clk) begin
    if (!pcsrcE) begin           //if doing jump or branch, skip the following instruction by resetting fetch part
      instrD <= instrF;
      pcD <= pcF;
      pcplus4D <= pcF + 4;
    end
    else begin
      instrD <= 0;
      pcD <= 0;
      pcplus4D <= 0;
    end
  end

  logic funct7D,alusrcD,memwriteD,resultsrcD,jbmuxD,pcwritemuxD,regwriteD,addupperD;
  logic [WIDTH-1:0] a0_outputD,rf_dout1D,rf_dout2D,immextD;
  logic [6:0] opcodeD;
  logic [4:0] rdD;
  logic [3:0] aluctrlD; 
  logic [2:0] funct3D;

  assign opcodeD = instrD[6:0];
  assign funct3D = instrD[14:12];
  assign funct7D = instrD[30];
  assign rdD = instrD[11:7];

  decode decode (
    .clk(clk),
    .opcode(opcodeD),
    .funct3(funct3D),
    .funct7(funct7D),
    .reg_addr_1(instrD[19:15]),
    .reg_addr_2(instrD[24:20]),
    .reg_addr_3(rdW),            //from write part
    .imm_of_instr(instrD[31:7]),
    .wd3(resultW),               //from write part
    .trigger(trigger),
    .regwrite(regwriteW),  //input for enable from write part
    .alusrc(alusrcD),
    .aluctrl(aluctrlD),
    .memwrite(memwriteD),
    .resultsrc(resultsrcD),
    .jbmux(jbmuxD),
    .pcwritemux(pcwritemuxD),
    .a0_output(a0_outputD),
    .rd1(rf_dout1D),
    .rd2(rf_dout2D),
    .immop(immextD),       //*to keep consistant, change immop to immext in decode will be better
    .pc(pcF), 
    .write_en(regwriteD),  //output from control, needs to propogate through pipeline
    .addupper(addupperD)
  );

  logic regwriteE,addupperE,alusrcE,memwriteE,resultsrcE,jbmuxE,pcwritemuxE;
  logic [WIDTH-1:0] a0_outputE,rf_dout1E,rf_dout2E,immextE,pcE,pcplus4E;
  logic [6:0] opcodeE;
  logic [4:0] rdE;  
  logic [3:0] aluctrlE;
  logic [2:0] funct3E;

  always_ff @(posedge clk) begin
    if (!pcsrcE) begin
      opcodeE <= opcodeD;
      funct3E <= funct3D;
      alusrcE <= alusrcD;
      aluctrlE <= aluctrlD;
      memwriteE <= memwriteD;
      resultsrcE <= resultsrcD;
      jbmuxE <= jbmuxD;
      pcwritemuxE <= pcwritemuxD;
      a0_outputE <= a0_outputD;
      rf_dout1E <= rf_dout1D;
      rf_dout2E <= rf_dout2D;
      immextE <= immextD;
      regwriteE <= regwriteD;
      addupperE <= addupperD;
      pcE <= pcD;
      pcplus4E <= pcplus4D;
      rdE <= rdD;
    end
    else begin
      opcodeE <= 0;
      funct3E <= 0;
      alusrcE <= 0;
      aluctrlE <= 0;
      memwriteE <= 0;
      resultsrcE <= 0;
      jbmuxE <= 0;
      pcwritemuxE <= 0;
      a0_outputE <= a0_outputD;
      rf_dout1E <= 0;
      rf_dout2E <= 0;
      immextE <= 0;
      regwriteE <= 0;
      addupperE <= 0;
      pcE <= 0;
      pcplus4E <= 0;
      rdE <= 0;
    end
  end

  logic [WIDTH-1:0] pctargetE,aluresultE;
  logic pcsrcE;

  execute execute (
    .clk(clk),
    .alusrc(alusrcE),
    .aluctrl(aluctrlE),
    .rf_dout1(rf_dout1E),
    .immop(immextE),      //*to keep consistant, change immop to immext in execute will be better
    .regop2(rf_dout2E),
    .opcode(opcodeE),
    .funct3(funct3E),
    .jbmux(jbmuxE),
    .prog_addr(pcE),
    .addupper(addupperE),
    .jumpaddress(pctargetE), //*to keep consistant, change jumpaddress to pctarget in fetch will be better
    .aluout(aluresultE),
    .pcsrc(pcsrcE)
  );

  logic regwriteM,resultsrcM,memwriteM,pcwritemuxM;
  logic [WIDTH-1:0] aluresultM,write_dataM,pcplus4M,a0_outputM;
  logic [4:0] rdM;
  logic [2:0] funct3M;

  always_ff @(posedge clk) begin
    aluresultM <= aluresultE;
    write_dataM <= rf_dout2E;
    rdM <= rdE;
    regwriteM <= regwriteE;
    resultsrcM <= resultsrcE;
    memwriteM <= memwriteE;
    pcplus4M <= pcplus4E;
    funct3M <= funct3E;
    pcwritemuxM <= pcwritemuxE;
    a0_outputM <= a0_outputE;
  end

  logic [WIDTH-1:0] read_dataM;

  data_memory memory (
    .clk(clk),
    .write_enable(memwriteM),
    .addrmode(funct3M),
    .selectbytes(aluresultM[1:0]),       //use 2 spare bits from address to select bytes in load and store instrucions
    .write_data(write_dataM),
    .address({aluresultM[31:2], 2'b00}), //the last 2 bit will always be zero
    .read_data(read_dataM)
  );

  logic regwriteW,resultsrcW,pcwritemuxW;
  logic [WIDTH-1:0] read_dataW,aluresultW,pcplus4W;
  logic [4:0] rdW;

  always_ff @(posedge clk) begin
    read_dataW <= read_dataM;
    regwriteW <= regwriteM;
    resultsrcW <= resultsrcM;
    aluresultW <= aluresultM;
    rdW <= rdM;
    pcplus4W <= pcplus4M;
    pcwritemuxW <= pcwritemuxM;
    a0_outputW <= a0_outputM;
  end

  logic [WIDTH-1:0] resultW;

  always_comb begin
    case ({
      pcwritemuxW, resultsrcW         
    })
      2'b01:   resultW = read_dataW;
      2'b10:   resultW = pcplus4W;
      default: resultW = aluresultW;
    endcase
  end

  always_ff @(posedge clk) begin
    $display("ins: %h", instrF, " progaddr: %h", pcF, "\n");
  end

endmodule
