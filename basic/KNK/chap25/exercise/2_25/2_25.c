#include <stdio.h>
#include <stdlib.h> // C89 mb,wc 5 characater function

int mbcheck(const char *s) {
	int n;

	for (mblen(NULL, 0);;s += n)
		if ((n = mblen(s, MB_CUR_MAX)) <= 0)
			return n;
}

int main(void) {
	const char *s[4] = {"\x05\x87\x80\x36\xed\xaa",\
						"\x20\xe4\x50\x88\x3f",\
						"\xde\xad\xbe\xef",\
						"\x8a\x60\x92\x74\x41"};

	for (int i = 0; i < 4; i++) {
		printf("%d\n", mbcheck(s[i]));
	}
	return 0;
}


