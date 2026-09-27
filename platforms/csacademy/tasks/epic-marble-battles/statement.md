# Epic Marble Battles

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/epic-marble-battles/](https://csacademy.com/contest/archive/task/epic-marble-battles/)  

---

Every successful game starts with a brilliant idea, and Georgel knows that. Peer pressured by his colleagues and his university teacher, he started to develop Epic Marble Battles: the multiplayer marble-matching competitive game of the century, and he has already released its first version to the public!

  

The game consists in a long string of marble balls. In the first version of the game, each marble can have one of two colors: azure or blue. The two players alternate turns. Suppose the player that starts the game is $P1$ and the second player is $P2$.

  

In each of $P1$'s turns, they can take one blue marble and replace it with two azure marbles (because, objectively speaking, azure is a superior color to blue). For example, if the string of marbles is $abbab$, player $P1$ can choose to take the third marble and replace it with two azure marbles in its place, effectively transforming the string into $abaaab$. However, nothing stops $P1$ to choose the second or the fifth marble instead.

  

In each of $P2$'s turns, they can take three adjacent azure marbles and remove them from the string. For example, if the string of marbles is $abaaab$, player $P2$ can choose to take the third, fourth and fifth marbles out of the string, effectively transforming it into $abb$. Note that taking this is the only valid move that player $P2$ has for this string.

  

If, at any moment, one of the players has no way of making a move, they lose.

  

The game became so popular around the university that people are starting to write strategy guides, organize tournaments, and even bet peanuts on the outcome of the game! You, however, are somewhat unimpressed about the game mechanics, reasoning that you could win every time on any scenario, no matter how well your opponent may play. You have decided to prove this to Georgel, by playing $T$ different scenarios against him.

  

One question remains: Do you want to play first or second?

  

### Standard input

  

The first line of input contains a positive integer $T$, denoting the number of scenarios that you will play against Georgel. Each of the next $T$ lines will describe the initial configuration of the string of marbles: a lowercase a corresponds to an azure marble, whereas a lowercase b corresponds to a blue marble.

  

### Standard output

  

The output should contain the answer for each scenario, on a separate line. Output First if you want to go first, or Second if you want to go second.

  

### Constraints and notes

$1 \leq T \leq 10$ Each string will consist of at least $1$ and at most $10^5$ marbles.   

| Input | Output |
| --- | --- |
| 3<br>bb<br>bbab<br>ab | First<br>First<br>Second |
