# Candles

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/candles/](https://csacademy.com/contest/archive/task/candles/)  

---

You have $N$ candles, for each candle $i$ you know its height $h_i$. Using a candle during one evening decreases the candle height by $1$.

You plan to have at most $M$ romantic evenings. For each evening $i$ you know the number of candles $c_i$ you want to lit. Find of strategy of lighting the candles in order to maximize the number of evenings you can spend. You are forced to stop after the first night $i$ when you can't light $c_i$ candles.

### Standard input

The first line contains two integers $N$ and $M$.

The second line contains $N$ integers representing the initial heights of the candles.

The third line contains $M$ integers representing the number of candles you want to lit each evening.

### Standard output

Print a single integer representing the maximum number of evening you can spend, satisfying the candle requirements.

### Constraints and notes

$1 \leq N, M \leq 10^5$ $1 \leq h_i \leq 10^5$ $1 \leq c_i \leq 10^5$  

| Input | Output | Explanation |
| --- | --- | --- |
| 3 5<br>1 2 5<br>1 2 3 2 1 | 3 | One way spend $3$ romantic evenings would be:* the lit candles are undelined$1\ 2\ 5$ - before evening 1$1\ 2\ \underline{4}$ - after evening 1$1\ \underline{1}\ \underline{3}$ - after evening 2$\underline{0}\ \underline{0}\ \underline{2}$ - after evening 3Note that you can't satisfy the requirements for evening $4$, the answer is $3$. Even thou you can satisfy evening $5$, you must spend the evenings in order . |
| 5 5<br>1 3 3 4 5<br>1 2 4 4 4 | 5 | $1\ 3\ 3\ 4\ 5$$\underline{0}\ 3\ 3\ 4\ 5$$0\ 3\ 3\ \underline{3}\ \underline{4}$$0\ \underline{2}\ \underline{2}\ \underline{2}\ \underline{3}$$0\ \underline{1}\ \underline{1}\ \underline{1}\ \underline{2}$$0\ \underline{0}\ \underline{0}\ \underline{0}\ \underline{1}$ |
