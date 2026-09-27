# Traveling Time

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/traveling-time/](https://csacademy.com/contest/archive/task/traveling-time/)  

---

There are $N$ equidistant train stations on the number line, numbered from $1$ to $N$. The $i$-th station is located at coordinate $i$.

  

There are also $M$ trains. The $i$-th train is going from station $l_i$ to station $r_i$ starting at time $t_i$ ($1 \leq i \leq M$). Trains stop in all intermediary stations. All trains move from left to right ($l_i \lt r_i$) and have the same constant speed: it takes exactly one unit of time to go between any two adjacent stations.

  

Gigel is at station $1$ at time $0$ and wants to arrive at station $N$ at a time no later than $T$, using the train network. In order to do that, he can use multiple trains; however, he wants to minimize the number of tickets he has to buy (and, therefore, the number of trains that he would take).

  

Print the minimum number of trains Gigel has to take in order to arrive at the station $N$ at the required time or tell that it is impossible.

  

### Standard input

  

On the first line there are three space-separated integers: $N$ $M$ $T$. Each of the following $M$ lines contains three space-separated integers: $l_i$ $r_i$ $t_i$ (as specified in the statement).

  

### Standard output

  

The standard output should contain a single integer: the minimum number of trains that Gigel to take in order to achieve that. If there is no possible schedule, print -1.

  

### Constraints and notes

  
$1\leq N\leq 10^9$ $1\leq M\leq 10^5$ $1\leq T\leq 10^9$ $1\leq l_i \lt r_i\leq N$ $1\leq t_i\leq 10^9$ If Gigel gets off at station $i$ at time $t$, he can take any train that leaves the station $i$ at the same time $t$ (or later).  

| Input | Output | Explanation |
| --- | --- | --- |
| 5 5 10<br>1 5 7<br>1 2 1<br>2 4 3<br>3 5 4<br>2 5 8 | 3 | Gigel can take the second train and arrive at  the station 2 at time 2.Then he can wait a minute and take the third train, arriving at the station 4 at time 5, just in time to jump into the fourth train and arrive at the last station at time 6.There is no way to arrive at the station 5 at time 10 using at most 2 trains. |
| 6 5 10<br>1 3 5<br>4 5 7<br>3 5 12<br>3 4 8<br>5 6 8 | -1 | There is no way for Gigel to arrive at the station 6 at time 10. |
