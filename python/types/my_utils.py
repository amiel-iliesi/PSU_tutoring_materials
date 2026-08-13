from typing import Optional
from math import sqrt
from my_types import Number


def to_number(user_input: str) -> Optional[Number]:
    '''Attempts to cast `user_input` to a numeric type.

    ### Arguments
    * `user_input`: uncast raw input string

    ### Returns
    A numeric type if the cast was successful, or `None` if the cast failed.'''
    try:
        value: Number

        if '.' in user_input or 'e' in user_input:
            value = float(user_input)
        else:
            value = int(user_input)

        return value
    except ValueError:
        return None


def is_prime(x: int) -> bool:
    '''Checks whether or not the inputted integer is prime.

    ### Arguments
    * `x`: value to be checked

    ### Returns
    Boolean value indicating primeness of `x`.'''
    if x <= 1:
        return False

    check_bound = int(sqrt(float(x)) + 0.5)  # +0.5 to round the value

    for n in range(2, check_bound+1):
        if x % n == 0:
            return False

    return True
