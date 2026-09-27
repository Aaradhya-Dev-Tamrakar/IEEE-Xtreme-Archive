# Boundless Atek

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fiicode-2022-b1/](https://csacademy.com/contest/archive/task/fiicode-2022-b1/)  

---

Fanurie enjoys looking at the sky. The other night, he observed for the first time a group of $n$ planets, which seem to be part of the same stellar system. He was surprised by the fact that those planets were standing in a straight line.

This night he looked at them again. Using their position relative to Earth in the two nights, he calculated the velocity of each planet (in billions of kilometers per year). Let's denote them with $a_1, a_2, \ldots, a_n$.

Fanurie knows nothing more about this stellar system, so he is wondering what is its maximum circumference $m$ such that, after exactly one year, the planets will be aligned again.

### Input

The first line of the input contains the number $n$, representing the number of planets in the stellar system.

The second line contains $n$ positive integers $a_1, a_2, \ldots, a_n$, representing the velocities of these planets.

### Output

The output contains a single number, namely the answer $m$. If $m$ can be arbitrarily large, print $-1$ instead.

### Constraints

$2 \le n \le 10^5$ $1 \le a_1, a_2, \ldots, a_n \le 10^{18}$ We consider that all the planets use the exactly same orbit. In other words, they all must use the same amount of space in order to make a full rotation around their star.

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>21 13 | 8 | After one year, the first planet will be at a distance of $21 \,\operatorname{mod}\, 8 = 5$ units away from its initial position. The second planet will also be at a distance of $5 = 13 \,\operatorname{mod}\, 8$ units away from its initial position. |
