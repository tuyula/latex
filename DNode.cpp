#include <iostream>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;


bool InitDLinkList(DLinkList &L) {
    L = (DLinkList)malloc(sizeof(DLinkList));
    if (L == nullptr) {
        return false;
    }

    L->prior = NULL;
    L->next = NULL;
    return true;
}

bool InsertNextDNode(DNode *p, DNode *s){
    if (p == NULL || s== NULL) {
        return false;
    }

    s->next = p->next;
    s->prior = p;
    p->next = s;
    return true;
}

bool DestoryDList(DLinkList &L) {
    while (L->next != NULL) {
        DNode *p = L;
        L = L->next;
        free(p);
    }
    free(L);
    return true;    
}

void PrintDList(DLinkList L) {
    DNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        std::cout << p->data << std::endl;
    }
    return;
}

int main() {
    DLinkList L;
    InitDLinkList(L);
    PrintDList(L);
    DestoryDList(L);
    return 0;
}