#ifndef ANALYZER_H
#define ANALYZER_H

// Struct for analysis results
typedef struct {
    // In sentence counters
    int    word_count,
           line_count,
           char_count;

    // Sentence length counters
    int    longest_sentence_length,
           shortest_sentence_length;

    // Avg lengths of word and sentence counters
    double average_word_length,
           average_sentence_length;
} analysis_results;

/**
 * @brief Analyzes the contents of a text file and stores various metrics in results.
 * 
 * @param filename  Path to the input file to analyze (file to analyze)
 * @param results   Pointer to structure where analysis results will be stored
 */
void analyze_file(const char *filename, analysis_results *results);

/**
 * @brief Exports analysis results to a CSV file format.
 * 
 * @param filename  Path to the output CSV file (file to export)
 * @param results   Pointer to structure containing analysis results to export
 */
void export_to_csv(const char *filename, const analysis_results *results);

/**
 * @brief Displays analysis results in a formatted way to standard output.
 * 
 * @param results   Pointer to structure containing analysis results to display
 */
void display_results(const analysis_results *results);

#endif
