# Gerrymandering

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/gerrymandering/](https://csacademy.com/contest/archive/task/gerrymandering/)  

---

Gerrymandering is a practice intended to establish a political advantage for a particular party or group by manipulating district boundaries.

An election between the political parties $A$ and $B$ has taken place in $N$ counties. Therefore, each county has chosen to represent either $A$ or $B$.

Each county is either small or large. You are to partition them into districts so that:

Each county belongs to one districtIf counties $i$ and $j$ ($1 \leq i < j \leq N$) belong to the same district, then counties $i + 1, i + 2, \ldots, j - 1$ must also belong hereEach district must contain one and only one large county

$A$ is majority in a district if the number of counties (belonging to this district) voting for it is greater or equal to the number of counties voting for the opposite party.

Find a split which maximizes the number of districts in which $A$ is majority. Print its number of districts.

### Standard input

The first line contain an integer $N$.

The next $N$ lines characterize the counties with two letters.

The first letter is either $A$ or $B$, representing the elected party in this county.

The second letter is either $S$ or $L$, where $S$ stands for small county and $L$ large county.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ There is at least one large country

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>A L<br>B S | 1 | The counties that are belonging in the same district are inside the same $[brackets]$The large counties are underlined.$[\underline{A}\ B]$The district has even votes, so the winner is party $A$. |
| 3<br>A L<br>B S<br>B L | 1 | $[\underline{A}][B\ \underline{B}]$The first district is won by party $A$ while the second one goes to party $B$. |
| 13<br>A S<br>A L<br>B S<br>B S<br>B S<br>B S<br>A S<br>A L<br>B S<br>B L<br>B S<br>B S<br>A L | 3 | $[A\ \underline{A}\ B\ B][B\ B\ A\ \underline{A}][B\ \underline{B}\ B\ B][\underline{A}]$Party $A$ has a majority in districts $1, 2, 4$ while party $B$ only has majority in district $3$. |
