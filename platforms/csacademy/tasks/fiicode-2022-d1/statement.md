# Dynamic Atek

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fiicode-2022-d1/](https://csacademy.com/contest/archive/task/fiicode-2022-d1/)  

---

To optimize the length of a source code, FIICoders are challenged to find a way to refactor the names of variables in such a way that the total number of characters used to be as small as possible.

A valid refactoring process is one in which the variable names don't lose their semantics. Each final version of the name should be in fact a prefix of the initial version. For example, if the variable is called magic, then we can rename it as m, ma, mag, magi, or keep its original form as magic.

Of course, a piece of code has several uses for each variable and refactoring a variable means changing its name across all references. Also, two variables which were named differently at the beginning shouldn't have the same name at the end.

You are required to find the minimum number of characters which can be used for all variables' references after a refactoring process.

### Input

The first line of the input has a single integer $n$ – the number of variable references.

The second line consists of the variable references separated by a single space. All names are made out of lowercase English letters.

### Output

The first line of the output has a single integer representing the total number of characters used for the variable references after renaming them.

### Constraints

$1 \le n \le 1\,000$ Initially, the length of every variable name is at least $1$ and at most $50$.

| Input | Output | Explanation |
| --- | --- | --- |
| 9<br>xa xab xabc xabc xabc xd xd xd xd | 16 | xa xab x x x xd xd xd xd is good and has 16 characters.x xa xab xab xab xd xd xd xd is good, but has 20 characters.x x xa xa xa xd xd xd xd is not good as two variables (xa and xab) end up having the same name.xa xb x xabc xabc xd xd xd is not good as not all references of a variable (abc) are renamed. |
