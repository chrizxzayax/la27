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
        const string &catchphrase = get<2>(info);
        cout << "  " << name << " : "
             << "friendship=" << frendship << ", "
             << "species=" << species << ", "
             << "catchphrase=\"" << catchphrase << "\"\n";
    }
        
}


int main() {
    cout << "villager map milestones demo\n";
    mstone2_demo();

    return 0;
    
}