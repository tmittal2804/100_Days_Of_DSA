#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct QueueNode {
    struct Node* node;
    int hd;
};
struct Queue {
    int front, rear;
    struct QueueNode arr[100];
};
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
}

struct QueueNode dequeue(struct Queue* q) {
    struct QueueNode temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Queue q;
    initQueue(&q);

    int map[200][100];
    int size[200] = {0};
    int offset = 100;

    int minHD = 0, maxHD = 0;

    enqueue(&q, root, 0);

    while (!isEmpty(&q)) {
        struct QueueNode temp = dequeue(&q);
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int index = hd + offset;
        map[index][size[index]++] = curr->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left)
            enqueue(&q, curr->left, hd - 1);
        if (curr->right)
            enqueue(&q, curr->right, hd + 1);
    }
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + offset;
        for (int j = 0; j < size[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}