# Simple Makefile for SystemVerilog Pipeline Exercise
# Uses iverilog with -g2012 flag for SystemVerilog 2012 support

# Create build directory
all: setup basic hazard forwarding

setup:
	mkdir -p build

# Basic pipeline implementation
basic: setup
	@echo "Compiling basic pipeline..."
	iverilog -g2012 -o build/basic_tb.out pipeline_arith.sv testbench_basic.sv
	@echo "Running basic pipeline testbench..."
	vvp build/basic_tb.out

# Pipeline with hazard detection
hazard: setup
	@echo "Compiling pipeline with hazard detection..."
	iverilog -g2012 -o build/hazard_tb.out pipeline_arith_with_hazard.sv hazard_detection_unit.sv testbench_hazard.sv
	@echo "Running hazard detection testbench..."
	vvp build/hazard_tb.out

# Pipeline with forwarding
forwarding: setup
	@echo "Compiling pipeline with forwarding..."
	iverilog -g2012 -o build/forwarding_tb.out pipeline_arith_with_forwarding.sv forwarding_unit.sv testbench_forwarding.sv
	@echo "Running forwarding testbench..."
	vvp build/forwarding_tb.out

# Clean build artifacts
clean:
	rm -rf build

.PHONY: all setup basic hazard forwarding clean
