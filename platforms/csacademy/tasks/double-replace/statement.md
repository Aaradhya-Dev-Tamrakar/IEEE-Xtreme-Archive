# Double Replace

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/double-replace/](https://csacademy.com/contest/archive/task/double-replace/)  

---

You are given $3$ strings $S$, $A$ and $B$. Replace every substring of $S$ equal to $A$ with $B$, and every substring equal to $B$ with $A$.

It is possible that two or more substrings matching $A$ or $B$ overlap. To avoid confusion about this situation, you should find the leftmost substring that matches $A$ or $B$, replace it, and then continue with the rest of the string.

For example, if $S = aab$, $A = aa$ and $B=bb$, we first find the prefix $aa$ and replace it with $bb$. Then we continue with the rest of the string that consists only of the last character $b$ and we stop because we can't find any more matches.

### Standard input

The first line contains string $S$.

The second line contains string $A$.

The third line contains string $B$.

### Standard output

Print the resulting $S$ on the first line.

### Constraints and notes

The length of all three strings is between $1$ and $1000$ $A \neq B$ $A$ and $B$ will have the same length

| Input | Output | Explanation |
| --- | --- | --- |
| aab<br>aa<br>bb | bbb | We match the first two characters with $A$ and replacing it with $B$ we get $bbb$. Then we continue the algorithm starting at index $3$ and we don't find any more matches. |
| aabbaabb<br>aa<br>bb | bbaabbaa | String $S$ is the concatenation $ABAB$, so in the end we get the concatenation $BABA$ |
| cdabcadb<br>a<br>b | cdbacbda | Each character $a$ gets replaced by $b$, and each $b$ by $a$ |
