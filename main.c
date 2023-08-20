/*
NAME : Shubham Borkar
DATE : 25/06/2023
Project title : Inverted Search
*/

#include "inverted_index.h"

int main(int argc, char *argv[])
{
    int flag=0;
    char choice1;
    if (argc == 1)                                                                 //if CLA is 1 then
    {
	printf("Please pass the valid file names through command line\n");         //print please pass the file names through command line
	return FAILURE;
    }
    file_node_t *file=NULL;                                                         //declare a file_node_t *file pointer
    validate_n_store_filenames(&file,argv);                                         //call the validate_n_store_filenames function
    if (file == NULL)
    {
	return FAILURE;
    }
    main_node_t *head[SIZE]={NULL};                                                //declare a array of pointer for structure main_node_t
    for (int i=0;i<SIZE;i++)
    {
	head[i]=NULL;                                                              //initialize all the values to NULL
    }
    do
    {
	int choice;
	printf("\nSelect your choice among following options:\n");
	printf("1.Create_Database\n2.Display_Database\n3.Search_Database\n4.Save_Database\n5.Update_database\n6.Exit\nEnter the choice:\n");           //print the choices
	scanf("%d",&choice);
	switch (choice)
	{
	    case 1:                                                                  //create_database
		{
		    flag=1;
		    if (create_DB(file,head)==FAILURE)                               //call the create_DB function
		    {
			printf("DATABASE creation failure\n");
		    }
		    break;
		}
	    case 2:
		{
		    if (display_DB(head) == SUCCESS)                                  //call the display_DB function
		    {
			printf("Display  DATABASE success\n");
		    }
		    else
		    {
			printf("NO data found in DATABASE\n");
		    }
		    break;
		}
	    case 3:                                                                  //call the search_DB function
		{
		    char word[50];
		    printf("Enter the word you want to search:\n");
		    scanf("%s",word);
		    if (search_DB(head,word) == NOT_PRESENT)
		    {
			printf("%s not present in DATABASE\n",word);
		    }
		    break;
		}
	    case 4:
		{
		    int save;
		    char filename[50];
		    printf("Enter the file name:\n");
		    scanf("%s",filename);
		    if ((save=(save_DB(head,filename))) == SUCCESS)                   //call the save_DB function
		    {
			printf("DATABASE is  saved\n");
		    }
		    else if(save == EMPTYLIST)
		    {
			printf("NO data found in DATABASE to save\n");
		    }
		    else
		    {
			printf("%s is failed to open\n",filename);
		    }
		    break;
		}
	    case 5:
		{
		    if(flag == 1)
		    {
			char filename[50];
			printf("Enter the filename to update DATABASE:\n");
			scanf("%s",filename);
			if(update_DB(&file,head,filename)==SUCCESS)                             //call the update_DB function
			{
			    printf("Update DATABASE Success\n");
			}
		    }
		    else
		    {
			printf("Error : create Database operation shall be called before trying to call the update database operation\n");
		    }
		    break;
		}
	    case 6:
		{
		    return SUCCESS;                                                       //exit
		}
	    default:
		printf("Enter proper choice !!\n"); 
		break;
	}
	printf("Do you want to continue y/n\n");
	scanf(" %c",&choice1);
    }while ((choice1 == 'y' || choice1 == 'Y'));
    return SUCCESS;
}


