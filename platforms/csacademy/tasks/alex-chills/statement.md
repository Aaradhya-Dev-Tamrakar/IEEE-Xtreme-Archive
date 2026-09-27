# Alex Chills

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/alex-chills/](https://csacademy.com/contest/archive/task/alex-chills/)  

---

### Statement

Recently, Alex discovered a new game called "One finger death punch" (Note: References in this problem are indicative and do not reflect what's actually happening in the game). Thus, he can experience being a Kung-Fu master and stopping the enemies that want to knock him down.

Long story short, we will only consider the situation where the enemies are coming from the right. Alex stands in the center of the screen and he's able to see $N$ enemies that stand in front of him. Each enemy has a level (Obviously, if the level is high, the enemy is harder to defeat).

Alex doesn't know the level of the incoming enemies (the ones after the given $N$), but he can compute them with the formula $f[k]=f[k-1] \oplus f[k-2] \oplus ... \oplus f[k-n]$, where "$a \oplus b$" denotes Bitwise XOR between $a$ and $b$.

Besides $N$ (the number of enemies Alex can see on the screen) and $N$ integers that denote the levels of those enemies, you are given two more integers $L$ and $R$, that indicate an interval of enemy indices from which you need to find out the maximum level of an enemy, so Alex knows what to prepare for.

### Standard input

The first line contains $N$, $L$ and $R$ (the number of enemies Alex can see, and an interval from which you need to determine the maximum level of an enemy).

The second line contains $N$ integers denoting the levels of the enemies that Alex can see.

### Standard output

An integer denoting the maximum level of an enemy from the interval $[L, R]$.

### Constraints and notes

$1 \le N \le 10^5$ $1 \le L, R \le 10^9$ $0 \le f[i] \le 10^9$  (for every $i$ between $1$ and $N$)

| Input | Output | Explanation |
| --- | --- | --- |
| 3 1 4<br>1 2 3 | 3 | We have 3 numbers (1, 2 and 3), and we have to compute the maximum number between the first and the fourth number.To do that, we compute the fourth number, which is 0, and then we find the maximum number from that interval, which is 3. |
| 3 5 6<br>1 2 3 | 2 | The sequence will be: 1 2 3 0 1 2. Thus, the maximum number between the fifth and the sixth position is 2. |
