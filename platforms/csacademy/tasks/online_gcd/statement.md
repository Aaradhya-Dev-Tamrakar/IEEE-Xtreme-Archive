# Online Gcd

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/online_gcd/](https://csacademy.com/contest/archive/task/online_gcd/)  

---

You are given an array of $N$ integer values and $M$ update operations. An update consists of choosing an element of the array and dividing it by a given value. It is guaranteed that  the element is divisible by the chosen value. After each update you should compute the greatest common divisor of all the elements of the array.

### Standard input

The first line contains two integer values $N$ and $M$.

The second line contains $N$ integer values representing the elements of the array.

Each of the next $M$ lines contains two integers. The first integer is a number between $1$ and $N$ representing the index of the element in the update. The second integer represents the value by which to divide the chosen element.

### Standard output

The output should contain $M$ lines. On each line you should print the value of the greatest common divisor after each update operation.

### Constraints and notes

$1 \leq N \leq 10^5$$1 \leq M \leq 10^5$The values of the array are integers between $1$ and $2*10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 3<br>36 24 72<br>1 3<br>3 12<br>2 4 | 12<br>6<br>6 | After each operation the array values will be:$12, 24, 72$$12, 24, 6$$12, 6, 6$ |
| 5 6<br>100 150 200 600 300<br>4 6<br>2 3<br>4 4<br>1 4<br>2 5<br>5 25 | 50<br>50<br>25<br>25<br>5<br>1 | After each operation the array values will be:$100, 150, 200, 100, 300$$100, 50, 200, 100, 300$$100, 50, 200, 25, 300$$25, 50, 200, 25, 300$$25, 10, 200, 25, 300$$25, 10, 200, 25, 12$ |
| 5 3<br>1 1 1 1 1<br>1 1<br>3 1<br>5 1 | 1<br>1<br>1 |  |
| 4 4<br>100000 100000 100000 100000<br>1 1<br>2 1<br>3 1<br>4 1 | 100000<br>100000<br>100000<br>100000 |  |
