# First Debug

## Compiling

In order run `gdb`, you need to have `main.cpp` compiled with all the
information `gdb` needs in order to function. The `-g` flag in `g++` is how we
tell the compiler to include that extra information.

```sh
g++ -g ... 
```

## Running

After we compile with debug information included, we can start `gdb` like so:

```sh
gdb ./[PROGRAM]
```

...and now we should be in `gdb` running our file. This is where we can start
specifying things before we execute. We can tell the file where we would like
to pause for further observation.

Let's try running it in this order:

1. Ask for source code to be shown alongside, so we can more easily follow the
program flow:

```gdb
(gdb) lay src
```

2. Run it normally and see where the error occurs:

```gdb
(gdb) run
```
3. Read the error carefully:

> Program received signal SIGFPE, Arithmetic exception.
> 0x0000555555555347 in math_div (x=@0x7fffffffdc00: 8, y=@0x7fffffffdc04: 0) at main.cpp:33

We now know that the error occurs in `math_div(...)` with parameters `x=8`,
`y=0` along with some other information like the address of `x`, and `y`, as
well as the line number of the error (at `main.cpp:33`).

4. Let's get ready to restart the loop but more slowly, now that we have more
information. Let's tell the program to stop when we enter the `math_div`
function, since that's where the problem seems to be.

```gdb
(gdb) break math_div(int&, int&)
```

*NOTE*: You can hit `tab` to autofill the remainder of the function, so you can
just type `math_d` then hit `tab` to autocomplete.

5. Now let's restart the program execution by:

```gdb
(gdb) run
```

6. Let's print the values now that we've entered by typing:

```gdb
(gdb) print x
(gdb) print y
```

...and it looks like `x=8` and `y=0` just like we saw in the parameter list
before.

7. Let's step through the function until we hit the error:

If we step through, line by line we can see where the fault occurs:
```gdb
(gdb) next
(gdb) next
```

We fail on line 33 where we're running:

```c++
x /= y;
```

We now know these things:
- `x = 8`
- `y = 0`
- `x /= y` triggers the error, IE `8 /= 0`

Looks like a simple case of dividing by zero!
