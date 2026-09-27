# Cloud Computing

**Time Limit:** `2500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cloud-computing/](https://csacademy.com/contest/archive/task/cloud-computing/)  

---

Johnny is founding Bytecomp, a company that offers computing power in the cloud. Companies with this profile usually have many fast computers on which customers computations can be made.

Johnny still has not bought any machines. He went to a computer shop and received a list of all $n$~available computers. Every computer is specified by the number of (processor) cores $c_i$, the clock rate $f_i$, and the price~$v_i$. Such a computer contains $c_i$ separate cores that do not interfere with each other, so they can be assigned to different tasks.

When a customer makes an order for resources, she specifies the required number of cores $C_j$ and the minimum needed clock rate $F_j$. An order also contains the price $V_j$ that the customer is willing to pay in return. If an order is accepted, Bytecomp needs to provide exclusive access to computing power required by the customer. Johnny needs to choose $C_j$ cores (possibly from different computers), each with clock rate at least $F_j$. Those cores cannot be assigned to any other order.

Help Johnny earn as much as possible: choose an optimal subset of orders to accept and a subset of computers from the shop to satisfy all the accepted orders. Your goal is to maximize the total profit, that is, the difference between earnings for providing computing power to customers and the cost of buying the computers.

### Standard input

The first line contains an integer $n$, the number of computers that are available at the shop. Each of next $n$ lines contains a description of one computer. It consists of three space-separated integers $c_i$, $f_i$, and $v_i$ which represent the number of cores, the clock rate, and the price, respectively.

The next line contains an integer $m$, the number of orders. Each of next $m$ lines contains a description of one order. It consists of three space-separated integers $C_j$, $F_j$, and $V_j$ which represent the number of cores needed, the minimum allowed clock rate, and the customer's budget, respectively.

### Standard output

The only line of the standard output should contain one integer, the maximum total profit that can be achieved.

### Constraints and notes

$1 \le n \le 2000$  $1 \le m \le 2000$ $1 \le c_i \le 50$, $1 \le f_i \le 10^9$, $1 \le v_i \le 10^9$ $1 \le C_j \le 50$, $1 \le F_j \le 10^9$, $1 \le V_j \le 10^9$ 

### Subtasks

SubtaskAdditional constraintsNumber of points1$n \le 15$$18$2$m \le 15$$18$3$n, m \le 250$, $c_i = C_j = 1$$18$4$f_i = F_j = 1$$18$5$v_i = V_j = 1$$18$6no additional constraints$10$

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>4 2200 700<br>2 1800 10<br>20 2550 9999<br>4 2000 750<br>3<br>1 1500 300<br>6 1900 1500<br>3 2400 4550 | 350 | There are four available computers and three orders. It is optimal to buy two quad-core computers that cost $700$ and $750$ ($1450$ in total) and then accept the first two orders to earn $300 + 1500 = 1800$ in total.We then have four cores with clock rate $2000$ and four cores with clock rate $2200$.We can assign any six of them to the second order (clock rate $1900$ needed) and one to the first order (clock rate $1500$ needed).Note that one core will not be used, which is allowed. |
