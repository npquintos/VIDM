# VIDM
Display Manager inspired by vim/tmux, a fork of DWM by Suckless.org

# Goals
- keybindings would be as near to vim as possible
- keybindings should be easy to remember and there should be just a few of them.
- keybindings should be easy to type. Numbers are hard to type, so avoid numbers
- avoid combinations like Ctrl-Alt or Ctrl-Alt-Shift unless they are unavoidable and they should be easy to remember
- Create a "Normal" mode, which applies to windows and an "Insert" mode that applies to contents of current window.

# Why fork DWM?
DWM uses Alt as modifier and many application uses Alt to access the menu. I believe this will create a lot of conflicts.
I also find the key bindings of DWM hard to remember. While I could simply modify conf.h to suit my preferred keybindings,
there are additional funcionalities that I wish to include namely:

## "Normal" mode that will apply to windows
##You go into *Normal* mode by pressing Alt-TAB, which also simultaneously select the previously selected window.##

When in normal mode, jklh will move between windows without modifier. You could access the same functionality while
in "Insert" mode but using the windows button in addition to jklh

When in normal mode, Alt-jklh will resize windows. You could access the same functionality while
in "Insert" mode but using the windows button in addition to Alt-jklh

When in normal mode, Shift-jklh will move windows. Take note that "Shifting" is almost synonymous to "moving" and hence,
easier to remember. You could access the same functionality while
in "Insert" mode but using the windows button in addition to Shift-jklh

When in normal mode, you could "mark" windows using 'm', just like in vim. Any window that are marked together goes to the same
*unused* workspace (or tags in DWM). <Enter> should be pressed when finished 'marking'; <Esc> to erase marked windows.
  
When in normal mode, <TAB> would cycle you through the different workspace (or tags in DWM). When in insert mode, Win-Tab does
the same thing.
  
When in normal mode, 's' would cycle you through the different 'screens' (or monitor). When in insert mode, Win-x does
the same thing.
  
When in normal mode, 'x' would exit/close (or delete as in vim) currently focused windows. When in insert mode, Win-x does
the same thing.

When in normal mode, 'z' would zoom in/out (it is a zoom toggle) the currently focused window. When in insert mode, Win-z does
the same thing. 
  
## You exit the "Normal" mode and enter the "Insert" mode by pressing <Enter> on a currently selected window. ##

