#include "list.h"

/* Initialize List */
node_t * head = NULL;

/* Variables */
char text[999];
char word[20];
int word_count = 0;
int iter = 0;

/* Functions */
void read_file();
void get_word();
int check_word(char temp[20], int counter);
int count_word();
void insert_to_list();

int main()
{
    read_file();

    printf("\n");
    while(text[iter] != '\0')
    {
        get_word();
        word_count = count_word();
        insert_to_list();

        word_count = 0;
        for(int i = 0; word[i] != '\0'; i++)
        {
            word[i] = NULL;
        }
    }
    printf("\n");

    list_print(head);

    return 0;
}

void read_file()
{
    int counter = 0;
    FILE * read_words = fopen("tests/example_text_2.txt", "r");

    if(read_words == NULL)
    {
    printf("file is empty");
    }

    while((text[counter] = tolower(getc(read_words))) != EOF)
    {
        putchar(text[counter]);
        counter++;
    }
    fclose(read_words);
}

void get_word()
{
    char temp[20];
    int counter = 0;

    while(text[iter] == ' ')
    {
        iter++;
    }
    while(text[iter] != ' ' && text[iter] != '\0')
    {
        temp[counter] = text[iter];

        counter++;
        iter++;
    }

    if(check_word(temp, counter))
    {
        get_word();
    }
    else
    {
        for(int i = 0; i < counter; i++)
        {
            word[i] = temp[i];
        }
    }
}

int check_word(char temp[20], int counter)
{
    int correct = 0;

    for(node_t *current = &head; current != NULL; current = current -> next)
    {
        for(int j = 0; j < counter; j++)
        {
            if(temp[j] == current -> word[j])
            {
                correct++;
            }
        }
        if(counter == correct && current -> word[counter] == '\0')
        {
            return 1;
        }
        correct = 0;
    }
}

int count_word()
{
    int cw_iter = 0;
    int counter = 0;
    int correct = 0;
    int word_count = 0;

    for(int i = 0; i < 120; i++)
    {
        while(text[cw_iter] == ' ')
        {
            cw_iter++;
        }
        while(text[cw_iter] != ' ')
        {
            if(word[counter] == text[cw_iter])
            {
                correct++;
            }
            counter++;
            cw_iter++;
        }
        if(counter == correct && word[counter] == '\0')
        {
            word_count++;
        }
        counter = 0;
        correct = 0;
    }
    return word_count;
}

void insert_to_list()
{
    if(head == NULL)
    {
        head = list_create(word_count, word);
    }
    else
    {
        if(word_count > head -> word_count)
        {
            head = list_push_beginning(head, word_count, word);
        }
        else
        {
            for(node_t *current = &head; current != NULL; current = current -> next)
            {
                if(current -> next == NULL)
                {
                    list_push_end(head, word_count, word);
                    break;
                }
                else if(current -> next -> word_count < word_count)
                {
                    list_push_between(head, word_count, word);
                    break;
                }
            }
        }
    }
}
