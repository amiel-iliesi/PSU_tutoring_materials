from __future__ import annotations
from typing import TypeVar, Generic, Callable, Any, Optional

T = TypeVar('T')


class BST(Generic[T]):
    '''A generic Binary Search Tree'''

    class Node:
        '''Internal node for use by BST'''

        def __init__(self, data: T) -> None:
            self.data = data
            self.left: Optional[BST.Node] = None
            self.right: Optional[BST.Node] = None

    @staticmethod
    def less(a: T, b: T) -> bool:
        '''default comparison to use for insertion'''
        # ignore the type error below; user might override the comparison used
        # for the class at initialization

        return a < b  # type: ignore

    def __init__(self, comp: Callable[[Any, Any], bool] = less):
        '''Initialized the tree with a specified comparison method.
        ## Arguments
        * `comp`: Function that defines comparison criteria for various
        functions. By default it uses `f(a, b)->bool: a < b`.'''
        super().__init__()

        self.comp = comp
        self.root: Optional[BST.Node] = None

    def _equal(self, a: T, b: T,
               comp: Optional[Callable[[Any, Any], bool]] = None) -> bool:
        '''Define equality in terms of the given less than comparison. Less
        efficient, but we require less specificaiton from the user this way.'''
        if comp is None:
            comp = self.comp

        return not comp(a, b) and not comp(b, a)

    def insert(self, data: T,
               comp: Optional[Callable[[Any, Any], bool]] = None) -> bool:
        '''Inserts `data` into the tree. Duplicate entries are rejected.

        ## Arguments
        * `data`: Datum to be inserted into the tree.
        * `comp`: Optional override for the comparison function for the call.

        ## Returns
        Insertion status. Fails if `data` is already in the tree.'''
        if self.root is None:
            self.root = BST.Node(data)
            return True

        curr = self.root

        if comp is None:
            comp = self.comp

        while True:
            if comp(data, curr.data):
                if curr.left is not None:
                    curr = curr.left
                else:
                    curr.left = BST.Node(data)
                    break
            elif comp(curr.data, data):
                if curr.right is not None:
                    curr = curr.right
                else:
                    curr.right = BST.Node(data)
                    break
            # not (a < b) and not (b < a); therefore a == b (cannot insert)
            else:
                return False

        return True

    def remove(self, key: Any,
               comp: Optional[Callable[[Any, Any], bool]] = None) -> bool:
        '''Removes the given key value.

        ## Arguments
        * `key`: Value to look for (and remove) within the tree.

        * `comp`: Optional override for the comparison function for the call.

        ## Returns
        Whether or not it was able to remove a value, IE whether or not the
        key was contained in the tree.'''

        if self.root is None:
            return False

        if comp is None:
            comp = self.comp

        if self._equal(self.root.data, key, comp):
            # TODO

    def display(self) -> None:
        '''Prints the contents of the tree, comma delineated, and in-order.'''
        if self.root is None:
            print(f'{self.__repr__()} is empty')
        else:
            last: BST.Node = self.root

            while last.right:
                last = last.right

            self._display(self.root, last)
            print('\n', end='')

    def _display(self, curr: Node, last: Node) -> None:
        '''Private recursive helper for display.'''
        if curr.left is not None:
            self._display(curr.left, last)

        if curr is not last:
            print(f'{curr.data}, ', end='')
        else:
            print(f'{curr.data}', end='')

        if curr.right is not None:
            self._display(curr.right, last)
