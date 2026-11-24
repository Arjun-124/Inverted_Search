#include<stdio.h>
#include<string.h>
#include<string.h>
#include"inverted_search.h"
int read_validate(int argc,char *argv[],Flist **head)
{
    for(int i=1;i<argc;i++)
    {
        if(strlen(argv[i]) < 4 ||strcmp(argv[i] + strlen(argv[i]) - 4, ".txt") != 0)
        {
            continue;
        }
        if(duplicate_validate(*head,argv[i])!=SUCCESS)
        {
            continue;
        }
        FILE *fp=fopen(argv[i],"r");
        if(fp==NULL)
        {
            printf("file is not opened");
            continue;
        }
        int ch=fgetc(fp);
        if(ch==EOF)
        {
            printf("empty file");
            fclose(fp);
            continue;
        }
        if(insert_last(head,argv[i])!=SUCCESS)
        {
            continue;
        }
        fclose(fp);
    }
    if(*head == NULL)
    {
        printf("INFO : List is empty\n");
        return FAILURE;
    }

   return SUCCESS;

}
int duplicate_validate(Flist *head,char *filename)
{
    Flist *temp=head;
    if(temp==NULL)
    {
        return SUCCESS;
    }
    while(temp!=NULL)
    {
        // if(strcmp(temp->file,filename)==0)
        if(strcmp(temp->filename, filename) == 0)
        {
            printf("files is already there");
            return FAILURE;
        }
        temp=temp->link;
    }
    return SUCCESS;
}
int insert_last(Flist **head,char *filename)
{
     Flist *new=malloc(sizeof(Flist));
    if(*head==NULL)
    {
        // strcpy(new->file,filename);
        strcpy(new->filename, filename);
        new->link=NULL;
        *head=new;
        return SUCCESS;
    }
    else{
         Flist*temp=*head;
         while(temp->link!=NULL)
         {
            temp=temp->link;
         }
        //  strcpy(new->file,filename);
        strcpy(new->filename, filename);
         new->link=NULL;
         temp->link=new;
         return SUCCESS;
    }
}