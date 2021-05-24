#ifndef UNISTDK_H
#define UNISTDK

#include <scheduler.h>
#include <MemMang.h>
#include <stdlib.h>

void createProcess(void (*function)(),int foreground,char **argv, uint64_t *pid);
void exceptionProcess();

#endif