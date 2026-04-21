#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int* visited, int** graph, int* graphSize) {
    visited[node] = 1;

    for (int i = 0; i < graphSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph, graphSize);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* degree = calloc(n + 1, sizeof(int));
    int edges[m][2];

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    int** graph = malloc((n + 1) * sizeof(int*));
    int* graphSize = calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        graph[i] = malloc(degree[i] * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }


    int* visited = calloc(n + 1, sizeof(int));

    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, graph, graphSize);
            components++;
        }
    }

    printf("%d\n", components);

    return 0;
}