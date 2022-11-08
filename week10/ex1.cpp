#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void reverse_sequence(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    if (begin == end) return;
    reverse_sequence<T>(begin + 1, end);
    cout << *begin << " ";
}

int main() {
    vector<int> v;
    int current;

    while (cin >> current) v.push_back(current);
    reverse_sequence<int>(v.begin(), v.end());

    return 0;
}
