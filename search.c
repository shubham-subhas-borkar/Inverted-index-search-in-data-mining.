#include "inverted_index.h"
int search_DB (main_node_t **head, char *word)
{
    int index,flag=0;
    char ch=toupper(word[0]);                                     //convert first character of word to upper
    index=ch%65;                                                  //find the index
    main_node_t *temp=head[index];                                 //declare *temp =head[index]
    if (temp == NULL)                                              //if temp == NULL then
    {
	return NOT_PRESENT;                                         //return NOT_PRESENT
    }
    while(temp)
    {
	if (!strcmp(temp->word,word))                                   //if word matches with temp->word then
	{
	    flag++;
	    printf("Word  %s is present in  %d file(s)\n",word,temp->f_count);           //print the word and no of files
	    sub_node_t *temp1=temp->sub_link;
	    while(temp1)
	    {
		printf("In file : %s   %d  time(s)\n",temp1->f_name,temp1->w_count);       //print the filenames and word count
		temp1=temp1->link;
	    }
	}
	temp=temp->link;
    }
    printf("\n");
    if(flag>0)
    {
	return SUCCESS;
    }
    else
    {
	return NOT_PRESENT;
    }
}
