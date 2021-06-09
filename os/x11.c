#include "x11.h"

#ifdef __linux__

#include <stdio.h>
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h> // for STDOUT_FILENO

struct winsize get_window_size(void);

void* _init_instance(ContainerSize* cs)
{
	struct winsize size = get_window_size();
	cs->cs_row = size.ws_row;
	cs->cs_col = size.ws_col;
	printf("%s", "\x1B[1m");
	// TODO - return display ptr
	return NULL;
}

struct winsize get_window_size(void)
{
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);	
	return size;
}

#endif // __linux__