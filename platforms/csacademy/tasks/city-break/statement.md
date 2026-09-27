# City Break

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/city-break/](https://csacademy.com/contest/archive/task/city-break/)  

---

There are N cities on a circle, you know the distance between any two consecutive cities. You start in the city with index S, at every step you move to the closest city that was not previously visited (in case there is more than one closest city you choose the one with minimum index). What’s the distance you cover until you visit all the $N$ cities?

### Standard input

The first line contains two integers $N$ and $S$.

The second line contains $N$ integers, representing the distance between consecutive cities (the last number is the distance between cities $N$ and $1$)

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq S \leq N$  The distance between any $2$ consecutive cities is an integer between $1$ and $10^7$ The sum of distances is $\leq 10^8$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4 1<br>1 10 1 1 | 4 | Start at city $1$. visit city 1 traveling 0The closest city is city $2$ with a travel-distance of $1$ Note that city $4$ has a travel-distance of $1$ as well, but city $2$ has a smaller index. visit city 2 traveling 1The closest city is city $4$ with a travel-distance of $2$. visit city 4 traveling 2The closest and the only city that was not visited is city $3$ with a travel-distance of $1$. visit city 3 traveling 1 |
| 5 2<br>1 10 100 3 2 | 22 | Start at city $2$. visit city 2 traveling 0 visit city 1(2->1) traveling 1 visit city 5(1->5) traveling 2 visit city 4(5->4) traveling 3 visit city 3(4->5->1->2->3) traveling 16 |
| 6 4<br>11 3 1 1 5 21 | 39 | 11 3 1 1 5 21Start at city $4$. visit city 4 traveling 0 visit city 3(4->3) traveling 1 visit city 5(3->4->5) traveling 2 visit city 2(5->4->3->2) traveling 5 visit city 6(2->3->4->5->6) traveling 10 visit city 1 traveling 21there are $2$ ways to go from city $6$ to city $1$, both having a travel cost of $21$. |
