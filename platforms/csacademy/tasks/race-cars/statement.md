# Race Cars

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/race-cars/](https://csacademy.com/contest/archive/task/race-cars/)  

---

There are $N$ race cars. Each car is characterised by two integers $D$ and $V$ representing the distance until it crosses the finish line and the speed. There is a hacker capable of doing one of two things:

increase the speed of your car by $X$ reduce the speed of all other cars by $Y$ 

Consider that the hacker is driving each car. What's the best place the hacker can finish the race opting for the best hack?

All scenarios are independent of each other - the choice made for car $i$ does not affect other cars.

If two cars cross the finish lane at the same time, the car with the lowest id will be crossing first, that is the car that appears first in the input.

### Standard input

The first line contains three integers $N$, $X$ and $Y$.

Each of the following $N$ lines contains two integers $D$ and $V$ describing a car.

### Standard output

You should output $N$ lines, each containing the best place the hacker can end up on if she was driving that car.

### Constraints and notes

$2 \leq N \leq 10^5$ $1 \leq D \leq 10^7$ $1 \leq V \leq 10^7$ $0 \leq X \leq 10^7$ $0 \leq Y < min\ V$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4 2 2<br>10 3<br>5 3<br>25 10<br>30 15 | 2<br>1<br>2<br>1 | Explanation format$X$ $Y$ $Z$ $X$ = the place in the race if there're no hacks.$Y$ = the place in the race if car $i$ will increase it's speed.$Z$ = the place in the race if car $i$ will decrease other cars speed.$4\ 2\ 3$ $1\ 1\ 1$ $3\ 3\ 2$ $2\ 2\ 1$ |
| 2 2 1<br>10 7<br>10 5 | 1<br>2 | $1\ 1\ 1$ $2\ 2\ 2$ Note that if the second car increases its speed, it will still finish last because it appears later in the input. |
| 2 2 1<br>10 5<br>10 7 | 1<br>1 | $2\ 1\ 2$ $1\ 1\ 1$ Note that if the first car increases its speed ($5 \rightarrow 7$)  it'll finish first because it appears first in the input. |
