#ifndef __LL_H_
#define __LL_H_

#include <stdio.h>

struct node {
	struct node *next;
	struct node *prev;
	long value;
};

struct ll_info {
	struct node *head;
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
};

struct options {
	enum command cmd;
	enum sub_command sub_cmd;
	long value;
};

int insert_head(struct node *head, struct node *node);

#endif
