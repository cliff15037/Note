## Sessions
- `tmux` starts a new session.
- `tmux new -s NAME` starts it with that name.
- `tmux ls` lists the current sessions
- Within tmux typing `<C-b>` `d` detaches the current session. (1) press Ctrl+b, (2) release Ctrl+b, and then (3) press d
- `tmux a` attaches the last session. You can use -t flag to specify which. `tmux a -t NUMBER`
