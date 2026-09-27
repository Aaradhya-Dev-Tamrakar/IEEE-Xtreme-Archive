# Crazy Atek

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fiicode-2022-c1/](https://csacademy.com/contest/archive/task/fiicode-2022-c1/)  

---

Recently, Detective Dutzi was involved in a very mysterious case. He noticed that some incidents took part in houses that, at first glance, had nothing in common. After some more thorough analysis, they found that the numbers on the houses were hiding a very fascinating particularity: the sum of digits is equal to their product. For example, Detective Dutzi noticed a criminal offence that involved the house $312$, because $3 + 1 + 2 = 3 \cdot 1 \cdot 2 = 6$.

This problem involving criminal offences is wide-spread, meaning that Dutzi needs to travel through $t$ cities and check some details for each one of them. For every city, the police is helping the detective by telling that each city contains a house with each number having the number of digits between some given limits, $l$ and $r$.

You must help Detective Dutzi in order to predict the next move of the offenders. More precisely, you must help him find the number of houses that satisfy that fascinating particularity by using the help from the police, for every city that he passes through. Because the number of houses can be very large, you must print it modulo $998\,244\,353$.

### Input

The first line contains an integer $t$ – number of cities the detective passes through. The following $t$ lines contain the information given by the police: two integers $l$ and $r$ representing the minimum and maximum number of digits that a house number from that city can have.

### Output

For every city the detective passes through, you must print the number of houses that are in the offender's sight (the sum of digits is equal to the product of digits), given the fact that each house has a number of digits between $l$ and $r$.

### Constraints

$1 \le t \le 10^5$ $1 \le l \le r \le 10^{12}$

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>1 3<br>2 2<br>1 1000000000000 | 16<br>1<br>600574323 | For the first test, the city contains houses with all numbers between $1$ and $999$. Among these, only $16$ numbers meet the fascinating particularity. |
