#pragma once
#include <string>

// --------------------------------------------------
// -shops--------------------------------------------
struct Shop {
    std::string name;
    std::string type;
    float rating;
};

class ShopList {
    private:
        struct ShopNode {
            Shop data;
            ShopNode* next;

            ShopNode();
            ShopNode(const Shop&, ShopNode*);
        };

        ShopNode* head;
    public:
        ShopList();
        ~ShopList();

        bool contains(std::string) const;

        bool add(const Shop&);
        void display() const;
};

// --------------------------------------------------
// -places-------------------------------------------
struct Place {
    std::string name;
    unsigned population;

    ShopList shops;
};

class PlaceList {
    private:
        struct PlaceNode {
            Place data;
            PlaceNode* next;

            PlaceNode();
            PlaceNode(const Place&, PlaceNode*);
        };

        PlaceNode* head;
    public:
        PlaceList();
        ~PlaceList();

        bool contains(std::string) const;

        bool add(const Place&);
        void display() const;

        // search for, and return inner shop list!
        ShopList& get_shops(std::string);
        const ShopList& get_shops_const(std::string) const;
};
