'''A module of generalized utility functions.'''


def header(s: str) -> str:
    '''Returns an underscored version of the input string.'''
    return f'{s}\n{'-'*len(s)}'
