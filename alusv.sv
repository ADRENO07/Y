// Non‑pipelined, clocked ALU in SystemVerilog
module alu_sv
  #(parameter int WIDTH = 8)
  (
    input  logic                 clk,
    input  logic                 reset,   // active‑high synchronous reset
    input  logic [WIDTH-1:0]     a,
    input  logic [WIDTH-1:0]     b,
    input  logic [3:0]           op,
    output logic [WIDTH-1:0]     y,
    output logic                 carry,
    output logic                 zero
  );

  // Optional typed opcode enum (for readability)
  typedef enum logic [3:0] {
    OP_ADD   = 4'b0000,
    OP_SUB   = 4'b0001,
    OP_AND   = 4'b0010,
    OP_OR    = 4'b0011,
    OP_XOR   = 4'b0100,
    OP_SLL   = 4'b0101,
    OP_SRL   = 4'b0110,
    OP_MOVA  = 4'b0111
  } op_t;

  logic [WIDTH-1:0] result_next;
  logic              carry_next;

  // combinational ALU core
  always_comb begin
    result_next = '0;
    carry_next  = 1'b0;

    unique case (op_t'(op))
      OP_ADD: begin
        {carry_next, result_next} = a + b;
      end
      OP_SUB: begin
        {carry_next, result_next} = a - b;
      end
      OP_AND: begin
        result_next = a & b;
      end
      OP_OR: begin
        result_next = a | b;
      end
      OP_XOR: begin
        result_next = a ^ b;
      end
      OP_SLL: begin
        result_next = a << 1;
      end
      OP_SRL: begin
        result_next = a >> 1;
      end
      OP_MOVA: begin
        result_next = a;
      end
      default: begin
        result_next = '0;
      end
    endcase
  end

  // sequential: register outputs
  always_ff @(posedge clk) begin
    if (reset) begin
      y     <= '0;
      carry <= 1'b0;
      zero  <= 1'b1;
    end else begin
      y     <= result_next;
      carry <= carry_next;
      zero  <= (result_next == '0);
    end
  end

endmodule
