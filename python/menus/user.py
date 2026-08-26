from dataclasses import dataclass


@dataclass
class User:
    '''A basic user structure.'''
    name: str
    id: int
