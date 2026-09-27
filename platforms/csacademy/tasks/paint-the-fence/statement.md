# Paint the Fence

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/paint-the-fence/](https://csacademy.com/contest/archive/task/paint-the-fence/)  

---

You have a fence with $N$ boards. There are $M$ painters, and each of them will paint a subarray of boards.

More specifically the $i^{\text{th}}$ painter will paint the boards $L_i, L_i + 1, L_i + 2, ..., R_i$. Subarrays of different painters may overlap.

For each painter,find the number of boards that would remain unpainted if we ignore his work.

### Standard input

The first line contains two integers $N$ and $M$.

The next $M$ lines contain two integers $L_i$ and $R_i$.

### Standard output

Print $M$ lines in the output.

The $i^{\text{th}}$ line will contain an integer, the number of boards that would remain unpainted if we were to ignore $i^{\text{th}}$'s contribution.

### Constraints and notes

$1 \leq N, M \leq 10^5$ $1 \leq L_i \leq R_i \leq N$ for every $1 \leq i \leq M$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 3<br>1 3<br>4 5<br>3 4 | 2<br>1<br>0 | If we ignore the first painter's work boards $1$ and $2$ will remain unpainted.For the second painter board $5$ will remain unpainted.For the third painter all boards will remain painted (boards $1, 2$ and $3$ painted by the first painter and boards $4$ and $5$ by the second one) |
| 6 2<br>1 2<br>4 5 | 4<br>4 | If we ignore the first painter's work, boards $1, 2, 3$ and $6$ will be unpainted. Note that boards $3$ and $6$ are unpainted and will be counted for both the first and the second painter. |
| 9 4<br>2 9<br>3 4<br>4 5<br>1 4 | 4<br>0<br>0<br>1 |  |
