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
      instrD <= 0;
      pcD <= 0;
      pcplus4D <= 0;
    end
  end

  logic funct7D,alusrcD,memwriteD,resultsrcD,jbmuxD,pcwritemuxD,regwriteD,addupperD
  logic [WIDTH-1:0] a0_outputD,rf_dout1D,rf_dout2D,immextD
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
    .reg_addr_3(rdW),
    .imm_of_instr(instrD[31:7]),
    .wd3(resultW),
    .trigger(trigger),
    .regwrite(regwriteW),  //input for enable
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

  logic regwriteE,,addupperE,alusrcE,memwriteE,resultsrcE,jbmuxE,pcwritemuxE
  logic [WIDTH-1:0] a0_outputE,rf_dout1E,rf_dout2E,immextE,pcE,pcplus4E
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
      pcD <= 0;
      rdE <= 0;
    end
  end

endmodule
