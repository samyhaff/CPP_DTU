#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x == y) cout << x << " is equal to " << y;
    else if (x > y) cout << x << " is bigger than " << y;
    else cout << x << " is smaller than " << y;

    return 0;
}
