
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


typedef struct {
    int size;
    struct Node* head;  // peek
    struct Node* tail;  // where to insert
} Queue;


Queue* createQueue();
Queue* enqueue(Queue* queue, int data);
struct Node* peek(Queue* queue);
struct Node* dequeue(Queue* queue);
void printQueue(Queue* queue);


int main(){
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);

    struct Node* head = peek(queue);
    printQueue(queue);
    return 0;
}


struct Node* createNode(int data, struct Node* next);
void printNode(struct Node* node);


// Queue Functions
Queue* createQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

Queue* enqueue(Queue* queue, int data){
    struct Node* node = createNode(data, NULL);

    if(!queue->head){
        queue->head = node;    
    } else if(!queue->tail) {
        queue->head->next = node;
        queue->tail = node;
    } else {
        queue->tail->next = node; 
        queue->tail = node;
    }
    
    ++queue->size;
    return queue;
}

void printQueue(Queue* queue){
    printNode(queue->head);
    printf("\n");
}

struct Node* peek(Queue* queue){
    return queue->head;
}


// Node Functions
struct Node* createNode(int data, struct Node* next){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void printNode(struct Node* node){
    printf("%d ", node->data);
    if(node->next){
        printNode(node->next);
    }
}

