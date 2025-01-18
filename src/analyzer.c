// System libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <unistd.h>
#include <limits.h>

// Structure and functions prototypes
#include "../include/analyzer.h"

static int64_t sentence_count = 0; // Amount of sentences

void analyze_file(
    const char *filename, 
    analysis_results *results, 
    word_freq frequencies[], 
    int *words_num
)
{
    FILE *file = fopen(filename, "r"); // Open file in read mode

    if (file == NULL) { // Can't open file - exit
        perror("Error! Can't open file\nStatus");
        exit(EXIT_SUCCESS);
    }

    // Set to zero all counters
    results->word_count = results->line_count = results->char_count      = 0;
    results->longest_sentence_length                                     = 0;
    results->shortest_sentence_length                                    = INT_MAX;
    results->average_word_length = results->average_sentence_length      = 0;

    // Counter for amount of character and sentence length
    static char character;
    static int64_t sentence_length = 0,
                   word_length     = 0,
                   total_word_char = 0;

    // Stores a word, flag and index of word's pos
    char word[WORD_LENGTH];
    int wordIndex = 0;
    int found = 0;

    // Read while not end-of-file
    while ((character = fgetc(file)) != EOF) {
        // Increment amount of characters in text
        results->char_count++; 

        // Character is space then check if it's new line
        if (isspace(character)) {
            if (word_length > 0) {
                // Increment amount of words in text
                results->word_count++;

                // Amount of characters in word
                total_word_char += word_length;
                
                // Reset word length
                word_length = 0; 
            }
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
                if (sentence_length < results->shortest_sentence_length)
                    results->shortest_sentence_length = sentence_length;
                    
                // Increment amount of sentences
                ++sentence_count;
                
                // Begin of new sentence
                sentence_length = 0;
            }
        } else {// Sentence go on without signals of sentence end
            // Increment sentence and word lengths
            ++sentence_length;
            ++word_length;
        }
        if (isalnum(character)) { //Only alphanumeric characters are part of words
            word[wordIndex++] = tolower(character); //Convert to lowercase for case-insensitive counting.
            word[wordIndex] = '\0'; //Null-terminate the word string
        } else if (wordIndex > 0) { //Encountered a non-alphanumeric character, indicating end of a word

            found = 0;

            for (int i = 0; i < *words_num; i++) {
                if (strcmp(frequencies[i].word, word) == 0) {
                    frequencies[i].frequency++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (*words_num < MAX_WORDS) { //Avoid exceeding the maximum number of words
                    strcpy(frequencies[*words_num].word, word);
                    frequencies[*words_num].frequency = 1;
                    (*words_num)++;
                }
            }
            wordIndex = 0;
        }
    }
   
    
    // Account for the last word in the file (if not followed by space)
    if (word_length > 0) {
        results->word_count++;
        total_word_char += word_length;
    }

    // Handle case where no sentences were found
    if (sentence_count == 0)
        results->shortest_sentence_length = 0; // No sentences, set to 0

    // Calculate averages
    results->average_word_length = (results->word_count > 0)
        ? (double)total_word_char / results->word_count : 0.0;

    results->average_sentence_length = (sentence_count > 0)
        ? (double)results->char_count / sentence_count : 0.0;

    // Check if file is empty
    if (results->char_count == 0) {
        perror("File is empty!\nStatus");
        exit(EXIT_FAILURE);
    }

    // Close file and free memory 
    fclose(file);
}

void export_to_csv(
    const char *filename, 
    const analysis_results *results, 
    const word_freq frequencies[], 
    int words_num
) 
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
            results->char_count - 1); // Remove zero symbol of string
    fprintf(file, "Longest Sentence Length (symbols amount except whitespace) - %d\n", 
            results->longest_sentence_length);
    fprintf(file, "Shortest Sentence Length (symbols amount except whitespace) - %d\n", 
            results->shortest_sentence_length);
    fprintf(file, "Average Word Length - %.2f\n", 
            results->average_word_length);
    fprintf(file, "Average Sentence Length - %.2f\n", 
            results->average_sentence_length);
    fprintf(file, "\n---------------\n");
    //Add the bar chart output:
    int max_freq = 0;
    for (int i = 0; i < words_num; i++) {
        if (frequencies[i].frequency > max_freq) {
            max_freq = frequencies[i].frequency;
        }
    }

    fprintf(file, "\nWord Frequency Bar Chart:\n");
    for (int i = 0; i < words_num; i++) {
        int bar_length = (int)((float)frequencies[i].frequency / max_freq * 40); 
        if (bar_length < 1) bar_length = 1; 
        fprintf(file, "%-20s |", frequencies[i].word); 
        for (int j = 0; j < bar_length; j++) {
            fprintf(file, "#");
        }
        fprintf(file, " (%d)\n", frequencies[i].frequency);
    }

    // Close file
    fclose(file);
}

// Display the analysis results
void display_results(const analysis_results *results) 
{
    printf("Word Count: %d\n", 
        results->word_count);
    printf("Line Count: %d\n", 
        results->line_count);
    printf("Character Count: %d\n", 
        results->char_count - 1); // Remove zero symbol of string
    printf("Longest Sentence Length (symbols amount except whitespace): %d\n", 
        results->longest_sentence_length);
    printf("Shortest Sentence Length (symbols amount except whitespace): %d\n", 
        results->shortest_sentence_length);
    printf("Average Word Length: %.2f\n", 
        results->average_word_length);
    printf("Average Sentence Length: %.2f\n", 
        results->average_sentence_length);
}

void print_bar_chart(const word_freq frequencies[], int words_num) {
    //This function is the same as in previous responses.
    if (words_num <= 0) {
        printf("No words to display.\n");
        return;
    }

    // Find maximum frequency for scaling
    int max_freq = 0;
    for (int i = 0; i < words_num; i++) {
        if (frequencies[i].frequency > max_freq) {
            max_freq = frequencies[i].frequency;
        }
    }

    printf("\nWord Frequency Bar Chart:\n");
    for (int i = 0; i < words_num; i++) {
        int bar_length = (int)((float)frequencies[i].frequency / max_freq * 40); // Scale to 40 chars
        if (bar_length < 1) bar_length = 1; //Avoid zero-length bars.
        printf("%-20s |", frequencies[i].word); //Left-align word
        for (int j = 0; j < bar_length; j++) {
            printf("#");
        }
        printf(" (%d)\n", frequencies[i].frequency);
    }
}