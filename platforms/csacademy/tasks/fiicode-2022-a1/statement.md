# Awesome Atek

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fiicode-2022-a1/](https://csacademy.com/contest/archive/task/fiicode-2022-a1/)  

---

We all heard about Cookie Monster and his immense appetite for cookies. Wanting to test his limits, he leads $t$ experiments. Every experiment takes place over $n$ days in which he intends to eat a total of $s$ cookies. Cookie Monster owns boxes in which he can place at least one and at most $m$ cookies.

In the first day, he eats exactly one box of cookies. In order to exceed his limits, he plans to eat, in each of the next $n - 1$ days, one more box of cookies than in the previous day. It is worth mentioning that all the boxes he eats in one day must contain the same number of cookies.

You must help Cookie Monster by telling him if there is a way in which he can choose cookies and place them in boxes, such that, at the end of the experiment, he would have eaten exactly $s$ cookies.

### Input

The first line of the input contains one integer $t$ – the number of experiments Monster Cookie will lead. The following $t$ lines contain the description of every experiment.

Every experiment is described by three integers $n$, $m$ and $s$, representing the number of days for this experiment, the maximum number of cookies that can be placed in a box and the total number of cookies that he intends to eat during this experiment.

### Output

For every experiment, you must print $1$ if there exists a way to make the experiment successful or $0$ otherwise.

### Constraints

$1 \le t \le 10^5$ $1 \le n, m, s \le 10^{18}$

| Input | Output | Explanation |
| --- | --- | --- |
| 6<br>5 1 14<br>5 1 15<br>5 1 16<br>4 4 25<br>100 10000 10000000<br>9876543210 123456789 1000000000000000000 | 0<br>1<br>0<br>1<br>1<br>0 | The first three experiments require $5$ days to finish and there can be placed only one cookie in every box. Following the calculation, the total number of cookies that were eaten in those $5$ days is equal to $15$. Thus, only the second experiment turned out to be successful.For the fourth experiment, the only possible way is to put $3$ cookies in the box for the first day, $1$ cookie in each of the two boxes for the second day, $4$ cookies in each of the three boxes for the third day and $2$ cookies in each of the four boxes for the fourth day ($1 \cdot 3 + 2 \cdot 1 + 3 \cdot 4 + 4 \cdot 2 = 25$). |
