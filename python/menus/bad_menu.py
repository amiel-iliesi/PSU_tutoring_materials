'''A naive and poorly scalable menu system using conditional execution.'''

from user import User
from typing import Optional
from sys import stderr
from utils import header

PROMPT_STR = '>>> '
ERROR_STR = '*** '


class Menu:
    def __init__(self) -> None:
        self.data: list[User] = []

    def main(self) -> None:
        print('Welcome to the User Inventory System.')

        user_choice: Optional[str] = None
        valid_choices: list[str]

        while user_choice != '4':
            print(f'\n{header('main menu:')}')

            print('1. add new user\n'
                  '2. remove user\n'
                  '3. display users\n'
                  '4. quit')

            valid_choices = ['1', '2', '3', '4']

            while True:
                user_choice = input(PROMPT_STR)

                if user_choice not in valid_choices:
                    print(f'{ERROR_STR}invalid choice', file=stderr)
                else:
                    break

            if user_choice == '1':
                print(f'\n{header('add user:')}')

                name = input(f'{PROMPT_STR}name=')

                while True:
                    try:
                        id = int(input(f'{PROMPT_STR}id='))
                        break
                    except ValueError:
                        print(f'{ERROR_STR}input an integer', file=stderr)

                self.data.append(User(name, id))
            # NOTE: we start losing track of state semantics
            elif user_choice == '2':
                print(f'\n{header('remove user:')}')

                # NOTE: nested menus might require backtracking for expected
                # behavior
                prev_choice = user_choice

                print('1. remove by name\n'
                      '2. remove by id\n'
                      '3. remove by both')

                while True:
                    user_choice = input(f'{PROMPT_STR}')

                    valid_choices = ['1', '2', '3']

                    if user_choice not in valid_choices:
                        print(f'{ERROR_STR}invalid choice', file=stderr)
                    else:
                        break

                found_index: Optional[int] = None

                # NOTE: nested menus get increasingly nested
                if user_choice == '1':
                    name = input(f'{PROMPT_STR}user=')

                    for index, user in enumerate(self.data):
                        if user.name == name:
                            found_index = index
                            break
                elif user_choice == '2':
                    while True:
                        try:
                            id = int(input(f'{PROMPT_STR}id='))
                            break
                        except ValueError:
                            print(f'{ERROR_STR}input an integer', file=stderr)

                    for index, user in enumerate(self.data):
                        if user.id == id:
                            found_index = index
                            break
                else:
                    name = input(f'{PROMPT_STR}user=')
                    while True:
                        try:
                            id = int(input(f'{PROMPT_STR}id='))
                            break
                        except ValueError:
                            print(f'{ERROR_STR}input an integer', file=stderr)

                    try:
                        found_index = self.data.index(User(name, id))
                    except ValueError:
                        pass

                if found_index is not None:
                    removed = self.data.pop(found_index)
                    print(f'removed {removed.name}({removed.id})')
                else:
                    print(f'{ERROR_STR}user not found', file=stderr)

                user_choice = prev_choice
            elif user_choice == '3':
                print(header('\nusers:'))

                for user in self.data:
                    print(f'* {user.name}({user.id})')
            else:
                print('\nGoodbye.')
