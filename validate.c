#include "inverted_index.h"
void validate_n_store_filenames(file_node_t **file, char *filenames[])
{
    int i=1,valid,store;
    while (filenames[i])                                                                           //run the while loop for all the entered files through command line
    {
	valid=IsFileValid(filenames[i]);                                                           //call the IsFileValid function
	if (valid==SUCCESS)                                                                        //if valid==SUCCESS then 
	{
	    store=store_filenames_to_list(filenames[i],file);                                      //call the store_filenams_to_list function
	    if (store==REPEATED)                                                                   //if store==REPEATED then
	    {
		printf("INFO! Duplicate found for file %s, skipping...\n",filenames[i]);        //print duplicate files
	    }
	    else if(store==SUCCESS)                                                               //if store==SUCCESS
	    {
		printf("INFO %s successfully added to list\n",filenames[i]);                      //print file successfully added
	    }
	}
	else if(valid==NOT_PRESENT)                                                                 //if valid==NOT_PRESENT then
	{
	    printf("%s not present\n",filenames[i]);                                              //print file is not present
	}
	else if (valid == FILE_EMPTY)                                                                //if valid == FILE_EMPTY then
	{
	    printf("%s has no content\n",filenames[i]);                                           //print file has no content
	}
	i++;
    }
}
int IsFileValid(char *filename)                                                                    //isfilevalid function defination
{
	FILE *fptr;
	fptr=fopen(filename,"r");                                                                   //open the file through fptr file pointer
	if(fptr == NULL)                                                                            //if fptr==NULL then
	{
	    return NOT_PRESENT;                                                                     //return NOT_PRESENT
	}
	char ch;
	ch=fgetc(fptr);                                                                            //read the first character from the file 
	if (ch != EOF)                                                                             //if ch != EOF then
	{
	    return SUCCESS;                                                                        //return SUCCESS
	}
	else                                                                                       //else then
	{
	    return FILE_EMPTY;                                                                     //return FILE_EMPTY                                                                             
	}
}
int store_filenames_to_list(char *filename, file_node_t **file)                                   //store_filenames_to_list function defination
{
    file_node_t *new=malloc(sizeof(file_node_t));                                                //create new node
    if (new==NULL)
    {
	return FAILURE;
    }
    strcpy(new->f_name,filename);                                                                  //copy the filename to new->f_name
    new->link=NULL;                                                                                //assign new->link with NULL
    if(*file==NULL)                                                                                //if list is empty then
    {
	*file=new;                                                                               //*file with new
	return SUCCESS;
    }
    file_node_t *temp=*file;                                                                         //declare *temp assign *file
    file_node_t *prev=NULL;                                                                       //declare *prev with NULL
    while(temp)
    {
	if (!strcmp(temp->f_name,filename))                                                      //check for same filename if yes then
	{
	    return REPEATED;                                                                     //return REPEATED
	}
	prev=temp;                                                                               //assign prev with temp
	temp=temp->link;                                                                         //temp=temp->link
    }
    prev->link=new;                                                                              //when temp reaches NULL then assign prev->link with new
    return SUCCESS;
}
