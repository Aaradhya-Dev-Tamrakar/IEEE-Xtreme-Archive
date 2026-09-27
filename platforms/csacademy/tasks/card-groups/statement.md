# Card Groups

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/card-groups/](https://csacademy.com/contest/archive/task/card-groups/)  

---

You are given $N$ cards, each of them has one side painted red and the other one blue, and each side has a number written on it.

You should divide the cards in two groups: for the first group you compute the sum of the numbers written on the red sides, for the second group the sum of the numbers written on the blue sides. The goal is to divide the cards in such a way that the two sums are equal. Every card should be part of a group.

If the solution is not unique, you want to minimize the absolute difference between the number of cards in the groups.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains two integers, representing the numbers written on the red and on the blue faces of a card.

### Standard output

If there is no solution such that the two sums are equal, output $-1$.

Otherwise, print $N$ binary values, each corresponding to a card: $0$ if the card is in the red group, $1$ if it's in the blue group.

### Constraints and notes

$1 \leq N \leq 40$ The numbers on the cards are integers between $0$ and $10^9$ If there are more solutions with equal sum and minimum absolute difference of group sizes, you can output any of them.

| Input | Output |
| --- | --- |
| 4<br>1 1<br>1 1<br>1 1<br>1 1 | 0011 |
| 3<br>1 2<br>1 1<br>1 1 | 100 |
| 2<br>100 100<br>90 90 | -1 |
