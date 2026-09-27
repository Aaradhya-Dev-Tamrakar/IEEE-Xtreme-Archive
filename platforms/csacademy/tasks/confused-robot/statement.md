# Confused Robot

**Time Limit:** `3000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/confused-robot/](https://csacademy.com/contest/archive/task/confused-robot/)  

---

With the increase of popularity in robotics, FII has developed a robot which can move (revolutionary!). In fact, he can move very fast. In order to prove that, he will be sent to a room filled with boxes. This room is N meters long and M meters wide. It will be described as a $N \times M$ matrix, where a cell filled with . is free for the robot to access and # if there is a box there. The lines will be numbered from top to bottom from $1$ to $N$ and the columns will be numbered from left to right from $1$ to $M$.

Furthermore, he will get a list of instructions which he needs to execute. This will be represented as a string containing only U, D, L and R characters. These letter instructions represent the direction in which the robot should move: U for up, D for down, L for left and R for right. If one instruction tells the robot to move out of the room, the instruction will not be executed. Also, if an instruction tells the robot to go into a box, the instruction will not be executed. This means that at any time, the robot will be only on . spaces inside the matrix.

As the developers can't assign to the robot a string too long, they will only give him a rather short string. After finishing the instructions, the robot will start executing them again from the beginning. Thus the robot will repeat the same instructions all over again - infinitely.

FII wants to see if the robot executes the instructions correctly, therefore they will calculate by hand the answers for some tests. One test sounds like: if we put the robot in a cell with coordinates $X, Y$, where will it be after $Z$ moves. There will be $Q$ such tests, and for each of them the final position should be computed. Help them with a super-efficient algorithm to determine the final position for each test. Hopefully, the robot will move correctly and respect your answers.

### Standard input

The first line contains three integers: $N$ - the number of lines in the matrix, $M$ - the number of columns in the matrix and $Q$ - the number of tests.

On the next $N$ lines there will be the description of the matrix.

On the $N+2$th line there will be a string $S$ containing the instructions for the robot.

The last $Q$ lines will contain the tests. Each of these lines will contain three integers $X, Y, Z$ - the starting coordinates and the number of moves to be simulated.

### Standard output

The output should contain $Q$ lines. The i-th line should have two integers representing the line and the column in which the robot will reside according to the i-th test.

### Constraints and notes

$1 \leq N, M \leq 500$ $1 \leq |S| \leq 100$ $1 \leq Q \leq 10^5$ $1 \leq X_i \leq N, 1 \leq Y_i \leq M$ $1 \leq Z_i \leq 10^9$ 

It is guaranteed that the initial position of the robot is free.

| Input | Output | Explanation |
| --- | --- | --- |
| 3 5 2<br>.....<br>.....<br>..#..<br>LLUR<br>2 3 2<br>3 4 6 | 2 1<br>2 3 | In the second case, the moves that are executed are LLURLL |
| 4 4 4<br>..#.<br>....<br>....<br>.#.#<br>LRURUD<br>1 4 5<br>3 3 10<br>4 1 1<br>4 3 2 | 1 4<br>1 4<br>4 1<br>4 3 |  |
