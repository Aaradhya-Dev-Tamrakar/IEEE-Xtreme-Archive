# Best Driver

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/best-driver/](https://csacademy.com/contest/archive/task/best-driver/)  

---

Priskovel thinks about himself that he is a very good driver.  However, his brother, Priskovinko, thinks that Priskovel can't drive economically. They decide to compete  in $Q$ days one against each other to see who was the lowest fuel consumption after .

Each day, Priskovel starts by resetting the average consumption and then driving the car $X_1$ km with an average fuel consumption of $C_1$ litres per 100km. Priskovinko continues the next $X_2$ km, without resetting the fuel consumption meter, resulting in a fuel consumption of $C_2$ (litres per 100km) for the whole trip (for the distance $X_1 + X_2$). So, the consumption $C_2$ is for both Priskovel and Priskovinko on that day.

  

Help them find out what consumption (in litres per 100km) had Priskovinko on each day. (On the segment of $X_2$ kilometers)

  

### Standard input

The first line contains $Q$ the number of days that they compete.

The next $Q$ lines contain $X_1, X_2, C_1, C_2$ separated by spaces.

### Standard output

The output contains $Q$ lines. On each line it is the average the fuel consumption $C_2$ that Priskovinko had had on the distance $X_2$ on that day.

### Constraints and notes

$1 \leq Q \leq 100$ $1 \leq X_1, X_2, C_1, C_2 \leq 10^4$ the answer will be considered correct if the relativ or absolute error between your result and correct answer is at most $10^{-6}$ It is guaranteed that the answer (the fuel consumption on the second segment) is greater than 0.

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>100 100 5 6<br>100 200 5 4 | 7.00000000<br>3.50000000 | For the second day, Priskovel drove the first 100km with an average fuel consumption of 5 (l/100km), and the fuel consumption at the end of the trip (after Priskovinko drove the last 200km) was 4 (l/100km). The average fuel consumption for the last 200 km was 3.5 (l/100km) |
