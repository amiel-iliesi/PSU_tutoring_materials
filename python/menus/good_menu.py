'''A more robust and modular menu system using function invocation.'''

from user import User
from sys import stderr
from typing import Optional
from utils import header

PROMPT_STR = '>>> '
ERROR_STR = '*** '


def get_int(prompt: str) -> int:
    '''Ensures the user enters an integer value. Loops until success.

    ### arguments
    `prompt`: input prompt message, prefixed with the global prompt string.

    ### returns
    The value the user entered.'''
    while True:
        try:
            value = int(input(f'{PROMPT_STR}{prompt}'))
            return value
        except ValueError:
            print(f'{ERROR_STR}input an integer', file=stderr)


class Menu:
    def __init__(self) -> None:
        self.users: list[User] = []

    # NOTE: clear up intention and readbility by making utility functions for
    # your class
    @staticmethod
    def _validate_choice(*choices: str) -> str:
        '''Ensure that the user enters a string that matches one of the given
        choices. Functions like a dropdown selector element.'''
        while True:
            choice = input(PROMPT_STR)

            if choice not in choices:
                print(f'{ERROR_STR}please select from: {', '.join(choices)}',
                      file=stderr)
            else:
                return choice

    def main(self) -> None:
        '''Runs the main menu in a loop.'''

        print('Welcome to the User Inventory System.')

        while True:
            print(f'\n{header('main menu:')}')

            print('1. add new user\n'
                  '2. remove user\n'
                  '3. display users\n'
                  '4. quit')

            # NOTE: adding constants for the choices is optional, but makes the
            # conditionals below nicer to read
            CHOICE_ADD_USER = '1'
            CHOICE_REMOVE_USER = '2'
            CHOICE_DISPLAY_USER = '3'
            CHOICE_QUIT = '4'
            choice = self._validate_choice(CHOICE_ADD_USER,
                                           CHOICE_REMOVE_USER,
                                           CHOICE_DISPLAY_USER,
                                           CHOICE_QUIT)

            # NOTE: see?
            if choice == CHOICE_ADD_USER:
                self._add_user()
            elif choice == CHOICE_REMOVE_USER:
                self._remove_user()
            elif choice == CHOICE_DISPLAY_USER:
                self._display_users()
            else:  # CHOICE_QUIT
                print('\nGoodbye.')
                break

    # NOTE: using functions allows for better usage documentation.
    def _add_user(self) -> None:
        '''Prompt the user to add a single new user.'''

        print(f'\n{header('add user:')}')

        name = input(f'{PROMPT_STR}user=')
        id = get_int('id=')

        self.users.append(User(name, id))

    def _remove_user(self) -> None:
        '''Prompt the user to remove a single user from our table.'''

        print(f'\n{header('remove user:')}')

        print('1. remove by name\n'
              '2. remove by id\n'
              '3. remove by both')

        CHOICE_BY_NAME = '1'
        CHOICE_BY_ID = '2'
        CHOICE_REQUIRE_ALL = '3'
        choice = self._validate_choice(CHOICE_BY_NAME,
                                       CHOICE_BY_ID,
                                       CHOICE_REQUIRE_ALL)

        found_index: Optional[int] = None  # falsy by default

        if choice == CHOICE_BY_NAME:
            name = input(f'{PROMPT_STR}user=')

            for index, user in enumerate(self.users):
                if user.name == name:
                    found_index = index
                    break
        elif choice == CHOICE_BY_ID:
            id = get_int('id=')

            for index, user in enumerate(self.users):
                if user.id == id:
                    found_index = index
                    break
        else:  # CHOICE_REQUIRE_ALL
            name = input(f'{PROMPT_STR}user=')
            id = get_int('id=')

            try:
                found_index = self.users.index(User(name, id))
            except ValueError:
                pass

        if found_index is not None:
            removed = self.users.pop(found_index)
            print(f'removed {removed.name}({removed.id})')
        else:
            print(f'{ERROR_STR}user not found', file=stderr)

    def _display_users(self) -> None:
        '''Display all users directly to standard output.'''

        print(f'\n{header('users:')}')

        for user in self.users:
            print(f'* {user.name}({user.id})')
