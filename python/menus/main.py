import good_menu as gm
import bad_menu as bm

USE_BAD = False
MENU = bm.Menu if USE_BAD else gm.Menu

if __name__ == '__main__':
    menu = MENU()

    menu.main()
