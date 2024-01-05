#ifndef QUEUE_ADT_H
#define QUEUE_ADT_H

#include <stdbool.h>

typedef int ITEM;
typedef struct queue *Queue;

Queue create_queue(void);
void destory_queue(Queue qu);

void insert_item_queue(Queue qu, ITEM data);
ITEM pop_item_queue(Queue qu);

ITEM check_entrance_queue(Queue qu);
ITEM check_exit_queue(Queue qu);

void make_empty_queue(Queue qu);
bool is_empty_queue(Queue qu);

#endif
