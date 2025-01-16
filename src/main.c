// System libs
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Structure and functions prototypes
#include "../include/analyzer.h"

#define MAX_PATH_LENGTH 1024 // For User's output file path

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

    // Ask the user if he wants to save results
    printf("Do you want to save your results of analysis? (y/n): ");
    char user_choice;
    scanf("%c", &user_choice);
    while (getchar() != '\n'); // Clear the input buffer
    user_choice = tolower(user_choice); // for comfortable check

    // Ask the user for the output file path
    char output_path[MAX_PATH_LENGTH];
    if (user_choice == 'n')
        exit(EXIT_SUCCESS);
    printf("Where you want to save results? Enter the full path: ");
    if (fgets(output_path, MAX_PATH_LENGTH, stdin) == NULL) {
        perror("Error while reading input!\n");
        exit(EXIT_FAILURE);
    }

    // Remove trailing newline character, if present
    output_path[strcspn(output_path, "\n")] = '\0';

    // Call the export function with the user-provided path
    export_to_csv(output_path, &results);
    printf("\nAnalysis was successfuly exported to %s!\n", output_path);

    return EXIT_SUCCESS;
}
