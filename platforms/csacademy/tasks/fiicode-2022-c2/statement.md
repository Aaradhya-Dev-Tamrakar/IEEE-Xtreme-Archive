# Crazy Software

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fiicode-2022-c2/](https://csacademy.com/contest/archive/task/fiicode-2022-c2/)  

---

Gareth the Green Duck is a big fan of quality music, so he decided to make a playlist with the best $n$ rap songs of all time. For this purpose, Gareth chose tracks from the discographies of $k$ artists, specifically $a_i$ tracks for each artist/band $i$.

However, these songs cannot be arranged in any order! Since he is a perfectionist, Gareth wants his playlist to obey the following rule: Between any two consecutive songs of the same rapper, there must be exactly one song of a different rapper.

For example, let's say that Gareth wants to listen to $3$ songs of Wu-Tang Clan and $3$ songs of Cypress Hill. He cannot listen to two consecutive Wu-Tang songs, because he would be hit by too many deep lyrics at once. Neither can he listen to two Cypress Hill tracks one after the other, because of the psychedelic beats of DJ Muggs. Therefore, the only possible playlists are $\langle \texttt{WT}, \texttt{CH}, \texttt{WT}, \texttt{CH}, \texttt{WT}, \texttt{CH} \rangle$ and $\langle \texttt{CH}, \texttt{WT}, \texttt{CH}, \texttt{WT}, \texttt{CH}, \texttt{WT} \rangle$.

Unfortunately, Gareth isn't just a perfectionist, but also a guy obsessed with numbers, his favorite one being $1.618$. Another particularly interesting number to Gareth is $666\,013$. Thus, he asks you to find the total number of possible playlists modulo $666\,013$.

### Input

The first line of the input contains two integers $n$ and $k$, representing the number of tracks and the number of artists. The second line contains $n$ positive integers, representing the sequence $a_1, a_2, \ldots, a_n$.

### Output

The output contains a single integer, representing the number of playlists modulo $666\,013$.

### Constraints

$1 \le k \le n \le 500$ $a_1 + a_2 + \cdots + a_k = n$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 3<br>2 1 2 | 4 | $\langle 1, 3, 1, 3, 2 \rangle\\ \langle 2, 1, 3, 1, 3 \rangle\\ \langle 2, 3, 1, 3, 1 \rangle\\ \langle 3, 1, 3, 1, 2 \rangle$ |
