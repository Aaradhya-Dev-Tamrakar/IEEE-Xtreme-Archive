# Base K Xor

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/base-k-xor/](https://csacademy.com/contest/archive/task/base-k-xor/)  

---

Given $2$ numbers $a$ and $b$ ($a \leq b$) and a value $k$, print the digital sum in base $k$ of the  numbers $a,\ a+1\ ...\ b$.

Let's take two numbers $x=20$ and $y=14$ and compute their digital sum in base $k=3$. First we write the numbers in base $3$:

$x=202$$y=112$

Then we compute the sum of corresponding digits and discard all carry overs. The result (in base $3$) is $011$. The final step consists of converting the result to back to base $10$, so we get the desired answer $4$.

### Standard input

The first line contains a single integer $T$, representing the number of tests to follow.

Each of the next $T$ lines contains $3$ integers $a\ b\ k$.

### Standard output

Output $T$ lines, each containing a single integer representing the answer for a test.

### Constraints and notes

$1 \leq T \leq 5 * 10^4$$1 \leq a \leq b \leq 10^8$$2 \leq k \leq 10$ 

| Input | Output |
| --- | --- |
| 4<br>1 5 2<br>5 29 3<br>16 31 4<br>100 10000 7 | 1<br>5<br>0<br>16172 |
