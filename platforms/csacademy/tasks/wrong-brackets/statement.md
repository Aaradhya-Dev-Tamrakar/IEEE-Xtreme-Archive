# Wrong Brackets

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/wrong-brackets/](https://csacademy.com/contest/archive/task/wrong-brackets/)  

---

A bracket sequence $S$ is a correct bracket sequence if either of the following holds :

It is empty.It is the concatenation of $2$ correct bracket sequences.It is of the form $(T)$, where $T$ is a correct bracket sequence.

For example, $(()), (()()), (()(()))(()())$ are correct bracket sequences while  $())(,(()))(,()((,($ are not correct bracket sequences.

Consider strings of length $2*N$ consisting of $N$ open brackets and  $N$ closed brackets. From all these strings that are not correct bracket sequences, which is the $K^{th}$ in lexicographical order?

### Standard input

The first line contains two integers $N$ and $K$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 30$ $1 \leq K$ $K$ fits on a signed $64$ bit integerOn all the tests there are at least $K$ strings that are not bracket sequencesCharacter ( comes before ) in lexicographical order

| Input | Output |
| --- | --- |
| 1 1 | )( |
| 2 2 | )(() |
| 3 10 | )()()( |
