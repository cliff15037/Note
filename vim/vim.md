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
- Basic movement: hjkl (left, down, up, right)
- Words: w (next word), b (beginning of word), e (end of word)
- Lines: 0 (beginning of line), ^ (first non-blank character), $ (end of line)
- Screen: H (top of screen), M (middle of screen), L (bottom of screen)
- Scroll: Ctrl-u (up), Ctrl-d (down)
- File: gg (beginning of file), G (end of file)
- Line numbers: :{number}<CR> or {number}G (line {number})
- Misc: % (corresponding item)
- Find: f{character}, t{character}, F{character}, T{character} find/to forward/backward {character} on the current line, / ; for navigating matches
- Search: /{regex}, n / N for navigating matches

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
