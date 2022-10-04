#include <iostream>

#define SIZE 1000

using namespace std;

int main() {
    int c;
    int count[SIZE];

    for (int i = 0; i < SIZE; i++) count[i] = 0;
    while (true) {
        cin >> c;
        if (c == 0) break;
        cout << count[c - 1]++ << endl;
    }

    return 0;
}
