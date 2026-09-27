# IEEE-Xtreme Competitive Programming Knowledge Base: Master Catalog

> **Grounding Metadata & NotebookLM Oracle**  
> - **Target Notebook ID:** `95a79d26-2f87-42cd-8cb9-8361a1e56059` (*Personal Notebook: ⚙️ Aaradhya — Engineer's Personal Notebook*)  
> - **Corpus Origin:** `F:\Aaradhya-Dev-Tamrakar\IEEE-Xtreme-Archive`  
> - **Total Tasks Analyzed:** `669` across CS Academy & IEEE PreXtreme Platforms  
> - **Compiler Target:** `g++ 15.2.0` (`-std=c++23 -O2 -pthread`) on Ubuntu 25.04 x64  
> - **Taxonomic Framework:** 10 Major Algorithmic Archetypes for Competitive Programming Mastery

---

## 1. Executive Taxonomy Matrix

Below is the core breakdown of all archived competitive programming tasks classified into 10 foundational archetypes. Each archetype is paired with a specialized briefing guide containing rigorous mathematical proofs, canonical solution blueprints, implementation traps, and complete task references.

| ID | Archetype | Core Paradigms & Techniques | Task Count | Study Guide Briefing |
| :-: | :--- | :--- | :-: | :--- |
| `01` | **Dynamic Programming** | Tree DP, Bitmask DP, Digit DP, Divide & Conquer DP, Interval DP, Matrix Exponentiation | **67** | [`briefings/01_dynamic_programming.md`](01_dynamic_programming.md) |
| `02` | **Graph Theory & Network Flows** | Shortest Path, 2-SAT, Max Flow, Min Cut, Bipartite Matching, SCC, Bridges | **69** | [`briefings/02_graph_theory_and_flows.md`](02_graph_theory_and_flows.md) |
| `03` | **Trees & Lowest Common Ancestor** | Binary Lifting, Heavy-Light Decomposition, Centroid Decomposition, Tree Diameters | **29** | [`briefings/03_trees_and_lca.md`](03_trees_and_lca.md) |
| `04` | **Range Queries & Data Structures** | Segment Tree, Fenwick Tree, Mo's Algorithm, Sparse Table, Treap, DSU | **24** | [`briefings/04_range_queries_and_data_structures.md`](04_range_queries_and_data_structures.md) |
| `05` | **Combinatorics & Number Theory** | Inclusion-Exclusion, Modulo Arithmetic, NTT/FFT, Prime Sieve, GCD/LCM, Burnside | **92** | [`briefings/05_combinatorics_and_number_theory.md`](05_combinatorics_and_number_theory.md) |
| `06` | **Greedy Algorithms & Two Pointers** | Interval Scheduling, Sliding Window, Prefix Sums, Monotonic Binary Search | **205** | [`briefings/06_greedy_and_two_pointers.md`](06_greedy_and_two_pointers.md) |
| `07` | **Computational Geometry & Convex Hull** | Points, Vectors, Cross Product, Convex Hull, Polygon Area, Rotating Calipers | **59** | [`briefings/07_computational_geometry.md`](07_computational_geometry.md) |
| `08` | **String Algorithms** | KMP, Z-algorithm, Suffix Automaton, Aho-Corasick, Rolling Hash, Manacher | **55** | [`briefings/08_string_algorithms.md`](08_string_algorithms.md) |
| `09` | **Game Theory & Nim Games** | Sprague-Grundy, Nim-sum, Impartial Games, Minimax, Backward Induction on DAGs | **31** | [`briefings/09_game_theory.md`](09_game_theory.md) |
| `10` | **Constructive & Interactive Algorithms** | Interactive Query Protocols, Flush Stdout, Parity Invariants, Permutation Construction | **38** | [`briefings/10_constructive_and_interactive.md`](10_constructive_and_interactive.md) |
| **TOTAL** | *Full Platform Archive* | *End-to-End Competitive Programming Coverage* | **669** | *Master Registry* |

---

## 2. Difficulty Distribution Across Archetypes

A balanced distribution of easy, medium, and hard tasks enables calibrated progressive training from contest warmups to Grandmaster-tier algorithmic challenges.

| Archetype | Easy | Medium | Hard | Tutorial / Other | Total |
| :--- | :-: | :-: | :-: | :-: | :-: |
| **Dynamic Programming** | 22 | 38 | 7 | 0 | **67** |
| **Graph Theory & Network Flows** | 14 | 38 | 17 | 0 | **69** |
| **Trees & Lowest Common Ancestor** | 0 | 20 | 9 | 0 | **29** |
| **Range Queries & Data Structures** | 3 | 15 | 6 | 0 | **24** |
| **Combinatorics & Number Theory** | 30 | 40 | 19 | 3 | **92** |
| **Greedy Algorithms & Two Pointers** | 57 | 129 | 19 | 0 | **205** |
| **Computational Geometry & Convex Hull** | 12 | 33 | 14 | 0 | **59** |
| **String Algorithms** | 17 | 33 | 5 | 0 | **55** |
| **Game Theory & Nim Games** | 5 | 22 | 4 | 0 | **31** |
| **Constructive & Interactive Algorithms** | 6 | 23 | 7 | 2 | **38** |

---

## 3. Algorithmic Archetype Profiles & Canonical Slugs

### 01. [Dynamic Programming](01_dynamic_programming.md) (67 Tasks)
**Key Patterns:** Tree DP, Bitmask DP, Digit DP, Divide & Conquer DP, Interval DP, Matrix Exponentiation  
**Study Guide File:** [`briefings/01_dynamic_programming.md`](01_dynamic_programming.md)  

**Featured Canonical Tasks:**
- [`odd-sum`](../platforms/csacademy/tasks/odd-sum/statement.md) — **Odd Sum** (`EASY`) | *Round #49*
- [`sorting_partition`](../platforms/csacademy/tasks/sorting_partition/statement.md) — **Sorting Partition** (`EASY`) | *Beta Round #1*
- [`maximize-profit`](../platforms/csacademy/tasks/maximize-profit/statement.md) — **Maximize Profit** (`MEDIUM`) | *Round #63 (Div. 2 only)*
- [`monotone-subarray`](../platforms/csacademy/tasks/monotone-subarray/statement.md) — **Monotone Subarray** (`EASY`) | *Round #53 (Div. 2 only)*
- [`three-equal`](../platforms/csacademy/tasks/three-equal/statement.md) — **Three Equal** (`MEDIUM`) | *Round #73 (Div. 2 only)*

### 02. [Graph Theory & Network Flows](02_graph_theory_and_flows.md) (69 Tasks)
**Key Patterns:** Shortest Path, 2-SAT, Max Flow, Min Cut, Bipartite Matching, SCC, Bridges  
**Study Guide File:** [`briefings/02_graph_theory_and_flows.md`](02_graph_theory_and_flows.md)  

**Featured Canonical Tasks:**
- [`donkey-paradox`](../platforms/csacademy/tasks/donkey-paradox/statement.md) — **Donkey Paradox** (`EASY`) | *Round #10*
- [`matrix_exploration`](../platforms/csacademy/tasks/matrix_exploration/statement.md) — **Matrix Exploration** (`EASY`) | *CS Academy Archive*
- [`xor-match`](../platforms/csacademy/tasks/xor-match/statement.md) — **Xor Match** (`MEDIUM`) | *Round #63 (Div. 2 only)*
- [`check-dfs`](../platforms/csacademy/tasks/check-dfs/statement.md) — **Check DFS** (`EASY`) | *Round #44 (Div. 2 only)*
- [`bicycle-rental`](../platforms/csacademy/tasks/bicycle-rental/statement.md) — **Bicycle Rental** (`EASY`) | *Round #36 (Div. 2 only)*

### 03. [Trees & Lowest Common Ancestor](03_trees_and_lca.md) (29 Tasks)
**Key Patterns:** Binary Lifting, Heavy-Light Decomposition, Centroid Decomposition, Tree Diameters  
**Study Guide File:** [`briefings/03_trees_and_lca.md`](03_trees_and_lca.md)  

**Featured Canonical Tasks:**
- [`virus-on-a-tree`](../platforms/csacademy/tasks/virus-on-a-tree/statement.md) — **Virus on a Tree** (`MEDIUM`) | *Round #52*
- [`crossing-tree`](../platforms/csacademy/tasks/crossing-tree/statement.md) — **Crossing Tree** (`MEDIUM`) | *Round #65 (Div. 2 only)*
- [`root-lca-queries`](../platforms/csacademy/tasks/root-lca-queries/statement.md) — **Root LCA Queries** (`MEDIUM`) | *Round #63 (Div. 2 only)*
- [`tree-coloring`](../platforms/csacademy/tasks/tree-coloring/statement.md) — **Tree Coloring** (`MEDIUM`) | *Round #51 (Div. 2 only)*
- [`tree-nodes-sets`](../platforms/csacademy/tasks/tree-nodes-sets/statement.md) — **Tree Nodes Sets** (`MEDIUM`) | *Round #36 (Div. 2 only)*

### 04. [Range Queries & Data Structures](04_range_queries_and_data_structures.md) (24 Tasks)
**Key Patterns:** Segment Tree, Fenwick Tree, Mo's Algorithm, Sparse Table, Treap, DSU  
**Study Guide File:** [`briefings/04_range_queries_and_data_structures.md`](04_range_queries_and_data_structures.md)  

**Featured Canonical Tasks:**
- [`nested-segments`](../platforms/csacademy/tasks/nested-segments/statement.md) — **Nested Segments** (`EASY`) | *Round #56*
- [`dictionary-pagination`](../platforms/csacademy/tasks/dictionary-pagination/statement.md) — **Dictionary Pagination** (`EASY`) | *(Out of Beta) Round #9*
- [`contiguous-segments`](../platforms/csacademy/tasks/contiguous-segments/statement.md) — **Contiguous Segments** (`EASY`) | *Round #58*
- [`bitwise-and-queries`](../platforms/csacademy/tasks/bitwise-and-queries/statement.md) — **Bitwise And Queries** (`MEDIUM`) | *Round #12 (Div. 2 only)*
- [`seven-segment-display`](../platforms/csacademy/tasks/seven-segment-display/statement.md) — **Seven-segment Display** (`MEDIUM`) | *Round #39 (Div. 2 only)*

### 05. [Combinatorics & Number Theory](05_combinatorics_and_number_theory.md) (92 Tasks)
**Key Patterns:** Inclusion-Exclusion, Modulo Arithmetic, NTT/FFT, Prime Sieve, GCD/LCM, Burnside  
**Study Guide File:** [`briefings/05_combinatorics_and_number_theory.md`](05_combinatorics_and_number_theory.md)  

**Featured Canonical Tasks:**
- [`addition`](../platforms/csacademy/tasks/addition/statement.md) — **Addition** (`TUTORIAL`) | *CS Academy Archive*
- [`gcd`](../platforms/csacademy/tasks/gcd/statement.md) — **Greatest Common Divisor** (`TUTORIAL`) | *CS Academy Archive*
- [`3-divisible-pairs`](../platforms/csacademy/tasks/3-divisible-pairs/statement.md) — **3-divisible Pairs** (`EASY`) | *(Out of Beta) Round #9*
- [`odd-divisor-count`](../platforms/csacademy/tasks/odd-divisor-count/statement.md) — **Odd Divisor Count** (`EASY`) | *Round #12 (Div. 2 only)*
- [`frequent-numbers`](../platforms/csacademy/tasks/frequent-numbers/statement.md) — **Frequent Numbers** (`EASY`) | *Round #44 (Div. 2 only)*

### 06. [Greedy Algorithms & Two Pointers](06_greedy_and_two_pointers.md) (205 Tasks)
**Key Patterns:** Interval Scheduling, Sliding Window, Prefix Sums, Monotonic Binary Search  
**Study Guide File:** [`briefings/06_greedy_and_two_pointers.md`](06_greedy_and_two_pointers.md)  

**Featured Canonical Tasks:**
- [`shoe-pairs`](../platforms/csacademy/tasks/shoe-pairs/statement.md) — **Shoe Pairs** (`EASY`) | *Round #38*
- [`pokemon-evolution`](../platforms/csacademy/tasks/pokemon-evolution/statement.md) — **Pokémon Evolution** (`EASY`) | *Round #10*
- [`attack-and-speed`](../platforms/csacademy/tasks/attack-and-speed/statement.md) — **Attack and Speed** (`EASY`) | *Round #38*
- [`fill-the-glasses`](../platforms/csacademy/tasks/fill-the-glasses/statement.md) — **Fill the Glasses** (`EASY`) | *Round #54*
- [`celsius-to-fahrenheit`](../platforms/csacademy/tasks/celsius-to-fahrenheit/statement.md) — **Celsius to Fahrenheit** (`MEDIUM`) | *Round #61*

### 07. [Computational Geometry & Convex Hull](07_computational_geometry.md) (59 Tasks)
**Key Patterns:** Points, Vectors, Cross Product, Convex Hull, Polygon Area, Rotating Calipers  
**Study Guide File:** [`briefings/07_computational_geometry.md`](07_computational_geometry.md)  

**Featured Canonical Tasks:**
- [`matrix_rotations`](../platforms/csacademy/tasks/matrix_rotations/statement.md) — **Matrix Rotations** (`EASY`) | *Beta Round #5*
- [`travel-distance`](../platforms/csacademy/tasks/travel-distance/statement.md) — **Travel Distance** (`EASY`) | *Round #50 (Div. 2 only)*
- [`check-square`](../platforms/csacademy/tasks/check-square/statement.md) — **Check Square** (`EASY`) | *Round #50 (Div. 2 only)*
- [`dominant-point`](../platforms/csacademy/tasks/dominant-point/statement.md) — **Dominant Point** (`EASY`) | *Round #13*
- [`circle-elimination`](../platforms/csacademy/tasks/circle-elimination/statement.md) — **Circle Elimination** (`EASY`) | *Round #39 (Div. 2 only)*

### 08. [String Algorithms](08_string_algorithms.md) (55 Tasks)
**Key Patterns:** KMP, Z-algorithm, Suffix Automaton, Aho-Corasick, Rolling Hash, Manacher  
**Study Guide File:** [`briefings/08_string_algorithms.md`](08_string_algorithms.md)  

**Featured Canonical Tasks:**
- [`anagrams`](../platforms/csacademy/tasks/anagrams/statement.md) — **Anagrams** (`EASY`) | *Beta Round #4*
- [`one_letter`](../platforms/csacademy/tasks/one_letter/statement.md) — **One Letter** (`EASY`) | *Beta Round #7*
- [`word_permutation`](../platforms/csacademy/tasks/word_permutation/statement.md) — **Word Permutation** (`EASY`) | *Beta Round #2*
- [`encipherment`](../platforms/csacademy/tasks/encipherment/statement.md) — **Encipherment** (`MEDIUM`) | *Round #65 (Div. 2 only)*
- [`word_ordering`](../platforms/csacademy/tasks/word_ordering/statement.md) — **Word Ordering** (`EASY`) | *Beta Round #1*

### 09. [Game Theory & Nim Games](09_game_theory.md) (31 Tasks)
**Key Patterns:** Sprague-Grundy, Nim-sum, Impartial Games, Minimax, Backward Induction on DAGs  
**Study Guide File:** [`briefings/09_game_theory.md`](09_game_theory.md)  

**Featured Canonical Tasks:**
- [`game-of-chance`](../platforms/csacademy/tasks/game-of-chance/statement.md) — **Game of Chance** (`EASY`) | *Round #48 (Div. 2 only)*
- [`flip-game`](../platforms/csacademy/tasks/flip-game/statement.md) — **Flip Game** (`MEDIUM`) | *(Out of Beta) Round #9*
- [`unfair_game`](../platforms/csacademy/tasks/unfair_game/statement.md) — **Unfair Game** (`EASY`) | *Beta Round #1*
- [`pokemon-fight`](../platforms/csacademy/tasks/pokemon-fight/statement.md) — **Pokemon Fight** (`EASY`) | *Round #13*
- [`tennis-tournament`](../platforms/csacademy/tasks/tennis-tournament/statement.md) — **Tennis Tournament** (`EASY`) | *Round #41*

### 10. [Constructive & Interactive Algorithms](10_constructive_and_interactive.md) (38 Tasks)
**Key Patterns:** Interactive Query Protocols, Flush Stdout, Parity Invariants, Permutation Construction  
**Study Guide File:** [`briefings/10_constructive_and_interactive.md`](10_constructive_and_interactive.md)  

**Featured Canonical Tasks:**
- [`consecutive-sum`](../platforms/csacademy/tasks/consecutive-sum/statement.md) — **Consecutive Sum** (`EASY`) | *Round #47*
- [`prime-factors`](../platforms/csacademy/tasks/prime-factors/statement.md) — **Prime Factors** (`MEDIUM`) | *Round #64 (Interactive only)*
- [`adaptive-binary-search`](../platforms/csacademy/tasks/adaptive-binary-search/statement.md) — **Adaptive Binary Search** (`TUTORIAL`) | *CS Academy Archive*
- [`flip-the-prefix`](../platforms/csacademy/tasks/flip-the-prefix/statement.md) — **Flip the Prefix** (`EASY`) | *Round #45 (Div. 1.5)*
- [`binary-search`](../platforms/csacademy/tasks/binary-search/statement.md) — **Binary Search** (`TUTORIAL`) | *CS Academy Archive*

---

## 4. Master Task Slug Cross-Index

Complete alphabetized index of all 669 tasks mapped to their respective archetypes and local statements.

| Slug | Title | Archetype | Difficulty | Contest | Local Statement |
| :--- | :--- | :--- | :---: | :--- | :---: |
| `0-k-multiple` | 0-K Multiple | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #21 | [`statement.md`](../platforms/csacademy/tasks/0-k-multiple/statement.md) |
| `0-sum-array` | 0-Sum Array | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #25 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/0-sum-array/statement.md) |
| `101-palindromes` | 101 Palindromes | [`08`](08_string_algorithms.md) | `HARD` | (Out of Beta) Round #9 | [`statement.md`](../platforms/csacademy/tasks/101-palindromes/statement.md) |
| `3-divisible-pairs` | 3-divisible Pairs | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | (Out of Beta) Round #9 | [`statement.md`](../platforms/csacademy/tasks/3-divisible-pairs/statement.md) |
| `8-divisible` | 8 Divisible | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #48 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/8-divisible/statement.md) |
| `Sugarel-and-modulo` | Sugarel and Modulo | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/Sugarel-and-modulo/statement.md) |
| `Sugarel-in-Love` | Sugarel in Love | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/Sugarel-in-Love/statement.md) |
| `Sugarel-s-Garden` | Sugarel’s Garden | [`07`](07_computational_geometry.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/Sugarel-s-Garden/statement.md) |
| `a-single-one` | A Single One | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #11 | [`statement.md`](../platforms/csacademy/tasks/a-single-one/statement.md) |
| `a_game` | A-Game | [`09`](09_game_theory.md) | `MEDIUM` | Beta Round #3 | [`statement.md`](../platforms/csacademy/tasks/a_game/statement.md) |
| `aa-tree` | AA Tree | [`03`](03_trees_and_lca.md) | `MEDIUM` | RMI 2023 - Day 1 Mirror | [`statement.md`](../platforms/csacademy/tasks/aa-tree/statement.md) |
| `acronyms` | Acronyms | [`08`](08_string_algorithms.md) | `EASY` | Round #54 | [`statement.md`](../platforms/csacademy/tasks/acronyms/statement.md) |
| `adaptive-binary-search` | Adaptive Binary Search | [`10`](10_constructive_and_interactive.md) | `TUTORIAL` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/adaptive-binary-search/statement.md) |
| `add-and-divide` | Add and Divide | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #28 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/add-and-divide/statement.md) |
| `add-and-subtract` | Add and Subtract | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #41 | [`statement.md`](../platforms/csacademy/tasks/add-and-subtract/statement.md) |
| `addition` | Addition | [`05`](05_combinatorics_and_number_theory.md) | `TUTORIAL` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/addition/statement.md) |
| `addition-time` | Addition Time | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/addition-time/statement.md) |
| `adjacent-vowels` | Adjacent Vowels | [`08`](08_string_algorithms.md) | `EASY` | Round #47 | [`statement.md`](../platforms/csacademy/tasks/adjacent-vowels/statement.md) |
| `aggressive-pawns` | Aggressive Pawns | [`07`](07_computational_geometry.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/aggressive-pawns/statement.md) |
| `airport` | Airport | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Romanian IOI Selection 2023 - Day 2 | [`statement.md`](../platforms/csacademy/tasks/airport/statement.md) |
| `aisimok` | Aisimok | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | FIICode 2021 Round #1 | [`statement.md`](../platforms/csacademy/tasks/aisimok/statement.md) |
| `alex-chills` | Alex Chills | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | FIICode 2021 Round #3 | [`statement.md`](../platforms/csacademy/tasks/alex-chills/statement.md) |
| `alex-climbs` | Alex Climbs | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | FIICode 2021 Round #3 | [`statement.md`](../platforms/csacademy/tasks/alex-climbs/statement.md) |
| `alex-combines` | Alex Combines | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | FIICode 2021 Round #3 | [`statement.md`](../platforms/csacademy/tasks/alex-combines/statement.md) |
| `alex-concatenates` | Alex Concatenates | [`01`](01_dynamic_programming.md) | `MEDIUM` | FIICode 2021 Round #3 | [`statement.md`](../platforms/csacademy/tasks/alex-concatenates/statement.md) |
| `alex-counts` | Alex Counts | [`01`](01_dynamic_programming.md) | `MEDIUM` | FIICode 2021 Round #3 | [`statement.md`](../platforms/csacademy/tasks/alex-counts/statement.md) |
| `alice-tree` | Alice's Tree | [`03`](03_trees_and_lca.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/alice-tree/statement.md) |
| `all-numbers` | All Numbers | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/all-numbers/statement.md) |
| `alphabet-rotation` | Alphabet Rotation | [`08`](08_string_algorithms.md) | `EASY` | Beta Round #8 | [`statement.md`](../platforms/csacademy/tasks/alphabet-rotation/statement.md) |
| `alternant-array` | Alternant Array | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #61 | [`statement.md`](../platforms/csacademy/tasks/alternant-array/statement.md) |
| `alternating-subarray` | Alternating Subarray | [`01`](01_dynamic_programming.md) | `EASY` | Round #15 | [`statement.md`](../platforms/csacademy/tasks/alternating-subarray/statement.md) |
| `amusement-park` | Amusement Park | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #49 | [`statement.md`](../platforms/csacademy/tasks/amusement-park/statement.md) |
| `an-unstable-graph` | An Unstable Graph | [`02`](02_graph_theory_and_flows.md) | `HARD` | Round #52 | [`statement.md`](../platforms/csacademy/tasks/an-unstable-graph/statement.md) |
| `anagram-sort` | Anagram Sort | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | [`statement.md`](../platforms/csacademy/tasks/anagram-sort/statement.md) |
| `anagrams` | Anagrams | [`08`](08_string_algorithms.md) | `EASY` | Beta Round #4 | [`statement.md`](../platforms/csacademy/tasks/anagrams/statement.md) |
| `and-closure` | And Closure | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #13 | [`statement.md`](../platforms/csacademy/tasks/and-closure/statement.md) |
| `and-or-max` | And or Max | [`04`](04_range_queries_and_data_structures.md) | `HARD` | Round #70 | [`statement.md`](../platforms/csacademy/tasks/and-or-max/statement.md) |
| `anomalies` | Anomalies | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #58 | [`statement.md`](../platforms/csacademy/tasks/anomalies/statement.md) |
| `array-elimination` | Array Elimination | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #44 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/array-elimination/statement.md) |
| `array-macao` | Array Macao | [`09`](09_game_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/array-macao/statement.md) |
| `array-removal` | Array Removal | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | (Out of Beta) Round #9 | [`statement.md`](../platforms/csacademy/tasks/array-removal/statement.md) |
| `array_coloring` | Array Coloring | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Beta Round #7 | [`statement.md`](../platforms/csacademy/tasks/array_coloring/statement.md) |
| `as-easy-as-abc` | As easy as ABC | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/as-easy-as-abc/statement.md) |
| `aspirations` | Aspirations | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/aspirations/statement.md) |
| `attack-and-speed` | Attack and Speed | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #38 | [`statement.md`](../platforms/csacademy/tasks/attack-and-speed/statement.md) |
| `attending-events` | Attending Events | [`01`](01_dynamic_programming.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/attending-events/statement.md) |
| `b9i` | B9i | [`09`](09_game_theory.md) | `MEDIUM` | FIICode 2021 Round #1 | [`statement.md`](../platforms/csacademy/tasks/b9i/statement.md) |
| `baby-seokhwan` | Baby Seokhwan | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/baby-seokhwan/statement.md) |
| `back-in-business` | Back in Business | [`07`](07_computational_geometry.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/back-in-business/statement.md) |
| `backpack-packing` | Backpack Packing | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #27 | [`statement.md`](../platforms/csacademy/tasks/backpack-packing/statement.md) |
| `bad-triplet` | Bad Triplet | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #43 | [`statement.md`](../platforms/csacademy/tasks/bad-triplet/statement.md) |
| `balanced-min-pairing` | Balanced Min Pairing | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #13 | [`statement.md`](../platforms/csacademy/tasks/balanced-min-pairing/statement.md) |
| `balanced-number` | Balanced Number | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #42 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/balanced-number/statement.md) |
| `balanced-string` | Balanced String | [`08`](08_string_algorithms.md) | `HARD` | IOI 2016 Training Round #5 | [`statement.md`](../platforms/csacademy/tasks/balanced-string/statement.md) |
| `balanced-strings` | Balanced Strings | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #31 | [`statement.md`](../platforms/csacademy/tasks/balanced-strings/statement.md) |
| `ball-sampling` | Ball Sampling | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #24 | [`statement.md`](../platforms/csacademy/tasks/ball-sampling/statement.md) |
| `banned-digits` | Banned Digits | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/banned-digits/statement.md) |
| `base-k-xor` | Base K Xor | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #15 | [`statement.md`](../platforms/csacademy/tasks/base-k-xor/statement.md) |
| `bbox-count` | BBox Count | [`07`](07_computational_geometry.md) | `HARD` | Round #36 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/bbox-count/statement.md) |
| `beautiful-matrix` | Beautiful Matrix | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #72 | [`statement.md`](../platforms/csacademy/tasks/beautiful-matrix/statement.md) |
| `best-array-cut` | Best Array Cut | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #19 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/best-array-cut/statement.md) |
| `best-driver` | Best Driver | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/best-driver/statement.md) |
| `bfs` | Bfs | [`04`](04_range_queries_and_data_structures.md) | `HARD` | Romanian IOI 2017 Selection #3 | [`statement.md`](../platforms/csacademy/tasks/bfs/statement.md) |
| `bfs-dfs` | BFS-DFS | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #41 | [`statement.md`](../platforms/csacademy/tasks/bfs-dfs/statement.md) |
| `bicycle-rental` | Bicycle Rental | [`02`](02_graph_theory_and_flows.md) | `EASY` | Round #36 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/bicycle-rental/statement.md) |
| `big-string` | Big String | [`08`](08_string_algorithms.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/big-string/statement.md) |
| `binary-differences` | Binary Differences | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #71 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/binary-differences/statement.md) |
| `binary-flips` | Binary Flips | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #57 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/binary-flips/statement.md) |
| `binary-isomorphism` | Binary Isomorphism | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #73 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/binary-isomorphism/statement.md) |
| `binary-search` | Binary Search | [`10`](10_constructive_and_interactive.md) | `TUTORIAL` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/binary-search/statement.md) |
| `binary-swaps` | Binary Swaps | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Round #58 | [`statement.md`](../platforms/csacademy/tasks/binary-swaps/statement.md) |
| `binary_matching` | Binary Matching | [`02`](02_graph_theory_and_flows.md) | `HARD` | Beta Round #5 | [`statement.md`](../platforms/csacademy/tasks/binary_matching/statement.md) |
| `bitwise-and-queries` | Bitwise And Queries | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | Round #12 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/bitwise-and-queries/statement.md) |
| `black-shapes` | Black Shapes | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #22 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/black-shapes/statement.md) |
| `black-white-necklace` | Black White Necklace | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #24 | [`statement.md`](../platforms/csacademy/tasks/black-white-necklace/statement.md) |
| `black-white-tree` | Black White Tree | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | Round #55 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/black-white-tree/statement.md) |
| `boaty-mcboatface` | Boaty McBoatface | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #75 | [`statement.md`](../platforms/csacademy/tasks/boaty-mcboatface/statement.md) |
| `bob-tree` | Bob's Tree | [`03`](03_trees_and_lca.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/bob-tree/statement.md) |
| `boring-number` | Boring Number | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #37 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/boring-number/statement.md) |
| `boring-operation` | Boring Operation | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/boring-operation/statement.md) |
| `borland` | Borland | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Junior Challenge 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/borland/statement.md) |
| `boss-fight` | Boss Fight | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/boss-fight/statement.md) |
| `bottle-recycling` | Bottle Recycling | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #18 | [`statement.md`](../platforms/csacademy/tasks/bottle-recycling/statement.md) |
| `bounded-diameter-trees` | Bounded Diameter Trees | [`03`](03_trees_and_lca.md) | `HARD` | Round #14 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/bounded-diameter-trees/statement.md) |
| `bounded-difference` | Bounded Difference | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #38 | [`statement.md`](../platforms/csacademy/tasks/bounded-difference/statement.md) |
| `bounded-distinct` | Bounded Distinct | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #26 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/bounded-distinct/statement.md) |
| `bounding-box` | Bounding Box | [`07`](07_computational_geometry.md) | `EASY` | Round #33 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/bounding-box/statement.md) |
| `bracket-grid` | Bracket Grid | [`10`](10_constructive_and_interactive.md) | `HARD` | Round #49 | [`statement.md`](../platforms/csacademy/tasks/bracket-grid/statement.md) |
| `bst-fixed-height` | BST Fixed Height | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #24 | [`statement.md`](../platforms/csacademy/tasks/bst-fixed-height/statement.md) |
| `build-binary-matrix` | Build Binary Matrix | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #35 | [`statement.md`](../platforms/csacademy/tasks/build-binary-matrix/statement.md) |
| `build-correct-brackets` | Build Correct Brackets | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #69 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/build-correct-brackets/statement.md) |
| `build-the-fence` | Build the Fence | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #55 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/build-the-fence/statement.md) |
| `build-the-towers` | Build the Towers | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #26 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/build-the-towers/statement.md) |
| `building-bridges` | Building Bridges | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | CEOI 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/building-bridges/statement.md) |
| `bunny-on-number-line` | Bunny on Number Line | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Round #49 | [`statement.md`](../platforms/csacademy/tasks/bunny-on-number-line/statement.md) |
| `camel` | Camel | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | EJOI 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/camel/statement.md) |
| `candles` | Candles | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Round #41 | [`statement.md`](../platforms/csacademy/tasks/candles/statement.md) |
| `candy-boxes` | Candy Boxes | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #76 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/candy-boxes/statement.md) |
| `card-collecting-game` | Card Collecting Game | [`09`](09_game_theory.md) | `MEDIUM` | Round #49 | [`statement.md`](../platforms/csacademy/tasks/card-collecting-game/statement.md) |
| `card-groups` | Card Groups | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #60 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/card-groups/statement.md) |
| `card-shuffle` | Card Shuffle | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #28 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/card-shuffle/statement.md) |
| `catch-the-thief` | Catch the Thief | [`02`](02_graph_theory_and_flows.md) | `HARD` | Round #21 | [`statement.md`](../platforms/csacademy/tasks/catch-the-thief/statement.md) |
| `cats` | Cats | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Balkan OI 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/cats/statement.md) |
| `cats-and-dogs` | Cats and Dogs | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/cats-and-dogs/statement.md) |
| `celsius-to-fahrenheit` | Celsius to Fahrenheit | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #61 | [`statement.md`](../platforms/csacademy/tasks/celsius-to-fahrenheit/statement.md) |
| `chase` | Chase | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CEOI 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/chase/statement.md) |
| `check-dfs` | Check DFS | [`02`](02_graph_theory_and_flows.md) | `EASY` | Round #44 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/check-dfs/statement.md) |
| `check-square` | Check Square | [`07`](07_computational_geometry.md) | `EASY` | Round #50 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/check-square/statement.md) |
| `checkroom-hooks` | Checkroom Hooks | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #38 | [`statement.md`](../platforms/csacademy/tasks/checkroom-hooks/statement.md) |
| `chocolate` | Chocolate | [`09`](09_game_theory.md) | `MEDIUM` | Romanian IOI 2017 Selection #4 | [`statement.md`](../platforms/csacademy/tasks/chocolate/statement.md) |
| `choose-the-price` | Choose the Price | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #34 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/choose-the-price/statement.md) |
| `chromatic-number` | Chromatic Number | [`01`](01_dynamic_programming.md) | `MEDIUM` | Junior Challenge 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/chromatic-number/statement.md) |
| `cinema-seats` | Cinema Seats | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #41 | [`statement.md`](../platforms/csacademy/tasks/cinema-seats/statement.md) |
| `circle-elimination` | Circle Elimination | [`07`](07_computational_geometry.md) | `EASY` | Round #39 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/circle-elimination/statement.md) |
| `circle-kingdom` | Circle Kingdom | [`07`](07_computational_geometry.md) | `MEDIUM` | Round #72 | [`statement.md`](../platforms/csacademy/tasks/circle-kingdom/statement.md) |
| `circuits` | Circuits | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | RMI 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/circuits/statement.md) |
| `circular_shift_sort` | Circular Shift Sort | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Beta Round #7 | [`statement.md`](../platforms/csacademy/tasks/circular_shift_sort/statement.md) |
| `circular_subarrays` | Circular Subarrays | [`01`](01_dynamic_programming.md) | `MEDIUM` | Beta Round #2 | [`statement.md`](../platforms/csacademy/tasks/circular_subarrays/statement.md) |
| `cities-robbery` | Cities Robbery | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #19 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/cities-robbery/statement.md) |
| `city-attractions` | City Attractions | [`07`](07_computational_geometry.md) | `MEDIUM` | Balkan OI 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/city-attractions/statement.md) |
| `city-break` | City Break | [`07`](07_computational_geometry.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/city-break/statement.md) |
| `city-upgrades` | City Upgrades | [`02`](02_graph_theory_and_flows.md) | `EASY` | Round #20 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/city-upgrades/statement.md) |
| `classic-task` | Classic Task | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #65 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/classic-task/statement.md) |
| `closest-numbers` | Closest Numbers | [`04`](04_range_queries_and_data_structures.md) | `HARD` | Round #54 | [`statement.md`](../platforms/csacademy/tasks/closest-numbers/statement.md) |
| `cloud-computing` | Cloud Computing | [`01`](01_dynamic_programming.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/cloud-computing/statement.md) |
| `clown-fiesta` | Clown Fiesta | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | FIICode 2021 Round #2 | [`statement.md`](../platforms/csacademy/tasks/clown-fiesta/statement.md) |
| `clubs` | Clubs | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | IATI Shumen 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/clubs/statement.md) |
| `cntgigelmat` | Count Gigel Matrices | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #46 (Div. 1.5) | [`statement.md`](../platforms/csacademy/tasks/cntgigelmat/statement.md) |
| `cograph_clique` | Cograph Clique | [`02`](02_graph_theory_and_flows.md) | `HARD` | IOI 2016 Training Round #2 | [`statement.md`](../platforms/csacademy/tasks/cograph_clique/statement.md) |
| `colored-forests` | Colored Forests | [`03`](03_trees_and_lca.md) | `MEDIUM` | Round #24 | [`statement.md`](../platforms/csacademy/tasks/colored-forests/statement.md) |
| `colored_marbles` | Colored Marbles | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Beta Round #1 | [`statement.md`](../platforms/csacademy/tasks/colored_marbles/statement.md) |
| `colorgraph` | Colorgraph | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | IATI Shumen 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/colorgraph/statement.md) |
| `combinatorix` | Combinatorix | [`04`](04_range_queries_and_data_structures.md) | `HARD` | Round #46 (Div. 1.5) | [`statement.md`](../platforms/csacademy/tasks/combinatorix/statement.md) |
| `concatenated-array` | Concatenated Array | [`08`](08_string_algorithms.md) | `EASY` | Round #57 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/concatenated-array/statement.md) |
| `concatenated-string` | Concatenated String | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #18 | [`statement.md`](../platforms/csacademy/tasks/concatenated-string/statement.md) |
| `confused-robot` | Confused Robot | [`08`](08_string_algorithms.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/confused-robot/statement.md) |
| `connect-the-graph` | Connect the Graph | [`02`](02_graph_theory_and_flows.md) | `EASY` | Round #11 | [`statement.md`](../platforms/csacademy/tasks/connect-the-graph/statement.md) |
| `connected-tree-subgraphs` | Connected Tree Subgraphs | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Round #11 | [`statement.md`](../platforms/csacademy/tasks/connected-tree-subgraphs/statement.md) |
| `connecting-the-graph` | Connecting the Graph | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/connecting-the-graph/statement.md) |
| `consecutive-digit-signs` | Consecutive Digits Signs | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #18 | [`statement.md`](../platforms/csacademy/tasks/consecutive-digit-signs/statement.md) |
| `consecutive-remainders` | Consecutive Remainders | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/consecutive-remainders/statement.md) |
| `consecutive-subsequence` | Consecutive Subsequence | [`01`](01_dynamic_programming.md) | `EASY` | Beta Round #8 | [`statement.md`](../platforms/csacademy/tasks/consecutive-subsequence/statement.md) |
| `consecutive-sum` | Consecutive Sum | [`10`](10_constructive_and_interactive.md) | `EASY` | Round #47 | [`statement.md`](../platforms/csacademy/tasks/consecutive-sum/statement.md) |
| `constant-sum` | Constant Sum | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #30 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/constant-sum/statement.md) |
| `contiguous-segments` | Contiguous Segments | [`04`](04_range_queries_and_data_structures.md) | `EASY` | Round #58 | [`statement.md`](../platforms/csacademy/tasks/contiguous-segments/statement.md) |
| `cookie-clicker` | Cookie Clicker | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/cookie-clicker/statement.md) |
| `coprime` | Coprime Pairs | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #43 | [`statement.md`](../platforms/csacademy/tasks/coprime/statement.md) |
| `cosmological-nightmare` | Cosmological Nightmare | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/cosmological-nightmare/statement.md) |
| `count-4-cycles` | Count 4-cycles | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #65 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/count-4-cycles/statement.md) |
| `count-arrays` | Count Arrays | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #65 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/count-arrays/statement.md) |
| `count-bst` | Count BST | [`03`](03_trees_and_lca.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/count-bst/statement.md) |
| `count-squares` | Count Squares | [`07`](07_computational_geometry.md) | `MEDIUM` | Round #44 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/count-squares/statement.md) |
| `counting-quacks` | Counting Quacks | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #66 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/counting-quacks/statement.md) |
| `counting-quests` | Counting Quests | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #35 | [`statement.md`](../platforms/csacademy/tasks/counting-quests/statement.md) |
| `cover-the-tree` | Cover the Tree | [`03`](03_trees_and_lca.md) | `MEDIUM` | Round #69 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/cover-the-tree/statement.md) |
| `create-tree` | Create Tree | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #64 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/create-tree/statement.md) |
| `critical-cells` | Critical Cells | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #26 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/critical-cells/statement.md) |
| `crossing-tree` | Crossing Tree | [`03`](03_trees_and_lca.md) | `MEDIUM` | Round #65 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/crossing-tree/statement.md) |
| `crypto` | Crypto | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | IATI Shumen 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/crypto/statement.md) |
| `cryptomania` | Cryptomania | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/cryptomania/statement.md) |
| `cube-coloring` | Cube Coloring | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Beta Round #8 | [`statement.md`](../platforms/csacademy/tasks/cube-coloring/statement.md) |
| `cuinelo` | Cuinelo | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | FIICode 2021 Round #1 | [`statement.md`](../platforms/csacademy/tasks/cuinelo/statement.md) |
| `cut-the-edges` | Cut the Edges | [`02`](02_graph_theory_and_flows.md) | `HARD` | Round #58 | [`statement.md`](../platforms/csacademy/tasks/cut-the-edges/statement.md) |
| `cut-the-tree` | Cut the Tree | [`03`](03_trees_and_lca.md) | `MEDIUM` | Round #52 | [`statement.md`](../platforms/csacademy/tasks/cut-the-tree/statement.md) |
| `cut-the-trees` | Cut the Trees | [`03`](03_trees_and_lca.md) | `MEDIUM` | Round #47 | [`statement.md`](../platforms/csacademy/tasks/cut-the-trees/statement.md) |
| `cycle_tree` | Cycle Tree | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Beta Round #5 | [`statement.md`](../platforms/csacademy/tasks/cycle_tree/statement.md) |
| `cyclic-shifts` | Cyclic Shifts | [`07`](07_computational_geometry.md) | `HARD` | Round #67 | [`statement.md`](../platforms/csacademy/tasks/cyclic-shifts/statement.md) |
| `dacian-array` | Dacian Array | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Romanian IOI Selection 2023 - Day 1 | [`statement.md`](../platforms/csacademy/tasks/dacian-array/statement.md) |
| `dakara` | Dakara | [`01`](01_dynamic_programming.md) | `MEDIUM` | Romanian IOI Selection 2023 - Day 2 | [`statement.md`](../platforms/csacademy/tasks/dakara/statement.md) |
| `dazzling-trams` | Dazzling Trams | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/dazzling-trams/statement.md) |
| `decreasing-subarrays` | Decreasing Subarrays | [`01`](01_dynamic_programming.md) | `EASY` | Round #35 | [`statement.md`](../platforms/csacademy/tasks/decreasing-subarrays/statement.md) |
| `dependency-graph` | Dependency Graph | [`02`](02_graph_theory_and_flows.md) | `HARD` | Beta Round #8 | [`statement.md`](../platforms/csacademy/tasks/dependency-graph/statement.md) |
| `dictionary-pagination` | Dictionary Pagination | [`04`](04_range_queries_and_data_structures.md) | `EASY` | (Out of Beta) Round #9 | [`statement.md`](../platforms/csacademy/tasks/dictionary-pagination/statement.md) |
| `diesel-train` | Diesel Train | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #43 | [`statement.md`](../platforms/csacademy/tasks/diesel-train/statement.md) |
| `digit-function` | Digit Function | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/digit-function/statement.md) |
| `digit-holes` | Digit Holes | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #70 | [`statement.md`](../platforms/csacademy/tasks/digit-holes/statement.md) |
| `digit-permutation` | Digit Permutation | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #60 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/digit-permutation/statement.md) |
| `digital-lcs` | Digital LCS | [`01`](01_dynamic_programming.md) | `HARD` | Round #43 | [`statement.md`](../platforms/csacademy/tasks/digital-lcs/statement.md) |
| `digits-permutation` | Digits Permutation | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | [`statement.md`](../platforms/csacademy/tasks/digits-permutation/statement.md) |
| `direct-the-graph` | Direct the Graph | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #40 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/direct-the-graph/statement.md) |
| `dirijor` | Dirijor | [`03`](03_trees_and_lca.md) | `MEDIUM` | Romanian IOI Selection 2023 - Day 3 | [`statement.md`](../platforms/csacademy/tasks/dirijor/statement.md) |
| `disjoint-tree-paths` | Disjoint Tree Paths | [`09`](09_game_theory.md) | `MEDIUM` | Round #56 | [`statement.md`](../platforms/csacademy/tasks/disjoint-tree-paths/statement.md) |
| `disk-mechanism` | Disk Mechanism | [`07`](07_computational_geometry.md) | `MEDIUM` | Round #23 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/disk-mechanism/statement.md) |
| `disproportionate-tree` | Disproportionate Tree | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/disproportionate-tree/statement.md) |
| `distinct-palindromes` | Distinct Palindromes | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #57 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/distinct-palindromes/statement.md) |
| `distinct_neighbours` | Distinct Neighbours | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Beta Round #7 | [`statement.md`](../platforms/csacademy/tasks/distinct_neighbours/statement.md) |
| `distinct_rotations` | Distinct Rotations | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #22 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/distinct_rotations/statement.md) |
| `distribute-candies` | Distribute Candies | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #70 | [`statement.md`](../platforms/csacademy/tasks/distribute-candies/statement.md) |
| `div-3` | Div 3 | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #33 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/div-3/statement.md) |
| `divided-kingdom` | Divided Kingdom | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/divided-kingdom/statement.md) |
| `divisible-matching` | Divisible Matching | [`02`](02_graph_theory_and_flows.md) | `HARD` | Round #67 | [`statement.md`](../platforms/csacademy/tasks/divisible-matching/statement.md) |
| `divisor_clique` | Divisor Clique | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Beta Round #3 | [`statement.md`](../platforms/csacademy/tasks/divisor_clique/statement.md) |
| `dogs` | Diamond Dogs | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #72 | [`statement.md`](../platforms/csacademy/tasks/dogs/statement.md) |
| `dominant-free-sets` | Dominant Free Sets | [`07`](07_computational_geometry.md) | `MEDIUM` | Round #48 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/dominant-free-sets/statement.md) |
| `dominant-point` | Dominant Point | [`07`](07_computational_geometry.md) | `EASY` | Round #13 | [`statement.md`](../platforms/csacademy/tasks/dominant-point/statement.md) |
| `domino-train` | Domino Train | [`01`](01_dynamic_programming.md) | `HARD` | Round #66 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/domino-train/statement.md) |
| `dominoes` | Dominoes | [`01`](01_dynamic_programming.md) | `EASY` | Beta Round #6 | [`statement.md`](../platforms/csacademy/tasks/dominoes/statement.md) |
| `dominoes-rotations` | Dominoes Rotations | [`01`](01_dynamic_programming.md) | `EASY` | Round #19 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/dominoes-rotations/statement.md) |
| `donkey-paradox` | Donkey Paradox | [`02`](02_graph_theory_and_flows.md) | `EASY` | Round #10 | [`statement.md`](../platforms/csacademy/tasks/donkey-paradox/statement.md) |
| `double-palindromes` | Double Palindromes | [`08`](08_string_algorithms.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/double-palindromes/statement.md) |
| `double-replace` | Double Replace | [`08`](08_string_algorithms.md) | `EASY` | Round #42 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/double-replace/statement.md) |
| `douchebag-parking` | Douchebag Parking | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/douchebag-parking/statement.md) |
| `dragons` | Dragons | [`02`](02_graph_theory_and_flows.md) | `EASY` | Round #17 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/dragons/statement.md) |
| `dranei` | Dr. Anei | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | FIICode 2021 Round #1 | [`statement.md`](../platforms/csacademy/tasks/dranei/statement.md) |
| `driveaway` | Driveaway | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/driveaway/statement.md) |
| `editor` | Editor | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #59 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/editor/statement.md) |
| `election-spies` | Election Spies | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #64 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/election-spies/statement.md) |
| `elections` | Elections | [`08`](08_string_algorithms.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/elections/statement.md) |
| `electric-cars` | Electric Cars | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #75 | [`statement.md`](../platforms/csacademy/tasks/electric-cars/statement.md) |
| `eliminate-edges` | Eliminate Edges | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #64 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/eliminate-edges/statement.md) |
| `empty-triangles` | Empty Triangles | [`07`](07_computational_geometry.md) | `HARD` | IOI 2016 Training Round #5 | [`statement.md`](../platforms/csacademy/tasks/empty-triangles/statement.md) |
| `enchained` | Enchained | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/enchained/statement.md) |
| `encipherment` | Encipherment | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #65 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/encipherment/statement.md) |
| `endgame` | Endgame | [`09`](09_game_theory.md) | `MEDIUM` | FIICode 2021 Round #2 | [`statement.md`](../platforms/csacademy/tasks/endgame/statement.md) |
| `enemy` | Line Enemies | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | Round #72 | [`statement.md`](../platforms/csacademy/tasks/enemy/statement.md) |
| `epic-marble-battles` | Epic Marble Battles | [`09`](09_game_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/epic-marble-battles/statement.md) |
| `equal-sums` | Equal Sums | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #35 | [`statement.md`](../platforms/csacademy/tasks/equal-sums/statement.md) |
| `equality` | Equality | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #29 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/equality/statement.md) |
| `equidistant-points` | Equidistant Points | [`07`](07_computational_geometry.md) | `MEDIUM` | Round #32 | [`statement.md`](../platforms/csacademy/tasks/equidistant-points/statement.md) |
| `erase-extremes` | Erase Extremes | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #45 (Div. 1.5) | [`statement.md`](../platforms/csacademy/tasks/erase-extremes/statement.md) |
| `erase-value` | Erase Value | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #40 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/erase-value/statement.md) |
| `escape-the-matrix` | Escape the Matrix | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #75 | [`statement.md`](../platforms/csacademy/tasks/escape-the-matrix/statement.md) |
| `escaping-courses` | Escaping Courses | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/escaping-courses/statement.md) |
| `etianap` | Etianap | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | FIICode 2021 Round #1 | [`statement.md`](../platforms/csacademy/tasks/etianap/statement.md) |
| `even-subset` | Even Subset | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #67 | [`statement.md`](../platforms/csacademy/tasks/even-subset/statement.md) |
| `everything-is-random` | Everything is Random | [`03`](03_trees_and_lca.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/everything-is-random/statement.md) |
| `expected-dice` | Expected Dice | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #43 | [`statement.md`](../platforms/csacademy/tasks/expected-dice/statement.md) |
| `expected-lcp` | Expected Lcp | [`08`](08_string_algorithms.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/expected-lcp/statement.md) |
| `expected-max` | Expected Max | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Round #56 | [`statement.md`](../platforms/csacademy/tasks/expected-max/statement.md) |
| `expected-merge` | Expected Merge | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #47 | [`statement.md`](../platforms/csacademy/tasks/expected-merge/statement.md) |
| `expected-tree-degrees` | Expected Tree Degrees | [`03`](03_trees_and_lca.md) | `HARD` | Round #10 | [`statement.md`](../platforms/csacademy/tasks/expected-tree-degrees/statement.md) |
| `experience` | Experience | [`03`](03_trees_and_lca.md) | `MEDIUM` | EJOI 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/experience/statement.md) |
| `exponential_game` | Exponential Game | [`09`](09_game_theory.md) | `MEDIUM` | Beta Round #6 | [`statement.md`](../platforms/csacademy/tasks/exponential_game/statement.md) |
| `fake-coins` | Fake Coins | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #16 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/fake-coins/statement.md) |
| `falling-balls` | Falling Balls | [`07`](07_computational_geometry.md) | `MEDIUM` | Round #67 | [`statement.md`](../platforms/csacademy/tasks/falling-balls/statement.md) |
| `falling-leaves` | Falling Leaves | [`07`](07_computational_geometry.md) | `EASY` | Round #56 | [`statement.md`](../platforms/csacademy/tasks/falling-leaves/statement.md) |
| `fantastic-4` | Fantastic 4 | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #37 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/fantastic-4/statement.md) |
| `farey_sequence` | Farey Sequence | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | IOI 2016 Training Round #1 | [`statement.md`](../platforms/csacademy/tasks/farey_sequence/statement.md) |
| `fashion` | Fashion | [`10`](10_constructive_and_interactive.md) | `HARD` | RMI 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/fashion/statement.md) |
| `fast-travel` | Fast Travel | [`07`](07_computational_geometry.md) | `EASY` | Round #23 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/fast-travel/statement.md) |
| `fast-typing` | Fast Typing | [`08`](08_string_algorithms.md) | `EASY` | Round #57 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/fast-typing/statement.md) |
| `fibonacci-mod` | Fibonacci Mod | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Round #59 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/fibonacci-mod/statement.md) |
| `fibonacci-representations-big` | Fibonacci Representations Big | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/fibonacci-representations-big/statement.md) |
| `fibonacci-representations-small` | Fibonacci Representations Small | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/fibonacci-representations-small/statement.md) |
| `field-activation` | Field Activation | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Round #13 | [`statement.md`](../platforms/csacademy/tasks/field-activation/statement.md) |
| `fiicode-2022-a1` | Awesome Atek | [`06`](06_greedy_and_two_pointers.md) | `EASY` | FIICode 2022 Round #1 – Powered by Atek Software | [`statement.md`](../platforms/csacademy/tasks/fiicode-2022-a1/statement.md) |
| `fiicode-2022-a2` | Awesome Software | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | FIICode 2022 Round #2 – Powered by Atek Software | [`statement.md`](../platforms/csacademy/tasks/fiicode-2022-a2/statement.md) |
| `fiicode-2022-b1` | Boundless Atek | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | FIICode 2022 Round #1 – Powered by Atek Software | [`statement.md`](../platforms/csacademy/tasks/fiicode-2022-b1/statement.md) |
| `fiicode-2022-b2` | Boundless Software | [`01`](01_dynamic_programming.md) | `EASY` | FIICode 2022 Round #2 – Powered by Atek Software | [`statement.md`](../platforms/csacademy/tasks/fiicode-2022-b2/statement.md) |
| `fiicode-2022-c1` | Crazy Atek | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | FIICode 2022 Round #1 – Powered by Atek Software | [`statement.md`](../platforms/csacademy/tasks/fiicode-2022-c1/statement.md) |
| `fiicode-2022-c2` | Crazy Software | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | FIICode 2022 Round #2 – Powered by Atek Software | [`statement.md`](../platforms/csacademy/tasks/fiicode-2022-c2/statement.md) |
| `fiicode-2022-d1` | Dynamic Atek | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | FIICode 2022 Round #1 – Powered by Atek Software | [`statement.md`](../platforms/csacademy/tasks/fiicode-2022-d1/statement.md) |
| `fiicode-2022-d2` | Dynamic Software | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | FIICode 2022 Round #2 – Powered by Atek Software | [`statement.md`](../platforms/csacademy/tasks/fiicode-2022-d2/statement.md) |
| `fiicode-2022-e1` | Empowering Atek | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | FIICode 2022 Round #1 – Powered by Atek Software | [`statement.md`](../platforms/csacademy/tasks/fiicode-2022-e1/statement.md) |
| `fiicode-2022-e2` | Empowering Software | [`01`](01_dynamic_programming.md) | `MEDIUM` | FIICode 2022 Round #2 – Powered by Atek Software | [`statement.md`](../platforms/csacademy/tasks/fiicode-2022-e2/statement.md) |
| `fill-the-glasses` | Fill the Glasses | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #54 | [`statement.md`](../platforms/csacademy/tasks/fill-the-glasses/statement.md) |
| `final-a` | Final A | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | FIICode 2021 Final Round | [`statement.md`](../platforms/csacademy/tasks/final-a/statement.md) |
| `final-b` | Final B | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | FIICode 2021 Final Round | [`statement.md`](../platforms/csacademy/tasks/final-b/statement.md) |
| `final-d` | Final D | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | FIICode 2021 Final Round | [`statement.md`](../platforms/csacademy/tasks/final-d/statement.md) |
| `final-e` | Final E | [`06`](06_greedy_and_two_pointers.md) | `HARD` | FIICode 2021 Final Round | [`statement.md`](../platforms/csacademy/tasks/final-e/statement.md) |
| `final-index` | Final Index | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #28 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/final-index/statement.md) |
| `finalc` | Final C | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | FIICode 2021 Final Round | [`statement.md`](../platforms/csacademy/tasks/finalc/statement.md) |
| `find-binary-array` | Find Binary Array | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #62 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/find-binary-array/statement.md) |
| `find-edge-list` | Find Edge List | [`02`](02_graph_theory_and_flows.md) | `EASY` | Round #56 | [`statement.md`](../platforms/csacademy/tasks/find-edge-list/statement.md) |
| `find-path-union` | Find Path Union | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #56 | [`statement.md`](../platforms/csacademy/tasks/find-path-union/statement.md) |
| `find-remainder` | Find Remainder | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #63 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/find-remainder/statement.md) |
| `find-the-matrix` | Find the Matrix | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #61 | [`statement.md`](../platforms/csacademy/tasks/find-the-matrix/statement.md) |
| `find-the-tree` | Find the Tree | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #64 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/find-the-tree/statement.md) |
| `firestarter` | Firestarter | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/firestarter/statement.md) |
| `flareon` | Flareon | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Romanian IOI 2017 Selection #6 | [`statement.md`](../platforms/csacademy/tasks/flareon/statement.md) |
| `flawed-olympiad` | Flawed Olympiad | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/flawed-olympiad/statement.md) |
| `flip-game` | Flip Game | [`09`](09_game_theory.md) | `MEDIUM` | (Out of Beta) Round #9 | [`statement.md`](../platforms/csacademy/tasks/flip-game/statement.md) |
| `flip-the-edges` | Flip the Edges | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #60 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/flip-the-edges/statement.md) |
| `flip-the-matrix` | Flip the Matrix | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #46 (Div. 1.5) | [`statement.md`](../platforms/csacademy/tasks/flip-the-matrix/statement.md) |
| `flip-the-prefix` | Flip the Prefix | [`10`](10_constructive_and_interactive.md) | `EASY` | Round #45 (Div. 1.5) | [`statement.md`](../platforms/csacademy/tasks/flip-the-prefix/statement.md) |
| `flipping-matrix` | Flipping Matrix | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #66 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/flipping-matrix/statement.md) |
| `fold` | Fold | [`06`](06_greedy_and_two_pointers.md) | `HARD` | RMI 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/fold/statement.md) |
| `fold-polygon` | Fold Polygon | [`07`](07_computational_geometry.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/fold-polygon/statement.md) |
| `food-pairing` | Food Pairing | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #32 | [`statement.md`](../platforms/csacademy/tasks/food-pairing/statement.md) |
| `football-tournament` | Football Tournament | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #23 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/football-tournament/statement.md) |
| `force_graph` | Force Graph | [`07`](07_computational_geometry.md) | `MEDIUM` | Beta Round #5 | [`statement.md`](../platforms/csacademy/tasks/force_graph/statement.md) |
| `foxes-on-a-wheel` | Foxes on a Wheel | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #57 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/foxes-on-a-wheel/statement.md) |
| `free-palindromes` | Free Palindromes | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #33 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/free-palindromes/statement.md) |
| `frequency-exception` | Frequency Exception | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #22 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/frequency-exception/statement.md) |
| `frequent-numbers` | Frequent Numbers | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #44 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/frequent-numbers/statement.md) |
| `friday-13` | Friday 13 | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #50 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/friday-13/statement.md) |
| `game` | Game | [`09`](09_game_theory.md) | `MEDIUM` | EJOI 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/game/statement.md) |
| `game-of-chance` | Game of Chance | [`09`](09_game_theory.md) | `EASY` | Round #48 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/game-of-chance/statement.md) |
| `game-on-a-circle` | Game on a Circle | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #52 | [`statement.md`](../platforms/csacademy/tasks/game-on-a-circle/statement.md) |
| `gcd` | Greatest Common Divisor | [`05`](05_combinatorics_and_number_theory.md) | `TUTORIAL` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/gcd/statement.md) |
| `gcd-on-a-circle` | Gcd on a Circle | [`07`](07_computational_geometry.md) | `HARD` | Round #18 | [`statement.md`](../platforms/csacademy/tasks/gcd-on-a-circle/statement.md) |
| `gcd-rebuild` | Gcd Rebuild | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #47 | [`statement.md`](../platforms/csacademy/tasks/gcd-rebuild/statement.md) |
| `generating-set` | Generating Set | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/generating-set/statement.md) |
| `gerrymandering` | Gerrymandering | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/gerrymandering/statement.md) |
| `ginas-necklace` | Gina's Necklace | [`07`](07_computational_geometry.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/ginas-necklace/statement.md) |
| `global-warming` | Global Warming | [`01`](01_dynamic_programming.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/global-warming/statement.md) |
| `good-permurations` | Good Permutations | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #74 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/good-permurations/statement.md) |
| `grade-system` | Grade System | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #60 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/grade-system/statement.md) |
| `graph-game` | Graph Game | [`09`](09_game_theory.md) | `MEDIUM` | Round #63 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/graph-game/statement.md) |
| `group-split` | Group Split | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #37 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/group-split/statement.md) |
| `groups` | Groups | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/groups/statement.md) |
| `growing-segment` | Growing Segment | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/growing-segment/statement.md) |
| `growing-trees` | Growing Trees | [`03`](03_trees_and_lca.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/growing-trees/statement.md) |
| `guess-the-number` | Guess the Number | [`10`](10_constructive_and_interactive.md) | `EASY` | Round #16 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/guess-the-number/statement.md) |
| `hallway` | Hallway | [`07`](07_computational_geometry.md) | `MEDIUM` | IOI 2016 Training Round #1 | [`statement.md`](../platforms/csacademy/tasks/hallway/statement.md) |
| `hamming-distances` | Hamming Distances | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #67 | [`statement.md`](../platforms/csacademy/tasks/hamming-distances/statement.md) |
| `hangman2` | Hangman 2 | [`06`](06_greedy_and_two_pointers.md) | `HARD` | RMI 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/hangman2/statement.md) |
| `heap-count` | Heap Count | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Round #47 | [`statement.md`](../platforms/csacademy/tasks/heap-count/statement.md) |
| `heroes` | Heroes | [`07`](07_computational_geometry.md) | `MEDIUM` | RMI 2023 - Day 1 Mirror | [`statement.md`](../platforms/csacademy/tasks/heroes/statement.md) |
| `hill-skateboarding` | Hill Skateboarding | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/hill-skateboarding/statement.md) |
| `histogram-partition` | Histogram Partition | [`01`](01_dynamic_programming.md) | `EASY` | Round #53 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/histogram-partition/statement.md) |
| `homecoming` | Homecoming | [`01`](01_dynamic_programming.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/homecoming/statement.md) |
| `huge-matrix` | Huge Matrix | [`02`](02_graph_theory_and_flows.md) | `EASY` | Round #27 | [`statement.md`](../platforms/csacademy/tasks/huge-matrix/statement.md) |
| `increasing-pair` | Increasing Pair | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #20 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/increasing-pair/statement.md) |
| `increasing_subarrays` | Increasing Subarrays | [`01`](01_dynamic_programming.md) | `HARD` | IOI 2016 Training Round #2 | [`statement.md`](../platforms/csacademy/tasks/increasing_subarrays/statement.md) |
| `independent-rectangles` | Independent Rectangles | [`07`](07_computational_geometry.md) | `EASY` | Round #12 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/independent-rectangles/statement.md) |
| `infinity-array` | Infinity Array | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #75 | [`statement.md`](../platforms/csacademy/tasks/infinity-array/statement.md) |
| `infinity-war` | Infinity War | [`09`](09_game_theory.md) | `MEDIUM` | FIICode 2021 Round #2 | [`statement.md`](../platforms/csacademy/tasks/infinity-war/statement.md) |
| `insert-in-sorted-array` | Insert in Sorted Array | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #31 | [`statement.md`](../platforms/csacademy/tasks/insert-in-sorted-array/statement.md) |
| `integer-coords` | Integer Coords | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #68 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/integer-coords/statement.md) |
| `interactive-partial-sums` | Interactive Partial Sums | [`10`](10_constructive_and_interactive.md) | `EASY` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/interactive-partial-sums/statement.md) |
| `interval-expected-max` | Interval Expected Max | [`04`](04_range_queries_and_data_structures.md) | `HARD` | Round #13 | [`statement.md`](../platforms/csacademy/tasks/interval-expected-max/statement.md) |
| `invsort` | Invsort | [`10`](10_constructive_and_interactive.md) | `HARD` | IOI 2016 Training Round #4 | [`statement.md`](../platforms/csacademy/tasks/invsort/statement.md) |
| `ioi-selection` | IOI Selection | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | [`statement.md`](../platforms/csacademy/tasks/ioi-selection/statement.md) |
| `jeans-and-shirts` | Jeans and Shirts | [`01`](01_dynamic_programming.md) | `EASY` | Round #18 | [`statement.md`](../platforms/csacademy/tasks/jeans-and-shirts/statement.md) |
| `jetpack` | Jetpack | [`07`](07_computational_geometry.md) | `MEDIUM` | (Out of Beta) Round #9 | [`statement.md`](../platforms/csacademy/tasks/jetpack/statement.md) |
| `jokers` | Jokers | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #30 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/jokers/statement.md) |
| `jolteon` | Jolteon | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Romanian IOI 2017 Selection #6 | [`statement.md`](../platforms/csacademy/tasks/jolteon/statement.md) |
| `k-consecutive` | K-consecutive | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | IOI 2016 Training Round #4 | [`statement.md`](../platforms/csacademy/tasks/k-consecutive/statement.md) |
| `k-consequal` | K Consequal | [`08`](08_string_algorithms.md) | `EASY` | Round #15 | [`statement.md`](../platforms/csacademy/tasks/k-consequal/statement.md) |
| `k-inversions` | K Inversions | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/k-inversions/statement.md) |
| `k-subsets-removal` | K-subsets Removal | [`01`](01_dynamic_programming.md) | `EASY` | Round #14 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/k-subsets-removal/statement.md) |
| `k-swap` | K Swap | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Round #39 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/k-swap/statement.md) |
| `karaoke-group` | Karaoke Group | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #31 | [`statement.md`](../platforms/csacademy/tasks/karaoke-group/statement.md) |
| `khans` | Khans | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | IATI Shumen 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/khans/statement.md) |
| `kth-special-number` | Kth Special Number | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #24 | [`statement.md`](../platforms/csacademy/tasks/kth-special-number/statement.md) |
| `lamp` | Lamp | [`07`](07_computational_geometry.md) | `HARD` | Romanian IOI 2017 Selection #4 | [`statement.md`](../platforms/csacademy/tasks/lamp/statement.md) |
| `largest-and-subset` | Largest And Subset | [`01`](01_dynamic_programming.md) | `EASY` | Round #17 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/largest-and-subset/statement.md) |
| `late-edges` | Late Edges | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #54 | [`statement.md`](../platforms/csacademy/tasks/late-edges/statement.md) |
| `least-even-digits` | Least Even Digits | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #35 | [`statement.md`](../platforms/csacademy/tasks/least-even-digits/statement.md) |
| `letter-by-letter` | Letter by Letter | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #16 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/letter-by-letter/statement.md) |
| `letters-deque` | Letters Deque | [`08`](08_string_algorithms.md) | `EASY` | Round #46 (Div. 1.5) | [`statement.md`](../platforms/csacademy/tasks/letters-deque/statement.md) |
| `library_book` | Library Book | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Beta Round #4 | [`statement.md`](../platforms/csacademy/tasks/library_book/statement.md) |
| `license-plates` | License Plates | [`08`](08_string_algorithms.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/license-plates/statement.md) |
| `light-count` | Light Count | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Round #32 | [`statement.md`](../platforms/csacademy/tasks/light-count/statement.md) |
| `lightbulbs` | Lightbulbs | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Beta Round #2 | [`statement.md`](../platforms/csacademy/tasks/lightbulbs/statement.md) |
| `lights-out` | Lights Out | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | IOI 2016 Training Round #5 | [`statement.md`](../platforms/csacademy/tasks/lights-out/statement.md) |
| `limited-moves` | Limited Moves | [`09`](09_game_theory.md) | `MEDIUM` | Round #64 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/limited-moves/statement.md) |
| `limited-swaps` | Limited Swaps | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #22 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/limited-swaps/statement.md) |
| `limited-vocabulary` | Limited Vocabulary | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #26 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/limited-vocabulary/statement.md) |
| `lis_generator` | LIS Generator | [`01`](01_dynamic_programming.md) | `HARD` | Beta Round #6 | [`statement.md`](../platforms/csacademy/tasks/lis_generator/statement.md) |
| `lonely-points` | Lonely Points | [`07`](07_computational_geometry.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/lonely-points/statement.md) |
| `long-pressed-name` | Long Pressed Name | [`08`](08_string_algorithms.md) | `EASY` | Round #11 | [`statement.md`](../platforms/csacademy/tasks/long-pressed-name/statement.md) |
| `long_journey` | Long Journey | [`02`](02_graph_theory_and_flows.md) | `EASY` | Beta Round #5 | [`statement.md`](../platforms/csacademy/tasks/long_journey/statement.md) |
| `losing-nim` | Losing Nim | [`09`](09_game_theory.md) | `MEDIUM` | Round #71 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/losing-nim/statement.md) |
| `lottery` | Lottery | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/lottery/statement.md) |
| `love-story` | Love Story | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/love-story/statement.md) |
| `lucky-days` | Lucky Days | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #52 | [`statement.md`](../platforms/csacademy/tasks/lucky-days/statement.md) |
| `lynx` | Lynx | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | FIICode 2021 Round #2 | [`statement.md`](../platforms/csacademy/tasks/lynx/statement.md) |
| `magic` | Magic | [`08`](08_string_algorithms.md) | `MEDIUM` | EJOI 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/magic/statement.md) |
| `manhattan` | Manhattan | [`07`](07_computational_geometry.md) | `HARD` | Romanian IOI 2017 Selection #1 | [`statement.md`](../platforms/csacademy/tasks/manhattan/statement.md) |
| `manhattan-center` | Manhattan Center | [`07`](07_computational_geometry.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/manhattan-center/statement.md) |
| `manhattan-distances` | Manhattan Distances | [`07`](07_computational_geometry.md) | `MEDIUM` | Round #51 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/manhattan-distances/statement.md) |
| `many-zeros` | Many Zeros | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/many-zeros/statement.md) |
| `marble-weights` | Marble Weights | [`10`](10_constructive_and_interactive.md) | `EASY` | Round #16 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/marble-weights/statement.md) |
| `marbles-graph-game` | Marbles Graph Game | [`09`](09_game_theory.md) | `MEDIUM` | Round #17 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/marbles-graph-game/statement.md) |
| `matching-substrings` | Matching Substrings | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #48 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/matching-substrings/statement.md) |
| `matdiv2` | Mathison and the divisors 2 | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | RMI 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/matdiv2/statement.md) |
| `matrix-balls` | Matrix Balls | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #71 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/matrix-balls/statement.md) |
| `matrix-palindromes` | Matrix Palindromes | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #55 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/matrix-palindromes/statement.md) |
| `matrix_coloring` | Matrix Coloring | [`02`](02_graph_theory_and_flows.md) | `HARD` | Beta Round #2 | [`statement.md`](../platforms/csacademy/tasks/matrix_coloring/statement.md) |
| `matrix_exploration` | Matrix Exploration | [`02`](02_graph_theory_and_flows.md) | `EASY` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/matrix_exploration/statement.md) |
| `matrix_rotations` | Matrix Rotations | [`07`](07_computational_geometry.md) | `EASY` | Beta Round #5 | [`statement.md`](../platforms/csacademy/tasks/matrix_rotations/statement.md) |
| `max-even-subarray` | Max Even Subarray | [`01`](01_dynamic_programming.md) | `EASY` | Round #27 | [`statement.md`](../platforms/csacademy/tasks/max-even-subarray/statement.md) |
| `max-intersection-partition` | Max Intersection Partition | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #11 | [`statement.md`](../platforms/csacademy/tasks/max-intersection-partition/statement.md) |
| `max-or-subarray` | Max Or Subarray | [`01`](01_dynamic_programming.md) | `EASY` | Round #34 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/max-or-subarray/statement.md) |
| `max-score-tree` | Max Score Tree | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Beta Round #8 | [`statement.md`](../platforms/csacademy/tasks/max-score-tree/statement.md) |
| `max-snake` | Max Snake | [`02`](02_graph_theory_and_flows.md) | `HARD` | Round #47 | [`statement.md`](../platforms/csacademy/tasks/max-snake/statement.md) |
| `max-substring` | Max Substring | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #49 | [`statement.md`](../platforms/csacademy/tasks/max-substring/statement.md) |
| `max-wave-array` | Max Wave Array | [`01`](01_dynamic_programming.md) | `EASY` | Round #21 | [`statement.md`](../platforms/csacademy/tasks/max-wave-array/statement.md) |
| `maximize-profit` | Maximize Profit | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #63 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/maximize-profit/statement.md) |
| `maxor` | Maxor | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #53 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/maxor/statement.md) |
| `meet` | Meet | [`03`](03_trees_and_lca.md) | `MEDIUM` | Romanian IOI Selection 2023 - Day 3 | [`statement.md`](../platforms/csacademy/tasks/meet/statement.md) |
| `meow` | Meow | [`03`](03_trees_and_lca.md) | `HARD` | Romanian IOI 2017 Selection #2 | [`statement.md`](../platforms/csacademy/tasks/meow/statement.md) |
| `metal-examination` | Metal Examination | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #28 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/metal-examination/statement.md) |
| `milk-and-bread` | Milk and Bread | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/milk-and-bread/statement.md) |
| `min-coin-payment` | Min Coin Payment | [`01`](01_dynamic_programming.md) | `EASY` | Round #21 | [`statement.md`](../platforms/csacademy/tasks/min-coin-payment/statement.md) |
| `min-distances` | Min Distances | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #70 | [`statement.md`](../platforms/csacademy/tasks/min-distances/statement.md) |
| `min-ends-subsequence` | Min Ends Subsequence | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #25 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/min-ends-subsequence/statement.md) |
| `min-max-sum` | Min Max Sum | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Round #35 | [`statement.md`](../platforms/csacademy/tasks/min-max-sum/statement.md) |
| `min-pairing` | Min Pairing | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #41 | [`statement.md`](../platforms/csacademy/tasks/min-pairing/statement.md) |
| `min-races` | Min Races | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #50 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/min-races/statement.md) |
| `min-swap-counting` | Min Swap Counting | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #14 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/min-swap-counting/statement.md) |
| `min-swaps` | Min Swaps | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #50 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/min-swaps/statement.md) |
| `minimize-ancestor-cost` | Minimize Ancestor Cost | [`03`](03_trees_and_lca.md) | `HARD` | Round #18 | [`statement.md`](../platforms/csacademy/tasks/minimize-ancestor-cost/statement.md) |
| `minimize-max-diff` | Minimize Max Diff | [`09`](09_game_theory.md) | `MEDIUM` | Round #34 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/minimize-max-diff/statement.md) |
| `minimum-by-xor` | Minimum by Xor | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #74 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/minimum-by-xor/statement.md) |
| `minmax_subarray` | MinMax Subarray | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Beta Round #3 | [`statement.md`](../platforms/csacademy/tasks/minmax_subarray/statement.md) |
| `missing-number` | Missing Number | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #29 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/missing-number/statement.md) |
| `modulo-queries` | Modulo Queries | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | Round #75 | [`statement.md`](../platforms/csacademy/tasks/modulo-queries/statement.md) |
| `money-machine` | Money Machine | [`01`](01_dynamic_programming.md) | `EASY` | Round #49 | [`statement.md`](../platforms/csacademy/tasks/money-machine/statement.md) |
| `money-savings` | Money Savings | [`01`](01_dynamic_programming.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/money-savings/statement.md) |
| `monotone-subarray` | Monotone Subarray | [`01`](01_dynamic_programming.md) | `EASY` | Round #53 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/monotone-subarray/statement.md) |
| `monsters` | Monsters | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Balkan OI 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/monsters/statement.md) |
| `mountain-time` | Mountain Time | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/mountain-time/statement.md) |
| `mousetrap` | Mousetrap | [`09`](09_game_theory.md) | `HARD` | CEOI 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/mousetrap/statement.md) |
| `move-the-bishop` | Move the Bishop | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #40 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/move-the-bishop/statement.md) |
| `moving_segments` | Moving Segments | [`07`](07_computational_geometry.md) | `MEDIUM` | Beta Round #3 | [`statement.md`](../platforms/csacademy/tasks/moving_segments/statement.md) |
| `necromancer` | Necromancer | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Romanian IOI 2017 Selection #4 | [`statement.md`](../platforms/csacademy/tasks/necromancer/statement.md) |
| `neighbour-sum-replacement` | Neighbour Sum Replacement | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Beta Round #8 | [`statement.md`](../platforms/csacademy/tasks/neighbour-sum-replacement/statement.md) |
| `nested-segments` | Nested Segments | [`04`](04_range_queries_and_data_structures.md) | `EASY` | Round #56 | [`statement.md`](../platforms/csacademy/tasks/nested-segments/statement.md) |
| `network-rumour` | Network Rumour | [`02`](02_graph_theory_and_flows.md) | `HARD` | IOI 2016 Training Round #3 | [`statement.md`](../platforms/csacademy/tasks/network-rumour/statement.md) |
| `next-dance-move` | Next Dance Move | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #32 | [`statement.md`](../platforms/csacademy/tasks/next-dance-move/statement.md) |
| `no-prime-sum` | No Prime Sum | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #23 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/no-prime-sum/statement.md) |
| `no-repeat` | No Repeat | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #59 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/no-repeat/statement.md) |
| `nogcd` | Nogcd | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Romanian IOI 2017 Selection #1 | [`statement.md`](../platforms/csacademy/tasks/nogcd/statement.md) |
| `nonempty-rectangles` | Nonempty Rectangles | [`07`](07_computational_geometry.md) | `HARD` | IOI 2016 Training Round #4 | [`statement.md`](../platforms/csacademy/tasks/nonempty-rectangles/statement.md) |
| `num-cube-sets` | Num Cube Sets | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #13 | [`statement.md`](../platforms/csacademy/tasks/num-cube-sets/statement.md) |
| `number_elimination` | Number Elimination | [`01`](01_dynamic_programming.md) | `HARD` | Beta Round #1 | [`statement.md`](../platforms/csacademy/tasks/number_elimination/statement.md) |
| `numbers-game` | Numbers Game | [`09`](09_game_theory.md) | `EASY` | Round #30 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/numbers-game/statement.md) |
| `numbers-tournament` | Numbers Tournament | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #33 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/numbers-tournament/statement.md) |
| `odd-divisor-count` | Odd Divisor Count | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #12 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/odd-divisor-count/statement.md) |
| `odd-pair-sums` | Odd Pair Sums | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #26 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/odd-pair-sums/statement.md) |
| `odd-palindromes` | Odd Palindromes | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #29 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/odd-palindromes/statement.md) |
| `odd-sum` | Odd Sum | [`01`](01_dynamic_programming.md) | `EASY` | Round #49 | [`statement.md`](../platforms/csacademy/tasks/odd-sum/statement.md) |
| `odd_divisors` | Odd Divisors | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Beta Round #4 | [`statement.md`](../platforms/csacademy/tasks/odd_divisors/statement.md) |
| `oil-wells` | Oil Wells | [`07`](07_computational_geometry.md) | `MEDIUM` | Romanian IOI Selection 2023 - Day 2 | [`statement.md`](../platforms/csacademy/tasks/oil-wells/statement.md) |
| `one-way-streets` | One Way Streets | [`03`](03_trees_and_lca.md) | `HARD` | CEOI 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/one-way-streets/statement.md) |
| `one_letter` | One Letter | [`08`](08_string_algorithms.md) | `EASY` | Beta Round #7 | [`statement.md`](../platforms/csacademy/tasks/one_letter/statement.md) |
| `online_gcd` | Online Gcd | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Beta Round #2 | [`statement.md`](../platforms/csacademy/tasks/online_gcd/statement.md) |
| `online_xormax` | Online XorMax | [`04`](04_range_queries_and_data_structures.md) | `HARD` | Beta Round #4 | [`statement.md`](../platforms/csacademy/tasks/online_xormax/statement.md) |
| `open-the-bottles` | Open the Bottles | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #53 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/open-the-bottles/statement.md) |
| `or-problem` | Or Problem | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Round #56 | [`statement.md`](../platforms/csacademy/tasks/or-problem/statement.md) |
| `overlapping-matrices` | Overlapping Matrices | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/overlapping-matrices/statement.md) |
| `paint-the-fence` | Paint the Fence | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #61 | [`statement.md`](../platforms/csacademy/tasks/paint-the-fence/statement.md) |
| `pair-swap` | Pair Swap | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #54 | [`statement.md`](../platforms/csacademy/tasks/pair-swap/statement.md) |
| `palindrome-centers` | Palindrome Centers | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #27 | [`statement.md`](../platforms/csacademy/tasks/palindrome-centers/statement.md) |
| `palindrome-free-strings` | Palindrome Free Strings | [`08`](08_string_algorithms.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/palindrome-free-strings/statement.md) |
| `palindromic-concatenation` | Palindromic Concatenation | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #20 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/palindromic-concatenation/statement.md) |
| `palindromic-friendship` | Palindromic Friendship | [`08`](08_string_algorithms.md) | `EASY` | Round #58 | [`statement.md`](../platforms/csacademy/tasks/palindromic-friendship/statement.md) |
| `palindromic-partitions` | Palindromic Partitions | [`08`](08_string_algorithms.md) | `MEDIUM` | CEOI 2017 Day 2 | [`statement.md`](../platforms/csacademy/tasks/palindromic-partitions/statement.md) |
| `palindromic-tree` | Palindromic Tree | [`08`](08_string_algorithms.md) | `MEDIUM` | Junior Challenge 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/palindromic-tree/statement.md) |
| `parallel-lines` | Parallel Lines | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Round #38 | [`statement.md`](../platforms/csacademy/tasks/parallel-lines/statement.md) |
| `parallel-rectangles` | Parallel Rectangles | [`07`](07_computational_geometry.md) | `MEDIUM` | Round #53 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/parallel-rectangles/statement.md) |
| `parentrisis` | Parentrisis | [`08`](08_string_algorithms.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/parentrisis/statement.md) |
| `partial-maximums` | Partial Maximums | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #62 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/partial-maximums/statement.md) |
| `partial_ladder_graph` | Partial Ladder Graph | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Beta Round #7 | [`statement.md`](../platforms/csacademy/tasks/partial_ladder_graph/statement.md) |
| `particles` | Particles | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | EJOI 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/particles/statement.md) |
| `path-inversions` | Path Inversions | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #58 | [`statement.md`](../platforms/csacademy/tasks/path-inversions/statement.md) |
| `path-travel` | Path Travel | [`02`](02_graph_theory_and_flows.md) | `EASY` | Round #17 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/path-travel/statement.md) |
| `path-union` | Path Union | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #38 | [`statement.md`](../platforms/csacademy/tasks/path-union/statement.md) |
| `penguin-dance` | Penguin Dance | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/penguin-dance/statement.md) |
| `perm_matrix` | Perm Matrix | [`02`](02_graph_theory_and_flows.md) | `HARD` | Beta Round #6 | [`statement.md`](../platforms/csacademy/tasks/perm_matrix/statement.md) |
| `permutation-matrix` | Permutation Matrix | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #23 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/permutation-matrix/statement.md) |
| `permutation-shift` | Permutation Shift | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #67 | [`statement.md`](../platforms/csacademy/tasks/permutation-shift/statement.md) |
| `permutation-towers` | Permutation Towers | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Round #27 | [`statement.md`](../platforms/csacademy/tasks/permutation-towers/statement.md) |
| `permutations` | Permutations | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #75 | [`statement.md`](../platforms/csacademy/tasks/permutations/statement.md) |
| `piece-of-cake` | Piece of Cake | [`09`](09_game_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/piece-of-cake/statement.md) |
| `pinball` | Pinball | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | RMI 2023 - Day 1 Mirror | [`statement.md`](../platforms/csacademy/tasks/pinball/statement.md) |
| `pirouettes` | Pirouettes | [`07`](07_computational_geometry.md) | `HARD` | Romanian IOI 2017 Selection #2 | [`statement.md`](../platforms/csacademy/tasks/pirouettes/statement.md) |
| `pitmutation` | Pitmutation | [`09`](09_game_theory.md) | `HARD` | Romanian IOI 2017 Selection #3 | [`statement.md`](../platforms/csacademy/tasks/pitmutation/statement.md) |
| `plants` | Plants | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #55 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/plants/statement.md) |
| `platforms` | Platforms | [`07`](07_computational_geometry.md) | `MEDIUM` | Beta Round #1 | [`statement.md`](../platforms/csacademy/tasks/platforms/statement.md) |
| `play-time` | Play Time | [`09`](09_game_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/play-time/statement.md) |
| `point-in-kgon` | Point in Kgon | [`07`](07_computational_geometry.md) | `MEDIUM` | Round #34 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/point-in-kgon/statement.md) |
| `points-matching` | Points Matching | [`07`](07_computational_geometry.md) | `HARD` | Round #15 | [`statement.md`](../platforms/csacademy/tasks/points-matching/statement.md) |
| `points_in_polygon` | Points in Polygon | [`07`](07_computational_geometry.md) | `HARD` | IOI 2016 Training Round #2 | [`statement.md`](../platforms/csacademy/tasks/points_in_polygon/statement.md) |
| `poisoned-food` | Poisoned Food | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #51 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/poisoned-food/statement.md) |
| `pokemon-evolution` | Pokémon Evolution | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #10 | [`statement.md`](../platforms/csacademy/tasks/pokemon-evolution/statement.md) |
| `pokemon-fight` | Pokemon Fight | [`09`](09_game_theory.md) | `EASY` | Round #13 | [`statement.md`](../platforms/csacademy/tasks/pokemon-fight/statement.md) |
| `pokemon-fights` | Pokemon Fights | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #69 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/pokemon-fights/statement.md) |
| `polygon_partition` | Polygon Partition | [`07`](07_computational_geometry.md) | `HARD` | IOI 2016 Training Round #1 | [`statement.md`](../platforms/csacademy/tasks/polygon_partition/statement.md) |
| `popcorn` | Popcorn | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Romanian IOI 2017 Selection #2 | [`statement.md`](../platforms/csacademy/tasks/popcorn/statement.md) |
| `positive-product-subarrays` | Positive Product Subarrays | [`01`](01_dynamic_programming.md) | `EASY` | Round #12 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/positive-product-subarrays/statement.md) |
| `postivie-xor` | Positive Xor | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #29 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/postivie-xor/statement.md) |
| `prefix-free-subset` | Prefix Free Subset | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #30 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/prefix-free-subset/statement.md) |
| `prefix-matches` | Prefix Matches | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #42 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/prefix-matches/statement.md) |
| `prefix-suffix-counting` | Prefix Suffix Counting | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #12 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/prefix-suffix-counting/statement.md) |
| `previous-divisors` | Previous Divisors | [`10`](10_constructive_and_interactive.md) | `EASY` | Round #16 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/previous-divisors/statement.md) |
| `prime-distance` | Prime Distance | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #21 | [`statement.md`](../platforms/csacademy/tasks/prime-distance/statement.md) |
| `prime-factors` | Prime Factors | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #64 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/prime-factors/statement.md) |
| `printer` | Printer | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/printer/statement.md) |
| `processing-discounts` | Processing Discounts | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #66 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/processing-discounts/statement.md) |
| `product-replace` | Product Replace | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #70 | [`statement.md`](../platforms/csacademy/tasks/product-replace/statement.md) |
| `pyramids` | Pyramids | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/pyramids/statement.md) |
| `quadrants` | Quadrants | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/quadrants/statement.md) |
| `race-cars` | Race Cars | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #75 | [`statement.md`](../platforms/csacademy/tasks/race-cars/statement.md) |
| `race-qualifying` | Race Qualifying | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #51 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/race-qualifying/statement.md) |
| `random_nim_generator` | Random Nim Generator | [`09`](09_game_theory.md) | `HARD` | Round #11 | [`statement.md`](../platforms/csacademy/tasks/random_nim_generator/statement.md) |
| `randomly-permuted-costs` | Randomly Permuted Costs | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #18 | [`statement.md`](../platforms/csacademy/tasks/randomly-permuted-costs/statement.md) |
| `rbubblesort` | RBubbleSort | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/rbubblesort/statement.md) |
| `reconstruct-graph` | Reconstruct Graph | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #37 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/reconstruct-graph/statement.md) |
| `reconstruct-sum` | Reconstruct Sum | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #39 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/reconstruct-sum/statement.md) |
| `rectangle-fit` | Rectangle Fit | [`07`](07_computational_geometry.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/rectangle-fit/statement.md) |
| `rectangle-mst` | MST and Rectangles | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | Round #72 | [`statement.md`](../platforms/csacademy/tasks/rectangle-mst/statement.md) |
| `rectangle-partition` | Rectangle Partition | [`01`](01_dynamic_programming.md) | `EASY` | Round #43 | [`statement.md`](../platforms/csacademy/tasks/rectangle-partition/statement.md) |
| `rectangle-path` | Rectangle Path | [`02`](02_graph_theory_and_flows.md) | `EASY` | Round #25 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/rectangle-path/statement.md) |
| `recursive-arrays` | Recursive Arrays | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Round #37 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/recursive-arrays/statement.md) |
| `recursive-string` | Recursive String | [`08`](08_string_algorithms.md) | `EASY` | Round #31 | [`statement.md`](../platforms/csacademy/tasks/recursive-string/statement.md) |
| `recursive_shuffle` | Recursive Shuffle | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Beta Round #5 | [`statement.md`](../platforms/csacademy/tasks/recursive_shuffle/statement.md) |
| `red-blue-teams` | Red Blue Teams | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #55 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/red-blue-teams/statement.md) |
| `refrigerator-letters` | Refrigerator Letters | [`08`](08_string_algorithms.md) | `EASY` | Round #35 | [`statement.md`](../platforms/csacademy/tasks/refrigerator-letters/statement.md) |
| `remove-update` | Remove Update | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Junior Challenge 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/remove-update/statement.md) |
| `removed-pages` | Removed Pages | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #39 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/removed-pages/statement.md) |
| `replace-a` | Replace A | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #71 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/replace-a/statement.md) |
| `restricted-arrays` | Restricted Arrays | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/restricted-arrays/statement.md) |
| `restricted-permutations` | Restricted Permutations | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #40 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/restricted-permutations/statement.md) |
| `revenge` | Revenge | [`02`](02_graph_theory_and_flows.md) | `HARD` | Romanian IOI 2017 Selection #3 | [`statement.md`](../platforms/csacademy/tasks/revenge/statement.md) |
| `reverse-subarray` | Reverse Subarray | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #69 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/reverse-subarray/statement.md) |
| `reversed-number` | Reversed Number | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #72 | [`statement.md`](../platforms/csacademy/tasks/reversed-number/statement.md) |
| `rhombus` | Rhombus | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/rhombus/statement.md) |
| `ricocheting-balls` | Ricocheting Balls | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #73 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/ricocheting-balls/statement.md) |
| `right-down-path` | Right Down Path | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #70 | [`statement.md`](../platforms/csacademy/tasks/right-down-path/statement.md) |
| `right-triangles` | Right Triangles | [`07`](07_computational_geometry.md) | `MEDIUM` | Round #68 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/right-triangles/statement.md) |
| `risk-rolls` | Risk Rolls | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #66 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/risk-rolls/statement.md) |
| `road-trips` | Road Trips | [`03`](03_trees_and_lca.md) | `HARD` | Round #19 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/road-trips/statement.md) |
| `robot-in-a-labyrinth` | Robot in a Labyrinth | [`01`](01_dynamic_programming.md) | `HARD` | Round #52 | [`statement.md`](../platforms/csacademy/tasks/robot-in-a-labyrinth/statement.md) |
| `robots` | Robots | [`08`](08_string_algorithms.md) | `MEDIUM` | IATI Shumen 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/robots/statement.md) |
| `rooks` | Rooks | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/rooks/statement.md) |
| `rooms` | Rooms | [`07`](07_computational_geometry.md) | `HARD` | Romanian IOI 2017 Selection #1 | [`statement.md`](../platforms/csacademy/tasks/rooms/statement.md) |
| `root-change` | Root Change | [`03`](03_trees_and_lca.md) | `MEDIUM` | Round #29 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/root-change/statement.md) |
| `root-lca-queries` | Root LCA Queries | [`03`](03_trees_and_lca.md) | `MEDIUM` | Round #63 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/root-lca-queries/statement.md) |
| `russian-dolls` | Russian Dolls | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #71 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/russian-dolls/statement.md) |
| `russian-dolls-ways` | Russian Dolls Ways | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #73 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/russian-dolls-ways/statement.md) |
| `safe-spots` | Safe Spots | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #36 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/safe-spots/statement.md) |
| `scrambled-eggs` | Scrambled Eggs | [`01`](01_dynamic_programming.md) | `MEDIUM` | FIICode 2021 Round #2 | [`statement.md`](../platforms/csacademy/tasks/scrambled-eggs/statement.md) |
| `second-minimum` | Second Minimum | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #31 | [`statement.md`](../platforms/csacademy/tasks/second-minimum/statement.md) |
| `server-attack` | Server Attack | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #34 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/server-attack/statement.md) |
| `server-hacking` | Server Hacking | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Round #15 | [`statement.md`](../platforms/csacademy/tasks/server-hacking/statement.md) |
| `set-subtraction` | Set Subtraction | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #46 (Div. 1.5) | [`statement.md`](../platforms/csacademy/tasks/set-subtraction/statement.md) |
| `seven-segment-display` | Seven-segment Display | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | Round #39 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/seven-segment-display/statement.md) |
| `shampoo-exchange` | Shampoo Exchange | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | [`statement.md`](../platforms/csacademy/tasks/shampoo-exchange/statement.md) |
| `sheets` | Sheets | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | Balkan OI 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/sheets/statement.md) |
| `shell-game` | Shell Game | [`09`](09_game_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/shell-game/statement.md) |
| `shifted-diagonal-sum` | Shifted Diagonal Sum | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #10 | [`statement.md`](../platforms/csacademy/tasks/shifted-diagonal-sum/statement.md) |
| `shoe-pairs` | Shoe Pairs | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #38 | [`statement.md`](../platforms/csacademy/tasks/shoe-pairs/statement.md) |
| `shopping-time` | Shopping Time | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/shopping-time/statement.md) |
| `similar_words` | Similar Words | [`08`](08_string_algorithms.md) | `EASY` | Beta Round #6 | [`statement.md`](../platforms/csacademy/tasks/similar_words/statement.md) |
| `simple-paths` | Simple Paths | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #62 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/simple-paths/statement.md) |
| `single-digit-numbers` | Single Digit Numbers | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #11 | [`statement.md`](../platforms/csacademy/tasks/single-digit-numbers/statement.md) |
| `six` | Six | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | EJOI 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/six/statement.md) |
| `sliding-product-sum` | Sliding Product Sum | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #68 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/sliding-product-sum/statement.md) |
| `smallest-array-permutation` | Smallest Array Permutation | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #19 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/smallest-array-permutation/statement.md) |
| `smallest-missing-numbers` | Smallest Missing Numbers | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/smallest-missing-numbers/statement.md) |
| `smallest-subsets` | Smallest Subsets | [`01`](01_dynamic_programming.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/smallest-subsets/statement.md) |
| `sniper` | Sniper | [`07`](07_computational_geometry.md) | `MEDIUM` | Romanian IOI Selection 2023 - Day 3 | [`statement.md`](../platforms/csacademy/tasks/sniper/statement.md) |
| `soccer-field` | Soccer Field | [`06`](06_greedy_and_two_pointers.md) | `EASY` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/soccer-field/statement.md) |
| `socks-pairs` | Socks Pairs | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #36 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/socks-pairs/statement.md) |
| `soldiers` | Soldiers | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Beta Round #4 | [`statement.md`](../platforms/csacademy/tasks/soldiers/statement.md) |
| `sortall` | Sort All | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | [`statement.md`](../platforms/csacademy/tasks/sortall/statement.md) |
| `sorting-steps` | Sorting Steps | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #42 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/sorting-steps/statement.md) |
| `sorting_partition` | Sorting Partition | [`01`](01_dynamic_programming.md) | `EASY` | Beta Round #1 | [`statement.md`](../platforms/csacademy/tasks/sorting_partition/statement.md) |
| `spanning-trees` | Spanning Trees | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #54 | [`statement.md`](../platforms/csacademy/tasks/spanning-trees/statement.md) |
| `special-mvc` | Special MVC | [`02`](02_graph_theory_and_flows.md) | `HARD` | Round #21 | [`statement.md`](../platforms/csacademy/tasks/special-mvc/statement.md) |
| `split-the-sticks` | Split the Sticks | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/split-the-sticks/statement.md) |
| `spring-love` | Spring Love | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/spring-love/statement.md) |
| `sprint-cleaning` | Spring Cleaning | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #72 | [`statement.md`](../platforms/csacademy/tasks/sprint-cleaning/statement.md) |
| `sqrt-frac-easy` | Square Root Frac (Easy) | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #32 | [`statement.md`](../platforms/csacademy/tasks/sqrt-frac-easy/statement.md) |
| `sqrt-frac-hard` | Square Root Frac (Hard) | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #32 | [`statement.md`](../platforms/csacademy/tasks/sqrt-frac-hard/statement.md) |
| `square-cover` | Square Cover | [`02`](02_graph_theory_and_flows.md) | `EASY` | Round #44 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/square-cover/statement.md) |
| `squared-ends` | Squared Ends | [`07`](07_computational_geometry.md) | `MEDIUM` | Round #70 | [`statement.md`](../platforms/csacademy/tasks/squared-ends/statement.md) |
| `squarish-rectangle` | Squarish Rectangle | [`07`](07_computational_geometry.md) | `EASY` | Round #18 | [`statement.md`](../platforms/csacademy/tasks/squarish-rectangle/statement.md) |
| `stargazing` | Stargazing | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/stargazing/statement.md) |
| `stepping-number` | Stepping Number | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #20 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/stepping-number/statement.md) |
| `strange-distance` | Strange Distance | [`07`](07_computational_geometry.md) | `MEDIUM` | Beta Round #8 | [`statement.md`](../platforms/csacademy/tasks/strange-distance/statement.md) |
| `strange-matrix` | Strange Matrix | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/strange-matrix/statement.md) |
| `strange-substring` | Strange Substring | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #73 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/strange-substring/statement.md) |
| `strange-transformation` | Strange Transformation | [`04`](04_range_queries_and_data_structures.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/strange-transformation/statement.md) |
| `strictly-increasing-array` | Strictly Increasing Array | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #61 | [`statement.md`](../platforms/csacademy/tasks/strictly-increasing-array/statement.md) |
| `string-concat` | String Concat | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #68 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/string-concat/statement.md) |
| `strings` | Strings | [`08`](08_string_algorithms.md) | `HARD` | Balkan OI 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/strings/statement.md) |
| `strips` | Strips | [`08`](08_string_algorithms.md) | `MEDIUM` | Romanian IOI Selection 2023 - Day 1 | [`statement.md`](../platforms/csacademy/tasks/strips/statement.md) |
| `subarray-medians` | Subarray Medians | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #10 | [`statement.md`](../platforms/csacademy/tasks/subarray-medians/statement.md) |
| `subarray-partition` | Subarray Partition | [`01`](01_dynamic_programming.md) | `EASY` | Round #32 | [`statement.md`](../platforms/csacademy/tasks/subarray-partition/statement.md) |
| `subarray_removal` | Subarray Removal | [`01`](01_dynamic_programming.md) | `EASY` | Beta Round #7 | [`statement.md`](../platforms/csacademy/tasks/subarray_removal/statement.md) |
| `subarrays-xor-sum` | Subarrays Xor Sum | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #14 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/subarrays-xor-sum/statement.md) |
| `subinterval-division` | Subinterval Division | [`07`](07_computational_geometry.md) | `MEDIUM` | Round #33 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/subinterval-division/statement.md) |
| `subsequence-queries` | Subsequence Queries | [`08`](08_string_algorithms.md) | `HARD` | Round #24 | [`statement.md`](../platforms/csacademy/tasks/subsequence-queries/statement.md) |
| `subset-trees` | Subset Trees | [`03`](03_trees_and_lca.md) | `HARD` | Round #41 | [`statement.md`](../platforms/csacademy/tasks/subset-trees/statement.md) |
| `substring-restrictions` | Substring Restrictions | [`08`](08_string_algorithms.md) | `HARD` | Round #15 | [`statement.md`](../platforms/csacademy/tasks/substring-restrictions/statement.md) |
| `subway-ride` | Subway Ride | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #74 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/subway-ride/statement.md) |
| `suffix-flip` | Suffix Flip | [`09`](09_game_theory.md) | `MEDIUM` | Round #67 | [`statement.md`](../platforms/csacademy/tasks/suffix-flip/statement.md) |
| `sugarel-and-bars` | Sugarel and Bars | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/sugarel-and-bars/statement.md) |
| `sugarel-and-substrings` | Sugarel and Substrings | [`08`](08_string_algorithms.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/sugarel-and-substrings/statement.md) |
| `sum-of-powers` | Sum of Powers | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Round #32 | [`statement.md`](../platforms/csacademy/tasks/sum-of-powers/statement.md) |
| `sum-of-squares` | Sum of Squares | [`07`](07_computational_geometry.md) | `HARD` | (Out of Beta) Round #9 | [`statement.md`](../platforms/csacademy/tasks/sum-of-squares/statement.md) |
| `sum-triplets` | Sum Triplets | [`05`](05_combinatorics_and_number_theory.md) | `EASY` | Round #52 | [`statement.md`](../platforms/csacademy/tasks/sum-triplets/statement.md) |
| `superstition` | Superstition | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | IATI Shumen 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/superstition/statement.md) |
| `sure-bet` | Sure Bet | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CEOI 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/sure-bet/statement.md) |
| `surround-the-enemy` | Surround the Enemy | [`01`](01_dynamic_programming.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/surround-the-enemy/statement.md) |
| `surrounded-rectangle` | Surrounded Rectangle | [`07`](07_computational_geometry.md) | `EASY` | Round #14 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/surrounded-rectangle/statement.md) |
| `suspect-interval` | Suspect Interval | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #25 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/suspect-interval/statement.md) |
| `swap_pairing` | Swap Pairing | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Beta Round #4 | [`statement.md`](../platforms/csacademy/tasks/swap_pairing/statement.md) |
| `swap_permutation` | Swap Permutation | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Beta Round #1 | [`statement.md`](../platforms/csacademy/tasks/swap_permutation/statement.md) |
| `switch-the-lights` | Switch the Lights | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #40 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/switch-the-lights/statement.md) |
| `t-shapes` | T-shapes | [`02`](02_graph_theory_and_flows.md) | `EASY` | Round #15 | [`statement.md`](../platforms/csacademy/tasks/t-shapes/statement.md) |
| `tale` | Tale | [`07`](07_computational_geometry.md) | `MEDIUM` | Balkan OI 2017 Day 1 | [`statement.md`](../platforms/csacademy/tasks/tale/statement.md) |
| `telegraph` | Telegraph | [`02`](02_graph_theory_and_flows.md) | `HARD` | IOI 2016 Training Round #3 | [`statement.md`](../platforms/csacademy/tasks/telegraph/statement.md) |
| `template-addition` | Template Addition | [`05`](05_combinatorics_and_number_theory.md) | `TUTORIAL` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/template-addition/statement.md) |
| `tennis-tournament` | Tennis Tournament | [`09`](09_game_theory.md) | `EASY` | Round #41 | [`statement.md`](../platforms/csacademy/tasks/tennis-tournament/statement.md) |
| `the-sprawl` | The Sprawl | [`07`](07_computational_geometry.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/the-sprawl/statement.md) |
| `the-wall` | The Wall | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #69 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/the-wall/statement.md) |
| `three-equal` | Three Equal | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #73 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/three-equal/statement.md) |
| `three-ones` | Three Ones | [`08`](08_string_algorithms.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/three-ones/statement.md) |
| `time-to-shine` | Time to Shine | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/time-to-shine/statement.md) |
| `to-front-to-back` | To Front - To Back | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #17 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/to-front-to-back/statement.md) |
| `token-grid` | Tokens on a grid | [`01`](01_dynamic_programming.md) | `HARD` | Round #31 | [`statement.md`](../platforms/csacademy/tasks/token-grid/statement.md) |
| `tournament` | Tournament | [`07`](07_computational_geometry.md) | `HARD` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | [`statement.md`](../platforms/csacademy/tasks/tournament/statement.md) |
| `tournament-cycle` | Tournament Cycle | [`02`](02_graph_theory_and_flows.md) | `HARD` | Round #21 | [`statement.md`](../platforms/csacademy/tasks/tournament-cycle/statement.md) |
| `tournament-swaps` | Tournament Swaps | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #58 | [`statement.md`](../platforms/csacademy/tasks/tournament-swaps/statement.md) |
| `towns` | Towns | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | [`statement.md`](../platforms/csacademy/tasks/towns/statement.md) |
| `toys-big` | Toys Big | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/toys-big/statement.md) |
| `toys-small` | Toys Small | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/toys-small/statement.md) |
| `trailing-zeros` | Trailing Zeros | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #64 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/trailing-zeros/statement.md) |
| `transpermutation` | Transpermutation | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/transpermutation/statement.md) |
| `travel-distance` | Travel Distance | [`07`](07_computational_geometry.md) | `EASY` | Round #50 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/travel-distance/statement.md) |
| `traveling-time` | Traveling Time | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/traveling-time/statement.md) |
| `tree-antichain-easy` | Tree Antichain (Easy) | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #38 | [`statement.md`](../platforms/csacademy/tasks/tree-antichain-easy/statement.md) |
| `tree-antichain-hard` | Tree Antichain (Hard) | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Round #38 | [`statement.md`](../platforms/csacademy/tasks/tree-antichain-hard/statement.md) |
| `tree-coloring` | Tree Coloring | [`03`](03_trees_and_lca.md) | `MEDIUM` | Round #51 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/tree-coloring/statement.md) |
| `tree-construct` | Tree Reconstruction | [`10`](10_constructive_and_interactive.md) | `HARD` | Round #43 | [`statement.md`](../platforms/csacademy/tasks/tree-construct/statement.md) |
| `tree-from-leaves` | Tree From Leaves | [`10`](10_constructive_and_interactive.md) | `HARD` | Round #16 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/tree-from-leaves/statement.md) |
| `tree-node-distances` | Tree Node Distances | [`10`](10_constructive_and_interactive.md) | `MEDIUM` | Round #16 (Interactive only) | [`statement.md`](../platforms/csacademy/tasks/tree-node-distances/statement.md) |
| `tree-nodes-destruction` | Tree Nodes Destruction | [`03`](03_trees_and_lca.md) | `HARD` | IOI 2016 Training Round #3 | [`statement.md`](../platforms/csacademy/tasks/tree-nodes-destruction/statement.md) |
| `tree-nodes-sets` | Tree Nodes Sets | [`03`](03_trees_and_lca.md) | `MEDIUM` | Round #36 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/tree-nodes-sets/statement.md) |
| `tree-square` | Tree Square | [`02`](02_graph_theory_and_flows.md) | `HARD` | IOI 2016 Training Round #5 | [`statement.md`](../platforms/csacademy/tasks/tree-square/statement.md) |
| `tree_game` | Tree Game | [`09`](09_game_theory.md) | `HARD` | Beta Round #2 | [`statement.md`](../platforms/csacademy/tasks/tree_game/statement.md) |
| `tree_swapping` | Tree Swapping | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Beta Round #3 | [`statement.md`](../platforms/csacademy/tasks/tree_swapping/statement.md) |
| `trees-partition` | Trees Partition | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #62 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/trees-partition/statement.md) |
| `triangle-count` | Triangle Count | [`07`](07_computational_geometry.md) | `EASY` | Round #22 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/triangle-count/statement.md) |
| `triangular-matrix` | Triangular Matrix | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #59 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/triangular-matrix/statement.md) |
| `triangular-updates` | Triangular Updates | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #68 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/triangular-updates/statement.md) |
| `triplet-min-sum` | Triplet Min Sum | [`05`](05_combinatorics_and_number_theory.md) | `MEDIUM` | Round #30 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/triplet-min-sum/statement.md) |
| `triplet-queries` | Triplet Queries | [`10`](10_constructive_and_interactive.md) | `HARD` | Round #27 | [`statement.md`](../platforms/csacademy/tasks/triplet-queries/statement.md) |
| `two-coins` | Two Coins | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #62 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/two-coins/statement.md) |
| `two-elevators` | Two Elevators | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #60 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/two-elevators/statement.md) |
| `two-guards` | Two Guards | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #20 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/two-guards/statement.md) |
| `two-rows` | Two Rows | [`09`](09_game_theory.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/two-rows/statement.md) |
| `two-squares` | Two Squares | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #74 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/two-squares/statement.md) |
| `two_progressions` | Two Progressions | [`10`](10_constructive_and_interactive.md) | `HARD` | Beta Round #1 | [`statement.md`](../platforms/csacademy/tasks/two_progressions/statement.md) |
| `ultimateorbs` | Ultimate Orbs | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #46 (Div. 1.5) | [`statement.md`](../platforms/csacademy/tasks/ultimateorbs/statement.md) |
| `unfair_game` | Unfair Game | [`09`](09_game_theory.md) | `EASY` | Beta Round #1 | [`statement.md`](../platforms/csacademy/tasks/unfair_game/statement.md) |
| `unicorns` | Unicorns | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #74 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/unicorns/statement.md) |
| `uniform-trees` | Uniform Trees | [`03`](03_trees_and_lca.md) | `HARD` | Round #31 | [`statement.md`](../platforms/csacademy/tasks/uniform-trees/statement.md) |
| `unstable-merge-sort` | Unstable Merge Sort | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Round #61 | [`statement.md`](../platforms/csacademy/tasks/unstable-merge-sort/statement.md) |
| `vaporeon` | Vaporeon | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Romanian IOI 2017 Selection #6 | [`statement.md`](../platforms/csacademy/tasks/vaporeon/statement.md) |
| `vector-size` | Vector Size | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #24 | [`statement.md`](../platforms/csacademy/tasks/vector-size/statement.md) |
| `virus-on-a-tree` | Virus on a Tree | [`03`](03_trees_and_lca.md) | `MEDIUM` | Round #52 | [`statement.md`](../platforms/csacademy/tasks/virus-on-a-tree/statement.md) |
| `voting` | Voting | [`06`](06_greedy_and_two_pointers.md) | `HARD` | Round #54 | [`statement.md`](../platforms/csacademy/tasks/voting/statement.md) |
| `water` | Water | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Romanian IOI Selection 2023 - Day 1 | [`statement.md`](../platforms/csacademy/tasks/water/statement.md) |
| `water-bottles` | Water Bottles | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #28 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/water-bottles/statement.md) |
| `water-supply` | Water Supply | [`01`](01_dynamic_programming.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/water-supply/statement.md) |
| `water-tower` | Water Tower | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/water-tower/statement.md) |
| `water-volume` | Water Volume | [`06`](06_greedy_and_two_pointers.md) | `EASY` | Round #48 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/water-volume/statement.md) |
| `win-percentages` | Win Percentages | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #59 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/win-percentages/statement.md) |
| `word_ordering` | Word Ordering | [`08`](08_string_algorithms.md) | `EASY` | Beta Round #1 | [`statement.md`](../platforms/csacademy/tasks/word_ordering/statement.md) |
| `word_permutation` | Word Permutation | [`08`](08_string_algorithms.md) | `EASY` | Beta Round #2 | [`statement.md`](../platforms/csacademy/tasks/word_permutation/statement.md) |
| `work-time` | Work Time | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/work-time/statement.md) |
| `wrong-brackets` | Wrong Brackets | [`08`](08_string_algorithms.md) | `MEDIUM` | Round #51 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/wrong-brackets/statement.md) |
| `x-distance` | X Distance | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #27 | [`statement.md`](../platforms/csacademy/tasks/x-distance/statement.md) |
| `xor-closure` | Xor Closure | [`05`](05_combinatorics_and_number_theory.md) | `HARD` | Round #10 | [`statement.md`](../platforms/csacademy/tasks/xor-closure/statement.md) |
| `xor-match` | Xor Match | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #63 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/xor-match/statement.md) |
| `xor-submatrix` | Xor Submatrix | [`01`](01_dynamic_programming.md) | `MEDIUM` | Round #42 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/xor-submatrix/statement.md) |
| `xor-the-graph` | Xor the Graph | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #61 | [`statement.md`](../platforms/csacademy/tasks/xor-the-graph/statement.md) |
| `xor-transform` | Xor Transform | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | Round #78 (based on Romanian Olympiad IOI selection camp) | [`statement.md`](../platforms/csacademy/tasks/xor-transform/statement.md) |
| `xor_cycle` | Xor Cycle | [`02`](02_graph_theory_and_flows.md) | `HARD` | Beta Round #6 | [`statement.md`](../platforms/csacademy/tasks/xor_cycle/statement.md) |
| `yurys-tree` | Yury's Tree | [`03`](03_trees_and_lca.md) | `MEDIUM` | Round #10 | [`statement.md`](../platforms/csacademy/tasks/yurys-tree/statement.md) |
| `zalmolxis` | Zalmolxis | [`06`](06_greedy_and_two_pointers.md) | `MEDIUM` | CS Academy Archive | [`statement.md`](../platforms/csacademy/tasks/zalmolxis/statement.md) |
| `zone-capture` | Zone Capture | [`02`](02_graph_theory_and_flows.md) | `MEDIUM` | Round #25 (Div. 2 only) | [`statement.md`](../platforms/csacademy/tasks/zone-capture/statement.md) |
