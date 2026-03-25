from dataclasses import dataclass


@dataclass
class Person:
    id: int
    name: str
    age: int

    def __str__(self) -> str:
        return f'{{[{self.id}] {self.name}, {self.age} year(s) old}}'

    def __repr__(self) -> str:
        return f'Person(id={self.id}, name=\'{self.name}\', age={self.age})'

    def __eq__(self, value: object) -> bool:
        if isinstance(value, Person):
            return value.id == self.id and\
                value.name == self.name and\
                value.age == self.age
        else:
            raise TypeError(f'{type(self)} does not support equality '
                            f'with {type(value)}')


def PersonComp(a: Person, b: Person):
    '''Returns true if a < b, and checks all fields in order by
    {id, name, age}, in that order.'''
    if a.id < b.id:
        return True
    elif b.id < a.id:
        return False

    if a.name < b.name:
        return True
    elif b.name < a.name:
        return False

    if a.age < b.age:
        return True
    elif b.age < a.age:
        return False

    return False
