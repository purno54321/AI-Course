#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define BEAM_WIDTH 2   // একসাথে কয়টি নোড রাখা যাবে (Beam Width)

// নোড স্ট্রাকচার
typedef struct {
    int id;     // নোড নাম্বার
    int h;      // heuristic মান
} Node;

// গ্রাফ (adjacency list আকারে রাখা হচ্ছে)
int graph[MAX][MAX];   // graph[u][v] = 1 হলে u থেকে v তে edge আছে
int graphSize[MAX];    // প্রতিটি নোডের প্রতিবেশীর সংখ্যা

// heuristic মান রাখা
int heuristic[MAX];

// Beam Search ফাংশন
void beamSearch(int start, int goal) {
    Node beam[BEAM_WIDTH];   // একসাথে রাখা হবে সর্বোচ্চ BEAM_WIDTH সংখ্যক নোড
    int beamCount = 0;       // beam এ কয়টি নোড আছে

    // প্রথমে start node beam এ রাখি
    beam[beamCount++] = (Node){start, heuristic[start]};

    while (beamCount > 0) {
        printf("Current Beam: ");
        for (int i = 0; i < beamCount; i++) {
            printf("%d(h=%d) ", beam[i].id, beam[i].h);
        }
        printf("\n");

        // goal পেলে search শেষ
        for (int i = 0; i < beamCount; i++) {
            if (beam[i].id == goal) {
                printf("Goal Found: %d\n", beam[i].id);
                return;
            }
        }

        // প্রতিবেশী নোড সংগ্রহ
        Node candidates[MAX];
        int candidateCount = 0;

        for (int i = 0; i < beamCount; i++) {
            int u = beam[i].id;
            for (int j = 0; j < graphSize[u]; j++) {
                int v = graph[u][j];
                candidates[candidateCount++] = (Node){v, heuristic[v]};
            }
        }

        // beam পরিষ্কার
        beamCount = 0;

        // ক্যান্ডিডেট নোডগুলো heuristic অনুযায়ী sort করা
        for (int i = 0; i < candidateCount - 1; i++) {
            for (int j = i + 1; j < candidateCount; j++) {
                if (candidates[i].h > candidates[j].h) {
                    Node temp = candidates[i];
                    candidates[i] = candidates[j];
                    candidates[j] = temp;
                }
            }
        }

        // ছোট heuristic মানের BEAM_WIDTH সংখ্যক নোড বেছে নিয়ে beam এ রাখা
        for (int i = 0; i < candidateCount && i < BEAM_WIDTH; i++) {
            beam[beamCount++] = candidates[i];
        }
    }

    printf("Goal Not Found!\n");
}

int main() {
    // গ্রাফ বানানো
    graph[1][0] = 2; graph[1][1] = 3; graphSize[1] = 2;
    graph[2][0] = 4; graph[2][1] = 5; graphSize[2] = 2;
    graph[3][0] = 6; graphSize[3] = 1;
    graph[4][0] = 7; graphSize[4] = 1;
    graph[5][0] = 8; graphSize[5] = 1;
    graph[6][0] = 9; graphSize[6] = 1;

    // heuristic মান (ধরে নেই goal = 9)
    heuristic[1] = 6;
    heuristic[2] = 4;
    heuristic[3] = 3;
    heuristic[4] = 5;
    heuristic[5] = 2;
    heuristic[6] = 1;
    heuristic[7] = 7;
    heuristic[8] = 4;
    heuristic[9] = 0;

    beamSearch(1, 9);  // শুরু = 1, goal = 9
    return 0;
} 