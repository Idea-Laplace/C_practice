#ifndef SHOW_BYTES
#define SHOW_BYTES

#define HEX 16
#define BIN 2
#define MODE BIN
#define REVERSE true

void show_output_mode(void);

void show_int(int i);
void show_float(float f);
void show_double(double d);
void show_pointer(void *p);

#endif
