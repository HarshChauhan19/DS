#include <stdio.h>
#define MAX_SIZE 100
// Define a stack
struct Stack {
int items[MAX_SIZE];
int top;
};
// Function to initialize a stack
void initialize(struct Stack* stack) {
stack->top = -1;
}
// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
return stack->top == -1;
}
// Function to check if the stack is full
int isFull(struct Stack* stack) {
return stack->top == MAX_SIZE - 1;
}
// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
if (isFull(stack)) {
printf("Stack overflow!\n");
return;
}
stack->items[++stack->top] = item;
}
// Function to pop an element from the stack
int pop(struct Stack* stack) {
if (isEmpty(stack)) {
printf("Stack underflow!\n");
return -1;
}
return stack->items[stack->top--];
}
int main() {
struct Stack stack;
initialize(&stack);
push(&stack, 10);
push(&stack, 20);
push(&stack, 30);
printf("Popped item: %d\n", pop(&stack));
printf("Popped item: %d\n", pop(&stack));
return 0;
}