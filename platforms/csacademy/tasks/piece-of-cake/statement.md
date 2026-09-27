# Piece of Cake

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/piece-of-cake/](https://csacademy.com/contest/archive/task/piece-of-cake/)  

---

Alice and Bob have a table with $N$ pieces of cake of various weights. They invented a game to help them eat all the cake. The players move alternatively, with Alice going first. In each turn, the player which has to move selects one of the cake pieces and cuts it into two parts. The other player selects one of the parts which will be eaten by the player who cut the cake, while the part that was not eaten remains on the table and can be selected in the following turns.

In other words, the process goes like this:

Alice selects one cake of weight $w$ and cuts it into two parts of weights $x$ and $y$ ($w = x + y$). Bob chooses either the part of weight $x$, or the one with weight $y$ (let's say he chooses $x$). Alice will then eat the part with weight $x$ and put the one with weight $y$ back on the table. Bob selects one cake of weight $w'$ and cuts it in two parts of weights $x'$ and $y'$ ($w' = x' + y'$). Alice chooses either the part of weight $x'$, or the one with weight $y'$ (let's say she chooses $x'$). Bob will eat the part with weight $x'$ and put the one with weight $y'$ back on the table. The process continues indefinitely.

  

However, Alice and Bob are smart, and they have easily figured out that the game they created would turn out to be infinite. Trusting that each other will always try to maximize the amount of cake eaten, they have decided to find the amount of cake that each of them will end up eating after playing this game for an infinite amount of time.

  

Print two numbers, the total amount of cake eaten by Alice and the total amount eaten by Bob, if both want to maximize the amount of cake they eat.

### Standard input

The first line contains the number $N$ of pieces of cake on the table.

The second line contains $N$ positive integers $w_1, w_2, ..., w_N$, the weights of the pieces.

### Standard output

In the first line print the amount of cake eaten by Alice, and in the second line the amount of cake eaten by Bob, considering the scenario that they would play the game indefinitely. It can be proven that the answers can be written in the form $p/q$, where $p$ and $q$ are positive coprime integers. You are required to print both answers in this format (like in the samples).

  

### Constraints and notes

$1\leq N\leq 10^5$ All the weights are positive integers, not exceeding $10^6$.

| Input | Output |
| --- | --- |
| 3<br>1 2 3 | 7/2<br>5/2 |
| 2<br>2 5 | 9/2<br>5/2 |
| 2<br>5 5 | 5/1<br>5/1 |
| 4<br>7 2 2 5 | 9/1<br>7/1 |
