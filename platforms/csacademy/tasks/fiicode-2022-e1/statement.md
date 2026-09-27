# Empowering Atek

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fiicode-2022-e1/](https://csacademy.com/contest/archive/task/fiicode-2022-e1/)  

---

As you all know, Paftenie is a big gamer. Today, he is playing MLC (Mo's Life Course), a game in which he controls a robot named Mo. The playground is a grid consisting of $m$ rows and $n$ columns. The rows are numbered from $1$ to $m$ from top to bottom and the columns are numbered from $1$ to $n$ from left to right.

At each step, Mo can move one cell down or one cell to the right, because the other two arrows in Paftenie's keyboard are broken. In other words, from cell $(i, j)$, he can move either to $(i + 1, j)$ or to $(i, j + 1)$, as long as he doesn't exit the grid. Some cells are filled with obstacles, so Mo must avoid them.

Each of the other cells contains a certain amount of coins, between $1$ and $9$. Mo starts in cell $(1, 1)$ and his goal is to reach cell $(m, n)$ while collecting a maximum amount of coins. But there's a secret in this game that only Paftenie knows about. There are certain combinations of keys that, when executed, bring an amount of coins equal to their length. For example, each time Mo's algorithm follows the sequence of keys ↓↓→↓→, Paftenie would win $5$ coins.

### Input

The first line of the input contains the numbers $m$ and $n$, representing the dimensions of the grid.

The following $m$ lines describe the structure of the grid. Each of them contains $n$ integers between $0$ and $9$, which are not separated by spaces. The value $0$ represents a cell with obstacles, while a value greater than $0$ represents the amount of coins in that cell.

The next line contains the number $k$, representing the number of secret key combinations that bring bonus coins to Paftenie.

Each of the next $k$ lines contains one of those combinations, in the form of a string consisting only of the characters d (for arrow-down) and r (for arrow-right).

### Output

The output contains a single integer, namely the maximum amount of coins Paftenie can end the game with. If he cannot reach cell $(m, n)$, you will instead print $-1$.

### Constraints

$1 \le m, n \le 100$ $1 \le k \le 10$ The elements of the grid are integers between $0$ and $9$.Each of the $k$ strings has a length between $1$ and $20$.

| Input | Output | Explanation |
| --- | --- | --- |
| 4 7<br>1111111<br>0111111<br>1100111<br>1111111<br>2<br>rd<br>d | 19 | $\begin{pmatrix} \textcolor{red}{1} & \textcolor{red}{1} & 1 & 1 & 1 & 1 & 1\\ 0 & \textcolor{red}{1} & \textcolor{red}{1} & \textcolor{red}{1} & \textcolor{red}{1} & 1 & 1\\ 1 & 1 & 0 & 0 & \textcolor{red}{1} & \textcolor{red}{1} & 1\\ 1 & 1 & 1 & 1 & 1 & \textcolor{red}{1} & \textcolor{red}{1} \end{pmatrix}$ |
