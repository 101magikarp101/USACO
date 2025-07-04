// TODO: Implement the forwarding unit
// This module should detect when forwarding can be used to resolve data hazards
// It should generate control signals to forward data from later pipeline stages
// back to earlier stages when appropriate

module forwarding_unit (
  input  [4:0]  id_ex_rs,    // source register 1 in EX stage
  input  [4:0]  id_ex_rt,    // source register 2 in EX stage
  input  [4:0]  ex_mem_rd,   // destination register in MEM stage
  input  [4:0]  mem_wb_rd,   // destination register in WB stage
  input         ex_mem_regwrite, // control signal if MEM stage will write to register
  input         mem_wb_regwrite, // control signal if WB stage will write to register
  output reg [1:0] forward_a,    // forwarding control for first ALU operand
  output reg [1:0] forward_b     // forwarding control for second ALU operand
);
  // Your implementation here
  
endmodule
