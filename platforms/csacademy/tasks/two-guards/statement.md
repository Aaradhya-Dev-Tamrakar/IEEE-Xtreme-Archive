# Two Guards

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/two-guards/](https://csacademy.com/contest/archive/task/two-guards/)  

---

Alex wants to rob a shop which is guarded by two people. The first guard comes to the shop each second day, while the second guard comes each third day. In the first day when the shop was opened both guards came to work.

Alex want to know the number of days in the interval $[A, B]$ when none of the two guards will come to work.

### Standard input

The first line contains two integers $A$ and $B$.

### Standard output

Print a single integer representing the number of days when the shop will not be guarded.

### Constraints and notes

$1 \leq A \leq B \leq 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 1 4 | 1 | The first guard comes to the shop in the days 1 and 3 while the second one in the days 1 and 4.In day 2 none of the guards will come to work. |
| 3 8 | 2 | The first guard comes to the shop in the days 3, 5, 7 while the second one in the days 4 and 7.In the days 6 and 8 none of the guards will come to work. |
