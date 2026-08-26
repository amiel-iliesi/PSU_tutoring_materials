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
                 right: Optional[Node[T]] = None) -> None:
        super().__init__()

        self.value = value
        self.left = left
        self.right = right

    def __repr__(self) -> str:
        return str(self.__class__) + '@' + str(hex(id(self))) +\
            f'(value={str(self.value)}, left={str(self.left)}, ' +\
            f'right={str(self.right)})'

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

        def _insert(value: T, curr: Optional[Node]) -> tuple[bool, Node[T]]:
            '''Recursive helper for insert.

            ### arguments
            * `value`: new value to insert into the tree
            * `curr`: node to recurse insertion from

            ### returns
            `(status, node)`
            * `status`: whether or not insertion was successful (no duplicate
            found)
            * `node`: returns the node at the given call'''

            if curr is None:
                return (True, Node(value))
            elif value < curr.value:
                status, curr.left = _insert(value, curr.left)
                return (status, curr)
            elif value > curr.value:
                status, curr.right = _insert(value, curr.right)
                return (status, curr)
            else:
                return (False, curr)

        status, self.root = _insert(value, self.root)
        return status

    def remove(self, value: T) -> bool:
        '''Removes the deepest match of the value from the tree.

        **arguments**:
        * `value`: key for item to be removed.

        **returns**:
        * Success status of removal; can fail if `value` is not present in
        tree.'''

        def _pop_ios(curr: Node[T]) -> Optional[T]:
            '''Pops the in-order successor of the given node from the tree.

            ### arguments
            `curr`: node to start from.

            ### returns
            * `None`: if there is no in-order successor.
            * `T` otherwise.'''

            ios: Optional[Node[T]] = curr.right

            if ios is None:
                return None

            prev = curr
            while ios.left is not None:
                prev = ios
                ios = ios.left

            if ios is prev.left:
                prev.left = ios.right
            else:
                prev.right = ios.right

            return ios.value

        def _remove(value: T, curr: Optional[Node[T]]) \
                -> tuple[bool, Optional[Node[T]]]:
            '''Recursive helper for remove.

            ### arguments
            * `value`: value to match against for removal.
            * `curr`: node to recurse from.

            ### returns
            `(status, node)`
            * `status`: status of removal
            * `node`: (new) node at site of recursion.
            '''

            if curr is None:
                return (False, None)
            elif value < curr.value:
                status, curr.left = _remove(value, curr.left)
                return (status, curr)
            elif value > curr.value:
                status, curr.right = _remove(value, curr.right)
                return (status, curr)
            else:  # ==, remove value
                if curr.left is None and curr.right is None:
                    return (True, None)
                elif curr.left is not None and curr.right is not None:
                    popped = _pop_ios(curr)
                    if popped is not None:
                        curr.value = popped
                    return (True, curr)
                elif curr.left is not None:
                    return (True, curr.left)
                else:
                    return (True, curr.right)

        status, self.root = _remove(value, self.root)
        return status

    def _size(self, curr: Optional[Node[T]]) -> int:
        if curr is None:
            return 0

        return 1 + self._size(curr.left) + self._size(curr.right)

    def size(self) -> int:
        '''**returns**:
        * The size of the tree.'''

        if self.root is None:
            return 0
        else:
            return self._size(self.root)

    def contains(self, value: T) -> bool:
        '''**returns**:
        * Whether or not the value is found in the tree.'''

        def _contains(value: T, curr: Optional[Node[T]]) -> bool:
            if curr is None:
                return False
            elif value < curr.value:
                return _contains(value, curr.left)
            elif value > curr.value:
                return _contains(value, curr.right)
            else:
                return True

        return _contains(value, self.root)

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
