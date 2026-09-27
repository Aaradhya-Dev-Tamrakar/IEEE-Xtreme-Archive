# Final B

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/final-b/](https://csacademy.com/contest/archive/task/final-b/)  

---

### Statement

Paul is a big fan of pizza (I mean, who doesn't love pizza anyway?). But in order to make the best sauce, he needs to boil it a number of times. He learned this recipe from his great-grandfather, who used a rather weird, but effective, formula.

His great-grandfather took a positive number $N_0$ and a positive integer $K$. He would start by computing a new number $N_1$, equal to $N_0+(N_0 \text{ mod } 100)$. Continuing on, he would compute $N_2 = N_1 + (N_1 \text{ mod } 100)$, and so on. The secret formula says that the number of times that the sauce must be bolied is exactly equal to $N_K$.

Help Paul compute this number.

### Standard input

On the first line there is a positive integer $T$, the number of tests for which you need to compute the number of times the sauce must boil.

In the next $T$ lines, there will be two positive integers, $N_0$ and $K$, the values from the statement.

### Standard output

For every test case, output one line with a positive integer, the number of times the sauce must boil.

### Constraints and notes

$1 \le T \le 500$ $1 \le N_0 \le 10^9$ $1 \le K \le 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>31102014 2<br>10101 10 | 31102056<br>10324 | For the first test:$N_0=31102014$<br><br>$N_1=31102014+(31102014 \text{ mod } 100)=31102028$<br><br>$N_2=31102028+(31102028 \text{ mod } 100)=31102056$ |
