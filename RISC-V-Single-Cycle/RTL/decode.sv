module decode(
    input logic [31:0] wd3D, pcF, pcplusfourF, a0D, instrD,
    input logic we3D, clk, triggerD,
    input logic [4:0] ad3D,
    output logic regwriteD, resultsrcD, memwriteD, alusrcD, addupperD,
    output logic [3:0] aluctrlD,
    output logic [31:0] pcD, pcplusfourD, immopD, rd1D, rd2D,
    output logic [4:0] rdD
);

    wire [2:0] immsrcD;
    wire funct3D = instrD[14:12];
    wire funct7D = instrD[30];
    wire opcodeD = instrD[6:0];
    wire signextinD = instrD[31:7];
    wire ad1D = instrD[19:15];
    wire ad2D = instrD[24:20];

    assign rdD = instrD[11:7];
    assign pcD = pcF;
    assign pcplusfourD = pcplusfourF;

controlunit ctrlunitD(
    .opcode(opcodeD),
    .funct3(funct3D),
    .funct7(funct7D),
    .regwrite(regwriteD),
    .alusrc(alusrcD),
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
