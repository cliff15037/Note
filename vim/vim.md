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
- If accidently press Ctrl+z, it will put process to back, use `fg` to get it to front, `jobs` to watch process ont he back.
- Basic movement: hjkl (left, down, up, right)
- Words: w (next word), b (beginning of word), e (end of word), a(append after the word)
- Lines: 0 (beginning of line), ^ (first non-blank character), $ (end of line)
- Screen: H (top of screen), M (middle of screen), L (bottom of screen)
- Scroll: Ctrl-u (up), Ctrl-d (down)
- File: gg (beginning of file), G (end of file)
- Line numbers: :{number}<CR> or {number}G (line {number})
- Misc: % (corresponding item)
- Find: f{character}, t{character}, F{character}, T{character} find/to forward/backward {character} on the current line, / ; for navigating matches
- Search: `/`{regex}, `n` / `N` for navigating matches
- `Ctrl D` is scroll down, `Ctrl U` is scroll up
- `o` open a new empty line under, and enter insert mode.
- `O` open a new empty line above, and enter insert mode.
- `dd` : can delete a whole line.
- `d` : is delete, can use combination command, `dh`, `dj`, `dk`, `dl`, delete left char, next line, pre line, right char, `de` delete to the end of the word.
- `c` is similar to `d`, change to the end of the word, and enter the insert mode.
- `r` is replace, `ra` to replace the char now to char a, press r as command, then press a as parameter
- Copy : `yy` copy the current line, `yw` copy the word, use `v` into visual mode to choose target the use `p` to paste
- Paste : `p` is paste
- `ci[` : change inside a [], make cursor on the [xxx], and use `ci[` can change it.

## Insert Mode
- `Ctrl D` delete the char

## Visual Mode
- `v` go to visual mode, and can choose char by char
- `V` go to visual line mode, and can choose line by line
- `Ctrl D` delete the choosen text
- `3e` : This is the combination of command, select 3 words, also can do lots of similar stuff. `2d` delete 2 line, `2de` delete 2 words. `8j` move down to 8 line later. 

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

- `:"qa`: close all windows

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
