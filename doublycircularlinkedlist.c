#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

// creates node 
Node* createNode(int data){
    Node* temp = malloc(sizeof(Node));
    temp->data = data;
    temp->prev = NULL;
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
        temp->prev = last;
        last->next = temp;
        temp->next->prev = temp;
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
        temp->prev = head; // ! check
    } else {
        Node* walker = head;

        while(walker->next != head){
            walker = walker->next;
        }

        temp->next = head;
        temp->prev = walker;
        walker->next = temp;
        head->prev = temp;
    }

    return head;
}

// inserts node at specified place in list
Node* insertPlace(Node* head, int data, int place){
    Node* temp = createNode(data);

    if(head == NULL){
        head = temp;
        temp->next = head;
        temp->prev = head;
    } else {
        Node* walker = head;

        for(int i = 0; i < place - 1; i++){
            walker = walker->next;
        }

        if(walker->next != head){
            temp->next = walker->next;
            temp->prev = walker;
            walker->next = temp;
            walker->next->prev = temp;
        }
    }

    return head;
}

// deletes node with specified value
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
                head->prev = walker;
                walker->next = head;
                free(temp);
                return head;
            }
        }

        temp = head;
        last->next = temp->next;
        temp->next->prev = last;
        free(temp);
        return head;
    }

    walker = head;
    while(walker->next != head && walker->next->data != data){
        walker = walker->next;
    }

    temp = walker->next;
    walker->next = walker->next->next;
    walker->next->next->prev = walker;
    free(temp);
    return head;
}

// searches nodes given a specified value
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

// displays the full list
void displayList(Node* head){
    Node* show = head;

    printf("\n");
    do {
        printf("%d ", show->data);
        show = show->next;
    } while(show != head);
    printf("\n\n");
}

// frees the list
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

// gets the length of the list
int listLength(Node* head){
    Node* walker = head;
    int count = 1;

    while(walker->next != head){
        count += 1;
        walker = walker->next;
    }

    return count;
}

// prints the list twice, and in reverse (to show functionality of previous pointer and circular)
void printTwiceReverse(Node* head){
    Node* show = head;
    int len = listLength(head);
    int count = 0;

    while(show->next != head){
        show = show->next;
    }

    do {
        printf("%d ", show->data);
        show = show->prev;
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
        printf("7. Display linked list twice and reversed\n8. Exit\n");

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
                printTwiceReverse(head);
                break;
            case 8:
                freeList(head);
                return 0;
            default:
                printf("\nInvalid input!\n");
        }
    }
}