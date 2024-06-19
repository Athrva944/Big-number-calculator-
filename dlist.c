/* Name: Atharva kothawade */

#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

Dlist_t *create_node(int data) {
    Dlist_t *new_node = (Dlist_t *)malloc(sizeof(Dlist_t));
    if (new_node == NULL) {
	printf("Memory allocation failed\n");
	exit(1);
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void dl_insert_first(Dlist_t **head, int data) {
    Dlist_t *new_node = create_node(data);
    if (*head == NULL) {
	*head = new_node;
    } else {
	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;
    }
}

void dl_print_list(Dlist_t *head) {
    Dlist_t *temp = head;
    while (temp != NULL) {
	printf("%d ", temp->data);
	temp = temp->next;
    }
    printf("\n");
}

void dl_delete_list(Dlist_t **head) {
    Dlist_t *current = *head;
    Dlist_t *next;
    while (current != NULL) {
	next = current->next;
	free(current);
	current = next;
    }
    *head = NULL;
}

