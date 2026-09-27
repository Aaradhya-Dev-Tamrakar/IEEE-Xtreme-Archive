# Aisimok

**Time Limit:** `500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/aisimok/](https://csacademy.com/contest/archive/task/aisimok/)  

---

Paftenie the master-mason was given a new mission from king Reginald the Outstanding! His Excellency ordered him to make $n$ lighting poles, of various heights, for the promenade in the royal court. To do this, Paftenie has an unlimited number of steel segments of length $1$.

At each step, the master-mason chooses two segments from this heap (of lengths $a$ and respectively $b$) and he welds them, obtaining a new segment of length $a + b$, which he puts back in the heap. The goal is that at the end, among the segments in the heap, there should be $n$ segments of lengths corresponding to the pillars required by the king.

Since this is a laborious process, Macarie offered to weld some segments for Paftenie as well, but with one condition: For two segments to be welded by Macarie, their lengths must be equal.

Since Paftenie is cunning, he realized that he can get rid of a lot of work if he chooses the right segment pairs to be welded by Macarie. Therefore, Paftenie asks you to find the minimum number of welds that he needs to make in order to build the $n$ lighting poles.

### Standard input

The first line contains $n$, the number of lighting poles. The second line contains $n$ positive integers, representing their heights.

### Standard output

The output contains a single number – the minimum number of welds that Paftenie has to make.

### Constraints and notes

$1 \le n \le 10^5$ The heights of the pillars are integers between $1$ and $10^{9}$.

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>3 1 | 1 | Macarie welds two segments of length $1$, obtaining one of length $2$. Then, Paftenie welds it with one of length $1$, obtaining the segment of length $3$. In the infinite segment heap there already exists one of length $1$, so the process finished (with only one weld from Paftenie). |
