// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/* sampleCodeModule.c */
#include <stdio.h>
#include <Shell.h>
#include <syscallsASM.h>
#include <stdint.h>
#include <unistd.h>
#include <chess.h>
#include <stddef.h>
// #include <testProces.h>


char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;


int main() {
	*v = 'X';
	*(v+1) = 0x74;

	char *argv[2];
	argv[0] = "shell";
	argv[1] = NULL;
	createProcess(init_shell,1,argv);
	// nice(0,20);
	// createProcess(chess,argv);
	while (1)
	{
		/* code */
	}
	


	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;

	return 0xDEADBEEF;
}
