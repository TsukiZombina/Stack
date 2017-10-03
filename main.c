#include <stdio.h>
#define STACKSIZE 20

struct point {
    float x;
    float y;
};

typedef struct point Point;

struct point_stack {
    Point array[STACKSIZE];
    int stack_pointer;
};

typedef struct point_stack Stack;

void initialize(Stack*);
void push(Stack*, Point*);
void pop(Stack*, Point*);
void top(Stack*, Point*);

void initialize(Stack* s){
    s->stack_pointer = 0;
}

void push(Stack* s, Point* p){
    if(s->stack_pointer < STACKSIZE)
        s->array[s->stack_pointer++] = *p;
}

void pop(Stack* s, Point* p){
    if(s->stack_pointer > 0){
        s->stack_pointer --;
        *p = s->array[s->stack_pointer];
    }
}

void top(Stack* s, Point* p){
    *p = s->array[s->stack_pointer - 1];
}

int main(){
    Stack stack;
    initialize(&stack);
    Point point;
    for(int i = 0; i < 10; i++){
        point.x = i;
        point.y = i + 1;
        push(&stack, &point);
    }

    for(int i = 0; i < 9; i++){
        pop(&stack, &point);
        printf("%f %f\n", point.x, point.y);
    }
    return 0;
}