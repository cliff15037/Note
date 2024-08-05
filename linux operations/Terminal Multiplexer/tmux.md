## Sessions
- `tmux` starts a new session.
- `tmux new -s NAME` starts it with that name.
- `tmux ls` lists the current sessions
- Within tmux typing `<C-b>` `d` detaches the current session. (1) press Ctrl+b, (2) release Ctrl+b, and then (3) press d
- `tmux a` attaches the last session. You can use -t flag to specify which. `tmux a -t NUMBER`

## Sessions Windows 
Equivalent to tabs in editors or browsers, they are visually separate parts of the same session
- `<C-b>` `c` Creates a new window. To close it you can just terminate the shells doing <C-d>
- `<C-b> N` Go to the N th window. Note they are numbered
- <C-b> p Goes to the previous window
- <C-b> n Goes to the next window
- <C-b> , Rename the current window
- <C-b> w List current windows
