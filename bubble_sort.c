#include <stdio.h>
#include <stdbool.h>

int KCN, RMN;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    RMN += 3;
}

void BubbleSortV1(int A[], int n) {
    KCN = 0; RMN = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            KCN++;
            if (A[j - 1] > A[j])
                swap(&A[j - 1], &A[j]);
        }
    }
}

void BubbleSortV2(int A[], int n) {
    KCN = 0; RMN = 0;
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = n - 1; j > i; j--) {
            KCN++;
            if (A[j - 1] > A[j]) {
                swap(&A[j - 1], &A[j]);
                flag = true;
            }
        }
        if (!flag) return;
    }
}

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void TestV1(int A[], int n) {
    printf("V1.0 (basic bubble sort):\n");
    BubbleSortV1(A, n);
    printf("After sorting: ");
    PrintArray(A, n);
    printf("KCN = %d  RMN = %d\n\n", KCN, RMN);
}

void TestV2(int A[], int n) {
    printf("V2.0 (flag-optimized bubble sort):\n");
    BubbleSortV2(A, n);
    printf("After sorting: ");
    PrintArray(A, n);
    printf("KCN = %d  RMN = %d\n\n", KCN, RMN);
}

void CopyArray(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

int main() {
    int original[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;
    int A[8];

    printf("Before sorting: ");
    PrintArray(original, n);
    printf("\n");

    CopyArray(original, A, n);
    TestV1(A, n);

    CopyArray(original, A, n);
    TestV2(A, n);

    printf("Bubble Sort KCN formulas:\n");
    printf("  Best:  KCN = n-1 = %d\n", n - 1);
    printf("  Worst: KCN = n(n-1)/2 = %d\n", n * (n - 1) / 2);
    printf("Bubble Sort RMN formulas:\n");
    printf("  Best:  RMN = 0\n");
    printf("  Worst: RMN = 3n(n-1)/2 = %d\n", 3 * n * (n - 1) / 2);

    return 0;
}