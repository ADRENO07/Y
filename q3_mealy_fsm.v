module mealy_fsm(
    input clk,
    input rst,
    input [9:0] count,
    output reg done
);

reg [2:0] state;
reg prev_hit;

wire hit;
assign hit = (count == 10'd777);

always @(posedge clk)
begin
    if (rst)
    begin
        state <= 0;
        done <= 0;
        prev_hit <= 0;
    end
    else
    begin
        case(state)
            0: if (hit && !prev_hit) state <= 1;
            1: if (hit && !prev_hit) state <= 2;
            2: if (hit && !prev_hit) state <= 3;
            3: if (hit && !prev_hit) state <= 4;
            4: if (hit && !prev_hit) state <= 5;
            5: begin
                   done <= 1;
                   state <= 5;
               end
        endcase
        prev_hit <= hit;
    end
end

endmodule