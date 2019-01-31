#include<stdio.h>
#include<stdlib.h>

typedef struct link{
    int data;
    struct link* next;
}Link;

Link* Node(int data){
    Link* newNode = (Link*) malloc(sizeof(Link));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
    }

void insert(Link** head, int data){
    Link* item = (Link*) malloc(sizeof(Link));
    item->data = data;
    item->next = *head;
    *head = item;
    return;
}

void insertPos(Link** head, int data, int pos){
    Link* ref = *head;

    Link* item = (Link*) malloc(sizeof(Link));
    item->data = data;
    item->next = *head;

    if(!pos){
        *head = item;
        return;
    }
    Link* temp = NULL;
    int i =0;
    for(i=1; i<pos; i++)
        ref = ref->next;
    temp = ref->next;
    ref->next = item;
    item->next = temp;
    return;
}


void insertLast(Link** head, int data){
    Link* ref = *head;
    
    Link* item = (Link*) malloc(sizeof(Link));
    item->data = data;
    item->next = NULL;
    // If no element is present insert it
    if(!ref){
        ref = item;
        *head = ref;
        return;
    }

    while(ref->next != NULL)
        ref = ref->next;
    ref->next = item;
    return;
}

void cleanup(Link** head){
    Link* temp;
    while(*head != NULL){
        temp = *head;
        *head = temp->next;
        free(temp);
    }
}

void printList(Link* head){
    Link* ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int listLength(Link* head){
    Link* ptr = head;
    int length = 0;
    while (ptr != NULL){
        length++;
        ptr = ptr->next;
    }
    return length;
}

Link* rev(Link* head){
    Link* prev = NULL;
    Link* next = NULL;

    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
