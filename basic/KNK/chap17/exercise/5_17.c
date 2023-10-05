int main(void) {
	struct {
		union {
			char a, b;
			int c;
		} d;

		int e[5];
	} f, *p = &f;

	// Legal
	p -> e[3] = 10;
	(*p).d.a = '*';

	// Illegel
	// p -> b = ' ';
	p -> d.b = ' ';
	// p -> d -> c = 20;
	p -> d.c = 20;

	return 0;
}

