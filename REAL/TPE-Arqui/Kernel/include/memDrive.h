#ifndef MEMDRIVE_H
#define MEMDRIVE_H

#include <stdint.h>

void sbrk(uint64_t size,void ** answer);

#endif