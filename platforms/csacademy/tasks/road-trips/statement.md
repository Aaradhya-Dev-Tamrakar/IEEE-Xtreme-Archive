# Road Trips

**Time Limit:** `1500 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/road-trips/](https://csacademy.com/contest/archive/task/road-trips/)  

---

You are given a rooted tree with $N$ nodes. The root is always the node labeled with $1$, and the edges have associated costs representing their lengths.

There are $M$ kids that want to go on road trips. For each of them you know their speed $v_i$. Each kid starts in the root and finishes in one of the leaves. They start together, and if at any moment there are more of them that want to take the same edge they will go together as a group. The speed of the group is equal to the speed of its slowest member.

The energy spent for an edge is equal to its length multiplied by the speed of the kid or the group that traverses it. You should maximize the total sum of energy spent for all the edges that are traversed by at least one kid.

### Standard input

The first line contains two integers $N$ and $M$.

The second line contains $M$ integers representing the speed values of the kids.

Each of the next $N-1$ lines contains three integers $a\ b\ c$, representing an edge between nodes $a$ and $b$, having length $c$.

### Standard output

Print a single integer representing the maximum total energy.

### Constraints and notes

$2 \leq N \leq 10^5$ $1 \leq M \leq 18$$1 \leq c_i \leq 10^5$$1 \leq v_i \leq 10^5$The number of leaves in the tree is always $\leq M$

| Input | Output |
| --- | --- |
| 7 4<br>7 2 5 3<br>1 4 5<br>1 2 2<br>2 7 4<br>4 5 3<br>2 3 1<br>4 6 6 | 103 |
| 5 3<br>5 4 2<br>2 5 1<br>1 2 5<br>1 4 7<br>2 3 3 | 59 |
| 4 3<br>1 2 3<br>1 3 1<br>1 2 3<br>1 4 2 | 14 |
| 5 2<br>1 2<br>3 2 1<br>3 4 3<br>1 5 2<br>5 3 3 | 12 |
| 6 4<br>1 2 2 4<br>4 6 3<br>6 5 3<br>4 3 3<br>6 2 1<br>1 4 2 | 29 |
