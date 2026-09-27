# Alex Counts

**Time Limit:** `500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/alex-counts/](https://csacademy.com/contest/archive/task/alex-counts/)  

---

### Statement

Paul really enjoys deck building card games. He enjoys them so much, that in every game he reaches the final act, and then he smiles before beating the boss.

This time, he got in a little bit of trouble, so he needs your help. In hand, he's got $N$ cards, every card having a power ability. In order to beat this boss, he needs to do a combo with $3$ cards that he's got in hand. More formally, he needs to choose $3$ cards, such that the power of the first one is equal to the power of the second one multiplied by the power of the third one.

Can you help him compute the number of ways of beating the final boss?

(Note 1: those $3$ cards must be different, and the second one from the combo must appear before the third one).

(Note 2: a combo is different from another combo if the first one has at least a card that is not included in the second combo and viceversa).

### Standard input

On the first line is a natural number $N$ and on the second line are $N$ natural numbers separated by a space.

### Standard output

Display a single number - how many combos can Paul make in order to beat the boss.

### Constraints and notes

$1 \le n \le 2*10^5$ $1 \le A[i] \le 10^6$ (where $A[i]$ denotes the power of the $i$-th card, with $i$ between $1$ and $N$)

| Input | Output | Explanation |
| --- | --- | --- |
| 7<br>8 9 2 4 2 3 6 | 4 | Consider the numbers indexed from 1.The 4 sets are: $\{7,5,6\}$ , $\{7,3,6\}$, $\{1,3,4\}$ și $\{1,4,5\}$. $A[$7$]$ $=$  $A[5]$  $\cdot$ $A[6]$   ($6$ $=$ $2$ $\cdot$ $3$ and $5 < 6$), $A[$7$]$ $=$  $A[3]$  $\cdot$  $A[6]$   ($6$ $=$ $2$ $\cdot$ $3$ and $3 < 6$), $A[$1$]$ $=$  $A[3]$  $\cdot$ $A[4]$   ($8$ $=$ $2$ $\cdot$ $4$ and $3 < 4$), $A[$1$]$ $=$  $A[4]$  $\cdot$  $A[5]$   ($8$ $=$ $4$ $\cdot$ $2$ and $4 < 5$). |
