# Introduction

Welcome to Python programming! This guide assumes you came from C++ and are
looking to learn some Python.

## Applications and Environment

You can program in whatever you like. You can write Python in Vim even, but
using an IDE like Visual Studio Code really helps in a language like Python
because of how Python relies on libraries and importing. It makes it way easier;
you don't have to remember all function names, and objects and stuff like that.

This `0 - background` chapter will lead you through setting up a fairly basic
IDE for Python, but you can ignore this chapter if you'd like to just use Vim,
or if you already have VSCode set up how you like it.

## Visual Studio Code

The IDE of choice for most of the industry is VSCode, and it's a great choice
for us here with Python, also.

You can download VSCode here: <https://code.visualstudio.com/>

Just follow the relevant install instructions for your operating system there.

## Python Extensions

VSCode is very versatile and works for hundreds of languages and file types.
Because of that, we need to download extensions to make it work for what
programming environment we intend to use.

When you open VSCode you will see a few things, but all we need to look at for
now is the `extensions` pane in the `side panel`. To see where this is, look at
`"VSCode Overview.png"` in the `"figures"` folder.

I've grouped them into three categories. You can find a picture of these
extensions in `figures/Python extensions.png`.

### 1: Necessary

In order to run Python on VSCode, you'll need these to run your `.py` files:

1. `Python`: this extension gives VSCode the ability to run Python files, at
   at all. You will definitely need this. It should automatically install the
   next two extensions listed here as well.

2. `Python Debugger`: This will allow you to debug your files.

### 2: Good to Have

1. `Pylance`: This is what does live error checking, plus a few other things.

### 3: Extras I Really Like

1. `autopep8`: This will let you automatically space/indent/format your files
   with the push of a shortcut. You can find that shortcut here:
   `https://code.visualstudio.com/docs/editor/codebasics#_formatting`

2. `Flake8`: Python has a style guide that is very strongly adhered to called
   `pep8` which you can google if you like. `Flake8` is kind of like an error
   checker, but for the official style guide.

3. `Mypy Type Checker`: Python doesn't have type checking by default, but this
   extension lets you keep track of the types you're using.

## Conclusion

With all of these installed, we're ready to start looking at code. My figures
will use the VSCode setup I've guided you through, but feel free to use Vim if
you like. I'll include how to run files from the terminal for the first chapter
as well just in case you don't want to use VSCode.
