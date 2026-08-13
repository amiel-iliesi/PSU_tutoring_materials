# Types in Python

## Summary
Although Python is [dynamically typed](https://developer.mozilla.org/en-US/docs/Glossary/Dynamic_typing) and has no need for types, Python has [a manual, opt-in type system](https://docs.python.org/3/library/typing.html).

## Motivation
It's not like Python's typing will give you a runtime exception or something
like a strongly typed programming language, but there are various benefits you
get by choosing to label your variables and functions with types.

The biggest benefit is static type checking. Labeling your types enables your
IDE to run various checks for you, like--have you validated your input? Is it
possible for this type to be `None`? It ensures that you aren't using your
variables in undefined ways, and makes your code much more safe.

It also provides tokens in the global space for you to use for your IDE's
suggestions. For example, if you have a variable called `A` and you label it as
a string, then when you start to member-access `A` like: `A.`, the IDE will
help you and suggest string's functions and data members for you to use. It
helps with discoverability and faster typing as well. This also results in
fewer spelling mistakes of function names, and the like.

## Extensions

Install `Mypy Type Checker` as an extension to get a Python Typing compliant extension.

**VSCode**: `ms-python.mypy-type-checker`.

## Basic Syntax

### Variable Labeling

```py
n: int = 5
x: float = 5.0
heights_cm: list[int] = []
```

### Compound Types

```py
coord: tuple[float, float] = (0.0, 0.0)
```

### Unions

```py
Numeric = int | float 
x: Numeric = 5
```

### Typing Library

The [Typing library](https://docs.python.org/3/library/typing.html) has some useful types you may want to use, for example if something can be None, you can use [`Optional`](https://docs.python.org/3/library/typing.html#typing.Optional):

```py
from Typing import Optional

suspect: Optional[str] = None
```

or, `Any`, if the type is uncertain and needs to be checked:

```py
from Typing import Any

x: Any = f()

if isinstance(x, int):
    print('Nice, x is the right type')
else:
    raise TypeError(f'{x} is not an int')
```

And as a nice bonus, the IDE--within that `if` block, will know that x is an
integer, due to the `if` condition. The static checking knows which zones hold
which potential types. Very neat!

### Functions

They use an arrow syntax for the return type, but besides that are no different
from the above examples:

```py
def max(a: int, b: int) -> int:
    #...
```


## More

I included a file with various type hinting things in it, feel free to explore!
