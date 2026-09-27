# Switch the Lights

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/switch-the-lights/](https://csacademy.com/contest/archive/task/switch-the-lights/)  

---

There are $N$ lightbulbs arranged in a line. For each of them you know whether it's turned on or off.

There are also $N$ light switches. The $i^{th}$ switch toggles the state of all the lightbulbs between $i$ and $R_i$, and it costs $C_i$ to use it.

Find the minimum total cost of switching off all the lightbulbs.

### Standard input

The first line contains a single integer $N$.

The second line contains a string of length $N$. The $i^{th}$ character of the string is 0 if initially the $i^{th}$ lightbulb is turned off, and 1 if it's turned on.

The third line contains $N$ integers representing the elements of $R$.

The fourth line contains $N$ integers representing the elements of $C$.

### Standard output

If there is no solution output $-1$.

Otherwise, print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $i \leq R_i \leq N$ $1 \leq C_i \leq 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1010<br>2 3 3 4<br>3 1 2 3 | 4 | 1010 Initial state of the lightbulbs1100 After toggling the $2$nd switch, changing lightbulbs $2\text{ and }3$  (cost $1$)0000 After toggling the $1$st switch, changing lightbulbs $1\text{ and }2$  (cost $3$) |
| 5<br>01100<br>1 2 3 4 5<br>1 5 5 2 3 | 10 | 01100 Initial state of the lightbulbs00100 After toggling the $2$nd switch, changing lightbulb $2$  (cost $5$)00000 After toggling the $3$rd switch, changing lightbulb $3$  (cost $5$) |
| 4<br>0101<br>3 4 3 4<br>1 1 1 1 | 2 | 0101 Initial state of the lightbulbs0111 After toggling the $3$rd switch, changing lightbulb $3$  (cost $1$)0000 After toggling the $2$nd switch, changing lightbulbs $2\text{, }3\text{ and } 4$  (cost $1$) |
