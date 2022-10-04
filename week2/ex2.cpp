#include <iostream>

using namespace std;

int main() {
    bool stop = false;
    int n;
    cin >> n;

    while (n > 1) {
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                if (n / i != 1) cout << i << " * ";
                else cout << i << endl;
                n /= i;
                break;
            }
        }
    }

    return 0;
}
