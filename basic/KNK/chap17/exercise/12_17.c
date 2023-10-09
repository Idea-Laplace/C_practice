struct node {
	int value;
	int struct node *next;
};

struct node *find_last(struct node *list, int n) {
	struct node *contain_n = list;

	while (list != NULL) {
		if (list -> value == n)
			contain_n = list;
		list = list -> next;
	}

	return contain_n;
}
