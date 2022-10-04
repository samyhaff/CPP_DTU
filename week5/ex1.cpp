#include <bits/stdc++.h>

using namespace std;

void print_vect(vector<int> v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
     }
}

int main() {
    vector<int> a, b;
    char dataset;
    int val;

    while (cin >> dataset >> val) {
        if (dataset == 'a') a.push_back(val);
        else b.push_back(val);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    print_vect(a);
    print_vect(b);

    return 0;
}
