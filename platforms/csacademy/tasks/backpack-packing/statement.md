# Backpack Packing

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/backpack-packing/](https://csacademy.com/contest/archive/task/backpack-packing/)  

---

You have two backpacks of volumes $A$ and $B$. You also have $N$ objects, for each object $i$ you know its volume $V_i$.

You are planning to go on a trip, so you decide to pack the objects. You take each object in order and try to pack it in the backpack that's got the most room left. If you can't pack an object you are going to leave it home.

Find the number of objects left home.

### Standard input

The first line contains three integers $A$, $B$ and $N$.

The second line contains $N$ integers representing the volumes of the objects.

### Standard output

Print a single integer representing the number of objects left home.

### Constraints and notes

$1 \leq A, B \leq 10^5$ $1 \leq N \leq 100$ $1 \leq V_i \leq 10^5$ The objects are packed in the order given in the input

| Input | Output | Explanation |
| --- | --- | --- |
| 7 5 8<br>3 1 4 2 5 1 4 3 | 3 | The steps of packing are:$A=\{\},\ B=\{\}$$A=\{3\},\ B=\{\}$$A=\{3\},\ B=\{1\}$$A=\{3,4\},\ B=\{1\}$ (item with volume 4 can also be inserted in the second backpack) $A=\{3,4\},\ B=\{1,2\}$$A=\{3,4\},\ B=\{1,2\}\$ (item with volume 5 is left home)$A=\{3,4\},\ B=\{1,2,1\}$$A=\{3,4\},\ B=\{1,2,1\}\$ (item with volume 4 is left home)$A=\{3,4\},\ B=\{1,2,1\}\$ (item with volume 3 is left home) |
| 10 10 4<br>2 4 1 5 | 0 | The steps of packing are:$A=\{\},\ B=\{\}$$A=\{2\},\ B=\{\}$$A=\{2\},\ B=\{4\}$$A=\{2,1\},\ B=\{4\}$$A=\{2,1,5\},\ B=\{4\}$ |
| 5 5 6<br>1 4 5 2 3 4 | 3 | The steps of packing are:$A=\{\},\ B=\{\}$$A=\{1\},\ B=\{\}$$A=\{1\},\ B=\{4\}$$A=\{1\},\ B=\{4\}$ (item with volume 5 is left home)$A=\{1,2\},\ B=\{4\}$$A=\{1,2\},\ B=\{4\}$ (item with volume 3 is left home)$A=\{1,2\},\ B=\{4\}$ (item with volume 4 is left home) |
