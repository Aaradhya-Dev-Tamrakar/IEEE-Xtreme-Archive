# Sure Bet

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/sure-bet/](https://csacademy.com/contest/archive/task/sure-bet/)  

---

Luck is a fundamental part of betting. Some people improve their chances and earnings by having good knowledge of what they are betting on. We will take a different approach.

Various bookmakers offer different odds or quotas for the same outcome. (An odds of $x$ means that if you bet $1$ euro and predict the outcome correctly, you get $x$ euros back. If you predict the outcome incorrectly, you of course get nothing back. Note that you pay $1$ euro regardless of the outcome.) What if you could be certain of making a profit by cleverly placing several bets? You would want to make this guaranteed profit as large as possible.

The event we want to bet on has two possible outcomes. There are $n$ bookmakers that offer different odds. Let us denote the odds offered by the $i$-th bookmaker for the first outcome with $a_i$, and the odds offered for the second outcome with $b_i$. You can place a bet on any subset of the offered odds. You can even bet on both outcomes at the same bookmaker. However, all bets have to be exactly $1$ euro and you cannot bet on the same outcome with the same bookmaker multiple times.

In case of the first outcome, you will receive $a_i$ euros from every bookmaker $i$ with whom you placed a bet on the first outcome. Similarly, in case of the second outcome, you will receive $b_i$ euros from all eligible bookmakers. Of course in both cases, you already paid $1$ euro for every bet you placed.

What is the largest guaranteed profit (i.e. regardless of the outcome) if you place your bets optimally?

### Input

The first line contains the number of bookmakers, $n$. The following $n$ lines describe the odds offered by each bookmaker with two space-separated real numbers $a_i$ and $b_i$ - the odds for the first and second outcome offered by the $i$-th bookmaker. The odds will be given to at most $4$ decimal places.

### Constraints

$0.0 \leq a_i,b_i \leq 1001.0$ $1\leq n \leq 10^5$ 

### Subtask 1 (20 points)

$n \leq 10$ 

### Subtask 2 (40 points)

$n \leq 1\,000$ 

### Subtask 3 (40 points)

no additional constraints

### Output

Output the maximum guaranteed profit rounded to exactly $4$ decimal places.

Here are the commands to print the floating point numbers in various languages:

C and C++: printf("%.4lf",(double)x)Java: System.out.printf("%.4lf",x)Pascal: writeln(x:0:4)Python 3: print("%.4lf"%x)C#: Console.WriteLine(String.Format("0:0.0000",x))

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1.4 3.7<br>1.2 2<br>1.6 1.4<br>1.9 1.5 | 0.5000 | The optimal betting strategy consists of betting on the second outcome with the first bookmaker and on the first outcome with the third and fourth bookmaker. In case of the first outcome, we will earn $1.6 + 1.9 - 3 = 0.5$ and in case of the second outcome $3.7 - 3 = 0.7$. So we’re guaranteed $0.5$ euros regardless of the outcome. |
