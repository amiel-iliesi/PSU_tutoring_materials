from typing import Optional, Any


def plural(n: int) -> str:
    '''Returns plural suffix based on input value'''
    return 's' if n != 1 else ''


class Vehicle:
    '''abstract vehicle class'''

    # static class variable (see how derived classes modify this)
    __medium__ = 'unknown'

    @classmethod
    def medium(cls) -> str:
        return cls.__medium__

    def __init__(self,
                 fuel_type: str,
                 mpg: Optional[float],
                 seating: int,
                 cargo_space_ft3: float) -> None:
        # NOTE: MPG is optional since some fuel types cannot be easily
        # quanitified EG: manpower, windpower
        self.fuel_type = fuel_type
        self.mpg = mpg
        self.seating = seating
        self.cargo_space_ft3 = cargo_space_ft3

    def items(self) -> dict[str, Any]:
        return {'fuel_type': self.fuel_type,
                'mpg': self.mpg,
                'seating': self.seating,
                'cargo_space_ft3': self.cargo_space_ft3}

    def __str__(self) -> str:
        return f'{self.fuel_type}' +\
            (f'@{self.mpg:.3g}mpg' if self.mpg is not None else '') + ', ' +\
            f'{self.seating} seat{plural(self.seating)}, ' +\
            f'{self.cargo_space_ft3:.4g} ft³ of cargo space, ' +\
            f'{self.__medium__} vehicle'


class Car(Vehicle):
    '''Land-medium specialization of vehicle, with doors and wheels'''

    __medium__ = 'land'

    def __init__(self,
                 fuel_type: str,
                 mpg: Optional[float],
                 seating: int,
                 cargo_space_ft3: float,
                 doors: int,
                 wheels: int) -> None:
        # super().__init__ is Python's version of C++'s parent initialization,
        # IE: B::B(): A() {...}
        super().__init__(fuel_type, mpg, seating, cargo_space_ft3)

        # Cars always have doors and wheels whereas other vehicles might not
        # necessarily have them, EG boats
        self.doors = doors
        self.wheels = wheels

        # NOTE: if vehicles in general *often* have a parameter like doors—but
        # not always—you could also make them an *optional* parameter for the
        # user to include; this makes a parameter a *loose* contract with the
        # user, IE: **opt-in**.

    def items(self) -> dict[str, Any]:
        return {'doors': self.doors,
                'wheels': self.wheels} |\
            super().items()

    def __str__(self) -> str:
        return f'{self.doors} door{plural(self.doors)}, ' +\
            f'{self.wheels} wheel{plural(self.wheels)}, ' +\
            super().__str__()


class Coupe(Car):
    '''Specialization of car, with two doors and four wheels by definition'''

    # __medium__ not modified, since it's still a land vehicle, like a regular
    # car

    def __init__(self,
                 fuel_type: str,
                 mpg: Optional[float],
                 seating: int,
                 cargo_space_ft3: float) -> None:
        # A Coupe is a specialization of a Car, so we can reduce parameters
        doors = 2
        wheels = 4

        super().__init__(fuel_type,
                         mpg,
                         seating,
                         cargo_space_ft3,
                         doors,
                         wheels)


class Boat(Vehicle):
    '''Sea specialization of vehicle with propellers and decks.'''

    __medium__ = 'sea'

    def items(self) -> dict[str, Any]:
        return {'propellers': self.propellers,
                'num_decks': self.num_decks} |\
            super().items()

    def __init__(self,
                 fuel_type: str,
                 mpg: Optional[float],
                 seating: int,
                 cargo_space_ft3: float,
                 propellers: int,
                 num_decks: int) -> None:

        super().__init__(fuel_type, mpg, seating, cargo_space_ft3)

        self.propellers = propellers
        self.num_decks = num_decks

    def __str__(self) -> str:
        return f'{self.propellers} propeller{plural(self.propellers)}, ' +\
            f'{self.num_decks} deck{plural(self.num_decks)}, ' +\
            super().__str__()
