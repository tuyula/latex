#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define InitSize 10

typedef struct
{
    int *data;
    int length;
    int maxSize;
} sqList;

void initList(sqList &L)
{
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.maxSize = InitSize;
    L.length = 0;
}

void IncreaseSize(sqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.maxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.maxSize += len;
    free(p);
}

void ListInsert(sqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
    {
        printf("Error\n");
        return;
    }
    if (L.length >= L.maxSize)
    {
        IncreaseSize(L, 10);
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
}

bool ListDelete(sqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
    {
        printf("Error\n");
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

int GetElem(sqList L, int i)
{
    return L.data[i - 1];
}

int LocateElem(sqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

int printList(sqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    return 0;
}



int main()
{
    sqList L;
    initList(L);
    printList(L);
    ListInsert(L, 1, 1);
    printList(L);
    ListInsert(L, 1, 2);
    printList(L);
    ListInsert(L, 1, 3);
    printList(L);
    int e;
    ListDelete(L, 1, e);
    printList(L);
    return 0;
}