# Planning -- Iteration 0

## Internal Monologue

First thing's first, let's establish our program's foundation. We can start 
with some of the most basic pieces. What things in this program that are 
depended on, but don't have any dependencies themselves?--The things that are 
foundational. The first thing that comes to mind is the `Track` type 
definition. It depends on nothing but fundamental types, so we can implement it 
straight away without any complications. It's a straight up type definition, no 
frills. I think we should put it in it's own file, that way if we need helper 
functions for the type, we can define them there too.

Next, let's try and imagine some interactions, this is going to help guide how 
we write our functions later.

Here's how the menu should look, as well as some example interactions with it:

```
*** Tracklist reading from `tracklist_db.txt`.
*** 83 tracks loaded.

1. Add new track.
2. Update track.
3. Delete track.
4. List all tracks.
5. Display track info.
6. Quit.

>>> 5
>>> track name: Scene Seven: I. The Dance of Eternity
>>> artist: Dream Theater

Track Info:
- name: Scene Seven: I. The Dance of Eternity
- artist: Dream Theater
- duration: 6:14
- genre: Progressive Metal
- album: Metropolis, Pt. 2: Scenes from a Memory

1. Add new track.
2. Update track.
3. Delete track.
4. List all tracks.
5. Display track info.
6. Quit.

>>> 2
>>> track name: <PLACEHOLDER TRACK NAME>
>>> artist: Jimmy Rosenberg

Found:
- name: <PLACEHOLDER TRACK NAME>
- artist: Jimmy Rosenberg
- duration: 3:48
- genre: <UNKNOWN>
- album: Trio

>>> Edit? (Y/N): y
>>> name: Chega De Saudade (feat. Nomy Rosenberg)
>>> artist: Jimmy Rosenberg
>>> duration: 3:48
>>> genre: Gypsy Jazz
>>> album: Trio

1. Add new track.
2. Update track.
3. Delete track.
4. List all tracks.
5. Display track info.
6. Quit.

>>> 6

*** Saved tracklist to `tracklist_db.txt`.
*** 83 tracks saved.
```

With this, we can block out our main menu structure and get started there.

Writing out this usage example text for the menu, I have some ideas!

### Reusable Function Ideas

Here are some helper functions we should implement before writing all the 
larger details.

**Find track** by name and artist is reused a couple times, namely on menu 
items 2, 3, 5. So it should be a function we can reuse! **NOTE**: because 
delete needs the position of the track in order to remove it, this function 
should return a *pointer*. This also has the added benefit of being able to 
return `nullptr` if it can't find the track.

Next, **track entry** is reused on menu items 1, 2. That should also be a 
reusable function.

Also, **display track** used on menu items 2, 5.

Finally, we'll probably want to move tracks around in the code, so let's write 
a **track copy** function, to help with that.

### Overall Structure

Here's the outline I've come up with--to start:

```md
## Top-Level
1. Load file from hard-coded filename, on entry: tracklist_db.txt.
2. Run `menu_main`:
    * `menu_main` will present all top level functions for the tracklist.
3. Save to file on quit.

## `menu_main`
* `menu_add_track`
* `menu_update_track`
* `menu_delete_track`
* `display_all_tracks`
* `menu_track_info`
* QUIT

## `menu_add_track`
1. Check if array has any more room. Leave if not, and inform the user.
2. Call *helper function* **track_entry** and enter at the end of the array.

## `menu_update_track`
1. Call *helper function* **find track**.
2. If the track isn't found, leave and inform the user.
3. Call *helper function* **display track**.
4. Ask user if they want to update the track found. Leave if not.
5. Call *helper function* **track entry** on the location that step 1 found.

## `menu_delete_track`
1. Call *helper function* **find track**.
2. If the track isn't found, leave and inform the user.
3. Perform delete on the array. This involves our *helper function* **copy 
track**. Look at the accompanying sketch `deleting.png` to see how to do this.

## `display_all_tracks`
**example**:
artist1 - song name, artist2 - another song, ...

1. Loop through each array index.
2. Display just the name and artist. The user can use those 2 details to 
display all info from the main menu later, if they want.
3. Make this a single line, comma seperated. Look at the example above.

## `menu_track_info`
1. Call *helper function* find_track.
2. If the track isn't found, leave and inform the user.
3. Call *helper function* **display track**.

## QUIT
Just run the save function and give diag info to user as you do so.
```

Looks like we have enough implementation details planned out to start basic 
function prototyping, and program structuring. Now (and **only** now that I've 
done this planning) it's time to start work on our program basics. I've done 
the preliminary work outlined here in `./source_code/`.

## Post Code Writing Thoughts

After writing the code, I've returned here to document my progress and thoughts.

I was able to implement the following:
| What                        | Status              | Where            |
| --------------------------- | ------------------- | ---------------- |
| Track type definition       | Complete            | track_data.h/cpp |
| Track type helper functions | Complete (untested) | track_data.h/cpp |
| Track aggregate functions   | Prototypes defined  | tracklist.h/cpp  |
| Menus/IO                    | Outline complete    | main.cpp         |

Next planning iteration should iron out the details of the incomplete parts.
