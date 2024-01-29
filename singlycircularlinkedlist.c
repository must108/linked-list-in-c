#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
}

Node* createNode(int data){
    Node* temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

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
        last->next = temp;
    }

    head = temp;
    return head;
}

Node* insertEnd(Node* head, int data){
    Node* temp = createNode(data);

    if(head == NULL){
        head = temp;
        temp->next = head;
    } else {
        Node* walker = head;

        while(walker->next != head){
            walker = walker->next;
        }
        temp->next = head;
        walker->next = temp;
    }

    return head;
}

Node* insertPlace(Node* head, int data, int place){
    Node* temp = createNode(data);

    if(head == NULL){
        head = temp;
        temp->next = head;
    } else {
        Node* walker = head;

        for(int i = 0; i < place - 1; i++){
            walker = walker->next;
        }

        if(walker->next != head){
            temp->next = walker->next;
            walker->next = temp;
        }
    }

    return head;
}

Node* deleteItem(Node* head, int data){
// TODO: work on this 
}

int main(){
// TODO: work on this!
}