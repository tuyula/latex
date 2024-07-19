#include <stdio.h>

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

bool BrackerCheck(char str[])
{
    SqStack s;
    InitStack(s);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            PushStack(s, str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (s.top == -1)
            {
                return false;
            }
            int e;
            PopStack(s, e);
            if (str[i] == ')' && e != '(')
            {
                return false;
            }
            if (str[i] == ']' && e != '[')
            {
                return false;
            }
            if (str[i] == '}' && e != '{')
            {
                return false;
            }
        }
    }
    if (s.top == -1)
    {
        return true;
    }
    return false;
}

int main()
{
    char str[] = "((()))";
    if (BrackerCheck(str))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}