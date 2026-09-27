# Toys Big

**Time Limit:** `5000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/toys-big/](https://csacademy.com/contest/archive/task/toys-big/)  

---

Note that the task was splitted into $2$ tasks:

Toys Small Toys Big 

This was done due to different time limits per subtasks. This task is worth $21$ points.

Johnny collects toys. His collection may contain many toys of many different types: cars, trucks, diggers and many more. He may own more than one piece of the same toy, e.g. four trucks, in which case all the pieces are indistinguishable for him.

Emma asked Johnny how many toys he has. Not wanting to reveal the secret, he answered with a riddle (it is typical for him): $\text{If I chose a different set of my toys for each day, I could play for } n \text{ days.}$ In other words, for every two days there is a type of toy with a different quantity. Here, Johnny considers an empty set of toys as a valid set.

Emma likes neither the answer and nor this riddle, but she is really curious to know how many toys Johnny has. She asked you for help.

Can you determine all possibilities of the number of toys that Johnny may have in his collection?

### Standard input

The first (and the only one) line of the standard input contains an integer $n$.

### Standard output

The first line of the standard output should contain one integer $r$, the number of solutions (that is, the number of possibilities of the number of toys in Johnny's collection).

The second line should contain a strictly increasing sequence of $r$ integers that represents the numbers of toys that Johnny may have in his collection.

### Constraints and notes

$1 \le n \le 10^9$ 

### Subtasks

SubtaskAdditional constraintsNumber of points*1$n \le 50$ (available in task Toys Small)$19$*2$n \le 10\,000$ (available in task Toys Small)$20$*3$n \le 100\,000$ (available in task Toys Small)$20$*4$n \le 10^8$ (available in task Toys Small)$20$5no additional constraints$21$

| Input | Output | Explanation |
| --- | --- | --- |
| 12 | 4<br>4 5 6 11 | Johnny could have:two trucks, one car, and one digger ($4$ toys in total)three trucks and two cars ($5$ toys in total)five trucks and one car ($6$ toys in total)eleven trucks ($11$ toys in total)Each of these options guarantees exactly $12$ days of fun.For example, if he has eleven trucks, he can choose a set of $i-1$ trucks on the $i$-th day (for $i=1,...,12$). |
| 36 | 8<br>6 7 8 10 11 13 18 35 | Note that there are two different sets of $10$ toys that guarantee $36$ days of fun:one truck, one car, and eight diggersfive trucks and five diggersStill, only one of them is output.To get $6$ toys in~total, Johnny could have one truck, one car, two diggers and two buses. |
