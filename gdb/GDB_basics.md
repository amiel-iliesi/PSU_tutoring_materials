# GDB Basics

# Prerequisites

You need to compile with the `-g` flag, otherwise your GDB can't include human
readable information to debug with.

```sh
g++ -Wall -g *.cpp
```

# Basic Usage

## Changing Layouts
* `lay[out] <layout type>`


## Adding and Removing Breakpoints
* adding: `b[reak] <function name>` **OR** `b <file_name:line_number>`
    * ex: `b main.cpp:47` **OR** `b Candy::add(Node*&, const Candy&)`
    * tab for autocomplete of function names

* displaying: `info breakpoints`

* deleting: `delete [#]`

* clear all breakpoints: `clear`



# Displaying Information

* print out a variable: `p[rint] <var name>`
    * print out an array: `p <var name>@length`
    * character arrays are so common, you can just print them out like normal;
      no need to do the above.

* print out a variable (update every time): `display <var name>`

* remove a display call: `undisplay <#>`



# Moving

* go to next line: `n[ext]`

* step into current line's operation: `s[tep]`

* continue to next breakpoint: `c[ontinue]`

* finish a function and display the return value: `'fin[ish]`



# Stack Trace

* to show a function's stack trace (including after a seg fault):
    `bt` **OR** `backtrace`
