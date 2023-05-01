#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_NODES 100
int n;                                   // number of nodes
int c[MAX_NODES][MAX_NODES];            // capacity matrix 
int f[MAX_NODES][MAX_NODES];           // flow matrix
int parent[MAX_NODES];                // parent array for BFS
int source, sink;                    // source and sink nodes
// Breadth-First Search
bool bfs()
{
    bool visited[MAX_NODES] = {false};
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = source;
    visited[source] = true;
    parent[source] = -1;
    while (front != rear)
    {
        int u = queue[front++];
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && c[u][v] > f[u][v])
            {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[sink];
}

// Edmonds-Karp Algorithm

int edmonds_karp()
{
    int max_flow = 0;
    while (bfs())
    {
        int path_flow = INT_MAX;
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            path_flow = path_flow < c[u][v] - f[u][v] ? path_flow : c[u][v] - f[u][v];
        }
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            f[u][v] += path_flow;
            f[v][u] -= path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    // read input
    scanf("%d", &n);
    scanf("%d%d", &source, &sink);
    source--;
    sink--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    int max_flow = edmonds_karp();
    printf("Maximum Flow = %d\n", max_flow);
    return 0;
}