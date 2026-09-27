# Archetype 01: Dynamic Programming (DP)

> **Grounding Metadata & NotebookLM Oracle**  
> - **Archetype ID:** `01_dynamic_programming`  
> - **Target Notebook ID:** `95a79d26-2f87-42cd-8cb9-8361a1e56059` (*Personal Notebook: ⚙️ Aaradhya — Engineer's Personal Notebook*)  
> - **Total Archived Tasks:** `67`  
> - **Sub-Archetypes:** Tree DP, Bitmask DP, Digit DP, Divide & Conquer DP, Interval DP, Convex Hull Trick, Matrix Exponentiation  
> - **Compiler Standards:** `g++ 15.2.0` (`-std=c++23 -O2 -pthread`) on Ubuntu 25.04 x64  

---

## 1. Executive Overview & Core Principles

Dynamic Programming (DP) solves complex optimization and counting problems by decomposing them into overlapping subproblems governed by the **Principle of Optimality**: an optimal policy has the property that whatever the initial state and initial decision are, the remaining decisions must constitute an optimal policy with regard to the state resulting from the first decision.

In competitive programming, the transition graph of subproblems must form a **Directed Acyclic Graph (DAG)**. Identifying state compactification, transitional invariants, and monotonicity allows reducing polynomial complexities from $O(N^3)$ or $O(N^2)$ down to $O(N \log N)$ or $O(N)$.

---

## 2. Key Mathematical Patterns & Recurrence Formulations

### 2.1 State Compactification & Bitmasking
When $N \le 20$, subsets can be encoded as bit integers $S \in [0, 2^N - 1]$:
$$\text{dp}[S][u] = \min_{v \notin S} \left( \text{dp}[S \cup \{v\}][v] + \text{weight}(u, v) \right)$$
Iterating over all submasks of a mask $M$:
```cpp
for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
    // Submask iteration: Total complexity across all masks is O(3^N)
}
```

### 2.2 Digit DP
Counting integers $X \in [A, B]$ satisfying a given property $\mathcal{P}$:
$$\text{dp}(\text{idx}, \text{tight}, \text{leading\_zeros}, \text{state})$$
- `tight = 1`: current prefix matches the boundary number; valid digits $\le \text{digit}[\text{idx}]$.
- `tight = 0`: strictly smaller prefix; valid digits $\in [0, 9]$.
Transitions proceed sequentially from most significant digit to least significant digit in $O(10 \times \text{states} \times \log_{10} B)$.

### 2.3 Divide and Conquer Optimization
Applicable when transitions follow:
$$\text{dp}[i][j] = \min_{k < j} \left( \text{dp}[i-1][k] + C(k, j) \right)$$
and the optimal transition point $\text{opt}(i, j) = \arg\min_k (\dots)$ satisfies monotonicity:
$$\text{opt}(i, j) \le \text{opt}(i, j+1)$$
A sufficient condition is the **Quadrangle Inequality** (Monge Property) on cost function $C$:
$$C(a, c) + C(b, d) \le C(a, d) + C(b, c) \quad \forall a \le b \le c \le d$$
Reduces complexity from $O(K \cdot N^2)$ to $O(K \cdot N \log N)$.

### 2.4 Tree DP & Rerooting
For rooted tree at node $u$ with children $v \in \text{children}(u)$:
$$\text{dp}[u] = f\left( \{ \text{dp}[v] \mid v \in \text{children}(u) \} \right)$$
Rerooting (tree all-pairs) computes solutions for all roots in $O(N)$ by maintaining prefix and suffix aggregates of sibling transitions during a second DFS.

---

## 3. Sub-Archetypes Taxonomic Breakdown

```
Dynamic Programming
 ├── 1D / Linear DP (Prefix / Suffix state tracking, Kadane, LIS)
 ├── 2D / Grid DP (DAG paths, Obstacles, Bounded steps)
 ├── Bitmask DP (Hamiltonian paths, Assignment, Matching on small N <= 20)
 ├── Digit DP (Counting numerical invariants in range [L, R])
 ├── Interval DP (Matrix chain multiplication, Segment merging dp[i][j])
 ├── Tree DP (Independent set, Tree knapsack, Tree rerooting)
 └── DP Optimizations
      ├── Convex Hull Trick / Li Chao Tree (Linear cost functions y = mx + c)
      ├── Divide & Conquer Optimization (Monge cost functions)
      ├── Knuth-Yao Optimization (opt[i][j-1] <= opt[i][j] <= opt[i+1][j])
      └── Matrix Exponentiation (Linear recurrences for large N <= 10^18)
```

---

## 4. Canonical Problem Deep-Dives from Archive

### 4.1 Consecutive Subsequence (`consecutive-subsequence`)
- **Contest:** Round #35 | **Difficulty:** EASY / MEDIUM | **Platform Slug:** [`consecutive-subsequence`](../platforms/csacademy/tasks/consecutive-subsequence/statement.md)
- **Problem Statement:** Given an array $A$ of $N$ integers, find the length of the longest subsequence such that each element is strictly equal to the preceding element $+ 1$.
- **Mathematical Invariant:**
  $$\text{dp}[x] = \text{dp}[x - 1] + 1$$
  where $\text{dp}[x]$ represents the maximum length of a consecutive subsequence ending with value $x$.
- **Optimal Complexity:** $O(N)$ time with hash map or coordinate array; $O(N)$ space.
- **Production C++23 Implementation:**
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    unordered_map<int, int> dp;
    dp.reserve(n * 2);

    int max_len = 0;
    int best_end = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int val = a[i];
        dp[val] = dp[val - 1] + 1;
        if (dp[val] > max_len) {
            max_len = dp[val];
            best_end = val;
        }
    }

    cout << max_len << "\n";
    return 0;
}
```

### 4.2 Circular Subarrays (`circular_subarrays`)
- **Contest:** Round #16 | **Difficulty:** MEDIUM | **Platform Slug:** [`circular_subarrays`](../platforms/csacademy/tasks/circular_subarrays/statement.md)
- **Problem Statement:** Given a circular array $A$ of $N$ integers, compute the maximum sum of contiguous subarrays subject to constraints.
- **Mathematical Invariant:**
  A circular subarray either does not wrap around (standard Kadane: $\max \text{Subarray}(A)$) or wraps around, which is equivalent to:
  $$\text{TotalSum}(A) - \min \text{Subarray}(A)$$
  provided not all elements are negative.
- **Optimal Complexity:** $O(N)$ time, $O(1)$ auxiliary space.

---

## 5. Optimal Complexity Tips & Competitive Pitfalls

1. **64-bit Accumulator Safety:** Always use `long long` for cost and sum states; overflows in cost calculations produce negative values that corrupt `std::min` or `std::max`.
2. **Memory Layout & Cache Locality:** In 2D DP `dp[N][M]`, ensure the inner loop iterates across the second dimension (`dp[i][j]`) to exploit L1/L2 hardware cache lines. Avoid stride jumps.
3. **Array Re-use & Rolling Buffers:** When $\text{dp}[i][\dots]$ only depends on $\text{dp}[i-1][\dots]$, alternate between two rows:
   ```cpp
   vector<int> prev(M), curr(M);
   // swap(prev, curr) after each outer step
   ```
4. **Recursion Stack vs Iterative DP:** Deep tree DP on chains ($N = 10^5$) can exceed the default 8 MB stack limit on Linux judges. Prefer iterative topological DP or expand stack via `sys.setrecursionlimit` or custom stack runners.

---

## 6. Comprehensive Archive Task Registry (67 Tasks)

| Slug | Title | Difficulty | Contest | Solved Ratio | Archive Link |
| :--- | :--- | :---: | :--- | :---: | :---: |
| `alternating-subarray` | **Alternating Subarray** | `EASY` | Round #15 | 88% | [`alternating-subarray`](../platforms/csacademy/tasks/alternating-subarray/statement.md) |
| `fiicode-2022-b2` | **Boundless Software** | `EASY` | FIICode 2022 Round #2 – Powered by Atek Software | 85% | [`fiicode-2022-b2`](../platforms/csacademy/tasks/fiicode-2022-b2/statement.md) |
| `consecutive-subsequence` | **Consecutive Subsequence** | `EASY` | Beta Round #8 | 81% | [`consecutive-subsequence`](../platforms/csacademy/tasks/consecutive-subsequence/statement.md) |
| `decreasing-subarrays` | **Decreasing Subarrays** | `EASY` | Round #35 | 97% | [`decreasing-subarrays`](../platforms/csacademy/tasks/decreasing-subarrays/statement.md) |
| `dominoes` | **Dominoes** | `EASY` | Beta Round #6 | 80% | [`dominoes`](../platforms/csacademy/tasks/dominoes/statement.md) |
| `dominoes-rotations` | **Dominoes Rotations** | `EASY` | Round #19 (Div. 2 only) | 95% | [`dominoes-rotations`](../platforms/csacademy/tasks/dominoes-rotations/statement.md) |
| `histogram-partition` | **Histogram Partition** | `EASY` | Round #53 (Div. 2 only) | 82% | [`histogram-partition`](../platforms/csacademy/tasks/histogram-partition/statement.md) |
| `jeans-and-shirts` | **Jeans and Shirts** | `EASY` | Round #18 | 97% | [`jeans-and-shirts`](../platforms/csacademy/tasks/jeans-and-shirts/statement.md) |
| `k-subsets-removal` | **K-subsets Removal** | `EASY` | Round #14 (Div. 2 only) | 96% | [`k-subsets-removal`](../platforms/csacademy/tasks/k-subsets-removal/statement.md) |
| `largest-and-subset` | **Largest And Subset** | `EASY` | Round #17 (Div. 2 only) | 94% | [`largest-and-subset`](../platforms/csacademy/tasks/largest-and-subset/statement.md) |
| `max-even-subarray` | **Max Even Subarray** | `EASY` | Round #27 | 89% | [`max-even-subarray`](../platforms/csacademy/tasks/max-even-subarray/statement.md) |
| `max-or-subarray` | **Max Or Subarray** | `EASY` | Round #34 (Div. 2 only) | 81% | [`max-or-subarray`](../platforms/csacademy/tasks/max-or-subarray/statement.md) |
| `max-wave-array` | **Max Wave Array** | `EASY` | Round #21 | 84% | [`max-wave-array`](../platforms/csacademy/tasks/max-wave-array/statement.md) |
| `min-coin-payment` | **Min Coin Payment** | `EASY` | Round #21 | 98% | [`min-coin-payment`](../platforms/csacademy/tasks/min-coin-payment/statement.md) |
| `money-machine` | **Money Machine** | `EASY` | Round #49 | 92% | [`money-machine`](../platforms/csacademy/tasks/money-machine/statement.md) |
| `monotone-subarray` | **Monotone Subarray** | `EASY` | Round #53 (Div. 2 only) | 93% | [`monotone-subarray`](../platforms/csacademy/tasks/monotone-subarray/statement.md) |
| `odd-sum` | **Odd Sum** | `EASY` | Round #49 | 96% | [`odd-sum`](../platforms/csacademy/tasks/odd-sum/statement.md) |
| `positive-product-subarrays` | **Positive Product Subarrays** | `EASY` | Round #12 (Div. 2 only) | 92% | [`positive-product-subarrays`](../platforms/csacademy/tasks/positive-product-subarrays/statement.md) |
| `rectangle-partition` | **Rectangle Partition** | `EASY` | Round #43 | 92% | [`rectangle-partition`](../platforms/csacademy/tasks/rectangle-partition/statement.md) |
| `sorting_partition` | **Sorting Partition** | `EASY` | Beta Round #1 | 71% | [`sorting_partition`](../platforms/csacademy/tasks/sorting_partition/statement.md) |
| `subarray-partition` | **Subarray Partition** | `EASY` | Round #32 | 87% | [`subarray-partition`](../platforms/csacademy/tasks/subarray-partition/statement.md) |
| `subarray_removal` | **Subarray Removal** | `EASY` | Beta Round #7 | 66% | [`subarray_removal`](../platforms/csacademy/tasks/subarray_removal/statement.md) |
| `digital-lcs` | **Digital LCS** | `HARD` | Round #43 | 61% | [`digital-lcs`](../platforms/csacademy/tasks/digital-lcs/statement.md) |
| `domino-train` | **Domino Train** | `HARD` | Round #66 (Div. 2 only) | 75% | [`domino-train`](../platforms/csacademy/tasks/domino-train/statement.md) |
| `increasing_subarrays` | **Increasing Subarrays** | `HARD` | IOI 2016 Training Round #2 | 72% | [`increasing_subarrays`](../platforms/csacademy/tasks/increasing_subarrays/statement.md) |
| `lis_generator` | **LIS Generator** | `HARD` | Beta Round #6 | 75% | [`lis_generator`](../platforms/csacademy/tasks/lis_generator/statement.md) |
| `number_elimination` | **Number Elimination** | `HARD` | Beta Round #1 | 67% | [`number_elimination`](../platforms/csacademy/tasks/number_elimination/statement.md) |
| `robot-in-a-labyrinth` | **Robot in a Labyrinth** | `HARD` | Round #52 | 80% | [`robot-in-a-labyrinth`](../platforms/csacademy/tasks/robot-in-a-labyrinth/statement.md) |
| `token-grid` | **Tokens on a grid** | `HARD` | Round #31 | 78% | [`token-grid`](../platforms/csacademy/tasks/token-grid/statement.md) |
| `add-and-subtract` | **Add and Subtract** | `MEDIUM` | Round #41 | 70% | [`add-and-subtract`](../platforms/csacademy/tasks/add-and-subtract/statement.md) |
| `alex-concatenates` | **Alex Concatenates** | `MEDIUM` | FIICode 2021 Round #3 | 87% | [`alex-concatenates`](../platforms/csacademy/tasks/alex-concatenates/statement.md) |
| `alex-counts` | **Alex Counts** | `MEDIUM` | FIICode 2021 Round #3 | 89% | [`alex-counts`](../platforms/csacademy/tasks/alex-counts/statement.md) |
| `array-elimination` | **Array Elimination** | `MEDIUM` | Round #44 (Div. 2 only) | 74% | [`array-elimination`](../platforms/csacademy/tasks/array-elimination/statement.md) |
| `attending-events` | **Attending Events** | `MEDIUM` | CS Academy Archive | 95% | [`attending-events`](../platforms/csacademy/tasks/attending-events/statement.md) |
| `build-correct-brackets` | **Build Correct Brackets** | `MEDIUM` | Round #69 (Div. 2 only) | 86% | [`build-correct-brackets`](../platforms/csacademy/tasks/build-correct-brackets/statement.md) |
| `chromatic-number` | **Chromatic Number** | `MEDIUM` | Junior Challenge 2017 Day 1 | 72% | [`chromatic-number`](../platforms/csacademy/tasks/chromatic-number/statement.md) |
| `circular_subarrays` | **Circular Subarrays** | `MEDIUM` | Beta Round #2 | 78% | [`circular_subarrays`](../platforms/csacademy/tasks/circular_subarrays/statement.md) |
| `cloud-computing` | **Cloud Computing** | `MEDIUM` | CS Academy Archive | 50% | [`cloud-computing`](../platforms/csacademy/tasks/cloud-computing/statement.md) |
| `dakara` | **Dakara** | `MEDIUM` | Romanian IOI Selection 2023 - Day 2 | 53% | [`dakara`](../platforms/csacademy/tasks/dakara/statement.md) |
| `fiicode-2022-e2` | **Empowering Software** | `MEDIUM` | FIICode 2022 Round #2 – Powered by Atek Software | 83% | [`fiicode-2022-e2`](../platforms/csacademy/tasks/fiicode-2022-e2/statement.md) |
| `even-subset` | **Even Subset** | `MEDIUM` | Round #67 | 89% | [`even-subset`](../platforms/csacademy/tasks/even-subset/statement.md) |
| `global-warming` | **Global Warming** | `MEDIUM` | CS Academy Archive | 73% | [`global-warming`](../platforms/csacademy/tasks/global-warming/statement.md) |
| `hamming-distances` | **Hamming Distances** | `MEDIUM` | Round #67 | 80% | [`hamming-distances`](../platforms/csacademy/tasks/hamming-distances/statement.md) |
| `homecoming` | **Homecoming** | `MEDIUM` | CS Academy Archive | 66% | [`homecoming`](../platforms/csacademy/tasks/homecoming/statement.md) |
| `integer-coords` | **Integer Coords** | `MEDIUM` | Round #68 (Div. 2 only) | 81% | [`integer-coords`](../platforms/csacademy/tasks/integer-coords/statement.md) |
| `max-intersection-partition` | **Max Intersection Partition** | `MEDIUM` | Round #11 | 83% | [`max-intersection-partition`](../platforms/csacademy/tasks/max-intersection-partition/statement.md) |
| `maximize-profit` | **Maximize Profit** | `MEDIUM` | Round #63 (Div. 2 only) | 95% | [`maximize-profit`](../platforms/csacademy/tasks/maximize-profit/statement.md) |
| `maxor` | **Maxor** | `MEDIUM` | Round #53 (Div. 2 only) | 77% | [`maxor`](../platforms/csacademy/tasks/maxor/statement.md) |
| `min-distances` | **Min Distances** | `MEDIUM` | Round #70 | 90% | [`min-distances`](../platforms/csacademy/tasks/min-distances/statement.md) |
| `min-ends-subsequence` | **Min Ends Subsequence** | `MEDIUM` | Round #25 (Div. 2 only) | 88% | [`min-ends-subsequence`](../platforms/csacademy/tasks/min-ends-subsequence/statement.md) |
| `min-races` | **Min Races** | `MEDIUM` | Round #50 (Div. 2 only) | 85% | [`min-races`](../platforms/csacademy/tasks/min-races/statement.md) |
| `money-savings` | **Money Savings** | `MEDIUM` | CS Academy Archive | 96% | [`money-savings`](../platforms/csacademy/tasks/money-savings/statement.md) |
| `partial-maximums` | **Partial Maximums** | `MEDIUM` | Round #62 (Div. 2 only) | 84% | [`partial-maximums`](../platforms/csacademy/tasks/partial-maximums/statement.md) |
| `reverse-subarray` | **Reverse Subarray** | `MEDIUM` | Round #69 (Div. 2 only) | 78% | [`reverse-subarray`](../platforms/csacademy/tasks/reverse-subarray/statement.md) |
| `russian-dolls-ways` | **Russian Dolls Ways** | `MEDIUM` | Round #73 (Div. 2 only) | 76% | [`russian-dolls-ways`](../platforms/csacademy/tasks/russian-dolls-ways/statement.md) |
| `scrambled-eggs` | **Scrambled Eggs** | `MEDIUM` | FIICode 2021 Round #2 | 88% | [`scrambled-eggs`](../platforms/csacademy/tasks/scrambled-eggs/statement.md) |
| `set-subtraction` | **Set Subtraction** | `MEDIUM` | Round #46 (Div. 1.5) | 89% | [`set-subtraction`](../platforms/csacademy/tasks/set-subtraction/statement.md) |
| `smallest-subsets` | **Smallest Subsets** | `MEDIUM` | CS Academy Archive | 77% | [`smallest-subsets`](../platforms/csacademy/tasks/smallest-subsets/statement.md) |
| `subarray-medians` | **Subarray Medians** | `MEDIUM` | Round #10 | 64% | [`subarray-medians`](../platforms/csacademy/tasks/subarray-medians/statement.md) |
| `subarrays-xor-sum` | **Subarrays Xor Sum** | `MEDIUM` | Round #14 (Div. 2 only) | 83% | [`subarrays-xor-sum`](../platforms/csacademy/tasks/subarrays-xor-sum/statement.md) |
| `subway-ride` | **Subway Ride** | `MEDIUM` | Round #74 (Div. 2 only) | 88% | [`subway-ride`](../platforms/csacademy/tasks/subway-ride/statement.md) |
| `surround-the-enemy` | **Surround the Enemy** | `MEDIUM` | CS Academy Archive | 65% | [`surround-the-enemy`](../platforms/csacademy/tasks/surround-the-enemy/statement.md) |
| `the-wall` | **The Wall** | `MEDIUM` | Round #69 (Div. 2 only) | 85% | [`the-wall`](../platforms/csacademy/tasks/the-wall/statement.md) |
| `three-equal` | **Three Equal** | `MEDIUM` | Round #73 (Div. 2 only) | 93% | [`three-equal`](../platforms/csacademy/tasks/three-equal/statement.md) |
| `trees-partition` | **Trees Partition** | `MEDIUM` | Round #62 (Div. 2 only) | 85% | [`trees-partition`](../platforms/csacademy/tasks/trees-partition/statement.md) |
| `water-supply` | **Water Supply** | `MEDIUM` | CS Academy Archive | 65% | [`water-supply`](../platforms/csacademy/tasks/water-supply/statement.md) |
| `xor-submatrix` | **Xor Submatrix** | `MEDIUM` | Round #42 (Div. 2 only) | 81% | [`xor-submatrix`](../platforms/csacademy/tasks/xor-submatrix/statement.md) |
