# Archetype 05: Combinatorics & Number Theory

> **Grounding Metadata & NotebookLM Oracle**  
> - **Archetype ID:** `05_combinatorics_and_number_theory`  
> - **Target Notebook ID:** `95a79d26-2f87-42cd-8cb9-8361a1e56059` (*Personal Notebook: ⚙️ Aaradhya — Engineer's Personal Notebook*)  
> - **Total Archived Tasks:** `92`  
> - **Sub-Archetypes:** Inclusion-Exclusion, Modulo Arithmetic, Prime Sieve, GCD/LCM, Binomial Coefficients, NTT/FFT Polynomial Multiplication, Burnside's Lemma, Linear Basis (XOR Basis)  
> - **Compiler Standards:** `g++ 15.2.0` (`-std=c++23 -O2 -pthread`) on Ubuntu 25.04 x64  

---

## 1. Executive Overview & Core Principles

Number Theory and Combinatorics address algebraic structures, integer divisibility, counting configurations, and polynomial transformations under prime or composite moduli.

Key foundations include **Fermat's Little Theorem**, **Bézout's Identity**, **The Fundamental Theorem of Arithmetic**, and the **Inclusion-Exclusion Principle**, enabling exact counting without constructing exponential state spaces.

---

## 2. Key Mathematical Patterns & Algorithms

### 2.1 Modular Arithmetic & Factorials
For prime modulo $P = 10^9 + 7$ or $998244353$:
- Modular inverse via Fermat's Little Theorem:
  $$a^{-1} \equiv a^{P - 2} \pmod P$$
- Binomial coefficients in $O(1)$ after $O(N)$ factorial precomputation:
  $$\binom{n}{k} = \frac{n!}{k! (n - k)!} \equiv \text{fact}[n] \cdot \text{invFact}[k] \cdot \text{invFact}[n - k] \pmod P$$

### 2.2 Linear Sieve of Eratosthenes (Euler's Sieve)
Computes primes and multiplicative functions (Euler totient $\phi$, Möbius $\mu$) in strictly $O(N)$ time:
```cpp
vector<int> primes;
vector<int> min_prime(N + 1);
for (int i = 2; i <= N; ++i) {
    if (!min_prime[i]) {
        min_prime[i] = i;
        primes.push_back(i);
    }
    for (int p : primes) {
        if (p > min_prime[i] || i * p > N) break;
        min_prime[i * p] = p;
    }
}
```

### 2.3 Inclusion-Exclusion Principle
For finite sets $A_1, A_2, \dots, A_n$:
$$\left| \bigcup_{i=1}^n A_i \right| = \sum_{k=1}^n (-1)^{k-1} \sum_{1 \le i_1 < \dots < i_k \le n} \left| A_{i_1} \cap \dots \cap A_{i_k} \right|$$

### 2.4 Linear Basis over $\mathbb{F}_2$ (XOR Basis)
Maintains independent basis vectors $B_0, B_1, \dots, B_{D-1}$ under bitwise XOR:
- Any element $X$ is reduced against basis vectors.
- If reduced $X > 0$, it is inserted as a new independent basis vector.
- Total spanning space size: $2^{\text{size}(B)}$. Max XOR sum found greedily in $O(D)$.

### 2.5 Burnside's Lemma
Number of distinct orbits under group action $G$ on set $X$:
$$|X / G| = \frac{1}{|G|} \sum_{g \in G} |X^g|$$
where $|X^g|$ is the number of configurations invariant under group element $g$.

---

## 3. Sub-Archetypes Taxonomic Breakdown

```
Combinatorics & Number Theory
 ├── Elementary Number Theory
 │    ├── Greatest Common Divisor (Euclidean algorithm, Extended GCD, Bezout)
 │    ├── Sieve of Eratosthenes (Prime factorization, Divisor generation)
 │    └── Euler's Totient Function (Euler's theorem a^phi(m) == 1 mod m)
 ├── Combinatorics & Counting
 │    ├── Binomial Coefficients & Pascal Triangle
 │    ├── Inclusion-Exclusion (Derangements, Bounded subset sums)
 │    ├── Catalan Numbers (Balanced bracket sequences, Triangulations)
 │    └── Burnside's Lemma / Polya Enumeration (Rotational / Reflection symmetries)
 ├── Linear Algebra & Bitwise Mathematics
 │    ├── Linear Basis over GF(2) (Maximum XOR subset, Spanning subspace)
 │    └── Matrix Exponentiation (O(K^3 log N) transition propagation)
 └── Transform Methods
      ├── Fast Fourier Transform (FFT - Complex roots of unity)
      └── Number Theoretic Transform (NTT - Modulo 998244353 with generator g = 3)
```

---

## 4. Canonical Problem Deep-Dives from Archive

### 4.1 Xor Closure (`xor-closure`)
- **Contest:** Round #39 | **Difficulty:** HARD | **Platform Slug:** [`xor-closure`](../platforms/csacademy/tasks/xor-closure/statement.md)
- **Problem Statement:** Given an array $A$ of $N$ integers, compute the size of its closure under the XOR operation.
- **Mathematical Invariant:**
  The XOR closure is precisely the vector subspace spanned by the elements over the field $\mathbb{F}_2$.
  If the linear basis of $A$ has dimension $d$, the total number of distinct achievable XOR values is $2^d$.
- **Optimal Complexity:** $O(N \cdot B)$ time where $B = 60$; $O(B)$ space.
- **Production C++23 Implementation:**
```cpp
#include <iostream>
#include <vector>

using namespace std;

struct XorBasis {
    long long basis[62] = {0};
    int dim = 0;

    void insert(long long mask) {
        for (int b = 61; b >= 0; --b) {
            if (!((mask >> b) & 1)) continue;
            if (!basis[b]) {
                basis[b] = mask;
                dim++;
                return;
            }
            mask ^= basis[b];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    XorBasis xb;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        xb.insert(val);
    }

    // Total elements in span is 2^dim
    long long total_closure = 1LL << xb.dim;
    cout << total_closure << "\n";
    return 0;
}
```

### 4.2 Greatest Common Divisor (`gcd`)
- **Contest:** Tutorial | **Difficulty:** TUTORIAL | **Platform Slug:** [`gcd`](../platforms/csacademy/tasks/gcd/statement.md)
- **Problem Statement:** Compute the greatest common divisor of two integers $A$ and $B$.
- **Mathematical Invariant:**
  $$\gcd(A, B) = \gcd(B, A \pmod B)$$
  Termination occurs in $O(\log(\min(A, B)))$ by Lamé's Theorem.
- **Optimal Complexity:** $O(\log(\min(A, B)))$ time, $O(1)$ space.

---

## 5. Optimal Complexity Tips & Competitive Pitfalls

1. **64-bit Multiplication Overflow:** When multiplying numbers modulo $P$, product $A \cdot B$ can reach $10^{18}$, exceeding standard 32-bit `int`. Always cast operands to `long long` or use `__int128_t` for larger moduli.
2. **Negative Modulo Correction:** In C++, `-7 % 5 == -2`. Always normalize subtraction results:
   ```cpp
   int val = (a - b) % MOD;
   if (val < 0) val += MOD;
   ```
3. **Linear Sieve Boundary Limits:** When precomputing factorials and inverses up to $N = 10^6$, initialize arrays up to $N + 5$ to prevent off-by-one heap buffer overruns.

---

## 6. Comprehensive Archive Task Registry (92 Tasks)

| Slug | Title | Difficulty | Contest | Solved Ratio | Archive Link |
| :--- | :--- | :---: | :--- | :---: | :---: |
| `0-sum-array` | **0-Sum Array** | `EASY` | Round #25 (Div. 2 only) | 93% | [`0-sum-array`](../platforms/csacademy/tasks/0-sum-array/statement.md) |
| `3-divisible-pairs` | **3-divisible Pairs** | `EASY` | (Out of Beta) Round #9 | 66% | [`3-divisible-pairs`](../platforms/csacademy/tasks/3-divisible-pairs/statement.md) |
| `8-divisible` | **8 Divisible** | `EASY` | Round #48 (Div. 2 only) | 65% | [`8-divisible`](../platforms/csacademy/tasks/8-divisible/statement.md) |
| `add-and-divide` | **Add and Divide** | `EASY` | Round #28 (Div. 2 only) | 96% | [`add-and-divide`](../platforms/csacademy/tasks/add-and-divide/statement.md) |
| `fiicode-2022-a2` | **Awesome Software** | `EASY` | FIICode 2022 Round #2 – Powered by Atek Software | 86% | [`fiicode-2022-a2`](../platforms/csacademy/tasks/fiicode-2022-a2/statement.md) |
| `balanced-number` | **Balanced Number** | `EASY` | Round #42 (Div. 2 only) | 93% | [`balanced-number`](../platforms/csacademy/tasks/balanced-number/statement.md) |
| `boring-number` | **Boring Number** | `EASY` | Round #37 (Div. 2 only) | 96% | [`boring-number`](../platforms/csacademy/tasks/boring-number/statement.md) |
| `constant-sum` | **Constant Sum** | `EASY` | Round #30 (Div. 2 only) | 92% | [`constant-sum`](../platforms/csacademy/tasks/constant-sum/statement.md) |
| `counting-quacks` | **Counting Quacks** | `EASY` | Round #66 (Div. 2 only) | 80% | [`counting-quacks`](../platforms/csacademy/tasks/counting-quacks/statement.md) |
| `div-3` | **Div 3** | `EASY` | Round #33 (Div. 2 only) | 86% | [`div-3`](../platforms/csacademy/tasks/div-3/statement.md) |
| `divisor_clique` | **Divisor Clique** | `EASY` | Beta Round #3 | 91% | [`divisor_clique`](../platforms/csacademy/tasks/divisor_clique/statement.md) |
| `equal-sums` | **Equal Sums** | `EASY` | Round #35 | 93% | [`equal-sums`](../platforms/csacademy/tasks/equal-sums/statement.md) |
| `expected-dice` | **Expected Dice** | `EASY` | Round #43 | 96% | [`expected-dice`](../platforms/csacademy/tasks/expected-dice/statement.md) |
| `frequent-numbers` | **Frequent Numbers** | `EASY` | Round #44 (Div. 2 only) | 95% | [`frequent-numbers`](../platforms/csacademy/tasks/frequent-numbers/statement.md) |
| `gcd-rebuild` | **Gcd Rebuild** | `EASY` | Round #47 | 90% | [`gcd-rebuild`](../platforms/csacademy/tasks/gcd-rebuild/statement.md) |
| `group-split` | **Group Split** | `EASY` | Round #37 (Div. 2 only) | 85% | [`group-split`](../platforms/csacademy/tasks/group-split/statement.md) |
| `kth-special-number` | **Kth Special Number** | `EASY` | Round #24 | 95% | [`kth-special-number`](../platforms/csacademy/tasks/kth-special-number/statement.md) |
| `missing-number` | **Missing Number** | `EASY` | Round #29 (Div. 2 only) | 87% | [`missing-number`](../platforms/csacademy/tasks/missing-number/statement.md) |
| `neighbour-sum-replacement` | **Neighbour Sum Replacement** | `EASY` | Beta Round #8 | 96% | [`neighbour-sum-replacement`](../platforms/csacademy/tasks/neighbour-sum-replacement/statement.md) |
| `numbers-tournament` | **Numbers Tournament** | `EASY` | Round #33 (Div. 2 only) | 90% | [`numbers-tournament`](../platforms/csacademy/tasks/numbers-tournament/statement.md) |
| `odd-divisor-count` | **Odd Divisor Count** | `EASY` | Round #12 (Div. 2 only) | 93% | [`odd-divisor-count`](../platforms/csacademy/tasks/odd-divisor-count/statement.md) |
| `odd_divisors` | **Odd Divisors** | `EASY` | Beta Round #4 | 60% | [`odd_divisors`](../platforms/csacademy/tasks/odd_divisors/statement.md) |
| `odd-pair-sums` | **Odd Pair Sums** | `EASY` | Round #26 (Div. 2 only) | 94% | [`odd-pair-sums`](../platforms/csacademy/tasks/odd-pair-sums/statement.md) |
| `online_gcd` | **Online Gcd** | `EASY` | Beta Round #2 | 80% | [`online_gcd`](../platforms/csacademy/tasks/online_gcd/statement.md) |
| `poisoned-food` | **Poisoned Food** | `EASY` | Round #51 (Div. 2 only) | 96% | [`poisoned-food`](../platforms/csacademy/tasks/poisoned-food/statement.md) |
| `prime-distance` | **Prime Distance** | `EASY` | Round #21 | 92% | [`prime-distance`](../platforms/csacademy/tasks/prime-distance/statement.md) |
| `processing-discounts` | **Processing Discounts** | `EASY` | Round #66 (Div. 2 only) | 83% | [`processing-discounts`](../platforms/csacademy/tasks/processing-discounts/statement.md) |
| `shifted-diagonal-sum` | **Shifted Diagonal Sum** | `EASY` | Round #10 | 89% | [`shifted-diagonal-sum`](../platforms/csacademy/tasks/shifted-diagonal-sum/statement.md) |
| `single-digit-numbers` | **Single Digit Numbers** | `EASY` | Round #11 | 94% | [`single-digit-numbers`](../platforms/csacademy/tasks/single-digit-numbers/statement.md) |
| `sum-triplets` | **Sum Triplets** | `EASY` | Round #52 | 77% | [`sum-triplets`](../platforms/csacademy/tasks/sum-triplets/statement.md) |
| `borland` | **Borland** | `HARD` | Junior Challenge 2017 Day 1 | 35% | [`borland`](../platforms/csacademy/tasks/borland/statement.md) |
| `bunny-on-number-line` | **Bunny on Number Line** | `HARD` | Round #49 | 86% | [`bunny-on-number-line`](../platforms/csacademy/tasks/bunny-on-number-line/statement.md) |
| `camel` | **Camel** | `HARD` | EJOI 2017 Day 2 | 29% | [`camel`](../platforms/csacademy/tasks/camel/statement.md) |
| `connected-tree-subgraphs` | **Connected Tree Subgraphs** | `HARD` | Round #11 | 93% | [`connected-tree-subgraphs`](../platforms/csacademy/tasks/connected-tree-subgraphs/statement.md) |
| `cube-coloring` | **Cube Coloring** | `HARD` | Beta Round #8 | 83% | [`cube-coloring`](../platforms/csacademy/tasks/cube-coloring/statement.md) |
| `distinct_neighbours` | **Distinct Neighbours** | `HARD` | Beta Round #7 | 88% | [`distinct_neighbours`](../platforms/csacademy/tasks/distinct_neighbours/statement.md) |
| `expected-max` | **Expected Max** | `HARD` | Round #56 | 92% | [`expected-max`](../platforms/csacademy/tasks/expected-max/statement.md) |
| `farey_sequence` | **Farey Sequence** | `HARD` | IOI 2016 Training Round #1 | 63% | [`farey_sequence`](../platforms/csacademy/tasks/farey_sequence/statement.md) |
| `fibonacci-mod` | **Fibonacci Mod** | `HARD` | Round #59 (Div. 2 only) | 69% | [`fibonacci-mod`](../platforms/csacademy/tasks/fibonacci-mod/statement.md) |
| `heap-count` | **Heap Count** | `HARD` | Round #47 | 81% | [`heap-count`](../platforms/csacademy/tasks/heap-count/statement.md) |
| `k-consecutive` | **K-consecutive** | `HARD` | IOI 2016 Training Round #4 | 79% | [`k-consecutive`](../platforms/csacademy/tasks/k-consecutive/statement.md) |
| `light-count` | **Light Count** | `HARD` | Round #32 | 68% | [`light-count`](../platforms/csacademy/tasks/light-count/statement.md) |
| `matdiv2` | **Mathison and the divisors 2** | `HARD` | RMI 2017 Day 2 | 42% | [`matdiv2`](../platforms/csacademy/tasks/matdiv2/statement.md) |
| `min-max-sum` | **Min Max Sum** | `HARD` | Round #35 | 84% | [`min-max-sum`](../platforms/csacademy/tasks/min-max-sum/statement.md) |
| `permutation-towers` | **Permutation Towers** | `HARD` | Round #27 | 91% | [`permutation-towers`](../platforms/csacademy/tasks/permutation-towers/statement.md) |
| `six` | **Six** | `HARD` | EJOI 2017 Day 1 | 41% | [`six`](../platforms/csacademy/tasks/six/statement.md) |
| `sum-of-powers` | **Sum of Powers** | `HARD` | Round #32 | 86% | [`sum-of-powers`](../platforms/csacademy/tasks/sum-of-powers/statement.md) |
| `tree-antichain-hard` | **Tree Antichain (Hard)** | `HARD` | Round #38 | 73% | [`tree-antichain-hard`](../platforms/csacademy/tasks/tree-antichain-hard/statement.md) |
| `xor-closure` | **Xor Closure** | `HARD` | Round #10 | 86% | [`xor-closure`](../platforms/csacademy/tasks/xor-closure/statement.md) |
| `addition-time` | **Addition Time** | `MEDIUM` | CS Academy Archive | 59% | [`addition-time`](../platforms/csacademy/tasks/addition-time/statement.md) |
| `all-numbers` | **All Numbers** | `MEDIUM` | CS Academy Archive | 85% | [`all-numbers`](../platforms/csacademy/tasks/all-numbers/statement.md) |
| `amusement-park` | **Amusement Park** | `MEDIUM` | Round #49 | 75% | [`amusement-park`](../platforms/csacademy/tasks/amusement-park/statement.md) |
| `and-closure` | **And Closure** | `MEDIUM` | Round #13 | 88% | [`and-closure`](../platforms/csacademy/tasks/and-closure/statement.md) |
| `aspirations` | **Aspirations** | `MEDIUM` | CS Academy Archive | 89% | [`aspirations`](../platforms/csacademy/tasks/aspirations/statement.md) |
| `banned-digits` | **Banned Digits** | `MEDIUM` | CS Academy Archive | 76% | [`banned-digits`](../platforms/csacademy/tasks/banned-digits/statement.md) |
| `checkroom-hooks` | **Checkroom Hooks** | `MEDIUM` | Round #38 | 85% | [`checkroom-hooks`](../platforms/csacademy/tasks/checkroom-hooks/statement.md) |
| `clown-fiesta` | **Clown Fiesta** | `MEDIUM` | FIICode 2021 Round #2 | 78% | [`clown-fiesta`](../platforms/csacademy/tasks/clown-fiesta/statement.md) |
| `consecutive-digit-signs` | **Consecutive Digits Signs** | `MEDIUM` | Round #18 | 89% | [`consecutive-digit-signs`](../platforms/csacademy/tasks/consecutive-digit-signs/statement.md) |
| `coprime` | **Coprime Pairs** | `MEDIUM` | Round #43 | 89% | [`coprime`](../platforms/csacademy/tasks/coprime/statement.md) |
| `count-arrays` | **Count Arrays** | `MEDIUM` | Round #65 (Div. 2 only) | 75% | [`count-arrays`](../platforms/csacademy/tasks/count-arrays/statement.md) |
| `counting-quests` | **Counting Quests** | `MEDIUM` | Round #35 | 91% | [`counting-quests`](../platforms/csacademy/tasks/counting-quests/statement.md) |
| `crypto` | **Crypto** | `MEDIUM` | IATI Shumen 2017 Day 2 | 61% | [`crypto`](../platforms/csacademy/tasks/crypto/statement.md) |
| `cryptomania` | **Cryptomania** | `MEDIUM` | CS Academy Archive | 85% | [`cryptomania`](../platforms/csacademy/tasks/cryptomania/statement.md) |
| `dacian-array` | **Dacian Array** | `MEDIUM` | Romanian IOI Selection 2023 - Day 1 | 44% | [`dacian-array`](../platforms/csacademy/tasks/dacian-array/statement.md) |
| `digit-function` | **Digit Function** | `MEDIUM` | CS Academy Archive | 98% | [`digit-function`](../platforms/csacademy/tasks/digit-function/statement.md) |
| `digit-holes` | **Digit Holes** | `MEDIUM` | Round #70 | 91% | [`digit-holes`](../platforms/csacademy/tasks/digit-holes/statement.md) |
| `digits-permutation` | **Digits Permutation** | `MEDIUM` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | 85% | [`digits-permutation`](../platforms/csacademy/tasks/digits-permutation/statement.md) |
| `distinct_rotations` | **Distinct Rotations** | `MEDIUM` | Round #22 (Div. 2 only) | 86% | [`distinct_rotations`](../platforms/csacademy/tasks/distinct_rotations/statement.md) |
| `fiicode-2022-d2` | **Dynamic Software** | `MEDIUM` | FIICode 2022 Round #2 – Powered by Atek Software | 75% | [`fiicode-2022-d2`](../platforms/csacademy/tasks/fiicode-2022-d2/statement.md) |
| `etianap` | **Etianap** | `MEDIUM` | FIICode 2021 Round #1 | 72% | [`etianap`](../platforms/csacademy/tasks/etianap/statement.md) |
| `expected-merge` | **Expected Merge** | `MEDIUM` | Round #47 | 89% | [`expected-merge`](../platforms/csacademy/tasks/expected-merge/statement.md) |
| `finalc` | **Final C** | `MEDIUM` | FIICode 2021 Final Round | 86% | [`finalc`](../platforms/csacademy/tasks/finalc/statement.md) |
| `good-permurations` | **Good Permutations** | `MEDIUM` | Round #74 (Div. 2 only) | 89% | [`good-permurations`](../platforms/csacademy/tasks/good-permurations/statement.md) |
| `least-even-digits` | **Least Even Digits** | `MEDIUM` | Round #35 | 68% | [`least-even-digits`](../platforms/csacademy/tasks/least-even-digits/statement.md) |
| `metal-examination` | **Metal Examination** | `MEDIUM` | Round #28 (Div. 2 only) | 75% | [`metal-examination`](../platforms/csacademy/tasks/metal-examination/statement.md) |
| `necromancer` | **Necromancer** | `MEDIUM` | Romanian IOI 2017 Selection #4 | 77% | [`necromancer`](../platforms/csacademy/tasks/necromancer/statement.md) |
| `no-prime-sum` | **No Prime Sum** | `MEDIUM` | Round #23 (Div. 2 only) | 71% | [`no-prime-sum`](../platforms/csacademy/tasks/no-prime-sum/statement.md) |
| `nogcd` | **Nogcd** | `MEDIUM` | Romanian IOI 2017 Selection #1 | 80% | [`nogcd`](../platforms/csacademy/tasks/nogcd/statement.md) |
| `permutations` | **Permutations** | `MEDIUM` | Round #75 | 82% | [`permutations`](../platforms/csacademy/tasks/permutations/statement.md) |
| `prefix-suffix-counting` | **Prefix Suffix Counting** | `MEDIUM` | Round #12 (Div. 2 only) | 79% | [`prefix-suffix-counting`](../platforms/csacademy/tasks/prefix-suffix-counting/statement.md) |
| `product-replace` | **Product Replace** | `MEDIUM` | Round #70 | 95% | [`product-replace`](../platforms/csacademy/tasks/product-replace/statement.md) |
| `restricted-permutations` | **Restricted Permutations** | `MEDIUM` | Round #40 (Div. 2 only) | 94% | [`restricted-permutations`](../platforms/csacademy/tasks/restricted-permutations/statement.md) |
| `reversed-number` | **Reversed Number** | `MEDIUM` | Round #72 | 97% | [`reversed-number`](../platforms/csacademy/tasks/reversed-number/statement.md) |
| `smallest-missing-numbers` | **Smallest Missing Numbers** | `MEDIUM` | CS Academy Archive | 89% | [`smallest-missing-numbers`](../platforms/csacademy/tasks/smallest-missing-numbers/statement.md) |
| `stepping-number` | **Stepping Number** | `MEDIUM` | Round #20 (Div. 2 only) | 81% | [`stepping-number`](../platforms/csacademy/tasks/stepping-number/statement.md) |
| `Sugarel-and-modulo` | **Sugarel and Modulo** | `MEDIUM` | CS Academy Archive | 81% | [`Sugarel-and-modulo`](../platforms/csacademy/tasks/Sugarel-and-modulo/statement.md) |
| `superstition` | **Superstition** | `MEDIUM` | IATI Shumen 2017 Day 1 | 45% | [`superstition`](../platforms/csacademy/tasks/superstition/statement.md) |
| `tree-antichain-easy` | **Tree Antichain (Easy)** | `MEDIUM` | Round #38 | 80% | [`tree-antichain-easy`](../platforms/csacademy/tasks/tree-antichain-easy/statement.md) |
| `triplet-min-sum` | **Triplet Min Sum** | `MEDIUM` | Round #30 (Div. 2 only) | 96% | [`triplet-min-sum`](../platforms/csacademy/tasks/triplet-min-sum/statement.md) |
| `addition` | **Addition** | `TUTORIAL` | CS Academy Archive | 94% | [`addition`](../platforms/csacademy/tasks/addition/statement.md) |
| `gcd` | **Greatest Common Divisor** | `TUTORIAL` | CS Academy Archive | 79% | [`gcd`](../platforms/csacademy/tasks/gcd/statement.md) |
| `template-addition` | **Template Addition** | `TUTORIAL` | CS Academy Archive | 94% | [`template-addition`](../platforms/csacademy/tasks/template-addition/statement.md) |
