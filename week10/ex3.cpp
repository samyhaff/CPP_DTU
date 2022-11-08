#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(vector<int>::iterator left, vector<int>::iterator right) {
    if (right - left <= 1) return true;
    return (*left == *(right - 1) && is_palindrome(left + 1, right - 1));
}

int main() {
    vector<int> sequence;
    int current;

    while (cin >> current) sequence.push_back(current);

    if (is_palindrome(sequence.begin(), sequence.end())) cout << "yes";
    else cout << "no";

    return 0;
}
