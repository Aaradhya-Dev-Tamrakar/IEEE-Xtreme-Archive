# Poisoned Food

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/poisoned-food/](https://csacademy.com/contest/archive/task/poisoned-food/)  

---

Alex went to a party where there are $N$ types of food. For each type you know the total number of portions and the number of portions that have been poisoned. Unfortunately, you don't know which portions are safe and which are poisoned.

The rules of the house say you have to eat, so Alex wants to minimize the risk of eating a poisoned portion. Find the type of food that is the safest to eat, if Alex chooses a random portion of that type.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains $2$ integers $t_i$ and $p_i$, representing the total number of portions and the number of portions that have been poisoned for the $i^{th}$ type of food.

### Standard output

Print the index of the safest type of food on the first line. If the solution is not unique, print the smallest value.

### Constraints and notes

$1 \leq N \leq 100$ $1 \leq p_i \leq t_i \leq 100$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>2 1<br>3 2<br>4 2 | 1 | The $1^{st}$ and the $3^{rd}$ types of food are the safest, with a probability of $50\%$ of eating a poisoned portion. |
| 5<br>10 6<br>20 12<br>50 40<br>9 5<br>18 10 | 4 | The $4^{th}$ and the $5^{th}$ types of food are the safest. |
