// System libs
#include <stdio.h>
#include <stdlib.h>

// Structure and functions prototypes
#include "../include/analyzer.h"

int main(int argc, char *argv[]) 
{
    // Check if user enter correct format of usage
    if (argc < 2) {
        fprintf(stderr, "Attention! Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // File to analyze
    analysis_results results;
    analyze_file(argv[1], &results);

    // Display and export results of analysis
    display_results(&results);
    export_to_csv("output/analysis.csv", &results);

    return EXIT_SUCCESS;
}
