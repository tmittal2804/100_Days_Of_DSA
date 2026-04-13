#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Node {
    int data;
    struct Node* next;
};
int visited[MAX];

void dfs(struct Node* adj[], int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            dfs(adj, neighbor);
        }
        temp = temp->next;
    }
}

int main() {
    int n, edges, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    struct Node* adj[MAX];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = v;
        newNode->next = adj[u];
        adj[u] = newNode;

        struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
        newNode2->data = u;
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);
    printf("DFS Traversal: ");
    dfs(adj, s);
    return 0;
}