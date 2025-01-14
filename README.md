# Description
A straightforward and expandable CLI-application for text file analysis. Word count, line count, character count, sentence length, word frequency, and other information are among the insights it offers. In addition to offering a number of other sophisticated tools for further in-depth text analysis, the program may export the analysis findings to a CSV file.

# Features
- **Basic analysis**: 
    - *Word count.*
    - *Line count.*
    - *Character count.*
    - *Sentence length analysis (longest and shortest).*
    - *Avg word and sentence length.*

- **Advanced analysis:**
    - *Word frequency analysis (counts how often each words appears).*
    - *Ability to export results to a CSV file.*

- **Additional features:**
    - *Supports stopwords filtering.*
    - *Option to analyze multiple files at once.*

# Requirements 
- GCC 

# How to build 
1. *Clone the repository to comfortable for you dir*.
2. *Open a terminal and navigate to the project dir*.
3. *Run the following command to compile the program:*
``` Bash
make
```
4. *After compiling, you'll have an executable called* `analyzer`. 

# How to use
1. *Run the program by passing a test file as argument:*
``` Bash
./analyzer data/file_with_text.txt
```
2. *See a result. Also all results of analysis will be stored in* `output/analysis.csv`.
3. *Word frequency by command:*
``` Bash
./analyzer word_frequency data/sample.txt
```

# Samples of output
- **Terminal output:**
``` Bash
Word Count: 450
Line Count: 35
Character Count: 2950
Longest Sentence Length (symbols amount): 128
Shortest Sentence Length (symbols amount): 18
Average Word Length: 4.37
Average Sentence Length: 12.9
```
- **SCV output:**
``` CSV
Type of output: Metric - Value

----RESULTS---

Word Count - 450
Line Count - 35
Character Count - 2950
Longest Sentence Length (symbols amount) - 128
Shortest Sentence Length (symbols amount) - 18
Average Word Length - 4.37
Average Sentence Length - 12.9

--------------
```

# Additional Features (Future Plans)
- **Text Summarization:** *Create a shortened version of the text that only includes the most crucial details.*
- **Plagiarism Checker:** *To find similarities, compare the text to a database of previously published texts.*
- **Visualization:** *Create visual depictions of the text data, including word clouds or bar charts for word frequencies.*
