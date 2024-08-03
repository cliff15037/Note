Vim has multiple operating modes.

-Normal: for moving around a file and making edits
-Insert: for inserting text
-Replace: for replacing text
-Visual (plain, line, or block): for selecting blocks of text
-Command-line: for running a command


In Normal mode:
    x will delete the character under the cursor.
    If want to undo it: Esc, then use 'u'
    If want to redo it: Ctrl + r

Split in vim:
    Ctrl-w then c（Ctrl-w c）to cancel cur tab. (can also use :q)
    :sp, :vsp to create new tab
    :vsp file3.txt    # open a split window and open file name file3.txt
  Change between tab:
  Ctrl-w then h：to left
  Ctrl-w then j：to down
  Ctrl-w then k：to top
  Ctrl-w then l：to right

List all vim:
  :ls
  For example:
    :ls
    1 #    "test.txt"                     line 30
    2 %a   "my.txt"                       line 2

    %a is the current editing file.
    # is current used file.
Change to a window:
  :b<number>
Kill buffer:
  :bd number
  :bd      #This can kilkl current buffer
