# Seven-segment Display

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/seven-segment-display/](https://csacademy.com/contest/archive/task/seven-segment-display/)  

---

A Seven-segment display (SSD), or seven-segment indicator, is a form of electronic display device for displaying decimal numerals.

Below you can see the representation of every decimal digit.

Different digits use a different number of segments in their representation. For example, $0$ uses $6$ segments, while $1$ uses only $2$.

You are given a number $K$, what is the smallest non-negative integer that uses exactly $K$ segments in its representation?

### Standard input

The first line contains a single integer $K$.

### Standard output

If there is no solution print $-1$.

Otherwise, print the answer on the first line. The number can be quite large and doesn't necessarily fit in a 64 bit integer.

### Constraints and notes

$1 \leq K \leq 10^5$ 

| Input | Output |
| --- | --- |
| 7 | 8 |
| 10 | 22 |
| 12 | 28 |
