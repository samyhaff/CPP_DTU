#include <bits/stdc++.h>

using namespace std;

void print_vectors(vector<int> a, vector<int> b) {
    auto it_a = a.begin();
    auto it_b = b.begin();

    while (it_a != a.end() || it_b != b.end()) {
        if (it_a != a.end()) cout << *it_a++ << " ";
        if (it_b != b.end()) cout << *it_b++ << " ";
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

    print_vectors(a, b);

    return 0;
}
