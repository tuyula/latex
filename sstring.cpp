#define MAXLEN 20

typedef struct
{
    char data[MAXLEN];
    int len;
} SString;


bool SubString(SString &Sub, SString S, int pos, int len)
{
    if (pos + len - 1 > S.len)
    {
        return false;
    }
    for (int i = pos; i < pos + len; i++)
    {
        Sub.data[i - pos + 1] = S.data[i];
    }
    Sub.len = len;
    return true;
}

int StrCompare(SString S, SString T)
{
    for (int i = 1; i <= S.len && i <= T.len; i++)
    {
        if (S.data[i] != T.data[i])
        {
            return S.data[i] - T.data[i];
        }
    }
    return S.len - T.len;
}

int Index(SString S, SString T)
{
    int i = 1, n = S.len, m = T.len;
    SString sub;
    while (i <= n - m + 1)
    {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0)
        {
            ++i;
        }
        else
        {
            return i;
        }
    }
    return 0;
}