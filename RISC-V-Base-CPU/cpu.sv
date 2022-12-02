module cpu #(
    parameter WIDTH = 32
) (
    input logic clk, rst,
    output logic [4:0] rd_add,
    output logic [WIDTH-1:0] prog_addr, interm_ins, rout_test, a0_output, rf_dout1, rf_dout2, interm_immop
);

  wire [WIDTH-1:0] interm_aluout, result = interm_resultsrc ? rout_test : interm_aluout;
  wire [2:0] interm_aluctrl, interm_immsrc, inter_addrmode;
  wire interm_memwrite, interm_resultsrc, write_en, interm_pcsrc, interm_eq, interm_alusrc;
  
  assign rd_add = interm_ins[19:15];

  controlunit ctrlunit (
      .instruction(interm_ins),  //in
      .eq(interm_eq),  //in
      .regwrite(write_en),  //out
      .aluctrl(interm_aluctrl),  //out
      .alusrc(interm_alusrc),  //out
      .pcsrc(interm_pcsrc),  //out
      .immsrc(interm_immsrc),  //out
      .memwrite(interm_memwrite),  //out
      .addrmode(inter_addrmode),  //out
      .resultsrc(interm_resultsrc)  //out
  );

  pcountunit programcounter (
      .clk(clk),  //in
      .rst(rst),  //in
      .pcsrc(interm_pcsrc),  //in
      .immop(interm_immop),  //in
      .pc(prog_addr)  //out
  );

  instrmem programmem (
      .address(prog_addr),
      .dout(interm_ins)
  );

  signextender sgnextend (
      .instruction(interm_ins),
      .immsrc(interm_immsrc),
      .immop(interm_immop)
  );


  alu alu (
      .alusrc(interm_alusrc),
      .aluctrl(interm_aluctrl),
      .aluop1(rf_dout1),
      .immop(interm_immop),
      .regop2(rf_dout2),
      .aluout(interm_aluout),
      .eq(interm_eq)
  );

  rf registerfile (
      .clk(clk),  //in
      .we3(write_en),  //in
      .ad1(interm_ins[19:15]),  //in
      .ad2(interm_ins[24:20]),  //in
      .ad3(interm_ins[11:7]),  //in
      .wd3(result),  //in
      .a0(a0_output),  //out
      .rd1(rf_dout1),  //out
      .rd2(rf_dout2)  //out
  );

  ram ram (
      .clk(clk),
      .address(interm_aluout),
      .bytes(inter_addrmode),
      .we(interm_memwrite),
      .wd(rf_dout2),
      .dout(rout_test)
  );



endmodule
