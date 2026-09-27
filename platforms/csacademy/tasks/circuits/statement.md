# Circuits

**Time Limit:** `400 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/circuits/](https://csacademy.com/contest/archive/task/circuits/)  

---

Jane and Joe are planning their winter vacation. They already have a list with $N$ cities that they want to visit and another list with $M$ flights connecting the cities.

Since Jane and Joe just won the lottery, instead of finding the cheapest circuit that visits all the cities exactly once, they want to choose the $K^{th}$ such circuit in lexicographic order because this is their lucky number.

### Standard input

The first line contains three integers $N$, $M$ and $K$.

The following $M$ lines contain the list of flight connections in the format: u v meaning that there is a flight leaving from city $u$ and arriving in city $v$.

### Standard output

The first line contains $N + 1$ numbers representing the circuit that Jane and Joe want to take, if it exists. Otherwise print a single number: 0.

### Constraints and notes

A circuit starts and finishes in city number 1 (Jane and Joe's home city) and visits all the cities exactly once.A flight connection allows them to fly from city $u$ to city $v$ but not the other way around.Two circuits are different if the order the cities are visited is different.$3 \leq N \leq 18$.$0 \leq M \leq N \cdot (N - 1)$.$1 \leq K \leq 10^{18}$.$1 \leq u, v \leq N, u \neq v$ for all flights.

### Subtasks

Test cases will be scored individually.

| Subtask | Percentage of test cases | Additional input constraints |
| --- | --- | --- |
| 1 | $30\%$ | $N \leq 10$ |
| 2 | $20\%$ | $K \leq 10^4$ |
| 3 | $50\%$ | none |

### Examples

| Input | Output | Explanation |
| --- | --- | --- |
| 4 10 2<br>1 2<br>2 1<br>2 4<br>4 2<br>1 3<br>3 1<br>3 4<br>4 3<br>1 4<br>2 3 | 1 3 4 2 1 | There are 3 possible circuits. In lexicographic order, they are:1 2 4 3 11 3 4 2 11 4 2 3 1 |
