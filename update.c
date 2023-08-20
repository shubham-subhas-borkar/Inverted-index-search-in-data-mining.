#include "inverted_index.h"

int update_DB(file_node_t **file, main_node_t **head, char *filename)
{
    int valid,store;
    valid=IsFileValid(filename);
    if(valid==SUCCESS)
    {
	store=store_filenames_to_list(filename,file);
	if(store==REPEATED)
	{
	    printf("INFO! the file %s is duplicate already present in list\n",filename);
	}
	else
	{
	    printf("INFO  %s successfully added to list\n",filename);
	    read_datafile(*file,head,filename);
	    printf("Successful : creation of Database for %s\n",filename);
	    return SUCCESS;
	} 
    }
    else if(valid==NOT_PRESENT)
    {
	printf("%s not present\n",filename);
    }
    else if(valid==FILE_EMPTY)
    {
	printf("%s has no content\n",filename);
    }
    return FAILURE;
    
}
