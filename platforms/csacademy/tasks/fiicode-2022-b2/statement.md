# Boundless Software

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fiicode-2022-b2/](https://csacademy.com/contest/archive/task/fiicode-2022-b2/)  

---

A terrible war is knocking on the door. The army of teddy bears declared war upon the community of plush rabbits, who are trying to defend their territory even at the cost of their own life. The bears are real strategists, thus, they have divided the war on several fronts, $t$ to be exact.

On each front, the number $n$ of bears is known. They are to be divided into $k$ divisions that must follow some rules. We know that $k \le \sqrt{n}$, because otherwise we would get divisions with too few bears, and so they would not be able to form a good team.

Furthermore, every bear soldier has a tag, a digit between $0$ and $9$, depending on their role on the battlefield. Those $n$ bears will be lined up, and every bear from each division must occupy consecutive positions in this sequence. Let $s_i$ be the number of bears from the division $i$. The division must follow these rules:

Every bear takes part in exactly one division: $s_1 + s_2 + \cdots + s_k = n$.The size of any two divisions must differ by at most one bear: $|s_i - s_j| \le 1$.No division can begin with a bear with the tag $0$ due to the fact that those bears are not trained to be leaders.

For example, a correct division of the sequence 1012100354 into three divisions is 101|2100|354. Two incorrect examples would be 1012|1003|54 (the second rule is not satisfied) and 101|210|0354 (the third rule is not satisfied).

Your mission is to determine, for each battle front, in how many ways you can divide the bears while also following the rules. Since the total number of divisions can be very large, you must print it modulo  $998\,244\,353$.

### Input

The first line of the input contains an integer $t$, the number of battle fronts. The following lines contain the description of every battle front.

The first line of the description of a battle front contains two integers $n$ and $k$, representing the number of bears on that front and the number of divisions in which they need to be divided. The second line of the description of a battle front contains a sequence of $n$ digits, representing the tags of those $n$ bears.

### Output

For every battle front, you must print the number of ways you can divide the bears modulo $998\,244\,353$.

### Constraints

$1 \le t \le 10^5$ $1 \le k^2 \le n \le 10^7$ It is guaranteed that the total number of bears across all the battlefields does not exceed $10^7$.

| Input | Output |
| --- | --- |
| 7<br>7 2<br>1021304<br>5 1<br>09999<br>5 2<br>11110<br>9 3<br>100200300<br>6 2<br>120089<br>1 1<br>0<br>15 3<br>980706504030210 | 2<br>0<br>2<br>1<br>0<br>0<br>1 |
