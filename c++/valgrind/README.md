# Valgrind

**Note**: Start with the files in the `./unsolved` directory. The key will show
you what the files look like as you follow along on this guide, step by step,
so you can verify your results! Don't skip ahead.

These files are here to help you learn how to use Valgrind effectively. If you
have memory leaks, they are actually far less daunting to deal with if you use
the tools you have available to you.

Valgrind can do a lot, but its output is pretty verbose. That doesn't mean our
eyes should just glaze over, and have us resort to trial-and-error. If we give
Valgrind a proper chance, it actually simplifies our life massively!

As a minor note: these errors can be solved by using proper memory management
techniques to begin with, as well as the `std::optional` feature, rather than
using pointers to do the same thing—but unsafely.

## Program Structure

First, let me outline the program structure so that you can think about where
the errors might occur.

```
Book:
    - string title
    - string author
    - optional: string sequel_ptr

BookList: A LLL of Book Nodes

Reader:
    - string Name
    - BookList favorite_books
```

The book is a single element that gets put in a book list. The reader has one
of these book lists, which holds their favorite books.

## First Run

Run the program by running the following command:

```bash
valgrind --tool=memcheck ./books
```

We get the following message:
```
==150974== HEAP SUMMARY:
==150974==     in use at exit: 509 bytes in 11 blocks
==150974==   total heap usage: 29 allocs, 18 frees, 76,202 bytes allocated
==150974== 
==150974== LEAK SUMMARY:
==150974==    definitely lost: 320 bytes in 7 blocks
==150974==    indirectly lost: 189 bytes in 4 blocks
==150974==      possibly lost: 0 bytes in 0 blocks
==150974==    still reachable: 0 bytes in 0 blocks
==150974==         suppressed: 0 bytes in 0 blocks
==150974== Rerun with --leak-check=full to see details of leaked memory
==150974== 
==150974== For lists of detected and suppressed errors, rerun with: -s
==150974== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Fairly unhelpful, it is essentially telling us "yeah, you leaked, oops", and
nothing else. Already though, it's hinting at us to ask more if it, with the
following line:
> `Rerun with --leak-check=full to see details of leaked memory`

I will actually give you a few more options that the documentation for Valgrind
(and memcheck specifically) has available to you.

## Detailed Run

The reason why they don't include all these helpful flags by default, is
because it slows down runtime. Lots of people use Valgrind professionally on
*huge* codebases, and running these thorough checks every time makes no sense.
So by default, people mostly just want to run `memcheck` to do a quick sanity
check and make sure they're not leaking. That's why the default flags are the
way they are.

That being said, here are all the options I like to run with when I'm being
thorough:
```bash
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./books
```

Wow, what a pain in the butt to remember, but as an aside:

## Save Bash Commands (Alias)

If you don't want to remember all that, you can make a command shortcut for
bash.

First open `~/.bashrc` in the editor of your choice, and add a command alias,
like so:
```bash
alias COMMAND_SHORTCUT_NAME="valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes -s"
```

I set my `COMMAND_SHORTCUT_NAME` as `vg`, so I can type:
```bash
vg ./books
```

Now you can either refresh your terminal by closing and reopening it, or
sourcing your config file by typing:
```bash
source ~/.bashrc
```

## First Run

Now lets actually Run that command from above.

Now if we look at the output, it is significantly longer. I won't paste it all
here for the sake of clarity and readability, but I will highlight specific
portions.

Let's read the summary from the top down, and look at our first error in detail

## First Error

```
==151300== 32 bytes in 1 blocks are definitely lost in loss record 1 of 11
==151300==    at 0x4846FA3: operator new(unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==151300==    by 0x10CF24: Book::Book(char const*, char const*, char const*) (booklist.cpp:19)
==151300==    by 0x10A46C: main (main.cpp:19)
```

I strongly advise you only tackle one error block at a time, so that you don't
get overwhelmed trying to track down every error in the file. We can read the
call-stack of the error from the bottom up, to see that:
1. In the `main()` function in `main.cpp` on line 19:
2. In the `Book` constructor in `booklist.cpp` on line 19:
3. We called `new`, and never freed that block of memory back again.

Nice! We found the first place to correct the mistake.

If we follow the line to where the error is, we see the following function:
```cpp
Book::Book(const char* t, const char* a, const char* s):
	title(t), author(a)
{
	sequel_ptr = (s ? new string(s) : nullptr);
}
```

The sequel pointer of the book never gets freed after we create it! How do we
fix this?

Well, any time we have private memory in a `class` or `struct`, that same
`class` or `struct` should have a destructor! Google "C++ Rule of Three" if you
want to find out more about this. If we make the book clean up it's memory when
we exit, we shouldn't have to worry about the sequel string leaking anymore
after we leave.

I'm going to add this destructor to `struct Book` in the `booklist.h`:
```cpp
struct Book
{
    // ...
    ~Book();

    //...
};
```

...and I'm going to implement it in `booklist.cpp`, like so:
```cpp
Book::~Book()
{
	delete sequel_ptr;
}
```

Now, let's rerun Valgrind and ensure that we resolved that first error!

Nice, our leaks went from:
```
==151604== LEAK SUMMARY:
==151604==    definitely lost: 320 bytes in 7 blocks
==151604==    indirectly lost: 189 bytes in 4 blocks
==151604==      possibly lost: 0 bytes in 0 blocks
==151604==    still reachable: 0 bytes in 0 blocks
==151604==         suppressed: 0 bytes in 0 blocks
==151604== 
==151604== ERROR SUMMARY: 7 errors from 7 contexts (suppressed: 0 from 0)
```

—to looking like:
```
==152046== LEAK SUMMARY:
==152046==    definitely lost: 160 bytes in 2 blocks
==152046==    indirectly lost: 109 bytes in 2 blocks
==152046==      possibly lost: 0 bytes in 0 blocks
==152046==    still reachable: 0 bytes in 0 blocks
==152046==         suppressed: 0 bytes in 0 blocks
==152046== 
==152046== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```

We cut down half of the leaked memory!

Now let's tackle the next error!

## Second Run, Second Error

I strongly advise the loop of fix **only 1 error**, re-run Valgrind, and repeat.
If you try and use the first run of Valgrind and keep fixing errors, you might
be trying to fix an error that might have already been fixed on the first
error. Errors can cascade, so it might be wasted effort! For example, our leak
summary noted that fixing that one error cut down our errors from 7, to 2!

Moving past that, let's read our next error:
```
==152046== 45 bytes in 1 blocks are indirectly lost in loss record 1 of 4
==152046==    at 0x4846FA3: operator new(unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==152046==    by 0x10C862: std::__new_allocator<char>::allocate(unsigned long, void const*) (new_allocator.h:151)
==152046==    by 0x10C2AA: allocate (allocator.h:198)
==152046==    by 0x10C2AA: allocate (alloc_traits.h:482)
==152046==    by 0x10C2AA: std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_S_allocate(std::allocator<char>&, unsigned long) (basic_string.h:126)
==152046==    by 0x10BCBD: std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_create(unsigned long&, unsigned long) (basic_string.tcc:159)
==152046==    by 0x10CC1C: void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct<char*>(char*, char*, std::forward_iterator_tag) (basic_string.tcc:229)
==152046==    by 0x10CB0A: std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) (basic_string.h:551)
==152046==    by 0x10D051: Book::Book(Book const&) (booklist.cpp:28)
==152046==    by 0x10D176: BookList::Node::Node(Book const&) (booklist.cpp:35)
==152046==    by 0x10D2EC: BookList::add(Book const&) (booklist.cpp:66)
==152046==    by 0x10C998: Reader::add(Book const&) (reader.cpp:10)
==152046==    by 0x10A586: main (main.cpp:26)
```

Reading from the bottom, up:
1. In `main.cpp` on line 26:
2. In the `Reader::add` function in `reader.cpp` on line 10:
3. In the `BookList::add` function in `booklist.cpp` on line 66:
4. In the `BookList::Node` constructor in `booklist.cpp` on line 35
5. In the `Book` constructor in `booklist.cpp` on line 28
6. Blah blah blah... we can skip most of the standard libary calls to `string`
7. All the way to the top, we have a call to `new` from that `Book` constructor
   that we didn't free.

Let's look at the most inner function call and see if we can't spot the
problem. The line we want to be looking at is our step **5.**, the `Book`
constructor, so let's head to line 28:
```cpp
Book::Book(const Book& other):
	title(other.title), author(other.author)
{
	sequel_ptr = (other.sequel_ptr ? new string(*other.sequel_ptr) : nullptr);
}
```

Hmm, looks fine to me, the problem might be upstream, let's go up a step. Let's
look at the `BookList::Node` constructor on line 35, and see if we missed
anything:
```cpp
BookList::Node::Node(const Book& other): data(other), next(nullptr) {}
```

We don't initialize anything here either, let's back up once more to
`BookList::add`, on line 66:
```cpp
void BookList::add(const Book& book)
{
	Node* new_node = new Node(book);
	new_node->next = head;
	head = new_node;
}
```

Gotcha! We make a `new Node` here, and for some reason it doesn't get freed? We
should have freed it already since we have a `BookList` destructor which
handles the freeing of Nodes. Let's go look at that and see if we can't spot
any errors:
```cpp
BookList::~BookList()
{
	if (!head) {
		return;
	}

	head = head->next;
	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}
}
```

Oh yeah, what on earth? What was this coder thinking? For some reason, `head`
gets *skipped* in deleting. We're always going to miss one in that case, how
strange. Let's correct this to include `head`, so the destructor now looks like
this:
```cpp
BookList::~BookList()
{
	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}
}
```

Let's re-run now, and see how our errors and leaks look like:
```
==152826== HEAP SUMMARY:
==152826==     in use at exit: 0 bytes in 0 blocks
==152826==   total heap usage: 29 allocs, 29 frees, 76,202 bytes allocated
==152826== 
==152826== All heap blocks were freed -- no leaks are possible
==152826== 
==152826== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Nice! Just by fixing two errors, we fixed our whole program! And it was far
simpler than we originally thought!
