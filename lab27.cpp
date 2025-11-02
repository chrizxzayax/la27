// comsc 210 | lab27 | Christian Molina

#include <iostream>
#include <map>
#include <vector>
#include <string>


using namespace std;

using Villagername = string;
using ColorList   = vector<string>;
using VillagerInfo = tuple<int, string, string>;

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

using Villagerinfo = tuple<int, string, string>;
void printvillagerM(const map<string, Villagerinfo> &m){

    cout << "villager details:\n";
    for (const auto &p : m) {
        const string &name = p.first;
        const Villagerinfo &info = p.second;
        int frendship = get<0>(info);
        const string &species = get<1>(info);
        const string &catchphrase = get<2>(info);// unpacking tuple
        cout << "  " << name << " : "
             << "friendship=" << frendship << ", "
             << "species=" << species << ", "
             << "catchphrase=\"" << catchphrase << "\"\n";
    }
        
}
void mstone2_demo() {

    cout << "second milestone 2\n";

    map<string, Villagerinfo> villager_details;
    villager_details["Drago"]   = make_tuple(5,  string("Alligator"),  string("Snap into IT!"));
    villager_details["Kyle"]    = make_tuple(10, string("Wolf"),       string("HUBBA HUBBA!!"));
    villager_details["Raymond"] = make_tuple(8,  string("Cat"),        string("Nya nice fit!"));

    printvillagerM(villager_details);// print initial details

    cout << "=== End Milestone 2 demo ===\n\n";
}

int mainmenu() {
    int choice;
    while (true) {
        cout << " basic villager menu\n";
        cout << "1. Increase friendship\n";
        cout << "2. Decrease Friendship\n";
        cout << "3. Search Villager Details\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }
        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer
        return choice;
    }

}


int main() {
    cout << "villager map milestones demo\n";
    mstone2_demo();

    return 0;

}