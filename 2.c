#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the stack

int stack[MAX_SIZE]; // Stack array
int top = -1; // Top of the stack, initialized to -1 when empty

// Function to push an element onto the stack
void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push element onto a full stack.\n");
    } else {
        stack[++top] = element; // Increment top and add the element
    }
}

// Function to pop an element from the stack and return it
int pop() {
    if (top == -1) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return -1; // Return a sentinel value (e.g., -1) to indicate an error
    } else {
        return stack[top--]; // Return the element and decrement top
    }
}

// Function to check if the stack is empty
bool isEmpty() {
    return (top == -1);
}

int main() {
    // Example usage of stack operations
    push(10);
    push(20);
    push(30);
    
    printf("Top element: %d\n", stack[top]); // Should print 30
    
    printf("Popped element: %d\n", pop()); // Should print 30
    printf("Popped element: %d\n", pop()); // Should print 20
    
    printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No"); // Should print "No"
    
    return 0;
}
