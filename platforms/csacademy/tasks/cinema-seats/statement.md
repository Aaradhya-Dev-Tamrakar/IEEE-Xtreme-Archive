# Cinema Seats

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cinema-seats/](https://csacademy.com/contest/archive/task/cinema-seats/)  

---

In a cinema there is a long row of $N$ seats. Some of them are occupied, some of them are free. At most one of the people who are already seated can move to another seat.

A group of friends are going to come the cinema. What is the largest size of the group such that they can take a contiguous sequence of seats?

### Standard input

The first line contains a binary string of length $N$. The $i^{th}$ character is 0 is the $i^{th}$ seat is empty, and 1 if the seat is taken.

### Standard output

Print the answer on the first line.

### Constraints and notes

$2 \leq N \leq 10^5$ There will be at least one taken seatThere will be at least one free seat

| Input | Output | Explanation |
| --- | --- | --- |
| 10010101 | 4 | You can move the person seating in the $4$th seat to the $7$th, obtaining the configuration 10000111. In this way, the group size will be $4$, sitting from the $2$nd chair up to the $5$th one.12222111 - the group's chairs were marked with 2 |
| 001100 | 3 | One way is to move the person from the $3$rd seat to the $5$th one.This way, the cinema row becomes 000110, leaving a sequence of $3$ seats for the group. |
| 01000100 | 6 | Move the person from the $6$th seat to the $1$st one.This way, it's posible to sear a group of size $6$ |
