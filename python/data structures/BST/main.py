from typing import Optional
from random import randint


class Tree:
    def __init__(self, data: Optional[int] = None) -> None:
        self.data: Optional[int] = data
        self.left: Optional[Tree] = None
        self.right: Optional[Tree] = None

    def _insert_recursive(self, data: int) -> None:
        if self.data is None:
            self.data = data
        elif data <= self.data:
            if self.left is None:
                self.left = Tree(data)
            else:
                self.left._insert_recursive(data)
        else:
            if self.right is None:
                self.right = Tree(data)
            else:
                self.right._insert_recursive(data)

    def insert(self, data: int) -> None:
        self._insert_recursive(data)

    def collect_in_order(self) -> list[int]:
        left_data: list[int]
        center_data: list[int]
        right_data: list[int]

        if self.left is None:
            left_data = []
        else:
            left_data = self.left.collect_in_order()

        if self.data is None:
            center_data = []
        else:
            center_data = [self.data]

        if self.right is None:
            right_data = []
        else:
            right_data = self.right.collect_in_order()

        return left_data + center_data + right_data

    def __str__(self) -> str:
        return ', '.join([str(data) for data in self.collect_in_order()])

    def __repr__(self) -> str:
        left: str = f'{repr(self.left)} ' if self.left is not None else ''
        right: str = f' {repr(self.right)}' if self.right is not None else ''
        return f'{{{left}{self.data}{right}}}'


if __name__ == '__main__':
    ints = Tree()

    for _ in range(5):
        ints.insert(randint(0, 10))

    print(repr(ints))
