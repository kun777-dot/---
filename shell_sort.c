#include <stdio.h>

void ShellSort(int A[], int n) {
    int d, i, j;
    for (d = n / 2; d >= 1; d = d / 2) {
        for (i = d + 1; i <= n; i++) {
            if (A[i] < A[i - d]) {
                A[0] = A[i];
                for (j = i - d; j > 0 && A[0] < A[j]; j -= d)
                    A[j + d] = A[j];
                A[j + d] = A[0];
            }
        }
    }
}

void PrintArray(int A[], int n) {
    for (int i = 1; i <= n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[11] = {0, 49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
    int n = 10;

    printf("Before sorting: ");
    PrintArray(A, n);

    ShellSort(A, n);

    printf("After sorting:  ");
    PrintArray(A, n);

    return 0;
}