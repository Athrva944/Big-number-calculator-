#ifndef DLIST_H
#define DLIST_H

typedef struct node {
        int data;
	    struct node *prev;
	        struct node *next;
} Dlist_t;

Dlist_t *create_node(int data);
void dl_insert_first(Dlist_t **head, int data);
void dl_print_list(Dlist_t *head);
void dl_delete_list(Dlist_t **head);

#endif

