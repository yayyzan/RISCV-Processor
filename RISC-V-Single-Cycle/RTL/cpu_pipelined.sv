module cpu_pipelined #(
  parameter WIDTH = 32
) (
  input logic trigger,clk,rst,
  output logic [WIDTH-1:0] a0W
);

  logic [WIDTH-1:0] pcF;
  logic [WIDTH-1:0] instrF;
  logic [WIDTH-1:0] pcplusfourF;


  fetch fetch (
    .clk(clk),
    .rst(rst),
    .pcsrc(pcsrcE),
    .jumpaddress(pctargetE),
    .pc(pcF),
    .dout(instrF),
    .pc_plus4(pcplusfourF)
  );
  
  logic [WIDTH-1:0] pcD;
  logic [WIDTH-1:0] instrD;
  logic [WIDTH-1:0] pcplusfourD;

  always_ff @(posedge clk) begin
    if (!pcsrcE) begin           //if doing jump or branch, skip the following dout by resetting fetch part
      instrD <= instrF;
      pcD <= pcF;
      pcplusfourD <= pcplusfourF;
    end
    else begin
      instrD <= 0;
      pcD <= 0;
      pcplusfourD <= 0;
    end
  end

  logic regwriteD,resultsrcD,memwriteD,alusrcD,addupperD,jbmuxD,pcwritemuxD;
  logic [WIDTH-1:0] a0D,rd1D,rd2D,immextD;
  logic [6:0] opcodeD;
  logic [4:0] rdD;
  logic [3:0] aluctrlD; 
  logic [2:0] funct3D;

  assign opcodeD = instrD[6:0];
  assign funct3D = instrD[14:12];
  assign rdD = instrD[11:7];

  decode decode (
    .clk(clk),
    .triggerD(trigger),
    .we3D(regwriteW),           //from write part 
    .ad3D(rdW),                 //from write part 
    .wd3D(resultW),             //from write part 
    .a0D(a0D),
    .instrD(instrD),            //input ends here
    .regwriteD(regwriteD),
    .resultsrcD(resultsrcD),
    .memwriteD(memwriteD),
    .alusrcD(alusrcD),
    .addupperD(addupperD),
    .jbmuxD(jbmuxD),
    .pcwritemuxD(pcwritemuxD),
    .aluctrlD(aluctrlD),
    .immopD(immextD),
    .rd1D(rd1D),
    .rd2D(rd2D),
    .rdD(rdD)
  );

  logic regwriteE,addupperE,alusrcE,memwriteE,resultsrcE,jbmuxE,pcwritemuxE;
  logic [WIDTH-1:0] a0E,rd1E,rd2E,immextE,pcE,pcplusfourE;
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
      a0E <= a0D;
      rd1E <= rd1D;
      rd2E <= rd2D;
      immextE <= immextD;
      regwriteE <= regwriteD;
      addupperE <= addupperD;
      pcE <= pcD;
      pcplusfourE <= pcplusfourD;
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
      a0E <= a0D;
      rd1E <= 0;
      rd2E <= 0;
      immextE <= 0;
      regwriteE <= 0;
      addupperE <= 0;
      pcE <= 0;
      pcplusfourE <= 0;
      rdE <= 0;
    end
  end

  logic [WIDTH-1:0] pctargetE,aluresultE;
  logic pcsrcE;

  execute execute (
    .clk(clk),
    .alusrc(alusrcE),
    .aluctrl(aluctrlE),
    .rf_dout1(rd1E),
    .immop(immextE),      //*to keep consistant, change immop to immext in execute will be better
    .regop2(rd2E),
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
  logic [WIDTH-1:0] aluresultM,write_dataM,pcplusfourM,a0M;
  logic [4:0] rdM;
  logic [2:0] funct3M;

  always_ff @(posedge clk) begin
    aluresultM <= aluresultE;
    write_dataM <= rd2E;
    rdM <= rdE;
    regwriteM <= regwriteE;
    resultsrcM <= resultsrcE;
    memwriteM <= memwriteE;
    pcplusfourM <= pcplusfourE;
    funct3M <= funct3E;
    pcwritemuxM <= pcwritemuxE;
    a0M <= a0E;
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
  logic [WIDTH-1:0] read_dataW,aluresultW,pcplusfourW;
  logic [4:0] rdW;

  always_ff @(posedge clk) begin
    read_dataW <= read_dataM;
    regwriteW <= regwriteM;
    resultsrcW <= resultsrcM;
    aluresultW <= aluresultM;
    rdW <= rdM;
    pcplusfourW <= pcplusfourM;
    pcwritemuxW <= pcwritemuxM;
    a0W <= a0M;
  end

  logic [WIDTH-1:0] resultW;

  always_comb begin
    case ({
      pcwritemuxW, resultsrcW  //if resultsrcW is one resultW = read_dataW; if pcwritemuxW is one resultW = pcplus4W;
    })
      2'b01:   resultW = read_dataW;
      2'b10:   resultW = pcplusfourW;
      default: resultW = aluresultW;
    endcase
  end

  always_ff @(posedge clk) begin
    $display("ins: %h", instrF, " progaddr: %h", pcF, "\n");
  end

endmodule
