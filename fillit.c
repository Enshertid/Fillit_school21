#include "unistd.h"
#include "stdlib.h"

#include "fillit.h"

void error(void)
{
	write(1, "error\n", 6);
	exit(0);
}
