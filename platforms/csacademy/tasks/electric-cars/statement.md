# Electric Cars

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/electric-cars/](https://csacademy.com/contest/archive/task/electric-cars/)  

---

There are $N$ electric cars, each of them being characterised by one integer $C$, representing the capacity of the battery. In order to charge the car's battery, each car will come to the only charging station which can charge $1$ unit of energy per second. If multiple cars want to charge at the same time, the charging station will only charge one car, the car that appears first in the input.

Knowing for each car the time $T$ when it arrives at the charging station, compute the time when the car will be fully charged. Find this value for each car.

### Standard input

The first line contains a single integer $N$.

Each of the following $N$ lines contains two integers $C$ and $T$ describing a car.

### Standard output

You should output $N$ lines, line $i$ containing the time when the $i$th car will be fully charged.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq C_i \leq 10^9$ $0 \leq T_i \leq 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>100 100<br>200 0 | 200<br>300 | The second car will charge until $T=100$.At $T=100$ the first car will come to the charging station, and it'll have priority.The first car will finish charging at $T=200$ and after that, the charging station will continue to charge the second car. |
| 2<br>100 100<br>100 500 | 200<br>600 | There is no overlapping when charging the cars.The first car will finish charging at $T=200$ $(arrival\ time = 100 + capacity = 100)$ The second car will finish charging at $T=600$ $(arrival\ time = 500 + capacity = 100)$ |
| 4<br>50 300<br>100 250<br>100 200<br>100 150 | 350<br>400<br>450<br>500 | $T = [150, 200)$ - charge $4th$ car.$T = [200, 250)$ - charge $3rd$ car.$T = [250, 300)$ - charge $2nd$ car.$T = [300, 350)$ - charge $1st$ car.$T = [350, 400)$ - charge $2nd$ car.$T = [400, 450)$ - charge $3rd$ car.$T = [450, 500)$ - charge $4th$ car. |
| 3<br>300 0<br>100 100<br>100 300 | 300<br>400<br>500 | $T = [0, 300)$ - charge $1st$ car.$T = [300, 400)$ - charge $2nd$ car.$T = [400, 500)$ - charge $3rd$ car. |
