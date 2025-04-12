// TODO: Implement the pipeline with hazard detection
// This module should extend the basic pipeline with hazard detection
// It should stall the pipeline when necessary to handle data dependencies

module pipeline_arith_with_hazard (
  input         clk,
  input         rst,
  input  [7:0]  a,
  input  [7:0]  b,
  input  [4:0]  rs,
  input  [4:0]  rt,
  input  [4:0]  rd,
  input         mem_read,
  output reg [7:0] result
);
  // Your implementation here
  
endmodule
