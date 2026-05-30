#include <stdio.h>

int Partition(int A[], int low, int high) {
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot) --high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot) ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;

    printf("Before sorting: ");
    PrintArray(A, n);

    QuickSort(A, 0, n - 1);

    printf("After sorting:  ");
    PrintArray(A, n);

    return 0;
}