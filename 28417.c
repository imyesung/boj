#include <stdio.h>

int main(void) {
    int n;  // number of players
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int best_total = -1;

    for (int i = 0; i < n; ++i) {
        int run1, run2;
        if (scanf ("%d %d", &run1, &run2) != 2) {    // read the two run scores
            return 0;
        }

        /* top1 = largest trick score so far, top2 = second largest
        scores are in [0, 100], so -1 is a safe sentinel meaning "no score yet" */
        int top1 = -1;
        int top2 = -1;

        for (int j = 0; j < 5; j++) {  // read 5 trick scores
            int s;  // score for this trick attempt
            if (scanf ("%d", &s) != 1) {
                return 0;
            }

            /* single-pass O(5) update to keep the two largest trick scores:
            after this block, top1 is max, top2 is second max among processed tricks */
            if (s > top1) {
                top2 = top1;
                top1 = s;
            } else if (s > top2) {
                top2 = s;
            }
        }

        int run_best = (run1 > run2) ? run1 : run2; // best score among two runs
        int total = run_best + top1 + top2;

        if (total > best_total) {
            best_total = total;
        }
    }

    printf("%d\n", best_total);
    return 0;
}