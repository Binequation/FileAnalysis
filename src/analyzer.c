// System libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <unistd.h>

// Struct and functions
#include "../include/analyzer.h"

// Define a word length
#define WORD_LENGTH 1024

void analyze_file(const char *filename, analysis_results *results)
{
    // Open file in read mode
    FILE *file = fopen(filename, "r");

    // Can't open file - exit
    if (file == NULL) {
        perror("Error! Can't open file.\n");
        exit(EXIT_FAILURE);
    }

    // Set to zero all counters
    results->word_count = results->line_count = results->char_count      = 0;
    results->longest_sentence_length = results->shortest_sentence_length = 0;
    results->average_word_length = results->average_sentence_length      = 0;

    // Counter for amount of character and sentence length
    char character;
    int64_t sentence_length = 0;

    // Read while not end-of-file
    while ((character = fgetc(file)) != EOF) {
        // Increment amount of characters in text
        results->char_count++;
        
        // if character is space then check if it's new line
        if (isspace(character)) {
            if (character == '\n')
                // Increment line counter if it's new line
                results->line_count++;
        }
        
        // Check if it's character the signal of sentence end 
        else if (ispunct(character)) {
            if (character == '.' || character == '?' || character == '!') {
                // Check max length of sentence
                if (sentence_length > results->longest_sentence_length)
                    results->longest_sentence_length  = sentence_length;
                else 
                    results->shortest_sentence_length = sentence_length;
            }
        } else // Sentence go on without signals of sentence end
            // Increment counter
            ++sentence_length;
    }

    // Close file and free memory 
    fclose(file);
}

void word_frequency(const char *filename)
{
    // Require realization
}

void export_to_csv(const char *filename, const analysis_results *results) 
{
    // Open file
    FILE *file = fopen(filename, "w");

    // Can't open file - exit
    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    // Write analysis info
    fprintf(file, "Type of output: Metric - Value\n\n");
    fprintf(file, "----RESULTS----\n\n");
    fprintf(file, "Word Count - %d\n", 
            results->word_count);
    fprintf(file, "Line Count - %d\n", 
            results->line_count);
    fprintf(file, "Character Count - %d\n", 
            results->char_count);
    fprintf(file, "Longest Sentence Length - %d\n", 
            results->longest_sentence_length);
    fprintf(file, "Shortest Sentence Length - %d\n", 
            results->shortest_sentence_length);
    fprintf(file, "Average Word Length - %.2f\n", 
            results->average_word_length);
    fprintf(file, "Average Sentence Length - %.2f\n", 
            results->average_sentence_length);
    fprintf(file, "\n---------------\n");

    // Close file
    fclose(file);
}

// Display the analysis results
void display_results(const analysis_results *results) 
{
    printf("Word Count: %d\n", results->word_count);
    printf("Line Count: %d\n", results->line_count);
    printf("Character Count: %d\n", results->char_count);
    printf("Longest Sentence Length: %d\n", results->longest_sentence_length);
    printf("Shortest Sentence Length: %d\n", results->shortest_sentence_length);
    printf("Average Word Length: %.2f\n", results->average_word_length);
    printf("Average Sentence Length: %.2f\n", results->average_sentence_length);
}
