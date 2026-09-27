# Max Substring

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/max-substring/](https://csacademy.com/contest/archive/task/max-substring/)  

---

You are given a string $S$. Find a string $T$ that has the most number of occurrences as a substring in $S$.

If the solution is not unique, you should find the one with maximum length. If the solution is still not unique, find the smallest lexicographical one.

### Standard input

The first line contains string $S$.

### Standard output

Print string $T$ on the first line.

### Constraints and notes

$S$ consists of lowercase letters of the English alphabetThe length of $S$ is between $1$ and $10^5$ 

| Input | Output | Explanation |
| --- | --- | --- |
| cabdab | ab | a, b and ab appear $2$ times, but ab is bigger. There're no other substrings that appear more than once. |
| cabcabc | c | c appears $3$ times while a, b, ab,ca, bc,  abc and cab appear only $2$ times. |
| ababababab | ab | Note that we're interested in substrings(continuous) not subsequences.ab is the winner with $5$ appearances. |
