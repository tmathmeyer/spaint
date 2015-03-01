#define _DEFAULT_SOURCE

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    Display *d;
    Window w;
    XEvent e;
    int s;

    d = XOpenDisplay(NULL);
    if (d == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 100, 100, 1,
            BlackPixel(d, s), WhitePixel(d, s));
    XSelectInput(d, w, ExposureMask | KeyPressMask | ButtonPressMask | PointerMotionMask);
    XMapWindow(d, w);

    while (1) {
        XNextEvent(d, &e);
        if (e.type==MotionNotify) {
            XFillRectangle(d, w, DefaultGC(d, s), e.xmotion.x, e.xmotion.y, 5, 5);
        }
    }

    XCloseDisplay(d);
    return 0;
}
