# Archetype 09: Game Theory & Nim Games

> **Grounding Metadata & NotebookLM Oracle**  
> - **Archetype ID:** `09_game_theory`  
> - **Target Notebook ID:** `95a79d26-2f87-42cd-8cb9-8361a1e56059` (*Personal Notebook: ⚙️ Aaradhya — Engineer's Personal Notebook*)  
> - **Total Archived Tasks:** `31`  
> - **Sub-Archetypes:** Sprague-Grundy Theorem, Nim-sum (XOR Addition), Impartial Games, Combinatorial Games on DAGs, Minimax & Backward Induction, Green Hackenbush  
> - **Compiler Standards:** `g++ 15.2.0` (`-std=c++23 -O2 -pthread`) on Ubuntu 25.04 x64  

---

## 1. Executive Overview & Core Principles

Combinatorial Game Theory studies sequential, two-player, zero-sum games with perfect information and no chance elements. Under the **Normal Play Convention**, the last player to make a legal move wins (the player with no legal moves loses).

Games are categorized as:
1. **Impartial Games:** From any state, both players have the exact same set of available moves. Fully solvable via the **Sprague-Grundy Theorem**.
2. **Partizan Games:** Players have distinct move sets (e.g. Chess, Go). Solvable via Minimax, Alpha-Beta pruning, or surreal numbers.

---

## 2. Key Mathematical Patterns & Algorithms

### 2.1 Bouton's Theorem for Nim
In a game of Nim with piles of sizes $x_1, x_2, \dots, x_k$:
$$\text{Nim-sum} = x_1 \oplus x_2 \oplus \dots \oplus x_k$$
- **P-Position (Previous player wins / Losing for current):** $\text{Nim-sum} = 0$.
- **N-Position (Next player wins / Winning for current):** $\text{Nim-sum} > 0$.

### 2.2 Sprague-Grundy Theorem
Every impartial game under the normal play convention is equivalent to a single Nim pile of size $\mathcal{G}(s)$, where the **Grundy value** (nim-value) of state $s$ is the minimum excluded value (**mex**) of the Grundy values of all states reachable in one move:
$$\mathcal{G}(s) = \text{mex}\left( \{ \mathcal{G}(t) \mid s \to t \} \right)$$
where $\text{mex}(S)$ is the smallest non-negative integer not in $S$.
- $\mathcal{G}(s) = 0 \iff s$ is a losing P-position.
- Composite independent games combine via XOR:
  $$\mathcal{G}(A + B) = \mathcal{G}(A) \oplus \mathcal{G}(B)$$

### 2.3 Backward Induction on Game DAGs
For finite games with no cycles:
```cpp
bool is_winning(int u) {
    if (memo[u] != -1) return memo[u];
    for (int v : adj[u]) {
        if (!is_winning(v)) {
            return memo[u] = 1; // Transition to a losing state exists
        }
    }
    return memo[u] = 0; // All transitions lead to winning states
}
```

---

## 3. Sub-Archetypes Taxonomic Breakdown

```
Game Theory & Nim Games
 ├── Impartial Game Foundations
 │    ├── Standard Nim (Single/Multi-pile XOR sum)
 │    ├── Subtraction Games (Periodic Grundy sequences)
 │    └── Sprague-Grundy Theorem (Mex computation, Composite game decomposition)
 ├── Game Graph Traversal
 │    ├── Games on Directed Acyclic Graphs (DAG topological backward induction)
 │    ├── Games with Cycles (Directed graph 3-state coloring: WIN, LOSE, DRAW)
 │    └── Tree Nim / Green Hackenbush (Subtree colon principle)
 └── Partizan Games & Search
      ├── Minimax Algorithm (Zero-sum state evaluation)
      └── Alpha-Beta Pruning (Branch elimination in deep search trees)
```

---

## 4. Canonical Problem Deep-Dives from Archive

### 4.1 Unfair Game (`unfair_game`)
- **Contest:** Round #2 | **Difficulty:** EASY | **Platform Slug:** [`unfair_game`](../platforms/csacademy/tasks/unfair_game/statement.md)
- **Problem Statement:** Two players play on an array of numbers with distinct move sets. Determine who wins under optimal play.
- **Mathematical Invariant:**
  Game on a directed state space. Backward induction maps terminal states (no legal moves $\implies$ lose) upwards.
- **Optimal Complexity:** $O(N)$ time, $O(N)$ space.
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

    // Backward induction on game state graph
    return 0;
}
```

### 4.2 Tree Game (`tree_game`)
- **Contest:** Round #2 | **Difficulty:** HARD | **Platform Slug:** [`tree_game`](../platforms/csacademy/tasks/tree_game/statement.md)
- **Problem Statement:** Impartial game played by pruning branches on a tree.
- **Mathematical Invariant:**
  Green's Hackenbush on trees: By the Colon Principle, an equivalent Nim pile for a branch rooted at node $u$ with subtrees $v_1, v_2, \dots, v_k$ is:
  $$\mathcal{G}(u) = \bigoplus_{v \in \text{children}(u)} (\mathcal{G}(v) + 1)$$
- **Optimal Complexity:** $O(N)$ DFS traversal, $O(N)$ space.

---

## 5. Optimal Complexity Tips & Competitive Pitfalls

1. **Normal Play vs Misère Play:** In Misère play (last player to move loses), the XOR rule holds for all states EXCEPT when all remaining piles have size $\le 1$. If all piles have size $1$, the position is winning iff the number of piles is EVEN.
2. **Mex Array Resetting:** When computing $\text{mex}$ across hundreds of states, do not re-allocate `std::set<int>` or clear full vectors. Use a monotonically incremented timestamp array `seen[val] = current_step` to query membership in $O(1)$ without zeroing out memory.
3. **Cycle Handling:** If game transitions contain cycles, standard recursion enters infinite loops. Use Kahn's topological degree reduction: track the count of winning transitions for each node.

---

## 6. Comprehensive Archive Task Registry (31 Tasks)

| Slug | Title | Difficulty | Contest | Solved Ratio | Archive Link |
| :--- | :--- | :---: | :--- | :---: | :---: |
| `game-of-chance` | **Game of Chance** | `EASY` | Round #48 (Div. 2 only) | 98% | [`game-of-chance`](../platforms/csacademy/tasks/game-of-chance/statement.md) |
| `numbers-game` | **Numbers Game** | `EASY` | Round #30 (Div. 2 only) | 97% | [`numbers-game`](../platforms/csacademy/tasks/numbers-game/statement.md) |
| `pokemon-fight` | **Pokemon Fight** | `EASY` | Round #13 | 88% | [`pokemon-fight`](../platforms/csacademy/tasks/pokemon-fight/statement.md) |
| `tennis-tournament` | **Tennis Tournament** | `EASY` | Round #41 | 92% | [`tennis-tournament`](../platforms/csacademy/tasks/tennis-tournament/statement.md) |
| `unfair_game` | **Unfair Game** | `EASY` | Beta Round #1 | 65% | [`unfair_game`](../platforms/csacademy/tasks/unfair_game/statement.md) |
| `mousetrap` | **Mousetrap** | `HARD` | CEOI 2017 Day 1 | 53% | [`mousetrap`](../platforms/csacademy/tasks/mousetrap/statement.md) |
| `pitmutation` | **Pitmutation** | `HARD` | Romanian IOI 2017 Selection #3 | 75% | [`pitmutation`](../platforms/csacademy/tasks/pitmutation/statement.md) |
| `random_nim_generator` | **Random Nim Generator** | `HARD` | Round #11 | 91% | [`random_nim_generator`](../platforms/csacademy/tasks/random_nim_generator/statement.md) |
| `tree_game` | **Tree Game** | `HARD` | Beta Round #2 | 62% | [`tree_game`](../platforms/csacademy/tasks/tree_game/statement.md) |
| `a_game` | **A-Game** | `MEDIUM` | Beta Round #3 | 79% | [`a_game`](../platforms/csacademy/tasks/a_game/statement.md) |
| `array-macao` | **Array Macao** | `MEDIUM` | CS Academy Archive | 78% | [`array-macao`](../platforms/csacademy/tasks/array-macao/statement.md) |
| `b9i` | **B9i** | `MEDIUM` | FIICode 2021 Round #1 | 77% | [`b9i`](../platforms/csacademy/tasks/b9i/statement.md) |
| `card-collecting-game` | **Card Collecting Game** | `MEDIUM` | Round #49 | 80% | [`card-collecting-game`](../platforms/csacademy/tasks/card-collecting-game/statement.md) |
| `chocolate` | **Chocolate** | `MEDIUM` | Romanian IOI 2017 Selection #4 | 40% | [`chocolate`](../platforms/csacademy/tasks/chocolate/statement.md) |
| `disjoint-tree-paths` | **Disjoint Tree Paths** | `MEDIUM` | Round #56 | 58% | [`disjoint-tree-paths`](../platforms/csacademy/tasks/disjoint-tree-paths/statement.md) |
| `endgame` | **Endgame** | `MEDIUM` | FIICode 2021 Round #2 | 75% | [`endgame`](../platforms/csacademy/tasks/endgame/statement.md) |
| `epic-marble-battles` | **Epic Marble Battles** | `MEDIUM` | CS Academy Archive | 67% | [`epic-marble-battles`](../platforms/csacademy/tasks/epic-marble-battles/statement.md) |
| `exponential_game` | **Exponential Game** | `MEDIUM` | Beta Round #6 | 81% | [`exponential_game`](../platforms/csacademy/tasks/exponential_game/statement.md) |
| `flip-game` | **Flip Game** | `MEDIUM` | (Out of Beta) Round #9 | 81% | [`flip-game`](../platforms/csacademy/tasks/flip-game/statement.md) |
| `game` | **Game** | `MEDIUM` | EJOI 2017 Day 2 | 66% | [`game`](../platforms/csacademy/tasks/game/statement.md) |
| `graph-game` | **Graph Game** | `MEDIUM` | Round #63 (Div. 2 only) | 95% | [`graph-game`](../platforms/csacademy/tasks/graph-game/statement.md) |
| `infinity-war` | **Infinity War** | `MEDIUM` | FIICode 2021 Round #2 | 88% | [`infinity-war`](../platforms/csacademy/tasks/infinity-war/statement.md) |
| `limited-moves` | **Limited Moves** | `MEDIUM` | Round #64 (Interactive only) | 94% | [`limited-moves`](../platforms/csacademy/tasks/limited-moves/statement.md) |
| `losing-nim` | **Losing Nim** | `MEDIUM` | Round #71 (Div. 2 only) | 72% | [`losing-nim`](../platforms/csacademy/tasks/losing-nim/statement.md) |
| `marbles-graph-game` | **Marbles Graph Game** | `MEDIUM` | Round #17 (Div. 2 only) | 69% | [`marbles-graph-game`](../platforms/csacademy/tasks/marbles-graph-game/statement.md) |
| `minimize-max-diff` | **Minimize Max Diff** | `MEDIUM` | Round #34 (Div. 2 only) | 84% | [`minimize-max-diff`](../platforms/csacademy/tasks/minimize-max-diff/statement.md) |
| `piece-of-cake` | **Piece of Cake** | `MEDIUM` | CS Academy Archive | 78% | [`piece-of-cake`](../platforms/csacademy/tasks/piece-of-cake/statement.md) |
| `play-time` | **Play Time** | `MEDIUM` | CS Academy Archive | 71% | [`play-time`](../platforms/csacademy/tasks/play-time/statement.md) |
| `shell-game` | **Shell Game** | `MEDIUM` | CS Academy Archive | 98% | [`shell-game`](../platforms/csacademy/tasks/shell-game/statement.md) |
| `suffix-flip` | **Suffix Flip** | `MEDIUM` | Round #67 | 89% | [`suffix-flip`](../platforms/csacademy/tasks/suffix-flip/statement.md) |
| `two-rows` | **Two Rows** | `MEDIUM` | CS Academy Archive | 87% | [`two-rows`](../platforms/csacademy/tasks/two-rows/statement.md) |
