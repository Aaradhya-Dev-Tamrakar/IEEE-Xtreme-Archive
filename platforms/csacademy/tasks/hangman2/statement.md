# Hangman 2

**Time Limit:** `350 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/hangman2/](https://csacademy.com/contest/archive/task/hangman2/)  

---

John likes to play Hangman, the word guessing game. Today, however, he got really mad at the game. He arrived at the configuration spi_e, where finding the solution requires pure luck (solutions include spice, spike, spine and spire).

John is frustrated and argues that some words should never be chosen initially, namely words that differ from other words by at most two letters.

### Task

Given a list of $N$ words, all of length $K$, determine the words from which no other word can be obtained by substituting at most two letters.

### Clarification

Unlike classic Hangman, in this problem when John guesses a letter only one instance of the letter is revealed. For example, spi_e could hypothetically resolve to spise, whereas in classic Hangman guessing s would reveal both s's, so spi_e would be an invalid configuration.

### Standard input

The first line contains an integer $T$, the number of tests. The $T$ tests follow. Each of them has the following structure:

The first line contains two integer numbers $N$ and $K$.Each of the following $N$ lines contains a word of $K$ small English letters.

### Standard output

For each of the $T$ tests print one line with the following structure:

A sequence of $N$ characters: the $i^{th}$ charater is 1 if the $i^{th}$ word can be obtained by substituting at most two letters from another or 0 if not and can be played in the game.

### Constraints and notes

$1 \leq T \leq 10$ $1 \leq N \cdot K \leq 3 \cdot 10^4$

| Subtask | Percentage of test cases | Additional input constraints |
| --- | --- | --- |
| 1 | 10% | $1 \leq T \leq 10$  $1 \leq N \cdot K \leq 3 \cdot 10^3$ |
| 2 | 90% | none |

| Input | Output | Explanation |
| --- | --- | --- |
| 1<br>7 5<br>spike<br>speed<br>choir<br>spine<br>chair<br>chore<br>spire | 1011111 | We have the following related words:spike, spine and spire differ only in the fourth letter;chair and choir differ only in the third letter;choir and chore differ in the fourth and fifth letter.The only word that isn't similar with any other is: speed. |
