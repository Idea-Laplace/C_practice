#ifndef LOOP_DECISION_H
#define LOOP_DECISION_H

#include <stdbool.h>

/**
 * void loop_decision(bool *loop) :
 *	This function would be called in a nested while(loop) loop.
 *	The function displays a message asking users whether you want to continue a loop process where the function is or
 * quit the loop by entering y or n. (case insenisitive).
 * Depending on user's reply, 
 **/
void loop_decision(bool *loop);

#endif
