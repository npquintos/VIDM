**Alt-Tab** will go to prevous window and enter the **Normal** mode. Alternatively, **Caps-lock** will toggle between **Normal** and **Insert** mode.

## variables used to keep track of desired actions:##
  - **select_mode** --> could be either 0 (not selecting windows) or 1 (selecting windows)
  - **win_for_copying** --> array containing pointers to windows that are to be copied to another tag (workspace). This is populated by pressing 'y' (as in 'yank') on the focused window.
  - **win_for_moving** --> array containing pointers to windows that are to be moved to another tag. This is populated by pressing 'x' (similar to delete in vim) on the focused window.
  
  
  - Normal Mode
      - Select Mode
        - jkhl --> move to the next window
      - Non-Select Mode
      
