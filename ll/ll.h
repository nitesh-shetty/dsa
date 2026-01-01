struct node {
	struct node *next;
	struct node *prev;
	long value;
};

struct ll_info {
	struct node *head;
};

int insert_head(struct node *head, struct node *node);
