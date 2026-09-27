# Dynamic Software

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fiicode-2022-d2/](https://csacademy.com/contest/archive/task/fiicode-2022-d2/)  

---

Mr. Mitica lives in a country with $n$ cities that are connected by $n-1$ roads. The cities are numbered from $1$ to $n$ and Mr. Mitica lives in city with number 1. He likes very much to drive, so he wants to drive as much as possible, but NEVER going closer to his house. Of course, he can only drive on the existing roads, so each time he drives to a node directly connected to the node he is currently. If there are multiple nodes to choose from, he chooses one uniformly at random (NOT necessarily the one that would make him drive the longest).

Mr. Mitica asks himself a series of $q$ questions of the following 2 types:

Question: If he would start his journey from city $i$ (he can also start from a friend's house), what would be the expected value for the length of the path from city $i$, knowing that, at each step, Mitica would travel to a neighbour city while possible? Mitica would randomly choose, with equal probability, one of the valid cities.Update: The authorities declare closed a city $i$, together with all the accessible cities from $i$ (the accessible cities are the cities that Mr Mitica could reach, following the strategy described earlier). The update remains valid for the next curiosities as well.

### Standard input

The first line of input contains an integer $n$ - the number of cities on the map. The next $n-1$ lines contain a pair of integers $x$ and $y$, one per line, meaning that there is a street between city $x$ and city $y$.

The next line contains an integer $q$, the number of curiosities that Mr. Mitica has. The next $q$ lines contain a pair of integers, $type$ and $i$, one per line, the type of curiosity Mr. Mitica has ($1$ for update, $2$ for question) and the city from which he intends to start his journey.

### Standard output

You must print, for every curiosity of type $2$ ( question ), a value that represents the expected value. If the value can be written as a irreducible fraction $p / q$, then you must print the value as $p \cdot q^{-1} \,\operatorname{mod}\, (10^9 + 7)$.

### Constraints and notes

$1 \le n \le 10^5$ $1 \le q \le 2 \cdot 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 6<br>1 2<br>2 3<br>2 4<br>4 5<br>1 6<br>10<br>2 3<br>2 4<br>2 2<br>2 1<br>1 5<br>2 1<br>1 4<br>2 1<br>1 2<br>2 1 | 0<br>1<br>500000005<br>750000007<br>500000005<br>500000005<br>1 | For the first query, node 3 is a leaf, so the path contains the node itself and the length is 0.For the second query, will certainly go to node 5, resulting a path of length 1.For the third query, with probability 0.5 the path will be 2-3, and with probability 0.5 the path will be 2-4-5, so the answer is 0.5 $\cdot$ 1 + 0.5 $\cdot$ 2 = 1.5.The answer for the fourth query is 7/4. |
