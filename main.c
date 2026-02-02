#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_node.h"

// Function to insert a new student node at the end of the list
StudentPtr insert_student(StudentPtr head, long id, const char* name) {
    StudentPtr new_node = (StudentPtr)malloc(sizeof(struct student_node));
    new_node->student_id = id;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    
    // If list is empty, return new node as head
    if (head == NULL) {
        return new_node;
    }
    
    // Otherwise, traverse to the end and add new node
    StudentPtr temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    
    return head;
}

// Function to print all students in the linked list
void print_students(StudentPtr head) {
    StudentPtr temp = head;
    while (temp != NULL) {
        printf("%ld %s\n", temp->student_id, temp->name);
        temp = temp->next;
    }
}

// Function to delete all nodes and free memory
void delete_all(StudentPtr head) {
    StudentPtr temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(int argc, const char * argv[]) {
    StudentPtr head = NULL;
    
    // Check if we have arguments (argc must be odd: program_name + pairs of id/name)
    if (argc < 3 || argc % 2 == 0) {
        printf("Usage: %s <student_id> <name> [<student_id> <name> ...]\n", argv[0]);
        return 1;
    }
    
    // Process command line arguments in pairs (id, name)
    for (int i = 1; i < argc; i += 2) {
        long student_id = atol(argv[i]);      // Convert string to long
        const char* name = argv[i + 1];       // Get name
        head = insert_student(head, student_id, name);
    }
    
    // Print all students
    print_students(head);
    
    // Clean up: delete all nodes
    delete_all(head);
    
    return 0;
}
