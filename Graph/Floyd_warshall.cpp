#include <iostream>
using namespace std;
#define MAXV 500
typedef struct
{
    int edges[MAXV][MAXV];
    int degrees[MAXV];
    bool visited[MAXV];
    int nedges, nvertices;
} Graph;

void floyd_warshall(Graph *g)
{
    for(int k=0; k<g->nvertices; k++) {
        for(int i=0; i<g->nvertices; i++) {
            for(int j=0; j<g->nvertices; j++) {
                g->edges[i][j] = g->edges[i][j] | (g->edges[i][k] & g->edges[k][j]);
            }
        }
    }
    for (int i = 0; i < g->nvertices; i++)
    {
        for (int j = 0; j < g->nvertices; j++)
        {
            cout << g->edges[i][j] << " ";
        }
        cout << endl;

    }


}

int main()
{
    Graph g;
    cin >> g.nvertices >> g.nedges;

    for (int j = 0; j < g.nedges; j++)
    {
        int start, finish;
        cin >> start >> finish;
        g.edges[start][finish] = 1;
    }

    floyd_warshall(&g);
    cout << endl;
}
