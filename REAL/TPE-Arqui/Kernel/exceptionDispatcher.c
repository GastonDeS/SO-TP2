#ifndef EXC_DISPATCHER
#define EXC_DISPATCHER

#include <regi.h>
#include <interrupts.h>
#include <exceptions.h>
#include <scheduler.h>

void printException();

void exceptionDispatcher(uint64_t exc, registerStruct * registers) {
  switch(exc) {
    case 0: exc_0h(registers);
    break;
    case 6: exc_6h(registers);
    break;
  }
  exceptionProcess();
}

#endif
