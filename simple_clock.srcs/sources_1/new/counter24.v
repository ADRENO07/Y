`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Harshit
// 
// Create Date: 04/18/2026
// Design Name: 
// Module Name: counter24
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module counter24 (
    output reg [4:0] count,
    output reg carry,
    input en, rst, clk
);

always @(posedge clk or posedge rst)
begin
    if (rst)
    begin
        count <= 0;
        carry <= 0;
    end
    else if (en)
    begin
        if (count == 23)
        begin
            count <= 0;
            carry <= 1;
        end
        else
        begin
            count <= count + 1;
            carry <= 0;
        end
    end
    else
        carry <= 0;
end

endmodule
    