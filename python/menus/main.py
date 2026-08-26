import good_menu as gm
import bad_menu as bm

USE_BAD = False

if __name__ == '__main__':
    menu = bm.Menu() if USE_BAD else gm.Menu()

    menu.main()
