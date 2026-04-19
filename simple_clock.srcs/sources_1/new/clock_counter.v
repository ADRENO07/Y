`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Harshit
// 
// Create Date: 04/19/2026 
// Design Name: 
// Module Name: clock_counter
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


module clock_counter(
    input clk, rst,
    output [5:0] sec, min,
    output [4:0] hour
);

wire c1, c2;

counter60 s1(sec, c1, 1'b1, rst, clk);
counter60 m1(min, c2, c1, rst, clk);
counter24 h1(hour, , c2, rst, clk);

endmodule