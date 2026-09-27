# Cats and Dogs

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cats-and-dogs/](https://csacademy.com/contest/archive/task/cats-and-dogs/)  

---

In a city there are $N$ cats and $M$ dogs. We represent the city as a coordinate system, for each animal you are given its coordinates.

Each dog will run to the closest cat. If there are multiple closest cats, a dog will chose the one with the lowest index.

Count the number of cats such that exactly one dog will run to them.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains two integers representing the coordinates of a cat.

Each of the next $M$ lines contains two integers representing the coordinates of a dog.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N, M \leq 2000$ The coordinates are integers in $[-10^4, 10^4]$ There will not be two animals at the same coordinatesIn this problem you should work with Euclidian distances

| Input | Output |
| --- | --- |
| 3 3<br>1 1<br>1 2<br>1 3<br>2 1<br>3 1<br>2 2 | 1 |
| 2 2<br>1 1<br>1 3<br>2 1<br>1 2 | 0 |
| 2 2<br>1 3<br>1 1<br>2 1<br>1 2 | 2 |
