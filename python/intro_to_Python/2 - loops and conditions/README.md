# Loops and Conditions

There's quite a bit more to Python than just the basics, and loops/conditions,
but that's pretty much all you need to get started! There's just a few minor
differences between the languages so we'll outline them here.

## Note: `do-while`

I didn't include `do-while` as an example because Python doesn't have a
`do-while`! We kind of just fake it when we need it, no big deal.

## `for` Loop

This is going to be the longest section because `Python`'s `for` loops are kind
of weird, when compared to `C++`'s `for` loops.

`C++` uses the following syntax:

```cpp
for (initialize vars; loop condition; update vars) {
    // do stuff
}
```

`Python` works a bit differently. It uses this syntax:

```python
for var in iterable:
    # do stuff
```

Where an **iterable** is something that has multiple elements, like a list.

Before I get into what I did for the `for` loop in `program.py`, let me explain
how this loop works, to avoid confusion.

If we have a loop like:

```python
for num in [1,3,5,7]:
    print(num)
```

—it will go through all those numbers in order from the given list.

...If we have this:

```python
for character in "this is a cool sentence":
    print(character.toupper())
```

—it will go through each character and print it uppercase.

`Python`'s for loop doesn't really use a counter/increment/checking a condition
like in `C++`, it just goes through a collection of things like a list or a
string (which `Python` calls an **iterable**), element by element.

Now, back to what we had in `program.py`, what the `range` function does is
it generates a list so the `for` loop can work like the `C++` `for` loop.

The `range` function has these parameters: `range(start, stop, step)`, where:

* `start`: where the variable should start
* `stop`: where the variable should end
* `step`: how much to increment the variable by each loop

For example:

```python
for i in range(0,10,1):
    print(i):
```

—is the same as:

```python
for i in [0,1,2,3,4,5,6,7,8,9]:
    print(i)
```

### Note: C++ for loop addendum

`C++` also has a `for` loop like `Python`'s! It's just not used a lot in class.
Feel free to Google "C++ range-based for loop" if you're curious.

## `while` Loop

This one I'll skip explaining because `Python`'s `while` loop is functionally
the same to `C++`'s.

## `if`, `else if`, `else`

This will be short as well because there's only one major and one minor thing to
note here.

**Major note**: `Python` doesn't use `else if`, it uses `elif` to keep things
shorter.

**Minor note**: `Python` doesn't need parenthesis in its conditions, but feel
free to use them if you like!

## Conclusion

There are minor differences between loops and conditions for the languages;
mostly the `for` loop feels different, but the differences between the two
languages are otherwise pretty minor.
