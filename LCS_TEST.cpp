#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printTable(int table[MAX_LENGTH][MAX_LENGTH], int rows, int cols) {
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
}

int lcsLength(char S1[], char S2[], int m, int n) {
    int table[MAX_LENGTH][MAX_LENGTH];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    printf("LCS Length Table:\n");
    printTable(table, m, n);

    return table[m][n];
}

void constructLCS(char S1[], char S2[], int m, int n) {
    int table[MAX_LENGTH][MAX_LENGTH];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    int lcsLength = table[m][n];
    char lcs[MAX_LENGTH];
    int index = lcsLength;

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcs[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        } else if (table[i - 1][j] > table[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char S1[] = {'B', 'C', 'D', 'A', 'A', 'C', 'D'};
    char S2[] = {'A', 'C', 'D', 'B', 'A', 'C'};

    int m = sizeof(S1) / sizeof(S1[0]);
    int n = sizeof(S2) / sizeof(S2[0]);

    int length = lcsLength(S1, S2, m, n);
    printf("LCS Length: %d\n", length);

    constructLCS(S1, S2, m, n);

    return 0;
}
