#include <stdio.h>

int rowcheck(int a[9][9]);
int colcheck(int a[9][9]);
int cubecheck(int a[9][9]);

int main() {
    int a[9][9] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {4, 5, 6, 7, 8, 9, 1, 2, 3},
        {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {2, 3, 4, 5, 6, 7, 8, 9, 1},
        {5, 6, 7, 8, 9, 1, 2, 3, 4},
        {8, 9, 1, 2, 3, 4, 5, 6, 7},
        {3, 4, 5, 6, 7, 8, 9, 1, 2},
        {6, 7, 8, 9, 1, 2, 3, 4, 5},
        {9, 1, 2, 3, 4, 5, 6, 7, 8}
    };

    if (rowcheck(a) == 1 && colcheck(a) == 1 && cubecheck(a) == 1)
        printf("success\n");
    else
        printf("failed\n");

    return 0;
}

int rowcheck(int a[9][9]) {
    int c[10] = {0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            c[a[i][j]]++;
        }
        for (int k = 1; k <= 9; k++)
            if (c[k] != 1) {
                printf("the value %d came %d times in %d row\n", k, c[k], i + 1);
                return 0;
            }
        for (int k = 1; k <= 9; k++)
            c[k] = 0;
    }
    return 1;
}

int colcheck(int a[9][9]) {
    int c[10] = {0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            c[a[j][i]]++;
        }
        for (int k = 1; k <= 9; k++)
            if (c[k] != 1) {
                printf("the value %d came %d times in %d column\n", k, c[k], i + 1);
                return 0;
            }
        for (int k = 1; k <= 9; k++)
            c[k] = 0;
    }
    return 1;
}

int cubecheck(int a[9][9]) {
    int c[10] = {0}, count = 0;
    for (int m = 0; m < 9; m += 3) {
        for (int b = 0; b < 9; b += 3) {
            for (int i = m; i < m + 3; i++) {
                for (int j = b; j < b + 3; j++) {
                    c[a[i][j]]++;
                }
            }
            count++;
            for (int k = 1; k <= 9; k++)
                if (c[k] != 1) {
                    printf("the value %d came %d times in %d box\n", k, c[k], count);
                    return 0;
                }
            for (int k = 1; k <= 9; k++)
                c[k] = 0;
        }
    }
    return 1;
}
