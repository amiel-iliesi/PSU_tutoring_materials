# Tackling Problems — Methodology

This module is going to discuss how to approach a programming problem like the 
ones you see in your coursework. It will attempt to offer sound alternatives to 
the naive approach to programming out a project.

First, let's go over the approach that a student might take given the path of 
least thought/resistance. Let's see how it goes wrong.

In preperation for this module, I've written a fake assignment to pair with the 
content. It will serve to give context to the methodologies discussed here.

Read over the given example assignment and come back here afterwards.

## Naive Approach

A student might start running ahead and putting "pen to paper"--writing out the 
program requirements in code, such as the struct data members. This might even 
work, for smaller assignments, for a time.

The problem with just immediately writing out the assignment, from 
the top of the file--in the code is the problem of being too zoomed in, so to 
speak.

If a student starts writing the program, what happens in the following cases?:

* A revision is posted and they have to add a new field to the structure, or a 
new function is required to be implemented.
* Their approach to data storage turns out to be a dead end, and they have to 
modify all references to their array of tracks.
* They thought that they interpreted the idea of the track-list correctly, but 
it turns out that their misinterpretations mean that over half of what they 
wrote is unusable.

The list goes on, but the main idea is this: don't write yourself into a 
corner. The vast, *vast* majority of bugs arise from being too hasty. A little 
bit of planning goes a very long way, especially in multi-layered assignments 
like the following.

## Headspace

There are multiple steps to completing a project like this one, but the first 
thing is to make sure we're in the right headspace before we begin. Where 
should your head be when writing these assignments?

Always have the following idea at the top of mind when you're reading a project 
PDF or specification for the first time:

> What is this asking of me, practically?

A lot of students will just briefly skim a document outlining requirements, 
like the fake assignment given here. They will approach the assignment by rote 
application of the recent concepts they learned in class or in lab. They will 
think something like: "How can I put a for loop here? I remember seeing `i < 
size` so lets write that down."

The resulting code from this line of thinking is a half-functioning program 
with code written with the sole intention of taking up page space.

Your job isn't to write code.

Your job is to digest problems. You are a creative problem solver.

## Step 1 -- Assessment

The largest chunk of your time should be spent reading, planning, studying. By 
the time you are going to put code down on paper, you should already have a 
very strong understanding of what the assignment is asking of you.

I talk to lots of students in coding dead-ends in their programming 
assignments, and ask them plainly: "What is your program asking you to do?"

The answer should *not* be "I don't know" but it is often the case. How can you 
solve a problem that you can't visualize or verbalize? You can't solve a 
problem you can't articulate.

If you can't explain the problem or requirements, you need to re-assess the 
specification, not start writing code.

Spend a **very large** amount of time on this first step.

Like a smart sculptor, they will start by first imagining very carefully what 
they want to bring into the world, because a mistake takes a lot of time to 
rectify--it might even mean they need to start chiseling from scratch if the 
mistake is large enough. Before they touch the marble, any worthwhile sculptor 
can already mentally picture the final form.

Coding is the same. Changes are expensive--you have to edit all references, and 
fix all design patterns. A rewrite can be days of work--so minimize your 
rewrites.

Be able to understand the problem at hand before you touch the keyboard.

## Step 2 -- Planning

The following step after planning is to iteratively program out the solution, 
but planning and programming aren't super clear cut boundaries. Yes the bulk of 
the planning you will do in these small-scale projects is at the beginning as 
you make your design decisions, but the planning never really stops.

For example, if I was to plan out baking some cookies as a practical process, 
my first planning step might look something like this:

```md
**BAKE COOKIES**

1. Procure recipe.
2. Check pantry; ensure all ingredients are present.
3. Preheat oven.
4. Follow recipe.
5. Enjoy cookies!
```

This is a great first step, and all planning should start with the biggest 
chunks. A common problem I see with some students is they immediately start 
writing some of the inner functions of their programs. They have an idea and 
they want to commit it to paper before they forget. However if you lose sight 
of the forest for the trees, you might make mistakes. Being overeager to 
implement small details might mean you miss the obvious clue that it can't be 
implemented the way you were planning because of an overarching design decision 
at the most zoomed out scale. Or it turns out that you have to make many 
adjustments to make your original implementation fit--anyways.

To tie it back to the cookie-baking thought experiment above, imagine I didn't 
start with that generalized outline above, and later I stumble on the obvious 
roadblock that I'm missing ingredients because I forgot the step of checking 
my pantry. It's a costly step I wouldn't have missed if I started with the big 
steps first.

Next, maybe we programmed a little bit of the top level and we start planning 
our inner steps after the first iteration of planning. Now our baking program 
looks something like this:

```md
**BAKE COOKIES**

1. Procure recipe.
    * Ask Grandma, or Google.
2. Check pantry; ensure all ingredients are present.
    * Cooking ingredients:
        - sugar
        - flour
        - eggs
        - baking powder
        - sugar
        - vanilla
        - chocolate chips
        - cinnamon
        - salt
    * Supplementary: non-stick spray.
    * If ingredients are missing:
        1. Get wallet and car keys.
        2. Get in car.
        3. Drive to store.
        4. Purchase missing ingredients.
        5. Return home.
3. Preheat oven.
    * Crossref recipe: <375f>.
4. Follow recipe.
    * read @ ~/Documents/recipe.pdf
5. Enjoy cookies!
```

We've outlined some more of the nit-picky details that we omitted before, in 
ways that allow us to carry out the baking as a practical process.

We were only able to do this as we read the "recipe" and came up with a plan 
only after thorough assessment of the problem at hand. After thinking over some 
of the details we were able to plan those as well.

A minor addendum: plan for your code to be modified, and to be read by others. 
This makes sure you don't write yourself into a corner, and makes sure you plan 
to make your code more readable. Readability is a huge help when it comes to 
code bugs--lots of bugs seem to spring up when code is hard to parse. Don't 
think you're safe if your code is messy, because "I'm the only one reading it". 
If you find yourself jumping back and forth between different parts of your 
code, trying to grasp what's happening, the cause is usually poor readability. 
Also if you revisit old code after even just a few days, poor readability can 
slow code production speed--on top of the initial bugs it causes.

## Step 2.A -- Planning Styles

This is a minor addition to the planning step. Try and experiment with your 
planning. Since you haven't done too much programming yet, the way you plan for 
it is still unfamiliar to you. What works for you might not work for someone else.

In the above example I used a text outline for planning, but that doesn't work 
for everybody, or for all problems.

Depending on the person, or the problem, try drawing, diagrams, flow charts, 
create supplementary documentation for your code, etc.

Find what works for you and your own style of planning!

## Step 3 -- Iterative Programming

Solve the largest, most zoomed out problems first. This lets you double check 
your design decisions from steps 1 and 2, before you commit to all the minor 
implementation details.

If some of your largest problems require implementation details, it's fine to 
put in a temporary function that does nothing to notate a spot to return to.

For example, if you are writing a menu, something like this is acceptable for 
temporary blocking out of the code:
```cpp
void menu_main()
{
    switch(option) {
        case 'A':
            menu_A();
            break;
        case 'B':
            menu_B();
            break;
        case 'C':
            menu_C();
            break;
    }
}

// TODO
void menu_A() {
    println("*** menu_A()::not yet implemented.");
    return;
}
```

This way you can code out your largest design structures first, and still have 
a compiling program to test with.

If things dont pan out as you start implementing, just return to step 2 and 
re-plan your original designs.

That's it, just implement from the top-level down, as zoomed out as you can. 
This step is very short because the bulk of your work should be in planning and 
assessment. Steps 1 and 2 are the least visible in terms of output, but they 
should use up most of your time.
