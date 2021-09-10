#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Node
{
    struct Node* next;
    int word_count;
    char word[20];
} node_t;

/* Linked List */
node_t* list_create(int* word_count, char* word[20]);
node_t* list_push_end(node_t * head, int* word_count, char* word[20]);
node_t* list_push_beginning(node_t * head, int* word_count, char* word[20]);
node_t* list_push_between(node_t * head, int* word_count, char* word[20]);
void list_print(node_t * head);

#endif // _LIST_H

