#include "ll.h"
#include <malloc.h>

void insert_tail(struct node **head, struct node *node)
{
	struct node *tail;	

	// if head is null, append to head
	if (!*head) {
		*head = node;
		return;
	} 

	//find the tail node
	tail = *head;
	while(tail->next)
		tail = tail->next;
	
	tail->next = node;
}

void insert_head(struct node **head, struct node *node)
{
	struct node *temp;	

	node->next = *head;
	*head = node;
}

void insert_index(struct node **head, struct node *node, int i)
{
	struct node *cur;	

	if (!*head) {
		if (i>0) {
			printf("[Error: Index out of bound]\n");
			return;
		}
		*head = node;
		return;
	} 

	// if index is zero, its insert head case
	if (!i) {
		insert_head(head, node);
		return;

	}

	cur = *head;

	// find the (i-1)th node
	while(--i && cur && cur->next)
		cur = cur->next;
	
	if (i) {
		printf("[Error: Index out of bound]\n");
	} else {
		node->next = cur->next;
		cur->next = node;
	}
}

void insert(struct node **head, struct options *op)
{
	struct node *node = init_node(op->value);	

	if (op->sub_cmd == INSERT_HEAD)
		insert_head(head, node);
	else if (op->sub_cmd == INSERT_TAIL)
		insert_tail(head, node);
	else if (op->sub_cmd == INSERT_INDEX)
		insert_index(head, node, op->index);
	else
		printf("[Error: Invalid sub_command]\n");

}
