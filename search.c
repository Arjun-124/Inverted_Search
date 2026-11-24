#include <stdio.h>
#include "inverted_search.h"
#include <ctype.h>
#include<string.h>

void search_database(hash_table *arr)
{
    char word[30];
    int flag=0;
    printf("enter the word we want to search\n");
    scanf("%s",word);
    int index;
    if(word[0]>='A'&&word[0]<='Z')
    {
        index=word[0]-'A';
        }
    else{
        index=word[0]-'a';
     }
    main_node *main_temp = arr[index].link;
    while(main_temp!=NULL)
    {
        //sub_node *sub_temp = main_temp->sub_link;
        if(strcmp(main_temp->word,word)==0)
        {
             sub_node *sub_temp = main_temp->sub_link;
            printf("%-15s %-15s %-20s %-20s %-10s\n",
                   "Index", "Word", "File Count",
                   "Filename", "Word Count");
            while(sub_temp!=NULL)
            {
                printf("%-15d %-15s %-20d %-20s %-10d\n",
                                 arr[index].index,
                                 main_temp->word,
                                 main_temp->file_count,
                                 sub_temp->filename,
                                 sub_temp->word_count);

                sub_temp = sub_temp->sub_link;
            }
            flag=1;
            break;
        }
        main_temp=main_temp->main_link;
    }
    if(flag==0)
    {
        printf("word not found");
    }

}