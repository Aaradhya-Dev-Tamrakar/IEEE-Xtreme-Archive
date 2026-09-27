# Lynx

**Time Limit:** `500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/lynx/](https://csacademy.com/contest/archive/task/lynx/)  

---

Ajerora is a very skilled engineer. He likes building towers since he was a little boy. Recently, he has invested his time in studying towers of different heights. Thus, he's got $n$ towers of $a_i$ height each.

Also, because time is a valuable and limited resource, he has at most $k$ operations that can be applied on the towers. An operation consists of decreasing a tower's height by $1$.

He is interested in seeing how many towers can be brought to a certain height $x$. Given the fact that he is a well-known engineer (one that likes to impress people), Ajerora wants to see this number for every $x$ equal to $a_i$, given in input.

### Standard input

The first line contains two integers $n$ and $k$ – the number of towers owned by Ajerora and the maximum number of operations.

The next line contains $n$ positive integers: $a_1, a_2, \ldots, a_n$ – the heights of the towers.

### Standard output

The output contains $n$ positive integers: $b_1, b_2, \ldots, b_n$, where $b_i$ is the number of towers that can be brought to height $x = a_i$, for $i = \overline{1, n}$.

### Constraints and notes

$1 \le n \le 10^5$ $1 \le k \le 10^9$ $1 \le a_i \le 10^9, i = \overline{1, n}$ 

| Input | Output |
| --- | --- |
| 5 7<br>1 4 2 2 6 | 4 2 4 4 1 |
