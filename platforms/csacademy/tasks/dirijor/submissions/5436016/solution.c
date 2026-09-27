#include <stdio.h>

int main() {
    int N, P;
    scanf("%d %d", &N, &P);
    
    int costs[5000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &costs[i]);
    }
    
    int totalCost = 0;

    // Perform 2 * P trips: P to N+1 and P back to 1
    for (int concert = 0; concert < P; concert++) {
        // Even index concert goes to city N + 1, odd index concert goes to city 1
        int start = (concert % 2 == 0) ? 0 : N; // Start city
        int end = (concert % 2 == 0) ? N : 0;   // End city

        // Determine the maximum cost in the path
        int maxCost = 0;

        // If traveling from city 1 to N+1
        if (start < end) {
            for (int i = start; i < end; i++) {
                if (costs[i] > maxCost) {
                    maxCost = costs[i];
                }
            }
        } else { // If traveling from city N+1 to 1
            for (int i = end; i < start; i++) {
                if (costs[i] > maxCost) {
                    maxCost = costs[i];
                }
            }
        }

        // Add maximum cost to total cost
        totalCost += maxCost;

        // Set the maximum cost in the segment to 0
        if (start < end) {
            for (int i = start; i < end; i++) {
                if (costs[i] == maxCost) {
                    costs[i] = 0; // Replace max cost with 0
                    break; // Set only the first occurrence
                }
            }
        } else {
            for (int i = end; i < start; i++) {
                if (costs[i] == maxCost) {
                    costs[i] = 0; // Replace max cost with 0
                    break; // Set only the first occurrence
                }
            }
        }
    }

    // Output the total cost
    printf("%d\n", totalCost);
    return 0;
}
