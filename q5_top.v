module top_module(
    input clk,
    input rst
);

wire [9:0] count;
wire fsm_done;
wire cnt512_done;
wire global_rst;

assign global_rst = rst | cnt512_done;

counter_1024 c1(clk, global_rst, count);
mealy_fsm fsm(clk, global_rst, count, fsm_done);
counter_512 c2(clk, global_rst, fsm_done, cnt512_done);

endmodule