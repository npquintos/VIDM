**Alt-Tab** will go to prevous window and enter the **Normal** mode. Alternatively, **Caps-lock** will toggle between **Normal** and **Insert** mode.

## variables used to keep track of desired actions:
  - **win_for_copying** --> array containing pointers to windows that are to be copied to another tag (workspace). This is populated by pressing 'y' (as in 'yank') on the focused window. 
  - **win_for_moving** --> array containing pointers to windows that are to be moved to another tag. This is populated by pressing 'x' (similar to delete in vim) on the focused window. 
  - **win_for_closing** --> array containing pointers to windows that are to be closed permanently
  
  
  ## Normal Mode
 - jkhl --> (navigate) move to the next window. That window will be momentarily be in focus to show contents but will not stay there unless **Enter** is pressed. In that way, the previously visible window is not clobbered.
 - <Shift> hl --> (navigate) move to the next tag. <Shift> is used to be similar to AstroNvim when moving from tab to tab. Tab is similar to tags.
 - x    --> (delete) mark focused window for moving; insert window pointer to  **win_for_moving** array. Pressing x twice over the same window will undo the selection.
 - y    --> (yank) mark focused window for copying; insert window pointer to  **win_for_copying** array. Pressing y twice over the same window will undo the selection.
 - p    --> (paste) copy windows stored in win_for_copying array and move windows stored in win_for_moving array to currently focused tag. Delete the contents of both win_for_moving and win_for_copying. You are still in Normal mode after this operation. If the currently selected tag has windows in it, the copied and moved windows will simply be added to the existing ones. If p is pressed without going to a different tag, no change will happen.
 - c    --> (close) make currently focused window disappear as if closed, then store window reference into win_for_closing array. The intention is to allow the 'closing' to be undone via 'u' (undo) prior to pressing <Enter>. Closing could not be undone after pressing <Enter>.
 - u    --> (undo) restore the windows stored in  win_for_closing. Delete contents of win_for_moving and win_for_copying
 - Enter -> copy windows stored in win_for_copying array and move windows stored in win_for_moving array to currently vacant tag. Those for moving and those for copying will go to 2 separate vacant tag. Delete the contents of both win_for_moving and win_for_copying. Permanently close the windows that are stored in win_for_closing; delete contents of this array when done closing. You are still in Normal mode after this operation.
      
      
      
      
