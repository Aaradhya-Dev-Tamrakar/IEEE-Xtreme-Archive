# Strips

**Time Limit:** `2500 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/strips/](https://csacademy.com/contest/archive/task/strips/)  

---

The owner of a renowned programming club from Cluj wishes to introduce bracelets made from multiple coloured strips which he will manufacture from multicoloured rubber band. Because he has consumed too much milk in his last escaped on the street Piezisa he requires your help with the manufacturing.

You will be given a sequence $a$ of $N$ elements indexed from 1 describing the band. We will call a maximal substring $[l, r]$ with all elements equal (that is $a_l = a_{l+1} = a_{l+2} = ... = a_{r}$ a strip.

On this sequence we will apply the following two operations:

$1\ L\ R$ - Find the number of strips and longest strip considering only the substring band $[L, R]$ from the sequence $a$. The given band will be considered circular: positions $L$ and $R$ from the original sequence will be neighbours.

$2\ L\ R\ M\ B_1\ B_2\ ...\ B_M$ - The substring $[L, R]$ of $a$ is replaced for all subsequent operations with the pattern $B$. If substring $[L, R]$ is longer than the pattern it is length-extended by repetition to match the length of the substring. For example the operation $2\ 3\ 10\ 3\ 1\ 2\ 2$ will replace the substring $[3, 10]$ with the sequence $1\ 2\ 2\ 1\ 2\ 2\ 1\ 2$.

In total $Q$ such operations will be applied. At the end of all these operations you should also display the sequence $a$.

### Standard input

The first line will contain two integers $N$ and $Q$ with the meaning described above.

The second line will contain $N$ space separated integers, the original values of sequence $a$.

### Standard output

On the first line you should output two numbers, the number of strips and longest strip in the original sequence.

Each of the following lines except the last should have the same answer but for each operation of type $2$.

The last line must contain $N$ numbers, representing the final state of sequence $a$.

### Constraints and notes

$1\leq N \leq 250\ 000$ $0 \leq Q \leq 200\ 000$ For each operation $1 \leq L \leq R \leq N$ and $1 \leq M \leq N$ The sum of all $M \leq 250\ 000$ $a_i \leq 10^9$ 

#PointsRestrictions17$N, Q \leq 5000$29All operations will be of the first type35Sum of $R - L$ for all operations of type $2\leq 200\ 000$410$M = 1$ for all operations511Sum of $M \leq 5\ 000$627$N, Q \leq 75\ 000$ and Sum of $M \leq 50\ 000$731No other restrictions

### Examples

| Input | Output |
| --- | --- |
| 12 9<br>1 1 2 3 2 1 2 2 2 3 1 1<br>1 1 11<br>1 3 9<br>2 6 6 1 2<br>1 3 9<br>1 1 11<br>2 4 10 4 2 2 1 1<br>1 1 12<br>1 3 9<br>1 1 11 | 7 4<br>7 3<br>4 4<br>2 6<br>5 5<br>4 5<br>2 5<br>4 4<br>1 1 2 2 2 1 1 2<br>2 1 1 1 |
