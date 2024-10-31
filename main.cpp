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
             << "5. Search for Villager\n"
             << "6. Display all Villagers\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        string name;
        switch (choice) {
            case 1: { // Add Villager
                int friendshipLevel;
                string species, catchphrase;

                cout << "Villager name: ";
                cin >> name;
                cout << "Friendship level (0-10): ";
                cin >> friendshipLevel;
                cout << "Species: ";
                cin >> species;
                cout << "Catchphrase: ";
                cin.ignore(); 
                getline(cin, catchphrase);

                villagers[name] = make_tuple(friendshipLevel, species, catchphrase);
                cout << name << " added.\n";
                break;
            }
            case 2: { // Delete Villager
                cout << "Villager name to delete: ";
                cin >> name;
                if (villagers.erase(name)) {
                    cout << name << " deleted.\n";
                } else {
                    cout << name << " not found.\n";
                }
                break;
            }
            case 3: { 
                cout << "Villager name to increase friendship: ";
                cin >> name;
                auto it = villagers.find(name);
                if (it != villagers.end()) {
                    int& friendshipLevel = get<0>(it->second);
                    if (friendshipLevel < 10) {
                        friendshipLevel++;
                        cout << "Increased friendship for " << name << ".\n";
                    } else {
                        cout << name << "'s friendship level is already at maximum.\n";
                    }
                } else {
                    cout << name << " not found.\n";
                }
                break;
            }
            case 4: { 
                cout << "Villager name to decrease friendship: ";
                cin >> name;
                auto it = villagers.find(name);
                if (it != villagers.end()) {
                    int& friendshipLevel = get<0>(it->second);
                    if (friends