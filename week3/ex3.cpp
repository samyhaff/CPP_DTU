#include <bits/stdc++.h>

using namespace std;

#define MAX_PAGE 50
#define N_FIELDS 8

typedef struct {
    string first_name;
    string middle_name;
    string last_name;
    string phone;
    string street_address;
    string house_number;
    string zip;
    string region;
} contact;

int main () {
    contact *address_book[MAX_PAGE] = { NULL };
    string command;
    int page;

    while (cin >> command) {
        if (command == "add") {
            cin >> page;
            if (1 <= page && page <= MAX_PAGE && address_book[page - 1] == NULL) {
                contact **entry = address_book + page - 1;
                *entry = new contact;
                cin >> (*entry)->first_name;
                cin >> (*entry)->middle_name;
                cin >> (*entry)->last_name;
                cin >> (*entry)->phone;
                cin >> (*entry)->street_address;
                cin >> (*entry)->house_number;
                cin >> (*entry)->zip;
                cin >> (*entry)->region;
            } else {
                string ignore;
                for (int i = 0; i < N_FIELDS; i++) cin >> ignore;
            }
        }
        else if (command == "clr") {
            cin >> page;
            if (1 <= page && page <= MAX_PAGE) {
                delete address_book[page - 1];
                address_book[page - 1] = NULL;
            }
        }
        else if (command == "qry") {
            cin >> page;
            if (1 <= page && page <= MAX_PAGE && address_book[page - 1]) {
                contact *entry = address_book[page - 1];
                cout << entry->first_name << "," << entry->middle_name
                     << "," << entry->last_name << "," << entry->phone
                     << "," << entry->street_address << "," << entry->house_number
                     << "," << entry->zip << "," << entry->region << endl;
            }
        }
        else break;
    }

    return 0;
}
