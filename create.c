#include <stdio.h>
#include "inverted_search.h"
void create_hash(hash_table *arr, int size);

void createdatabase(Flist *head,hash_table *arr)
{
    Flist*temp=head;
    while(temp!=NULL)
    {
        FILE *fp=fopen(temp->filename,"r");
        if(fp==NULL)
        {
            temp=temp->link;
            continue;
        }
        char word[20];
        while (fscanf(fp, "%19s", word) == 1)
        {
            int index;
            if(word[0]>='A'&&word[0]<='Z')
            {
                 index=word[0]-'A';
            }
            else{
                  index=word[0]-'a';
            }
            main_node *main_temp = arr[index].link;
            main_node *prev = NULL;

           while (main_temp != NULL)
          {
              if (strcmp(main_temp->word, word) == 0)
               break;

               prev = main_temp;
               main_temp = main_temp->main_link;
           }

         if (main_temp != NULL)
         {
               sub_node *sub_temp = main_temp->sub_link;
               sub_node *prev_sub = NULL;

            while (sub_temp != NULL)
           {
               if (strcmp(sub_temp->filename, temp->filename) == 0)
                { 
                 sub_temp->word_count++;
                break;
                 }

            prev_sub = sub_temp;
            sub_temp = sub_temp->sub_link;
           }

          if (sub_temp == NULL)
         {
             sub_node *new_sub = malloc(sizeof(sub_node));

            strcpy(new_sub->filename, temp->filename);
            new_sub->word_count = 1;
            new_sub->sub_link = NULL;

            prev_sub->sub_link = new_sub;
            main_temp->file_count++;
          }
        }
        else
        {
            main_node *new_main = malloc(sizeof(main_node));

            strcpy(new_main->word, word);
            new_main->file_count = 1;
            new_main->main_link = NULL;
            sub_node *new_sub = malloc(sizeof(sub_node));

            strcpy(new_sub->filename, temp->filename);
            new_sub->word_count = 1;
            new_sub->sub_link = NULL;

            new_main->sub_link = new_sub;

            if (prev == NULL)
              arr[index].link = new_main;
            else
              prev->main_link = new_main;
          }
        }
        fclose(fp);
        temp = temp->link;
    }
}

void create_hash(hash_table *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }
}