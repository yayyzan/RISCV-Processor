module ram #(
  parameter ADDRESS_WIDTH = 32, 
            DATA_WIDTH = 8                         //byte addressed design
)(
  input logic                      clk, write_enable,    //clock and write enable
  input logic  [ADDRESS_WIDTH-1:0] address,        //address
  input logic  [             31:0] ramin,     //write data input
  output logic [             31:0] ramout       //data output
);

  logic [DATA_WIDTH-1:0] ram_array [32'h00001ffff : 32'h0000000]; //according to memory map

  initial begin                                                //initialise with all zeros
    for (int i = 32'h00001000; i < $size(ram_array); i++) begin
      ram_array[i] = 8'b0;
    end
    $readmemh("./mem/<filename>.mem", ram_array, 32'h10000); // ....mem is pdf mem file to test
  end

  always_comb begin 
    ramout = {{ram_array[address+3]}, {ram_array[address+2]}, {ram_array[address+1]}, {ram_array[address]}};  
  end

  always_ff @(posedge clk) begin
    if(write_enable) begin
      ram_array[address]   <= ramin[7:0];
      ram_array[address+1] <= ramin[15:8];
      ram_array[address+2] <= ramin[23:16];
      ram_array[address+3] <= ramin[31:24];
    end
  end

endmodule
