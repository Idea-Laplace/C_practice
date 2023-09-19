// This header file supplies loop_decision fuction.
#ifndef LOOP_TEMPLATE_H
#define LOOP_TEMPLATE_H
#
#include <stdbool.h>
/****************************************************
 * loop_decision(bool *loop) : This function should *
 * be called in a while(loop) so that the function  *
 * could access the bool type variable loop, once   *
 * the function is called, it asks you whether the  *
 * given process need to be continue. Users can     *
 * input 'y[Y]' or 'n[N]' according to their decis- *
 * -ion. Any other input would let the function     *
 * print guideline message and repeat the input     *
 * process.                                         *
 ****************************************************/
void loop_decision(bool *loop);
#
#endif
