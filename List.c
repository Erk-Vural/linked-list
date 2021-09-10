#include "list.h"

node_t* list_create(int* word_count, char* word[20])
{
    node_t * head = malloc(sizeof(node_t));
    if(head != NULL)
    {
        head -> next = NULL;
        head -> word_count = word_count;
        strcpy(head -> word, word);
    }
    return head;
}

node_t* list_push_end(node_t * head, int* word_count, char* word[20])
{
    node_t * new_node = list_create(word_count, word);
    if(new_node != NULL)
    {
        for(node_t *current = head; current != NULL; current = current -> next)
        {
			if (current -> next == NULL)
			{
				current -> next = new_node;
				break;
			}
		}
    }
    return new_node;
}

node_t* list_push_beginning(node_t * head, int* word_count, char* word[20])
{
    node_t * new_node = list_create(word_count, word);
    if(new_node != NULL)
    {
        new_node -> next = head;
    }
    return new_node;
}

node_t* list_push_between(node_t * head, int* word_count, char* word[20])
{
    node_t * new_node = list_create(word_count, word);
    for(node_t *current = head; current != NULL; current = current -> next)
    {
        if(current -> next -> word_count < new_node -> word_count)
        {
            new_node -> next = current -> next;
            current -> next = new_node;
            break;
        }
    }
    return new_node;
}

void list_print(node_t * head)
{
    int counter = 1;
    for(node_t *current = head; current != NULL; current = current -> next)
    {
        printf("\n%d. %s : %d", counter, current -> word, current ->word_count);
        counter++;
    }
}
