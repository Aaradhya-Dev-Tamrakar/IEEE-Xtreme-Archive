# Clown Fiesta

**Time Limit:** `2500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/clown-fiesta/](https://csacademy.com/contest/archive/task/clown-fiesta/)  

---

As you already know, Alex and Paul are big fans of games. After playing string games, coin games, and pile games, they now thought of playing something different, an endurance game. They combined two things they really like (big numbers and prime numbers) and the following game came out:

In order to start, they only need a sequence $a$, indexed from $1$, with $2n$ prime numbers and a prime $m$ that is smaller than any number in $a$.

They go through each element, from left to right, and, if the current position is odd, Alex changes the current element $a_i$ with $a_i^{a_{i - 1}}$. However, if the current position is even, Paul changes the current element $a_i$ with $a_i^{a_{i - 1}}$. By convention, $a_0 = 1$.

Despite the fact that, for most people, working with large numbers can be quite difficult, the two friends managed to carry out the calculations to the end.

Alex and Paul have already finished, and they want to check their results. So, they ask you to print the array $a$ after finishing all the operations.

Because the numbers can become very large after the operations, Alex and Paul ask you to display each number modulo $m$.

### Standard input

The first line contains the numbers $n$ and $m$. The second line contains $2n$ positive integers, representing the elements of $a$.

### Standard output

The output contains $2n$ numbers, where the $i$th one is the value of $a_i$ at the end of the game.

### Constraints and notes

$1 \le n \le 10^5$ $3 \le m \le 10^9$ and $m$ is prime $m \lt a_i \le 10^{14}, i = \overline{1, n}$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 2 3<br>5 7 11 5 | 2 1 2 2 |  |
| 2 7<br>11 13 17 19 | 4 6 3 3 | $a_1=11^1$<br><br>$a_2=13^{11}$<br><br>$a_3=17^{13^{11}}$<br><br>$a_4=19^{17^{13^{11}}}$<br><br>$a_1\; mod\; 7 = 4$<br><br>$a_2\; mod\; 7 = 6$<br><br>$a_3\; mod\; 7 = 3$<br><br>$a_4\; mod\; 7 = 3$<br><br>Please note that when calculating $a_i$ we consider the new value for $a_{i-1}$ and not the initial one. |
