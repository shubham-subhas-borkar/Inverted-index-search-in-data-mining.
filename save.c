#include "inverted_index.h"
int save_DB (main_node_t **head, char * fname)
{
    int flag=0;
    FILE *fptr=fopen(fname,"w");                                      //open the file in write mode
    if (fptr==NULL)
    {
	return FAILURE;
    }
    for(int i=0;i<SIZE;i++)
    {
	if(head[i]!=NULL)                                            //check for all the index values are NULL or not 
	{
	    flag++;
	}
    }
    if(flag > 0)
    {
	for (int i=0;i<SIZE;i++)                                      //run the for loop for all the index values
	{

	    main_node_t *temp=head[i];
	    if(temp)
	    {
		fprintf(fptr,"#%d;\n",i);                             //fprint the index value
	    }
	    while(temp)
	    {
		fprintf(fptr,"%s;",temp->word);                        //fprint the word
		fprintf(fptr,"%d;",temp->f_count);                     //fprint the filecont
		sub_node_t *temp1=temp->sub_link;       
		while(temp1)
		{
		    if(temp1->link==NULL)                                       
		    {
			fprintf(fptr,"%s;%d;#\n",temp1->f_name,temp1->w_count);        //fprint the filename and word count
		    }
		    else
		    {
			fprintf(fptr,"%s;%d;",temp1->f_name,temp1->w_count);
		    }
		    temp1=temp1->link;
		}
		temp=temp->link;
	    }
	}
	fclose(fptr);
	return SUCCESS;
    }
    fclose(fptr);
    return EMPTYLIST;
}

