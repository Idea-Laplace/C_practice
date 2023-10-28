/**
 * Modify the delete_from_list function(section 17.5) so that
 * its first parameter has type struct node **(a pointer to the
 * first node in a list) and its return type is void.
 * delete_from_list must modify its first argument to point to
 * the list after desired node has been deleted.
 **/

/**
 * struct node *delete_from_list(struct node *list, int n) {
 *    struct node *cur, *prev;
 *
 *    for  (cur = list, prev = NULL;
 *          cur != NULL && cur -> value != n;
 *          prev = cur, cur = cur -> next)
 *          ;
 *    
 *    if (cur == NULL)
 *        return list;
 *    if (prev = NULL)
 *        list = list -> next;
 *    else
 *        prev->next = cur->next;
 *    free(cur);
 *    return list;
 * }
 **/

#include <stdio.h>
#include <stdlib.h>
#define LEN 10

struct node {
	int value;
	struct node *next;
};

void delete_from_list(struct node **list, int n);
void print_list(struct node *list);

int main(void) {
	struct node *list = NULL;

	for (int i = 0; i < LEN; i++) {
		struct node *new_node = malloc(sizeof(struct node));
		new_node->value = i;
		new_node->next = list;
		list = new_node;
	}

	print_list(list);
	delete_from_list(&list, 7);
	print_list(list);


	return 0;
}

void delete_from_list(struct node **list_pointer, int n) {
	struct node *cur, *prev;

	for (cur = *list_pointer, prev = NULL;
		cur != NULL && cur->value != n;
		prev = cur, cur = cur->next)
		;

	if (cur == NULL)
		return;
	if (prev == NULL)
		*list_pointer = (*list_pointer)->next;
	else
		prev->next = cur->next;
	free(cur);
}

void print_list(struct node *list) {
	printf("list->");
	while (list != NULL) {
		printf("%d->", list->value);
		list = list->next;
	}
	
	printf("NULL\n");
}

