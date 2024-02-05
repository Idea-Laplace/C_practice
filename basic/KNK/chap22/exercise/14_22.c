/* 
   (a)
   Write your own version of the fgets function. Make it behave as much
   like the real fgets function as possible; In particular, make sure that
   it has the proper return value. To avoid confilcts with the standard
   library, don't name your function.

   (b)
   Write your own version of fputs, following the same rules as in part (a).
*/

#include <stdio.h>
#include <stdlib.h>
#define LEN 10


char *file_get_string(char * restrict str,
					int length,\
					FILE * restrict stream);

int file_put_string(const char * restrict str,\
					FILE * restrict stream);

int main(void) {
	char test_arr[LEN + 1];

	FILE *fp;
	fp = fopen("test14.c", "w");
	if (fp == NULL) {
		printf("File test14.c cannot be opened.\n");
		exit(EXIT_FAILURE);
	}

	file_put_string("Hi, there.\n", fp);
	file_get_string(test_arr, sizeof(test_arr), fp);

	for (int i = 0; i < LEN; i++)
		printf("%c", test_arr[i]);
	printf("\n");

	return 0;

}



char *file_get_string(char * restrict str,\
					int length,
					FILE * restrict stream) {
	int i, ch;

	for (i = 0; i < length - 1; i++) {
		ch = fgetc(stream);

		if (feof(stream)) {
			fclose(stream);
			printf("EOF error.\n");
			*(str + i) = '\0';
			return NULL;
		}

		if (ferror(stream)) {
			fclose(stream);
			*(str + i) = '\0';
			printf("Read error.\n");
			return NULL;
		}

		*(str + i) = ch;
	}

	*(str + i) = '\0';
	return str;
}


int file_put_string(const char * restrict str,\
					FILE * restrict stream) {
	int i, ch;

	while (*str) {
		fputc(*str++, stream);
		
		if (feof(stream)) {
			fclose(stream);
			printf("EOF error.\n");
			return EOF;
		}

		if (ferror(stream)) {
			fclose(stream);
			printf("Read error.\n");
			return EOF;
		}
	}
	return 0;
}

char *fget_string(char *s, int n, FILE *stream)
{
  int ch, len = 0;

  while (len < n - 1) {
    if ((ch = getc(stream)) == EOF) {
      if (len == 0 || ferror(stream))
        return NULL;
      break;
    }
    s[len++] = ch;
    if (ch == '\n')
      break;
  }

  s[len] = '\0';
  return s;
}

int fput_string(const char *s, FILE *stream)
{
  while (*s != '\0') {
    if (putc(*s, stream) == EOF)
      return EOF;
    s++;
  }

  return 0;
}
