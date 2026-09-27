# B9i

**Time Limit:** `500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/b9i/](https://csacademy.com/contest/archive/task/b9i/)  

---

Alex and Paul got bored playing with strings, so this time they came up with a coin game. On the table there are $n$ coins, numbered from $1$ to $n$, from left to right, each one being labeled with a letter (A if it's Alex's coin, or P if it belongs to Paul).

The game consists of iterating over the coins from left to right, the player whom the current coin belongs to having the right to remove one of the opponent's coins from the table. The player that remains with no coins loses the game. When an iteration finishes and both players still got coins on the table, a new iteration begins from the first position.

Knowing that both Alex and Paul play optimally, your mission is to print the name of the winner.

### Standard input

The first line contains a single integer $n$ – the number of coins on the table. The second line contains a string of length $n$ consisting only of A and P characters – the configuration of the table.

### Standard output

The output contains a string – either Alex or Paul, according to who wins the game.

### Constraints and notes

$1 \le n \le 300\,000$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>AAPPP | Alex | Step 1. Alex has the first coin, so he removes one of Paul's coins. The remaining coins on the table are AAPP.Step 2. Alex has the second coin, so he removes one of Paul's coins. The remaining coins on the table are AAP.Step 3. Paul has the third coin, so he removes one of Alex's coins. The remaining coins on the table are AP.Step 4. A new iteration begins, since both players have coins left on the table. Alex has the first coin, so he removes the last coin that belongs to Paul. The remaining coin(s) on the table are A.Alex is declared the winner, so we print Alex. |
