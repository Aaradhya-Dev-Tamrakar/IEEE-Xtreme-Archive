# Divided Kingdom

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/divided-kingdom/](https://csacademy.com/contest/archive/task/divided-kingdom/)  

---

Tragedy in the kingdom of Nowhereland! The king has just been assassinated, and there is no one but its two children,  little Gică and his sister Gina, to rule the kingdom as his legacy!

The kingdom is a network of $N$ cities, some of which are connected by bidirectional roads of different lengths ($M$ in total). Gică and Gina will each be granted some of the $N$ cities (not necessarily the same number of cities). However, because the king's death has not been foreseen, there is no guarantee which child will receive which cities to rule. In other words, any valid assignment of cities to siblings is possible. The only known thing is that each city will be assigned to exactly one of the two siblings.

Because times are rough in Nowhereland,  an assignment is bad when the distance between the two closest cities ruled by the same sibling is big. Formally, for an assignment $f : \{1, .., N\} \rightarrow \{Gica, Gina\}$, we define $cost(f) = min\{dist(a, b) \mid 1 \leq a, b \leq N, a \neq b, f(a) = f(b)\}$. The distance between $a$ and $b$ is defined as the length of the shortest path between the two cities. If the two cities aren't connected, the distance is defined to be infinite.

Gina and Gică want to find how bad an assignment can be, in a worst-case scenario. In other words, they want to find $max_f (cost(f))$.

### Standard input

The first line contains two positive integers $N$ and $M$, the number of cities in Nowhereland, and the number of roads, respectively. Each of the next $M$ lines contains three positive integers $a$, $b$, and $c$, meaning that there is a bidirectional road of length $c$ connecting cities $a$ and $b$.

### Standard output

The first line of the output should contain one positive integer $X$, the minimum distance between two cities governed by the same sibling in the worst-case. If the number in the worst-case can be infinite, output $-1$.

### Constraints and notes

$1 \leq N \leq 10^5$$1 \leq M \leq 2.5 \cdot 10^5$$1 \leq a, b \leq N$$1 \leq c \leq 10^6$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 4<br>1 2 10<br>2 3 15<br>1 3 18<br>1 4 25 | 18 | In the worst scenario, Gina would end up getting cities $1$ and $3$, and Gică would end up getting cities $2$ and $4$. The maximum distance is, therefore, $dist(1, 3) = 18$. |
| 2 1<br>1 2 100 | -1 | If Gică and Gina get one city each, then the distance between two different cities would be infinite both for Gică and Gina, so the answer is $-1$. |
