# Parentrisis

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/parentrisis/](https://csacademy.com/contest/archive/task/parentrisis/)  

---

You are given a string $S$ consisting only of ( and ).

Alena and Boris are colorblind. Alena cannot see blue, while Boris cannot see red.

You are supposed to color the characters of $S$ in red, blue or green such that both Alena and Boris will see a well-bracketed sequence.

A well-bracketed sequence is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters 1 and + between the characters of the string. For example, bracket sequences ()(), (()) are well-bracketed, whose corresponding arithmetic expressions are (1)+(1), ((1+1)+1)), while )( and ( are not well-bracketed. The empty sequence is well-bracketed.

### Standard input

The first line contains $T$, the number of test cases.

Each of the following $T$ lines will contain a string, the $i^{\text{th}}$ one being $S_i$.

### Standard output

If there is no solution, print impossible.

Otherwise, print the solution encoded with the first letter of the color capitalized.

### Constraints and notes

$1 \leq |S_i| \leq 10^6$ for $1 \leq i \leq T$ $1 \leq \sum\limits_{i=1}^{T} |S_i| \leq 10^6$

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>())(()<br>())) | GRBRBG<br>impossible | In the first case, both Alena and Boris will see the string ()().In the second case there is no solution. |
