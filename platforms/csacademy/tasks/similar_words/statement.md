# Similar Words

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/similar_words/](https://csacademy.com/contest/archive/task/similar_words/)  

---

You are given a special word $S$ and a set of other $N$ words. We call a word $W$ from the set similar to $S$ if it's identical to $S$ or if $S$ can be obtained from $W$ by:

changing one characteradding one characterdeleting one character

Compute the number of words similar to $S$.

### Standard input

The first line contains one integer value $N$.

The second line contains the special word $S$.

Each of the next $N$ lines contains one word from the set.

### Standard output

The output should contain a single value representing the number of words in the set that are similar to $S$.

### Constraints and notes

$1 \leq N \leq 10^5$The length of the special word is between $1$ and $10^5$The sum of lengths of the words is $\leq 10^5$All the words contain only lower case letters of the English alphabet.

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>abcd<br>afcd<br>abd<br>aqqd<br>abgcd | 3 | $S$ can be obtained from the first word by changing the second letter, from the second word by inserting letter $c$ and the fourth word by erasing the letter $g$. The third word is not similar to $S$. |
| 15<br>wikoxhcjaxayigr<br>hvgftvvbjllioqcd<br>lcobszwawmrl<br>wikoxhccjaxayigr<br>wikkxhcjaxayigr<br>wikoxhcjaxayigrq<br>hkoggwmbcvqs<br>wikoxhcjaxaykgr<br>wikoxhvjaxayigr<br>wikoxhceaxayigr<br>oatmqkbfllxymw<br>wikoxhjaxayigr<br>fnirsuluiylhas<br>wiroxhcjaxayigr<br>wikixhcjaxayigr<br>wiktoxhcjaxayigr | 10 | <p></p> |
