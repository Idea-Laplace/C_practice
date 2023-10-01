#include <stdio.h>


int main(void) {
	int code, i;
	typedef struct {
		char *country;
		int code;
	} dialing_code;

	const dialing_code country_code[] = 
	{{"Argentina", 54}, {"Bangladesh", 880}, {"Brazil", 55}, {"Burma(Myanma)", 95},
	 {"China", 86}, {"Colombia", 57}, {"Congo, Dem, Rep. of", 243}, {"Egypt", 20},
	 {"Ethiopia", 251}, {"France", 33}, {"Germany", 49}, {"India", 91},
	 {"Indonesia", 62}, {"Iran", 98}, {"Italy",  39}, {"Japan", 81},
	 {"Mexico", 52}, {"Nigeria", 234}, {"Pakistan", 92}, {"Philippines", 63},
	 {"Poland", 48}, {"Russia", 7}, {"South Africa", 27}, {"South Korea", 82},
	 {"Spain", 34}, {"Sudan", 249}, {"Thailand", 66}, {"Turkey", 90},
	 {"Ukraine", 380}, {"United Kingdom", 44}, {"United States", 1}, {"Vietnam", 84}};


	printf("Enter a dialing code: ");
	scanf("%d", &code);
	for (i = 0; i < 32; ++i)
		if (code == country_code[i].code) {
			printf("It's the dialing code for %s\n", country_code[i].country);
			break;
		}

	if (i == 32)
		printf("There is no information of dialing code for %d\n", code);


	return 0;
}
