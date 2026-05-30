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

void InsertSort(SqList *L) {
    int i, j;
    for (i = 2; i <= L->length; i++) {
        if (L->r[i].key < L->r[i-1].key) {
            L->r[0] = L->r[i];
            for (j = i - 1; L->r[j].key > L->r[0].key; j--) {
                L->r[j+1] = L->r[j];
            }
            L->r[j+1] = L->r[0];
        }
    }
}

void PrintSqList(SqList *L) {
    for (int i = 1; i <= L->length; i++) {
        printf("%d ", L->r[i].key);
    }
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

    InsertSort(&L);

    printf("After sorting:  ");
    PrintSqList(&L);

    return 0;
}
