#include <iostream>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} INODE, *LinkList;

INODE* GetElem(LinkList &L, int i, int &e)
{
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
    {
        return L;
    }

    if (i < 0)
    {
        return nullptr;
    }   

    while (p  && j < i)
    {
        p = p->next;
        j++;
    }

    return p;
}
// 按位序插入()
LinkList LIST_HEADInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = nullptr;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

// Init a no header LinkList
bool InitList(LinkList &L)
{
    L = nullptr;
    return true;
}

// Init a header LinkList
bool InitListWithHead(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if (L == nullptr)
    {
        return false;
    }
    L->next = nullptr;
    return true;
}

bool ListHeaderEmpty(LinkList L)
{
    if (L->next == nullptr)
    {
        return true;
    }
    return false;
}   

// check list whether is empty
bool ListEmpty(LinkList L)
{
    if (L == nullptr)
    {
        return true;
    }
    return false;
}


bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1) {
        return false;
    }

    LNode *p;
    int j = 0;
    p = L;
    while (p != nullptr && j < i-1) {
        p = p->next;
        j++;
    }

    if (p == nullptr) {
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// insert value before p node
bool InsertPriorNode(LNode *p, int e) {
    if (p == nullptr) {
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool listDelete(LinkList &L, int i){
    if (i < 1){
        return false;
    }

    LNode *p;
    int j = 0;
    p = L;
    while (p != nullptr && j < i-1)
    {
        p = p->next;
        j++;
    }

    if (p == nullptr) {
        return false;
    }

    if (p->next == nullptr){
        return false;
    }

    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

bool DeleteNode(LNode *p) {
    if (p == nullptr){
        return false;
    }

    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}

LNode * GetElem2(LinkList L, int i){
    if (i < 0) {
        return nullptr;
    }
    LNode *p;
    int j = 0;
    p = L;
    while (p != nullptr && j < i)
    {
        p = p->next;
        j++;
    }

    return p;
}

void printList(LinkList L){
    LNode *p = L->next;
    while (p != nullptr)
    {
        std::cout << p->data << std::endl;
        p = p->next;
    }
}

int main()
{
    LinkList L;
    InitListWithHead(L);
    printList(L);
    ListInsert(L, 1, 3);
    printList(L);
    ListInsert(L, 1, 4);
    printList(L);
    listDelete(L, 1);
    printList(L);
    return 0;
}