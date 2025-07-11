def is_prime(num: int) -> bool:
    """
    Evaluates if a given number is a prime number.

    Args:
        num: `integer` value to be evaluated.

    Returns:
        A `boolean` indicating if `num` is a prime or not.
    """
    if num < 2:
        return False

    for i in range(2, num):
        if num % i == 0:
            return False

    return True


def get_primes(max_prime: int) -> list[int]:
    """
    Generates a list of primes.

    Args:
        `max_prime`: Non-inclusive `integer` max of the list range.

    Returns:
        A list of prime numbers, up to `max_prime`."""
    primes: list[int] = []  # empty list to start

    for i in range(max_prime):
        if is_prime(i):
            primes.append(i)
        else:
            primes.append(0)

    return primes


# NOTE: I use a bit of shorthand here to show you that Python is really good
#       for writing short/readable code quickly!
#
#       It's not important you know what every line is doing, specifically.
if __name__ == "__main__":
    max_prime = int(input("generate primes up to: "))

    primes = get_primes(max_prime)
    primes = ' '.join([str(n) for n in primes if n != 0])  # convert to str
    print(primes)
