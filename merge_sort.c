#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int temp[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (A[i] <= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= mid)
        temp[k++] = A[i++];
    while (j <= high)
        temp[k++] = A[j++];
    for (int p = low; p <= high; p++)
        A[p] = temp[p];
}

void MergeSort(int A[], int temp[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, temp, low, mid);
        MergeSort(A, temp, mid + 1, high);
        Merge(A, temp, low, mid, high);
    }
}

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[] = {49, 38, 65, 97, 76, 13, 27};
    int n = 7;
    int *temp = (int *)malloc(n * sizeof(int));

    printf("Before sorting: ");
    PrintArray(A, n);

    MergeSort(A, temp, 0, n - 1);

    printf("After sorting:  ");
    PrintArray(A, n);

    free(temp);
    return 0;
}