#include <stdio.h>
#include <stdbool.h>

#define MAX 100
bool dfs(int node, int V, int adj[MAX][MAX], bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) { // edge exists
            // If not visited
            if (!visited[i]) {
                if (dfs(i, V, adj, visited, recStack))
                    return true;
            }
            // If already in recursion stack → cycle
            else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[node] = false; 
    return false;
}
bool isCyclic(int V, int adj[MAX][MAX]) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    if (isCyclic(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}