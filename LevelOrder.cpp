#include <iostream>
#include <stdlib.h>


typedef struct BITNode
{
    char data;
    struct BITNode *lchild, *rchild;
} BITNode, *BiTree;

typedef struct LinkNode
{
    BiTree data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
    return;
}

bool IsEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    return false;
}

void EnQueue(LinkQueue &Q, BiTree x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return;
}

bool DeQueue(LinkQueue &Q, BiTree &x)
{
    if (Q.front == Q.rear)
    {
        return false;
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
    {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}

void LevelOrder(BiTree &T)
{
    LinkQueue Q;
    InitQueue(Q);
    BiTree p = T;
    EnQueue(Q, p);
    while (!IsEmpty(Q))
    {
        DeQueue(Q, p);
        std::cout << p->data << std::endl;
        if (p->lchild != NULL)
        {
            EnQueue(Q, p->lchild);
        }
        if (p->rchild != NULL)
        {
            EnQueue(Q, p->rchild);
        }
    }

    return;
}
