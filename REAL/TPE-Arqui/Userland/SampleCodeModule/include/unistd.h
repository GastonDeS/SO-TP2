#ifndef UNISTD_H
#define UNISTD

#include <syscallsASM.h>
#include <stdint.h>

uint64_t createProcess(void (*function)(),int fg,char **argv);
int nice(uint64_t pid, uint64_t prio);
int block(uint64_t pid);
int unblock(uint64_t pid);
int kill(uint64_t pid);
uint64_t getPid();
void yield();
void myExit();

#endif