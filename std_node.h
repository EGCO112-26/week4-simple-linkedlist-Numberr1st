#ifndef node_h
#define node_h

struct student_node {
    long student_id;
    char name[100];
    struct student_node *next;
};

typedef struct student_node* StudentPtr;

#endif /* node_h */
