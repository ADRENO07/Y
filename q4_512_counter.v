module counter_512(
    input clk,
    input rst,
    input en,
    output done
);

wire [8:0] count;

param_counter #(511,9) c2(clk, rst, en, count, done);

endmodule