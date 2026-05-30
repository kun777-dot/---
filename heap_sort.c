#include <stdio.h>

typedef int KeyType;

typedef struct {
    KeyType key;
} RecordType;

#define MAXSIZE 100
typedef struct {
    RecordType r[MAXSIZE];
    int length;
} SqList;

void HeapAdjust(SqList *L, int s, int m) {
    RecordType rc = L->r[s];
    int j;
    for (j = 2 * s; j <= m; j = j * 2) {
        if (j < m && L->r[j].key < L->r[j + 1].key)
            j++;
        if (rc.key >= L->r[j].key)
            break;
        L->r[s] = L->r[j];
        s = j;
    }
    L->r[s] = rc;
}

void CreatHeap(SqList *L) {
    int n = L->length;
    for (int i = n / 2; i > 0; i--)
        HeapAdjust(L, i, n);
}

void HeapSort(SqList *L) {
    CreatHeap(L);
    for (int i = L->length; i > 1; i--) {
        RecordType temp = L->r[1];
        L->r[1] = L->r[i];
        L->r[i] = temp;
        HeapAdjust(L, 1, i - 1);
    }
}

void PrintSqList(SqList *L) {
    for (int i = 1; i <= L->length; i++)
        printf("%d ", L->r[i].key);
    printf("\n");
}

int main() {
    SqList L;
    L.r[1].key = 49;
    L.r[2].key = 38;
    L.r[3].key = 65;
    L.r[4].key = 97;
    L.r[5].key = 76;
    L.r[6].key = 13;
    L.r[7].key = 27;
    L.r[8].key = 49;
    L.length = 8;

    printf("Before sorting: ");
    PrintSqList(&L);

    HeapSort(&L);

    printf("After sorting:  ");
    PrintSqList(&L);

    return 0;
}