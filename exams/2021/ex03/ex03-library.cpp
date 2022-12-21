#include <iostream>
#include "ex03-library.h"
#include "algorithm"
using namespace std;

// Do not modify
Hotel::Hotel() {
    this->roomNames.push_back("Daisy");
    this->roomOccupancy["Daisy"] = {"Alan Smithee", "xyz890"};

    this->roomNames.push_back("Geranium");

    this->roomNames.push_back("Lotus");
    this->roomOccupancy["Lotus"] = {"Kathryn Bigelow", "456abc"};

    this->roomNames.push_back("Orchid");
    this->roomOccupancy["Orchid"] = {"Alan Smithee", "abc123"};

    this->roomNames.push_back("Tulip");
    this->roomOccupancy["Tulip"] = {"Denis Villeneuve", "123xyz"};
}

// Task 3(a).  Implement this method
void Hotel::addRoom(string name) {
    if (find(roomNames.begin(), roomNames.end(), name) == roomNames.end()) {
        roomNames.push_back(name);
    }
}

// Task 3(b).  Implement this method
void Hotel::addGuest(string roomName, string guestName, string guestId) {
    if (find(roomNames.begin(), roomNames.end(), roomName) == roomNames.end()
        || roomOccupancy.find(roomName) != roomOccupancy.end())
        return;

    for (auto p: roomOccupancy)
        if (p.second.id == guestId)
            return;

    roomOccupancy[roomName] = { .name = guestName, .id = guestId };
}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuest(string guestName, string guestId) {
    for (string roomName: roomNames) {
        if (roomOccupancy.find(roomName) != roomOccupancy.end()) {
            if (guestName == "*" || roomOccupancy[roomName].name == guestName
                && (guestId == "*" || roomOccupancy[roomName].name == guestId)) {
                cout << roomName << endl;
            }
        }
    }
}

// Do not modify
void Hotel::display() {
    for (auto it = this->roomNames.begin(); it != this->roomNames.end(); it++) {
        cout << "Room '" << *it << "' is ";
        if (this->roomOccupancy.find(*it) == this->roomOccupancy.end()) {
            cout << "empty" << endl;
        } else {
            cout << "occupied by " << this->roomOccupancy[*it].name;
            cout << " (id: " << this->roomOccupancy[*it].id << ")" << endl;
        }
    }
}
