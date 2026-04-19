`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Harshit
// 
// Create Date: 04/18/2026 
// Design Name: 
// Module Name: clock_counter_tb
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


`timescale 1ns/1ps

module clock_counter_tb;

// Inputs
reg clk;
reg rst;

// Outputs
wire [5:0] sec;
wire [5:0] min;
wire [4:0] hour;

// Instantiate DUT
clock_counter uut (
    .clk(clk),
    .rst(rst),
    .sec(sec),
    .min(min),
    .hour(hour)
);

// Clock Generation (10ns period)
initial clk = 0;
always #5 clk = ~clk;

// Stimulus
initial
begin
    // Apply reset
    rst = 1;
    #10;
    rst = 0;

    // Run simulation
    #2000;

    $finish;
end

// Monitor values
initial
begin
    $monitor("Time=%0t | Hour=%0d Min=%0d Sec=%0d",
              $time, hour, min, sec);
end

endmodule
