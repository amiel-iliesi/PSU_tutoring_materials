#include "list.h"
#include <cctype>
#include <iostream>
#include <exception>
#include <utility>

using namespace std;

string lower(string s) {
    for (char& c: s) {
        c = tolower(c);
    }
    
    return s;
}

// --------------------------------------------------
// -shops--------------------------------------------
ShopList::ShopNode::ShopNode(): next(nullptr) {}

ShopList::ShopNode::ShopNode(const Shop& shop, ShopNode* next = nullptr):
    data(shop), next(next) {}

ShopList::ShopList(): head(nullptr) {}

ShopList::~ShopList()
{
    while (head) {
        ShopNode* to_delete = head;
        head = head->next;
        delete to_delete;
    }
}

bool ShopList::contains(string name) const
{
    name = lower(name);

    for (const ShopNode* curr = head; curr; curr = curr->next) {
        if (name == lower(curr->data.name)) {
            return true;
        }
    }

    return false;
}

bool ShopList::add(const Shop& shop)
{
    if (contains(shop.name)) {
        return false;
    }

    string name = lower(shop.name);
    
    if (!head) {
        head = new ShopNode(shop);
        return true;
    }

    string curr_name = lower(head->data.name);
    if (name < curr_name) {
        head = new ShopNode(shop, head);
        return true;
    }

    ShopNode* prev = head;
    while (prev->next) {
        string curr_name = lower(prev->next->data.name);

        if (name < curr_name) {
            prev->next = new ShopNode(shop, prev->next);
            return true;
        }

        prev = prev->next;
    }

    prev->next = new ShopNode(shop);
    return true;
}

void ShopList::display() const
{
    for (const ShopNode* curr = head; curr; curr = curr->next) {
        {
            const Shop& shop = curr->data;
            cout << "* " << shop.name << '(' << shop.type << "): "
                 << shop.rating << '\n';
        }
    }
}

// --------------------------------------------------
// -places-------------------------------------------
PlaceList::PlaceNode::PlaceNode(): next(nullptr) {}

PlaceList::PlaceNode::PlaceNode(const Place& place, PlaceNode* next = nullptr):
    data(place), next(next) {}

PlaceList::PlaceList(): head(nullptr) {}

PlaceList::~PlaceList()
{
    while (head) {
        PlaceNode* to_delete = head;
        head = head->next;
        delete to_delete;
    }
}

bool PlaceList::contains(string name) const
{
    name = lower(name);

    for (const PlaceNode* curr = head; curr; curr = curr->next) {
        if (name == lower(curr->data.name)) {
            return true;
        }
    }

    return false;
}

bool PlaceList::add(const Place& place)
{
    if (contains(place.name)) {
        return false;
    }

    string name = lower(place.name);
    
    if (!head) {
        head = new PlaceNode(place);
        return true;
    }

    string curr_name = lower(head->data.name);
    if (name < curr_name) {
        head = new PlaceNode(place, head);
        return true;
    }

    PlaceNode* prev = head;
    while (prev->next) {
        string curr_name = lower(prev->next->data.name);

        if (name < curr_name) {
            prev->next = new PlaceNode(place, prev->next);
            return true;
        }

        prev = prev->next;
    }

    prev->next = new PlaceNode(place);
    return true;
}

void PlaceList::display() const
{
    for (const PlaceNode* curr = head; curr; curr = curr->next) {
        {
            const Place& place = curr->data;
            cout << place.name << ", population: " << place.population << '\n';
            place.shops.display();

            if (curr->next) {
                cout << '\n';
            }
        }
    }
}

ShopList& PlaceList::get_shops(string place_name)
{
    place_name = lower(place_name);

    for (PlaceNode* curr = head; curr; curr = curr->next) {
        if (place_name == lower(curr->data.name)) {
            return curr->data.shops;
        }
    }

    throw std::invalid_argument(place_name + " does not exist in list");
}

const ShopList& PlaceList::get_shops_const(string place_name) const
{
    place_name = lower(place_name);

    for (PlaceNode* curr = head; curr; curr = curr->next) {
        if (place_name == lower(curr->data.name)) {
            return curr->data.shops;
        }
    }

    throw std::invalid_argument(place_name + " does not exist in list");
}
