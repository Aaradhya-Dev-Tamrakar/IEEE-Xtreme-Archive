# Build the Fence

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/build-the-fence/](https://csacademy.com/contest/archive/task/build-the-fence/)  

---

You have $N$ wooden boards, having the same width, but different heights. You can take any wooden board and cut in two, as long as the resulting two wooden boards have integer heights. The cut can only be performed horizontally, so the two resulting boards will have the same width as the initial one.

Your goal is to build a fence consisting of $K$ boards, all having the same height. What's the maximum height of the boards in the fence?

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $N$ integers representing the initial heights of the $N$ wooden boards.

### Standard output

If there is no solution, output $0$.

Otherwise, print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq K \leq 10^{14}$ The heights are integers between $1$ and $10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3 4<br>15 10 8 | 7 | Cut the boards the following way:$15->7, 7, 1$$10->7, 3$$8->7, 1$This way, there are $4$ boards of height $7$ which can be used to build a fence of maximum height. |
| 3 5<br>1 1 1 | 0 | Note that there's no solution, so the answer is $0$. |
| 3 1<br>10 10 10 | 10 | Any board can be used to build a fence. |
| 3 4<br>100 5 10 | 25 | Cut the board of height $100$ into $4$ boards of height $25$. |
