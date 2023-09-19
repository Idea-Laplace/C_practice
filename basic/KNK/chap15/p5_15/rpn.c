#include "rpn.h"
#include <stdbool.h>

bool is_operator(char operator) {
	const char operator_arr[NUM_OPERATOR] = {'+', '-', '*', '/', '='};
	for (int i = 0; i < NUM_OPERATOR; i++)
		if (operator == operator_arr[i])
			return true;
	return false;
}

bool is_number(char number) {
	for (char ch = '0'; ch <= '9'; ch++)
		if (number == ch)
			return true;
	return false;
}
