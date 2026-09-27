# Telegraph

**Time Limit:** `1500 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/telegraph/](https://csacademy.com/contest/archive/task/telegraph/)  

---

You have a text that you wish to send to your friend using a telegraph. When dealing with a telegraph, you can transmit two different symbols: $.$ and $\_$. You and your friend should find a way to codify the letters in the text, i.e. to associate each letter with a string formed only by $.$ and $\_$. An encoding is valid if you cannot find two letters such that the string associated with one of them is a prefix of the string associated with the other one. For example if you codify letter $A$ by $.\_$ you are allowed to codify $B$ by $\_.\_$, but not by $.\_.$.

It takes one second to send a $.$ and two seconds to send a $\_$. You should find a valid encoding such that the total time of sending the text using the telegraph is minimum.

### Standard input

Instead of containing the text itself, the first line consists of a single integer $N$, representing the number of distinct letters in the text.

The second line contains the $N$ values representing the frequencies of the letters in the text.

### Standard output

The output should a single integer representing the minimum time necessary to send the text over the telegraph using a valid encoding.

### Constraints and notes

$1 \leq N \leq 750$The frequencies of the letters are integers between $1$ and $10^5$For 15% of the test cases, $N \leq 15$For 40% of the test cases, $N \leq 100$For 70% of the test cases, $N \leq 400$

| Input | Output |
| --- | --- |
| 3<br>2 1 1 | 9 |
| 4<br>1 2 3 4 | 27 |
| 4<br>1 2 2 3 | 22 |
| 5<br>1 1 1 1 1 | 17 |
| 5<br>2 2 2 2 2 | 34 |
