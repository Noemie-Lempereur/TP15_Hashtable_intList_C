#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H


struct Cell{
    int value;
    struct Cell* next;
};

struct List{
    int size;
    struct Cell* head;
};


struct Cell* createCell(int val);
struct List* createEmptyList();
void addFirst(struct List *l, int value);
bool isEmptyList(struct List* l);
int getItemPos(struct List* l, int position, bool* valid);
void deleteFirst(struct List* l);
void printList(struct List* l);
int listSize(struct List* l);
void addItemPos(struct List* l, int value, int position, bool* valid);
void deleteItemPos(struct List* l, int position, bool* valid);
void deleteList(struct List* l);
struct List* createListfromTab(int T[], int size);
struct Cell* belongs(struct List* l, int value);


#endif //UNTITLED_LIST_H