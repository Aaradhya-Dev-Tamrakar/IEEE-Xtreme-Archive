# Khans

**Time Limit:** `2000 ms`  
**Memory Limit:** `64 MB`  
**Source:** [https://csacademy.com/contest/archive/task/khans/](https://csacademy.com/contest/archive/task/khans/)  

---

Elly recently learned about Bulgarian khans – rulers of nomadic tribes, which travelled around the continent for hundreds of years before finally settling for good where Bulgaria currently resides.

The continent they used to inhabit was split into $N \times M$ regions, conveniently ordered in a rectangle with $N$ rows and $M$ columns. The khans spent one year in a certain region during which they and their tribe consumed all the food there. At the end of the year they moved to one of the (up to) four neighboring by side regions, where they spent the next year consuming all the food there, and so on. We consider moving to a neighboring region happening instantaneously right at the end of the year (what are several days of travelling, compared to an entire year?). The khans never stay at the same region for two consecutive years, as their tribe would starve to death.

Each region had a maximum amount of food, which it could sustain. We will denote this maximum amount for each region with the integer $A_{i,j}$. After the khans consumed all the food and moved out of a region, the food there started replenishing. The year after the khans have left yielded $1$ unit of food. The next year the amount doubled, then on the third year it doubled again and so on, until it reached the maximum $A_{i,j}$ for this region. Please note that the amount of food never exceeded the maximum the region could sustain. For example, if the maximum amount of food for some region was $A_{i,j} = 55$, the amount of food at the beginning of each of the ten years following the departure of the khans would be, respectively, $0$, $1$, $2$, $4$, $8$, $16$, $32$, $55$, $55$, $55$ units.

The khans knew that they should never return to a region until it has recovered to its maximum amount of food – otherwise they could damage it permanently, which they did not want to do. Because of this, sometimes they would even choose a less supplied region (e.g., with $42$ units of food) over a better supplied (e.g., with $64$, but with maximum of $71$). In the example from the previous paragraph, they could return to the region at the beginning of the eight year after they left it, since it is the first one with the maximum amount of food.

Elly has the information about the continent given as the matrix $A$ with $N$ rows and $M$ columns, giving the maximum amount of food for each of the regions. At the beginning, each region contained its maximum amount of food. Knowing that the khans spent their first year in the upper left region, what is the maximum amount of food they could consume over the period of $K$ years?

### Standard input

On the first line of the standard input will be given three integers $N$, $M$, and $K$, giving, respectively, the number of rows, the number of columns, and the number of years. On each of the next $N$ lines will be given $M$ integers $A_{i,j}$, representing the maximum amount of food in each of the regions.

### Standard output

On a single line of the standard output, print one integer – the maximum total amount of food the khans could have consumed if travelling optimally.

### Constraints and notes

$1 \le N, M \le 10$ $1 \le K \le 100$ $10 \le A_{i,j} \le 100$ It is guaranteed that there will always be a path, which doesn't violate the rule about not stepping in a region which hasn't replenished all of its food.In tests worth 20% of the points for the task $1 \le N, M \le 4$ In tests worth another 20% of the points for the task $1 \le K \le 20$ Each test is scored separately

| Input | Output | Explanation |
| --- | --- | --- |
| 4 4 11<br>11 17 13 96<br>10 12 18 15<br>13 12 16 17<br>24 10 14 22 | 254 | The regions, which the khans could visit in order to consume the maximum amount of food ($254$ units), can be the ones with $11$, $17$, $13$, $96$, $15$, $17$, $22$, $14$, $16$, $18$, $15$ units of food, respectively. With this possible path they would visit only one region twice – the last one with $15$ units of food. Please also note that after the last year none of the neighboring cells has replenished their food supply yet, thus the khans cannot move. This is fine as this was the last year; however, if the khans had to travel for one more year (i.e., $K$ was $12$ instead of $11$) they would choose a different route since remaining in a cell is not an option. A possible path for $K = 12$ would be $11$, $17$, $13$, $96$, $15$, $18$, $16$, $17$, $22$, $14$, $10$, $24$ for a sum of $273$ |
| 7 10 27<br>92 33 98 66 51 65 50 28 17 65<br>81 26 35 90 51 79 16 49 26 68<br>94 16 61 45 20 31 99 75 51 73<br>17 83 11 75 59 56 15 24 63 44<br>83 32 80 49 60 83 85 98 17 76<br>16 75 81 97 89 50 80 34 79 64<br>26 64 59 37 14 30 20 58 46 66 | 2017 |  |
