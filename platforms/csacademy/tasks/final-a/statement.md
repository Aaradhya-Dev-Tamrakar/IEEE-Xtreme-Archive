# Final A

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/final-a/](https://csacademy.com/contest/archive/task/final-a/)  

---

### Statement

"Stapane, stapane, mai chiama s-un cane..."

  

By doing an imaginary jump in time, Alex now sees himself as one of the characters from the universe of the crime novel "Baltagul" by Mihail Sadoveanu. Thus, he wants to help Nechifor Lipan (husband of Vitoria Lipan) with his amazing math skills so that the shepherd (Nechifor) can sell his $N$ sheep in a very profitable way.

Because Nechifor likes to keep things in order, he gives tags to his sheep, each animal being labeled with a distinct positive integer.

Alex knows from the book that not all sheep can be sold for a profitable amount (the Nechifor family has some weird superstitions), so, he decided to mark the sheep that do not bring enough money, and sell the ones that are not being marked. A sheep is being marked by Alex if it's tag number can be written as $a+(a+1)+...+(a+m)$, where $m\ge1$ and $a$ is a positive integer greater than $0$.

Your task is to compute the number of sheep that can be sold for profit.

### Standard input

The first line will contain one positive integer $N$, the number of sheep.

The next line will contain $N$ distinct positive integers, the numbers on the sheep's tags.

### Standard output

Output one line with one integer, the number of sheep that can be sold for profit.

### Constraints and notes

$1 \le N \le 10^5$ $1  \leq x_i \leq  10^{18}$, where $x_i$ is the number from the i-th sheep's tag 

| Input | Output | Explanation |
| --- | --- | --- |
| 7<br>5 8 3 7 9 4 6 | 5 | We can see that the numbers 8 and 4 cannot be written as a sum o consecutive integers, meaning that Nechifor can't sell those sheep. 7-2=5, the number of sheep that can be sold. |
