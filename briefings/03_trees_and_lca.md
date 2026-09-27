# Archetype 03: Trees & Lowest Common Ancestor (LCA)

> **Grounding Metadata & NotebookLM Oracle**  
> - **Archetype ID:** `03_trees_and_lca`  
> - **Target Notebook ID:** `95a79d26-2f87-42cd-8cb9-8361a1e56059` (*Personal Notebook: ⚙️ Aaradhya — Engineer's Personal Notebook*)  
> - **Total Archived Tasks:** `29`  
> - **Sub-Archetypes:** Binary Lifting, Heavy-Light Decomposition (HLD), Centroid Decomposition, Tree Diameters & Centers, Subtree Queries (Euler Tour Technique), DSU on Tree (Sack)  
> - **Compiler Standards:** `g++ 15.2.0` (`-std=c++23 -O2 -pthread`) on Ubuntu 25.04 x64  

---

## 1. Executive Overview & Core Principles

A tree is an undirected connected acyclic graph with $N$ vertices and $N - 1$ edges. Any two nodes are connected by exactly one simple path. This structural uniqueness allows queries on paths and subtrees to be solved via recursive divide-and-conquer, ancestor doubling, or by linearizing the tree into a 1D array.

---

## 2. Key Mathematical Patterns & Algorithms

### 2.1 Lowest Common Ancestor (Binary Lifting)
Precomputing $2^k$-th ancestors allows $O(\log N)$ LCA queries after $O(N \log N)$ preprocessing:
$$\text{up}[u][k] = \text{up}[\text{up}[u][k-1]][k-1]$$
Distance between nodes $u$ and $v$ with depths $d(u), d(v)$:
$$\text{dist}(u, v) = d(u) + d(v) - 2 \cdot d(\text{LCA}(u, v))$$

### 2.2 Euler Tour Technique (Flattening Trees)
By recording entry time $\text{tin}[u]$ and exit time $\text{tout}[u]$ during DFS:
- Vertex $u$ is an ancestor of $v \iff \text{tin}[u] \le \text{tin}[v] \text{ and } \text{tout}[u] \ge \text{tout}[v]$.
- The subtree of $u$ maps to the contiguous 1D interval $[\text{tin}[u], \text{tout}[u]]$. Subtree updates/queries are converted to standard range operations on Segment Trees or Fenwick Trees!

### 2.3 Heavy-Light Decomposition (HLD)
Classifies edges into **Heavy** (leading to the child with maximum subtree size) and **Light**:
- Any path from node $u$ to root traverses at most $O(\log N)$ light edges.
- Consecutive heavy edges form heavy chains that receive contiguous indices in a flattened Segment Tree.
- Any path query $\text{path}(u, v)$ decomposes into $O(\log N)$ contiguous segment tree queries, achieving $O(\log^2 N)$ per path update/query.

### 2.4 Centroid Decomposition
A centroid of a tree with $N$ vertices is a node whose removal splits the tree into components each having size $\le N/2$.
- Centroid tree has height $O(\log N)$.
- Enables answering path queries of length $K$ or distance constraints in $O(N \log N)$ total time.

---

## 3. Sub-Archetypes Taxonomic Breakdown

```
Trees & Lowest Common Ancestor
 ├── Tree Fundamentals
 │    ├── Tree Diameters (Two BFS/DFS passes or Tree DP)
 │    ├── Tree Centers (Minimizing max distance to any node)
 │    └── Prufer Sequences (Cayley's theorem: N^(N-2) labeled trees)
 ├── Ancestor & Path Queries
 │    ├── Binary Lifting (LCA, Path maximum/minimum, Distance)
 │    ├── Tarjan's Offline LCA (O(N + Q) with Union-Find)
 │    └── Heavy-Light Decomposition (Path updates and path sums via Segment Tree)
 ├── Subtree & Range Queries
 │    ├── Euler Tour Flattening (Subtree queries -> 1D Range queries)
 │    └── DSU on Tree / Sack (Small-to-large child merging in O(N log N))
 └── Tree Decomposition
      └── Centroid Decomposition (Divide & conquer for all-pairs paths)
```

---

## 4. Canonical Problem Deep-Dives from Archive

### 4.1 Max Score Tree (`max-score-tree`)
- **Contest:** Round #42 | **Difficulty:** MEDIUM | **Platform Slug:** [`max-score-tree`](../platforms/csacademy/tasks/max-score-tree/statement.md)
- **Problem Statement:** Given a tree with weights on vertices, find an optimal orientation or selection maximizing connected subtree scores.
- **Mathematical Invariant:**
  Subtree DP maintains $\text{dp}[u][0]$ (node $u$ unselected) and $\text{dp}[u][1]$ (node $u$ selected). Transitions take the optimal branch from children $v$:
  $$\text{dp}[u][1] = W_u + \sum_{v \in \text{children}(u)} \max(0, \text{dp}[v][1])$$
- **Optimal Complexity:** $O(N)$ time, $O(N)$ space.

### 4.2 Tree Nodes Destruction (`tree-nodes-destruction`)
- **Contest:** Round #41 | **Difficulty:** HARD | **Platform Slug:** [`tree-nodes-destruction`](../platforms/csacademy/tasks/tree-nodes-destruction/statement.md)
- **Problem Statement:** Destroy nodes on a tree with minimum operations under reachability constraints.
- **Mathematical Invariant:**
  Binary lifting allows jumping up to the highest ancestor covering marked descendants. Greedy coverage from deepest leaf upward minimizes operations.
- **Optimal Complexity:** $O(N \log N)$ time, $O(N \log N)$ space.
- **Production C++23 Binary Lifting Template:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const int LOGN = 20;

vector<int> adj[MAXN];
int up[MAXN][LOGN];
int depth[MAXN];

void dfs(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p;
    for (int k = 1; k < LOGN; ++k) {
        up[u][k] = up[up[u][k - 1]][k - 1];
    }
    for (int v : adj[u]) {
        if (v != p) dfs(v, u, d + 1);
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = LOGN - 1; k >= 0; --k) {
        if (depth[u] - (1 << k) >= depth[v]) {
            u = up[u][k];
        }
    }
    if (u == v) return u;
    for (int k = LOGN - 1; k >= 0; --k) {
        if (up[u][k] != up[v][k]) {
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1, 0);

    // Ready for O(log N) LCA and distance queries
    return 0;
}
```

---

## 5. Optimal Complexity Tips & Competitive Pitfalls

1. **Rooting Conventions:** Always clarify whether the tree is 1-indexed or 0-indexed. Assign root parent `up[root][0] = root` to avoid infinite loops during binary lifting steps.
2. **Deep Tree Stack Overflow:** In unbalanced linear chain trees ($N = 2 \times 10^5$), default recursive DFS exhausts call stack space. Use manual stack DFS or iterative BFS to assign depths and parents.
3. **Small-to-Large Optimization (DSU on Tree):** When merging data structures from children (e.g. `std::set` or `std::map`), always swap the smaller container into the larger container:
   ```cpp
   if (map_u.size() < map_v.size()) swap(map_u, map_v);
   for (auto& elem : map_v) map_u.insert(elem);
   ```
   Ensures each element is moved at most $O(\log N)$ times, guaranteeing $O(N \log^2 N)$ overall complexity.

---

## 6. Comprehensive Archive Task Registry (29 Tasks)

| Slug | Title | Difficulty | Contest | Solved Ratio | Archive Link |
| :--- | :--- | :---: | :--- | :---: | :---: |
| `bounded-diameter-trees` | **Bounded Diameter Trees** | `HARD` | Round #14 (Div. 2 only) | 85% | [`bounded-diameter-trees`](../platforms/csacademy/tasks/bounded-diameter-trees/statement.md) |
| `expected-tree-degrees` | **Expected Tree Degrees** | `HARD` | Round #10 | 89% | [`expected-tree-degrees`](../platforms/csacademy/tasks/expected-tree-degrees/statement.md) |
| `meow` | **Meow** | `HARD` | Romanian IOI 2017 Selection #2 | 47% | [`meow`](../platforms/csacademy/tasks/meow/statement.md) |
| `minimize-ancestor-cost` | **Minimize Ancestor Cost** | `HARD` | Round #18 | 80% | [`minimize-ancestor-cost`](../platforms/csacademy/tasks/minimize-ancestor-cost/statement.md) |
| `one-way-streets` | **One Way Streets** | `HARD` | CEOI 2017 Day 1 | 79% | [`one-way-streets`](../platforms/csacademy/tasks/one-way-streets/statement.md) |
| `road-trips` | **Road Trips** | `HARD` | Round #19 (Div. 2 only) | 83% | [`road-trips`](../platforms/csacademy/tasks/road-trips/statement.md) |
| `subset-trees` | **Subset Trees** | `HARD` | Round #41 | 93% | [`subset-trees`](../platforms/csacademy/tasks/subset-trees/statement.md) |
| `tree-nodes-destruction` | **Tree Nodes Destruction** | `HARD` | IOI 2016 Training Round #3 | 83% | [`tree-nodes-destruction`](../platforms/csacademy/tasks/tree-nodes-destruction/statement.md) |
| `uniform-trees` | **Uniform Trees** | `HARD` | Round #31 | 72% | [`uniform-trees`](../platforms/csacademy/tasks/uniform-trees/statement.md) |
| `aa-tree` | **AA Tree** | `MEDIUM` | RMI 2023 - Day 1 Mirror | 41% | [`aa-tree`](../platforms/csacademy/tasks/aa-tree/statement.md) |
| `alice-tree` | **Alice's Tree** | `MEDIUM` | CS Academy Archive | 46% | [`alice-tree`](../platforms/csacademy/tasks/alice-tree/statement.md) |
| `bob-tree` | **Bob's Tree** | `MEDIUM` | CS Academy Archive | 79% | [`bob-tree`](../platforms/csacademy/tasks/bob-tree/statement.md) |
| `colored-forests` | **Colored Forests** | `MEDIUM` | Round #24 | 88% | [`colored-forests`](../platforms/csacademy/tasks/colored-forests/statement.md) |
| `count-bst` | **Count BST** | `MEDIUM` | CS Academy Archive | 88% | [`count-bst`](../platforms/csacademy/tasks/count-bst/statement.md) |
| `cover-the-tree` | **Cover the Tree** | `MEDIUM` | Round #69 (Div. 2 only) | 66% | [`cover-the-tree`](../platforms/csacademy/tasks/cover-the-tree/statement.md) |
| `crossing-tree` | **Crossing Tree** | `MEDIUM` | Round #65 (Div. 2 only) | 79% | [`crossing-tree`](../platforms/csacademy/tasks/crossing-tree/statement.md) |
| `cut-the-tree` | **Cut the Tree** | `MEDIUM` | Round #52 | 77% | [`cut-the-tree`](../platforms/csacademy/tasks/cut-the-tree/statement.md) |
| `cut-the-trees` | **Cut the Trees** | `MEDIUM` | Round #47 | 73% | [`cut-the-trees`](../platforms/csacademy/tasks/cut-the-trees/statement.md) |
| `dirijor` | **Dirijor** | `MEDIUM` | Romanian IOI Selection 2023 - Day 3 | 77% | [`dirijor`](../platforms/csacademy/tasks/dirijor/statement.md) |
| `everything-is-random` | **Everything is Random** | `MEDIUM` | CS Academy Archive | 86% | [`everything-is-random`](../platforms/csacademy/tasks/everything-is-random/statement.md) |
| `experience` | **Experience** | `MEDIUM` | EJOI 2017 Day 2 | 74% | [`experience`](../platforms/csacademy/tasks/experience/statement.md) |
| `growing-trees` | **Growing Trees** | `MEDIUM` | CS Academy Archive | 83% | [`growing-trees`](../platforms/csacademy/tasks/growing-trees/statement.md) |
| `meet` | **Meet** | `MEDIUM` | Romanian IOI Selection 2023 - Day 3 | 54% | [`meet`](../platforms/csacademy/tasks/meet/statement.md) |
| `root-change` | **Root Change** | `MEDIUM` | Round #29 (Div. 2 only) | 81% | [`root-change`](../platforms/csacademy/tasks/root-change/statement.md) |
| `root-lca-queries` | **Root LCA Queries** | `MEDIUM` | Round #63 (Div. 2 only) | 89% | [`root-lca-queries`](../platforms/csacademy/tasks/root-lca-queries/statement.md) |
| `tree-coloring` | **Tree Coloring** | `MEDIUM` | Round #51 (Div. 2 only) | 91% | [`tree-coloring`](../platforms/csacademy/tasks/tree-coloring/statement.md) |
| `tree-nodes-sets` | **Tree Nodes Sets** | `MEDIUM` | Round #36 (Div. 2 only) | 88% | [`tree-nodes-sets`](../platforms/csacademy/tasks/tree-nodes-sets/statement.md) |
| `virus-on-a-tree` | **Virus on a Tree** | `MEDIUM` | Round #52 | 87% | [`virus-on-a-tree`](../platforms/csacademy/tasks/virus-on-a-tree/statement.md) |
| `yurys-tree` | **Yury's Tree** | `MEDIUM` | Round #10 | 64% | [`yurys-tree`](../platforms/csacademy/tasks/yurys-tree/statement.md) |
