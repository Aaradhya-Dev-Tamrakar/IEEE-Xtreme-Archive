# Play Time

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/play-time/](https://csacademy.com/contest/archive/task/play-time/)  

---

Alex and Paul play a game on a dictionary consisting of $N$ words. Players make the following move in turns: choose any word still present in the dictionary; remove it, along with all of its prefixes.

The player who is unable to make a move loses the game.

  

Alex moves first. In how many ways can Alex choose his first word in order to guarantee a win, considering that both of them play optimally?

  

### Standard input

  

The first line contains one integer $N$, the number of words in the dictionary.

Each of the next $N$ lines contain one word consisting of Latin lower-case characters.

  

### Standard output

  

Print the number of initial moves Alex can make in order to guarantee winning the game. If he cannot win the game no matter what, print "0" (without quotes).

  

### Constraints and notes

  
$1 \leq N \leq 10^5$ It is guaranteed that the sum of the lengths of the words in the dictionary does not exceed $10^6$. All the words in the input are distinct.  

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>a<br>ba<br>bac<br>z | 1 | Alex can win only by choosing the word "bac" (the words "bac" and "ba" are both removed after this step). |
| 4<br>cd<br>dc<br>b<br>a | 0 | No matter how Alex plays, Paul will win the game. |
| 5<br>a<br>b<br>c<br>d<br>e | 5 | Alex can choose any word as his first move. |
