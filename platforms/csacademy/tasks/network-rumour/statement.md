# Network Rumour

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/network-rumour/](https://csacademy.com/contest/archive/task/network-rumour/)  

---

You have a network consisting of $N$ computers. For each pair of computers $(A, B)$ you know the neccesary time of transferring a file from $A$ to $B$. It is possible that the transfer time from $A$ to $B$ is different than the transfer time from $B$ to $A$. You are not allowed to transfer a file from a computer to more than one other computer at the same time.

There is a very important file on computer $1$. You want to transfer this file to all the other computers. Once a computer gets the file, it can immediately start to transfer it to some other computer. You should minimze the time when the last file transfer finishes.

### Standard input

The first line contains a single integers $N$.

Each of the next $N$ lines contains $N$ integers. The $j$th element on the $i$th line represents the transfer time from computer $i$ to computer $j$. The $i$th value on the $i$th line is always $0$.

### Standard output

The output should contain a single integer representing the minimum time necessary to finish transferring the file to all the computers.

### Constraints and notes

$1$ ≤ $N$ ≤ $13$The transfer time are integers between $0$ and $10 000$

| Input | Output |
| --- | --- |
| 3<br>0 1 2<br>4 0 3<br>1 1 0 | 3 |
| 4<br>0 1 9 9<br>5 0 3 1<br>0 0 0 0<br>2 3 1 0 | 3 |
| 4<br>0 1 1 1<br>1 0 1 1<br>1 1 0 1<br>1 1 1 0 | 2 |
