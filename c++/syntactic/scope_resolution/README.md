# Scope Resolution and Namespaces

Before we talk about what these both are, let's talk about the problem that
they solve. If we have two functions `f()` presently in view, but they come from
different places. You may want to be able to call one instead of the other, but
in order to do that you'd want to be able to do something like:

> Call function `f()` from region `A`, then call function `f()` from region `B`.

The scope resolution operator (`::`) lets you do that in both the case of basic
scope resolution, and in explicit namespacing.

To be more explicit, name spacing and scope resolution lets you cut up your
code, into separate regions that you can refer to by some title you give.

## Namespaces

We'll start with namespaces, because the example is simpler and so is the
functionality.

Take a look at `namespace/main.cpp` as you read this section.

As a hypothetical scenario, let's imagine you work for PSU and are developing
the Viking ToolKit (VTK). You want to make a bunch of C++ functions, variables,
and code which heavily overlap in name with the C++ standard library. 

Let's create an explicity boundary around our own creations with a namespace.

You'll notice that I made a namespace with the following syntax:
```cpp
namespace <NAME>
{
    // contents...
}
```

In this example, we have a `vector` type that we want to work with, that
specifies a 3D coordinate vector. We then want to put it in a standard library
`vector` container. We can refer to our own things from our `vtk` region—our
namespace—with the scope resolution operator (`::`).

It's used in the following manner:

```cpp
namespace::element
```

The operation is read from left-to-right, and you read the operator as "has".
Or conversely is read from right-to-left with "from".

And important for us, we read a template such as `T<U>` as "our type T is
composed of U".

For example`std::vector` is read as "the standard namespace **has** a vector".
With this in mind, let's try and read the whole declaration of our `vertices`
object, by putting all of the above, together:

```cpp
std::vector<vtk::vector> vertices;
```

"`vertices` **IS** a vector **FROM** the standard library(std), which is
composed of vectors **FROM** the Viking ToolKit(vtk)".

Finally, note that in main, we call a `display` function we declared in our
`vtk` namespace, which we can read as "display **FROM** vtk".

## Scope Resolution

For the following section, please refer to the `scope\ resolution` directory.

Scope resolution is a special type of namespacing operation, where the region
is specified by `class` or `struct` boundaries. I've also nested types to
showcase how we can chain scope resolutions, EG: `A::B::C`.

The `store` hierarchy is as follows:
```md
- Store:
    - Item:
        - string name
        - string UPC
        - unsigned qty
        - unsigned price_USD_cents

    - Region:
        - string category
        - vector<Item> items

    - vector<Region> regions
```

I've specified everything as a transparent `struct` to give ourselves ease to
emphacize the scope resolution operator.

Mostly take note of `main.cpp` for the time being.

In main, note how we both can specify a `Store` object (`main.cpp:6`), and that
we can also specify a reference to a `Region` (`main.cpp:27`). Because the
`Store` type is a top-level type, it doesn't need scope resolution to declare
the store. However, because the `Region` is a nested type in the `Store`, we
need scope resolution to interact with it from `main.cpp`.

Let's look at line 27 in `main.cpp`, after we've populated the store a bit.

We want to refer to a specific region in the store, so we want to declare a
reference to a `Region` object. Let's work backwards from english to construct
the declaration:

"`Kroger_deli` **IS** a reference to(&) a `Region` **FROM** the `Store`."

Put together, we get the declaration we have on line 27. I've also initialized
it to the result of a `get` call.

After looking at this example, and the `namespace` section above, it should be
pretty understandable by this point, but I encourage you to look through
`store.cpp` to see how scope resolution pops up throughout the implementation
of the functions you see in `main.cpp`.
