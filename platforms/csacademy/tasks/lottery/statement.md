# Lottery

**Time Limit:** `3000 ms`  
**Memory Limit:** `32 MB`  
**Source:** [https://csacademy.com/contest/archive/task/lottery/](https://csacademy.com/contest/archive/task/lottery/)  

---

For a long long time you have been a big fan of Bytelotto. For around the same time, the members of your family have been telling you that all such games are a waste of money. You are sure that it is because of their lack of skill! You have a brilliant plan and everyone will see you winning the game soon.

There are many types of games. You are interested in one of them: Bitlotto. The choice was simple, as it is the easiest offered type of game: on each day exactly one number is drawn at random. You took notes the results of draws in $n$ consecutive days and obtained a sequence $a_1, a_2, ..., a_n$. You are sure that there is some pattern in this sequence, especially in intervals of $l$ consecutive days. Your family still does not believe you, so the only way to convince them is to use solid math.

There are $n - l + 1$ intervals of days of length $l$. The $i$-th interval starts at position $i$, so it contains elements $a_i, a_{i+1}, ..., a_{i+l-1}$. The distance between two intervals is the number of mismatches on their corresponding positions. In other words, for the $x$-th and the $y$-th interval it is the number of positions $i$ ($0 \le i < l$) such that $a_{x+i}$ and $a_{y+i}$ are different. Finally, we define two intervals to be $k$-similar if their distance is at most $k$.

There is a fixed sequence and an integer $l$. You are given $q$ queries. In every query, you are given an integer $k_j$ and for each of the $n - l + 1$ intervals you must find the number of intervals of the same length that are $k_j$-similar to this interval (not counting this interval itself).

### Standard input

The first line contains two space-separated integers $n$ and $l$, the number of days and the length of the analysed intervals.

The second line contains $n$ space-separated integers $a_1, a_2, \ldots, a_n$, where $a_i$ is the number that was drawn on the $i$-th day.

The third line contains an integer $q$, the number of queries. Each of the next $q$ lines contains an integer $k_j$, the similarity parameter for the $j$-th query.

### Standard output

Print $q$ lines. The $j$-th line should contain $n - l + 1$ space-separated integers that are the answer to the $j$-th query. The $i$-th number in a line should be the number of other intervals that are $k_j$-similar to the $i$-th interval.

### Constraints and notes

$1 \le l \le n \le 10\,000$ $1 \le q \le 100$ $1 \le a_i \le 10^9$ $0 \le k_j \le l$ 

### Subtasks

SubtaskAdditional constraintsNumber of points1$n \le 300$$25$2$n \le 2000$$20$3$q=1$, $k_1=0$$20$4$q=1$$15$5no additional constraints$20$

| Input | Output | Explanation |
| --- | --- | --- |
| 6 2<br>1 2 1 3 2 1<br>2<br>1<br>2 | 2 1 1 1 1 <br>4 4 4 4 4 | There are two queries.The first query has $k = 1$. The first and the third interval --- 1 2 and 1 3 --- differ only on the second position, so the distance between them is $1$. Similarly, the first and fourth interval --- 1 2 and 3 2 --- differ only on the first position, so the distance is $1$. These are the only two intervals that are $1$-similar to the first interval, so the first printed number is $2$.In the second query we are given $k = 2$. All pairs of intervals are $2$-similar. |
