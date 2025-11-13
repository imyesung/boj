#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    double max = 0.0;
    double sum = 0.0;
    
    for (int i = 0; i < n; i++) {
        double scores;
        scanf("%lf", &scores); // Read one score from input

        sum += scores;         // Add this score to the total sum

        if (scores > max) {    // Check if this score is the new maximum
            max = scores;      // Update maximum score
        }
    }
    
    printf("%lf\n", (sum / max * 100.0) / n);

    
    return 0;
}