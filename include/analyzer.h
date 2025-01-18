#ifndef ANALYZER_H
#define ANALYZER_H

#define WORD_LENGTH 1024 // Define a word length
#define MAX_WORDS   1000 // Limitations for words in bar chart

// Struct for analysis results
typedef struct {
    // In sentence counters
    int word_count,
        line_count,
        char_count;

    // Sentence length counters
    int longest_sentence_length,
        shortest_sentence_length;

    // Avg lengths of word and sentence counters
    double average_word_length,
           average_sentence_length;
} analysis_results;

// Struct for frequency of words
typedef struct {
    int frequency; // Count a frequency
    char word[WORD_LENGTH];
} word_freq;

/**
 * @brief Analyzes the contents of a text file and stores various metrics in results.
 * 
 * @param filename  Path to the input file to analyze (file to analyze)
 * @param results   Pointer to structure where analysis results will be stored
 */
void analyze_file(
    const char *filename, 
    analysis_results *results,
    word_freq *frequencies,
    int *words_num
);

/**
 * @brief Exports analysis results to a CSV file format.
 * 
 * @param filename  Path to the output CSV file (file to export)
 * @param results   Pointer to structure containing analysis results to export
 */
void export_to_csv(
    const char *filename, 
    const analysis_results *results,
    const word_freq frequencies[], 
    int words_num
);

/**
 * @brief Displays analysis results in a formatted way to standard output.
 * 
 * @param results   Pointer to structure containing analysis results to display
 */
void display_results(const analysis_results *results);

/**
 * @brief Displays bar charts of word's frequency
 * 
 * @param word_freq Pointer to structure containing word's frequency
 * @param words_num Amount of words
 * 
 */
void print_bar_chart(const word_freq frequencies[], int words_num);

#endif