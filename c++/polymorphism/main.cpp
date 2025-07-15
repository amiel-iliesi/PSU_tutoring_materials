#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Animal {
    private:
        string name;

    public:
        Animal() = default;
        Animal(const string& s): name(s) {}
        virtual ~Animal() = default; //https://stackoverflow.com/a/677623

        string get_name() const {
            return name;
        }

        virtual void make_noise() = 0; // pure virtual function; forces class to be abstract
};

class Dog: public Animal {
    public:
        Dog() = default;
        Dog(const string& s): Animal(s) {}

        void make_noise() override {
            cout << "Woof!" << endl;
        }
};

class Turtle: public Animal {
    private:
        string shell_color;
    public:
        Turtle() = default;
        Turtle(const string& name, const string& shell_color): Animal(name), shell_color(shell_color) {}

        void make_noise() override {
            cout << "..." << endl;
        }

        string get_shell_color() const {
            return shell_color;
        }
};

int main()
{
    vector<unique_ptr<Animal>> animals;

    animals.push_back(make_unique<Dog>("Rover"));
    animals.push_back(make_unique<Turtle>("Shelly", "Turquoise"));

    for (const unique_ptr<Animal>& animal_uptr: animals) {
        Animal* animal_ptr = animal_uptr.get();
        
        if (animal_ptr) {
            cout << animal_ptr->get_name();
            if (dynamic_cast<Dog*>(animal_ptr)) {
                cout << "(Dog)";
            }
            else if (Turtle* turtle = dynamic_cast<Turtle*>(animal_ptr)) {
                cout << "(Turtle)<" << turtle->get_shell_color() << '>';
            }

            cout << ": ";
            animal_ptr->make_noise();
        }
    }

    return 0;
}
