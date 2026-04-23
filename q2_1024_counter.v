module counter_1024(
    input clk,
    input rst,
    output [9:0] count
);

wire done;

param_counter #(1023,10) c1(clk, rst, 1'b1, count, done);

endmodule