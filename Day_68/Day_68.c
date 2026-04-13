#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX], front = -1, rear = -1;
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1)
        return -1;
    int x = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return x;
}

int isEmpty() {
    return front == -1;
}

int main() {
    int V, E;
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;
    int topo[MAX];
    while (!isEmpty()) {
        int u = dequeue();
        topo[count++] = u;

        for (int v = 0; v < V; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    enqueue(v);
            }
        }
    }
    if (count != V) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < count; i++)
            printf("%d ", topo[i]);
        printf("\n");
    }

    return 0;
}