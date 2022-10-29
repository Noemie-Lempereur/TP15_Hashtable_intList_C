//
// Created by Noémie on 11/05/2020.
//

#include "hashTableIntList.h"
#include "list.h"

struct HashTable* createEmptyHashTable(int buckets){
    struct HashTable* ht = malloc(sizeof(struct HashTable));
    ht->items = 0;
    ht->buckets = buckets;
    ht->table = malloc((buckets+1)*sizeof(int));
    if(ht->table!=NULL){
        for (int i = 0; i < buckets; i++) {
            ht->table[i]=createEmptyList();
        }
    }
    return ht;
}

bool isHashTableEmpty(struct HashTable* ht){
    if(ht!=NULL&&hashTableElements(ht)>0){
        return false;
    }
    return true;
}

int hashTableElements(struct HashTable* ht){
        if(ht!=NULL){
            return ht->items;
        }
        return -1;
}

int hash_function(struct HashTable* ht, int value){
    if (ht != NULL) {
        return (value % (ht->buckets));
    }
    return -1;
}

// Inserts "value" in the table. If no collision, it returns True, otherwise False
bool insert(struct HashTable* ht, int value) {
    if (ht != NULL) {
        int indice = hash_function(ht, value);
        addFirst(ht->table[indice], value);
        ht->items=ht->items+1;
        if (isEmptyList(ht->table[indice])) {
            return true;
        }
    }
    return false;
}

bool exists(struct HashTable* ht, int value){
    int hashIndex=hash_function(ht,value);
    if(belongs(ht->table[hashIndex],value)!=NULL){
        return true;
    }
    return false;
}

void printHashTable(struct HashTable* ht){
    if(ht!=NULL) {
        for(int i = 0; i <= (ht->buckets);i++) {
            if (!isEmptyList(ht->table[i])) {
                printList(ht->table[i]);
            }
        }
    }
}

void deleteItem(struct HashTable* ht, int value){
    if(ht!=NULL) {
        if(exists(ht, value)){
            int indice=hash_function(ht,value);
            struct List* lis=ht->table[indice];
            if(lis !=NULL) {
                struct Cell *itr = lis->head;
                int i = 0;
                if(itr->value!=value) {
                    while (itr->next != NULL && itr->next->value != value) {
                        itr = itr->next;
                        i++;
                    }
                    i++;
                    if (value == itr->value) {
                        bool val;
                        deleteItemPos(lis, i, &val);
                        ht->items = ht->items - 1;
                    }
                }
                else{
                    deleteFirst(lis);
                }
                ht->table[indice]=lis;
            }
        }
    }
}

void deleteHashTable(struct HashTable* ht){
    for(int i=0;i<ht->buckets;i++){
        deleteList(ht->table[i]);
    }
    ht->items=0;
    free(ht->table);
    free(ht);
}

// Shows the whole content of the table as a histogram
// For each bucket, print a ’*’ to indicate an item
void printAsHistogram(struct HashTable* ht){
    if(ht!=NULL) {
        for(int i = 0; i <= (ht->buckets);i++) {
            for(int j=0;j<listSize(ht->table[i]);j++){
                printf("*");
            }
            printf("\n");
        }
    }
}