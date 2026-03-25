from BST import BST
from person import Person, PersonComp
from typing import Any

if __name__ == "__main__":
    tree: BST[Any]

    section_header = "tree of ints"
    print(f"--{section_header}{'-'*(68-len(section_header))}")

    print("Constructing tree of integers...")
    tree = BST[int]()  # default comparison is fine

    print("\nDisplaying the tree...")
    tree.display()

    nums = (5, 3, 2)
    print(f"\nInserting {nums} into the tree...")
    for n in nums:
        tree.insert(n)

    print("\nDisplaying the tree...")
    tree.display()

    print('\n', end='')

    section_header = "tree of Person dataclass"
    print(f"--{section_header}{'-'*(68-len(section_header))}")

    tree = BST[Person](PersonComp)

    print("\nDisplaying the tree...")
    tree.display()

    tree.insert(Person(id=0, name="Jeff", age=35))
    tree.insert(Person(id=2, name="James", age=35))
    tree.insert(Person(id=1, name="John", age=35))

    print("\nDisplaying the tree...")
    tree.display()
