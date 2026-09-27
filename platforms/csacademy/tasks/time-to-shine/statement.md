# Time to Shine

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/time-to-shine/](https://csacademy.com/contest/archive/task/time-to-shine/)  

---

After lot of individual training, Gică decided to continue his experience along with some teammates. Thus, he went to a course named CP (Competitive Programming) so he can find a suitable team.

Once he got there, the professor started to give examples of problems which can be encountered in a contest. The first one sounded like follow:

Given a sequence $A$ of $N$ integers, the students should determine $\sum A_i \cdot A_j$, for each $i < j$, so the sum of all products of 2 elements which are in distinct positions. Please refer to the samples for more details.

In order to get in the best team at CP, Gica should resolve it as efficient as possible. As he is a bit nervous, he asked for your help.

### Standard input

On the first line of input, there is the integer $N$  - the number of elements in the sequence.

On the second line of input, there are $N$   integers - the numbers forming the sequence $A$.

### Standard output

On the first and only line of input, there should be a positive integer - the answer to the problem.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq A_i \leq 10^4$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>3 1 1 | 7 | The answer is obtained as follows:$A_1 \cdot A_2 = 3 \cdot 1 = 3$$A_1 \cdot A_3 = 3 \cdot 1 = 3$$A_2 \cdot A_3 = 1 \cdot 1 = 1$So the sum is $3+3+1=7$ |
| 2<br>7 5 | 35 | There are only 2 integers so the answer is simply $A_1 \cdot A_2=7 \cdot 5=35$ |
