module decode(
    input logic [31:0] wd3D, pcF, pcplusfourF, instrD,
    input logic we3D, clk, triggerD,
    input logic [4:0] ad3D,
    output logic regwriteD, resultsrcD, memwriteD, alusrcD, addupperD, jbmuxD, pcwritemuxD,
    output logic [3:0] aluctrlD,
    output logic [31:0] pcD, pcplusfourD, immopD, rd1D, rd2D, a0D,
    output logic [4:0] rdD
);

    wire funct7D = instrD[30];
    wire [2:0] immsrcD;
    wire [2:0] funct3D = instrD[14:12];
    wire [6:0]opcodeD = instrD[6:0];
    wire [24:0]signextinD = instrD[31:7];
    wire [4:0]ad1D = instrD[19:15];
    wire [4:0]ad2D = instrD[24:20];

    assign rdD = instrD[11:7];
    assign pcD = pcF;
    assign pcplusfourD = pcplusfourF;

controlunit ctrlunitD(
    .opcode(opcodeD),
    .funct3(funct3D),
    .funct7(funct7D),
    .regwrite(regwriteD),
    .alusrc(alusrcD),
    .pcwritemux(pcwritemuxD),
    .jbmux(jbmuxD),
    .memwrite(memwriteD),
    .resultsrc(resultsrcD),
    .addupper(addupperD),
    .aluctrl(aluctrlD),
    .immsrc(immsrcD)
);

rf rfD(
    .clk(clk),
    .we3(we3D),
    .trigger(triggerD),
    .ad1(ad1D),
    .ad2(ad2D),
    .ad3(ad3D),
    .wd3(wd3D),
    .a0(a0D),
    .rd1(rd1D),
    .rd2(rd2D)
);

signextender signexD(
    .instruction(signextinD),
    .immsrc(immsrcD),
    .immop(immopD)
);

endmodule
