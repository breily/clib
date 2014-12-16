#ifndef B_IO_H
#define B_IO_H

int BUFFER_SIZE;
int ERROR_BUFFER_SIZE_EXCEEDED;

char *bio_calloc();
void bio_free();

int breadline(char *);
int breadline_map(int (*func)(char *), char *);

#endif
