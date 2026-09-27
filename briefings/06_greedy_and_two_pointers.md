# Archetype 06: Greedy Algorithms & Two Pointers

> **Grounding Metadata & NotebookLM Oracle**  
> - **Archetype ID:** `06_greedy_and_two_pointers`  
> - **Target Notebook ID:** `95a79d26-2f87-42cd-8cb9-8361a1e56059` (*Personal Notebook: ⚙️ Aaradhya — Engineer's Personal Notebook*)  
> - **Total Archived Tasks:** `205`  
> - **Sub-Archetypes:** Interval Scheduling, Sliding Window, Monotonic Deque, Two Pointers, Monotonic Binary Search on Answer, Prefix Sums & Kadane  
> - **Compiler Standards:** `g++ 15.2.0` (`-std=c++23 -O2 -pthread`) on Ubuntu 25.04 x64  

---

## 1. Executive Overview & Core Principles

A greedy algorithm makes the locally optimal choice at each stage with the intent of reaching a global optimum. Proving correctness requires establishing:
1. **Greedy Choice Property:** A global optimum can be arrived at by making a locally optimal choice.
2. **Optimal Substructure:** An optimal solution to the problem contains optimal solutions to subproblems.
3. **Exchange Argument:** Transforming any supposed optimal non-greedy solution into the greedy solution without worsening the objective function.

The **Two Pointers** paradigm exploits monotonicity across arrays: if an interval $[L, R]$ satisfies a condition, incrementing $L$ monotonic expands or restricts $R$, bounding total pointer traversals to $O(N)$.

---

## 2. Key Mathematical Patterns & Algorithms

### 2.1 Exchange Arguments & Custom Sorting
Given a sequence of items $i$ and $j$, consider their order in the optimal solution. If swapping $i$ and $j$ strictly improves the objective:
$$f(i, j) < f(j, i)$$
Sort elements by comparator `f(a, b)` to determine the globally optimal execution order.

### 2.2 Two Pointers & Sliding Window
Maintaining a validity condition $\mathcal{C}(L, R)$ over subarray $[L, R]$:
```cpp
int r = 0;
for (int l = 0; l < n; ++l) {
    while (r < n && can_extend(l, r)) {
        add(r);
        r++;
    }
    // [l, r) is the maximal valid window starting at l
    remove(l);
}
// Total operations: O(N) amortized
```

### 2.3 Binary Search on Answer (Predicate Monotonicity)
When the question asks to "maximize the minimum" or "minimize the maximum":
Define boolean predicate $P(X)$: "Is answer $X$ achievable?".
If $P(X)$ is monotonic ($P(X) = \text{true} \implies P(X-1) = \text{true}$), binary search over the answer domain $[\text{low}, \text{high}]$ reduces optimization to $O(\log(\text{range}) \cdot \text{Cost}(P))$.

### 2.4 Monotonic Deque (Sliding Window RMQ)
Maintains indices of useful elements in $O(N)$ overall time:
- Values in deque are strictly increasing/decreasing.
- Pop outdated indices from front when $q.\text{front}() < i - K + 1$.
- Pop smaller elements from back before inserting current element.

---

## 3. Sub-Archetypes Taxonomic Breakdown

```
Greedy Algorithms & Two Pointers
 ├── Sorting & Selection
 │    ├── Interval Scheduling (Sort by end time, Non-overlapping selection)
 │    ├── Custom Exchange Comparator (Swapping adjacent elements analysis)
 │    └── Huffman Coding & Priority Queues (Min-heap aggregation)
 ├── Two Pointers & Windows
 │    ├── Converging Pointers (Pair sum targets in sorted arrays)
 │    ├── Trailing Pointers (Sliding window size / condition tracking)
 │    └── Monotonic Deque (Sliding window maximum/minimum in O(1) amortized)
 ├── Binary Search Paradigms
 │    ├── Monotonic Predicate Inversion (Maximize min, Minimize max)
 │    └── Ternary Search (Unimodal / Convex function peak optimization)
 └── Cumulative Analysis
      ├── Prefix & Suffix Extrema (O(N) partition cuts)
      └── Kadane's Algorithm (Maximum subarray sum)
```

---

## 4. Canonical Problem Deep-Dives from Archive

### 4.1 MinMax Subarray (`minmax_subarray`)
- **Contest:** Round #2 | **Difficulty:** EASY | **Platform Slug:** [`minmax_subarray`](../platforms/csacademy/tasks/minmax_subarray/statement.md)
- **Problem Statement:** Given an array $A$ of $N$ integers, find the length of the shortest subarray containing both the minimum and maximum elements of the entire array.
- **Mathematical Invariant:**
  Compute global $\min(A)$ and $\max(A)$. Traverse the array maintaining the most recent indices of the minimum and maximum elements:
  $$\text{len} = |\text{last\_min} - \text{last\_max}| + 1$$
- **Optimal Complexity:** $O(N)$ time, $O(1)$ auxiliary space.
- **Production C++23 Implementation:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    int min_val = 2e9, max_val = -2e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        min_val = min(min_val, a[i]);
        max_val = max(max_val, a[i]);
    }

    if (min_val == max_val) {
        cout << 1 << "\n";
        return 0;
    }

    int last_min = -1, last_max = -1;
    int ans = n;

    for (int i = 0; i < n; ++i) {
        if (a[i] == min_val) last_min = i;
        if (a[i] == max_val) last_max = i;

        if (last_min != -1 && last_max != -1) {
            ans = min(ans, abs(last_min - last_max) + 1);
        }
    }

    cout << ans << "\n";
    return 0;
}
```

### 4.2 Sorting Partition (`sorting_partition`)
- **Contest:** Round #2 | **Difficulty:** EASY | **Platform Slug:** [`sorting_partition`](../platforms/csacademy/tasks/sorting_partition/statement.md)
- **Problem Statement:** Partition an array into the maximum number of chunks such that sorting each chunk individually sorts the entire array.
- **Mathematical Invariant:**
  A cut after index $i$ is valid if and only if:
  $$\max_{0 \le k \le i} A[k] \le \min_{i+1 \le k < N} A[k]$$
  Precomputing prefix maximums and suffix minimums allows determining all valid split positions in $O(N)$.
- **Optimal Complexity:** $O(N)$ time, $O(N)$ space.

---

## 5. Optimal Complexity Tips & Competitive Pitfalls

1. **Strict Weak Ordering Violation:** In C++ `std::sort`, the comparator MUST return `false` for equivalent elements (`a < b`, NOT `a <= b`). Returning `true` for equality triggers undefined behavior and heap corruption!
2. **Binary Search Lower/Upper Bound Off-by-One:**
   ```cpp
   long long low = 1, high = MAX_ANS, ans = -1;
   while (low <= high) {
       long long mid = low + (high - low) / 2;
       if (check(mid)) { ans = mid; low = mid + 1; }
       else { high = mid - 1; }
   }
   ```
3. **Floating Point Precision in Ternary Search:** When executing ternary search over continuous domains, iterate a fixed number of times (e.g. 100 iterations) rather than relying on `while (high - low > eps)` which can get stuck due to floating point rounding.

---

## 6. Comprehensive Archive Task Registry (205 Tasks)

| Slug | Title | Difficulty | Contest | Solved Ratio | Archive Link |
| :--- | :--- | :---: | :--- | :---: | :---: |
| `anomalies` | **Anomalies** | `EASY` | Round #58 | 96% | [`anomalies`](../platforms/csacademy/tasks/anomalies/statement.md) |
| `attack-and-speed` | **Attack and Speed** | `EASY` | Round #38 | 87% | [`attack-and-speed`](../platforms/csacademy/tasks/attack-and-speed/statement.md) |
| `fiicode-2022-a1` | **Awesome Atek** | `EASY` | FIICode 2022 Round #1 – Powered by Atek Software | 80% | [`fiicode-2022-a1`](../platforms/csacademy/tasks/fiicode-2022-a1/statement.md) |
| `backpack-packing` | **Backpack Packing** | `EASY` | Round #27 | 94% | [`backpack-packing`](../platforms/csacademy/tasks/backpack-packing/statement.md) |
| `balanced-min-pairing` | **Balanced Min Pairing** | `EASY` | Round #13 | 79% | [`balanced-min-pairing`](../platforms/csacademy/tasks/balanced-min-pairing/statement.md) |
| `best-array-cut` | **Best Array Cut** | `EASY` | Round #19 (Div. 2 only) | 93% | [`best-array-cut`](../platforms/csacademy/tasks/best-array-cut/statement.md) |
| `black-shapes` | **Black Shapes** | `EASY` | Round #22 (Div. 2 only) | 88% | [`black-shapes`](../platforms/csacademy/tasks/black-shapes/statement.md) |
| `black-white-necklace` | **Black White Necklace** | `EASY` | Round #24 | 81% | [`black-white-necklace`](../platforms/csacademy/tasks/black-white-necklace/statement.md) |
| `bottle-recycling` | **Bottle Recycling** | `EASY` | Round #18 | 94% | [`bottle-recycling`](../platforms/csacademy/tasks/bottle-recycling/statement.md) |
| `bounded-difference` | **Bounded Difference** | `EASY` | Round #38 | 82% | [`bounded-difference`](../platforms/csacademy/tasks/bounded-difference/statement.md) |
| `bounded-distinct` | **Bounded Distinct** | `EASY` | Round #26 (Div. 2 only) | 89% | [`bounded-distinct`](../platforms/csacademy/tasks/bounded-distinct/statement.md) |
| `build-the-fence` | **Build the Fence** | `EASY` | Round #55 (Div. 2 only) | 88% | [`build-the-fence`](../platforms/csacademy/tasks/build-the-fence/statement.md) |
| `card-shuffle` | **Card Shuffle** | `EASY` | Round #28 (Div. 2 only) | 87% | [`card-shuffle`](../platforms/csacademy/tasks/card-shuffle/statement.md) |
| `choose-the-price` | **Choose the Price** | `EASY` | Round #34 (Div. 2 only) | 98% | [`choose-the-price`](../platforms/csacademy/tasks/choose-the-price/statement.md) |
| `cinema-seats` | **Cinema Seats** | `EASY` | Round #41 | 87% | [`cinema-seats`](../platforms/csacademy/tasks/cinema-seats/statement.md) |
| `equality` | **Equality** | `EASY` | Round #29 (Div. 2 only) | 76% | [`equality`](../platforms/csacademy/tasks/equality/statement.md) |
| `erase-extremes` | **Erase Extremes** | `EASY` | Round #45 (Div. 1.5) | 98% | [`erase-extremes`](../platforms/csacademy/tasks/erase-extremes/statement.md) |
| `erase-value` | **Erase Value** | `EASY` | Round #40 (Div. 2 only) | 97% | [`erase-value`](../platforms/csacademy/tasks/erase-value/statement.md) |
| `fill-the-glasses` | **Fill the Glasses** | `EASY` | Round #54 | 95% | [`fill-the-glasses`](../platforms/csacademy/tasks/fill-the-glasses/statement.md) |
| `final-index` | **Final Index** | `EASY` | Round #28 (Div. 2 only) | 91% | [`final-index`](../platforms/csacademy/tasks/final-index/statement.md) |
| `flip-the-matrix` | **Flip the Matrix** | `EASY` | Round #46 (Div. 1.5) | 95% | [`flip-the-matrix`](../platforms/csacademy/tasks/flip-the-matrix/statement.md) |
| `food-pairing` | **Food Pairing** | `EASY` | Round #32 | 90% | [`food-pairing`](../platforms/csacademy/tasks/food-pairing/statement.md) |
| `football-tournament` | **Football Tournament** | `EASY` | Round #23 (Div. 2 only) | 95% | [`football-tournament`](../platforms/csacademy/tasks/football-tournament/statement.md) |
| `foxes-on-a-wheel` | **Foxes on a Wheel** | `EASY` | Round #57 (Div. 2 only) | 73% | [`foxes-on-a-wheel`](../platforms/csacademy/tasks/foxes-on-a-wheel/statement.md) |
| `frequency-exception` | **Frequency Exception** | `EASY` | Round #22 (Div. 2 only) | 90% | [`frequency-exception`](../platforms/csacademy/tasks/frequency-exception/statement.md) |
| `friday-13` | **Friday 13** | `EASY` | Round #50 (Div. 2 only) | 95% | [`friday-13`](../platforms/csacademy/tasks/friday-13/statement.md) |
| `increasing-pair` | **Increasing Pair** | `EASY` | Round #20 (Div. 2 only) | 80% | [`increasing-pair`](../platforms/csacademy/tasks/increasing-pair/statement.md) |
| `insert-in-sorted-array` | **Insert in Sorted Array** | `EASY` | Round #31 | 97% | [`insert-in-sorted-array`](../platforms/csacademy/tasks/insert-in-sorted-array/statement.md) |
| `jokers` | **Jokers** | `EASY` | Round #30 (Div. 2 only) | 91% | [`jokers`](../platforms/csacademy/tasks/jokers/statement.md) |
| `karaoke-group` | **Karaoke Group** | `EASY` | Round #31 | 95% | [`karaoke-group`](../platforms/csacademy/tasks/karaoke-group/statement.md) |
| `limited-vocabulary` | **Limited Vocabulary** | `EASY` | Round #26 (Div. 2 only) | 97% | [`limited-vocabulary`](../platforms/csacademy/tasks/limited-vocabulary/statement.md) |
| `lucky-days` | **Lucky Days** | `EASY` | Round #52 | 98% | [`lucky-days`](../platforms/csacademy/tasks/lucky-days/statement.md) |
| `min-pairing` | **Min Pairing** | `EASY` | Round #41 | 98% | [`min-pairing`](../platforms/csacademy/tasks/min-pairing/statement.md) |
| `min-swap-counting` | **Min Swap Counting** | `EASY` | Round #14 (Div. 2 only) | 92% | [`min-swap-counting`](../platforms/csacademy/tasks/min-swap-counting/statement.md) |
| `minmax_subarray` | **MinMax Subarray** | `EASY` | Beta Round #3 | 88% | [`minmax_subarray`](../platforms/csacademy/tasks/minmax_subarray/statement.md) |
| `move-the-bishop` | **Move the Bishop** | `EASY` | Round #40 (Div. 2 only) | 91% | [`move-the-bishop`](../platforms/csacademy/tasks/move-the-bishop/statement.md) |
| `next-dance-move` | **Next Dance Move** | `EASY` | Round #32 | 94% | [`next-dance-move`](../platforms/csacademy/tasks/next-dance-move/statement.md) |
| `open-the-bottles` | **Open the Bottles** | `EASY` | Round #53 (Div. 2 only) | 98% | [`open-the-bottles`](../platforms/csacademy/tasks/open-the-bottles/statement.md) |
| `pair-swap` | **Pair Swap** | `EASY` | Round #54 | 80% | [`pair-swap`](../platforms/csacademy/tasks/pair-swap/statement.md) |
| `permutation-matrix` | **Permutation Matrix** | `EASY` | Round #23 (Div. 2 only) | 76% | [`permutation-matrix`](../platforms/csacademy/tasks/permutation-matrix/statement.md) |
| `plants` | **Plants** | `EASY` | Round #55 (Div. 2 only) | 99% | [`plants`](../platforms/csacademy/tasks/plants/statement.md) |
| `pokemon-evolution` | **Pokémon Evolution** | `EASY` | Round #10 | 73% | [`pokemon-evolution`](../platforms/csacademy/tasks/pokemon-evolution/statement.md) |
| `postivie-xor` | **Positive Xor** | `EASY` | Round #29 (Div. 2 only) | 83% | [`postivie-xor`](../platforms/csacademy/tasks/postivie-xor/statement.md) |
| `race-qualifying` | **Race Qualifying** | `EASY` | Round #51 (Div. 2 only) | 85% | [`race-qualifying`](../platforms/csacademy/tasks/race-qualifying/statement.md) |
| `red-blue-teams` | **Red Blue Teams** | `EASY` | Round #55 (Div. 2 only) | 93% | [`red-blue-teams`](../platforms/csacademy/tasks/red-blue-teams/statement.md) |
| `removed-pages` | **Removed Pages** | `EASY` | Round #39 (Div. 2 only) | 97% | [`removed-pages`](../platforms/csacademy/tasks/removed-pages/statement.md) |
| `risk-rolls` | **Risk Rolls** | `EASY` | Round #66 (Div. 2 only) | 97% | [`risk-rolls`](../platforms/csacademy/tasks/risk-rolls/statement.md) |
| `safe-spots` | **Safe Spots** | `EASY` | Round #36 (Div. 2 only) | 88% | [`safe-spots`](../platforms/csacademy/tasks/safe-spots/statement.md) |
| `server-attack` | **Server Attack** | `EASY` | Round #34 (Div. 2 only) | 97% | [`server-attack`](../platforms/csacademy/tasks/server-attack/statement.md) |
| `shoe-pairs` | **Shoe Pairs** | `EASY` | Round #38 | 89% | [`shoe-pairs`](../platforms/csacademy/tasks/shoe-pairs/statement.md) |
| `soccer-field` | **Soccer Field** | `EASY` | CS Academy Archive | 86% | [`soccer-field`](../platforms/csacademy/tasks/soccer-field/statement.md) |
| `suspect-interval` | **Suspect Interval** | `EASY` | Round #25 (Div. 2 only) | 91% | [`suspect-interval`](../platforms/csacademy/tasks/suspect-interval/statement.md) |
| `switch-the-lights` | **Switch the Lights** | `EASY` | Round #40 (Div. 2 only) | 92% | [`switch-the-lights`](../platforms/csacademy/tasks/switch-the-lights/statement.md) |
| `to-front-to-back` | **To Front - To Back** | `EASY` | Round #17 (Div. 2 only) | 88% | [`to-front-to-back`](../platforms/csacademy/tasks/to-front-to-back/statement.md) |
| `two-guards` | **Two Guards** | `EASY` | Round #20 (Div. 2 only) | 90% | [`two-guards`](../platforms/csacademy/tasks/two-guards/statement.md) |
| `vector-size` | **Vector Size** | `EASY` | Round #24 | 97% | [`vector-size`](../platforms/csacademy/tasks/vector-size/statement.md) |
| `water-volume` | **Water Volume** | `EASY` | Round #48 (Div. 2 only) | 82% | [`water-volume`](../platforms/csacademy/tasks/water-volume/statement.md) |
| `array_coloring` | **Array Coloring** | `HARD` | Beta Round #7 | 85% | [`array_coloring`](../platforms/csacademy/tasks/array_coloring/statement.md) |
| `binary-swaps` | **Binary Swaps** | `HARD` | Round #58 | 43% | [`binary-swaps`](../platforms/csacademy/tasks/binary-swaps/statement.md) |
| `candles` | **Candles** | `HARD` | Round #41 | 69% | [`candles`](../platforms/csacademy/tasks/candles/statement.md) |
| `cats` | **Cats** | `HARD` | Balkan OI 2017 Day 2 | 62% | [`cats`](../platforms/csacademy/tasks/cats/statement.md) |
| `field-activation` | **Field Activation** | `HARD` | Round #13 | 79% | [`field-activation`](../platforms/csacademy/tasks/field-activation/statement.md) |
| `final-e` | **Final E** | `HARD` | FIICode 2021 Final Round | 83% | [`final-e`](../platforms/csacademy/tasks/final-e/statement.md) |
| `flareon` | **Flareon** | `HARD` | Romanian IOI 2017 Selection #6 | 75% | [`flareon`](../platforms/csacademy/tasks/flareon/statement.md) |
| `fold` | **Fold** | `HARD` | RMI 2017 Day 1 | 62% | [`fold`](../platforms/csacademy/tasks/fold/statement.md) |
| `hangman2` | **Hangman 2** | `HARD` | RMI 2017 Day 1 | 55% | [`hangman2`](../platforms/csacademy/tasks/hangman2/statement.md) |
| `jolteon` | **Jolteon** | `HARD` | Romanian IOI 2017 Selection #6 | 56% | [`jolteon`](../platforms/csacademy/tasks/jolteon/statement.md) |
| `k-swap` | **K Swap** | `HARD` | Round #39 (Div. 2 only) | 67% | [`k-swap`](../platforms/csacademy/tasks/k-swap/statement.md) |
| `library_book` | **Library Book** | `HARD` | Beta Round #4 | 71% | [`library_book`](../platforms/csacademy/tasks/library_book/statement.md) |
| `monsters` | **Monsters** | `HARD` | Balkan OI 2017 Day 2 | 71% | [`monsters`](../platforms/csacademy/tasks/monsters/statement.md) |
| `or-problem` | **Or Problem** | `HARD` | Round #56 | 72% | [`or-problem`](../platforms/csacademy/tasks/or-problem/statement.md) |
| `parallel-lines` | **Parallel Lines** | `HARD` | Round #38 | 53% | [`parallel-lines`](../platforms/csacademy/tasks/parallel-lines/statement.md) |
| `recursive-arrays` | **Recursive Arrays** | `HARD` | Round #37 (Div. 2 only) | 67% | [`recursive-arrays`](../platforms/csacademy/tasks/recursive-arrays/statement.md) |
| `server-hacking` | **Server Hacking** | `HARD` | Round #15 | 71% | [`server-hacking`](../platforms/csacademy/tasks/server-hacking/statement.md) |
| `unstable-merge-sort` | **Unstable Merge Sort** | `HARD` | Round #61 | 88% | [`unstable-merge-sort`](../platforms/csacademy/tasks/unstable-merge-sort/statement.md) |
| `voting` | **Voting** | `HARD` | Round #54 | 72% | [`voting`](../platforms/csacademy/tasks/voting/statement.md) |
| `a-single-one` | **A Single One** | `MEDIUM` | Round #11 | 62% | [`a-single-one`](../platforms/csacademy/tasks/a-single-one/statement.md) |
| `airport` | **Airport** | `MEDIUM` | Romanian IOI Selection 2023 - Day 2 | 71% | [`airport`](../platforms/csacademy/tasks/airport/statement.md) |
| `aisimok` | **Aisimok** | `MEDIUM` | FIICode 2021 Round #1 | 85% | [`aisimok`](../platforms/csacademy/tasks/aisimok/statement.md) |
| `alex-chills` | **Alex Chills** | `MEDIUM` | FIICode 2021 Round #3 | 87% | [`alex-chills`](../platforms/csacademy/tasks/alex-chills/statement.md) |
| `alex-climbs` | **Alex Climbs** | `MEDIUM` | FIICode 2021 Round #3 | 86% | [`alex-climbs`](../platforms/csacademy/tasks/alex-climbs/statement.md) |
| `alternant-array` | **Alternant Array** | `MEDIUM` | Round #61 | 93% | [`alternant-array`](../platforms/csacademy/tasks/alternant-array/statement.md) |
| `array-removal` | **Array Removal** | `MEDIUM` | (Out of Beta) Round #9 | 89% | [`array-removal`](../platforms/csacademy/tasks/array-removal/statement.md) |
| `as-easy-as-abc` | **As easy as ABC** | `MEDIUM` | CS Academy Archive | 83% | [`as-easy-as-abc`](../platforms/csacademy/tasks/as-easy-as-abc/statement.md) |
| `bst-fixed-height` | **BST Fixed Height** | `MEDIUM` | Round #24 | 83% | [`bst-fixed-height`](../platforms/csacademy/tasks/bst-fixed-height/statement.md) |
| `baby-seokhwan` | **Baby Seokhwan** | `MEDIUM` | CS Academy Archive | 81% | [`baby-seokhwan`](../platforms/csacademy/tasks/baby-seokhwan/statement.md) |
| `ball-sampling` | **Ball Sampling** | `MEDIUM` | Round #24 | 94% | [`ball-sampling`](../platforms/csacademy/tasks/ball-sampling/statement.md) |
| `base-k-xor` | **Base K Xor** | `MEDIUM` | Round #15 | 85% | [`base-k-xor`](../platforms/csacademy/tasks/base-k-xor/statement.md) |
| `beautiful-matrix` | **Beautiful Matrix** | `MEDIUM` | Round #72 | 87% | [`beautiful-matrix`](../platforms/csacademy/tasks/beautiful-matrix/statement.md) |
| `best-driver` | **Best Driver** | `MEDIUM` | CS Academy Archive | 96% | [`best-driver`](../platforms/csacademy/tasks/best-driver/statement.md) |
| `binary-differences` | **Binary Differences** | `MEDIUM` | Round #71 (Div. 2 only) | 82% | [`binary-differences`](../platforms/csacademy/tasks/binary-differences/statement.md) |
| `binary-isomorphism` | **Binary Isomorphism** | `MEDIUM` | Round #73 (Div. 2 only) | 84% | [`binary-isomorphism`](../platforms/csacademy/tasks/binary-isomorphism/statement.md) |
| `boaty-mcboatface` | **Boaty McBoatface** | `MEDIUM` | Round #75 | 92% | [`boaty-mcboatface`](../platforms/csacademy/tasks/boaty-mcboatface/statement.md) |
| `boring-operation` | **Boring Operation** | `MEDIUM` | CS Academy Archive | 96% | [`boring-operation`](../platforms/csacademy/tasks/boring-operation/statement.md) |
| `boss-fight` | **Boss Fight** | `MEDIUM` | CS Academy Archive | 85% | [`boss-fight`](../platforms/csacademy/tasks/boss-fight/statement.md) |
| `fiicode-2022-b1` | **Boundless Atek** | `MEDIUM` | FIICode 2022 Round #1 – Powered by Atek Software | 65% | [`fiicode-2022-b1`](../platforms/csacademy/tasks/fiicode-2022-b1/statement.md) |
| `build-binary-matrix` | **Build Binary Matrix** | `MEDIUM` | Round #35 | 74% | [`build-binary-matrix`](../platforms/csacademy/tasks/build-binary-matrix/statement.md) |
| `build-the-towers` | **Build the Towers** | `MEDIUM` | Round #26 (Div. 2 only) | 88% | [`build-the-towers`](../platforms/csacademy/tasks/build-the-towers/statement.md) |
| `candy-boxes` | **Candy Boxes** | `MEDIUM` | Round #76 (Div. 2 only) | 93% | [`candy-boxes`](../platforms/csacademy/tasks/candy-boxes/statement.md) |
| `card-groups` | **Card Groups** | `MEDIUM` | Round #60 (Div. 2 only) | 62% | [`card-groups`](../platforms/csacademy/tasks/card-groups/statement.md) |
| `cats-and-dogs` | **Cats and Dogs** | `MEDIUM` | CS Academy Archive | 95% | [`cats-and-dogs`](../platforms/csacademy/tasks/cats-and-dogs/statement.md) |
| `celsius-to-fahrenheit` | **Celsius to Fahrenheit** | `MEDIUM` | Round #61 | 97% | [`celsius-to-fahrenheit`](../platforms/csacademy/tasks/celsius-to-fahrenheit/statement.md) |
| `chase` | **Chase** | `MEDIUM` | CEOI 2017 Day 2 | 62% | [`chase`](../platforms/csacademy/tasks/chase/statement.md) |
| `circuits` | **Circuits** | `MEDIUM` | RMI 2017 Day 2 | 77% | [`circuits`](../platforms/csacademy/tasks/circuits/statement.md) |
| `clubs` | **Clubs** | `MEDIUM` | IATI Shumen 2017 Day 2 | 36% | [`clubs`](../platforms/csacademy/tasks/clubs/statement.md) |
| `colored_marbles` | **Colored Marbles** | `MEDIUM` | Beta Round #1 | 50% | [`colored_marbles`](../platforms/csacademy/tasks/colored_marbles/statement.md) |
| `cookie-clicker` | **Cookie Clicker** | `MEDIUM` | CS Academy Archive | 87% | [`cookie-clicker`](../platforms/csacademy/tasks/cookie-clicker/statement.md) |
| `fiicode-2022-c1` | **Crazy Atek** | `MEDIUM` | FIICode 2022 Round #1 – Powered by Atek Software | 65% | [`fiicode-2022-c1`](../platforms/csacademy/tasks/fiicode-2022-c1/statement.md) |
| `fiicode-2022-c2` | **Crazy Software** | `MEDIUM` | FIICode 2022 Round #2 – Powered by Atek Software | 80% | [`fiicode-2022-c2`](../platforms/csacademy/tasks/fiicode-2022-c2/statement.md) |
| `critical-cells` | **Critical Cells** | `MEDIUM` | Round #26 (Div. 2 only) | 87% | [`critical-cells`](../platforms/csacademy/tasks/critical-cells/statement.md) |
| `cuinelo` | **Cuinelo** | `MEDIUM` | FIICode 2021 Round #1 | 71% | [`cuinelo`](../platforms/csacademy/tasks/cuinelo/statement.md) |
| `dazzling-trams` | **Dazzling Trams** | `MEDIUM` | CS Academy Archive | 86% | [`dazzling-trams`](../platforms/csacademy/tasks/dazzling-trams/statement.md) |
| `dogs` | **Diamond Dogs** | `MEDIUM` | Round #72 | 83% | [`dogs`](../platforms/csacademy/tasks/dogs/statement.md) |
| `diesel-train` | **Diesel Train** | `MEDIUM` | Round #43 | 90% | [`diesel-train`](../platforms/csacademy/tasks/diesel-train/statement.md) |
| `douchebag-parking` | **Douchebag Parking** | `MEDIUM` | CS Academy Archive | 97% | [`douchebag-parking`](../platforms/csacademy/tasks/douchebag-parking/statement.md) |
| `driveaway` | **Driveaway** | `MEDIUM` | CS Academy Archive | 79% | [`driveaway`](../platforms/csacademy/tasks/driveaway/statement.md) |
| `fiicode-2022-d1` | **Dynamic Atek** | `MEDIUM` | FIICode 2022 Round #1 – Powered by Atek Software | 75% | [`fiicode-2022-d1`](../platforms/csacademy/tasks/fiicode-2022-d1/statement.md) |
| `editor` | **Editor** | `MEDIUM` | Round #59 (Div. 2 only) | 67% | [`editor`](../platforms/csacademy/tasks/editor/statement.md) |
| `electric-cars` | **Electric Cars** | `MEDIUM` | Round #75 | 86% | [`electric-cars`](../platforms/csacademy/tasks/electric-cars/statement.md) |
| `enchained` | **Enchained** | `MEDIUM` | CS Academy Archive | 77% | [`enchained`](../platforms/csacademy/tasks/enchained/statement.md) |
| `escaping-courses` | **Escaping Courses** | `MEDIUM` | CS Academy Archive | 57% | [`escaping-courses`](../platforms/csacademy/tasks/escaping-courses/statement.md) |
| `fantastic-4` | **Fantastic 4** | `MEDIUM` | Round #37 (Div. 2 only) | 22% | [`fantastic-4`](../platforms/csacademy/tasks/fantastic-4/statement.md) |
| `fibonacci-representations-big` | **Fibonacci Representations Big** | `MEDIUM` | CS Academy Archive | 27% | [`fibonacci-representations-big`](../platforms/csacademy/tasks/fibonacci-representations-big/statement.md) |
| `fibonacci-representations-small` | **Fibonacci Representations Small** | `MEDIUM` | CS Academy Archive | 42% | [`fibonacci-representations-small`](../platforms/csacademy/tasks/fibonacci-representations-small/statement.md) |
| `final-a` | **Final A** | `MEDIUM` | FIICode 2021 Final Round | 81% | [`final-a`](../platforms/csacademy/tasks/final-a/statement.md) |
| `final-b` | **Final B** | `MEDIUM` | FIICode 2021 Final Round | 85% | [`final-b`](../platforms/csacademy/tasks/final-b/statement.md) |
| `find-binary-array` | **Find Binary Array** | `MEDIUM` | Round #62 (Div. 2 only) | 94% | [`find-binary-array`](../platforms/csacademy/tasks/find-binary-array/statement.md) |
| `find-remainder` | **Find Remainder** | `MEDIUM` | Round #63 (Div. 2 only) | 61% | [`find-remainder`](../platforms/csacademy/tasks/find-remainder/statement.md) |
| `find-the-matrix` | **Find the Matrix** | `MEDIUM` | Round #61 | 78% | [`find-the-matrix`](../platforms/csacademy/tasks/find-the-matrix/statement.md) |
| `flawed-olympiad` | **Flawed Olympiad** | `MEDIUM` | CS Academy Archive | 88% | [`flawed-olympiad`](../platforms/csacademy/tasks/flawed-olympiad/statement.md) |
| `flipping-matrix` | **Flipping Matrix** | `MEDIUM` | Round #66 (Div. 2 only) | 73% | [`flipping-matrix`](../platforms/csacademy/tasks/flipping-matrix/statement.md) |
| `gerrymandering` | **Gerrymandering** | `MEDIUM` | CS Academy Archive | 81% | [`gerrymandering`](../platforms/csacademy/tasks/gerrymandering/statement.md) |
| `grade-system` | **Grade System** | `MEDIUM` | Round #60 (Div. 2 only) | 98% | [`grade-system`](../platforms/csacademy/tasks/grade-system/statement.md) |
| `groups` | **Groups** | `MEDIUM` | CS Academy Archive | 87% | [`groups`](../platforms/csacademy/tasks/groups/statement.md) |
| `hill-skateboarding` | **Hill Skateboarding** | `MEDIUM` | CS Academy Archive | 88% | [`hill-skateboarding`](../platforms/csacademy/tasks/hill-skateboarding/statement.md) |
| `ioi-selection` | **IOI Selection** | `MEDIUM` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | 98% | [`ioi-selection`](../platforms/csacademy/tasks/ioi-selection/statement.md) |
| `infinity-array` | **Infinity Array** | `MEDIUM` | Round #75 | 66% | [`infinity-array`](../platforms/csacademy/tasks/infinity-array/statement.md) |
| `k-inversions` | **K Inversions** | `MEDIUM` | CS Academy Archive | 72% | [`k-inversions`](../platforms/csacademy/tasks/k-inversions/statement.md) |
| `khans` | **Khans** | `MEDIUM` | IATI Shumen 2017 Day 1 | 56% | [`khans`](../platforms/csacademy/tasks/khans/statement.md) |
| `lightbulbs` | **Lightbulbs** | `MEDIUM` | Beta Round #2 | 79% | [`lightbulbs`](../platforms/csacademy/tasks/lightbulbs/statement.md) |
| `limited-swaps` | **Limited Swaps** | `MEDIUM` | Round #22 (Div. 2 only) | 79% | [`limited-swaps`](../platforms/csacademy/tasks/limited-swaps/statement.md) |
| `love-story` | **Love Story** | `MEDIUM` | CS Academy Archive | 97% | [`love-story`](../platforms/csacademy/tasks/love-story/statement.md) |
| `lynx` | **Lynx** | `MEDIUM` | FIICode 2021 Round #2 | 83% | [`lynx`](../platforms/csacademy/tasks/lynx/statement.md) |
| `many-zeros` | **Many Zeros** | `MEDIUM` | CS Academy Archive | 83% | [`many-zeros`](../platforms/csacademy/tasks/many-zeros/statement.md) |
| `matrix-balls` | **Matrix Balls** | `MEDIUM` | Round #71 (Div. 2 only) | 88% | [`matrix-balls`](../platforms/csacademy/tasks/matrix-balls/statement.md) |
| `milk-and-bread` | **Milk and Bread** | `MEDIUM` | CS Academy Archive | 95% | [`milk-and-bread`](../platforms/csacademy/tasks/milk-and-bread/statement.md) |
| `min-swaps` | **Min Swaps** | `MEDIUM` | Round #50 (Div. 2 only) | 68% | [`min-swaps`](../platforms/csacademy/tasks/min-swaps/statement.md) |
| `mountain-time` | **Mountain Time** | `MEDIUM` | CS Academy Archive | 83% | [`mountain-time`](../platforms/csacademy/tasks/mountain-time/statement.md) |
| `num-cube-sets` | **Num Cube Sets** | `MEDIUM` | Round #13 | 80% | [`num-cube-sets`](../platforms/csacademy/tasks/num-cube-sets/statement.md) |
| `overlapping-matrices` | **Overlapping Matrices** | `MEDIUM` | CS Academy Archive | 90% | [`overlapping-matrices`](../platforms/csacademy/tasks/overlapping-matrices/statement.md) |
| `paint-the-fence` | **Paint the Fence** | `MEDIUM` | Round #61 | 89% | [`paint-the-fence`](../platforms/csacademy/tasks/paint-the-fence/statement.md) |
| `particles` | **Particles** | `MEDIUM` | EJOI 2017 Day 1 | 70% | [`particles`](../platforms/csacademy/tasks/particles/statement.md) |
| `penguin-dance` | **Penguin Dance** | `MEDIUM` | CS Academy Archive | 94% | [`penguin-dance`](../platforms/csacademy/tasks/penguin-dance/statement.md) |
| `permutation-shift` | **Permutation Shift** | `MEDIUM` | Round #67 | 98% | [`permutation-shift`](../platforms/csacademy/tasks/permutation-shift/statement.md) |
| `pinball` | **Pinball** | `MEDIUM` | RMI 2023 - Day 1 Mirror | 30% | [`pinball`](../platforms/csacademy/tasks/pinball/statement.md) |
| `pokemon-fights` | **Pokemon Fights** | `MEDIUM` | Round #69 (Div. 2 only) | 98% | [`pokemon-fights`](../platforms/csacademy/tasks/pokemon-fights/statement.md) |
| `popcorn` | **Popcorn** | `MEDIUM` | Romanian IOI 2017 Selection #2 | 32% | [`popcorn`](../platforms/csacademy/tasks/popcorn/statement.md) |
| `printer` | **Printer** | `MEDIUM` | CS Academy Archive | 90% | [`printer`](../platforms/csacademy/tasks/printer/statement.md) |
| `pyramids` | **Pyramids** | `MEDIUM` | CS Academy Archive | 68% | [`pyramids`](../platforms/csacademy/tasks/pyramids/statement.md) |
| `quadrants` | **Quadrants** | `MEDIUM` | CS Academy Archive | 99% | [`quadrants`](../platforms/csacademy/tasks/quadrants/statement.md) |
| `rbubblesort` | **RBubbleSort** | `MEDIUM` | CS Academy Archive | 63% | [`rbubblesort`](../platforms/csacademy/tasks/rbubblesort/statement.md) |
| `race-cars` | **Race Cars** | `MEDIUM` | Round #75 | 92% | [`race-cars`](../platforms/csacademy/tasks/race-cars/statement.md) |
| `recursive_shuffle` | **Recursive Shuffle** | `MEDIUM` | Beta Round #5 | 76% | [`recursive_shuffle`](../platforms/csacademy/tasks/recursive_shuffle/statement.md) |
| `remove-update` | **Remove Update** | `MEDIUM` | Junior Challenge 2017 Day 1 | 81% | [`remove-update`](../platforms/csacademy/tasks/remove-update/statement.md) |
| `restricted-arrays` | **Restricted Arrays** | `MEDIUM` | CS Academy Archive | 76% | [`restricted-arrays`](../platforms/csacademy/tasks/restricted-arrays/statement.md) |
| `rhombus` | **Rhombus** | `MEDIUM` | CS Academy Archive | 93% | [`rhombus`](../platforms/csacademy/tasks/rhombus/statement.md) |
| `ricocheting-balls` | **Ricocheting Balls** | `MEDIUM` | Round #73 (Div. 2 only) | 90% | [`ricocheting-balls`](../platforms/csacademy/tasks/ricocheting-balls/statement.md) |
| `russian-dolls` | **Russian Dolls** | `MEDIUM` | Round #71 (Div. 2 only) | 71% | [`russian-dolls`](../platforms/csacademy/tasks/russian-dolls/statement.md) |
| `shampoo-exchange` | **Shampoo Exchange** | `MEDIUM` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | 73% | [`shampoo-exchange`](../platforms/csacademy/tasks/shampoo-exchange/statement.md) |
| `shopping-time` | **Shopping Time** | `MEDIUM` | CS Academy Archive | 80% | [`shopping-time`](../platforms/csacademy/tasks/shopping-time/statement.md) |
| `sliding-product-sum` | **Sliding Product Sum** | `MEDIUM` | Round #68 (Div. 2 only) | 77% | [`sliding-product-sum`](../platforms/csacademy/tasks/sliding-product-sum/statement.md) |
| `smallest-array-permutation` | **Smallest Array Permutation** | `MEDIUM` | Round #19 (Div. 2 only) | 80% | [`smallest-array-permutation`](../platforms/csacademy/tasks/smallest-array-permutation/statement.md) |
| `socks-pairs` | **Socks Pairs** | `MEDIUM` | Round #36 (Div. 2 only) | 66% | [`socks-pairs`](../platforms/csacademy/tasks/socks-pairs/statement.md) |
| `soldiers` | **Soldiers** | `MEDIUM` | Beta Round #4 | 51% | [`soldiers`](../platforms/csacademy/tasks/soldiers/statement.md) |
| `sortall` | **Sort All** | `MEDIUM` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | 69% | [`sortall`](../platforms/csacademy/tasks/sortall/statement.md) |
| `sorting-steps` | **Sorting Steps** | `MEDIUM` | Round #42 (Div. 2 only) | 73% | [`sorting-steps`](../platforms/csacademy/tasks/sorting-steps/statement.md) |
| `split-the-sticks` | **Split the Sticks** | `MEDIUM` | CS Academy Archive | 92% | [`split-the-sticks`](../platforms/csacademy/tasks/split-the-sticks/statement.md) |
| `sprint-cleaning` | **Spring Cleaning** | `MEDIUM` | Round #72 | 88% | [`sprint-cleaning`](../platforms/csacademy/tasks/sprint-cleaning/statement.md) |
| `spring-love` | **Spring Love** | `MEDIUM` | CS Academy Archive | 98% | [`spring-love`](../platforms/csacademy/tasks/spring-love/statement.md) |
| `sqrt-frac-easy` | **Square Root Frac (Easy)** | `MEDIUM` | Round #32 | 69% | [`sqrt-frac-easy`](../platforms/csacademy/tasks/sqrt-frac-easy/statement.md) |
| `sqrt-frac-hard` | **Square Root Frac (Hard)** | `MEDIUM` | Round #32 | 55% | [`sqrt-frac-hard`](../platforms/csacademy/tasks/sqrt-frac-hard/statement.md) |
| `stargazing` | **Stargazing** | `MEDIUM` | CS Academy Archive | 80% | [`stargazing`](../platforms/csacademy/tasks/stargazing/statement.md) |
| `strictly-increasing-array` | **Strictly Increasing Array** | `MEDIUM` | Round #61 | 75% | [`strictly-increasing-array`](../platforms/csacademy/tasks/strictly-increasing-array/statement.md) |
| `Sugarel-in-Love` | **Sugarel in Love** | `MEDIUM` | CS Academy Archive | 81% | [`Sugarel-in-Love`](../platforms/csacademy/tasks/Sugarel-in-Love/statement.md) |
| `sure-bet` | **Sure Bet** | `MEDIUM` | CEOI 2017 Day 1 | 87% | [`sure-bet`](../platforms/csacademy/tasks/sure-bet/statement.md) |
| `swap_pairing` | **Swap Pairing** | `MEDIUM` | Beta Round #4 | 78% | [`swap_pairing`](../platforms/csacademy/tasks/swap_pairing/statement.md) |
| `swap_permutation` | **Swap Permutation** | `MEDIUM` | Beta Round #1 | 62% | [`swap_permutation`](../platforms/csacademy/tasks/swap_permutation/statement.md) |
| `time-to-shine` | **Time to Shine** | `MEDIUM` | CS Academy Archive | 93% | [`time-to-shine`](../platforms/csacademy/tasks/time-to-shine/statement.md) |
| `tournament-swaps` | **Tournament Swaps** | `MEDIUM` | Round #58 | 83% | [`tournament-swaps`](../platforms/csacademy/tasks/tournament-swaps/statement.md) |
| `towns` | **Towns** | `MEDIUM` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | 42% | [`towns`](../platforms/csacademy/tasks/towns/statement.md) |
| `toys-big` | **Toys Big** | `MEDIUM` | CS Academy Archive | 85% | [`toys-big`](../platforms/csacademy/tasks/toys-big/statement.md) |
| `toys-small` | **Toys Small** | `MEDIUM` | CS Academy Archive | 83% | [`toys-small`](../platforms/csacademy/tasks/toys-small/statement.md) |
| `traveling-time` | **Traveling Time** | `MEDIUM` | CS Academy Archive | 86% | [`traveling-time`](../platforms/csacademy/tasks/traveling-time/statement.md) |
| `tree_swapping` | **Tree Swapping** | `MEDIUM` | Beta Round #3 | 76% | [`tree_swapping`](../platforms/csacademy/tasks/tree_swapping/statement.md) |
| `two-coins` | **Two Coins** | `MEDIUM` | Round #62 (Div. 2 only) | 96% | [`two-coins`](../platforms/csacademy/tasks/two-coins/statement.md) |
| `two-elevators` | **Two Elevators** | `MEDIUM` | Round #60 (Div. 2 only) | 96% | [`two-elevators`](../platforms/csacademy/tasks/two-elevators/statement.md) |
| `ultimateorbs` | **Ultimate Orbs** | `MEDIUM` | Round #46 (Div. 1.5) | 75% | [`ultimateorbs`](../platforms/csacademy/tasks/ultimateorbs/statement.md) |
| `unicorns` | **Unicorns** | `MEDIUM` | Round #74 (Div. 2 only) | 97% | [`unicorns`](../platforms/csacademy/tasks/unicorns/statement.md) |
| `vaporeon` | **Vaporeon** | `MEDIUM` | Romanian IOI 2017 Selection #6 | 72% | [`vaporeon`](../platforms/csacademy/tasks/vaporeon/statement.md) |
| `water-bottles` | **Water Bottles** | `MEDIUM` | Round #28 (Div. 2 only) | 67% | [`water-bottles`](../platforms/csacademy/tasks/water-bottles/statement.md) |
| `water-tower` | **Water Tower** | `MEDIUM` | CS Academy Archive | 77% | [`water-tower`](../platforms/csacademy/tasks/water-tower/statement.md) |
| `win-percentages` | **Win Percentages** | `MEDIUM` | Round #59 (Div. 2 only) | 67% | [`win-percentages`](../platforms/csacademy/tasks/win-percentages/statement.md) |
| `work-time` | **Work Time** | `MEDIUM` | CS Academy Archive | 89% | [`work-time`](../platforms/csacademy/tasks/work-time/statement.md) |
| `xor-transform` | **Xor Transform** | `MEDIUM` | Round #78 (based on Romanian Olympiad IOI selection camp) | 88% | [`xor-transform`](../platforms/csacademy/tasks/xor-transform/statement.md) |
| `zalmolxis` | **Zalmolxis** | `MEDIUM` | CS Academy Archive | 72% | [`zalmolxis`](../platforms/csacademy/tasks/zalmolxis/statement.md) |
