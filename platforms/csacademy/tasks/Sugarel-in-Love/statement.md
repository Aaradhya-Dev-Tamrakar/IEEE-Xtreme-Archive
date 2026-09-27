# Sugarel in Love

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/Sugarel-in-Love/](https://csacademy.com/contest/archive/task/Sugarel-in-Love/)  

---

Sugarel has a new idea to make his girlfriend happy, beside reminders. Sugarina loves to travel and because he is short of money, he decided to sign up as a bus driver, so they can travel together as much as possible.

In his city, there are $N$ stations with $N-1$ bidirectional roads connecting them, such that between every two stations there is a single path. Everyday, he must choose a simple path to traverse with the bus, but he must never go through stations he has been in previous days.

Sugarel wants to drive as much as possible in order to be with his Sugarina, but as soon as no possible path exists, he will be fired. Your task is to find out the maximum total distance he can travel, by choosing conveniently the paths. This will give Sugarel time to come up with other ideas to save his relationship.

More formal, you must find a set of disjoint paths with maximum sum.

### Standard input

The first line contains one integer $N$, representing the number of stations.

Each of the following $N - 1$ lines contains three integer values $X Y Z$ meaning that there is a bidirectional road connecting station $X$ and station $Y$ of length $Z$.

### Standard output

The output should consist of a single value representing the maximum sum.

### Constraints and notes

$1 \leq N \leq 10^5$ $1\leq Z\leq 10^6$ $1 \leq X$, $Y \leq N$ 

| Input | Output |
| --- | --- |
| 8<br>1 2 1<br>1 3 8<br>2 4 6<br>3 5 4<br>3 6 1<br>6 7 3<br>6 8 7 | 29 |
