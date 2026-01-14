# Complicated Error

This file has more moving parts so we will actually be able to make use of
`gdb` a bit more realistically.

I'll skip the basics like compiling, and I'll start using the shorthand for
certain commands now too! I'll make a key for them before we start.

## Command Shortcut Key

| shortcut | original command |
| -------- | ---------------- |
| lay src  | layout src       |
| n        | next             |
| b        | break            |
| r        | run              |
| s        | step             |
| bt       | backtrace        |
| c        | continue         |

## Follow Along

### Perform initial run with no breaks.

```gdb
(gdb) r

Program received signal SIGSEGV, Segmentation fault.
0x0000555555556bce in std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_data (this=0x0) at /usr/include/c++/13/bits/basic_string.h:223
223	      { return _M_dataplus._M_p; }
```

This is a lot less helpful, let me introduce to you a super amazing command!
`backtrace`, aka `bt`! `backtrace` lets you see the callstack at the point of
the command, or post-fault/abort.

### Print out backtrace to find origin of fault:

```
(gdb) bt

#0  0x0000555555556bce in std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_data (this=0x0) at /usr/include/c++/13/bits/basic_string.h:223
#1  0x0000555555557c04 in std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string (this=0x7fffffffdb20, 
    __str=<error reading variable: Cannot access memory at address 0x8>) at /usr/include/c++/13/bits/basic_string.h:551
#2  0x000055555555869b in Person::who[abi:cxx11]() const (this=0x0) at person.cpp:10
#3  0x00005555555577e7 in List::display_neighbors (this=0x7fffffffdb78, _name="Jeff") at list.cpp:51
#4  0x0000555555556617 in main () at main.cpp:19
```

Because this is a call stack, it's read like so, from the top-down: "call #0,
called by #1, called by #2, called by #3...". Or if read from the bottom up:
"#4 calls #3, calls #2, calls #1, ...".

Dissecting this call stack, we see that:
1. `main()` at `main.cpp` line 19 calls—
2. `list.display_neighbors("Jeff")` at `list.cpp` line 51 calls—
3. `person.who()` at `person.cpp` line 10

The remaining calls indicate some system calls, along with the helpful
information that the string failed to read memory: "Cannot access memory at
address 0x8". This means we're probably either out of bounds, or accessing some
invalid address somewhere.

The information we need is actually in the call stack, but if we don't see the
issue yet, we can re-run with the information we have to get some more
information.

### Re-run Slowly

Plan:
1. Run, and stop at the `display_neighbors` that fails on line 19.
2. Continue until we get to the offending function call.
3. Print out any variables that might be useful for us to observe.

*Note*: hit `Ctrl+L` to refresh the screen, if `cout`/`stdout`
interleaves/messes up the output.

```gdb
(gdb) lay src
(gdb) b main.cpp:19
(gdb) b List::display_neighbors(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) const
(gdb) r
(gdb) c
(gdb) c
```

Now, we can just step through, by repeating:
```gdb
(gdb) n
```
Until we get to the offending line, at `list.cpp`, line 51, like we saw in the
above `backtrace`. Once we get there, lets observe our variables that could
give us trouble on that line.

```gdb
(gdb) p curr  
$1 = (List::Node *) 0x55555556e2b0
(gdb) p curr->prev
$2 = (List::Node *) 0x55555556e2f0
(gdb) p curr->next
$3 = (List::Node *) 0x0
```

### Identify the Problem

...and there's our culprit. We are blindly trying to print out
`curr->next->data.who()` and `curr->prev->data.who()` without even checking if
`next` or `prev` even exist! In the case of the segmentation fault, we just
tried to access/dereference `data.who()` from a `nullptr`. Now that we know
where/what the problem is, we can just add bounds-checking!

### Additional Clues/Investigation

If we didn't spot the problem there, we could have stepped into the `cout`
calls to `data.who()` on `list.cpp` line 52, with the step command. We would
have seen this when we got to `curr->next->data.who()`, when we step:

```gdb
List::display_neighbors (this=0x7fffffffdb78, _name="Jeff") at list.cpp:52
(gdb) s
Person::who[abi:cxx11]() const (this=0x0) at person.cpp:10
```

With this we see that the `Person` object has an address of `0x0` which is
`nullptr`, which would have also let us spot the problem if we missed the clue
from earlier.
