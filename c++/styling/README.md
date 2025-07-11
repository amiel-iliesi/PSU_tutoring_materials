# Styling: Importance In Programming

## Setup

I've prepared two files. `hard2read.cpp` and `easy2read.cpp`. They both do the
same thing, but one of them is following proper styling, and the other one is
not.

### Files
```
- makefile: makes the files

- easy2read.cpp
    - primes.cpp: used by easy2read.cpp
    - primes.h:   used by easy2read.cpp

- hard2read.cpp: same as easy2read.cpp (in functionality)
```

Use the makefile like so:


Below is the list of rules that one file is following, and the other is fully
ignoring. Hopefully, this contrasting demonstration will help you more
appreciate the value of proper styling in your files.

## Rules to Follow

* **Be Consistent**: If there are multiple agreed upon formats for a rule, pick
                     one and stay with it. This is the most important rule.

* **Use Spacing**: Spacing can make or break readability. No spaces, too many
                   spaces, or inconsistent spacing can make it difficult to
                   read through your program.

* **Be descriptive**: Your variable names should describe their identity,
                      purpose, and units. If you need to comment what your
                      variable is doing, it might need to be renamed.

* **Comment sparsely**: This one is more contentious—for some reason—but you
                        Should only comment when necessary. Think of those
                        times where someone goes crazy with a highlighter in
                        a textbook or notebook. If it's all highlighted and it's
                        all important, then none of it is, and none of it sticks
                        out—when it matters.

* **Use more files**: Computer storage isn't so small these days; don't fight
                      for kilobytes, and use files to separate things based on
                      functionality. Otherwise, it's like reading a book without
                      chapters and sections.
