// Non‑pipelined, clocked ALU in Verilog
module alu
  #(parameter WIDTH = 8)
  (
    input  wire                  clk,
    input  wire                  reset,   // active‑high synchronous reset
    input  wire [WIDTH-1:0]      a,
    input  wire [WIDTH-1:0]      b,
    input  wire [3:0]            op,
    output reg  [WIDTH-1:0]      y,
    output reg                   carry,
    output reg                   zero
  );

  // internal combinational signals
  reg [WIDTH-1:0] result_next;
  reg              carry_next;

  // combinational ALU core
  always @* begin
    result_next = {WIDTH{1'b0}};
    carry_next  = 1'b0;

    case (op)
      4'b0000: begin // ADD
        {carry_next, result_next} = a + b;
      end
      4'b0001: begin // SUB
        {carry_next, result_next} = a - b;
      end
      4'b0010: begin // AND
        result_next = a & b;
      end
      4'b0011: begin // OR
        result_next = a | b;
      end
      4'b0100: begin // XOR
        result_next = a ^ b;
      end
      4'b0101: begin // SHIFT LEFT
        result_next = a << 1;
      end
      4'b0110: begin // SHIFT RIGHT
        result_next = a >> 1;
      end
      4'b0111: begin // PASS A
        result_next = a;
      end
      default: begin
        result_next = {WIDTH{1'b0}};
      end
    endcase
  end

  // sequential: register outputs (single stage, non‑pipelined)
  always @(posedge clk) begin
    if (reset) begin
      y     <= {WIDTH{1'b0}};
      carry <= 1'b0;
      zero  <= 1'b1;
    end else begin
      y     <= result_next;
      carry <= carry_next;
      zero  <= (result_next == {WIDTH{1'b0}});
    end
  end

endmodule
