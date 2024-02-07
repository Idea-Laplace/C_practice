#ifndef _INVENTORY_H
#define _INVENTORY_H

struct part;

void insert(struct part **inventory_addr);
void search(struct part *inventory);
void update(struct part *inventory);
void print(struct part *inventory);
void dump(struct part *inventory);
void destroy(struct part *inventory);
void restore(struct part **inventory_addr);

#endif
