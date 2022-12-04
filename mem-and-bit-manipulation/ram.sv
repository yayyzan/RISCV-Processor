module ram #(
  parameter ADDRESS_WIDTH = 32, 
            DATA_WIDTH = 8                         //byte addressed design
)(
  input logic                      clk,            //clock
  input logic                      write_enable,   //write enable
  input logic  [ADDRESS_WIDTH-1:0] address,        //address
  input logic  [31:0]              write_data,     //write data input
  output logic [31:0]              read_data       //data output
);

  logic [DATA_WIDTH-1:0] ram_array [32'h00001fff : 32'h00001000]; //according to memory map

  initial begin                                                   //initialise with all zeros
    for (int i = 32'h00001000; i < $size(ram_array); i++) begin
      ram_array[i] = 8'b0;
    end
  end

  always_comb begin 
    read_data = {{ram_array[address+3]}, {ram_array[address+2]}, {ram_array[address+1]}, {ram_array[address]}};  
  end

  always_ff @(posedge clk) begin
    if(write_enable)
      ram_array[address]   <= write_data[7:0];
      ram_array[address+1] <= write_data[15:8];
      ram_array[address+2] <= write_data[23:16];
      ram_array[address+3] <= write_data[31:24];
  end

endmodule
