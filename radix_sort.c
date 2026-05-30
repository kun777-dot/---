#include <stdio.h>

#define MAXNUM 20
#define RADIX 10
#define MAXBIT 3

typedef int ArrType[RADIX];

typedef struct {
    int keys[MAXBIT + 1];
    int next;
} RecordType;

typedef struct {
    RecordType r[MAXNUM];
    int length;
} SLList;

void Distribute(SLList *L, int i, ArrType f, ArrType e) {
    int j;
    for (j = 0; j < RADIX; j++)
        f[j] = e[j] = 0;
    int p = L->r[0].next;
    while (p != 0) {
        int ord = L->r[p].keys[i];
        if (f[ord] == 0)
            f[ord] = p;
        else
            L->r[e[ord]].next = p;
        e[ord] = p;
        p = L->r[p].next;
    }
}

void Collect(SLList *L, ArrType f, ArrType e) {
    int t, j;
    for (j = 0; j < RADIX && f[j] == 0; j++);
    L->r[0].next = f[j];
    t = e[j];
    while (j < RADIX) {
        j++;
        for (; j < RADIX && f[j] == 0; j++);
        if (j < RADIX && f[j] != 0) {
            L->r[t].next = f[j];
            t = e[j];
        }
    }
    L->r[t].next = 0;
}

void RadixSort(SLList *L) {
    ArrType f, e;
    for (int i = 1; i <= MAXBIT; i++) {
        Distribute(L, i, f, e);
        Collect(L, f, e);
    }
}

void PrintSLList(SLList *L) {
    int p = L->r[0].next;
    while (p != 0) {
        int val = L->r[p].keys[1] + L->r[p].keys[2] * 10 + L->r[p].keys[3] * 100;
        printf("%d ", val);
        p = L->r[p].next;
    }
    printf("\n");
}

int main() {
    int data[] = {278, 109, 63, 930, 589, 184, 505, 269, 8, 83};
    int n = 10;

    SLList L;
    L.length = n;
    for (int i = 1; i <= n; i++) {
        int v = data[i - 1];
        L.r[i].keys[1] = v / 1 % 10;
        L.r[i].keys[2] = v / 10 % 10;
        L.r[i].keys[3] = v / 100 % 10;
        L.r[i].next = i + 1;
    }
    L.r[0].next = 1;
    L.r[n].next = 0;

    printf("Before sorting: ");
    PrintSLList(&L);

    RadixSort(&L);

    printf("After sorting:  ");
    PrintSLList(&L);

    return 0;
}