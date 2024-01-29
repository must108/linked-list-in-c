#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createNode(int data){
    Node* temp = malloc(sizeof(Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = temp;

    return temp;
}

Node* insertBeginning(Node* head, int data){
    Node* temp = createNode(data);

    if(head == NULL){
        head = temp;
        temp->next = head;
    } else {
        Node* last = head;

        while(last->next != head){
            last = last->next;
        }
        temp->next = head;
        temp->prev = last;
        last->next = temp;
        temp->next->prev = temp;
    }

    head = temp;
    return head;
}

int main(){
    // TODO: work on this
}