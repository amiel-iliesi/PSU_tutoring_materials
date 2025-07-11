#include "list.h"
#include <iostream>

using namespace std;

bool add(PlaceList&);
bool add(ShopList&);
bool add_shop_to_place(PlaceList&);
bool display_shops_for_place(const PlaceList&);

int main()
{
    PlaceList places;

    char choice;
    do {
        cout << "1. add place\n"
             << "2. display places\n"
             << "3. add shop\n"
             << "4. display shops for a place\n"
             << "q. quit\n>>> ";

        cin.get(choice);
        cin.ignore(256, '\n');

        cout << '\n';

        switch (choice) {
            case '1':
                if (not add(places)) {
                    cerr << "~~ ERR: failed to add place.\n";
                }
                break;
            case '2':
                places.display();
                break;
            case '3':
                if (not add_shop_to_place(places)) {
                    cerr << "~~ ERR: failed to add shop to place.\n";
                }
                break;
            case '4':
                if (not display_shops_for_place(places)) {
                    cerr << "~~ ERR: place does not exist.\n";
                }
                break;
            case 'q':
                cout << "Goodbye!";
                break;
            default:
                cerr << "~~ ERR: '" << choice << "' is an invalid choice.\n";
        }

        cout << '\n';
    } while (choice != 'q');

    return 0;
}

bool add(PlaceList& list)
{
    Place new_place;

    cout << ">>> place name: ";
    getline(cin, new_place.name);

    if (list.contains(new_place.name)) {
        return false;
    }

    cout << ">>> place population: ";
    cin >> new_place.population;
    cin.ignore(256, '\n');

    return list.add(new_place);
}

bool add(ShopList& list) {
    Shop new_shop;
    cout << ">>> shop name: ";
    getline(cin, new_shop.name);

    if (list.contains(new_shop.name)) {
        return false;
    }

    cout << ">>> shop type: ";
    getline(cin, new_shop.type);

    cout << ">>> shop rating [0-5]: ";
    cin >> new_shop.rating;
    cin.ignore(256, '\n');

    if (new_shop.rating < 0 || new_shop.rating > 5) {
        return false;
    }

    return list.add(new_shop);
}

bool add_shop_to_place(PlaceList& list)
{
    string place_name;
    cout << ">>> place name: ";
    getline(cin, place_name);

    if (not list.contains(place_name)) {
        return false;
    }

    ShopList& shops = list.get_shops(place_name);
    
    return add(shops);
}

bool display_shops_for_place(const PlaceList& list)
{
    string place_name;
    cout << ">>> place name: ";
    getline(cin, place_name);
    
    if (not list.contains(place_name)) {
        return false;
    }

    const ShopList& shops = list.get_shops_const(place_name);
    shops.display();

    return true;
}
