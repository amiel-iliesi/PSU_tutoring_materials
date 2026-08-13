from typing import Optional
from my_types import Number, Ints
from my_utils import to_number, is_prime


if __name__ == '__main__':
    print('Enter a series of numbers and I will tell you if they are prime.\n')

    nums: Ints = []
    # if MyPy doesn't type check correctly, you can assert to validate
    # lines below
    assert isinstance(nums, list)

    user_input: str = 'y'

    while True:  # exit cond as break; input semantics near loop end
        x: Optional[Number] = None

        while not isinstance(x, int):
            user_input = input('>>> enter a value: ')

            x = to_number(user_input)

            if x is None:
                print(f'\'{user_input}\' is not a number')
            elif isinstance(x, float):
                print(f'{x} is not an integer')

        nums.append(x)  # MyPy knows x is an int by now!

        while True:
            user_input = input('>>> enter another? (y/n): ').lower()

            if user_input not in ('y', 'n'):
                print('*** please choose (y/n)')
            else:
                break

        if user_input != 'y':
            break

    nums = set(nums)
    primes: Ints = {x for x in nums if is_prime(x)}
    nonprimes: Ints = nums.difference(primes)

    primes = sorted(list(primes))
    nonprimes = sorted(list(nonprimes))

    print('\nprimes: ' + ','.join([str(x) for x in primes]))
    print('non-primes: ' + ','.join([str(x) for x in nonprimes]))
