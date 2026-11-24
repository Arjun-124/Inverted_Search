#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE 1

typedef struct node
{
    char filename[50];
    struct node *link;
} Flist;
typedef struct sub
{
    int word_count;
    char filename[20];
    struct sub*sub_link;
}sub_node;
typedef struct main 
{
    int file_count;
    char word[20];
    sub_node *sub_link;
    struct main*main_link;
}main_node;
typedef struct hash
{
    int index;
    //char word[50];
    //struct hash *link;
     main_node *link;
} hash_table;

int read_validate(int argc, char *argv[], Flist **head);
int duplicate_validate(Flist *head, char *filename);
int insert_last(Flist **head, char *filename);

void createdatabase(Flist *head,hash_table *arr);
void create_hash(hash_table *arr, int size);
void print(hash_table *head1);
void display_database(hash_table *arr);
void search_database(hash_table *arr);
void save_database(hash_table *arr);
void update_database(hash_table *arr);

#endif