#include <stdio.h>
#include <stdlib.h>

#include "wsnQueue.h"

struct Queue* createQueue(int capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // This is important, see the enqueue
    queue->array = (DataFrame*)malloc(queue->capacity * sizeof(DataFrame));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, DataFrame item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from queue.
// It changes front and size
DataFrame dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return;
    DataFrame item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
DataFrame front(struct Queue* queue)
{
    if (isEmpty(queue))
        return;
    return queue->array[queue->front];
}

// Function to get rear of queue
DataFrame rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return;
    return queue->array[queue->rear];
}
