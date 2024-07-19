#include <iostream>
#include <stdlib.h>

#define MaxSize 50
typedef struct
{
    int data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &s)
{
    s.top = -1;
}

bool PushStack(SqStack &s, int x)
{
    if (s.top == MaxSize - 1)
    {
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

bool PopStack(SqStack &s, int &x)
{
    if (s.top == -1)
    {
        return false;
    }
    x = s.data[s.top--];
    return true;
}

bool GetTop(SqStack s, int &x)
{
    if (s.top == -1)
    {
        return false;
    }
    x = s.data[s.top];
    return true;
}

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode, *LinkStack;

void InitStack(LinkStack &s)
{
    s = (LinkStack)malloc(sizeof(LinkNode));
    s->next = NULL;
}

bool PushStack(LinkStack &s, int x)
{
    LinkNode *p;
    p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = x;
    p->next = s->next;
    s->next = p;
    return true;
}

bool PopStack(LinkStack &s, int &x)
{
    if (s->next == NULL)
    {
        return false;
    }
    LinkNode *p = s->next;
    x = p->data;
    s->next = p->next;
    free(p);
    return true;
}

int main()
{
    SqStack s;
    InitStack(s);
    return 0;
}