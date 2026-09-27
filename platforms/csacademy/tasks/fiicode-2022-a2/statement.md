# Awesome Software

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fiicode-2022-a2/](https://csacademy.com/contest/archive/task/fiicode-2022-a2/)  

---

Lately, the company Atek Software grew significantly. For this reason, it has been decided by the administrative council that the Atek headquarters needs to be moved to a new location in order to expand its offices.

In this regard, they decided to analyze $t$ cases. In every case, there is an integer $n$ given, the number of employees in the company. It is known that the relocation team is indeed a superstitious one, thus, not every location is suited for the employees. More precisely, this team needs to find, for every case, two integer coordinates $a$ and $b$ that satisfy a condition that is, also, a superstitious one: $\gcd(a, b) \cdot \operatorname{lcm}(a, b) + \gcd(a, b) + \operatorname{lcm}(a, b) = n$.

Only then, when this connection between the coordinates and the number of employees is accomplished, we can say that the relocation was successful. Until then, this team works day and night, without getting any sleep. Your objective is to help them check, for every case, if there exists a pair of coordinates that satisfy the superstitious conditon.

### Input

The first line of input contains an integer $t$ – the number of cases to be examined. The following $t$ lines contain one integer $n$ – the number of employees in each case.

### Output

For every case, print $1$ if there exists a pair of coordinates that satisfy the condition, or $0$ if there is no place on Earth good enough for Atek's employees.

### Constraints

$1 \le t \le 10^3$ $1 \le n \le 10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 7<br>5<br>1<br>8<br>34<br>52<br>999999999<br>905586532 | 1<br>0<br>1<br>0<br>0<br>1<br>0 | For $n = 1$, $n = 34$, $n = 52$ și $n = 905\,586\,532$, there are no solutions.For $n = 5$, the only solution is $(a, b) = (1, 2)$.For $n = 8$, the only solution is $(a, b) = (2, 2)$.For $n = 999\,999\,999$, a possible solution is $(a, b)=(999, 999\,999)$. |
