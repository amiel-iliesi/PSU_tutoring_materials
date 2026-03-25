from Vehicles import Vehicle, Car, Coupe, Boat

HEADER_WIDTH = 60
FOOTER = '-'*HEADER_WIDTH


def header(title: str,
           width: int = HEADER_WIDTH,
           align: str = 'center') -> str:
    '''returns a nice header for different sections

    `align`: `'left'`, `'right'`, `'center'`'''
    if len(title) > width:
        raise ValueError(f'title width overflow ({len(title)} > {width})')
    elif len(title) == width:
        return title

    if align == 'center':
        padding = width - len(title)
        left_padding = padding // 2
        right_padding = left_padding + (1 if padding % 2 == 1 else 0)

        return f'{'-'*left_padding}{title}{'-'*right_padding}'
    elif align == 'left':
        return f'-{title}{'-'*((width-1)-len(title))}'
    elif align == 'right':
        return f'{'-'*((width-1)-len(title))}{title}-'
    else:
        raise ValueError(f'align({align}) needs to be {{left, right, center}}')


if __name__ == '__main__':
    print(header('Vehicles'))

    ufo = Vehicle('Dark Matter', 5.63e85, 125000, float('inf'))
    print(f'* UFO({ufo.__class__.__name__}): {str(ufo)}')

    print()
    print(header('Cars'))

    aus_ute = Car('Diesel', 25.0, 2, 500, 2, 4)
    print(f'* Australian Ute({aus_ute.__class__.__name__}): {str(aus_ute)}')

    semi_truck = Car('Biodiesel', 7, 2, 4000, 2, 18)
    print(f'* Semi-Truck({semi_truck.__class__.__name__}): {str(semi_truck)}')

    print()
    print(header('Coupes'))

    supra_mk5 = Coupe('Premium Gasoline(93 octane)', 23.5, 2, 10.2)
    print(f'* Supra MK5({supra_mk5.__class__.__name__}): {str(supra_mk5)}')

    print()
    print(header('Boats'))

    row_boat = Boat('Manpower', None, 6, 20, 0, 0)
    print(f'* Row Boat({row_boat.__class__.__name__}): {str(row_boat)}')

    nuclear_aircraft_carrier = Boat('Uranium', 3.5e8, 5500, 1.13e7, 4, 25)
    print('* Aircraft Carrier(',
          nuclear_aircraft_carrier.__class__.__name__,
          '): ', nuclear_aircraft_carrier, sep='')

    print(FOOTER)
