# Attending Events

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/attending-events/](https://csacademy.com/contest/archive/task/attending-events/)  

---

Jimmy wants to plan the evenings of the upcoming nights. For this, he has noted in his calendar in each evening what event is taking place. (He wrote down 1 for a movie running in the cinema, 2 for a musical concert and 3 for a comedy show).

  

It is not necessary to attend all the events. He wants to choose as many events as possible, respecting the following restrictions:

the first event is a movie (type 1)after he watches a movie, the next event he chooses must be a musical concert (2)after he attends a musical concert (2), the next events must be a comedy show (3)after a comedy show (3), the next event must be a movie running in the cinema (1)  

In other words, he must select the longest subsequence of the form 1 2 3 1 2 3 1 2 ...  from the list of events.

  

### Standard input

The first line contains one integer $N$, the number of days for which we know the events.

The second line contains $N$ integers, the $i$-th integer denoting the type of the event in the $i$-th day. (This number is either 1, 2 or 3).

### Standard output

The first line contains one integer, the length of the longest subsequence which has the required property.

### Constraints and notes

$1 \leq N \leq 10^5$

  

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>1 2 3 2 1 | 4 |  |
| 8<br>2 1 2 2 3 1 1 2 | 5 | A valid subsequence of events could be determined by the positions 2, 3, 5, 6, 8:$2\ \underline{1}\  \underline{2}\ 2\  \underline{3}\ 1\  \underline{1}\  \underline{2}$ |
