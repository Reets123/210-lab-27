// Lab 27: Villager Map
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;

void displayVillagers(const map<string, tuple<int, string, string>>& villagers) {
    cout << "Villager details:\n";
    for (const auto& [name, details] : villagers) {
        cout << name << " ["
             << get<0>(details) << ", "
             << get<1>(details) << ", "
             << get<2>(details) << "]\n";
    }
}

int min() {
    // Declarations
    map<string, tuple<int, string, string>> villagers;

    // Insert initial elements
    villagers["Audie"] = make_tuple(5, "Wolf", "Let's go!");
    villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit!");
    villagers.insert({"Marshal", make_tuple(9, "Squirrel", "Y'all wanna hang out?")});

    int choice;

    do {
        cout << "\nMenu:\n"
             << "1. Add Villager\n"
             << "2. Delete Villager\n"
             << "3. Increase Friendship\n"
             << "4. Decrease Friendship\n"
             << "5. Searc