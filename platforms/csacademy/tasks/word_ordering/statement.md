# Word Ordering

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/word_ordering/](https://csacademy.com/contest/archive/task/word_ordering/)  

---

You are given a permutation of the letters in the English alphabet and a list of strings. You should sort the list of strings, but with a twist: the lexicographical order of the letters should be the one in the permutation. Also, upper case letters are considered lexicographically greater than lower case ones.

### Standard input

The first line contains a permutation of the $26$ letters in the English alphabet. All the letters will be lower case.

The second line contains a single integer $N$ representing the number of strings that should be sorted.

Each of the next $N$ lines contains a single string.

### Standard output

The output should contain the sorted list of strings, one per line.

### Constraints and notes

$1 \leq N \leq 10^5$The length of each string is $\leq 1 000$The sum of lengths of the strings is $\leq 10^5$The permutation in the input should also be used when comparing upper case letters.The strings will contain only lower case and upper case letters.

| Input | Output |
| --- | --- |
| xyzabcopqrstuvwdefghijklmn<br>7<br>pokemons<br>zebra<br>anagram<br>yahoo<br>pokemon<br>lake<br>csacademy | yahoo<br>zebra<br>anagram<br>csacademy<br>pokemon<br>pokemons<br>lake |
| jiabcdefghklmnopqrstuvwxyz<br>10<br>Word<br>Ordering<br>Xerox<br>xeroX<br>XeroX<br>CSAcademy<br>csacademy<br>xerox<br>insertion<br>sort | insertion<br>csacademy<br>sort<br>xerox<br>xeroX<br>CSAcademy<br>Ordering<br>Word<br>Xerox<br>XeroX |
