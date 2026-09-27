# Printer

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/printer/](https://csacademy.com/contest/archive/task/printer/)  

---

You just bought a new printer and would like to build a stash of ink cartridges for future use. There are $4$ types of cartridges. For each type you know the minimum number of cartridges you need, and their price. In addition to buying a cartridge separately, you can also choose to go for a bundle: buying 4 cartridges, one of each type, for a fixed price.

### Standard input

The first line contains $4$ integers representing the minimum number of cartridges of each type that you need.

The second line contains $4$ integers representing the price of buying each individual type of cartridge.

The third line contains a single integer representing the price of a bundle.

### Standard output

On the first line print the minimum price which must be paid in order to satisfy all the requirements.

### Constraints and notes

All the input values are integers between $0$ and $10^9$, with the additional restriction that the prices are stricty positive.

| Input | Output | Explanation |
| --- | --- | --- |
| 7 2 3 7<br>2 2 2 2<br>5 | 31 | buy $3\ \text{bundles}$ for $15$ buy $4$ cartridges of the first type for $8$ buy $4$ cartridges of the last type for $8$ Total cost: $15 + 8 + 8 = 31$ Note that you have an additional cartridge of type $2$ but that's allowed. |
| 3 0 0 5<br>3 3 3 2<br>7 | 19 | buy $3$ cartridges of the first type for $9$ buy $5$ cartridges of the last type for $10$ Total cost: $9 + 10 = 19$ |
| 0 2 3 5<br>2 2 2 2<br>5 | 18 | buy $2\ \text{bundles}$ for $10$ buy $1$ cartridge of the $3rd$ type for $2$ buy $3$ cartridges of the last type for $6$ Total cost: $10 + 2 + 6 = 18$ Note that you have additional cartridges of type $1$ even if you don't need any! |
