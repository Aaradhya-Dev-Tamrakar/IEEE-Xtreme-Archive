# Water Volume

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/water-volume/](https://csacademy.com/contest/archive/task/water-volume/)  

---

Alex has a glass that initially contains some quantity of water (it's possible that the glass is empty). He performs $N$ operations of two types:

Pour $x$ ml (millilitres) of water in the glassDrink $x$ ml of water from the glass

Alex writes down on a piece of paper the initial quantity of water. After each operation he writes down another number, representing the new volume of water in the glass. In total there will be $N+1$ numbers.

You know that the lowest number written by Alex is $0$. Find the largest one.

### Standard input

The first line contains a single integer $N$, the number of operations.

Each of the next $N$ lines contains two integers $t$ and $x$. If $t = 0$ Alex pours $x$ ml in the glass, if $t = 1$ he drinks $x$ ml.

### Standard output

Print the answer, expressed in ml, on the first line.

### Constraints and notes

$1 \leq N \leq 1\,000$ $1 \leq x_i \leq 1\,000$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>0 1<br>0 1<br>0 1<br>1 3 | 3 | The glass initially has $0$ml of water. The maximum value is obtained after the first $3$ operations. |
| 2<br>1 15<br>1 24 | 39 | The glass initially has $39$ml of water, and this is also the maximum value. |
