from __future__ import annotations
from typing import Any


class Fraction:
    def __init__(self, numerator: int, denominator: int) -> None:
        if denominator == 0:
            raise ValueError('Denominator cannot be zero')

        self.numerator = numerator
        self.denominator = denominator

        # normalize sign
        if (self.denominator < 0):
            self.numerator *= -1
            self.denominator *= -1

        self.reduce()

    @staticmethod
    def GCD(a: int, b: int) -> int:
        if not a < b:
            a, b = b, a

        while b % a != 0:
            c = b % a
            b = a
            a = c

        return a

    def reduce(self) -> Fraction:
        gcd = Fraction.GCD(self.numerator, self.denominator)

        self.numerator //= gcd
        self.denominator //= gcd

        return self

    @staticmethod
    def mult(a: Fraction, b: Fraction) -> Fraction:
        numerator = a.numerator * b.numerator
        denominator = a.denominator * b.denominator

        return Fraction(numerator, denominator).reduce()

    def __str__(self) -> str:
        return f'{self.numerator}/{self.denominator}'

    def __mul__(self, other: Any) -> Fraction:
        if isinstance(other, Fraction):
            return Fraction.mult(self, other)
        elif isinstance(other, int):
            return Fraction.mult(self, Fraction(other, 1))
        else:
            raise ValueError(f'cannot multiply {type(self)} and {type(other)}')
