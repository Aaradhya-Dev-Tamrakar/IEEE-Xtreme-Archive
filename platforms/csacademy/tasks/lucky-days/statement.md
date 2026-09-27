# Lucky Days

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/lucky-days/](https://csacademy.com/contest/archive/task/lucky-days/)  

---

Alex has started playing poker and he discovered he is so good, that everyday he wins a certain amount of money. You are given an array $A$ of $N$ elements, where $A_i$ is the amount he won during the $i^{th}$ day.

Alex calls a day lucky if he wins strictly more money than in any of the previous days. Note that by this definition the first day is always lucky.

Find the total number of lucky days.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ positive integers, representing the elements of $A$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 100$ $1 \leq A_i \leq 100$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 7<br>1 5 2 3 4 5 7 | 3 | Days $1$, $2$ and $7$ are lucky. |
| 5<br>1 1 3 3 3 | 2 | Only days $1$ and $3$ are lucky. Notice the amount of money won in a lucky day should be strictly greater than those from the previous days. |
