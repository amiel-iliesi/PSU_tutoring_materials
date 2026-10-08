# Menus

Within your classes, you will be asked to run some menus in the terminal. As
these get very long and nested, they kind of become disasterous to work with.
I've written two different versions of a single menu program. To illustrate the
better way to write menus.

## The Program

First let me explain what the program does. All it does is store calories from these sources:
1. **mealtime**: breakfast, lunch, dinner.
2. **type**: food, beverage.
3. **macro**: carbohydrates, protein, fiber, sugar, fat.

It stores the calories with the specific combination of the above given, and
reports the values in a tabulated overview.

## Monolithic

The monolithic version of the menu has it all together in one spot using
conditionals. This is the typical approach I see students use to write their
menus. I've intentionally written the expectation of the program to make this
approach especially difficult to take.

In fact I think I personally would have given up if not for some
well-positioned search-and-replace to help me along.

Anyways, we can see from the 700-ish line program that it is a nasty piece of
work. It is very indented, and we covered our program in temporary variables
that we don't need. It's hard to read, hard to work with, and hard to debug.

## Functional

This is the approach one should take when writing meuns that might have any
sort of nesting, or any sort of complexity above zero. All I've done is split
the menu into different functions for each layer. The parameters help send
information and dictate program flow within the menu functions.

Because of the way the parameters and functions are used, the number of lines
of code is *less than a third* of our monolithic version. This isn't even the
best benefit; I personaly believe that the fact that it's so much more readable
makes it that much more easy to work with and add new features on to--not to
mention how much easier this makes debugging.

Functions are wonderful for non-linear conditional execution like this!

I hope this demonstration has proved the value of function-driven menus.
