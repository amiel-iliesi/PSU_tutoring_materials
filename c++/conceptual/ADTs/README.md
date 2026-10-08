# ADTs

This directory will teach you about the difference between a **data
structure**, and an **abstract data type**.

## Data Structures

Data structures are containers for groups of elements. They describe *what*
data is held in memory.

## Abstract Data Types

Abstract Data Types (ADTs) are container wrappers that define an **interface**
to the container. They have a private--*inaccessible*--section, that is only
modified internally, and they have a public section, that defines a *strict*
way for the user to interact with the underlying data.

ADTs describe *how* the data is interaced with.

## Conceptualizing the Difference

Let's think of a real world thought experiment to illustrate the difference.

Imagine a group of people are attending a party you're hosting. There's music
playing, and you want to set up a song-request system.

For the above scenario, a **data structure** might be used to represent a
register of the people attending--like a paper list, spreadsheet, or RSVP. An
**abstract data type** might be used to represent the request order for the
music booth--like a *queue*.

The **data sturcture** registry example makes no restrictions, nor imposes any
procedure on its data. Names are read and written to the log freely. As for the
**abstract data type** *queue* for the music requests, there is an order, so
things can only be added to the end, and only the oldest song in the queue is
played next.

The difference between **data structures** and **ADTs** is therefore mostly
semantic, and slightly structural. One describes storage, the other describes
usage.

## Files

Take a look, first at `list.cpp` and `list.h` to see my implementation of the
*doubly linked list* **data structure** that the *queue* **abstract data type**
will use as it's underlying container.

Next, take a look at `queue.cpp` and `queue.h` to see my implementation of the
*queue* **ADT**.

Finally, take a look at `main.cpp` to see it running the *queue* in a simple
demonstration.

Take note of two things:

1. How much simpler the definition of the queue is.
2. How all it really defines is the mode of interaction with the underlying container.

That's all that **ADTs** really do, they semantically define an interaction
with an underlying **data structure**.
