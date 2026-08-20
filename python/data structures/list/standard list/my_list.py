'''A custom re-implementation of the python `list` as a pedagogical
exercise.'''

from __future__ import annotations
from typing import Any, Optional, Union, Iterator
from copy import deepcopy
from reprlib import recursive_repr


class List:
    '''A list class that holds any amount and order of types in a
    non-contiguous container.'''

    class Node:
        '''A doubly-linked node utility for the `List` class.'''

        def __init__(self,
                     value: Any,
                     previous: Optional[List.Node] = None,
                     next: Optional[List.Node] = None) -> None:
            self.value = value
            self.previous = previous
            self.next = next

    def __init__(self, *args) -> None:
        self.head: Optional[List.Node] = None
        self.tail: Optional[List.Node] = None

        self.append(*args)

    # implementing this allows the container to interface with standard Python
    # looping mechanisms like list comprehensions, and for-each loops
    def __iter__(self) -> Iterator[Any]:
        curr = self.head
        while curr is not None:
            yield curr.value
            curr = curr.next

    # implementing this allows you to use the subscript format for item
    # retrieval, IE: `List[x]` or `List[x:y:z]`
    def __getitem__(self, key: Any) -> Union[Any, List]:
        # 1. int indexing
        if isinstance(key, int):
            return self._node_at_index(key).value
        # 2. slice indexing
        elif isinstance(key, slice):
            new_list = List()

            # 2.a. loop variables
            start, stop, stride = key.indices(len(self))
            curr_index: int
            curr_node: Optional[List.Node]
            cycle = stride
            reverse: bool

            # 2.b. establish stride behavior
            if stride < 0:
                reverse = True
                curr_index = len(self) - 1
                curr_node = self.tail
            elif stride > 0:
                reverse = False
                curr_index = 0
                curr_node = self.head
            else:
                raise ValueError(f'{type(self)}'
                                 f'[{key.start}:{key.stop}:{key.step}] '
                                 'cannot have a step of 0')

            # 2.c. find starting point in list
            if reverse:
                while curr_index != start and curr_node is not None:
                    curr_index -= 1
                    curr_node = curr_node.previous
            else:
                while curr_index != start and curr_node is not None:
                    curr_index += 1
                    curr_node = curr_node.next

            # 2.d. build return list
            while curr_index != stop and curr_node is not None:
                if cycle == stride:
                    new_list.append(curr_node.value)
                    cycle = 0

                if reverse:
                    cycle -= 1
                    curr_index -= 1
                    curr_node = curr_node.previous
                else:
                    cycle += 1
                    curr_index += 1
                    curr_node = curr_node.next

            return new_list
        else:
            raise NotImplementedError(f'{type(self)} is only indexable '
                                      'via int or slice')

    # implementing this lets you use subscript assignment, IE: `List[x] = y`
    def __setitem__(self, index: Any, value: Any) -> None:
        if not isinstance(index, int):
            raise TypeError(f'{self.__class__.__name__}[{repr(index)}] = ... '
                            f': cannot index with {type(index)}')

        self._node_at_index(index).value = value

    # implementing this lets you use subcript deletion: IE: del `List[x]`
    def __delitem__(self, index: Any):
        if not isinstance(index, int):
            raise TypeError(f'del {self.__class__.__name__}[{repr(index)}] '
                            f': cannot index with type {type(index)}')

        self._remove_node(self._node_at_index(index))

    # implementing this allows for container concatenation
    def __add__(self, other: Any) -> List:
        if isinstance(other, List):
            # create two Lists and stitch the middles together

            # 1. create lists
            left = deepcopy(self)
            right = deepcopy(other)

            # 2. stitch them together

            # 2.a. nothing on the left side to stitch
            if left.tail is None:
                return right
            # 2.b. connect the ends together in the middle
            else:
                left.tail.next = right.head
                if right.head is not None:
                    right.head.previous = left.tail
                # 2.c. move tail to furthest end (if there's more)
                if right.tail is not None:
                    left.tail = right.tail
            return left
        else:
            raise TypeError(f'cannot concatenate {type(self)} and '
                            f'{type(other)}')

    def __len__(self) -> int:
        total_len = 0
        curr = self.head

        while curr is not None:
            total_len += 1
            curr = curr.next

        return total_len

    def __eq__(self, other: Any) -> bool:
        if other is self:
            return True

        if isinstance(other, List):
            it_self = iter(self)
            it_other = iter(other)

            while True:
                self_read = False
                try:
                    value_self = next(it_self)
                    self_read = True
                    value_other = next(it_other)

                    # short-circuit
                    if value_self != value_other:
                        return False
                except StopIteration:
                    if self_read:
                        return False  # self is longer
                    else:
                        try:
                            next(it_other)
                            return False  # other is longer
                        except StopIteration:
                            return True

        else:
            raise TypeError(f'cannot compare {self.__class__.__name__} '
                            f'and {type(other).__name__}')

    def __str__(self) -> str:
        return repr(self)

    @recursive_repr()
    def __repr__(self) -> str:
        return f'List({', '.join(repr(x) for x in self)})'

    def _remove_node(self, to_remove: List.Node) -> None:
        '''Removes the given node from the list.'''

        # 1. move class variables
        if to_remove is self.head and self.head is not None:
            self.head = self.head.next

        if to_remove is self.tail and self.tail is not None:
            self.tail = self.tail.previous

        # 2. remove surrounding references
        if to_remove.next:
            to_remove.next.previous = to_remove.previous

        if to_remove.previous:
            to_remove.previous.next = to_remove.next

        # NOTE: now the Node is floating and will be removed when no more
        # temporary references exist

    def _node_at_index(self, key: int) -> List.Node:
        '''retrieves the node at the given index

        ### arguments
        * `key`: index value in range of `[-len, len-1]` where negative indices
        begin from the end of the list

        ### returns
        The node at the given index

        ### raises
        * `IndexError`: if the supplied key lies outside of the valid range of
        `[-len, len-1]`, then no such index-value match exists
        '''
        if key < 0:
            curr_index = -1
            curr_node = self.tail

            while curr_index != key and curr_node is not None:
                curr_index -= 1
                curr_node = curr_node.previous
        else:
            curr_index = 0
            curr_node = self.head

            while curr_index != key and curr_node is not None:
                curr_index += 1
                curr_node = curr_node.next

        if curr_node is not None:
            return curr_node
        else:
            raise IndexError(f'{type(self)}[{key}] is out of range')

    def _push_back(self, value: Any) -> None:
        new_node = List.Node(value)

        if self.head is None:
            self.head = self.tail = new_node
        else:
            assert self.tail is not None  # if head exists, so should tail

            new_node.previous = self.tail
            self.tail.next = new_node
            self.tail = new_node

    def append(self, *args) -> None:
        '''Appends value(s) to the end of the list.'''

        for value in args:
            self._push_back(value)
