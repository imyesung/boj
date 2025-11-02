/*
 * Solution 1: Direct-Address Table (implemented as a Boolean Array)
 *
 * Time Complexity: 
 * - This problem: Θ(1) - 28 inputs + 30 checks (fixed)
 * - Generalized (n students, n-2 submissions): Θ(n)
 * Space Complexity: 
 * - This problem: Θ(1) - array size 31 (fixed)
 * - Generalized: Θ(n)
 */
#include <stdio.h>

int main(void) {
    int present[31] = {0}; // Attendance tracker for students 1 to 30
    int id; // Student ID input variable

    for (int i = 0; i < 28; i++) { // Loop to read 28 student IDs
        if (scanf("%d", &id) != 1) {
            return 0; // Input error handling
        }
        present[id] = 1; // Mark student as present
    }
    for (int i = 1; i <= 30; i++) {
        if (present[i] == 0) { // Check for absent students
            printf("%d\n", i); // Print absent student's number
        }
    }
    return 0;
}