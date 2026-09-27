# Archetype 10: Constructive & Interactive Algorithms

> **Grounding Metadata & NotebookLM Oracle**  
> - **Archetype ID:** `10_constructive_and_interactive`  
> - **Target Notebook ID:** `95a79d26-2f87-42cd-8cb9-8361a1e56059` (*Personal Notebook: ⚙️ Aaradhya — Engineer's Personal Notebook*)  
> - **Total Archived Tasks:** `38`  
> - **Sub-Archetypes:** Interactive Query Protocols, Information-Theoretic Query Bounds, Permutation Reconstruction, Invariant Preservation, Parity Arguments, Prefix Reversals  
> - **Compiler Standards:** `g++ 15.2.0` (`-std=c++23 -O2 -pthread`) on Ubuntu 25.04 x64  

---

## 1. Executive Overview & Core Principles

Constructive algorithms require synthesizing a valid configuration, permutation, graph, or operation sequence that satisfies a complex set of constraints, rather than simply computing an optimal scalar value.

Interactive problems represent a dialogue between the submission and an automated judge. The submission sends queries to standard output and receives responses from standard input, operating under a hard query budget bound $Q_{\max}$.

---

## 2. Key Mathematical Patterns & Algorithms

### 2.1 Information-Theoretic Lower Bounds
To uniquely identify a hidden configuration among $S$ possible configurations using $k$-ary query responses:
$$Q_{\max} \ge \lceil \log_k |S| \rceil$$
- **Binary queries (Yes/No, < / >):** $Q \ge \lceil \log_2 N \rceil$.
- **Ternary weighings (<, =, > on balance scale):** $Q \ge \lceil \log_3 N \rceil$.
Every query must be chosen to divide the remaining candidate set into $k$ subsets as equally sized as possible.

### 2.2 Standard Output Flushing Protocol
In interactive problems, standard I/O buffers must be flushed immediately after outputting each query to ensure the judge receives the message without stalling:
```cpp
// C++ Output Flush
cout << "? " << x << endl; // 'endl' automatically flushes the buffer

// Or explicit flush with fast newline:
cout << "? " << x << "\n" << flush;
```

### 2.3 Invariant Design & Extremal Principles
1. **Monotonic Invariant:** Every valid transformation strictly decreases a non-negative potential function $\Phi \ge 0$ (e.g. number of inversions in a permutation), guaranteeing finite termination.
2. **Parity Arguments:** If every operation changes the parity of an invariant, states with opposite parity are unreachable.
3. **Extremal Ordering:** Settle the boundary elements (the minimum element, the deepest leaf, or the outer boundary) first, reducing the problem to size $N - 1$.

---

## 3. Sub-Archetypes Taxonomic Breakdown

```
Constructive & Interactive Algorithms
 ├── Interactive Query Strategies
 │    ├── Binary Search Interaction (Guessing hidden values, Finding peaks)
 │    ├── Ternary Balance Scale (Fake coin identification in ceil(log_3 N))
 │    ├── Linear Query Systems (Reconstructing N values with N matrix weighings)
 │    └── Tree Reconstruction (Distance / LCA queries to reconstruct adjacency)
 └── Constructive Invariant Designs
      ├── Inversion Elimination (Sorting by prefix reversals, Swaps)
      ├── Grid Path Constructions (Eulerian tours, Hamiltonian cycles)
      ├── Parity Invariants (Coloring, Invariance under XOR / mod operations)
      └── Extremal Reductions (Placing min/max elements to decouple subproblems)
```

---

## 4. Canonical Problem Deep-Dives from Archive

### 4.1 Guess the Number (`guess-the-number`)
- **Contest:** Archive | **Difficulty:** EASY | **Platform Slug:** [`guess-the-number`](../platforms/csacademy/tasks/guess-the-number/statement.md)
- **Problem Statement:** Guess a hidden integer $X \in [1, 1000]$ by asking at most $10$ queries. Each query returns whether $X$ is smaller, larger, or equal.
- **Mathematical Invariant:**
  Binary search invariant: candidate interval $[L, R]$. At each step, test $M = \lfloor (L + R) / 2 \rfloor$.
  $$R' - L' + 1 \le \lceil (R - L + 1) / 2 \rceil$$
  Since $\lceil \log_2 1000 \rceil = 10$, termination is guaranteed within $10$ queries.
- **Optimal Complexity:** $O(\log N)$ queries, $O(1)$ memory.
- **Production C++23 Implementation:**
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int low = 1, high = 1000;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        cout << mid << endl; // Automatically flushes

        int response;
        if (!(cin >> response)) break;

        if (response == 0) {
            // Correct guess
            break;
        } else if (response == -1) {
            // Target is smaller
            high = mid - 1;
        } else {
            // Target is larger
            low = mid + 1;
        }
    }
    return 0;
}
```

### 4.2 Marble Weights (`marble-weights`)
- **Contest:** Archive | **Difficulty:** EASY / MEDIUM | **Platform Slug:** [`marble-weights`](../platforms/csacademy/tasks/marble-weights/statement.md)
- **Problem Statement:** $N$ marbles with integer weights. You can weigh at least $2$ marbles together. Find all weights using at most $N$ weighings.
- **Mathematical Invariant:**
  Weigh pairs $(1, 2), (1, 3), (2, 3)$ to find $W_1 + W_2 = S_{12}$, $W_1 + W_3 = S_{13}$, $W_2 + W_3 = S_{23}$.
  $$W_1 = \frac{S_{12} + S_{13} - S_{23}}{2}$$
  Once $W_1$ is known, each remaining marble $i \in [4, N]$ is determined with a single weighing $(1, i)$: $W_i = S_{1i} - W_1$.
  Total weighings: $3 + (N - 3) = N$.
- **Optimal Complexity:** $O(N)$ queries, $O(N)$ space.

---

## 5. Optimal Complexity Tips & Competitive Pitfalls

1. **Flushing Buffer Requirement:** Forgetting to flush (`cout << endl` or `fflush(stdout)`) causes the program to wait indefinitely for judge input while the judge waits for the query, leading to an immediate **Time Limit Exceeded (TLE)** or **Idleness Limit Exceeded**.
2. **Adaptive Judge Handling:** Some interactive judges do not fix the hidden state in advance; they adaptively choose answers to force your program into worst-case branches. Ensure your queries divide the worst-case search space symmetrically.
3. **Judge Response Parsing:** Always verify return codes from `std::cin`. If the judge outputs an error code (e.g. `-1` on query exhaustion or invalid query), terminate immediately (`return 0;`) to avoid getting a Wrong Answer on an infinite loop.

---

## 6. Comprehensive Archive Task Registry (38 Tasks)

| Slug | Title | Difficulty | Contest | Solved Ratio | Archive Link |
| :--- | :--- | :---: | :--- | :---: | :---: |
| `consecutive-sum` | **Consecutive Sum** | `EASY` | Round #47 | 90% | [`consecutive-sum`](../platforms/csacademy/tasks/consecutive-sum/statement.md) |
| `flip-the-prefix` | **Flip the Prefix** | `EASY` | Round #45 (Div. 1.5) | 92% | [`flip-the-prefix`](../platforms/csacademy/tasks/flip-the-prefix/statement.md) |
| `guess-the-number` | **Guess the Number** | `EASY` | Round #16 (Interactive only) | 85% | [`guess-the-number`](../platforms/csacademy/tasks/guess-the-number/statement.md) |
| `interactive-partial-sums` | **Interactive Partial Sums** | `EASY` | CS Academy Archive | 88% | [`interactive-partial-sums`](../platforms/csacademy/tasks/interactive-partial-sums/statement.md) |
| `marble-weights` | **Marble Weights** | `EASY` | Round #16 (Interactive only) | 92% | [`marble-weights`](../platforms/csacademy/tasks/marble-weights/statement.md) |
| `previous-divisors` | **Previous Divisors** | `EASY` | Round #16 (Interactive only) | 81% | [`previous-divisors`](../platforms/csacademy/tasks/previous-divisors/statement.md) |
| `bracket-grid` | **Bracket Grid** | `HARD` | Round #49 | 68% | [`bracket-grid`](../platforms/csacademy/tasks/bracket-grid/statement.md) |
| `fashion` | **Fashion** | `HARD` | RMI 2017 Day 1 | 73% | [`fashion`](../platforms/csacademy/tasks/fashion/statement.md) |
| `invsort` | **Invsort** | `HARD` | IOI 2016 Training Round #4 | 61% | [`invsort`](../platforms/csacademy/tasks/invsort/statement.md) |
| `tree-from-leaves` | **Tree From Leaves** | `HARD` | Round #16 (Interactive only) | 77% | [`tree-from-leaves`](../platforms/csacademy/tasks/tree-from-leaves/statement.md) |
| `tree-construct` | **Tree Reconstruction** | `HARD` | Round #43 | 63% | [`tree-construct`](../platforms/csacademy/tasks/tree-construct/statement.md) |
| `triplet-queries` | **Triplet Queries** | `HARD` | Round #27 | 83% | [`triplet-queries`](../platforms/csacademy/tasks/triplet-queries/statement.md) |
| `two_progressions` | **Two Progressions** | `HARD` | Beta Round #1 | 58% | [`two_progressions`](../platforms/csacademy/tasks/two_progressions/statement.md) |
| `anagram-sort` | **Anagram Sort** | `MEDIUM` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | 90% | [`anagram-sort`](../platforms/csacademy/tasks/anagram-sort/statement.md) |
| `circular_shift_sort` | **Circular Shift Sort** | `MEDIUM` | Beta Round #7 | 64% | [`circular_shift_sort`](../platforms/csacademy/tasks/circular_shift_sort/statement.md) |
| `classic-task` | **Classic Task** | `MEDIUM` | Round #65 (Div. 2 only) | 60% | [`classic-task`](../platforms/csacademy/tasks/classic-task/statement.md) |
| `create-tree` | **Create Tree** | `MEDIUM` | Round #64 (Interactive only) | 91% | [`create-tree`](../platforms/csacademy/tasks/create-tree/statement.md) |
| `digit-permutation` | **Digit Permutation** | `MEDIUM` | Round #60 (Div. 2 only) | 65% | [`digit-permutation`](../platforms/csacademy/tasks/digit-permutation/statement.md) |
| `disproportionate-tree` | **Disproportionate Tree** | `MEDIUM` | CS Academy Archive | 93% | [`disproportionate-tree`](../platforms/csacademy/tasks/disproportionate-tree/statement.md) |
| `distribute-candies` | **Distribute Candies** | `MEDIUM` | Round #70 | 72% | [`distribute-candies`](../platforms/csacademy/tasks/distribute-candies/statement.md) |
| `election-spies` | **Election Spies** | `MEDIUM` | Round #64 (Interactive only) | 86% | [`election-spies`](../platforms/csacademy/tasks/election-spies/statement.md) |
| `eliminate-edges` | **Eliminate Edges** | `MEDIUM` | Round #64 (Interactive only) | 71% | [`eliminate-edges`](../platforms/csacademy/tasks/eliminate-edges/statement.md) |
| `fake-coins` | **Fake Coins** | `MEDIUM` | Round #16 (Interactive only) | 77% | [`fake-coins`](../platforms/csacademy/tasks/fake-coins/statement.md) |
| `find-the-tree` | **Find the Tree** | `MEDIUM` | Round #64 (Interactive only) | 80% | [`find-the-tree`](../platforms/csacademy/tasks/find-the-tree/statement.md) |
| `game-on-a-circle` | **Game on a Circle** | `MEDIUM` | Round #52 | 75% | [`game-on-a-circle`](../platforms/csacademy/tasks/game-on-a-circle/statement.md) |
| `generating-set` | **Generating Set** | `MEDIUM` | CS Academy Archive | 74% | [`generating-set`](../platforms/csacademy/tasks/generating-set/statement.md) |
| `letter-by-letter` | **Letter by Letter** | `MEDIUM` | Round #16 (Interactive only) | 70% | [`letter-by-letter`](../platforms/csacademy/tasks/letter-by-letter/statement.md) |
| `lights-out` | **Lights Out** | `MEDIUM` | IOI 2016 Training Round #5 | 85% | [`lights-out`](../platforms/csacademy/tasks/lights-out/statement.md) |
| `minimum-by-xor` | **Minimum by Xor** | `MEDIUM` | Round #74 (Div. 2 only) | 92% | [`minimum-by-xor`](../platforms/csacademy/tasks/minimum-by-xor/statement.md) |
| `prime-factors` | **Prime Factors** | `MEDIUM` | Round #64 (Interactive only) | 98% | [`prime-factors`](../platforms/csacademy/tasks/prime-factors/statement.md) |
| `reconstruct-graph` | **Reconstruct Graph** | `MEDIUM` | Round #37 (Div. 2 only) | 90% | [`reconstruct-graph`](../platforms/csacademy/tasks/reconstruct-graph/statement.md) |
| `reconstruct-sum` | **Reconstruct Sum** | `MEDIUM` | Round #39 (Div. 2 only) | 96% | [`reconstruct-sum`](../platforms/csacademy/tasks/reconstruct-sum/statement.md) |
| `second-minimum` | **Second Minimum** | `MEDIUM` | Round #31 | 84% | [`second-minimum`](../platforms/csacademy/tasks/second-minimum/statement.md) |
| `trailing-zeros` | **Trailing Zeros** | `MEDIUM` | Round #64 (Interactive only) | 93% | [`trailing-zeros`](../platforms/csacademy/tasks/trailing-zeros/statement.md) |
| `transpermutation` | **Transpermutation** | `MEDIUM` | CS Academy Archive | 91% | [`transpermutation`](../platforms/csacademy/tasks/transpermutation/statement.md) |
| `tree-node-distances` | **Tree Node Distances** | `MEDIUM` | Round #16 (Interactive only) | 79% | [`tree-node-distances`](../platforms/csacademy/tasks/tree-node-distances/statement.md) |
| `adaptive-binary-search` | **Adaptive Binary Search** | `TUTORIAL` | CS Academy Archive | 87% | [`adaptive-binary-search`](../platforms/csacademy/tasks/adaptive-binary-search/statement.md) |
| `binary-search` | **Binary Search** | `TUTORIAL` | CS Academy Archive | 89% | [`binary-search`](../platforms/csacademy/tasks/binary-search/statement.md) |
