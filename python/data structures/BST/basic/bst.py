from __future__ import annotations
from typing import TypeVar, Generic, Optional, Protocol, Any


class Comparable(Protocol):
    def __lt__(self, value: Any, /) -> bool: ...
    def __eq__(self, value: object, /) -> bool: ...


T = TypeVar('T', bound=Comparable)


class Node(Generic[T]):
    def __init__(self,
                 value: T,
                 left: Optional[Node[T]] = None,
                 right: Optional[Node[T]] = None,
                 parent: Optional[Node[T]] = None,
                 ) -> None:
        super().__init__()

        self.value = value
        self.left = left
        self.right = right
        self.parent = parent

    def __repr__(self) -> str:
        return str(self.__class__) + '@' + str(hex(id(self))) +\
            f'(value={str(self.value)}, left={str(self.left)}, ' +\
            f'right={str(self.right)}, parent={str(self.parent)})'

    def __str__(self) -> str:
        return str(self.__class__) +\
            '@' + str(hex(id(self))) +\
            ':' + str(self.value)


class Tree(Generic[T]):
    '''Tree storage of generic types. Does not support duplicate key
    entries.'''

    def __init__(self) -> None:
        super().__init__()

        self.root: Optional[Node[T]] = None

    def __find(self, value: T, curr: Optional[Node[T]] = None) -> Node[T]:
        '''Finds the node location of the given `value`. If multiple values are
        present, return the deepest matching node in the tree--to aid with
        insertion.

        **arguments**:
        * `value`: key to search for.
        * `curr`: node to recurse search from. If no node is give, search is
        run from root.

        **returns**:
        * deepest matched node **OR** parent node to *vacant* matched
        location.'''

        if curr is None:
            if self.root is None:
                raise LookupError('cannot return Node from an empty tree')
            else:
                curr = self.root

        if value < curr.value:
            if curr.left is None:
                return curr
            else:
                return self.__find(value, curr.left)
        elif value > curr.value:
            if curr.right is None:
                return curr
            else:
                return self.__find(value, curr.right)
        else:
            return curr

    def __get_IOS(self, curr: Node[T]) -> Node[T]:
        '''Returns the in-order successor to the current node.

        **arguments**:
        * `curr`: node to find the in-order successor of.

        **returns**:
        * The in-order successor node.'''

        if curr.right is None:
            raise ValueError(f'no successor exists for {curr}')

        ios = curr.right

        while ios.left is not None:
            ios = ios.left

        return ios

    def __normalize_index(self, index: int) -> int:
        if index < 0:
            original_index = index
            size = self.size()
            index = size + index  # '+' because index is negative
            if index < 0:
                raise IndexError(f'reverse index {original_index} maps ' +
                                 f'to index of {index}, which is outside '
                                 f'of range for a tree of size {size}.')

        return index

    def __get_at_index(self, index: int, curr: Node[T])\
            -> tuple[Optional[Node[T]], int]:
        node = None

        if curr.left is not None:
            node, index = self.__get_at_index(index, curr.left)
            if node is not None:
                return (node, index)

        if index == 0:
            return (curr, index)
        index -= 1

        if curr.right is not None:
            return self.__get_at_index(index, curr.right)

        return (None, index)

    def __setitem__(self, index: int, value: T) -> None:
        if self.root is None:
            raise IndexError('An empty tree is not indexable')

        index = self.__normalize_index(index)

        node = None
        try:
            node, _ = self.__get_at_index(index, self.root)
        except IndexError:
            pass  # handled below

        if node is None:  # handled here so wrapper can give info
            size = self.size()
            raise IndexError(
                f'Tree[{index}] does not exist for tree of size {size}'
            )

        node.value = value

    def __getitem__(self, index: int) -> T:
        '''Return the i\\_th item in the tree. Supports negative indexing.'''
        if self.root is None:
            raise IndexError('An empty tree is not indexable')

        index = self.__normalize_index(index)

        value = None
        try:
            node, _ = self.__get_at_index(index, self.root)
            value = node.value if node is not None else None
        except IndexError:
            pass  # handled below

        if value is None:  # handled here so wrapper can give info
            size = self.size()
            raise IndexError(
                f'Tree[{index}] does not exist for tree of size {size}'
            )

        return value

    def insert(self, value: T) -> bool:
        '''Inserts a new value into the tree.

        **arguments**:
        * `value`: new datum to be inserted into the tree.

        **returns**:
        * Success status of insertion. Can fail if `value` is already present
        in tree.'''

        if self.root is None:
            self.root = Node(value)
            return True

        found_node = self.__find(value)

        if value > found_node.value:
            found_node.right = Node(value, parent=found_node)
        elif value < found_node.value:
            found_node.left = Node(value, parent=found_node)
        else:
            return False

        return True

    def remove(self, value: T) -> bool:
        '''Removes the deepest match of the value from the tree.

        **arguments**:
        * `value`: key for item to be removed.

        **returns**:
        * Success status of removal; can fail if `value` is not present in
        tree.'''

        if self.root is None:
            return False  # empty tree will never have a value

        found_node = self.__find(value)

        if found_node.value != value:
            return False

        found_parent = found_node.parent

        is_left = found_node is found_parent.left \
            if found_parent is not None else None

        # has no children
        if found_node.left is None and found_node.right is None:
            if found_parent is not None:
                if is_left:
                    found_parent.left = None
                else:
                    found_parent.right = None
            else:
                self.root = None
        # has one child
        elif (found_node.left is None) != (found_node.right is None):
            new_parents_child = found_node.left
            if found_node.right is not None:
                new_parents_child = found_node.right

            if found_parent is not None:
                if is_left:
                    found_parent.left = new_parents_child
                else:
                    found_parent.right = new_parents_child
            else:
                self.root = new_parents_child
        # both children
        else:
            ios = self.__get_IOS(found_node)
            ios_is_left = ios is ios.parent.left\
                if ios.parent is not None else None

            # swap values
            ios.value, found_node.value = found_node.value, ios.value

            # remove IOS
            if ios.parent is not None:
                if ios_is_left:
                    ios.parent.left = ios.right
                else:
                    ios.parent.right = ios.right
            else:
                raise ValueError(
                    'an in-order successor should always have a parent'
                )

        return True

    def __size(self, curr: Optional[Node[T]]) -> int:
        if curr is None:
            return 0

        return 1 + self.__size(curr.left) + self.__size(curr.right)

    def size(self) -> int:
        '''**returns**:
        * The size of the tree.'''

        if self.root is None:
            return 0
        else:
            return self.__size(self.root)

    def contains(self, value: T) -> bool:
        '''**returns**:
        * Whether or not the value is found in the tree.'''
        if self.root is None:
            return False

        found_node = self.__find(value)

        return found_node.value == value

    def display(self) -> None:
        '''Displays the tree, in descending order, from top to bottom. The
        structure of the tree is prefixed to the left.'''
        def _display(curr: Optional[Node[T]],
                     prefix: str,
                     is_right_child: bool) -> None:
            if curr is None:
                return

            _display(curr.right,
                     prefix + ('   ' if is_right_child else '│  '),
                     True)

            print(prefix +
                  ('┌  ' if is_right_child else '└  ') +
                  str(curr.value))

            _display(curr.left,
                     prefix + ('|  ' if is_right_child else '   '),
                     False)

        if self.root is None:
            print(f'{self} is empty')
            return

        _display(self.root.right, '', True)

        print(self.root.value)

        _display(self.root.left, '', False)

    def to_list(self) -> list[T]:
        '''Serializes the tree into a list.'''
        running_list: list[T] = []

        def _to_list(curr: Optional[Node[T]], running_list: list[T]) -> None:
            if curr is None:
                return

            _to_list(curr.left, running_list)

            running_list.append(curr.value)

            _to_list(curr.right, running_list)

        _to_list(self.root, running_list)

        return running_list
