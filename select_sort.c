#include <stdio.h>

void SelectSort(int A[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min])
                min = j;
        }
        if (min != i) {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[] = {49, 38, 65, 97, 49, 13, 27, 76};
    int n = 8;

    printf("Before sorting: ");
    PrintArray(A, n);

    SelectSort(A, n);

    printf("After sorting:  ");
    PrintArray(A, n);

    return 0;
}