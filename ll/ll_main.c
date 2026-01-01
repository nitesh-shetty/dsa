#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ll.h"

// Singly Linked List
// Insert a node at:
// beginning
// end
// given position
// Delete a node by:
// value
// position
// Traverse a linked list
// Find the length of a linked list
// Search an element in a linked list
// Reverse a linked list (iterative & recursive)
// Find the middle of a linked list
// Detect a loop (cycle detection)
// Find the nth node from the end
//
// Doubly Linked List
// Insert and delete nodes
// Reverse a doubly linked list
// Advantages over singly linked list
// Applications of doubly linked list
// ..Circular Linked List
// Difference between circular and singly linked list
// Detect loop in a circular linked list
// Split a circular linked list into two halves
//
// ..Intermediate / Interview-Focused
// Remove duplicates from a sorted linked list
// Remove duplicates from an unsorted linked list
// Check if a linked list is a palindrome
// Merge two sorted linked lists
// Intersection point of two linked lists
// Add two numbers represented by linked lists
// Swap nodes without swapping data
// Pairwise swap nodes
//
// ..Advanced / Tricky
// Clone a linked list with random pointer
// Flatten a multilevel linked list
// Reverse nodes in k-groups
// Segregate even and odd nodes
// Rotate a linked list
// Reorder list (L0 → Ln → L1 → Ln-1)
// Delete nodes having greater value on right
// Sort a linked list (Merge Sort)
// Convert linked list to BST
// LRU Cache using linked list + hashmap

int feat_implemented = 0;
int feat_total = 36;

enum status {
	RET_SUCCESS,
	RET_FAILURE,
};

enum command {
	CMD_INSERT,
	CMD_REMOVE,
	CMD_LEN,
};

enum sub_command {
	INSERT_HEAD,
	INSERT_TAIL,
};

struct options {
	enum command cmd;
	enum sub_command sub_cmd;
	long value;
};

void print_app_info(char *app_name)
{
	printf("\nlinked list manipulation\n");
	printf("%s command sub_command value\n\n", app_name);
	printf("Supported options\n");
	printf("%s insert head value\n", app_name);
	printf("sample:\n");
	printf("%s insert head 44\n", app_name);
	printf("%s: features completion [%d/%d], %d%\n", app_name,
		feat_implemented, feat_total,
		(feat_implemented*100)/feat_total);
}

void print_options(struct options *op) {
	printf("command: \t%d\n", op->cmd);
	printf("sub command: \t%d\n", op->sub_cmd);
	printf("value: \t\t%ld\n", op->value);
}

int parse_value(struct options *op)
{
	long value;
	char *end;
	char user_input[16];
	int ret;

	do {
		printf("Please enter value:\n");
		printf("value exit\n");
		scanf("%s", user_input);
		printf("input: %s\n", user_input);
		if (!strcmp(user_input, "exit")) {
			ret = RET_FAILURE;
			break;
		}
		value = strtol(user_input, &end, 10);
		if (*end != '\0') {
			printf("[Invalid value]\n");
		} else  {
			op->value = value;
			break;
		}
	} while(1);

	return RET_SUCCESS;
}

int parse_insert(struct options *op)
{
	int ret = RET_SUCCESS;
	char user_input[16];

	do {
		printf("Please enter sub command:\n");
		printf("head tail exit\n");
		scanf("%s", user_input);
		printf("input: %s\n", user_input);

		if (!strcmp(user_input, "head")) {
			op->sub_cmd = INSERT_HEAD;
			ret = parse_value(op);
			break;
		} else if (!strcmp(user_input, "tail")) {
			op->sub_cmd = INSERT_TAIL;
			ret = parse_value(op);
			break;
		} else if (!strcmp(user_input, "exit")) {
			ret = RET_FAILURE;
			break;
		} else {
			printf(" [Undefined sub_command]\n");
			ret = RET_FAILURE;
		}
	} while(1);
	
	return ret;
}

int parse_args(struct options *op)
{
	int ret = RET_SUCCESS;
	char user_input[16];

	do {
		printf("Please enter command:\n");
		printf("insert remove len exit\n");
		scanf("%s", user_input);
		printf("input: %s\n", user_input);

		if (!strcmp(user_input, "insert")) {
			op->cmd = CMD_INSERT;
			ret = parse_insert(op);
			if (!ret)
				print_options(op);
		} else if (!strcmp(user_input, "remove")) {
			op->cmd = CMD_REMOVE;
		} else if (!strcmp(user_input, "len")) {
			op->cmd = CMD_LEN;
		} else if (!strcmp(user_input, "exit")) {
			ret = RET_FAILURE;
			break;
		} else {
			printf("[Undefined command]\n");
			ret = RET_FAILURE;
		}
	} while (1);
	
	return ret;
}

int main(int argc, char *argv[])
{
	struct options op;
	struct node *head;

	if (parse_args(&op)) {
		print_app_info(argv[0]);
		return RET_FAILURE;
	}
	print_options(&op);

	return 0;
}
