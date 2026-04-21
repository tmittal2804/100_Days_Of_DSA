#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minKey(int* key, int* visited, int n) {
    int min = INT_MAX, minIndex = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

  
    int** graph = malloc((n + 1) * sizeof(int*));
    for (int i = 1; i <= n; i++) {
        graph[i] = malloc((n + 1) * sizeof(int));
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int* key = malloc((n + 1) * sizeof(int));
    int* visited = calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
    }

    key[1] = 0; 

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key, visited, n);
        visited[u] = 1;

        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}