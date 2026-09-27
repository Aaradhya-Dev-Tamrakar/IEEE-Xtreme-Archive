# Alex Climbs

**Time Limit:** `1000 ms`  
**Memory Limit:** `976.6 MB`  
**Source:** [https://csacademy.com/contest/archive/task/alex-climbs/](https://csacademy.com/contest/archive/task/alex-climbs/)  

---

You already knew that Alex is a fan of games and he likes a lot competitive programming, and now you have just learned about his new passion, climbing.

He has in front of him a panel on which he trains. Practically, the panel can be represented as a rectangular matrix with $N \cdot M$ portions. Each portion has a stone attached, in which case the value of the portion is $1$ or is free, in which case the value in that portion is $0$.

Alex knows that in order to be able to support his left leg in a portion then that portion must be free and the adjacent lower and left portions must have a stone. (so he does not fall or slide to the left). He calls such a portion a left grip. Also, in order to be able to support the right foot in a portion, then that portion must be free and the adjacent lower and right portions must have a stone. (so he does not fall or slide to the right). He calls such a portion a right grip. At the same time he can put his left hand only in a left grip and his right hand only in a right grip. Of course, a portion can also be a left grip and a right grip, in which case we will call it a double grip.

For a more detailed explanation, see the example.

Alex wants to count how many positions he can hold. That is, to have the right hand in one right grip, the right foot in one right grip, the left hand in one left grip and the left foot in one left grip. All grips must be distinct. Also, Alex can't stretch much, so consider only the quadruples that fit into a submatrix with sides of at most $K$. Two grips fit into a submatrix of maximum size $K$ if the difference between the length and height of the portions in which the foot / hand is placed is maximum $K$ (the portion has 0 on the panel).

  

More formally, you must find all quadruples $\{(X_{a},Y_{a}),(X_{b},Y_{b}),(X_{c},Y_{c}),(X_{d},Y_{d})\}$ such that all 4 are pairwise distinct and can be framed in a submatrix with sides at most $K$ and

  

$(X_{a},Y_{a})$ is either left grip or double grip;

$(X_{b},Y_{b})$ is either left grip or double grip;

$(X_{c},Y_{c})$ is either right grip or double grip;

$(X_{d},Y_{d})$ is either right grip or double grip;

  

He found a formula but it's complicated, and he doesn't know if it's correct. Please write a program that calculates the number of quadruples modules $10^9+ 7$.

  

### Standard input

On the first line there are three natural numbers $N$, $M$ matrix dimensions and $K$.

The following $N$ lines contain m characters that will be $0$ or $1$ without spaces between them, which represents the description of the panel.

### Standard output

You have to display a single number, how many configurations are on the panel modulo $10^9+ 7$.

### Constraints and notes

$4 \le N,M \le 1\,000$ $4 \le K \le max(N,M)$   

| Input | Output | Explanation |
| --- | --- | --- |
| 4 4 4<br>1010<br>1111<br>0101<br>1111 | 8 | The portion from $(0,1)$ is a double grip, and we note it $D_{1}$.The portion of $(0,3)$ is the left grip,and we note $L$.The portion from $(2,0)$ is the right grip,and  we note $R$.The portion of $(2,2)$ is a double grip, and we note it $D_{2}$.The answer is $8$, and the set is: $\{\{L, D1, R, D2\},$ $\{L, D1, D2, R\},$<br><br>$\{D1, L, R, D2\},$<br><br>$\{D1, L, D2, R\},$<br><br>$\{L, D2, R, D1\},$ $\{L, D2, D1, R\},$<br><br>$\{D2, L, R, D1\},$<br><br>$\{D2, L, D1, R\}\}.$ |
| 4 4 4<br>1010<br>1111<br>0110<br>1111 | 4 |  |
| 5 4 5<br>1011<br>1101<br>1011<br>1101<br>1111 | 24 |  |
