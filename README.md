# Description
A straightforward and expandable CLI-application for text file analysis. Word count, line count, character count, sentence length, word frequency, and other information are among the insights it offers. In addition to offering a number of other sophisticated tools for further in-depth text analysis, the program may export the analysis findings to a CSV file.

# Table of Contents

[Features](https://github.com/Binequation/FileAnalysis?tab=readme-ov-file#features)

[Requirements](https://github.com/Binequation/FileAnalysis?tab=readme-ov-file#requirements)

[How to build & usage](https://github.com/Binequation/FileAnalysis?tab=readme-ov-file#how-to-build)

[Output](https://github.com/Binequation/FileAnalysis?tab=readme-ov-file#samples-of-output)

[Future plans](https://github.com/Binequation/FileAnalysis?tab=readme-ov-file#additional-features-future-plans)

# Features
- **Basic analysis**: 
    - *Word count.*
    - *Line count.*
    - *Character count.*
    - *Sentence length analysis (longest and shortest).*
    - *Avg word and sentence length.*

- **Advanced analysis:**
    - *Chart bar of word's frequency*
    - *Ability to export results to a CSV file.*

# Requirements 
- GCC 
- Make

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
./analyzer path_to_file/file.txt
```
2. *See a result. All results of analysis will be stored in* `your_output_path` *(optional). 

# Samples of output
*File is full:*

**INPUT**

``` sample.txt
Harry knew, when they wished him good luck outside the locker rooms the
next afternoon, that Ron and Hermione were wondering whether they'd ever
see him alive again. This wasn't what you'd call comforting. Harry
hardly heard a word of Wood's pep talk as he pulled on his Quidditch
robes and picked up his Nimbus Two Thousand.
```

- **Terminal output:**
``` Output
Word Count: 57
Line Count: 5
Character Count: 325
Longest Sentence Length (symbols amount except whitespace): 134
Shortest Sentence Length (symbols amount except whitespace): 31
Average Word Length: 4.56
Average Sentence Length: 108.67

Word Frequency Bar Chart:
harry                |######################################## (2)
knew                 |#################### (1)
when                 |#################### (1)
they                 |######################################## (2)
wished               |#################### (1)
him                  |######################################## (2)
good                 |#################### (1)
luck                 |#################### (1)
outside              |#################### (1)
the                  |######################################## (2)
...

Do you want to save your results of analysis? (y/n):
```

- **SCV output (optional):**
``` CSV
Type of output: Metric - Value

----RESULTS----

Word Count - 5
Line Count - 1
Character Count - 19
Longest Sentence Length (symbols amount except whitespace) - 0
Shortest Sentence Length (symbols amount except whitespace) - 0
Average Word Length - 3.00
Average Sentence Length - 0.00

---------------

Word Frequency Bar Chart:
harry                |######################################## (2)
knew                 |#################### (1)
when                 |#################### (1)
they                 |######################################## (2)
wished               |#################### (1)
him                  |######################################## (2)
good                 |#################### (1)
luck                 |#################### (1)
outside              |#################### (1)
the                  |######################################## (2)
...
```

*File is empty:*

**Terminal output**
``` Output
File is empty!
Status: Success
```

*File not found:*

**Terminal output**
``` Output
Error! Can't open file
Status: No such file or directory
```

*Output path isn't entered:*
``` Output
<...>
Do you want to save your results of analysis? (y/n): y
Where you want to save results? Enter the full path: 
Error creating file: No such file or directory
```

# Additional Features (Future Plans)
- **Text Summarization:** *Create a shortened version of the text that only includes the most crucial details.*

- **Plagiarism Checker:** *To find similarities, compare the text to a database of previously published texts.*

- [x] **Visualization:** *Create visual depictions of the text data, including word clouds or bar charts for word frequencies.*
