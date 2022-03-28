#include <bits/stdc++.h>
using namespace std;
#define MAXV 500
typedef struct
{
    int edges[MAXV][MAXV];
    int degrees[MAXV];
    bool visited[MAXV];
    int nedges, nvertices;
} Graph;

void topological_sort(Graph *g, int v, stack<int> &Stack)
{
    g->visited[v] = true;

    for (int i = 0; i < g->nvertices; i++)
    {
        if(g->edges[v][i] == 1 && !g->visited[i]) {
            topological_sort(g, i, Stack);
        }
    }
    Stack.push(v);

}

int main()
{
    Graph g;
    stack<int> Stack;
    g.nvertices = 8;
    g.nedges = 4;
    g.edges[1][2] = 1;
    g.edges[1][5] = 1;
    g.edges[2][5] = 1;
    g.edges[4][7] = 1;
    int startVertex = 0;
    for(int i=0; i<g.nvertices; i++) {
        if(!g.visited[i]) {
            topological_sort(&g, i, Stack);
        }
    }
    while(!Stack.empty()) {
        cout << Stack.top() << endl;
        Stack.pop();
    }

    cout << endl;
}
