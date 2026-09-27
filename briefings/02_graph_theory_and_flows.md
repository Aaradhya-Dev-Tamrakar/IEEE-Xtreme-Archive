# Archetype 02: Graph Theory & Network Flows

> **Grounding Metadata & NotebookLM Oracle**  
> - **Archetype ID:** `02_graph_theory_and_flows`  
> - **Target Notebook ID:** `95a79d26-2f87-42cd-8cb9-8361a1e56059` (*Personal Notebook: ⚙️ Aaradhya — Engineer's Personal Notebook*)  
> - **Total Archived Tasks:** `69`  
> - **Sub-Archetypes:** Shortest Path (Dijkstra, 0-1 BFS), 2-SAT, Max Flow (Dinic), Min Cut, Bipartite Matching (Hopcroft-Karp), SCC (Tarjan, Kosaraju), Bridges & Articulation Points  
> - **Compiler Standards:** `g++ 15.2.0` (`-std=c++23 -O2 -pthread`) on Ubuntu 25.04 x64  

---

## 1. Executive Overview & Core Principles

Graph theory models pairwise relations between objects. Problems range from pathfinding and connectivity to capacity-constrained network flows. The core paradigm involves mapping real-world system states to vertices $V$ and valid transitions/constraints to edges $E$.

Network flows leverage the **Max-Flow Min-Cut Theorem**:
$$\max |f| = \min_{S, T} c(S, T)$$
enabling combinatorial cuts, maximum bipartite matchings (via König's theorem), and project selection optimization to be solved deterministically in polynomial time.

---

## 2. Key Mathematical Patterns & Algorithms

### 2.1 Shortest Path Metrics
- **Non-negative weights (Dijkstra):** $O((V + E) \log V)$ using `std::priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>`.
- **0-1 Weights (0-1 BFS):** $O(V + E)$ using `std::deque`: push weight-0 transitions to the front, weight-1 to the back.
- **Negative weights / Cycle detection (SPFA / Bellman-Ford):** $O(V \cdot E)$ with early exit.
- **All-pairs (Floyd-Warshall):** $O(V^3)$ state relaxation $\text{dist}[i][j] = \min(\text{dist}[i][j], \text{dist}[i][k] + \text{dist}[k][j])$.

### 2.2 Strongly Connected Components (SCC) & 2-SAT
A directed graph is decomposed into a DAG of components where each component is mutually reachable.
- **Tarjan / Kosaraju Algorithm:** $O(V + E)$ single/two-pass DFS.
- **2-SAT Satisfiability:** Clause $(u \lor v)$ is equivalent to directed implication edges $(\neg u \implies v)$ and $(\neg v \implies u)$.
  - **Satisfiable Condition:** No variable $x$ shares an SCC with $\neg x$:
    $$\text{scc}(x) \ne \text{scc}(\neg x) \quad \forall x$$
  - **Assignment:** If $\text{scc}(x) < \text{scc}(\neg x)$ in reverse topological order, assign $x = \text{true}$.

### 2.3 Maximum Flow & Minimum Cut (Dinic's Algorithm)
Constructs level graphs using BFS, then pushes blocking flows using DFS:
- General networks: $O(V^2 E)$
- Unit network / Bipartite matching: $O(E \sqrt{V})$
```cpp
struct Edge {
    int to;
    long long cap, flow;
    int rev;
};
```

---

## 3. Sub-Archetypes Taxonomic Breakdown

```
Graph Theory & Network Flows
 ├── Pathfinding & Traversal
 │    ├── BFS / DFS (Connected components, Bipartite coloring, Topological sort)
 │    ├── Shortest Paths (Dijkstra, 0-1 BFS, Bellman-Ford, Floyd-Warshall)
 │    └── Eulerian Path (Hierholzer's algorithm: in-degree == out-degree)
 ├── Connectivity & Decomposition
 │    ├── Strongly Connected Components (Tarjan / Kosaraju)
 │    ├── Bridges & Articulation Points (low[u] and tin[u] DFS discovery trees)
 │    └── Biconnected Components / Block-Cut Trees
 ├── Constraint Satisfaction
 │    └── 2-SAT (Implication DAG decomposition, Variable assignment)
 └── Network Flows & Cuts
      ├── Max Flow (Dinic's level graph and blocking flow)
      ├── Min Cut (S-T partition via reachable vertices in residual graph)
      ├── Bipartite Matching (Hopcroft-Karp / Dinic unit network)
      └── Min-Cost Max-Flow (Successive shortest path with SPFA / Johnson potentials)
```

---

## 4. Canonical Problem Deep-Dives from Archive

### 4.1 Long Journey (`long_journey`)
- **Contest:** Round #1 | **Difficulty:** EASY | **Platform Slug:** [`long_journey`](../platforms/csacademy/tasks/long_journey/statement.md)
- **Problem Statement:** Two travelers journey from start vertices $A$ and $B$ to a common destination $S$ along shortest paths. Maximize the length of their shared trailing path.
- **Mathematical Invariant:**
  Compute distance fields $D_A(u), D_B(u), D_S(u)$ using BFS. A node $u$ lies on a shortest path from $A$ to $S$ if and only if:
  $$D_A(u) + D_S(u) = D_A(S)$$
  The shared path is the node $u$ maximizing $D_S(u)$ satisfying both shortest path conditions.
- **Optimal Complexity:** $O(V + E)$ time, $O(V)$ space.

### 4.2 0-K Multiple (`0-k-multiple`)
- **Contest:** Round #21 | **Difficulty:** MEDIUM | **Platform Slug:** [`0-k-multiple`](../platforms/csacademy/tasks/0-k-multiple/statement.md)
- **Problem Statement:** Given an integer $N$ and digit $K$, find the smallest multiple of $N$ containing only digits $0$ and $K$.
- **Mathematical Invariant:**
  Formulate a state graph where vertices are remainders modulo $N$: $r \in [0, N-1]$.
  Transitions from remainder $r$ by appending digit $d \in \{0, K\}$:
  $$r' = (r \cdot 10 + d) \pmod N$$
  A BFS starting from $K \pmod N$ to $0 \pmod N$ guarantees the lexicographically smallest and shortest numerical multiple.
- **Optimal Complexity:** $O(N)$ time, $O(N)$ space.
- **Production C++23 Implementation:**
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    if (k % n == 0) {
        cout << k << "\n";
        return 0;
    }

    vector<int> parent(n, -1);
    vector<int> digit(n, -1);
    queue<int> q;

    int start_rem = k % n;
    parent[start_rem] = -2; // Marker for root
    digit[start_rem] = k;
    q.push(start_rem);

    while (!q.empty()) {
        int r = q.front();
        q.pop();

        if (r == 0) break;

        for (int d : {0, k}) {
            int nr = (r * 10 + d) % n;
            if (parent[nr] == -1) {
                parent[nr] = r;
                digit[nr] = d;
                q.push(nr);
            }
        }
    }

    string res = "";
    int curr = 0;
    while (curr != -2) {
        res.push_back('0' + digit[curr]);
        curr = parent[curr];
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";

    return 0;
}
```

---

## 5. Optimal Complexity Tips & Competitive Pitfalls

1. **Residual Capacity Direction:** When augmenting flow in Dinic/Edmonds-Karp, forward edge flow increments by $\Delta$, while reverse back-edge flow decrements by $\Delta$. Failing to maintain anti-parallel edges breaks max-flow correctness.
2. **0-1 BFS vs Dijkstra Overhead:** If all edge weights are $0$ or $1$, standard Dijkstra with `priority_queue` incurs an unnecessary $O(E \log V)$ penalty. `std::deque` achieves pure $O(V + E)$.
3. **Queue Re-entry in SPFA:** In graphs with negative edges, SPFA can blow up to $O(V \cdot E)$ on worst-case grids. If cycle detection is required, verify if a vertex enters the queue $\ge V$ times to immediately report a negative cycle.
4. **Bipartite Matching Edge Indexing:** Always reserve sufficient nodes ($2 \times 10^5$) when expanding bipartite sets $U$ and $V$ into a unified source-sink network.

---

## 6. Comprehensive Archive Task Registry (69 Tasks)

| Slug | Title | Difficulty | Contest | Solved Ratio | Archive Link |
| :--- | :--- | :---: | :--- | :---: | :---: |
| `bicycle-rental` | **Bicycle Rental** | `EASY` | Round #36 (Div. 2 only) | 97% | [`bicycle-rental`](../platforms/csacademy/tasks/bicycle-rental/statement.md) |
| `check-dfs` | **Check DFS** | `EASY` | Round #44 (Div. 2 only) | 76% | [`check-dfs`](../platforms/csacademy/tasks/check-dfs/statement.md) |
| `city-upgrades` | **City Upgrades** | `EASY` | Round #20 (Div. 2 only) | 79% | [`city-upgrades`](../platforms/csacademy/tasks/city-upgrades/statement.md) |
| `connect-the-graph` | **Connect the Graph** | `EASY` | Round #11 | 82% | [`connect-the-graph`](../platforms/csacademy/tasks/connect-the-graph/statement.md) |
| `donkey-paradox` | **Donkey Paradox** | `EASY` | Round #10 | 91% | [`donkey-paradox`](../platforms/csacademy/tasks/donkey-paradox/statement.md) |
| `dragons` | **Dragons** | `EASY` | Round #17 (Div. 2 only) | 92% | [`dragons`](../platforms/csacademy/tasks/dragons/statement.md) |
| `find-edge-list` | **Find Edge List** | `EASY` | Round #56 | 82% | [`find-edge-list`](../platforms/csacademy/tasks/find-edge-list/statement.md) |
| `huge-matrix` | **Huge Matrix** | `EASY` | Round #27 | 89% | [`huge-matrix`](../platforms/csacademy/tasks/huge-matrix/statement.md) |
| `long_journey` | **Long Journey** | `EASY` | Beta Round #5 | 83% | [`long_journey`](../platforms/csacademy/tasks/long_journey/statement.md) |
| `matrix_exploration` | **Matrix Exploration** | `EASY` | CS Academy Archive | 68% | [`matrix_exploration`](../platforms/csacademy/tasks/matrix_exploration/statement.md) |
| `path-travel` | **Path Travel** | `EASY` | Round #17 (Div. 2 only) | 90% | [`path-travel`](../platforms/csacademy/tasks/path-travel/statement.md) |
| `rectangle-path` | **Rectangle Path** | `EASY` | Round #25 (Div. 2 only) | 85% | [`rectangle-path`](../platforms/csacademy/tasks/rectangle-path/statement.md) |
| `square-cover` | **Square Cover** | `EASY` | Round #44 (Div. 2 only) | 91% | [`square-cover`](../platforms/csacademy/tasks/square-cover/statement.md) |
| `t-shapes` | **T-shapes** | `EASY` | Round #15 | 93% | [`t-shapes`](../platforms/csacademy/tasks/t-shapes/statement.md) |
| `an-unstable-graph` | **An Unstable Graph** | `HARD` | Round #52 | 83% | [`an-unstable-graph`](../platforms/csacademy/tasks/an-unstable-graph/statement.md) |
| `binary_matching` | **Binary Matching** | `HARD` | Beta Round #5 | 73% | [`binary_matching`](../platforms/csacademy/tasks/binary_matching/statement.md) |
| `catch-the-thief` | **Catch the Thief** | `HARD` | Round #21 | 66% | [`catch-the-thief`](../platforms/csacademy/tasks/catch-the-thief/statement.md) |
| `cograph_clique` | **Cograph Clique** | `HARD` | IOI 2016 Training Round #2 | 81% | [`cograph_clique`](../platforms/csacademy/tasks/cograph_clique/statement.md) |
| `cut-the-edges` | **Cut the Edges** | `HARD` | Round #58 | 87% | [`cut-the-edges`](../platforms/csacademy/tasks/cut-the-edges/statement.md) |
| `dependency-graph` | **Dependency Graph** | `HARD` | Beta Round #8 | 74% | [`dependency-graph`](../platforms/csacademy/tasks/dependency-graph/statement.md) |
| `divisible-matching` | **Divisible Matching** | `HARD` | Round #67 | 75% | [`divisible-matching`](../platforms/csacademy/tasks/divisible-matching/statement.md) |
| `matrix_coloring` | **Matrix Coloring** | `HARD` | Beta Round #2 | 57% | [`matrix_coloring`](../platforms/csacademy/tasks/matrix_coloring/statement.md) |
| `max-snake` | **Max Snake** | `HARD` | Round #47 | 81% | [`max-snake`](../platforms/csacademy/tasks/max-snake/statement.md) |
| `network-rumour` | **Network Rumour** | `HARD` | IOI 2016 Training Round #3 | 79% | [`network-rumour`](../platforms/csacademy/tasks/network-rumour/statement.md) |
| `perm_matrix` | **Perm Matrix** | `HARD` | Beta Round #6 | 59% | [`perm_matrix`](../platforms/csacademy/tasks/perm_matrix/statement.md) |
| `revenge` | **Revenge** | `HARD` | Romanian IOI 2017 Selection #3 | 62% | [`revenge`](../platforms/csacademy/tasks/revenge/statement.md) |
| `special-mvc` | **Special MVC** | `HARD` | Round #21 | 56% | [`special-mvc`](../platforms/csacademy/tasks/special-mvc/statement.md) |
| `telegraph` | **Telegraph** | `HARD` | IOI 2016 Training Round #3 | 61% | [`telegraph`](../platforms/csacademy/tasks/telegraph/statement.md) |
| `tournament-cycle` | **Tournament Cycle** | `HARD` | Round #21 | 95% | [`tournament-cycle`](../platforms/csacademy/tasks/tournament-cycle/statement.md) |
| `tree-square` | **Tree Square** | `HARD` | IOI 2016 Training Round #5 | 62% | [`tree-square`](../platforms/csacademy/tasks/tree-square/statement.md) |
| `xor_cycle` | **Xor Cycle** | `HARD` | Beta Round #6 | 89% | [`xor_cycle`](../platforms/csacademy/tasks/xor_cycle/statement.md) |
| `0-k-multiple` | **0-K Multiple** | `MEDIUM` | Round #21 | 63% | [`0-k-multiple`](../platforms/csacademy/tasks/0-k-multiple/statement.md) |
| `bfs-dfs` | **BFS-DFS** | `MEDIUM` | Round #41 | 88% | [`bfs-dfs`](../platforms/csacademy/tasks/bfs-dfs/statement.md) |
| `bad-triplet` | **Bad Triplet** | `MEDIUM` | Round #43 | 86% | [`bad-triplet`](../platforms/csacademy/tasks/bad-triplet/statement.md) |
| `binary-flips` | **Binary Flips** | `MEDIUM` | Round #57 (Div. 2 only) | 95% | [`binary-flips`](../platforms/csacademy/tasks/binary-flips/statement.md) |
| `building-bridges` | **Building Bridges** | `MEDIUM` | CEOI 2017 Day 2 | 71% | [`building-bridges`](../platforms/csacademy/tasks/building-bridges/statement.md) |
| `cities-robbery` | **Cities Robbery** | `MEDIUM` | Round #19 (Div. 2 only) | 82% | [`cities-robbery`](../platforms/csacademy/tasks/cities-robbery/statement.md) |
| `colorgraph` | **Colorgraph** | `MEDIUM` | IATI Shumen 2017 Day 2 | 47% | [`colorgraph`](../platforms/csacademy/tasks/colorgraph/statement.md) |
| `connecting-the-graph` | **Connecting the Graph** | `MEDIUM` | CS Academy Archive | 84% | [`connecting-the-graph`](../platforms/csacademy/tasks/connecting-the-graph/statement.md) |
| `count-4-cycles` | **Count 4-cycles** | `MEDIUM` | Round #65 (Div. 2 only) | 91% | [`count-4-cycles`](../platforms/csacademy/tasks/count-4-cycles/statement.md) |
| `cntgigelmat` | **Count Gigel Matrices** | `MEDIUM` | Round #46 (Div. 1.5) | 48% | [`cntgigelmat`](../platforms/csacademy/tasks/cntgigelmat/statement.md) |
| `cycle_tree` | **Cycle Tree** | `MEDIUM` | Beta Round #5 | 63% | [`cycle_tree`](../platforms/csacademy/tasks/cycle_tree/statement.md) |
| `direct-the-graph` | **Direct the Graph** | `MEDIUM` | Round #40 (Div. 2 only) | 91% | [`direct-the-graph`](../platforms/csacademy/tasks/direct-the-graph/statement.md) |
| `divided-kingdom` | **Divided Kingdom** | `MEDIUM` | CS Academy Archive | 76% | [`divided-kingdom`](../platforms/csacademy/tasks/divided-kingdom/statement.md) |
| `final-d` | **Final D** | `MEDIUM` | FIICode 2021 Final Round | 80% | [`final-d`](../platforms/csacademy/tasks/final-d/statement.md) |
| `find-path-union` | **Find Path Union** | `MEDIUM` | Round #56 | 47% | [`find-path-union`](../platforms/csacademy/tasks/find-path-union/statement.md) |
| `firestarter` | **Firestarter** | `MEDIUM` | CS Academy Archive | 74% | [`firestarter`](../platforms/csacademy/tasks/firestarter/statement.md) |
| `flip-the-edges` | **Flip the Edges** | `MEDIUM` | Round #60 (Div. 2 only) | 77% | [`flip-the-edges`](../platforms/csacademy/tasks/flip-the-edges/statement.md) |
| `late-edges` | **Late Edges** | `MEDIUM` | Round #54 | 74% | [`late-edges`](../platforms/csacademy/tasks/late-edges/statement.md) |
| `max-score-tree` | **Max Score Tree** | `MEDIUM` | Beta Round #8 | 87% | [`max-score-tree`](../platforms/csacademy/tasks/max-score-tree/statement.md) |
| `partial_ladder_graph` | **Partial Ladder Graph** | `MEDIUM` | Beta Round #7 | 88% | [`partial_ladder_graph`](../platforms/csacademy/tasks/partial_ladder_graph/statement.md) |
| `path-inversions` | **Path Inversions** | `MEDIUM` | Round #58 | 86% | [`path-inversions`](../platforms/csacademy/tasks/path-inversions/statement.md) |
| `path-union` | **Path Union** | `MEDIUM` | Round #38 | 88% | [`path-union`](../platforms/csacademy/tasks/path-union/statement.md) |
| `prefix-matches` | **Prefix Matches** | `MEDIUM` | Round #42 (Div. 2 only) | 92% | [`prefix-matches`](../platforms/csacademy/tasks/prefix-matches/statement.md) |
| `randomly-permuted-costs` | **Randomly Permuted Costs** | `MEDIUM` | Round #18 | 68% | [`randomly-permuted-costs`](../platforms/csacademy/tasks/randomly-permuted-costs/statement.md) |
| `right-down-path` | **Right Down Path** | `MEDIUM` | Round #70 | 93% | [`right-down-path`](../platforms/csacademy/tasks/right-down-path/statement.md) |
| `rooks` | **Rooks** | `MEDIUM` | CS Academy Archive | 72% | [`rooks`](../platforms/csacademy/tasks/rooks/statement.md) |
| `simple-paths` | **Simple Paths** | `MEDIUM` | Round #62 (Div. 2 only) | 70% | [`simple-paths`](../platforms/csacademy/tasks/simple-paths/statement.md) |
| `spanning-trees` | **Spanning Trees** | `MEDIUM` | Round #54 | 90% | [`spanning-trees`](../platforms/csacademy/tasks/spanning-trees/statement.md) |
| `strange-matrix` | **Strange Matrix** | `MEDIUM` | CS Academy Archive | 78% | [`strange-matrix`](../platforms/csacademy/tasks/strange-matrix/statement.md) |
| `sugarel-and-bars` | **Sugarel and Bars** | `MEDIUM` | CS Academy Archive | 79% | [`sugarel-and-bars`](../platforms/csacademy/tasks/sugarel-and-bars/statement.md) |
| `triangular-matrix` | **Triangular Matrix** | `MEDIUM` | Round #59 (Div. 2 only) | 69% | [`triangular-matrix`](../platforms/csacademy/tasks/triangular-matrix/statement.md) |
| `triangular-updates` | **Triangular Updates** | `MEDIUM` | Round #68 (Div. 2 only) | 80% | [`triangular-updates`](../platforms/csacademy/tasks/triangular-updates/statement.md) |
| `two-squares` | **Two Squares** | `MEDIUM` | Round #74 (Div. 2 only) | 50% | [`two-squares`](../platforms/csacademy/tasks/two-squares/statement.md) |
| `water` | **Water** | `MEDIUM` | Romanian IOI Selection 2023 - Day 1 | 70% | [`water`](../platforms/csacademy/tasks/water/statement.md) |
| `x-distance` | **X Distance** | `MEDIUM` | Round #27 | 92% | [`x-distance`](../platforms/csacademy/tasks/x-distance/statement.md) |
| `xor-match` | **Xor Match** | `MEDIUM` | Round #63 (Div. 2 only) | 96% | [`xor-match`](../platforms/csacademy/tasks/xor-match/statement.md) |
| `xor-the-graph` | **Xor the Graph** | `MEDIUM` | Round #61 | 79% | [`xor-the-graph`](../platforms/csacademy/tasks/xor-the-graph/statement.md) |
| `zone-capture` | **Zone Capture** | `MEDIUM` | Round #25 (Div. 2 only) | 79% | [`zone-capture`](../platforms/csacademy/tasks/zone-capture/statement.md) |
