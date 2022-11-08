#include <bits/stdc++.h>

using namespace std;

int levenshtein(string u, string v) {
    int m = u.length(),  n = v.length();
    if (m == 0) return n;
    if (n == 0) return m;
    return min({
        levenshtein(u.substr(1, m - 1), v) + 1,
        levenshtein(u, v.substr(1, n - 1))  + 1,
        levenshtein(u.substr(1, m - 1), v.substr(1, n - 1)) + (u[0] != v[0])
   });
}

int main() {
    string a, b;

    cin >> a >> b;
    cout << levenshtein(a, b);

    return 0;
}
