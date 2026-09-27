# Karaoke Group

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/karaoke-group/](https://csacademy.com/contest/archive/task/karaoke-group/)  

---

$N$ friends decided to go out for a karaoke night. There are $M$ total songs to choose from. For each of the $N$ friends you are given a list of the songs he likes.

Because people are shy, nobody wants to sing alone. You should find a group of friends (at least $2$ people) such that the number of songs they all like is maximized.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines describes the song preferences for one of the friends. The $i^{th}$ line contains an integer $L_i$, representing the number of songs liked by the $i^{th}$ friend, followed by $L_i$ distinct integers representing the indices of the songs.

### Standard output

Print the maximum number of songs liked by all the people in the chosen group.

### Constraints and notes

$2 \leq N \leq 100$ $1 \leq M \leq 100$ $0 \leq L_i \leq N$ The songs are identified by numbers between $1$ and $M$

| Input | Output |
| --- | --- |
| 3 4<br>2 1 2<br>2 2 3<br>2 3 4 | 1 |
| 4 3<br>1 1<br>1 2<br>1 3<br>3 1 2 3 | 1 |
| 4 6<br>3 1 2 3<br>2 2 3<br>4 1 3 4 5<br>3 4 5 6 | 2 |
