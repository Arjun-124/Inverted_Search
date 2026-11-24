#include <stdio.h>
#include "inverted_search.h"
void save_database(hash_table *arr)
{
    char filename[30];
    printf("Enter the database filename: ");
    scanf("%29s", filename);
    FILE *fp = fopen(filename, "w");
    if(fp==NULL)
    {
        printf("file is not opened");
        return;
    }
    for (int i = 0; i < 26; i++)
    {
        main_node *main_temp = arr[i].link;

        while (main_temp != NULL)
        {
          sub_node *sub_temp = main_temp->sub_link;

            while (sub_temp != NULL)
            {
                fprintf(fp,"%-15d %-15s %-20d %-20s %-10d\n",
                                 arr[i].index,
                                 main_temp->word,
                                 main_temp->file_count,
                                 sub_temp->filename,
                                 sub_temp->word_count);

                sub_temp = sub_temp->sub_link;
            }
            main_temp = main_temp->main_link;
        }
    }
}