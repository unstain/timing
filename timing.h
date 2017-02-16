#include <time.h>

#define TICTOC_SIZE 20
struct timespec tictoc_arr[TICTOC_SIZE];
unsigned char tictoc_index = 0;
void tic();
long vartoc(unsigned int precision);
long toc();
long mtoc();
long utoc();
long ntoc();
