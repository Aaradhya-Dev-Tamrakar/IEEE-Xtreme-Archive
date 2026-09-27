#include <stdio.h>

#define N 100000
#define INF 100000

int max(int a, int b) { return a > b ? a : b; }

struct Link {
    struct Link *next;
    int node;
} adjacency[N];

int max0[N], max1[N], max2[N], max3[N];

void addLink(int from, int to) {
    static struct Link links[N * 2], *linkPtr = links;
    linkPtr->node = to;
    linkPtr->next = adjacency[from].next;
    adjacency[from].next = linkPtr++;
}

void traverse(int parent, int current) {
    struct Link *link;
    int neighbor, sum0, sum1, sum2, sumTotal;

    sum0 = 0, sum1 = -INF, sum2 = -INF, sumTotal = 0;

    for (link = adjacency[current].next; link; link = link->next) {
        if ((neighbor = link->node) != parent) {
            traverse(current, neighbor);

            sum2 = max(max(sum1, sum2) + max3[neighbor], sum2 + max0[neighbor]);
            if (sum2 < 0)
                sum2 = -INF;

            sum1 = max(sum0 + max3[neighbor], sum1 + max0[neighbor]);
            if (sum1 < 0)
                sum1 = -INF;

            sum0 += max0[neighbor];
            sumTotal += max(max0[neighbor], max1[neighbor] + 1);
        }
    }

    max0[current] = max(sum0, sum2 + 1);
    max1[current] = sum1;
    max2[current] = sumTotal;
    max3[current] = max(max1[current], max2[current]);
}

int main() {
    int numNodes, edgeCount, i, j;

    scanf("%d", &numNodes);

    for (edgeCount = 0; edgeCount < numNodes - 1; edgeCount++) {
        scanf("%d %d", &i, &j);
        i--, j--;
        addLink(i, j);
        addLink(j, i);
    }

    traverse(-1, 0);

    printf("%d\n", max(max0[0], max3[0]));
    return 0;
}
