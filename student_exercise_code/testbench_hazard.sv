module testbench_hazard;
  reg         clk;
  reg         rst;
  reg  [7:0]  a, b;
  reg  [4:0]  rs, rt, rd;
  reg         mem_read;
  wire [7:0]  result;
  integer     cycle_count;

  // Instantiate the pipeline with hazard detection
  pipeline_arith_with_hazard uut (
    .clk(clk),
    .rst(rst),
    .a(a),
    .b(b),
    .rs(rs),
    .rt(rt),
    .rd(rd),
    .mem_read(mem_read),
    .result(result)
  );

  // Clock generation: 10ns period
  always #5 clk = ~clk;

  // Count cycles
  always @(posedge clk) begin
    if (!rst)
      cycle_count = cycle_count + 1;
  end

  // For tracking stalls
  integer stall_count;
  reg [7:0] prev_result;
  reg stall_detected;

  initial begin
    // Initialize signals
    clk = 0;
    rst = 1;
    cycle_count = 0;
    stall_count = 0;
    a = 8'd0;
    b = 8'd0;
    rs = 5'd0;
    rt = 5'd0;
    rd = 5'd0;
    mem_read = 0;
    
    // Reset sequence
    #20;
    rst = 0;

    // Test case 1: No hazard
    a = 8'd10; b = 8'd15; rs = 5'd1; rt = 5'd2; rd = 5'd3; mem_read = 0;
    #10;
    a = 8'd20; b = 8'd5; rs = 5'd4; rt = 5'd5; rd = 5'd6; mem_read = 0;
    #10;
    
    // Test case 2: Create a hazard (memory read followed by use of same register)
    a = 8'd30; b = 8'd40; rs = 5'd7; rt = 5'd8; rd = 5'd9; mem_read = 1;
    #10;
    
    prev_result = result;
    a = 8'd50; b = 8'd60; rs = 5'd9; rt = 5'd10; rd = 5'd11; mem_read = 0; // Hazard: rs depends on previous rd
    #10;
    
    // Check if a stall occurred (result didn't change)
    if (prev_result === result) begin
      stall_count = stall_count + 1;
      $display("Stall detected for hazard case!");
    end
    
    a = 8'd70; b = 8'd80; rs = 5'd12; rt = 5'd13; rd = 5'd14; mem_read = 0;
    #10;
    
    // Wait for pipeline to complete
    #100;
    
    // Display results
    $display("Simulation with hazard detection complete after %0d cycles", cycle_count);
    $display("Detected %0d stalls", stall_count);
    
    // Check if hazard detection is working correctly
    if (stall_count > 0)
      $display("Hazard detection is working!");
    else
      $display("Warning: No stalls detected. Hazard detection might not be working correctly.");
    
    $finish;
  end
endmodule
