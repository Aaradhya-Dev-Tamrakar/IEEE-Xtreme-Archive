# Flawed Olympiad

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/flawed-olympiad/](https://csacademy.com/contest/archive/task/flawed-olympiad/)  

---

For the first time in history, the infamous International Olympiad in Bitwise Arithmetics is taking place in Iași during this week-end. After hours of hard work and numerous calculations, Georgel has mastered the art of thinking in binary, and consequently earned the honor of taking part in this great contest, competing against the best of the best at this craft.

  

This year's challenge is based on a sequence $A$ of $N$ positive integers and a positive integer $x$ written on the board. The contestants should place the "$\&$" ( bitwise AND operator ) or "$|$" ( bitwise OR operator ) between every two adjacent numbers in the sequence $A$, such that the result of the computation is $x$. Note that in this task, the two operators have the same priority, therefore the expression is always evaluated from left to right.

  

For example, if the sequence is $[13, 8, 7]$ and $x$ equals $5$, one possible solution is $13\: |\: 8\: \&\: 7$. Note how the bitwise OR operation is evaluated before the bitwise AND operation.

  

Even with all his training and calculation speed, Georgel is struggling quite hard with this task. He is even inclined to think that the task might be impossible. But can that be true? Can the IOBA task be flawed?

  

### Standard input

  

The first line of input contains two positive integers: $N$ (the length of sequence $A$), and $x$. The second line contains $N$ positive integers $A_i$, denoting the sequence.

  

### Standard output

  

The output should consist in the solution to the challenge, written in the form $A_1 [op] A_2 [op] ... [op] A_n$ where $[op]$ is one of "$|$" or "$\&$". Note that you should not output any spaces between the operators. if the question is ill-defined, meaning that there is no solution, output a single word impossible.

  

### Constraints and notes

  

$1 \leq N \leq 10^5$

The elements $A_i$ of the sequence and the sought result $x$ are all non-negative integers strictly less than $2^{30}.$

  

| Input | Output |
| --- | --- |
| 3 5<br>13 8 7 | 13|8&7 |
| 3 0<br>13 8 7 | 13&8&7 |
| 3 13 <br>13 8 7 | impossible |
