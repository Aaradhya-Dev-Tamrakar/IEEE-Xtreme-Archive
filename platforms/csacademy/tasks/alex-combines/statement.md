# Alex Combines

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/alex-combines/](https://csacademy.com/contest/archive/task/alex-combines/)  

---

### Statement

Paul is a well-known chef. He owns a restaurant called Papa Paul where he serves a lot of different dishes. Every morning, Paul and the other chefs place on the counter all the ingredients that they have for that day (ingredients are not necessarily grouped, meaning that, for example, tomatoes can appear on more than one position on the counter). Thus, they have $N$ ingredients on the counter at the start of the day. They label those ingredients, each one having a number (for example, tomatoes, no matter where they appear, are going to have number $1$, all cucumbers that appear on the counter are going to have number $2$, etc.).

In order to make the best food, Paul decided to not have $2$ ingredients of the same type in one dish (so tomatoes from different positions can't go in the same dish), but also, because he likes quality over quantity, he looks forward to making less dishes, but very tasty and special ones.

Your task is to compute, for $Q$ queries of type $[L, R]$, the minimum number of groups of ingredients (substrings of ingredients) such that, in one group there are no $2$ ingredients of the same type (not even $2$ tomatoes). That would make Paul happy and he would be able to impress customers with fantastic dishes.

(Note: a substring of ingredients contains contiguous positions with ingredients).

### Standard input

In the first line there is $1$ integer, $N$ (the number of ingredients on the counter).

In the next line, $v[i]$ (the labels for ingredients, with $i$ between $1$ and $N$).

In the next line there is $1$ integer, $Q$ (the number of queries).

In the next $Q$ lines, there wil be $2$ numbers: $L$ and $R$ (which represents the interval for the query).

### Standard output

For every query, you need to output one number on one line, which represents the minimum number of groups, such that there are no $2$ ingredients of the same type in one substring (group).

### Constraints and notes

$1 \le N, Q \le 10^5$ $1 \le v[i] \le 10^6$ $1 \le L, R \le N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 10<br>5 1 5 5 4 1 4 4 2 4 <br>10<br>2 9<br>2 10<br>7 8<br>7 7<br>1 6<br>4 8<br>3 7<br>1 10<br>5 10<br>5 9 | 4<br>5<br>2<br>1<br>3<br>3<br>3<br>6<br>4<br>3 | For the first query, the groups can be formed as such:[1,5], [5,4,1], [4], [4,2]. |
