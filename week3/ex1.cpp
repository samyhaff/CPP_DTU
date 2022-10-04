#include <bits/stdc++.h>

using namespace std;

int main () {
    string command;
    int arg;
    set<int> bag;

    while (cin >> command) {
        if (command == "add") {
            cin >> arg;
            bag.insert(arg);
        } else if (command == "del") {
            cin >> arg;
            bag.erase(arg);
        } else if (command == "qry") {
            cin >> arg;
            if (bag.find(arg) != bag.end()) cout << "T";
            else cout << "F";
        } else break;
    }

    return 0;
}
