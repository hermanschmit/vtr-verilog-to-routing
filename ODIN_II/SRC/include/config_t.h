#ifndef CONFIG_T_H
#define CONFIG_T_H

#include <vector>
#include <string>
#include "odin_types.h"

/* This is the data structure that holds config file details */
struct config_t {
    std::vector<std::string> list_of_file_names;

    std::string debug_output_path; // path for where to output the debug outputs
    std::string dsp_verilog;       // path for the output Verilog file including target DSPs' declaration
    enum file_type_e input_file_type;
    enum file_type_e output_file_type;
    enum elaborator_e elaborator_type;
    bool fflegalize;     // Legalize DFFs by making them rising edge
    bool coarsen;        // Specify if the input BLIF is coarse-grain
    bool show_yosys_log; // Print Yosys logs into the standard output stream
    bool decode_names;   // Extracting hierarchical information from Yosys coarse-grained BLIF file for signal naming

    bool output_ast_graphs;     // switch that outputs ast graphs per node for use with GRaphViz tools
    bool output_netlist_graphs; // switch that outputs netlist graphs per node for use with GraphViz tools
    bool print_parse_tokens;    // switch that controls whether or not each token is printed during parsing
    bool output_preproc_source; // TODO: unused

    int min_hard_multiplier; // threshold from hard to soft logic
    int mult_padding;        // setting how multipliers are padded to fit fixed size
    // Flag for fixed or variable hard mult (1 or 0)
    int fixed_hard_multiplier;
    // Flag for splitting hard multipliers If fixed_hard_multiplier is set, this must be 1.
    int split_hard_multiplier;
    // 1 to split memory width down to a size of 1. 0 to split to arch width.
    char split_memory_width;
    // Set to a positive integer to split memory depth to that address width. 0 to split to arch width.
    int split_memory_depth;

    //add by Sen
    // Threshold from hard to soft logic(extra bits)
    int min_hard_adder;
    int add_padding; // setting how multipliers are padded to fit fixed size
    // Flag for fixed or variable hard mult (1 or 0)
    int fixed_hard_adder;
    // Flag for splitting hard multipliers If fixed_hard_multiplier is set, this must be 1.
    int split_hard_adder;
    //  Threshold from hard to soft logic
    int min_threshold_adder;
    // defines if the first cin of an adder/subtractor is connected to a global gnd/vdd
    // or generated using a dummy adder with both inputs set to gnd/vdd
    bool adder_cin_global;

    // If the memory is smaller than both of these, it will be converted to soft logic.
    int soft_logic_memory_depth_threshold;
    int soft_logic_memory_width_threshold;

    std::string arch_file; // Name of the FPGA architecture file
    std::string tcl_file;  // TCL file to be run by yosys
};

extern config_t configuration;

#endif
