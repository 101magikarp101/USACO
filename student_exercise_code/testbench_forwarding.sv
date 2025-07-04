module testbench_forwarding;
  reg         clk;
  reg         rst;
  reg  [7:0]  a, b;
  reg  [4:0]  rs, rt, rd;
  reg         reg_write;
  wire [7:0]  result;
  integer     cycle_count;

  // Instantiate the pipeline with forwarding
  pipeline_arith_with_forwarding uut (
    .clk(clk),
    .rst(rst),
    .a(a),
    .b(b),
    .rs(rs),
    .rt(rt),
    .rd(rd),
    .reg_write(reg_write),
    .result(result)
  );

  // Clock generation: 10ns period
  always #5 clk = ~clk;

  // Count cycles
  always @(posedge clk) begin
    if (!rst)
      cycle_count = cycle_count + 1;
  end

  // For tracking results
  reg [7:0] expected_results [0:4];
  integer i, errors;

  initial begin
    // Initialize signals
    clk = 0;
    rst = 1;
    cycle_count = 0;
    errors = 0;
    a = 8'd0;
    b = 8'd0;
    rs = 5'd0;
    rt = 5'd0;
    rd = 5'd0;
    reg_write = 0;
    
    // Initialize expected results
    expected_results[0] = 8'd25;  // 10 + 15
    expected_results[1] = 8'd25;  // 20 + 5
    expected_results[2] = 8'd70;  // 30 + 40
    expected_results[3] = 8'd110; // 50 + 60
    expected_results[4] = 8'd150; // 70 + 80
    
    // Reset sequence
    #20;
    rst = 0;

    // Test case 1: No hazard
    a = 8'd10; b = 8'd15; rs = 5'd1; rt = 5'd2; rd = 5'd3; reg_write = 1;
    #10;
    
    // Test case 2: Create a data dependency that requires forwarding
    a = 8'd20; b = 8'd5; rs = 5'd3; rt = 5'd5; rd = 5'd6; reg_write = 1; // rs depends on previous rd
    #10;
    
    // Test case 3: Another forwarding case
    a = 8'd30; b = 8'd40; rs = 5'd7; rt = 5'd6; rd = 5'd9; reg_write = 1; // rt depends on previous rd
    #10;
    
    // Test case 4: Multiple dependencies
    a = 8'd50; b = 8'd60; rs = 5'd9; rt = 5'd6; rd = 5'd11; reg_write = 1; // rs and rt depend on previous instructions
    #10;
    
    // Test case 5: No forwarding needed
    a = 8'd70; b = 8'd80; rs = 5'd12; rt = 5'd13; rd = 5'd14; reg_write = 1;
    #10;
    
    // Wait for pipeline to complete
    #100;
    
    // Display results
    $display("Simulation with forwarding complete after %0d cycles", cycle_count);
    
    // Check if forwarding is working correctly by verifying results
    if (result === expected_results[4])
      $display("Forwarding appears to be working correctly!");
    else
      $display("Warning: Final result doesn't match expected. Forwarding might not be working correctly.");
    
    $finish;
  end
endmodule
