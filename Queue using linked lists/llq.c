#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
    int data;
    struct node* next;
};

struct queue{
    struct node* front;
    int size;
    struct node* rear;
};

int isEmpty(struct queue* q){
    return q->front == NULL;
}

void enqueue(struct queue* q,int data){
    q->size++;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(q)){
        q->front = q->rear = newNode;
        printf("%d is enqueued\n",data);
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    printf("%d is enqueued\n",data);
}

void dequeue(struct queue* q){
 
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        return;
    }
    q->size--;
    struct node* temp = q->front;
    q->front = q->front->next;
    printf("%d is dequeued\n",temp->data);
    free(temp);
}

int size(struct queue* q){
    return q->size;
}

int front(struct queue* q){
    if(isEmpty(q)){
        return INT_MIN;
    }
    return q->front->data;
}

void display(struct queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = q->front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


struct queue* createQueue(struct queue* q){
    struct queue* qu = (struct queue*)malloc(sizeof(struct queue));
    qu->front = NULL;
    qu->rear = NULL;
    qu->size = 0;
    return qu;
}

int main(){
    struct queue* q = createQueue(q);
    enqueue(q,30);
    printf("The size of queue is %d\n",size(q));
    enqueue(q,90);
    enqueue(q,70);
    enqueue(q,40);
    printf("The size of queue is %d\n", size(q));
    display(q);
    dequeue(q);
    dequeue(q);
    printf("The size of queue is %d\n", size(q));
    dequeue(q);
    printf("The size of queue is %d\n", size(q));
    display(q);
}

