#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

CircularQueue* createQueue(int n)
{
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->capacity = n;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->arr = (int*)malloc(n * sizeof(int));
    return q;
}

int isFull(CircularQueue* q)
{
    return q->size == q->capacity;
}

int isEmpty(CircularQueue* q)
{
    return q->size == 0;
}

void enqueue(CircularQueue* q, int value)
{
    if (isFull(q))
        return;

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
}

void dequeue(CircularQueue* q)
{
    if (isEmpty(q))
        return;

    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

void display(CircularQueue* q)
{
    int i;
    int index = q->front;

    for(i = 0; i < q->size; i++)
    {
        printf("%d ", q->arr[index]);
        index = (index + 1) % q->capacity;
    }
}

int main()
{
    int n, m, i, x;

    scanf("%d", &n);

    CircularQueue* q = createQueue(n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(q, x);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
        dequeue(q);

    display(q);

    return 0;
}