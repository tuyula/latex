#include <vector> 

#define MAX_VERTEX_NUM 100

typedef struct graph
{
    char vec[MAX_VERTEX_NUM];
    int mat[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
} MGraph;


typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
} ArcNode;

typedef struct VNode
{
    char data;
    ArcNode *firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;


bool adjacent(MGraph *G, int x, int y)
{
    return G->mat[x][y] == 1;
}

bool adjacent(ALGraph *G, int x, int y)
{
    ArcNode *p = G->vertices[x].firstarc;
    while (p)
    {
        if (p->adjvex == y)
            return true;
        p = p->next;
    }
    return false;
}

std::vector<int> Neighbors(ALGraph *G, int x)
{
    std::vector<int> result;
    ArcNode *p = G->vertices[x].firstarc;
    while (p)
    {
        result.push_back(p->adjvex);
        p = p->next;
    }
    return result;
}

std::vector<int> Neighbors(MGraph *G, int x)
{
    std::vector<int> result;
    for (int i = 0; i < G->vexnum; i++)
    {
        if (G->mat[x][i] == 1)
            result.push_back(i);
    }
    return result;
}

bool insertVertex(MGraph *G, char x)
{
    if (G->vexnum == MAX_VERTEX_NUM)
        return false;
    G->vec[G->vexnum] = x;
    G->vexnum++;
    return true;
}

bool insertVertex(ALGraph *G, char x)
{
    if (G->vexnum == MAX_VERTEX_NUM)
        return false;
    G->vertices[G->vexnum].data = x;
    G->vexnum++;
    return true;
}

bool DeleteVertex(MGraph *G, char x)
{
    int i, j;
    for (i = 0; i < G->vexnum; i++)
    {
        if (G->vec[i] == x)
            break;
    }
    if (i == G->vexnum)
        return false;
    for (j = 0; j < G->vexnum; j++)
    {
        if (G->mat[i][j] == 1)
            G->arcnum--;
        if (G->mat[j][i] == 1)
            G->arcnum--;
        for (int k = i; k < G->vexnum - 1; k++)
        {
            G->mat[k][j] = G->mat[k + 1][j];
            G->mat[j][k] = G->mat[j][k + 1];
        }
    }
    for (int k = i; k < G->vexnum - 1; k++)
    {
        G->vec[k] = G->vec[k + 1];
    }
    G->vexnum--;
    return true;
}

bool DeleteVertex(ALGraph *G, char x)
{
    int i, j;
    for (i = 0; i < G->vexnum; i++)
    {
        if (G->vertices[i].data == x)
            break;
    }
    if (i == G->vexnum)
        return false;
    for (j = 0; j < G->vexnum; j++)
    {
        ArcNode *p = G->vertices[j].firstarc;
        ArcNode *q = NULL;
        while (p)
        {
            if (p->adjvex == i)
            {
                if (q)
                    q->next = p->next;
                else
                    G->vertices[j].firstarc = p->next;
                delete p;
                G->arcnum--;
            }
            q = p;
            p = p->next;
        }
    }
    for (int k = i; k < G->vexnum - 1; k++)
    {
        G->vertices[k] = G->vertices[k + 1];
    }
    G->vexnum--;
    return true;
}