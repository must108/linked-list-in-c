#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// creates node
Node* createNode(int data){
    Node* temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = temp;

    return temp;
}

// inserts node at beginning 
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

// inserts node at end
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

// inserts node at specified place
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

// deletes node with a specified value
Node* deleteItem(Node* head, int data){
    Node* temp;
    Node* last;
    Node* walker;

    if(head == NULL){
        return head;
    } else if(head->data == data){
        last = head;

        while(last->next != head){
            last = last->next;
        }

        if(last->data == data){
            walker = head;

            while(walker->next != head && walker->next != last){
                walker = walker->next;
            }

            if(walker->next == last){
                temp = walker->next;
                walker->next = head;
                free(temp);
                return head;
            }
        }

        temp = head;
        last->next = temp->next;
        head = temp->next;
        free(temp);
        return head;
    }

    walker = head;
    while(walker->next != head && walker->next->data != data){
        walker = walker->next;
    }

    temp = walker->next;
    walker->next = walker->next->next;
    free(temp);
    return head;
}

// searches for a node given a value
void searchItem(Node* head, int data){
    if(head == NULL){
        printf("Item not found\n");
    } else {
        Node* walker = head;

        while(walker->next != head && walker->next->data != data){
            walker = walker->next;
        }

        if(walker->next == head){
            printf("Item not found\n");
        } else {
            printf("Item %d found\n", walker->next->data);
        }
    }
}

// displays list
void displayList(Node* head){
    Node* show = head;

    printf("\n");
    do {
        printf("%d ", show->data);
        show = show->next;
    } while(show != head);
    printf("\n\n");
}

// frees list
void freeList(Node* head){
    Node* current = head->next;
    Node* next;

    while(current != head){
        next = current->next;
        free(current);
        current = next;
    }

    free(head);
}

// gets length of list
int listLength(Node* head){
    Node* walker = head;
    int count = 1;

    while(walker->next != head){
        count += 1;
        walker = walker->next;
    }

    return count;
}

// prints list twice (to show functionality of circular linked list)
void printTwice(Node* head){
    Node* show = head;
    int len = listLength(head);
    int count = 0;

    do {
        printf("%d ", show->data);
        show = show->next;
        count += 1;
    } while(count < len*2);
    printf("\n\n");
}

int main(){

    int command, value, place;
    Node* head = NULL;

    while(1){
        printf("1. Insert in beginning of linked list\n2. Insert in end of linked list\n");
        printf("3. Insert at specific place in linked list\n4. Delete item from linked list\n");
        printf("5. Search for an item in linked list\n6. Display linked list\n");
        printf("7. Display linked list twice\n8. Exit\n");

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
                printTwice(head);
                break;
            case 8:
                freeList(head);
                return 0;
            default:
                printf("\nInvalid input!\n");
        }
    }
}
