#include "inverted_index.h"

int create_DB(file_node_t *file_head,main_node_t **head)
{
    while(file_head)                                                                        //run the loop till the filehead reaches NULL
    {
	if (read_datafile(file_head,head,file_head->f_name)==FAILURE)                      //call the read_datafile function if return ==FAILURE then
	{
	    return FAILURE;            
	}
	else
	{
	    printf("Successful : creation of Database for file: %s\n",file_head->f_name);      //print successful creation of database for file
	}
	file_head=file_head->link;                                                                   //traverse the head
    }
}
int read_datafile(file_node_t *file_head, main_node_t **head, char *f_name)                   //read_datafile function defination
{
    FILE *fptr=fopen(f_name,"r");                                                              //open the file through file pointer
    char word[NAMELENGTH];                                                                     //declare a character array word of size NAMELENGTH
    while(fscanf(fptr,"%s",word) != EOF)                                                       //read the word till the fptr reaches EOF
    {
	insert_at_last_main(head,word,f_name);                                                 //call the insert at last function
    }
    fclose(fptr);
    return SUCCESS;
}
int insert_at_last_main(main_node_t **head,char *word,char *f_name)                            //insert_at_last_main function defination
{
    int index;
    char ch=toupper(word[0]);                                                                  //convert first letter of word to uppercase
    index=ch%65;                                                                               //find the index
    if (head[index] == NULL)                                                                   //head[index] == NULL then
    {
	main_node_t *new=malloc(sizeof(main_node_t));                                          //create the main node
	if(new==NULL)
	{
	    return FAILURE;
	}
	strcpy(new->word,word);                                                                //assign word to new->word
	new->link=NULL;                                                                        //assign new->link with NULL
	new->sub_link=NULL;                                                                    //assign new->sub_link with NULL
	new->f_count=1;                                                                        //assign new->f_count with 1
	sub_node_t *new1=malloc(sizeof(sub_node_t));                                           //create sub node
	if(new1==NULL)
	{
	    return FAILURE;
	}
	strcpy(new1->f_name,f_name);                                                          //assign f_name to new->f_name
	new1->link=NULL;                                                                      //assign new->link with NULL 
	new1->w_count=1;                                                                      //assign new->w_count with 1
	head[index]=new;                                                                      //assign head[index] with new
	new->sub_link=new1;                                                                   //new->sub_link with new1
	return SUCCESS;
    }
    main_node_t *temp=head[index];                                                            //declare *temp =head[index]
    while(temp)                                                                   
    {
	if(!strcmp(temp->word,word))                                                          //if word is same 
	{
	    sub_node_t *temp1=temp->sub_link;                                                 //declare *temp1=temp->sub_link
	    while(temp1)
	    {
		if(!strcmp(temp1->f_name,f_name))                                             //if filename is also same then
		{
		    temp1->w_count++;                                                         //increase the word count
		    return SUCCESS;
		}
		if(temp1->link==NULL)                                                        //if filename is not same then
		{
		    sub_node_t *new1=malloc(sizeof(sub_node_t));                             //create subnode
		    if(new1==NULL)
		    {
			return SUCCESS;
		    }
		    strcpy(new1->f_name,f_name);
		    new1->link=NULL;
		    new1->w_count=1;
		    temp1->link=new1;
		    temp->f_count++;
		    return SUCCESS;
		}
		temp1=temp1->link;
	    }                                                                                  //if word is not same then
	}
	if(temp->link==NULL)
	{
	    main_node_t *new=malloc(sizeof(main_node_t));                                        //create main node
	    if(new==NULL)
	    {
		return FAILURE;
	    }
	    strcpy(new->word,word);
	    new->link=NULL;
	    new->sub_link=NULL;
	    new->f_count++;
	    sub_node_t *new1=malloc(sizeof(sub_node_t));                                           //create sub node
	    if(new1==NULL)
	    {
		return FAILURE;
	    }
	    strcpy(new1->f_name,f_name);
	    new1->link=NULL;
	    new1->w_count=1;
	    new->sub_link=new1;     
	    temp->link=new;
	    return SUCCESS;
	}
	temp=temp->link;
    }
}




