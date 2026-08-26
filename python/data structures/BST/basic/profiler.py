from time import perf_counter
from bst import Tree
from random import shuffle
from functools import wraps

SIZE = 5000


def timed(func):
    @wraps(func)
    def _inner(*args, **kwargs) -> None:
        start = perf_counter()
        func(*args, **kwargs)
        end = perf_counter()

        print(f'{func.__name__} elapsed {end-start:.2e} seconds')

    return _inner


@timed
def insert(tree: Tree[int], values: list[int]) -> None:
    for n in values:
        tree.insert(n)


@timed
def to_list(tree: Tree[int]) -> list[int]:
    return tree.to_list()


@timed
def index_all(tree: Tree[int], size: int) -> None:
    for n in range(size):
        tree[n]


if __name__ == '__main__':
    tree = Tree[int]()

    values = [n for n in range(0, SIZE)]
    shuffle(values)

    insert(tree, values)

    to_list(tree)

    # shows that indexed/linear access in a BST is slow
    index_all(tree, tree.size())
