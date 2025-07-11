#include <iostream>
#include <vector>
#include <cctype>
#include "places.h"

using namespace std;

// -function prototypes------------------------------
bool add_place(vector<Place>& places);
bool place_exists(vector<Place>& places, string name);
void display(vector<Place>& places);

int main()
{
    vector<Place> places;

    // -menu-----------------------------------------
    char choice;

    do {
        cout << "1. add a place\n"
             << "2. display places\n"
             << "q. quit\n";
        cout << ">>> ";

        cin.get(choice);
        cin.ignore(256, '\n');
        choice = tolower(choice);

        cout << '\n';

        // -function delegation----------------------
        switch (choice) {
            case '1':
                if (not add_place(places)) {
                    cout << "ERR: already exists!\n";
                }
                break;
            case '2':
                display(places);
                break;
            case 'q':
                cout << "goodbye!\n";
                return 0;
            default:
                cout << "ERR: '" << choice
                     << "' is not a valid choice.\n";
        }

        cout << '\n';

    } while (choice != 'q');

    return 0;
}

// -function implementations-------------------------
bool add_place(vector<Place>& places)
{
    Place new_place;

    cout << "place name: ";
    getline(cin, new_place.name, '\n');

    if (place_exists(places, new_place.name)) {
        return false;
    }

    cout << "place population: ";
    cin >> new_place.population;
    cin.ignore(256, '\n');

    cout << "place rating (1-5): ";
    cin >> new_place.rating;
    cin.ignore(256, '\n');

    places.push_back(new_place);

    return true;
}

bool place_exists(vector<Place>& places, string name)
{
    for (char& c: name) {
        c = tolower(c);
    }

    for (const Place& place: places) {
        string curr_lower_name = place.name;

        for (char& c: curr_lower_name) {
            c = tolower(c);
        }

        if (name == curr_lower_name) {
            return true;
        }
    }

    return false;
}

void display(vector<Place>& places)
{
    cout << "-places---------------------------------\n";
    for (const Place& place: places) {
        cout << "* " << place.name << ", "
             << place.population << ", "
             << place.rating << '\n';
    }
    cout << "----------------------------------------\n";
}
