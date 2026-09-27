# Fold

**Time Limit:** `400 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fold/](https://csacademy.com/contest/archive/task/fold/)  

---

Consider a roll of $N$ paper towels. The roll is unrolled on the floor and its towels are numbered from $1$ to $N$, from left to right. We then perform several folding operations. Specifically, a fold at position $p$ consists of lifting all the towels to the right of the $p$-th towel and flipping them leftwards. For example, if $N = 7$, then a fold at position 2 looks like:

BeforeAfter1 2 3 4 5 6 7_ _ _ 4 3  7 6 5 1 2

Note that fold positions refer to the towels touching the floor, not necessarily to the numbers on them. For example, if we now perform a fold at position 2, the result is:

BeforeAfter_ _ _ 4 3  7 6 5 1 2_ 1 _  2 4 5  3 7 6

Folding can also occur at position 0. In that case we flip over the entire roll.

### Task

You are given the initial length of the towel, $N$, and $M$ folding operations to perform. You must print various details about the final configuration of the paper towels.

### Standard input

The first line contains two integers $N$ and $M$, representing the length of the roll and the number of operations to perform. Each of the following $M$ lines contains one integer, the position of the fold.

### Standard output

The first line should contain the numbers on the towels making up the tallest stack, from bottom to top. If multiple stacks exist with the same maximum height, print the contents of the leftmost stack.The second line should contain the numbers on the towels touching the floor, from left to right.The third line should contain the numbers on the towels visible from above, from left to right.

### Constraints and notes

$1 \leq N \leq 10^6$ $1 \leq M \leq 10^6$ $0 \leq p < L$ for every fold operation at position $p$, where $L$ is the remaining length of the roll at the time of the fold.

### Subtasks

Test cases will be scored individually.

| Subtask | Percentage of test cases | Additional input constraints |
| --- | --- | --- |
| 1 | 20% | $N, M \leq 10^3$ |
| 2 | 40% | $10^3 < N, M \leq 10^5$ |
| 3 | 40% | none |

### Examples

| Input | Output | Explanation |
| --- | --- | --- |
| 8 3<br>6<br>1<br>2 | 7 6 3<br>2 7 8<br>1 3 4 | The initial layout is1 2 3 4 5 6 7 8After the first operation the layout is_ _ _ _ 8 71 2 3 4 5 6After the second operation the layout is6 5 _ _ 27 8 4 3 1After the third operation the layout is_ 3 41 6 52 7 8 |
