#include <stdio.h>
#include <limits.h>

// Alpha-Beta Pruning সহ MinMax ফাংশন
int alphabeta(int depth, int nodeIndex, int isMax, int scores[], int h, int alpha, int beta) {
    // যদি লিফ নোডে পৌঁছাই তাহলে score রিটার্ন
    if (depth == h) {
        return scores[nodeIndex];
    }

    // যদি Maximizer এর টার্ন হয়
    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < 2; i++) {
            int val = alphabeta(depth + 1, nodeIndex * 2 + i, 0, scores, h, alpha, beta);
            if (val > best) best = val;
            if (best > alpha) alpha = best;

            // Pruning condition
            if (beta <= alpha) break;
        }
        return best;
    }
    // যদি Minimizer এর টার্ন হয়
    else {
        int best = INT_MAX;
        for (int i = 0; i < 2; i++) {
            int val = alphabeta(depth + 1, nodeIndex * 2 + i, 1, scores, h, alpha, beta);
            if (val < best) best = val;
            if (best < beta) beta = best;

            // Pruning condition
            if (beta <= alpha) break;
        }
        return best;
    }
}

int main() {
    // লিফ নোডগুলোর স্কোর
    int scores[] = {3, 5, 6, 9, 1, 2, 0, -1};
    int n = 8;  // লিফ নোড সংখ্যা

    // ট্রি এর উচ্চতা (log2(n))
    int h = 3;

    int optimal = alphabeta(0, 0, 1, scores, h, INT_MIN, INT_MAX);
    printf("Optimal value (with Alpha-Beta): %d\n", optimal);

    return 0;
} 