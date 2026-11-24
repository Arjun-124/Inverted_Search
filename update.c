#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inverted_search.h"

void update_database(hash_table *arr)
{
    char filename[30];
    int index, file_count, word_count;
    char word[20], file_name[50];

    printf("Enter database filename: ");
    scanf("%29s", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File not opened\n");
        return;
    }

    while (fscanf(fp, "%d %19s %d %49s %d",
                  &index, word, &file_count,
                  file_name, &word_count) == 5)
    {
        if (index < 0 || index >= 26)
            continue;

        main_node *main_temp = arr[index].link;

        // Search word
        while (main_temp != NULL &&
               strcmp(main_temp->word, word) != 0)
        {
            main_temp = main_temp->main_link;
        }

        // Create main node if word not found
        if (main_temp == NULL)
        {
            main_temp = malloc(sizeof(main_node));

            if (main_temp == NULL)
            {
                fclose(fp);
                return;
            }

            strcpy(main_temp->word, word);
            main_temp->file_count = file_count;
            main_temp->sub_link = NULL;
            main_temp->main_link = arr[index].link;

            arr[index].link = main_temp;
        }

        sub_node *sub_temp = main_temp->sub_link;

        // Search filename
        while (sub_temp != NULL &&
               strcmp(sub_temp->filename, file_name) != 0)
        {
            sub_temp = sub_temp->sub_link;
        }

        // Create subnode if filename not found
        if (sub_temp == NULL)
        {
            sub_temp = malloc(sizeof(sub_node));

            if (sub_temp == NULL)
            {
                fclose(fp);
                return;
            }

            strcpy(sub_temp->filename, file_name);
            sub_temp->word_count = word_count;

            sub_temp->sub_link = main_temp->sub_link;
            main_temp->sub_link = sub_temp;
        }
    }

    fclose(fp);

    printf("Database updated successfully\n");
}