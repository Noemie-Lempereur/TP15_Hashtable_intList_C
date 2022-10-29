//
// Created by Noémie on 11/05/2020.
//

#ifndef TP15_2_HASHTABLEINTLIST_H
#define TP15_2_HASHTABLEINTLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


struct HashTable {
    int items; // number of elements in the table
    int buckets; // table size
    struct List** table; // the array
};

struct HashTable* createEmptyHashTable(int buckets);
bool isHashTableEmpty(struct HashTable* ht);
int hashTableElements(struct HashTable* ht);
int hash_function(struct HashTable* ht, int value);
// Inserts "value" in the table. If no collision, it returns True, otherwise False
bool insert(struct HashTable* ht, int value);
bool exists(struct HashTable* ht, int value);
void printHashTable(struct HashTable* ht);
void deleteItem(struct HashTable* ht, int value);
void deleteHashTable(struct HashTable* ht);
// Shows the whole content of the table as a histogram
// For each bucket, print a ’*’ to indicate an item
void printAsHistogram(struct HashTable* ht);


#endif //TP15_2_HASHTABLEINTLIST_H
