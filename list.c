#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

struct Cell* createCell(int val){
    struct Cell* head=malloc(sizeof(struct Cell));
    if(head!=NULL) {
        head->value = val;
        head->next = NULL;
    }
    return head;
}

struct List* createEmptyList(){
    struct List* liste=malloc(sizeof(struct Cell));
    if(liste!=NULL) {
        liste->size = 0;
        liste->head = NULL;
    }
    return liste;
}

void addFirst(struct List *l, int value){
    if(l != NULL) {
        struct Cell *newHead = createCell(value);
        newHead->next = l->head;
        l->head = newHead;
        l->size = l->size + 1;
    }
}

bool isEmptyList(struct List* l){
    if (listSize(l)==0){
        return true;
    }
    return false;
}

int getItemPos(struct List* l, int position, bool* valid){
    int Size=l->size;
    if((position<0)||(position>=Size)||(l->head==NULL)){
        *valid=false;
        return -1;
    }
    int i=0;
    struct Cell* iter=l->head;
    while (i < position) {
        iter = iter->next;
        i++;
    }
    *valid=true;
    return iter->value;
}

void deleteFirst(struct List* l){
    if(l->head==NULL){
        return;
    }
    if(!isEmptyList(l)) {
        struct Cell *Head = l->head;
        struct Cell *newHead = Head->next;
        free(Head);
        l->head = newHead;
        l->size = l->size - 1;
    }
}


void printList(struct List* l){
    if (isEmptyList(l)==true) {
        printf("NULL\n");
    }
    else {
        struct Cell *itr = l->head;
        while (itr->next != NULL) {
            printf("%d->", itr->value);
            itr = itr->next;
        }
        printf("%d->", itr->value);
        printf("NULL\n");
    }
}

int listSize(struct List* l){
    return l->size;
}

void addItemPos(struct List* l, int value, int position, bool* valid){
    struct Cell *previous = l->head;
    int i = 0;
    if (position == 0) {
        addFirst(l,value);
        *valid = true;
        return;
    }
    if ((position < 0) || (position >= listSize(l)+1) || (l->head==NULL)) {
        *valid = false;
        return;
    }
    struct Cell *new = createCell(value);
    while (i < position -1) {
        previous = previous->next;
        i++;
    }
    new->next = previous->next;
    previous->next = new;
    *valid = true;
    l->size=l->size+1;
}

void deleteItemPos(struct List* l, int position, bool* valid){
    int i = 0;
    struct Cell *itr=l->head;
    if((position<0)||(position>=l->size)||(l->head==NULL)){
        *valid=false;
        return;
    }
    if (position==0){
        deleteFirst(l);
        *valid=true;
        return;
    }
    while (i < position-1) {
        itr = itr->next;
        i++;
    }

    struct Cell *nextcell=itr->next;
    itr->next=nextcell->next;
    free(nextcell);
    *valid=true;
    l->size=l->size-1;
}

void deleteList(struct List* l){
    if(l!=NULL) {
        struct Cell *current = l->head;
        struct Cell *next;
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
        l->head = NULL;
    }
    free(l);
}

struct List* createListfromTab(int T[], int size){
    struct Cell* head = NULL;
    struct Cell* previousCell = NULL;
    for(int i = 0; i < size; i++){
        if(i == 0) {
            head = createCell(T[i]);
            previousCell = head;
        }else{
            struct Cell* cell = createCell(T[i]);
            previousCell->next = cell;
            previousCell = cell;
        }
    }
    struct List* l=createEmptyList();
    l->head=head;
    l->size=size;
    return l;
}

struct Cell* belongs(struct List* l, int value){
    if(l !=NULL){
        struct Cell* itr = l->head;
        while (itr !=NULL){
            if (itr->value == value){
                return itr;
            }
            itr=itr->next;
        }
        return NULL;
    }
    return NULL;
}