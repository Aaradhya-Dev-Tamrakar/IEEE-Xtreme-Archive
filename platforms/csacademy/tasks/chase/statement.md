# Chase

**Time Limit:** `3000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/chase/](https://csacademy.com/contest/archive/task/chase/)  

---

Tom the cat is chasing Jerry the mouse again! Jerry is trying to gain some advantage by running into crowds of pigeons, where it is harder for Tom to follow him. Conveniently, Jerry arrived to Central Park in Ljubljana. The park has $n$ statues, numbered $1...n$, and $n - 1$ non-intersecting passages connecting them in such a way that it is possible to reach any statue from any other statue by traversing the passages. Clustered tightly around each statue $i$ there are $p_i$ pigeons. Jerry has $v$ breadcrumbs in his pocket. If he drops a breadcrumb by a statue at his current location, pigeons from neighbouring statues will immediately fly to this statue to eat the breadcrumb. As a result the current number of pigeons $p$ around this and neighbouring statues changes.

It all happens in the following order: First, Jerry arrives to the statue $i$ and meets $p_i$ pigeons. Then, he drops the breadcrumb. He leaves the statue. The pigeons from neighbouring statues move to statue $i$ before Jerry arrives to the next statue (so they don’t count towards his count of the pigeons met).

Jerry may enter the park at any statue, run down some passages (but never using the same passage twice), and then leave the park anywhere he wants. After Jerry exits the park, Tom will enter and traverse exactly the same route. By dropping at most $v$ breadcrumbs, Jerry wants to maximize the difference between the number of pigeons Tom will meet on the route and the number of pigeons he meets. Note that only pigeons that are present at some statue right before Jerry arrives there count toward the total number of pigeons he meets. See the comment of the example for further explanation.

### Input

The first line contains the number of statues $n$ and number of breadcrumbs $v$. The second line contains $n$ integers separated with a space, $p_1...p_n$. The following $n-1$ lines describe the passages with pairs of numbers $a_i$ and $b_i$, which indicate there is a passage between statues $a_i$ and $b_i$.

### Output

Output only one number, maximum difference between the number of pigeons Tom meets and the number of pigeons Jerry meets.

### Constraints

$1 \leq n \leq 10^5$ $0 \leq v \leq 100$ $0 \leq p_i \leq 10^9$ 

### Subtask 1 (20 points)

$1 \leq n \leq 10$ 

### Subtask 2 (20 points)

$1 \leq n \leq 1\,000$ 

### Subtask 3 (30 points)

An optimal route begins at statue $1$.

### Subtask 4 (30 points)

No additional constraints.

| Input | Output | Explanation |
| --- | --- | --- |
| 12 2<br>2 3 3 8 1 5 6 7 8 3 5 4<br>2 1<br>2 7<br>3 4<br>4 7<br>7 6<br>5 6<br>6 8<br>6 9<br>7 10<br>10 11<br>10 12 | 36 | One possible solution is the following. Jerry enters the park at the statue $6$. There he encounters $5$ pigeons. He drops a breadcrumb. $p_6$ is now $27$ and $p_5 = p_7 = p_8 = p_9 = 0$. Next he runs to the statue $7$ and encounters $0$ pigeons. He drops the second breadcrumb. $p_7$ is now $41$ and $p_2 =p_4 =p_6 =p_{10} =0$. He exits the park. He encountered $5+0=5$ pigeons. Tom follows him over the same route but encounters $p_6 + p_7 = 0 + 41 = 41$ pigeons. The difference is $41 - 5 = 36$ |
