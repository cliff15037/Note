## Sessions
- `tmux` starts a new session.
- `tmux new -s NAME` starts it with that name.
- `tmux ls` lists the current sessions
- Within tmux typing `<C-b>` `d` detaches the current session. (1) press Ctrl+b, (2) release Ctrl+b, and then (3) press d
- `tmux a` attaches the last session. You can use -t flag to specify which. `tmux a -t NUMBER`. `tmux attach -t session_name`

## Sessions Windows 
Equivalent to tabs in editors or browsers, they are visually separate parts of the same session
- `<C-b>` `c` Creates a new window. To close it you can just terminate the shells doing <C-d>
- `<C-b>` `N` Go to the N th window. Note they are numbered
- `<C-b>` `p` Goes to the previous window
- `<C-b>` `n` Goes to the next window
- `<C-b>` `,` Rename the current window
- `<C-b>` `w` List current windows

## Panes 
Like vim splits, panes let you have multiple shells in the same visual display.
- `<C-b>` `"` Split the current pane horizontally
- `<C-b>` `%` Split the current pane vertically
- `<C-b>` `<direction>` Move to the pane in the specified direction. Direction here means arrow keys.
- `<C-b>` `z` Toggle zoom for the current pane
- `<C-b>` `[` Start scrollback. You can then press <space> to start a selection and <enter> to copy that selection.
- `<C-b>` `<space>` Cycle through pane arrangements.
