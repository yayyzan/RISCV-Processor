module rf #(
    parameter A_WIDTH = 5,
    D_WIDTH = 32
) (
    input logic clk,we3,trigger,
    input logic [A_WIDTH-1:0] ad1,ad2,ad3,
    input logic [D_WIDTH-1:0] wd3,
    output logic [D_WIDTH-1:0] a0,rd1,rd2
);

  logic [D_WIDTH-1:0] rf_array[2**A_WIDTH-1:0];

  always_comb begin
    rd1 = rf_array[ad1];
    rd2 = rf_array[ad2];
  end

  initial begin
    for (int i = 0; i < $size(rf_array); i++) begin
      rf_array[i] = 32'h0000;
    end
  end

  assign a0 = rf_array[10];

    always_ff @(negedge clk) begin
        // $display(" s4: %h\t", rf_array[20], " s5: %h\t", rf_array[21], " s6: %h\t", rf_array[22], " s7: %h\t", rf_array[23],  " a0:%h \t", a0 ," a1: %h\t", rf_array[11], " a2: %h\t", rf_array[12], "a3: %h\t", rf_array[13], "a4: %h\t", rf_array[14], "a5: %h\t", rf_array[15], "a6: %h\t", rf_array[16]);
        if (trigger) begin 
        rf_array[9] <= {{31'b0}, 1'b1};
        end
        if(we3 && (ad3 != 0)) begin 
        rf_array[ad3] <= wd3; 
        end
    end
    
    
    
endmodule
