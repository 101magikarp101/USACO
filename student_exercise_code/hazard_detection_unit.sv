// TODO: Implement the hazard detection unit
// This module should detect data hazards in the pipeline
// It should identify when an instruction depends on the result of a previous instruction
// that is still in the pipeline, and generate a stall signal when necessary

module hazard_detection_unit (
  input  [4:0]  id_rs,     // source register from the decode stage
  input  [4:0]  id_rt,     // second source register
  input  [4:0]  ex_rd,     // destination register in EX stage
  input         ex_mem_read, // flag if EX stage is performing memory read
  output reg    stall      // output stall signal to pause pipeline fetch/decode
);
  // Your implementation here
  
endmodule
