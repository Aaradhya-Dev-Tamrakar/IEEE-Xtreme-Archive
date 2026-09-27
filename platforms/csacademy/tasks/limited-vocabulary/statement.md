# Limited Vocabulary

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/limited-vocabulary/](https://csacademy.com/contest/archive/task/limited-vocabulary/)  

---

You are given a list of $N$ words consisting of lower case letters of the English alphabet. Find the longest word that contains at most $K$ distinct letters.

### Standard input

The first line contains two integers $N$ and $K$.

Each of the next $N$ lines contains one of the words.

### Standard output

Print the length of the longest word containing at most $K$ distinct letters, or $-1$ if there is no solution.

### Constraints and notes

$1 \leq N \leq 100$ $1 \leq K \leq 26$ Any word consists of at most $100$ characters

| Input | Output | Explanation |
| --- | --- | --- |
| 3 2<br>abba<br>abccbaabc<br>baaab | 5 | baaab is the longest word which contains at most $2$ distinct characters. |
| 5 5<br>kayak<br>analysis<br>home<br>queue<br>dequeue | 7 | dequeue is the longest word which contains at most $5$ distinct characters. |
| 4 3<br>house<br>brick<br>fence<br>window | -1 | All the words have at least $4$ distinct characters. |
