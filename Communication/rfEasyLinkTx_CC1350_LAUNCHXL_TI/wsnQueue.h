
#include <xdc/std.h>
typedef struct DataFrame
{
    uint8_t data[30];
}DataFrame;

struct Queue
{
    int front, rear;
    int size, capacity;
    DataFrame* array;
};
struct Queue* createQueue(int capacity);

int isFull(struct Queue* queue);
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, DataFrame item);
DataFrame dequeue(struct Queue* queue);
DataFrame front(struct Queue* queue);
DataFrame rear(struct Queue* queue);
