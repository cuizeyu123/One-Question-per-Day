#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPQ(int capacity) {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->data = (int*)malloc((capacity + 1) * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(PriorityQueue *pq, int val) {
    if (pq->size >= pq->capacity) {
        printf("Queue is full!\n");
        return;
    }
    pq->size++;
    pq->data[pq->size] = val;
    int i = pq->size;

    while (i > 1 && pq->data[i] < pq->data[i / 2]) {
        swap(&pq->data[i], &pq->data[i / 2]);
        i /= 2;
    }
}

int pop(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Queue is empty!\n");
        return -1; 
    }
    int minVal = pq->data[1];
    pq->data[1] = pq->data[pq->size];
    pq->size--;

    int i = 1;
    while (2 * i <= pq->size) {
        int child = 2 * i;
        if (child < pq->size && pq->data[child + 1] < pq->data[child]) {
            child++;
        }
        if (pq->data[i] <= pq->data[child]) {
            break;
        }
        swap(&pq->data[i], &pq->data[child]);
        i = child;
    }
    return minVal; 
}

void destroyPQ(PriorityQueue *pq) {
    free(pq->data);
    free(pq);
}

int main() {

    int a[] = {5, 2, 8, 4, 3, 6, 9, 7, 1, 10};
    int n = 10;
    int k = 3;

    PriorityQueue *pq = createPQ(n);

    printf("原始列表: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
        push(pq, a[i]);
    }
    printf("\n");
    int kthSmallest;
    for (int i = 0; i < k; i++) {
        kthSmallest = pop(pq);
    }

    printf("第 %d 小的元素是: %d\n", k, kthSmallest);

    destroyPQ(pq);
    return 0;
}
