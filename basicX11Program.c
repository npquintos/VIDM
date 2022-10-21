#include <X11/Xlib.h> // Every Xlib program must include this
#include <assert.h>   // I include this to test return values the lazy way
#include <unistd.h>   // So we got the profile for 10 seconds

#define NIL (0)       // A name for the void pointer

Display *dpy = XOpenDisplay(NIL);
assert(dpy);

int blackColor = BlackPixel(dpy, DefaultScreen(dpy));
int whiteColor = WhitePixel(dpy, DefaultScreen(dpy));

// Create the window
Window w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0, 
				     200, 100, 0, blackColor, blackColor);

// We want to get MapNotify events
XSelectInput(dpy, w,StructureNotifyMask);

// "Map" the window (that is, make it appear on the screen)
XMapWindow(dpy, w);

// Create a "Graphics Context"
GC gc = XCreateGC(dpy, w, 0, NIL);

// Tell the GC we draw using the white color
XSetForeground(dpy, gc, whiteColor);

// Wait for the MapNotify event
for(;;) {
  XEvent e;
  XNextEvent(dpy, &e);
  if (e.type == MapNotify)
    break;
}

// Draw the line
XDrawLine(dpy, w, gc, 10, 60, 180, 20);

// Send the "DrawLine" request to the server
XFlush(dpy);

/* clear the window and bring it on top of the other windows */
XClearWindow(dpy, w);
XMapRaised(dpy, w);

/* it is good programming practice to return system resources to the 
   system...
*/
void close_x() {
	XFreeGC(dpy, gc);
	XDestroywdow(dpy,w);
	XClosedpyplay(dpy);	
	exit(1);				
}

// this call will allow us to receive input events
/* only Expose, ButtonPress and KeyPress events are regarded as valid. The Expose event type refers to when a portion of the window 
which had been obscured by another window becomes visisble again. This is usually handled by some sort of user routine to repaint the window.
Note: the redraws must be handle by the user! The below example assumes a routine redraw() has been written. Also notice how the KeyPress
event is handled. Pressing a 'q' will exit the program.
There are a lot of Event types and masks. Read the man pages on: XSelectInput and XNextEvent for more information. 
Also see /usr/include/X11 and search for NoEventMask. This will give you a complete list of all the different sorts of events there are.
It is worth noting that XNextEvent will block until another event comes through. So if no events occur, your program just sits there. 
XCheckWindowEvent is similar to XNextEvent (though it takes different arguments), but it returns a true (1) or a false (0) about whether or not 
an event occured. If an event did occur it fills an XEvent structure with info about the event. In either case, the program execution continues unabated.
*/

XSelectInput(dis, win, ExposureMask|ButtonPressMask|KeyPressMask);

{
/* look for events forever... */
	while(1) {		
		/* get the next event and stuff it into our event variable.
		   Note:  only events we set the mask for are detected!
		*/
		XNextEvent(dis, &event);
	
		if (event.type==Expose && event.xexpose.count==0) {
		/* the window was exposed redraw it! */
			redraw();
		}
		if (event.type==KeyPress&&
		    XLookupString(&event.xkey,text,255,&key,0)==1) {
		/* use the XLookupString routine to convert the invent
		   KeyPress data into regular text.  Weird but necessary...
		*/
			if (text[0]=='q') {
				close_x();
			}
			printf("You pressed the %c key!\n",text[0]);
		}
		if (event.type==ButtonPress) {
		/* tell where the mouse Button was Pressed */
			printf("You pressed a button at (%i,%i)\n",
				event.xbutton.x,event.xbutton.y);
		}
	}
}



