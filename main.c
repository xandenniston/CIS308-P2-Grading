/*Unit tests for each function.
 *If a function has an infinte loop, the test can be commented out and marked as a failure.
 *Some modifications can be made to account for function names and return types if they weren't specified in instructions.
 */
#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>

void checkPush();
void secretPrint(Node* n);
void checkPop();
void checkCount();
void checkGetNth();
void checkDelete();
void checkInsert();
void checkMove();
void checkReverse();

int main() {
    checkPush();
    checkPop();
    checkCount();
    checkGetNth();
    checkDelete();
    checkInsert();
    checkMove();
    checkReverse();
    return 0;
}

void secretPrint(Node* n){
    while (n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void checkPush(){
    printf("Push:\n");
    Node* n = malloc(sizeof(Node));
    n->data  = 3;
    n->next = NULL;

    Push(&n, 2);
    Push(&n, 1);

    int flag = 0;
    int counter =1;
    Node *temp = n;
    while(temp != NULL){
        if(temp->data != counter) { flag = 1; }
        temp = temp->next;
        counter++;
    }
    if(flag == 0){
        printf("Push is correct\n");
    }
    else{
        printf("Push is incorrect. Output below\n");
        secretPrint(n);
    }
    printf("Press enter to continue\n");
    getchar();

}

void checkPop(){
    printf("Pop:\n");
    Node *n1 = malloc(sizeof(Node));
    n1->data = 1;
    n1->next = malloc(sizeof(Node));
    n1->next->data = 2;
    n1->next->next = malloc(sizeof(Node));
    n1->next->next->data = 3;
    n1->next->next->next = NULL;
    int n = Pop(&n1);

    if(n != 1){
        printf("Pop does not correctly return the number\n");
    }

    int flag = 0;
    int counter =2;
    Node *temp = n1;
    while(temp != NULL){
        if(temp->data != counter) { flag = 1; }
        temp = temp->next;
        counter++;
    }
    if(flag == 0){
        printf("Pop list is correct\n");
    }
    else{
        printf("Pop list is incorrect. Output below\n");
        secretPrint(n1);
    }
    printf("Press enter to continue\n");
    getchar();

}

void checkCount(){
    printf("Count:\n");
    Node *n1 = malloc(sizeof(Node));
    n1->data = 1;
    n1->next = malloc(sizeof(Node));
    n1->next->data = 2;
    n1->next->next = malloc(sizeof(Node));
    n1->next->next->data = 1;
    n1->next->next->next = NULL;


    if(Count(n1, 1)== 2){
        printf("Count is correct\n");
    }
    else{
        printf("Count is incorrect.\nExpected: 2\nWas: %d\n", Count(n1, 1));
    }
    printf("Press enter to continue\n");
    getchar();
}

void checkGetNth(){
    printf("GetNth:\n");
    Node *n1 = malloc(sizeof(Node));
    n1->data = 1;
    n1->next = malloc(sizeof(Node));
    n1->next->data = 2;
    n1->next->next = malloc(sizeof(Node));
    n1->next->next->data = 3;
    n1->next->next->next = NULL;

    if(GetNth(n1, 0)!= 1){
        printf("0th index incorrect\n");
    }
    else if(GetNth(n1, 1)!= 2){
        printf("1st index incorrect\n");
    }
    else if(GetNth(n1, 2)!= 3){
        printf("2nd index incorrect\n");
    }
    else{
        printf("getNth correct\n");
    }

    printf("Press enter to continue\n");
    getchar();
}

void checkDelete(){
    printf("Delete:\n");
    Node *n1 = malloc(sizeof(Node));
    n1->data = 1;
    n1->next = malloc(sizeof(Node));
    n1->next->data = 2;
    n1->next->next = malloc(sizeof(Node));
    n1->next->next->data = 1;
    n1->next->next->next = NULL;

    DeleteList(&n1);
    if(n1!= NULL){
        printf("Delete List incorrect\n");
    }
    else{
        printf("Delete List correct\n");
    }

    printf("Press enter to continue\n");
    getchar();

}

void checkInsert(){
    printf("InsertNode:\n");
    Node *n1 = malloc(sizeof(Node));
    n1->data = 1;
    n1->next = malloc(sizeof(Node));
    n1->next->data = 3;
    n1->next->next = NULL;

    InsertNth(&n1,1,2);
    InsertNth(&n1,0,0);
    int flag = 0;
    int counter =0;
    Node *temp = n1;
    while(temp != NULL){
        if(temp->data != counter) { flag = 1; }
        temp = temp->next;
        counter++;
    }

    counter = 0;

    InsertNth(&n1,4,4);
    temp = n1;
    while(temp != NULL){
        if(temp->data != counter) { flag = 1; }
        temp = temp->next;
        counter++;
    }
    if(flag == 0){
        printf("Insert is correct\n");
    }
    else{
        printf("Insert is incorrect. Output below\n");
        secretPrint(n1);
    }
    printf("Press enter to continue\n");
    getchar();

}

void checkMove(){
    printf("MoveNode:\n");

    Node *n1 = malloc(sizeof(Node));
    n1->data = 2;
    n1->next = malloc(sizeof(Node));
    n1->next->data = 3;
    n1->next->next = NULL;

    Node *n2 = malloc(sizeof(Node));
    n2->data = 1;
    n2->next = malloc(sizeof(Node));
    n2->next->data = 3;
    n2->next->next = NULL;

    MoveNode(&n1, &n2);

    int flag = 0;
    int counter =1;
    Node *temp = n1;
    while(temp != NULL){
        if(temp->data != counter) { flag = 1; }
        temp = temp->next;
        counter++;
    }
    if(flag == 0){
        printf("Move is correct\n");
    }
    else{
        printf("Move is incorrect. Output below\n");
        secretPrint(n1);
    }
    printf("Press enter to continue\n");
    getchar();
}

void checkReverse(){
    printf("Reverse:\n");
    Node *n1 = malloc(sizeof(Node));
    n1->data = 1;
    n1->next = malloc(sizeof(Node));
    n1->next->data = 2;
    n1->next->next = malloc(sizeof(Node));
    n1->next->next->data = 3;
    n1->next->next->next = NULL;

    Reverse(&n1);
    //RecursiveReverse(&n1);
    int flag = 0;
    int counter =3;
    Node *temp = n1;
    while(temp != NULL){
        if(temp->data != counter) {
            flag = 1;
        }
        temp = temp->next;
        counter--;
    }
    if(flag == 0){
        printf("Reverse list is correct\n");
    }
    else{
       printf("Reverse list is incorrect. Output below\n");
        secretPrint(n1);
    }
}