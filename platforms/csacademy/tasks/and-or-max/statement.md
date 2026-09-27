# And or Max

**Time Limit:** `1500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/and-or-max/](https://csacademy.com/contest/archive/task/and-or-max/)  

---

You are given a sequence of $N$ integers, $A$. You are also given $Q$ queries:

1 L R X for every $L \leq i \leq R$, $A_i := A_i \land X$, where $\land$ is the bitwise and operator. 2 L R X for every $L \leq i \leq R$, $A_i := A_i \lor X$, where $\lor$ is the bitwise or operator. 3 L R  print $\text{max}(A_L, A_{L + 1}, ..., A_{R})$ 

### Standard input

On the first line there are two integers, $N$ and $Q$.

On the second line there are $N$ integers, representing $A$.

On the next $Q$ lines there will be queries, described as above.

### Standard output

For every query of type $3$ print the answer of a separate line.

### Constraints and notes

$1 \leq N \leq 2 * 10^5$ $1 \leq Q \leq 2 * 10^5$ $0 \leq A_i, X < 2^{20}$ $1 \leq L \leq R \leq N$  

| Input | Output | Explanation |
| --- | --- | --- |
| 5 8<br>1 3 2 5 4<br>3 1 3<br>2 1 1 5<br>3 1 3<br>1 1 4 6<br>2 3 4 1<br>3 2 3<br>2 2 3 4<br>3 1 5 | 3<br>5<br>3<br>7 | $1\ 3\ 2\ 5\ 4\$ $\text{Query}$ on interval $[1, 3]$$5\ 3\ 2\ 5\ 4\$ $OR$ on interval $[1, 1]$ with value $5$$5\ 3\ 2\ 5\ 4\$ $\text{Query}$ on interval $[1, 3]$$4\ 2\ 2\ 4\ 4\$ $AND$ on interval $[1, 4]$ with value $6$$4\ 2\ 3\ 5\ 4\$ $OR$ on interval $[3, 4]$ with value $1$$4\ 2\ 3\ 5\ 4\$ $\text{Query}$ on interval $[2, 3]$$4\ 6\ 7\ 5\ 4\$ $OR$ on interval $[2, 3]$ with value $4$$4\ 6\ 7\ 5\ 4\$ $\text{Query}$ on interval $[1, 5]$ |
