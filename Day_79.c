#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

typedef struct {
    int v, w;
} Edge;

Edge graph[MAX][100];   
int graphSize[MAX];

int dist[MAX];
int visited[MAX];

int getMin(int n) {
    int min = INT_MAX, index = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);


    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][graphSize[u]].v = v;
        graph[u][graphSize[u]++].w = w;

        graph[v][graphSize[v]].v = u; // undirected
        graph[v][graphSize[v]++].w = w;
    }

    int source;
    scanf("%d", &source);

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int i = 1; i <= n; i++) {
        int u = getMin(n);
        if (u == -1) break;

        visited[u] = 1;

        for (int j = 0; j < graphSize[u]; j++) {
            int v = graph[u][j].v;
            int w = graph[u][j].w;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}