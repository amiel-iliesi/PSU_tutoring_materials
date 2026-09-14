from my_list import List
from copy import deepcopy


if __name__ == '__main__':
    values = List(*(x for x in range(1, 10)))

    # test List.__repr__, which also tests __iter__
    print(f'{values=}')

    # test List.__getitem__
    print(f'\n{values[1]=}')

    print(f'\n{values[8:3:-4]=}')

    # test List.__setitem__
    print('\n***setting: values[3] = \'a\'')
    values[3] = 'a'
    print(f'{values=}')

    # test List.__delitem__
    print('\n***deleting: del values[3]')
    del values[3]
    print(f'{values=}')

    # ensure deepcopy works with our container
    print('\n***creating a copy, and modifying the first value of both')
    values_copy = deepcopy(values)
    values[0] = 'foo'
    values_copy[0] = 'bar'
    print(f'{values=}, {values_copy=}')

    # test List.__add__
    print(f'\n{values + values_copy=}')

    # test List.__eq__
    print(f'\n{values == values_copy=}')

    print(f'\n{List(1, 2, 3) == List(1, 2, 3)=}')
    print(f'{List(1, 2, 3, 4) == List(1, 2, 3)=}')
    print(f'{List(1, 2, 3) == List(1, 2, 3, 4)=}')
    print(f'{List() == List()=}')
    print(f'{List(1) == List()=}')
    print(f'{List() == List(1)=}')

    print('\n***appending values to itself')
    values.append(values)
    values.append(values[:-3:-1])
    print(f'{values=}')
