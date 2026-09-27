# Server Attack

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/server-attack/](https://csacademy.com/contest/archive/task/server-attack/)  

---

A hacker is trying to bring down a server, while the sysadmin is trying to keep it online. You know the moments when the hacker performs an attack and the moments when the sysadmin checks the server status and restarts it in case it's down.

Find the total amount of time the server is offline.

### Standard input

The first line contains a single integer $N$, representing the moments when the hacker is launching an attack or the sysadmin is checking the server.

Each of the next $N$ lines contains two integers. The first value is $1$ if the current line describes a hacker attack, and $2$ if it's a sysadmin check. The second value is the moment in time when this action happens.

### Standard output

Print a single integer representing the total time the server is down.

### Constraints and notes

$1 \leq N \leq 1000$ The time moments are integers between $0$ and $5000$ The time moments are distinct and in increasing orderThe last action performed is a sysadmin check

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>2 5<br>2 7<br>1 10<br>2 20 | 10 | The site was up until moment $10$ when it's attacked, and the sysadmin fixes it at moment $20$. The sysadmin's checks on moments $5$ and $7$ have no effect since the site is already up.This results in a downtime of $20 - 10 = 10$ |
| 4<br>2 3<br>1 4<br>1 10<br>2 15 | 11 | The hacker attacks the site at moments $4$ and $10$. When he attacks the site for the second time, the site is already down, so it'll stay that way. The sysadmin fixes it at moment $15$, giving a downtime of $15 - 4 = 11$ |
