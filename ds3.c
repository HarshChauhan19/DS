#include <stdio.h>
#include <string.h>

// Define a structure to store student information
struct Student {
    char name[50];
    int roll;
    float marks;
};

// Function to input student information
void inputStudent(struct Student *student) {
    printf("Enter student name: ");
    scanf(" %s", student->name);
    printf("Enter student roll number: ");
    scanf("%d", &student->roll);
    printf("Enter student marks: ");
    scanf("%f", &student->marks);
}

// Function to display student information
void displayStudent(const struct Student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->roll);
    printf("Marks: %.2f\n", student->marks);
}

int main() {
    struct Student students[10];
    int choice;
    int n;

    printf("Enter Numbers of Student : ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        printf("Enter information for student %d:\n", i + 1);
        inputStudent(&students[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display student information\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student number (1-10): ");
                int studentNumber;
                scanf("%d", &studentNumber);
                if (studentNumber >= 1 && studentNumber <= 10) {
                    printf("Student %d Information:\n", studentNumber);
                    displayStudent(&students[studentNumber - 1]);
                } else {
                    printf("Invalid student number. Please enter a number between 1 and 10.\n");
                }
                break;
            case 2:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
