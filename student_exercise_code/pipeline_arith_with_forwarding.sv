// TODO: Implement the pipeline with forwarding
// This module should extend the basic pipeline with data forwarding
// It should forward results from later pipeline stages to earlier stages
// to minimize stalls and improve performance

module pipeline_arith_with_forwarding (
  input         clk,
  input         rst,
  input  [7:0]  a,
  input  [7:0]  b,
  input  [4:0]  rs,
  input  [4:0]  rt,
  input  [4:0]  rd,
  input         reg_write,
  output reg [7:0] result
);
  // Your implementation here
  
endmodule
