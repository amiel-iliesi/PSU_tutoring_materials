from bst import Tree
from random import randint

LENGTH = 16
MIN = 0
MAX = 99

if __name__ == '__main__':
    tree = Tree[int]()

    inserted = 0
    while inserted < LENGTH:
        if tree.insert(randint(MIN, MAX)):
            inserted += 1

    print(f'size of tree: {tree.size()}')

    tree.display()

    print('removing 3 items from the tree...')
    removed: list[tuple[int, int]] = []
    for i in range(3):
        i = randint(0, tree.size()-1)
        removed.append((i, tree[i]))
        tree.remove(tree[i])

    print(f'removed: [{', '.join(f'{x}@{i}' for i, x in removed)}]')
    print(f'size of tree: {tree.size()}')

    tree.display()
