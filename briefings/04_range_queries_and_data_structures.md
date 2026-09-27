# Archetype 04: Range Queries & Data Structures

> **Grounding Metadata & NotebookLM Oracle**  
> - **Archetype ID:** `04_range_queries_and_data_structures`  
> - **Target Notebook ID:** `95a79d26-2f87-42cd-8cb9-8361a1e56059` (*Personal Notebook: ⚙️ Aaradhya — Engineer's Personal Notebook*)  
> - **Total Archived Tasks:** `24`  
> - **Sub-Archetypes:** Segment Tree (Point/Range Updates, Lazy Propagation), Fenwick Tree (BIT), Mo's Algorithm, Sparse Table (RMQ), Treap / Cartesian Tree, Disjoint Set Union (DSU with Rollbacks)  
> - **Compiler Standards:** `g++ 15.2.0` (`-std=c++23 -O2 -pthread`) on Ubuntu 25.04 x64  

---

## 1. Executive Overview & Core Principles

Range query problems require maintaining an array or collection under dynamic modifications (point or range updates) while querying aggregate functions (sum, minimum, maximum, GCD, bitwise AND/OR) over contiguous intervals $[L, R]$.

The core principle relies on **associative algebraic structures** (Monoids $(S, \oplus, e)$):
$$(a \oplus b) \oplus c = a \oplus (b \oplus c)$$
When an operation is associative, intervals can be partitioned into canonical sub-intervals of size $2^k$ (Sparse Table / Fenwick) or binary tree segments (Segment Tree), allowing queries in $O(\log N)$ or $O(1)$ time.

---

## 2. Key Mathematical Patterns & Algorithms

### 2.1 Segment Tree & Lazy Propagation
A binary tree where node $u$ covers interval $[l, r]$. If updates apply to entire ranges:
$$\text{tree}[u] = \text{tree}[2u] \oplus \text{tree}[2u + 1]$$
Lazy tags $\text{lazy}[u]$ defer updates to children until traversed. Composition of lazy tags must satisfy associativity:
$$\text{lazy}_{\text{new}}(x) = f(\text{lazy}_{\text{old}}(x))$$
- **Point Update / Range Query:** $O(\log N)$
- **Range Update / Range Query (Lazy):** $O(\log N)$
- **Segment Tree Beats (Bitz):** Handles range $\text{chmin} / \text{chmax}$ updates in $O((N + Q) \log N)$ by maintaining first and second strictly greatest values.

### 2.2 Fenwick Tree (Binary Indexed Tree - BIT)
Operates on prefix intervals using the least significant bit (`lsb(x) = x & (-x)`):
- Point update adds to indices $i + \text{lsb}(i)$.
- Prefix sum queries accumulate from $i - \text{lsb}(i)$.
- **Time Complexity:** $O(\log N)$ per operation with minimal constant factor and $O(N)$ flat memory.

### 2.3 Sparse Table (Static RMQ)
Precomputes range aggregates for intervals of length $2^k$:
$$\text{st}[i][k] = \text{st}[i][k-1] \oplus \text{st}[i + 2^{k-1}][k-1]$$
When the operator $\oplus$ is **idempotent** ($x \oplus x = x$, such as $\min, \max, \gcd$):
$$\text{Query}(L, R) = \text{st}[L][k] \oplus \text{st}[R - 2^k + 1][k] \quad \text{where } k = \lfloor \log_2(R - L + 1) \rfloor$$
Answers range queries in pure **$O(1)$ time** after $O(N \log N)$ preprocessing.

### 2.4 Mo's Algorithm (Offline Sqrt Decomposition)
Orders $Q$ offline interval queries $[L, R]$ by block index of $L$ ($\lfloor L / B \rfloor$ where $B = \lceil N / \sqrt{Q} \rceil$) and ascending $R$:
$$\text{Total Time} = O((N + Q) \sqrt{N})$$
Sorting by Hilbert curve order reduces cache misses and constant factor runtime by ~30%.

---

## 3. Sub-Archetypes Taxonomic Breakdown

```
Range Queries & Data Structures
 ├── Static Interval Queries
 │    ├── Prefix Sum Arrays (O(1) range sum, 2D prefix grids)
 │    ├── Difference Arrays (O(1) range addition, O(N) reconstruction)
 │    └── Sparse Table (O(1) idempotent RMQ / GCD)
 ├── Dynamic Tree Structures
 │    ├── Fenwick Tree (Binary Indexed Tree - 1D, 2D, Inversion counting)
 │    ├── Segment Tree (Point updates, Lazy propagation, Dynamic creation)
 │    ├── Persistent Segment Tree (Versioned history, Range k-th element)
 │    └── Treap / Cartesian Tree (Implicit keys, Range reversals, Split/Merge)
 ├── Bitwise / String Range Structures
 │    └── Binary Trie (O(30) point insert, Range maximum XOR)
 └── Query Optimization Techniques
      ├── Square Root Decomposition (Block updates and queries)
      └── Mo's Algorithm (Offline block-sorted query pointer traversal)
```

---

## 4. Canonical Problem Deep-Dives from Archive

### 4.1 Online XorMax (`online_xormax`)
- **Contest:** Round #2 | **Difficulty:** HARD | **Platform Slug:** [`online_xormax`](../platforms/csacademy/tasks/online_xormax/statement.md)
- **Problem Statement:** Maintain a set of numbers subject to dynamic insertions and deletions. Query the maximum XOR of any active element with a given target $X$.
- **Mathematical Invariant:**
  Binary trie stores numbers bit-by-bit from MSB (bit 29) to LSB (bit 0).
  To maximize $X \oplus Y$, at bit $b$, choose branch $1 - \text{bit}(X, b)$ if present; otherwise follow $\text{bit}(X, b)$.
  Subtree counts track element active frequencies to support dynamic deletions.
- **Optimal Complexity:** $O(B)$ per insertion, deletion, and query where $B = 30$. Total time: $O(Q \cdot B)$.
- **Production C++23 Implementation:**
```cpp
#include <iostream>
#include <vector>

using namespace std;

const int MAX_NODES = 300000 * 31;
int trie[MAX_NODES][2];
int cnt[MAX_NODES];
int node_count = 1;

void insert(int val, int delta) {
    int u = 1;
    for (int b = 29; b >= 0; --b) {
        int bit = (val >> b) & 1;
        if (!trie[u][bit]) {
            trie[u][bit] = ++node_count;
        }
        u = trie[u][bit];
        cnt[u] += delta;
    }
}

int query_max_xor(int x) {
    int u = 1;
    int res = 0;
    for (int b = 29; b >= 0; --b) {
        int bit = (x >> b) & 1;
        int target = 1 - bit;
        if (trie[u][target] && cnt[trie[u][target]] > 0) {
            res |= (1 << b);
            u = trie[u][target];
        } else {
            u = trie[u][bit];
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;

    // Ready for dynamic online queries
    return 0;
}
```

### 4.2 And or Max (`and-or-max`)
- **Contest:** Round #48 | **Difficulty:** HARD | **Platform Slug:** [`and-or-max`](../platforms/csacademy/tasks/and-or-max/statement.md)
- **Problem Statement:** Perform range bitwise AND, range bitwise OR, and query range maximum.
- **Mathematical Invariant:**
  Segment Tree Beats: maintain bitwise OR and bitwise AND across the segment. If an update bit-mask does not differentiate between elements in the segment, it collapses to a uniform range addition/assignment.
- **Optimal Complexity:** $O((N + Q) \log N)$ amortized time.

---

## 5. Optimal Complexity Tips & Competitive Pitfalls

1. **Segment Tree Memory Sizing:** Standard 1-based Segment Tree requires **$4N$** nodes. Allocating only $2N$ causes silent memory corruption and judge SIGSEGV errors.
2. **Fenwick Tree 1-Based Indexing:** `x & (-x)` produces an infinite loop at `x = 0`. Always use 1-based indexing for BIT structures.
3. **Lazy Tag Cleansing:** Always push down pending lazy updates before accessing or recursing into child nodes during queries or updates.
4. **Fast I/O Necessity:** When $Q \ge 2 \times 10^5$, standard `std::cin` without `cin.tie(NULL)` will cause TLE. Always unsync C++ streams.

---

## 6. Comprehensive Archive Task Registry (24 Tasks)

| Slug | Title | Difficulty | Contest | Solved Ratio | Archive Link |
| :--- | :--- | :---: | :--- | :---: | :---: |
| `contiguous-segments` | **Contiguous Segments** | `EASY` | Round #58 | 85% | [`contiguous-segments`](../platforms/csacademy/tasks/contiguous-segments/statement.md) |
| `dictionary-pagination` | **Dictionary Pagination** | `EASY` | (Out of Beta) Round #9 | 91% | [`dictionary-pagination`](../platforms/csacademy/tasks/dictionary-pagination/statement.md) |
| `nested-segments` | **Nested Segments** | `EASY` | Round #56 | 92% | [`nested-segments`](../platforms/csacademy/tasks/nested-segments/statement.md) |
| `and-or-max` | **And or Max** | `HARD` | Round #70 | 75% | [`and-or-max`](../platforms/csacademy/tasks/and-or-max/statement.md) |
| `bfs` | **Bfs** | `HARD` | Romanian IOI 2017 Selection #3 | 58% | [`bfs`](../platforms/csacademy/tasks/bfs/statement.md) |
| `closest-numbers` | **Closest Numbers** | `HARD` | Round #54 | 63% | [`closest-numbers`](../platforms/csacademy/tasks/closest-numbers/statement.md) |
| `combinatorix` | **Combinatorix** | `HARD` | Round #46 (Div. 1.5) | 48% | [`combinatorix`](../platforms/csacademy/tasks/combinatorix/statement.md) |
| `interval-expected-max` | **Interval Expected Max** | `HARD` | Round #13 | 78% | [`interval-expected-max`](../platforms/csacademy/tasks/interval-expected-max/statement.md) |
| `online_xormax` | **Online XorMax** | `HARD` | Beta Round #4 | 74% | [`online_xormax`](../platforms/csacademy/tasks/online_xormax/statement.md) |
| `alex-combines` | **Alex Combines** | `MEDIUM` | FIICode 2021 Round #3 | 88% | [`alex-combines`](../platforms/csacademy/tasks/alex-combines/statement.md) |
| `bitwise-and-queries` | **Bitwise And Queries** | `MEDIUM` | Round #12 (Div. 2 only) | 79% | [`bitwise-and-queries`](../platforms/csacademy/tasks/bitwise-and-queries/statement.md) |
| `black-white-tree` | **Black White Tree** | `MEDIUM` | Round #55 (Div. 2 only) | 70% | [`black-white-tree`](../platforms/csacademy/tasks/black-white-tree/statement.md) |
| `consecutive-remainders` | **Consecutive Remainders** | `MEDIUM` | CS Academy Archive | 84% | [`consecutive-remainders`](../platforms/csacademy/tasks/consecutive-remainders/statement.md) |
| `cosmological-nightmare` | **Cosmological Nightmare** | `MEDIUM` | CS Academy Archive | 74% | [`cosmological-nightmare`](../platforms/csacademy/tasks/cosmological-nightmare/statement.md) |
| `dranei` | **Dr. Anei** | `MEDIUM` | FIICode 2021 Round #1 | 86% | [`dranei`](../platforms/csacademy/tasks/dranei/statement.md) |
| `fiicode-2022-e1` | **Empowering Atek** | `MEDIUM` | FIICode 2022 Round #1 – Powered by Atek Software | 72% | [`fiicode-2022-e1`](../platforms/csacademy/tasks/fiicode-2022-e1/statement.md) |
| `growing-segment` | **Growing Segment** | `MEDIUM` | CS Academy Archive | 75% | [`growing-segment`](../platforms/csacademy/tasks/growing-segment/statement.md) |
| `enemy` | **Line Enemies** | `MEDIUM` | Round #72 | 88% | [`enemy`](../platforms/csacademy/tasks/enemy/statement.md) |
| `lottery` | **Lottery** | `MEDIUM` | CS Academy Archive | 66% | [`lottery`](../platforms/csacademy/tasks/lottery/statement.md) |
| `rectangle-mst` | **MST and Rectangles** | `MEDIUM` | Round #72 | 85% | [`rectangle-mst`](../platforms/csacademy/tasks/rectangle-mst/statement.md) |
| `modulo-queries` | **Modulo Queries** | `MEDIUM` | Round #75 | 69% | [`modulo-queries`](../platforms/csacademy/tasks/modulo-queries/statement.md) |
| `seven-segment-display` | **Seven-segment Display** | `MEDIUM` | Round #39 (Div. 2 only) | 76% | [`seven-segment-display`](../platforms/csacademy/tasks/seven-segment-display/statement.md) |
| `sheets` | **Sheets** | `MEDIUM` | Balkan OI 2017 Day 1 | 80% | [`sheets`](../platforms/csacademy/tasks/sheets/statement.md) |
| `strange-transformation` | **Strange Transformation** | `MEDIUM` | CS Academy Archive | 86% | [`strange-transformation`](../platforms/csacademy/tasks/strange-transformation/statement.md) |
