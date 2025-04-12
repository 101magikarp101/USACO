# Pipelining in SystemVerilog - 80-Minute Exercise

The exercise is designed to be completed in 80 minutes.

## Module Signatures

### Basic Pipeline (Stage 1)
```systemverilog
module pipeline_arith (
  input         clk,
  input         rst,
  input  [7:0]  a,
  input  [7:0]  b,
  output reg [7:0] result
);
```

### Hazard Detection Unit (Stage 2)
```systemverilog
module hazard_detection_unit (
  input  [4:0]  id_rs,     // source register from the decode stage
  input  [4:0]  id_rt,     // second source register
  input  [4:0]  ex_rd,     // destination register in EX stage
  input         ex_mem_read, // flag if EX stage is performing memory read
  output reg    stall      // output stall signal to pause pipeline fetch/decode
);
```

### Pipeline with Hazard Detection (Stage 2)
```systemverilog
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
```

### Forwarding Unit (Stage 2 Alternative)
```systemverilog
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
```

### Pipeline with Forwarding (Stage 2 Alternative)
```systemverilog
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
```

## Exercise Tasks

1. **Task 1: Basic Pipeline Implementation (30 minutes)**
   - Implement a basic 5-stage pipeline in `pipeline_arith.sv`
   - The pipeline should perform addition of two 8-bit inputs
   - Stages: Fetch, Decode, Execute, Memory, Writeback

2. **Task 2: Hazard Detection and Forwarding (50 minutes)**
   - Choose one of the following approaches:
     - Implement hazard detection in `hazard_detection_unit.sv` and `pipeline_arith_with_hazard.sv`
     - Implement data forwarding in `forwarding_unit.sv` and `pipeline_arith_with_forwarding.sv`

## How to Build and Test

### Prerequisites
- Icarus Verilog (iverilog) with SystemVerilog support

### Building and Running Tests

1. **Compile and run the basic pipeline:**
   ```
   make basic
   ```

2. **Compile and run the pipeline with hazard detection:**
   ```
   make hazard
   ```

3. **Compile and run the pipeline with forwarding:**
   ```
   make forwarding
   ```

4. **Clean build artifacts:**
   ```
   make clean
   ```

## Implementation Details

### Basic Pipeline
- Implement a 5-stage pipeline for arithmetic operations
- Each stage should be synchronized with the clock
- The pipeline should handle the basic flow of data through all stages

### Hazard Detection
- Detect when an instruction depends on the result of a previous instruction
- Generate a stall signal to pause the pipeline when necessary
- Insert bubbles (NOPs) into the pipeline to resolve hazards

### Data Forwarding
- Forward results from later pipeline stages to earlier stages
- Detect when forwarding can be used to resolve data hazards
- Implement forwarding paths to minimize stalls

## Expected Output

When your implementation is correct, you should see output similar to:

### Basic Pipeline
```
Test 0 passed. a=10, b=15, result=25
Test 1 passed. a=20, b=5, result=25
Test 2 passed. a=30, b=40, result=70
Test 3 passed. a=50, b=60, result=110
Test 4 passed. a=70, b=80, result=150
All tests passed successfully!
```

### Hazard Detection
```
Stall detected for hazard case!
Simulation with hazard detection complete after XX cycles
Detected 1 stalls
Hazard detection is working!
```

### Forwarding
```
Simulation with forwarding complete after XX cycles
Forwarding appears to be working correctly!
```
