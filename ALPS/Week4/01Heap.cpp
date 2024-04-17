#include<stdio.h>
#include<stdlib.h>

typedef struct {
   int value;
} element;

typedef struct {
   element** arr;
   int size;
} vector;

void push_back(vector* v, element item) {
   element* temp = (element*)malloc(sizeof(element));
   *temp = item;
   v->arr = (element**)realloc(v->arr, sizeof(element*) * sizeof(v->size + 1));
   *(v->arr + v->size) = temp;
   v->size++;
}

//MAX_heap
typedef struct {
   int size;
   element** arr;
} Heap;

void push(Heap* heap, element item) {
   heap->size++;
   int index = heap->size;

   element* temp = (element*)malloc(sizeof(element));
   *temp = item;
   heap->arr = (element**)realloc(heap->arr, sizeof(element*) * (heap->size));

   while (index != 1 && (*(heap->arr + index / 2 - 1))->value < item.value) {
      *(heap->arr + index - 1) = *(heap->arr + index / 2 - 1);
      index /= 2;
   }
   *(heap->arr + index - 1) = temp;
}

void top(Heap* heap) {
   if (heap->size == 0) printf("empty\n");
   else printf("%d\n", (*(heap->arr))->value);
}

void pop(Heap* heap) {
   if (heap->size == 0) {
      printf("empty\n");
      return;
   }
   int parent = 1, child = 2;
   heap->size--;
   element* temp = *(heap->arr + heap->size);
   while (child <= heap->size) {
      if (child < heap->size && (*(heap->arr + child - 1))->value < (*(heap->arr + child))->value) child++;
      if (temp->value >= (*(heap->arr + child))->value) break;
      *(heap->arr + parent - 1) = *(heap->arr + child - 1);
      parent = child;
      child *= 2;
   }
   *(heap->arr+parent-1) = temp;
}

void Free(Heap* heap) {
   for (int i = 0; i < heap->size; i++) free(*(heap->arr + i));
   free(heap->arr);
}

int main() {
   int tf = 0, order, temp;
   Heap pq = { 0, };
   while (1) {
      printf("1.push x\n2.pop\n3.top\n4.종료\n");
      scanf("%d", &order);
      switch (order) {
      case 1:
         scanf("%d", &temp);
         push(&pq, { temp });
         break;
      case 2:
         pop(&pq);
         break;
      case 3:
         top(&pq);
         break;
      default:
         tf = 1;
         break;
      }
      if (tf) break;
   }
   Free(&pq);
}