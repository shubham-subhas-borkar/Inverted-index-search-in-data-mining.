#include "inverted_index.h"

int display_DB(main_node_t **head) {
    int flag = 0;
	printf("========================================================================================================\n");
	printf("                                                   DATABASE                                                        \n");
	printf("========================================================================================================\n");
    for (int i = 0; i < SIZE; i++) {
        if (head[i] != NULL) {
            flag++;
        }
    }
    if (flag > 0) {
        printf("[Index]   [word]     filecount   file(s):   filename                             wordcount  time(s)\n");
    printf("========================================================================================================\n");
		for (int i = 0; i < SIZE; i++) {
            main_node_t *temp = head[i];
            while (temp) {
                printf("[%d]       [%s]        %d       file(s):   ", i, temp->word, temp->f_count);
                sub_node_t *temp1 = temp->sub_link;
                if (temp1) {
                    printf("%s                                     %d   time(s)\n", temp1->f_name, temp1->w_count);
                    temp1 = temp1->link;
                    while (temp1) {
                        printf("                                          ");
                        printf("%s                                     %d   time(s)\n", temp1->f_name, temp1->w_count);
                        temp1 = temp1->link;
                    }
                }
                temp = temp->link;
            }
        }
	printf("========================================================================================================\n");
        return SUCCESS;
    }
    return EMPTYLIST;
}

