# Archetype 08: String Algorithms

> **Grounding Metadata & NotebookLM Oracle**  
> - **Archetype ID:** `08_string_algorithms`  
> - **Target Notebook ID:** `95a79d26-2f87-42cd-8cb9-8361a1e56059` (*Personal Notebook: ⚙️ Aaradhya — Engineer's Personal Notebook*)  
> - **Total Archived Tasks:** `55`  
> - **Sub-Archetypes:** Knuth-Morris-Pratt (Prefix Function $\pi$), Z-algorithm, Rolling Hash (Rabin-Karp), Suffix Automaton (SAM), Suffix Array & LCP, Aho-Corasick Multi-Pattern Automaton, Manacher's Algorithm  
> - **Compiler Standards:** `g++ 15.2.0` (`-std=c++23 -O2 -pthread`) on Ubuntu 25.04 x64  

---

## 1. Executive Overview & Core Principles

String algorithms process sequences of characters over finite alphabets $\Sigma$. Problems involve exact pattern matching, counting distinct substrings, finding longest palindromes, and multi-pattern dictionary indexing.

The core insight is **prefix/suffix period duality**: periodicity in strings translates to self-overlap, captured by the **KMP prefix function** or **Z-array** in $O(N)$ deterministic time.

---

## 2. Key Mathematical Patterns & Algorithms

### 2.1 Knuth-Morris-Pratt (Prefix Function $\pi$)
The prefix function $\pi[i]$ is the length of the longest proper prefix of $s[0 \dots i]$ that is also a suffix of $s[0 \dots i]$:
$$\pi[i] = \max \{ k < i + 1 \mid s[0 \dots k-1] = s[i-(k-1) \dots i] \}$$
- Computed in strictly $O(N)$ time via amortized pointer backtracking.
- **Periodicity Theorem:** A string $S$ has a period of length $p \iff p \mid |S|$ and $|S| - \pi[|S|-1] = p$.

### 2.2 Z-Algorithm
$Z[i]$ is the length of the longest common prefix between $S$ and the suffix of $S$ starting at index $i$:
$$Z[i] = \text{LCP}(S, S[i \dots |S|-1])$$
Maintains a segment $[L, R]$ of the rightmost matched prefix, achieving $O(N)$ runtime.

### 2.3 Polynomial Rolling Hash (Rabin-Karp)
Maps substring $S[l \dots r]$ to an integer hash value:
$$H(S[l \dots r]) = \left( \sum_{i=l}^r S[i] \cdot B^{r - i} \right) \pmod M$$
Substrings hashes are computed in **$O(1)$ time** using prefix hashes and precomputed powers of base $B$:
$$H(S[l \dots r]) = \left( H[r + 1] - H[l] \cdot B^{r - l + 1} \right) \pmod M$$
Double hashing with $(M_1 = 10^9+7, M_2 = 10^9+9, B_1 = 313, B_2 = 317)$ prevents hash collision hacks.

### 2.4 Suffix Automaton (SAM)
The minimal deterministic finite automaton (DFA) recognizing all suffixes of string $S$:
- Maximum vertices: $2N - 1$.
- Maximum transitions: $3N - 4$.
- Built online in $O(N)$ time.
- Answers distinct substring counts, substring occurrences, and shortest unrepresented strings in $O(|P|)$ time.

---

## 3. Sub-Archetypes Taxonomic Breakdown

```
String Algorithms
 ├── Linear Matching Primitives
 │    ├── KMP Prefix Function (Border tree, Periodicity)
 │    ├── Z-Algorithm (Longest common prefix intervals)
 │    └── Rolling Hash (O(1) substring equivalence, Double hash)
 ├── Suffix & Substring Automata
 │    ├── Suffix Array + LCP Array (Kasai's algorithm in O(N))
 │    ├── Suffix Automaton (SAM - DAG of substring equivalence classes)
 │    └── Aho-Corasick Automaton (Dictionary matching with failure links)
 └── Palindromic Structures
      ├── Manacher's Algorithm (O(N) all-centers palindromic radii)
      └── Palindromic Tree (EERTREE - Substring palindrome transitions)
```

---

## 4. Canonical Problem Deep-Dives from Archive

### 4.1 Word Ordering (`word_ordering`)
- **Contest:** Round #1 | **Difficulty:** EASY | **Platform Slug:** [`word_ordering`](../platforms/csacademy/tasks/word_ordering/statement.md)
- **Problem Statement:** Given a custom permutation of the Latin alphabet and a list of words, sort the words according to the custom lexicographical order.
- **Mathematical Invariant:**
  Map each character $c$ to its custom rank $R(c) \in [0, 25]$. Compare two strings character-by-character using $R(c)$.
- **Optimal Complexity:** $O(N \cdot L \log N)$ where $L$ is max word length.
- **Production C++23 Implementation:**
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string alpha;
    if (!(cin >> alpha)) return 0;

    vector<int> rank_map(256, 0);
    for (int i = 0; i < 26; ++i) {
        rank_map[alpha[i]] = i;
    }

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    sort(words.begin(), words.end(), [&](const string& a, const string& b) {
        int len = min(a.size(), b.size());
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                return rank_map[a[i]] < rank_map[b[i]];
            }
        }
        return a.size() < b.size();
    });

    for (const string& w : words) {
        cout << w << "\n";
    }
    return 0;
}
```

### 4.2 Anagrams (`anagrams`)
- **Contest:** Round #1 | **Difficulty:** EASY | **Platform Slug:** [`anagrams`](../platforms/csacademy/tasks/anagrams/statement.md)
- **Problem Statement:** Given $N$ words, find the maximum size of a group of mutually anagrammatic words.
- **Mathematical Invariant:**
  Two words are anagrams if and only if their sorted character signatures are identical.
- **Optimal Complexity:** $O(N \cdot L \log L)$ time, $O(N \cdot L)$ space.

---

## 5. Optimal Complexity Tips & Competitive Pitfalls

1. **Anti-Hash Tests & Random Bases:** Fixed bases like $B = 31$ or $B = 131$ with modulo $10^9+7$ can be systematically broken by Thue-Morse sequence collision generators. Always pick a random base $B \in [300, 10^6]$ via `std::mt19937_64`:
   ```cpp
   mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
   long long base = uniform_int_distribution<long long>(300, 1000000)(rng) | 1;
   ```
2. **KMP Backtracking Invariant:** During KMP prefix function construction, the while loop `j = pi[j - 1]` is amortized: $j$ increases by at most $1$ per character, hence total decrements are bounded by $N$.
3. **Manacher Delimiter Padding:** Always insert non-alphabetic dummy characters (e.g. `^` at start, `#` between characters, `$` at end) to unify odd-length and even-length palindrome processing into a single symmetric loop.

---

## 6. Comprehensive Archive Task Registry (55 Tasks)

| Slug | Title | Difficulty | Contest | Solved Ratio | Archive Link |
| :--- | :--- | :---: | :--- | :---: | :---: |
| `acronyms` | **Acronyms** | `EASY` | Round #54 | 88% | [`acronyms`](../platforms/csacademy/tasks/acronyms/statement.md) |
| `adjacent-vowels` | **Adjacent Vowels** | `EASY` | Round #47 | 98% | [`adjacent-vowels`](../platforms/csacademy/tasks/adjacent-vowels/statement.md) |
| `alphabet-rotation` | **Alphabet Rotation** | `EASY` | Beta Round #8 | 81% | [`alphabet-rotation`](../platforms/csacademy/tasks/alphabet-rotation/statement.md) |
| `anagrams` | **Anagrams** | `EASY` | Beta Round #4 | 80% | [`anagrams`](../platforms/csacademy/tasks/anagrams/statement.md) |
| `concatenated-array` | **Concatenated Array** | `EASY` | Round #57 (Div. 2 only) | 84% | [`concatenated-array`](../platforms/csacademy/tasks/concatenated-array/statement.md) |
| `double-replace` | **Double Replace** | `EASY` | Round #42 (Div. 2 only) | 95% | [`double-replace`](../platforms/csacademy/tasks/double-replace/statement.md) |
| `fast-typing` | **Fast Typing** | `EASY` | Round #57 (Div. 2 only) | 98% | [`fast-typing`](../platforms/csacademy/tasks/fast-typing/statement.md) |
| `k-consequal` | **K Consequal** | `EASY` | Round #15 | 81% | [`k-consequal`](../platforms/csacademy/tasks/k-consequal/statement.md) |
| `letters-deque` | **Letters Deque** | `EASY` | Round #46 (Div. 1.5) | 99% | [`letters-deque`](../platforms/csacademy/tasks/letters-deque/statement.md) |
| `long-pressed-name` | **Long Pressed Name** | `EASY` | Round #11 | 84% | [`long-pressed-name`](../platforms/csacademy/tasks/long-pressed-name/statement.md) |
| `one_letter` | **One Letter** | `EASY` | Beta Round #7 | 84% | [`one_letter`](../platforms/csacademy/tasks/one_letter/statement.md) |
| `palindromic-friendship` | **Palindromic Friendship** | `EASY` | Round #58 | 85% | [`palindromic-friendship`](../platforms/csacademy/tasks/palindromic-friendship/statement.md) |
| `recursive-string` | **Recursive String** | `EASY` | Round #31 | 77% | [`recursive-string`](../platforms/csacademy/tasks/recursive-string/statement.md) |
| `refrigerator-letters` | **Refrigerator Letters** | `EASY` | Round #35 | 97% | [`refrigerator-letters`](../platforms/csacademy/tasks/refrigerator-letters/statement.md) |
| `similar_words` | **Similar Words** | `EASY` | Beta Round #6 | 79% | [`similar_words`](../platforms/csacademy/tasks/similar_words/statement.md) |
| `word_ordering` | **Word Ordering** | `EASY` | Beta Round #1 | 71% | [`word_ordering`](../platforms/csacademy/tasks/word_ordering/statement.md) |
| `word_permutation` | **Word Permutation** | `EASY` | Beta Round #2 | 81% | [`word_permutation`](../platforms/csacademy/tasks/word_permutation/statement.md) |
| `101-palindromes` | **101 Palindromes** | `HARD` | (Out of Beta) Round #9 | 80% | [`101-palindromes`](../platforms/csacademy/tasks/101-palindromes/statement.md) |
| `balanced-string` | **Balanced String** | `HARD` | IOI 2016 Training Round #5 | 60% | [`balanced-string`](../platforms/csacademy/tasks/balanced-string/statement.md) |
| `strings` | **Strings** | `HARD` | Balkan OI 2017 Day 1 | 67% | [`strings`](../platforms/csacademy/tasks/strings/statement.md) |
| `subsequence-queries` | **Subsequence Queries** | `HARD` | Round #24 | 73% | [`subsequence-queries`](../platforms/csacademy/tasks/subsequence-queries/statement.md) |
| `substring-restrictions` | **Substring Restrictions** | `HARD` | Round #15 | 71% | [`substring-restrictions`](../platforms/csacademy/tasks/substring-restrictions/statement.md) |
| `balanced-strings` | **Balanced Strings** | `MEDIUM` | Round #31 | 81% | [`balanced-strings`](../platforms/csacademy/tasks/balanced-strings/statement.md) |
| `big-string` | **Big String** | `MEDIUM` | CS Academy Archive | 83% | [`big-string`](../platforms/csacademy/tasks/big-string/statement.md) |
| `concatenated-string` | **Concatenated String** | `MEDIUM` | Round #18 | 88% | [`concatenated-string`](../platforms/csacademy/tasks/concatenated-string/statement.md) |
| `confused-robot` | **Confused Robot** | `MEDIUM` | CS Academy Archive | 74% | [`confused-robot`](../platforms/csacademy/tasks/confused-robot/statement.md) |
| `distinct-palindromes` | **Distinct Palindromes** | `MEDIUM` | Round #57 (Div. 2 only) | 88% | [`distinct-palindromes`](../platforms/csacademy/tasks/distinct-palindromes/statement.md) |
| `double-palindromes` | **Double Palindromes** | `MEDIUM` | CS Academy Archive | 80% | [`double-palindromes`](../platforms/csacademy/tasks/double-palindromes/statement.md) |
| `elections` | **Elections** | `MEDIUM` | CS Academy Archive | 71% | [`elections`](../platforms/csacademy/tasks/elections/statement.md) |
| `encipherment` | **Encipherment** | `MEDIUM` | Round #65 (Div. 2 only) | 99% | [`encipherment`](../platforms/csacademy/tasks/encipherment/statement.md) |
| `escape-the-matrix` | **Escape the Matrix** | `MEDIUM` | Round #75 | 91% | [`escape-the-matrix`](../platforms/csacademy/tasks/escape-the-matrix/statement.md) |
| `expected-lcp` | **Expected Lcp** | `MEDIUM` | CS Academy Archive | 90% | [`expected-lcp`](../platforms/csacademy/tasks/expected-lcp/statement.md) |
| `free-palindromes` | **Free Palindromes** | `MEDIUM` | Round #33 (Div. 2 only) | 66% | [`free-palindromes`](../platforms/csacademy/tasks/free-palindromes/statement.md) |
| `license-plates` | **License Plates** | `MEDIUM` | CS Academy Archive | 94% | [`license-plates`](../platforms/csacademy/tasks/license-plates/statement.md) |
| `magic` | **Magic** | `MEDIUM` | EJOI 2017 Day 1 | 71% | [`magic`](../platforms/csacademy/tasks/magic/statement.md) |
| `matching-substrings` | **Matching Substrings** | `MEDIUM` | Round #48 (Div. 2 only) | 81% | [`matching-substrings`](../platforms/csacademy/tasks/matching-substrings/statement.md) |
| `matrix-palindromes` | **Matrix Palindromes** | `MEDIUM` | Round #55 (Div. 2 only) | 73% | [`matrix-palindromes`](../platforms/csacademy/tasks/matrix-palindromes/statement.md) |
| `max-substring` | **Max Substring** | `MEDIUM` | Round #49 | 78% | [`max-substring`](../platforms/csacademy/tasks/max-substring/statement.md) |
| `no-repeat` | **No Repeat** | `MEDIUM` | Round #59 (Div. 2 only) | 97% | [`no-repeat`](../platforms/csacademy/tasks/no-repeat/statement.md) |
| `odd-palindromes` | **Odd Palindromes** | `MEDIUM` | Round #29 (Div. 2 only) | 81% | [`odd-palindromes`](../platforms/csacademy/tasks/odd-palindromes/statement.md) |
| `palindrome-centers` | **Palindrome Centers** | `MEDIUM` | Round #27 | 86% | [`palindrome-centers`](../platforms/csacademy/tasks/palindrome-centers/statement.md) |
| `palindrome-free-strings` | **Palindrome Free Strings** | `MEDIUM` | CS Academy Archive | 86% | [`palindrome-free-strings`](../platforms/csacademy/tasks/palindrome-free-strings/statement.md) |
| `palindromic-concatenation` | **Palindromic Concatenation** | `MEDIUM` | Round #20 (Div. 2 only) | 74% | [`palindromic-concatenation`](../platforms/csacademy/tasks/palindromic-concatenation/statement.md) |
| `palindromic-partitions` | **Palindromic Partitions** | `MEDIUM` | CEOI 2017 Day 2 | 84% | [`palindromic-partitions`](../platforms/csacademy/tasks/palindromic-partitions/statement.md) |
| `palindromic-tree` | **Palindromic Tree** | `MEDIUM` | Junior Challenge 2017 Day 1 | 53% | [`palindromic-tree`](../platforms/csacademy/tasks/palindromic-tree/statement.md) |
| `parentrisis` | **Parentrisis** | `MEDIUM` | CS Academy Archive | 82% | [`parentrisis`](../platforms/csacademy/tasks/parentrisis/statement.md) |
| `prefix-free-subset` | **Prefix Free Subset** | `MEDIUM` | Round #30 (Div. 2 only) | 83% | [`prefix-free-subset`](../platforms/csacademy/tasks/prefix-free-subset/statement.md) |
| `replace-a` | **Replace A** | `MEDIUM` | Round #71 (Div. 2 only) | 97% | [`replace-a`](../platforms/csacademy/tasks/replace-a/statement.md) |
| `robots` | **Robots** | `MEDIUM` | IATI Shumen 2017 Day 1 | 40% | [`robots`](../platforms/csacademy/tasks/robots/statement.md) |
| `strange-substring` | **Strange Substring** | `MEDIUM` | Round #73 (Div. 2 only) | 89% | [`strange-substring`](../platforms/csacademy/tasks/strange-substring/statement.md) |
| `string-concat` | **String Concat** | `MEDIUM` | Round #68 (Div. 2 only) | 94% | [`string-concat`](../platforms/csacademy/tasks/string-concat/statement.md) |
| `strips` | **Strips** | `MEDIUM` | Romanian IOI Selection 2023 - Day 1 | 40% | [`strips`](../platforms/csacademy/tasks/strips/statement.md) |
| `sugarel-and-substrings` | **Sugarel and Substrings** | `MEDIUM` | CS Academy Archive | 93% | [`sugarel-and-substrings`](../platforms/csacademy/tasks/sugarel-and-substrings/statement.md) |
| `three-ones` | **Three Ones** | `MEDIUM` | CS Academy Archive | 88% | [`three-ones`](../platforms/csacademy/tasks/three-ones/statement.md) |
| `wrong-brackets` | **Wrong Brackets** | `MEDIUM` | Round #51 (Div. 2 only) | 90% | [`wrong-brackets`](../platforms/csacademy/tasks/wrong-brackets/statement.md) |
