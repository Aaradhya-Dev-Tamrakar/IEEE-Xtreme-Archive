# Douchebag Parking

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/douchebag-parking/](https://csacademy.com/contest/archive/task/douchebag-parking/)  

---

Consider a row of N parking spots. For each spot you know whether it's free or not, and you are also given its width. You have a car of width $W$. Because you are a douchbag, you afford parking on several consecutive parking spots, as longs as they are all free and their total width is greater or equal than $W$.

Find the lowest index of a parking spot from a set of consectuive spots where you can park your car.

### Standard input

The first line contains two integers $N$ and $W$.

Each of the next $N$ lines contains two integers: the first integer is equal to $0$ or $1$, where $0$ corresponds to a taken parking spot and $1$ to a free one; the  second integer is a number $L_i$ representing the width of the parking spot.

### Standard output

If there is no solution output $-1$.

Otherwise print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 300$ $1 \leq W \leq 300$ $1 \leq L_i \leq 300, 1 \leq i \leq N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5 9<br>1 3<br>1 5<br>0 4<br>1 2<br>1 10 | 4 | For the first parking spot, only a car of width smaller of equal to $8$ would fit.For the $4$th one, a car with width smaller or equal to $12$ would fit, this being the first parking space that can fit our car of width $9$ |
| 5 7<br>1 2<br>0 3<br>1 5<br>1 1<br>0 2 | -1 | There's no parking space big enough to fit the car. |
| 4 5<br>1 2<br>1 2<br>1 2<br>1 2 | 1 | Note that if there are multiple parking places in which the car could be parked, it's required to print the one having the lowest index. |
