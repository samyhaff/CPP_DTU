#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, current, previous;
    bool sorted = true;

    cin >> n;
    cin >> previous;
    for (int i = 0; i < n - 1; i++) {
        cin >> current;
        if (current < previous) sorted = false;
        previous = current;
    }

    if (sorted) cout << "SORTED";
    else cout << "UNSORTED";

    return 0;
}
