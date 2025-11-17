#include <stdio.h>
#define MAX 10

int adj[MAX][MAX] = {
    {0,1,1,0,0,0},
    {1,0,0,1,1,0},
    {1,0,0,0,1,0},
    {0,1,0,0,0,1},
    {0,1,1,0,0,1},
    {0,0,0,1,1,0}
};

int visited_from_start[MAX] = {0};
int visited_from_goal[MAX] = {0};
int n = 6;

void BFS_step(int queue[], int *front, int *rear, int visited[MAX]) {
    int node = queue[(*front)++];
    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            visited[i] = 1;
            queue[++(*rear)] = i;
        }
    }
}

int is_meeting_point() {
    for (int i = 0; i < n; i++)
        if (visited_from_start[i] && visited_from_goal[i])
            return i;
    return -1;
}

void bidirectional_search(int start, int goal) {
    int q1[MAX], q2[MAX];
    int f1 = 0, r1 = -1, f2 = 0, r2 = -1;

    q1[++r1] = start;
    q2[++r2] = goal;
    visited_from_start[start] = 1;
    visited_from_goal[goal] = 1;

    while (f1 <= r1 && f2 <= r2) {
        BFS_step(q1, &f1, &r1, visited_from_start);
        BFS_step(q2, &f2, &r2, visited_from_goal);

        int meet = is_meeting_point();
        if (meet != -1) {
            printf("Path found! Meeting at node: %d\n", meet);
            return;
        }
    }
    printf("No path found.\n");
}

int main() {
    bidirectional_search(0, 5);
    return 0;
}
