#include <stdio.h>
#define MAX 10

int DLS(int adj[MAX][MAX], int n, int start, int goal, int limit) {
    if (start == goal) return 1;
    if (limit <= 0) return 0;

    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1)
            if (DLS(adj, n, i, goal, limit - 1))
                return 1;
    }
    return 0;
}

void IDS(int adj[MAX][MAX], int n, int start, int goal, int maxDepth) {
    for (int limit = 0; limit <= maxDepth; limit++) {
        printf("Depth limit: %d\n", limit);
        if (DLS(adj, n, start, goal, limit)) {
            printf("Goal found at depth %d\n", limit);
            return;
        }
    }
    printf("Goal not found within depth %d\n", maxDepth);
}

int main() {
    int n = 6;
    int adj[MAX][MAX] = {
        {0,1,1,0,0,0},
        {1,0,0,1,1,0},
        {1,0,0,0,1,0},
        {0,1,0,0,0,1},
        {0,1,1,0,0,1},
        {0,0,0,1,1,0}
    };

    IDS(adj, n, 0, 5, 5);
    return 0;
}
