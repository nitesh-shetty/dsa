struct ll {
	struct ll *next;
	struct ll *prev;
	int data;
};

struct ll_info {
	struct ll *head;
};

int insert_head(struct ll_info *ll_info);
