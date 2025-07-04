module testbench_basic;
  reg         clk;
  reg         rst;
  reg  [7:0]  a, b;
  wire [7:0]  result;
  integer     cycle_count;

  // Instantiate the basic pipeline
  pipeline_arith uut (
    .clk(clk),
    .rst(rst),
    .a(a),
    .b(b),
    .result(result)
  );

  // Clock generation: 10ns period
  always #5 clk = ~clk;

  // Count cycles
  always @(posedge clk) begin
    if (!rst)
      cycle_count = cycle_count + 1;
  end

  // Test vector storage
  reg [7:0] expected_results [0:4];
  reg [7:0] test_a [0:4];
  reg [7:0] test_b [0:4];
  integer i, errors;

  initial begin
    // Initialize signals
    clk = 0;
    rst = 1;
    cycle_count = 0;
    a = 8'd0;
    b = 8'd0;
    errors = 0;
    
    // Initialize test vectors
    test_a[0] = 8'd10; test_b[0] = 8'd15; expected_results[0] = 8'd25;
    test_a[1] = 8'd20; test_b[1] = 8'd5;  expected_results[1] = 8'd25;
    test_a[2] = 8'd30; test_b[2] = 8'd40; expected_results[2] = 8'd70;
    test_a[3] = 8'd50; test_b[3] = 8'd60; expected_results[3] = 8'd110;
    test_a[4] = 8'd70; test_b[4] = 8'd80; expected_results[4] = 8'd150;
    
    // Reset sequence
    #20;
    rst = 0;

    // Test 1
    a = test_a[0]; b = test_b[0];
    #60; // Wait for pipeline to complete (5 stages + 1 for safety)
    if (result !== expected_results[0]) begin
      $display("ERROR: Test 0 failed. a=%0d, b=%0d, expected=%0d, got=%0d", 
               test_a[0], test_b[0], expected_results[0], result);
      errors = errors + 1;
    end else begin
      $display("Test 0 passed. a=%0d, b=%0d, result=%0d", 
               test_a[0], test_b[0], result);
    end
    
    // Test 2
    a = test_a[1]; b = test_b[1];
    #60; // Wait for pipeline to complete
    if (result !== expected_results[1]) begin
      $display("ERROR: Test 1 failed. a=%0d, b=%0d, expected=%0d, got=%0d", 
               test_a[1], test_b[1], expected_results[1], result);
      errors = errors + 1;
    end else begin
      $display("Test 1 passed. a=%0d, b=%0d, result=%0d", 
               test_a[1], test_b[1], result);
    end
    
    // Test 3
    a = test_a[2]; b = test_b[2];
    #60; // Wait for pipeline to complete
    if (result !== expected_results[2]) begin
      $display("ERROR: Test 2 failed. a=%0d, b=%0d, expected=%0d, got=%0d", 
               test_a[2], test_b[2], expected_results[2], result);
      errors = errors + 1;
    end else begin
      $display("Test 2 passed. a=%0d, b=%0d, result=%0d", 
               test_a[2], test_b[2], result);
    end
    
    // Test 4
    a = test_a[3]; b = test_b[3];
    #60; // Wait for pipeline to complete
    if (result !== expected_results[3]) begin
      $display("ERROR: Test 3 failed. a=%0d, b=%0d, expected=%0d, got=%0d", 
               test_a[3], test_b[3], expected_results[3], result);
      errors = errors + 1;
    end else begin
      $display("Test 3 passed. a=%0d, b=%0d, result=%0d", 
               test_a[3], test_b[3], result);
    end
    
    // Test 5
    a = test_a[4]; b = test_b[4];
    #60; // Wait for pipeline to complete
    if (result !== expected_results[4]) begin
      $display("ERROR: Test 4 failed. a=%0d, b=%0d, expected=%0d, got=%0d", 
               test_a[4], test_b[4], expected_results[4], result);
      errors = errors + 1;
    end else begin
      $display("Test 4 passed. a=%0d, b=%0d, result=%0d", 
               test_a[4], test_b[4], result);
    end
    
    // Report test results
    if (errors == 0)
      $display("All tests passed successfully!");
    else
      $display("%0d tests failed.", errors);
      
    $display("Simulation complete after %0d cycles", cycle_count);
    $finish;
  end
endmodule
