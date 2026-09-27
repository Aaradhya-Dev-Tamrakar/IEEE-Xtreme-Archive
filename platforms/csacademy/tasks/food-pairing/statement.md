# Food Pairing

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/food-pairing/](https://csacademy.com/contest/archive/task/food-pairing/)  

---

You need to cook for a lot of hungry programmers. All the $M$ dishes you can cook are made up of $N$ ingredients. For each ingredient you know how many units you have, and for every dish you know how many units of every ingredient you need for a single portion of that dish.

You want every programmer to have a meal that consists of the same two distinct dishes. Find the maximum number of programmers you can cook a meal for.

### Standard input

The first line in the input contains the number $N$, followed by a line with $N$ integers, representing the number of units of each ingredient you have.

The next line contains a number $M$ and each of the next $M$ lines describe the dishes, one by one. A dish is described by $N$ values, representing the number of units of each ingredient needed for that dish.

### Standard output

The first line of standard output should contain the maximum number of identical pairs of dishes that you can make.

### Constraints and notes

$1 \leq N \leq 32$ $2 \leq M \leq 512$ The numbers of units of ingredients are nonnegative and fit in a $32$ bit signed integer.Not all dishes may need all ingredients, but there isn't a dish that needs no units of any ingredient.

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>10 10<br>3<br>2 3<br>3 1<br>1 5 | 2 | Pick dishes $1$ and $2$. To cook $2$ meals, you will need $2 * (2, 3) = (4, 6)$ for the first dish, and $2 * (3, 1) = (6, 2)$ for the second dish.To serve two portions of both dished, you'll need $(4, 6) + (6, 2) = (10, 8)$. Since you have 10 units of both ingredients, that is enough. |
| 3<br>20 10 15<br>4<br>1 2 3<br>4 1 1<br>1 3 1<br>2 1 2 | 3 | You can pick any of the following menus ($1$, $2$), ($1$, $4$) and ($2$, $4$). |
