#include <stdio.h>

#define MAX_N 26

static int left_child[MAX_N];
static int right_child[MAX_N];

static void preorder(int node) {
    if (node == -1) return;
    putchar('A' + node);
    preorder(left_child[node]);
    preorder(right_child[node]);
}

static void inorder(int node) {
    if (node == -1) return;
    inorder(left_child[node]);
    putchar('A' + node);
    inorder(right_child[node]);
}

static void postorder(int node) {
    if (node == -1) return;
    postorder(left_child[node]);
    postorder(right_child[node]);
    putchar('A' + node);
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    for (int i = 0; i < MAX_N; i++) {
        left_child[i] = -1;
        right_child[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        char P, L, R;
        if (scanf(" %c %c %c", &P, &L, &R) != 3) {
            return 0;
        }
        int p = P - 'A';
        left_child[p]  = (L == '.') ? -1 : (L - 'A');
        right_child[p] = (R == '.') ? -1 : (R - 'A');
    }

    preorder(0);
    putchar('\n');
    inorder(0);
    putchar('\n');
    postorder(0);
    putchar('\n');

    return 0;
}
