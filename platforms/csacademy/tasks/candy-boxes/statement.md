# Candy Boxes

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/candy-boxes/](https://csacademy.com/contest/archive/task/candy-boxes/)  

---

You have $N$ boxes, each of them containing some candy. There are $M$ events of two types:

type $1$: take a candy from box $X$. Box $X$ mush have at least one candy.type $2$: you receive a candy. You need to chose in which box to put the candy.

For each event of type $2$ figure out in which box to put the candy so all operations of type $1$ are valid.

Note that the events are given in chronological order.

### Standard input

The first line contains 2 integers $N$ and $M$.

The second line contains $N$ integers representing the initial amount of candy in each box.

The next $M$ lines describe the events. Each line contains the integer $T$ which represents the type of the event. If $T = 1$ the line contains another integer $X$ representing the box number from which you must take the candy from.

### Standard output

Print $X$ lines, where $X$ is the number of events of type $2$.

Each line should contain an integer $(1 \leq V \leq N)$ representing the box in which you chose to put the candy into.

Note that you don't need to print $X$.

### Constraints and notes

it's guaranteed that there always exists a valid solution $1 \leq N \leq 10^5$ $1 \leq M \leq 10^5$ for operations of type $1$ it's guaranteed that $1\leq X \leq N$ let $A_i$ be the initial amount of candy in box $i$. $0 \leq A_i \leq 10^5$ it's guaranteed that there'll be at least one event of type $2$

| Input | Output |
| --- | --- |
| 3 7<br>1 2 1<br>1 1<br>2<br>2<br>1 1<br>1 3<br>1 2<br>1 3 | 3<br>1 |
| 4 5<br>1 1 1 1<br>2<br>1 1<br>1 2<br>1 3<br>1 4 | 3 |
| 2 11<br>1 1<br>2<br>2<br>1 1<br>1 1<br>1 2<br>2<br>1 2<br>2<br>1 1<br>1 1<br>2 | 1<br>2<br>1<br>1<br>1 |
