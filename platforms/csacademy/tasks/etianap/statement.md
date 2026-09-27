# Etianap

**Time Limit:** `1500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/etianap/](https://csacademy.com/contest/archive/task/etianap/)  

---

In the Outstanding Kingdom, there is a vacant post of master-mason. For that reason, King Reginald the Outstanding summoned $n$ candidates to the royal court for this job and calculated a masonry coefficient for each of them.

Being more indecisive of his kind, King Reginald the Outstanding needs several days to decide which craftsman to choose, namely $q$ days. Thus, every day, he chooses a number $k$ and is interested to see how many masters from a certain subsequence are prepared for the grand final.

For a master-mason to be ready for the grand final, his masonry coefficient and the number chosen by the king that day have to be coprime. Your mission is to compute, for each day, the number of masons ready for the grand final from the subsequence $[x, y]$ chosen by the king that day.

### Standard input

The first line contains the number $n$ – the number of candidates. On the next line there are $n$ positive integers, representing the coefficient of each master-mason.

The third line contains the number $q$, and each of the next $q$ lines will contain three numbers of the form x y k, representing the subsequence and the number chosen by the king on the corresponding day.

### Standard output

The output consists of $q$ lines, the $i$'th one containing the number of master-masons from day $i$ that are ready for the grand final.

### Constraints and notes

$1 \le n, q \le 10^5$ $1 \le k \le 10^6$ $1 \le x \le y \le n$ The masonry coefficients are integers between $1$ and $10^6$.Two integers are called coprime if their greatest common divisor is $1$.By "subsequence $[x, y]$" we refer to the elements located at positions $x, x + 1, \ldots, y$ in the given sequence.

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>20 7 23 14 6<br>1<br>2 5 7 | 2 | The numbers from subsequence $[2, 5]$ that are coprime with $7$ are $23$ and $6$. |
