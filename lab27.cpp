// comsc 210 | lab27 | Christian Molina

#include <iostream>
#include <map>
#include <vector>
#include <string>


using namespace std;

using Villagername = string;

void mstone1_demo() {

    cout << "second attempt milestone 1\n";

    map<string, vector<string>> villager_colors;
    villager_colors["Alice"] = {"Red", "Blue"};
    villager_colors["Bob"] = {"Green", "Yellow"};
    villager_colors["Omar"] = {"Gold", "Brown", "Black"};

    cout << "Villager favorite colors:\n";
    for (const auto &p : villager_colors) {
        cout << "  " << p.first << " : ";
        for (const auto &c : p.second) cout << c << " ";
        cout << "\n";
    }
    cout << "=== End Milestone 1 demo ===\n\n";
    

}
int main() {
    // declarations
    map<string, vector<string>> villager_colors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villager_colors["Audie"] = {"Orange", "Yellow", "Red"};
    villager_colors["Raymond"] = {"Black", "Gray", "White"};
    villager_colors.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villager_colors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villager_colors.begin(); 
                                               it != villager_colors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villager_colors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villager_colors.find(searchKey);
    if (it != villager_colors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villager_colors.size() << endl;
    villager_colors.clear();
    cout << "Size after clear: " << villager_colors.size() << endl;

    return 0;
}