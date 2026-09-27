# IOI Selection

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/ioi-selection/](https://csacademy.com/contest/archive/task/ioi-selection/)  

---

The IOI selection in Romania is now based off of $4$ stages. Each stage consists of $3$ problems and all problems are graded with points from $0$ to $100$. The score for a stage is the sum of points accumulated in the $3$ problems.

In the $4^{\text{th}}$ stage there are only $16$ students left. The first $4$ students with the greatest total score will represent Romania at the International Olympiad in Informatics.

After the first $3$ stages, given their scores in non-increasing order, find out how many of them have a chance at qualifying for IOI?

### Standard input

The input contains $16$ integers, representing the array $S$ of scores.

### Standard output

Print the answer on the first line.

### Constraints and notes

$0 \leq S_i \leq 900$ $S_i \geq S_{i+1}$ for $1 \leq i < 16$ On ties, the one with the greatest score in the first $3$ stages is selected 

| Input | Output | Explanation |
| --- | --- | --- |
| 743 643 530 515 475 441 433 429 423 380 339 273 270 254 253 197 | 15 |  |
| 603 602 601 600 300 300 300 300 300 300 300 300 300 300 300 300 | 4 | For the 5th participant, even if he scores 300 points and all others will score 0 points, he will not qualify for IOI since the tiebreaker is determined by the place after the 3rd round. |
| 869 854 809 680 660 583 582 517 461 290 230 168 140 133 108 14 | 9 |  |
