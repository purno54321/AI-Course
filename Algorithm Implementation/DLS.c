#include <stdio.h>
#define MAX 10

int DLS(int adj[MAX][MAX], int n, int start, int goal, int limit) {
    if (start == goal) return 1;
    if (limit <= 0) return 0;

    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1) {
            if (DLS(adj, n, i, goal, limit - 1))
                return 1;
        }
    }
    return 0;
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

    int limit = 3;
    int found = DLS(adj, n, 0, 5, limit);
    if (found) printf("Goal found within depth %d\n", limit);
    else printf("Goal NOT found within depth %d\n", limit);
    return 0;
}
