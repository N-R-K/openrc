#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <X11/Xlib.h>

int main(void)
{
	char *s;
	Display *dpy = XOpenDisplay(NULL);
	if (!dpy) {
		fprintf(stderr, "XOpenDisplay failed\n");
		return 1;
	}

	if ((s = getenv("DISPLAY")) != NULL)
		printf("DISPLAY='%s'\n", s);
	if ((s = getenv("XAUTHORITY")) != NULL)
		printf("XAUTHORITY='%s'\n", s);
	fflush(stdout);

	dprintf(3, "READY=1\n");
	close(3);

	for (XEvent ev; XNextEvent(dpy, &ev) == 0;)
		;

	return 0;
}
