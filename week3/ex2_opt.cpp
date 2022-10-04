#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    bool sorted = true;

    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int max = max_element(arr, arr + n) - arr;
    for (int i = 0; i < n; i++) {
        if (i != max) cout << arr[i] << " ";
        else cout << "*" << arr[i] << "* ";
    }

    return 0;
}
