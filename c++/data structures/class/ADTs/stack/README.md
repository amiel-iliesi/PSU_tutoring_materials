# Abstract Data Types

Abstract data types are distinct from their underlying data types, although
their relationship to one another is closely linked.

Abstract data types (ADTs) have a distinct set of ways you interact with them,
and the user of the ADT shouldn't care what data structure is at the core of
it.

As an analogy, if we have Cars and Engines, the ADT is the Car and the data
structure is the Engine. The user knows that you have pedals, doors, wipers,
turn signals, and the interface for these operations is similar from car to car.
Underlying these though, a car might be made of steel, composite, it might have
an electric motor instead of a combustion engine. *How* it works is important,
but not to the user.

The same goes for ADTs. How you make it do what your functions and prototypes
outline is up to you, the user shouldn't need to care.

I've implemented with two underlying structures, but the `main.cpp` is the same
in both cases! This should help illustrate the difference between ADTs and DSs.
