# Travel Distance

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/travel-distance/](https://csacademy.com/contest/archive/task/travel-distance/)  

---

Alex has decided to go on a new adventure. Initially, we can consider he is situated at coordinates $(0, 0)$. At each step, he will move $1$ unit in one of the four cardinal directions, denoted by $N$, $E$, $S$ and $W$.

Find the Manhattan distance between his final position and the starting one.

### Standard input

The first line contains a string representing Alex's moves. The string will contain only the characters $N$, $E$, $S$ or $W$.

### Standard output

Print the answer on the first line.

### Constraints and notes

The length of the input string will be between $1$ and $1\,000$.

| Input | Output |
| --- | --- |
| NES | 1 |
| SSSEEE | 6 |
| NSEW | 0 |
| NWNSSSWNW | 3 |
