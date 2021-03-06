#ifndef PHYLO
#define PHYLO

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <mySemaphore.h>
#include <syscallsASM.h>
#include <pipe.h>
#include <stddef.h>

#define INITIALPHYLOSOFERS 5
#define MAXPHYLOS 10
#define MINPHYLOS 2
#define SEMPHYLO "phylos"

void phyloMaster(int argc, char **argv);

#endif