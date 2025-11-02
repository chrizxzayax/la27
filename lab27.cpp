// comsc 210 | lab27 | Christian Molina

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
#include <limits>

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

void increasefriendship(map<string, Villagerinfo> &m, const string &name) {
    auto it = m.find(name);
    if (it != m.end()) {
        cout << name << " not found.\n";
        return;
    }
    int &friendship = get<0>(it->second);
    if (friendship < 10) {
        friendship += 1;
        cout << "Increased friendship of " << name << " to " << friendship << ".\n";
    } else {
        cout << name << "'s friendship is already at maximum (10).\n";
    }
}

void decreasefriendship(map<string, Villagerinfo> &m, const string &name) {
    auto it = m.find(name);
    if (it == m.end()) {
        cout << name << " not found.\n";
        return;
    }
    int &friendship = get<0>(it->second);
    if (friendship > 0) {
        friendship -= 1;
        cout << "Decreased friendship of " << name << " to " << friendship << ".\n";
    } else {
        cout << name << "'s friendship is already at minimum (0).\n";
    }
}

void searchvillager(const map<string, Villagerinfo> &m, const string &name) {
    auto it = m.find(name);
    if (it == m.end()) {
        cout << name << " not found.\n";
        return;
    }
    int friendship = get<0>(it->second);
    string species = get<1>(it->second);
    string catchphrase = get<2>(it->second);
    cout << name << " [" << friendship << ", " << species << "] says: \"" << catchphrase << "\"\n";
}

void mstone3_demo() {

    cout << "milestone 3 demo\n";

    map<string, Villagerinfo> villager_details;
    villager_details["Del"]   = make_tuple(8,  string("Alligator"),  string("got a snack?"));

    bool done = false;
    while (!done) {
        int choice = mainmenu();
        string name;
        switch (choice) {
            case 1:
                cout << "villager name to increase";
                getline(cin, name);
                increasefriendship(villager_details, name);
                printvillagerM(villager_details);
                break;
            case 2:
                cout << "villager name to decrease";
                getline(cin, name);
                decreasefriendship(villager_details, name);
                printvillagerM(villager_details);
                break;
            case 3:
                cout << "villager name to search";
                getline(cin, name);
                searchvillager(villager_details, name);
                break;
            case 4:
                done = true;
                break;
            
        }
    }

    cout << "=== End Milestone 3 demo ===\n\n";
}

int main_menu_full() {
    int choice;
    while (true) {
        cout << " full villager menu\n";
        cout << "1. Add Villager\n";
        cout << "2. Delete Villager\n";
        cout << "3. Increase Friendship\n";
        cout << "4. Decrease Friendship\n";
        cout << "5. Search Villager Details\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 6.\n";
            continue;
        }
        if (choice < 1 || choice > 6) {
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer
        return choice;
    }
}

void addvillager(map<string, VillagerInfo> &m) {
    string name, species, catchphrase;
    int friendship = 0;

    cout << "Enter villager name: ";
    getline(cin, name);
    cout << "Enter friendship level (0-10): ";
    while (!(cin >> friendship) || friendship < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a non-negative integer for friendship: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear remainder
    cout << "Enter species: ";
    getline(cin, species);
    cout << "Enter catchphrase: ";
    getline(cin, catchphrase);

    m[name] = make_tuple(friendship, species, catchphrase);
    cout << name << " added.\n";
}

void deletevillager(map<string, VillagerInfo> &m) {
    if (m.empty()) {
        cout << "No villagers to delete.\n";
        return;
    }
    cout << "selec the villager to delete:\n";
    int idx = 1;
    vector<string> keys;
    for (const auto &p : m) {
        cout << "  [" << idx << "] " << p.first << " "
             << "[" << get<0>(p.second) << ", " << get<1>(p.second) << ", " << get<2>(p.second) << "]\n";
        keys.push_back(p.first);
        ++idx;
    }
    cout << "Choice --> ";
    int choice;
    while (!(cin >> choice) || choice < 0 || choice >= idx) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a valid number between 0 and " << (idx - 1) << ": ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 0) {
        cout << "Delete cancelled.\n";
        return;
    }
    string name_to_delete = keys[choice - 1];
    m.erase(name_to_delete);
    cout << name_to_delete << " deleted.\n";

}

void mstone4_demo() {

    cout << "milestone 4 demo\n";

    map<string, VillagerInfo> villager_details;
    villager_details["Jean"] = make_tuple(5, string("Sheep"), string("Baa!"));
    villager_details["Iris"] = make_tuple(7, string("Bird"), string("Tweet!"));

    bool running = true;
    while (running) {
        int choice = main_menu_full();
        switch (choice) {
            case 1:
                addvillager(villager_details);
                printvillagerM(villager_details);
                break;
            case 2:
                deletevillager(villager_details);
                printvillagerM(villager_details);
                break;
            case 3: {
                cout << "Name to increase: ";
                string nm; getline(cin, nm);
                increasefriendship(villager_details, nm);//
                printvillagerM(villager_details);
                break;
            }
            case 4: {
                cout << "Name to decrease: ";
                string nm; getline(cin, nm);
                decreasefriendship(villager_details, nm);
                printvillagerM(villager_details);
                break;
            }
            case 5: {
                cout << "Name to search: ";
                string nm; getline(cin, nm);
                searchvillager(villager_details, nm);
                break;
            }
            case 6:
                running = false;
                break;
        }
    }

    cout << "=== End Milestone 4 demo ===\n\n";
}

int main() {
    cout << "villager map milestones demo\n";
    //i got confused on the last milestone and i added the whole code but i could just added the mstone3_demo


    mstone4_demo();
}