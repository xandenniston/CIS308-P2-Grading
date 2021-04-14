// change function prototypes if students are different
// NOTE: partial function signatures are given in instructions. In most cases if these partial functions are modified it is wrong
// If parameters are specified, they shouldn't be changed, removed, or added to.
//

#ifndef CIS308P2GRADING_LINKEDLIST_H
#define CIS308P2GRADING_LINKEDLIST_H

typedef struct node {
    int data;
    struct node* next;
} Node, node;

void Push(Node** headRef, int newData);
int Pop(Node** headRef);
int Count(Node* head, int searchFor);
int GetNth(Node* head, int index);
void DeleteList(Node** head);
void InsertNth(Node** head, int index, int data);
void MoveNode(Node** destRef, Node** sourceRef);
void Reverse(Node** headRef);
void RecursiveReverse(Node** headRef);



#endif //CIS308P2GRADING_LINKEDLIST_H
