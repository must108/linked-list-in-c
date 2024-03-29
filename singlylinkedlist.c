#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

// creates a node
Node* createNode(int data){
    Node* temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    
    return temp;
}

// inserts node in beginning of linked list
Node* insertBeginning(Node* head, int data){
    Node* temp = createNode(data);

    if(head == NULL){
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }

    return head;
}

// inserts node in end of linked list
Node* insertEnd(Node* head, int data){
    Node* temp = createNode(data);

    if(head == NULL){
        head = temp;
    } else {
        Node* walker = head;

        while(walker->next != NULL){
            walker = walker->next;
        }

        walker->next = temp;
    }

    return head;
}

// inserts node in a specified index in linked list
Node* insertPlace(Node* head, int data, int place){
    Node* temp = createNode(data);

    if(head == NULL){
        head = temp;
    } else {
        Node* walker = head;

        for(int i = 0; i < place - 1 && walker->next != NULL; i++){
            walker = walker->next;
        }

        temp->next = walker->next;
        walker->next = temp;
    }

    return head;
}

Node* deleteItem(Node* head, int data){
    Node* temp;

    if(head == NULL){
        return head;
    } else if(head->data == data){
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* walker = head;
    while(walker->next != NULL && walker->next->data != data){
        walker = walker->next;
    }

    temp = walker->next;
    walker->next = walker->next->next;
    free(temp);
    return head;
}

void searchItem(Node* head, int data){
    if(head == NULL){
        printf("Item not found\n");
    } else {

        Node* walker = head;

        while(walker->next != NULL && walker->next->data != data){
            walker = walker->next;
        } 

        if(walker->next == NULL){
            printf("Item not found\n");
        } else {
            printf("Item %d found\n", walker->next->data);
        }
    }
}

void displayList(Node* head){
    Node* show = head;

    printf("\n");
    while(show != NULL){
        printf("%d ", show->data);
        show = show->next;
    }
    printf("\n\n");
}

void freeList(Node* head){
    Node* current = head;
    Node* next;

    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}

int main(){

    int command, value, place;
    Node* head = NULL;

    while(1){
        printf("1. Insert in beginning of linked list\n2. Insert in end of linked list\n");
        printf("3. Insert at specific place in linked list\n4. Delete item from linked list\n");
        printf("5. Search for an item in linked list\n6. Display linked list\n");
        printf("7. Exit\n");

        scanf("%d", &command);

        switch(command){
            case 1:
                printf("\nEnter value: ");
                scanf("%d", &value);
                head = insertBeginning(head, value);
                break;
            case 2:
                printf("\nEnter value: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;
            case 3:
                printf("\nEnter value: ");
                scanf("%d", &value);
                printf("\nEnter place: ");
                scanf("%d", &place);
                head = insertPlace(head, value, place);
                break;
            case 4:
                printf("\nEnter item for deletion: ");
                scanf("%d", &value);
                head = deleteItem(head, value);
                break;
            case 5:
                printf("\nEnter item for searching: ");
                scanf("%d", &value);
                searchItem(head, value);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                freeList(head);
                return 0;
            default:
                printf("\nInvalid input!\n");
        }
    }
}