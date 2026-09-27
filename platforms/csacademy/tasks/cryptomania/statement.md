# Cryptomania

**Time Limit:** `1500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cryptomania/](https://csacademy.com/contest/archive/task/cryptomania/)  

---

Creating the perfect encryption algorithm is not only a process of great thinking, but also a true art in itself! Or, at least, that's what the cryptography teacher usually tells Georgel. Impressed by the great words of wisdom, he is now working on Ciphergel, his own encryption formula, that is simple to compute, but impossible to break!

  

Let's suppose the message is encoded as an array $A$ of $N$ non-negative integers strictly less than $P$. The encryption of $A$ will be an array $B$ of $N$ non-negative integers strictly less than $P$, where the elements of $B$ are given by Georgel's magic formula:

$B_i = (a \cdot {A_i}^2 + b \cdot A_i + c) \:mod\: P$

where $P$ is a prime number, $a$, $b$, $c$ are non-negative integers, and $x\: mod\: y$ is defined as the remainder of $x$ modulo $y$.

  

Of course, the key to cracking the cipher is finding out the secret numbers $a$, $b$, and $c$. Georgel knows that, and more importantly, Georgel's teacher knows that. Sadly, that's why he wasn't just ready to give Georgel straight A's for his research work.

  

Your task is to prove Georgel that his teacher had a point, indeed! Given $P$, an unencrypted array $A$ and its encrypted version $B$, find out the numbers $a$, $b$, and $c$ that were used to generate it!

  

### Standard input

  

The first line of input contains two positive integer: $N$ (the length of both sequences), and $P$. The second line contains $N$ integers representing the original sequence. The third line contains $N$ integers representing the encrypted sequence.

  

### Standard output

  

On the first line of the output, print the three non-negative integers $a$, $b$, and $c$ on a single line.

If there are multiple solutions, output the one with the smallest $a$ value. If there are still multiple solutions, output the one with the smallest $b$ value. If there are still multiple solutions, output the one with the smallest $c$ value.

If there are no solutions, output a single word impossible.

  

### Constraints and notes

  
$1 \leq N \leq 10^5$ $2 \leq P \leq 10^6$, $\:P$ is prime.$0 \leq A_i, B_i < P$ It is guaranteed that if a solution exists, then a solution satisfying $a, b, c \leq 10^9$ exists.

| Input | Output |
| --- | --- |
| 10 11<br>1 3 5 8 3 6 7 7 0 7 <br>5 3 9 0 3 4 1 1 9 1 | 1 6 9 |
| 5 17<br>1 2 3 4 5<br>2 4 3 5 6 | impossible |
