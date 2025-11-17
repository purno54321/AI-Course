#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// নোডের জন্য স্ট্রাকচার
typedef struct {
    int id;     // নোড নাম্বার
    int g;      // start থেকে আসার খরচ
    int h;      // heuristic মান (goal পর্যন্ত আনুমানিক খরচ)
    int f;      // f = g + h
    int parent; // parent নোড ট্র্যাক করার জন্য
} Node;

// গ্রাফ adjacency list আকারে
int graph[MAX][MAX];   // graph[u][v] = খরচ (যদি edge থাকে)
int graphSize[MAX];    // প্রতিটি নোডের প্রতিবেশীর সংখ্যা

// heuristic মান
int heuristic[MAX];

// Priority Queue এর জন্য (simple linear search দিয়ে min বের করবো)
int openSet[MAX];   // open set = যেসব নোড এখনো explore করা হয়নি
int openCount = 0;

int closedSet[MAX]; // closed set = যেসব নোড এক্সপ্লোর করা শেষ
int closedCount = 0;

Node nodes[MAX];    // প্রতিটি নোডের তথ্য রাখা হবে

// openSet এ নোড যোগ করা
void addOpenSet(int id) {
    openSet[openCount++] = id;
}

// openSet থেকে f মান সবচেয়ে ছোট নোড বের করা
int getBestNode() {
    int bestIndex = 0;
    for (int i = 1; i < openCount; i++) {
        if (nodes[openSet[i]].f < nodes[openSet[bestIndex]].f) {
            bestIndex = i;
        }
    }
    int bestNode = openSet[bestIndex];

    // সেই নোড openSet থেকে বাদ দেওয়া
    for (int i = bestIndex; i < openCount - 1; i++) {
        openSet[i] = openSet[i + 1];
    }
    openCount--;

    return bestNode;
}

// নোড closedSet এ আছে কিনা চেক
int inClosedSet(int id) {
    for (int i = 0; i < closedCount; i++) {
        if (closedSet[i] == id) return 1;
    }
    return 0;
}

// A* অ্যালগরিদম
void aStar(int start, int goal) {
    nodes[start].id = start;
    nodes[start].g = 0;
    nodes[start].h = heuristic[start];
    nodes[start].f = nodes[start].g + nodes[start].h;
    nodes[start].parent = -1;

    addOpenSet(start);

    while (openCount > 0) {
        int current = getBestNode();
        printf("Visiting Node: %d (f=%d, g=%d, h=%d)\n",
               current, nodes[current].f, nodes[current].g, nodes[current].h);

        if (current == goal) {
            printf("Goal Found!\n");

            // পথ প্রিন্ট করা
            printf("Path: ");
            int path[MAX], len = 0;
            for (int n = current; n != -1; n = nodes[n].parent) {
                path[len++] = n;
            }
            for (int i = len - 1; i >= 0; i--) {
                printf("%d ", path[i]);
            }
            printf("\n");
            return;
        }

        closedSet[closedCount++] = current;

        // প্রতিবেশী এক্সপ্লোর করা
        for (int i = 0; i < graphSize[current]; i++) {
            int neighbor = graph[current][i];
            int cost = 1;  // edge cost = 1 (সাধারণ করার জন্য)

            if (inClosedSet(neighbor)) continue;

            int tentativeG = nodes[current].g + cost;

            if (nodes[neighbor].id == 0 || tentativeG < nodes[neighbor].g) {
                nodes[neighbor].id = neighbor;
                nodes[neighbor].g = tentativeG;
                nodes[neighbor].h = heuristic[neighbor];
                nodes[neighbor].f = nodes[neighbor].g + nodes[neighbor].h;
                nodes[neighbor].parent = current;

                addOpenSet(neighbor);
            }
        }
    }

    printf("Goal Not Found!\n");
}

int main() {
    // গ্রাফ বানানো (undirected)
    graph[1][0] = 2; graph[1][1] = 3; graphSize[1] = 2;
    graph[2][0] = 4; graph[2][1] = 5; graphSize[2] = 2;
    graph[3][0] = 6; graphSize[3] = 1;
    graph[4][0] = 7; graphSize[4] = 1;
    graph[5][0] = 8; graphSize[5] = 1;
    graph[6][0] = 9; graphSize[6] = 1;

    // heuristic মান (ধরে নেই goal = 9)
    heuristic[1] = 6;
    heuristic[2] = 5;
    heuristic[3] = 3;
    heuristic[4] = 4;
    heuristic[5] = 2;
    heuristic[6] = 1;
    heuristic[7] = 6;
    heuristic[8] = 4;
    heuristic[9] = 0;

    aStar(1, 9);  // start = 1, goal = 9
    return 0;
} 