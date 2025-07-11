from random import randint
from sys import stderr
from traceback import print_exc


class BST():
    '''A binary search tree'''

    def __init__(self, value=None):
        self.left = self.right = None
        self.data = value

    def insert(self, value) -> bool:
        '''inserts value where it belongs in the BST'''

        if self.data is None:
            self.data = value
            return True

        try:
            if value <= self.data:
                if self.left is None:
                    self.left = BST(value)
                    return True
                else:
                    return self.left.insert(value)
            else:
                if self.right is None:
                    self.right = BST(value)
                    return True
                else:
                    return self.right.insert(value)
        except TypeError:
            print_exc()
            return False

    def min(self) -> int:
        if self.left:
            return self.left.min()
        else:
            return self.data

    def max(self) -> int:
        if self.right:
            return self.right.max()
        else:
            return self.data

    def has(self, value) -> bool:
        if self.data is None:
            return False

        try:
            if self.data == value:
                return True

            elif value < self.data and self.left is not None:
                return self.left.has(value)

            elif value > self.data and self.right is not None:
                return self.right.has(value)

            else:
                return False
        except TypeError:
            print_exc()
            return False

    def size(self) -> int:
        total_size = 1 if self.data is not None else 0

        for direction in (self.left, self.right):
            if direction is not None:
                total_size += direction.size()

        return total_size

    def BST_relational_test(self):
        if self.left:
            assert self.left.max() <= self.data
            self.left.BST_relational_test()

        if self.right:
            assert self.right.min() > self.data
            self.right.BST_relational_test()


if __name__ == '__main__':
    test_tree = BST(1)
    for x in (7.2, 'a', "ABCDEFG", BST()):
        if not test_tree.insert(x):
            print(f"\t{x.__repr__()} could not be inserted into test_tree")

    my_tree = BST()
    list_vals: list[int] = []

    N: int = 25000

    for i in range(N):
        to_insert = randint(0, 100000)
        while (my_tree.has(to_insert)):
            to_insert = randint(0, 100000)

        my_tree.insert(to_insert)
        list_vals.append(to_insert)

    # running tests
    my_tree.BST_relational_test()  # left side <= root and right side > root

    assert my_tree.size() == N

    for value in list_vals:
        assert my_tree.has(value)

    print("validation successful, no errors")
