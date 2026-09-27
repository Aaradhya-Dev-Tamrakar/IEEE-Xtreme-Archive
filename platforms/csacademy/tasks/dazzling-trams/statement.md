# Dazzling Trams

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/dazzling-trams/](https://csacademy.com/contest/archive/task/dazzling-trams/)  

---

Did you know that the city of Iași has one of the biggest tram networks in the country? According to Wikipedia, it measures a total of 82.6 kilometers! You could certainly get lost easily, if you are not too familiar with it! Thankfully, Georgel already has a map of all the lines that currently operate in Iași, and he is hoping to use that in order to get from his home to the university, where a big event is coming up.

  

The tram infrastructure in Iași consists of $N$ stations and $M$ tram routes, each tram route consisting of a list of stops, in order of which they are visited. Each of the $M$ tram routes is bidirectional, meaning that there are trams which go along the route in the left-to-right order and in the right-to-left one, as well.

  

The ticketing system for the tram network works as follows. You can buy tickets for any station; however, one ticket will only allow you to travel on one of the $M$ available tram lines, and only for a maximum of $K$ stops. Any trip longer than $K$ stops would require extra tickets. Moreover, you can only use a ticket once, which means that if you use a ticket for taking a tram from station $a$ to station $b$, the ticket will be invalidated once you get off the tram at station $b$.

  

Georgel's house is located near station $1$, and the university resides near station $N$. Under these circumstances, Georgel would like to choose a route for which he ends up buying as few tickets as possible. What is this minimum number of tickets?

  

### Standard input

  

The first line of input contains three positive integers $N$, $M$, and $K$, the number of stations, the number of tram routes, and the maximum length for a ticket, respectively.

  

The following $M$ lines describe the tram routes. Each of the lines contains a positive number $l_i$, the number of stops of the $i^{th}$ tram route. Then follow $l_i$ numbers, denoting the stations, in the order visited by the route. Note that each route is bidirectional.

  

### Standard output

  

The output should consist of a single positive integer, the minimum number of tram tickets needed to reach the university from Georgel's house.

  

### Constraints and notes

  
$2 \leq N \leq 10^5$ $1 \leq M \leq 10^5$ $1 \leq K \leq N$ Each tram route consists of at least two stops.It is guaranteed that you can reach the university from Georgel's house.Some tram routes may contain a stop multiple times.A tram route may have multiple consecutive stops at the same station.There will be at most $2.5 \cdot 10^5$ stops in total.   

| Input | Output |
| --- | --- |
| 15 2 2<br>12 1 2 3 5 6 7 9 10 11 13 14 15<br>5 4 3 8 13 12 | 3 |
| 15 2 7<br>12 1 2 3 5 6 7 9 10 11 13 14 15<br>5 4 3 8 13 12 | 2 |
| 10 1 2<br>12 3 1 2 4 5 6 5 7 8 9 2 10 | 2 |
