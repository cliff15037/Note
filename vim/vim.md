# Vim Usage Notes

## Vim Modes

- **Normal**: For moving around a file and making edits
- **Insert**: For inserting text
- **Replace**: For replacing text
- **Visual** (plain, line, or block): For selecting blocks of text
- **Command-line**: For running commands, use `:` to enter command-line mode

## Normal Mode Commands

- `x`: Delete the character under the cursor
- Undo: `Esc`, then `u`
- Redo: `Ctrl + r`

## Splitting Windows in Vim

- `Ctrl-w c`: Close the current tab (can also use `:q`)
- `:sp`: Create a new horizontal split
- `:vsp`: Create a new vertical split
- `:vsp file3.txt`: Open a vertical split and open `file3.txt`

## Switching Between Windows

- `Ctrl-w h`: Move to the window on the left
- `Ctrl-w j`: Move to the window below
- `Ctrl-w k`: Move to the window above
- `Ctrl-w l`: Move to the window on the right

## Managing Buffers

- `:ls`: List all open buffers
  - Example:
    ```
    :ls
    1 #    "test.txt"                     line 30
    2 %a   "my.txt"                       line 2
    ```
  - `%a` indicates the current editing file
  - `#` indicates the currently used file
- Switch to a buffer: `:b<number>`
- Kill a buffer: `:bd <number>`
  - `:bd`: Kill the current buffer
