#include <iostream>

using namespace std;

int main() {
    int n;
    float curr, sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin  >> curr;
        sum += curr;
    }
    cout << sum;

    return 0;
}
