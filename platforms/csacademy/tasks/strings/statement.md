# Strings

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/strings/](https://csacademy.com/contest/archive/task/strings/)  

---

### Description

You have an initial string $S = [s_1, ..., s_n]$.

By definition, $S_{x,y}$ is a part of string $S$ as follows:

$S_{x,y} = [s_x, ..., s_y]$, if $x \leq y$;$S_{x,y}$ is an empty string, if $x>y$.

You are given $m$ queries of several types:

A question query, given $i; j (1\leq i\leq j\leq n)$, is the substring $[s_i, ..., s_j]$ a palindrome?A modification query which can be of 3 types:(a) Cut the string into 3 (possibly empty) parts $S_{1,i-1}, S_{i,j}, S_{j+1,n}$. Concatenate the first part with the last one into $T= S_{1,i-1} S_{j+1,n}$ and insert the middle one as follows $S'=T_{1,k} S_{i,j} T_{k+1,n'}$ (where $n'=n-(j-i+1)$ respectively), then set $S$ to be equal to $S'$.(b) Reverse the substring $S_{i,j}$. Note that $1 \leq i \leq j \leq n$.(c) Insert a character $c$ at position $i$, i.e. set $S = S_{1,i-1} c S_{i,n}$.

Note that the value of $n$ will change on modification queries of type (c).

### Task

Write a program that runs the queries above.

### Input

The first line contains two space-separated integers $n, m$.

The second line contains $n$ characters representing the initial string.

The following $m$ lines contain the description of the $m$ queries.

A question query is of the form $Q\ i\ j$ where $1\leq i\leq j\leq n$.

A modification query is of the form:

$M\ 1\ i\ j\ k$ – Modification query (a), where $i\leq j$.$M\ 2\ i\ j$ – Modification query (b), where $i\leq j$.$M\ 3\ i\ c$ – Modification query (c), where $c$ is a character.

You can assume that the string will contain only lowercase characters of the English alphabet at all times.

You may assume that the input is valid.

### Output

For each question query, output a single line of "YES" or "NO" (without quotes).

### Constraints

Subtask 1 (10 points)

$\ \ \ \ \ \ \ \ \ \ \ \ \ n, m\leq 10^4$

$\ \ \ \ \ \ \ \ \ \ \ \$ All types of queries are present.

Subtask 2 (20 points)

$\ \ \ \ \ \ \ \ \ \ \ \ \ n, m\leq 2*10^5$

$\ \ \ \ \ \ \ \ \ \ \ \$ Only question and second modification queries are present.

Subtask 3 (20 points)

$\ \ \ \ \ \ \ \ \ \ \ \ \ n, m\leq 2*10^5$

$\ \ \ \ \ \ \ \ \ \ \ \$ Only question and third modification queries are present.

Subtask 4 (20 points)

$\ \ \ \ \ \ \ \ \ \ \ \ \ n, m\leq 2*10^5$

$\ \ \ \ \ \ \ \ \ \ \ \$ Only question queries are present.

Subtask 5 (30 points)

$\ \ \ \ \ \ \ \ \ \ \ \ \ n, m\leq 2*10^5$

$\ \ \ \ \ \ \ \ \ \ \ \$ All types of queries are present.

| Input | Output | Explanation |
| --- | --- | --- |
| 6 10<br>banana<br>Q 2 6<br>Q 2 5<br>M 2 2 3<br>Q 2 5<br>M 2 5 6<br>Q 1 6<br>M 3 7 b<br>Q 1 7<br>M 1 1 2 4<br>Q 4 7 | YES<br>NO<br>YES<br>NO<br>YES<br>NO | The modification queries will change the string in the following way:Initially : S = bananaQuery 1: S = bnaanaQuery 2: S = bnaaanQuery 3: S = bnaaanb Query 4: S = aaanbnb |
