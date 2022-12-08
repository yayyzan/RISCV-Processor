module cpu #(
    parameter WIDTH = 32
) (
    input logic trigger, clk, rst,
    output logic [WIDTH-1:0] a0_output
);

  wire [WIDTH-1:0] rf_dout1, rf_dout2, interm_immop, prog_addr, interm_ins, interm_aluout, interm_loadout, interm_wdrf, jump_addr, interm_rfpc;
  wire [WIDTH-1:0] result = interm_resultsrc ? interm_loadout : interm_aluout;
  wire [6:0] interm_opcode;
  wire [3:0] interm_aluctrl;
  wire [2:0] interm_funct3, interm_immsrc;
  wire interm_funct7, interm_alusrc, interm_pcsrc, interm_eq, write_en, interm_memwrite, interm_resultsrc, interm_jbmux, interm_pcwritemux, interm_addupper;
  
  assign interm_opcode = interm_ins[6:0];
  assign interm_funct3 = interm_ins[14:12];
  assign interm_funct7 = interm_ins[30];
  assign interm_wdrf = interm_pcwritemux ? prog_addr + 4 : result;
  assign jump_addr = interm_jbmux ? result : interm_immop;
  assign interm_rfpc = interm_addupper ? prog_addr : rf_dout1;

  controlunit ctrlunit (
      .opcode(interm_opcode),
      .funct3(interm_funct3),
      .funct7(interm_funct7),
      .eq(interm_eq),  //in
      .regwrite(write_en),  //out
      .aluctrl(interm_aluctrl),  //out
      .alusrc(interm_alusrc),  //out
      .pcsrc(interm_pcsrc),  //out
      .immsrc(interm_immsrc),  //out
      .memwrite(interm_memwrite),  //out
      .resultsrc(interm_resultsrc),
      .jbmux(interm_jbmux),
      .pcwritemux(interm_pcwritemux),
      .addupper(interm_addupper),
  );

  pcountunit programcounter (
      .clk(clk),  //in
      .rst(rst),  //in
      .pcsrc(interm_pcsrc),  //in
      .jumpaddress(jump_addr),  //in
      .pc(prog_addr),  //out
      .jbmux(interm_jbmux)
  );

  instrmem programmem (
      .address(prog_addr),
      .dout(interm_ins)
  );

  signextender sgnextend (
      .instruction(interm_ins[31:7]),
      .immsrc(interm_immsrc),
      .immop(interm_immop)
  );

  alu alu (
      .alusrc(interm_alusrc),
      .aluctrl(interm_aluctrl),
      .aluop1(interm_rfpc),
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
      .wd3(interm_wdrf),  //in
      .a0(a0_output),  //out
      .rd1(rf_dout1),  //out
      .rd2(rf_dout2),  //out
      .trigger(trigger)
  );

  data_memory memory (
      .clk(clk),
      .write_enable(interm_memwrite),
      .addrmode(interm_funct3),
      .selectbytes(interm_aluout[1:0]),
      .write_data(rf_dout2),
      .address({interm_aluout[31:2], 2'b00}),
      .read_data(interm_loadout)
  );

//   always_ff @(posedge clk) begin
//     $display("ins: %h", interm_ins, " progaddr: %h", prog_addr, "\n");
//   end

endmodule
