#include<stdio.h>
#include"inverted_search.h"
#define SUCCESS 0
#define FAILURE 1
int main(int argc, char *argv[])
{
    Flist *head=NULL;
    hash_table arr[26];
    create_hash(arr, 26); 
	if (argc < 2)
    {
        printf("ERROR: Pass file names through command line\n");
        return 1;
    }

    if (read_validate(argc, argv, &head) != SUCCESS)// read and validate the input files 
    {
        printf("ERROR: File validation failed\n");
        return 1;
    }
    int choice;

    do
    {
        printf("\n----- INVERTED SEARCH MENU -----\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Search Database\n");
        printf("4. Update Database\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createdatabase(head,arr);//creating data base is calling
                break;

            case 2:
                display_database(arr);// display data base is calling
                break;

            case 3:
                search_database(arr);//search function ids calling
                break;

            case 4:
                 printf("Calling update database\n");
                 update_database(arr);
                 printf("Update database returned\n");
                break;

            case 5:
                save_database(arr);
                printf("saved database returned\n");
                break;

            case 6:
                printf("Exiting Inverted Search\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}
