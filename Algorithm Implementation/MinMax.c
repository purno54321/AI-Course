#include <stdio.h>
#include <limits.h>

// MinMax ফাংশন
int minmax(int depth, int nodeIndex, int isMax, int scores[], int h) {
    // যদি লিফ নোডে পৌঁছাই তাহলে score রিটার্ন
    if (depth == h) {
        return scores[nodeIndex];
    }

    // যদি Max এর টার্ন হয়
    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < 2; i++) {
            int val = minmax(depth + 1, nodeIndex * 2 + i, 0, scores, h);
            if (val > best) best = val;
        }
        return best;
    }
    // যদি Min এর টার্ন হয়
    else {
        int best = INT_MAX;
        for (int i = 0; i < 2; i++) {
            int val = minmax(depth + 1, nodeIndex * 2 + i, 1, scores, h);
            if (val < best) best = val;
        }
        return best;
    }
}

int main() {
    // লিফ নোডগুলোর স্কোর (ধরা যাক টিক-ট্যাক-টো এর ফলাফল)
    int scores[] = {3, 5, 2, 9, 12, 5, 23, 23};
    int n = 8; // লিফ নোড সংখ্যা

    // ট্রি এর উচ্চতা (log2(n))
    int h = 3;  

    int optimal = minmax(0, 0, 1, scores, h);
    printf("Optimal value: %d\n", optimal);

    return 0;
} 