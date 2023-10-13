#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front;
    int *array;
    int rear;
    int size, capacity;
};

struct queue *createQueue(struct queue *q, int capacity)
{
    struct queue *qu = (struct queue *)malloc(sizeof(struct queue));
    qu->capacity = capacity;
    qu->front = 0;
    qu->array = (int *)malloc(capacity * sizeof(int));
    qu->rear = -1;
    return qu;
}

int isFull(struct queue *q)
{
    return q->size == q->capacity;
}

int isEmpty(struct queue *q)
{
    return q->size = 0;
}

void enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }
    q->size++;
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = data;
    printf("%d is enqueued\n", data);
}

void dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        return;
    }
    q->size--;
    int data = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    printf("%d is dequeued\n", data);
}

int front(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    return q->array[q->front];
}

int main()
{
    struct queue *q = createQueue(q, 5);
    enqueue(q, 45);
    enqueue(q, 54);
    enqueue(q, 67);
}