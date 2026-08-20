#include <stdio.h>

int main() {
    int n;
    printf("Enter set size (2 or 3): ");
    scanf("%d", &n);

    int total = 1 << (n * n);
    int count = 0;

    for (int num = 0; num < total; num++) {
        int r[5][5] = {0};
        int temp = num;

        // Make relation matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                r[i][j] = temp % 2;
                temp /= 2;
            }
        }

        int transitive = 1;

        // Check transitivity
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (r[i][j]) {
                    for (int k = 0; k < n; k++) {
                        if (r[j][k] && !r[i][k]) {
                            transitive = 0;
                        }
                    }
                }
            }
        }

        if (transitive)
            count++;
    }

    printf("Transitive relations = %d\n", count);

    return 0;
}