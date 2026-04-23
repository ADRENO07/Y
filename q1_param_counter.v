module param_counter #(parameter MAX = 1023, WIDTH = 10)(
    input clk,
    input rst,
    input en,
    output reg [WIDTH-1:0] count,
    output done
);

always @(posedge clk)
begin
    if (rst)
        count <= 0;
    else if (en)
    begin
        if (count == MAX)
            count <= 0;
        else
            count <= count + 1;
    end
end

assign done = (count == MAX);

endmodule