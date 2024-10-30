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

int m