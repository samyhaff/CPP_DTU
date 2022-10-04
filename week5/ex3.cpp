#include <bits/stdc++.h>

using namespace std;

int scalar_product(vector<int> a, vector<int> b) {
    auto it_a = a.begin();
    auto it_b = b.begin();
    int res = 0;
    int x, y;

    while (it_a != a.end() || it_b != b.end()) {
        x = y = 0;
        if (it_a != a.end()) x = *it_a++;
        if (it_b != b.end()) y = *it_b++;
        res += x * y;
    }

    return res;
}

int main() {
    vector<int> a, b;
    char dataset;
    int val;

    while (cin >> dataset >> val) {
        if (dataset == 'a') a.push_back(val);
        else b.push_back(val);
    }

    cout << scalar_product(a, b);

    return 0;
}
