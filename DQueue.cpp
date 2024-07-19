#include <iostream>
#include <stdlib.h>

#define Maxsize 50

typedef struct LinkNode
{
    int data;
    LinkNode *next;
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

void EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return;
}

bool DeQueue(LinkQueue &Q, int &x)
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


int main(){
    LinkQueue Q;
    InitQueue(Q);
    return 0;
}