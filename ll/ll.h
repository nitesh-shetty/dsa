#ifndef __LL_H_
#define __LL_H_

#include <stdio.h>

struct node {
	long value;
	struct node *next;
};

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
	INSERT_INDEX,
};

struct options {
	enum command cmd;
	enum sub_command sub_cmd;
	int index;
	long value;
};

/* main file */
void print_list(struct node *head);
struct node* init_node(long value);

/* func file */
void insert(struct node **head, struct options *op);
#endif
