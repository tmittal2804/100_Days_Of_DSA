#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node {
    int target, weight;
    struct Node* next;
};


struct HeapNode {
    int v, dist;
};


struct MinHeap {
    int size, capacity;
    int *pos; 
    struct HeapNode **array;
};


struct Node* newNode(int target, int weight) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->target = target;
    n->weight = weight;
    n->next = NULL;
    return n;
}
struct HeapNode* newHeapNode(int v, int dist) {
    struct HeapNode* n = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    n->v = v;
    n->dist = dist;
    return n;
}

void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}


void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct HeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    struct HeapNode* root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}
void dijkstra(struct Node** adj, int V, int src) {
    int dist[V];
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = V;
    minHeap->array = (struct HeapNode**)malloc(V * sizeof(struct HeapNode*));

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
    }

    dist[src] = 0;
    minHeap->array[minHeap->size++] = newHeapNode(src, dist[src]);

    while (minHeap->size != 0) {
        struct HeapNode* heapNode = extractMin(minHeap);
        int u = heapNode->v;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->target;
            if (dist[u] != INT_MAX && dist[u] + temp->weight < dist[v]) {
                dist[v] = dist[u] + temp->weight;
            
                minHeap->array[minHeap->size++] = newHeapNode(v, dist[v]);
                
                
                int i = minHeap->size - 1;
                while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
                    swapHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
                    i = (i - 1) / 2;
                }
            }
            temp = temp->next;
        }
        free(heapNode);
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i) printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int V = 5;
    struct Node* adj[V];
    for (int i = 0; i < V; i++) adj[i] = NULL;

    struct Node* e1 = newNode(1, 10); e1->next = newNode(4, 5); adj[0] = e1;
    
    adj[1] = newNode(2, 1);
    
    dijkstra(adj, V, 0);
    return 0;
}