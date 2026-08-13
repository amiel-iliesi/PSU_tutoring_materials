from bst import Tree, Node
from typing import Optional
from random import randint, shuffle


SIZE = 1000


def header(msg: str) -> str:
    return f'{msg}:\n{'-'*(len(msg)+1)}'


def bidirectionality(tree: Tree[int]) -> tuple[bool, list[Node[int]]]:
    '''Tests tree to ensure that all bidirectional relationships are accurate.
    All children should point to their parents correctly, and vice versa.

    **arguments**:
    * `tree`: tree to be tested.

    **returns**
    * A tuple of the status of the test, and a list of failed nodes
    (if any).'''

    def __bidirectionality(curr: Optional[Node[int]])\
            -> tuple[bool, list[Node[int]]]:
        '''Recursive implement of parent function.'''
        status = True
        cases: list[Node[int]] = []

        if curr is None:
            return (True, [])

        if curr.left is not None and curr.left.parent is not curr\
                or curr.right is not None and curr.right.parent is not curr:
            status = False
            cases.append(curr)

        left_status, left_cases = __bidirectionality(curr.left)
        right_status, right_cases = __bidirectionality(curr.right)

        status &= left_status & right_status
        cases = left_cases + cases + right_cases

        return (status, cases)

    return __bidirectionality(tree.root)


def insertion(tree: Tree[int], expected: set[int])\
        -> tuple[bool, tuple[set[int], set[int]]]:
    '''Ensures that all inserted values are in the tree, and no extras.'''
    tree_contents = set(tree.to_list())

    return (tree_contents == expected,
            (expected - tree_contents, tree_contents - expected))


def hierarchy(tree: Tree[int]) -> tuple[bool, list[Node[int]]]:
    '''Ensures that the a < b < c hierarchy is true across all nodes.

    **returns**:
    * A tuple with success status, and a list of nodes that have contradictory
    children.'''

    def __hierarchy(curr: Optional[Node[int]]) -> tuple[bool, list[Node[int]]]:
        '''Recursive implement for the parent function.'''

        if curr is None:
            return (True, [])

        status, cases = __hierarchy(curr.left)

        if curr.left is not None and curr.left.value >= curr.value or\
                curr.right is not None and curr.right.value <= curr.value:
            status = False
            cases.append(curr)

        right_status, right_cases = __hierarchy(curr.right)

        status &= right_status
        cases += right_cases

        return (status, cases)

    return __hierarchy(tree.root)


def duplication(insertions=10000, min=0, max=5000) -> tuple[bool, int]:
    '''Generates a new tree and naively attempts to insert values, in order to
    attempt to create collisions. Uses sets to monitor expected behavior, and
    compares results at the end. Since the `insertion` test didn't test
    duplication insertions, this tests the `Tree.insert` refusal mechaism in
    the `bst.Tree` itself.

    **returns**:
    * A tuple with success, and an integer noting the duplicate additions into
    the tree.'''

    expected: set[int] = set()
    inserted = 0

    duplication_tree = Tree[int]()

    for _ in range(insertions):
        n = randint(min, max)
        expected.add(n)
        if duplication_tree.insert(n):
            inserted += 1

    return (expected == set(duplication_tree.to_list()),
            duplication_tree.size() - len(expected))


def indexing(tree: Tree[int]) -> tuple[bool, list[int]]:
    '''Ensure that `Tree.__getitem__` works properly.

    **returns**:
    * A tuple of success status, and a list of indecies that didn't match the
    ideal list counterpart (OR failed to error when they should have).'''

    tree_list = tree.to_list()

    failure_indices: list[int] = []

    for i, n in enumerate(tree_list):
        if n != tree[i]:
            failure_indices.append(i)

    try:
        tree[tree.size()]
        failure_indices.append(tree.size())  # shouldn'tve gotten this far
    except IndexError:
        pass

    try:
        tree[-(tree.size()+1)]
        # shouldn'tve gotten this far
        failure_indices.append(-(tree.size()+1))
    except IndexError:
        pass

    return (len(failure_indices) == 0, failure_indices)


if __name__ == '__main__':
    tree = Tree[int]()

    print(header(f'running tests for Tree[int]{{size={SIZE}}}'))

    values = list(range(SIZE))
    shuffle(values)

    for n in values:
        tree.insert(n)

    success, cases = bidirectionality(tree)
    print(f'[{'✓' if success else '✗'}] Bidirectionality Test')
    for case in cases:
        print(repr(case))
        if case.left is not None and case.left.parent is not case:
            print(repr(case.left))
        if case.right is not None and case.right.parent is not case:
            print(repr(case.right))

    success, differences = insertion(tree, set(values))
    print(f'[{'✓' if success else '✗'}] Insertion Test')
    if not success:
        print(f'not inserted: {{{', '.join(str(n) for n in differences[0])}}}')
        print('extraneous in tree: ' +
              f'{{{', '.join(str(n) for n in differences[1])}}}')

    success, cases = hierarchy(tree)
    print(f'[{'✓' if success else '✗'}] Hierarchy Test')
    for case in cases:
        print(repr(case))

    success, excess = duplication()
    print(f'[{'✓' if success else '✗'}] Duplication Test')
    if not success:
        print(f'{excess} excess insertions')

    # NOTE: indexing on a tree is slow because it's O(n), and looping indexing
    # like this is O(n^2)
    tree_list = tree.to_list()
    success, failure_indices = indexing(tree)
    print(f'[{'✓' if success else '✗'}] Indexing Test')
    if not success:
        print(f'[{', '.join([f'{tree_list[i]}!={tree[i]}'
              for i in failure_indices])}]')
