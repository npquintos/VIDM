# VIDM
Display Manager inspired by vim/tmux, a fork of DWM by Suckless.org

# Goals
- keybindings would be as near to vim as possible
- keybindings should be easy to remember and there should be just a few of them.
- keybindings should be easy to type. Numbers are hard to type, so avoid numbers
- avoid combinations like Ctrl-Alt or Ctrl-Alt-Shift unless they are unavoidable and they should be easy to remember
- Create a "Normal" mode, which applies to windows and an "Insert" mode that applies to contents of current window.

# Why fork DWM?
DWM uses Alt as modifier and many application uses Alt to access the menu. I believe this will create a lot of conflicts. I also find the key bindings of DWM hard to remember. While I could simply modify conf.h to suit my preferred keybindings, there are additional functionalities that I wish to include namely:

## "Normal" mode that will apply to windows
## You go into *Normal* mode by pressing Alt-TAB, which also simultaneously select the previously selected window, or by pressing Caps-Lock, which is remapped and is no longer functioning as usual ##

  -  jklh will move between windows without modifier.
  -  Alt-jklh will resize windows.
  -  Shift-jklh will move windows. Take note that "Shifting" is almost synonymous to "moving" and hence, easier to remember.
  - "mark" windows using 'm', just like in vim. Any window that are marked together goes to the same *unused* workspace (or tags in DWM). *Enter* should be pressed when finished 'marking'; *Esc* to erase marked windows.
  - *TAB* would cycle you through the different workspace (or tags in DWM).   
  - *x* would 'cut' the current window with the intention of 'pasting' it on another workspace with *p*. 
  - *y* would 'yank' the current window with the intention of 'pasting' it on another workspace with *p*. The difference with *x* is that in *x* would remove the window from that workspace whereas not so with *y*.
  - *s* would cycle you through occupied 'screens' (or monitor). 
  - *c* would exit/close (or delete as in vim) currently focused windows.
  - *z* would zoom in/out (it is a zoom toggle) the currently focused window. 
  - ' ' (*Space*) would activate dmenu to run aplications
  - '/' would allow you to search for a particular window by matching on the window title.  

__In general, anything you could do in *normal* mode can be done in *insert* mode by prepending the corresponding normal keys with *Win* modifier__
This would make the keybindings very easy to remember.

## You exit the "Normal" mode and enter the "Insert" mode by pressing *Enter* on a currently selected window. ##

