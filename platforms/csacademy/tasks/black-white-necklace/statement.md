# Black White Necklace

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/black-white-necklace/](https://csacademy.com/contest/archive/task/black-white-necklace/)  

---

You have a necklace with $N$ black and white marbles. You can swap the positions of any two marbles. What's the minimum number of swaps needed to bring all the white (and black) marbles on consecutive positions?

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers corresponding to initial necklace. A white marble is represented by $0$, while a black one by $1$. Note that the array is circular.

### Standard output

Print a single integer representing the minimum number of swaps needed.

### Constraints and notes

$1 \leq N \leq 10^5$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 8<br>1 0 0 1 1 0 0 1 | 2 | $1\ 0\ 0\ 1\ 1\ 0\ 0\ 1$$\underline{0}\ 0\ \underline{1}\ 1\ 1\ 0\ 0\ 1$$0\ 0\ 1\ 1\ 1\ \underline{1}\ 0\ \underline{0}$ |
| 5<br>1 0 0 1 0 | 1 | $1\ 0\ 0\ 1\ 0$$\underline{0}\ 0\ 0\ 1\ \underline{1}$ |
| 6<br>0 0 1 0 1 0 | 1 | $0\ 0\ 1\ 0\ 1\ 0$$0\ \underline{1}\ 1\ 0\ \underline{0}\ 0$ |
