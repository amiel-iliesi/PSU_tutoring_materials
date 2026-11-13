# Planning -- Iteration 1

This planning step, and all the ones onward should be shorter. Most of the 
planning should be done at the beginning, since that's the time we have to make 
most of our decisions.

## Internal Monologue

So far I managed to complete the basic outline of my program, as well as some 
of the foundational types and their functionality.

Now I have to plan some of the minor details, and then implement them.

Here's my thought process, revisiting my closing thoughts from the last planning stage:

* The save/load can be left for last. If we can't make any use of the 
tracklist, there's no point trying to save it.
* The menus rely on the aggregate functions, so we have to define those first.
* The aggregate functions rely only on the track data details, and those are 
complete, so we can work on these now.

With that in mind, our progress today should go in this order:

```
aggregate functions -> menus -> save/load
```

Now that we've planned our initial stage, and carried out coding our 
foundation, we should just be able to write our code, smooth-sailing.

I'll come back here and detail any snags if I missed something.

...

Things I missed in the initial planning:
* tracklist.h/cpp: needed additional helper function(s).

Adjustments made:
* fixed minor formatting on track_data.cpp::display().
* tracklist.cpp::display_all_tracks(): put each entry on a new line
* modified menus to report status, and used the result to avoid saving when no 
changes were made
* makefile recipe target changed to comply with required program name

Also, I supplied a sample text file to load from.
