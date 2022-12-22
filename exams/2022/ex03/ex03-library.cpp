#include <iostream>
#include "ex03-library.h"
#include "algorithm"
using namespace std;

// Do not modify
Locker::Locker() {
    this->lockerIDs.push_back("LYNGBY01");
    this->lockerOccupancy["LYNGBY01"] = {"Alice", "Daisy", 1234};

    this->lockerIDs.push_back("LYNGBY02");
    this->lockerOccupancy["LYNGBY02"] = {"Claire", "Alice", 567};

    this->lockerIDs.push_back("LYNGBY03");
    this->lockerOccupancy["LYNGBY03"] = {"Daisy", "Bob", 890};

    this->lockerIDs.push_back("LYNGBY04");

    this->lockerIDs.push_back("LYNGBY05");
    this->lockerOccupancy["LYNGBY05"] = {"Bob", "Daisy", 159};

    this->lockerIDs.push_back("LYNGBY06");
}

// Task 3(a).  Implement this method
void Locker::putPackage(string lockerID, string sender, string recipient, int unlockCode) {
    if (find(lockerIDs.begin(), lockerIDs.end(), lockerID) != lockerIDs.end()
        && lockerOccupancy.find(lockerID) == lockerOccupancy.end())
        lockerOccupancy[lockerID] = { sender, recipient, unlockCode };
}

// Task 3(b).  Implement this method
void Locker::retrievePackage(string lockerID, int unlockCode) {
    if (lockerOccupancy.find(lockerID) != lockerOccupancy.end()
        && lockerOccupancy[lockerID].unlockCode == unlockCode)
        lockerOccupancy.erase(lockerID);
}

// Task 3(c).  Implement this method
void Locker::findPackagesByRecipient(vector<string> recipients) {
    for (string lockerID: lockerIDs) {
        if (lockerOccupancy.find(lockerID) != lockerOccupancy.end()
            && find(recipients.begin(), recipients.end(), lockerOccupancy[lockerID].recipient) != recipients.end())
            cout << lockerID << endl;
    }
}

// Do not modify
void Locker::display() {
    for (auto it = this->lockerIDs.begin(); it != this->lockerIDs.end(); it++) {
        cout << "Locker '" << *it << "' ";
        if (this->lockerOccupancy.find(*it) == this->lockerOccupancy.end()) {
            cout << "is empty" << endl;
        } else {
            cout << "contains a package from " << this->lockerOccupancy[*it].sender;
            cout << " to " << this->lockerOccupancy[*it].recipient;
            cout << " (unlock code: " << this->lockerOccupancy[*it].unlockCode << ")" << endl;
        }
    }
}
