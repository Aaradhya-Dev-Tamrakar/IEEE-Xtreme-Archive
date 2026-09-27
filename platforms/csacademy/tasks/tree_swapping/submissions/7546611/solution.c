#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MAXE 200005
#define INF 1000000000000000000LL

int head[MAXN];
int to[MAXE];
int nextEdge[MAXE];

int parent[MAXN];
int depth[MAXN];
int order[MAXN];

long long diff0[MAXN];
long long diff1[MAXN];

int edgeCount = 0;

void addEdge(int u, int v)
{
    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount;
    edgeCount++;
}

int main()
{
    int N;
    int i;

    scanf("%d", &N);

    char color[MAXN];

    scanf("%s", color);

    /* Initialize adjacency list */
    for (i = 1; i <= N; i++)
        head[i] = -1;

    /* Read edges */
    for (i = 0; i < N - 1; i++)
    {
        int u, v;

        scanf("%d %d", &u, &v);

        addEdge(u, v);
        addEdge(v, u);
    }

    /*
        Build parent, depth and traversal order.

        We use an iterative DFS instead of recursion
        because N can be 100000.
    */

    int orderSize = 0;

    parent[1] = 0;
    depth[1] = 0;

    order[orderSize++] = 1;

    for (i = 0; i < orderSize; i++)
    {
        int u = order[i];

        int e;

        for (e = head[u]; e != -1; e = nextEdge[e])
        {
            int v = to[e];

            if (v == parent[u])
                continue;

            parent[v] = u;
            depth[v] = depth[u] + 1;

            order[orderSize++] = v;
        }
    }

    /*
        There are two possible valid colorings.

        Coloring 0:
            even depth -> R
            odd depth  -> B

        Coloring 1:
            even depth -> B
            odd depth  -> R
    */

    int currentRed = 0;
    int targetRed0 = 0;
    int targetRed1 = 0;

    for (i = 1; i <= N; i++)
    {
        int current = (color[i - 1] == 'R');

        if (current)
            currentRed++;

        if (depth[i] % 2 == 0)
        {
            /* Target 0 wants Red */
            diff0[i] = current - 1;

            /* Target 1 wants Blue */
            diff1[i] = current;

            targetRed0++;
        }
        else
        {
            /* Target 0 wants Blue */
            diff0[i] = current;

            /* Target 1 wants Red */
            diff1[i] = current - 1;

            targetRed1++;
        }
    }

    long long ans0 = INF;
    long long ans1 = INF;

    /*
        Try target coloring 0.

        The number of Red nodes cannot change,
        because every operation only swaps colors.
    */

    if (currentRed == targetRed0)
    {
        long long moves = 0;

        /* Bottom-up processing */
        for (i = orderSize - 1; i > 0; i--)
        {
            int u = order[i];

            moves += llabs(diff0[u]);

            diff0[parent[u]] += diff0[u];
        }

        ans0 = moves;
    }

    /*
        Try target coloring 1.
    */

    if (currentRed == targetRed1)
    {
        long long moves = 0;

        /* Bottom-up processing */
        for (i = orderSize - 1; i > 0; i--)
        {
            int u = order[i];

            moves += llabs(diff1[u]);

            diff1[parent[u]] += diff1[u];
        }

        ans1 = moves;
    }

    long long answer;

    if (ans0 < ans1)
        answer = ans0;
    else
        answer = ans1;

    if (answer == INF)
        printf("-1\n");
    else
        printf("%lld\n", answer);

    return 0;
}