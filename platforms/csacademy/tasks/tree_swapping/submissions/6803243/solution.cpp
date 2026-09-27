#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

// Struct to hold the tree structure and colors
struct Node {
    vector<int> neighbors;
    char initial_color;
    char target_color; // Determined by the bipartite set
    int bipartite_set; // 0 or 1
};

vector<Node> tree;
int N;
long long total_swaps;

// --- Step 1: Bipartite Partition (DFS 1) ---
// Finds the two bipartite sets (sets nodes' bipartite_set)
// Also checks if the initial counts can form one of the two target colorings.
void find_bipartite_sets(int u, int parent, int set_id, int& count0, int& count1) {
    tree[u].bipartite_set = set_id;
    if (set_id == 0) count0++; else count1++;

    for (int v : tree[u].neighbors) {
        if (v != parent) {
            find_bipartite_sets(v, u, 1 - set_id, count0, count1);
        }
    }
}

// --- Step 2: Calculate Flow and Swaps (DFS 2) ---
// Returns the net flow of Red (R) that must cross the edge (u, parent).
// +1: u's subtree has one excess R that must move up.
// -1: u's subtree is deficient by one R that must move down.
int calculate_flow(int u, int parent) {
    // Determine if the current node needs an R to leave (+1) or an R to enter (-1)
    // based on the target coloring.
    int local_flow = 0;
    
    // Check if the current color is R (i.e., we have an R color to account for)
    if (tree[u].initial_color == 'R') {
        // If target is B ('B' means the 'R' must leave to be correct)
        if (tree[u].target_color == 'B') { 
            local_flow = 1; // R is present, but target is B. R must leave.
        } else { // target is R
            local_flow = 0; // R is present and R is correct. No net movement needed locally.
        }
    } else { // Current color is B
        // If target is R ('R' means the 'B' must leave to be replaced by an R)
        if (tree[u].target_color == 'R') { 
            local_flow = -1; // R is needed. A net R must flow in.
        } else { // target is B
            local_flow = 0; // B is present and B is correct.
        }
    }

    // Sum the flow from children
    for (int v : tree[u].neighbors) {
        if (v != parent) {
            local_flow += calculate_flow(v, u);
        }
    }

    // The net flow across the edge (u, parent) is the absolute value of the flow at u.
    // We only sum for non-root edges. The root's flow is checked by the caller.
    if (parent != 0) {
        total_swaps += abs(local_flow);
    }
    
    return local_flow;
}

// --- Main Solver ---
long long solve_for_target(char target0_color) {
    // Set Target Colors: target0_color for set 0, opposite for set 1
    char target1_color = (target0_color == 'R' ? 'B' : 'R');
    
    // Set the target colors for all nodes based on their bipartite set
    for (int i = 1; i <= N; ++i) {
        if (tree[i].bipartite_set == 0) {
            tree[i].target_color = target0_color;
        } else {
            tree[i].target_color = target1_color;
        }
    }

    // Check if the total initial R/B counts match the target R/B counts
    int initial_r_count = 0;
    for (int i = 1; i <= N; ++i) {
        if (tree[i].initial_color == 'R') {
            initial_r_count++;
        }
    }

    int target_r_count = 0;
    for (int i = 1; i <= N; ++i) {
        if (tree[i].target_color == 'R') {
            target_r_count++;
        }
    }

    if (initial_r_count != target_r_count) {
        return LLONG_MAX; // Impossible target for the given initial counts
    }

    // Perform the flow calculation DFS
    total_swaps = 0;
    int root_flow = calculate_flow(1, 0); // Start DFS from root (node 1)

    // The total net flow must be 0 for the entire tree, otherwise the count check failed.
    // If we passed the count check, root_flow must be 0.
    if (root_flow != 0) {
        // This should not happen if the count check passes, but as a safety measure
        return LLONG_MAX;
    }

    return total_swaps;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;
    
    string colors_str;
    cin >> colors_str;

    // Node indices are 1-based, so resize to N+1
    tree.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        tree[i].initial_color = colors_str[i - 1];
    }

    // Read edges
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].neighbors.push_back(v);
        tree[v].neighbors.push_back(u);
    }

    // --- Step 1: Find Bipartite Sets ---
    int count0 = 0, count1 = 0;
    find_bipartite_sets(1, 0, 0, count0, count1);

    // --- Step 2: Solve for both possible target colorings ---
    long long ans1 = solve_for_target('R'); // Target 1: Set 0 is R, Set 1 is B
    long long ans2 = solve_for_target('B'); // Target 2: Set 0 is B, Set 1 is R

    // --- Final Result ---
    long long result = min(ans1, ans2);

    if (result == LLONG_MAX) {
        cout << -1 << "\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}