# Magic

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/magic/](https://csacademy.com/contest/archive/task/magic/)  

---

Now is the English lesson in grade 9 with Mr. Daskalov. Our main character – Deni – is very weak in English and she counts the number of flies in the room. This proves to be very boring activity, so she looks at the board where the teacher has written some text. She ignores the spaces between the words so the whole text seems to her as one big sequence of English letters with length $N$. Let us denote the number of different characters in this sequence with $K$. Deni starts to take up different substrings from this sequence and she writes down the number of times each character occurs. When for all of the $K$ letters these numbers are equal, she calls the current substring magical.

Remarks: A substring is a part of a given string, which contains consecutively written characters.

During this English lesson she is able to check every substring of the sequence. Meanwhile she has counted how many of the substrings are magical and in the end she is very happy with the accomplished activity. Deni decides that she would like to do so in every English lesson. But with every subsequent English lesson the text on the board written by Mr. Daskalov is becoming longer and longer. So she asks for your help – you have to write a program which tells her the number of magical substrings in a given sequence of $N$ English letters.

### Task

Write a program which counts the number of magical substrings in a given sequence of $N$ English letters. Substrings which are the same but on different positions are counted as different

### Input

From the first line of the standard input, your program has to read one integer $N$ – the number of characters in the sequence written by Mr. Daskalov. From the next line your program has to read a string of $N$ English letters. The letters can be lower- and uppercase. Note that the lower- and uppercase forms of the same letter are considered to be different characters (A and a are different characters).

### Output

The program must print to the standard output the number of magical substrings in the given string. Since this number may be quite large, you are required to print its remainder when divided by $10^9+7$.

### Constraints

$2 \leq N \leq 10^5$ 

### Subtask 1 (10 points)

$N \leq 100$ 

### Subtask 2 (20 points)

$N \leq 2000$ 

### Subtask 3 (30 points)

$N \leq 10^5$ There are only two kinds of characters in the given string ($K=2$).

### Subtask 4 (40 points)

There are no further constraints.

| Input | Output | Explanation |
| --- | --- | --- |
| 8<br>abccbabc | 4 | The magical substrings are abc, cba, abc and abccba. Note that for example the substring ab is not magical because the letter c is not in it. |
| 7<br>abcABCC | 1 | Only the substring abcABC is magical (the letters a and A are different because a is a lowercase letter and A is an uppercase letter). |
| 20<br>SwSSSwwwwSwSwwSwwwwS | 22 | The number of magical substrings is $22$ and one of them is SwSwwS. |
