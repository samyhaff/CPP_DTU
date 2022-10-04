#include <iostream>

using namespace std;

double pi(int n) {
    double term, sum = 0;
    for (int i = 0; i < n ; i++) {
        term = 1. / (2 * i + 1);
        sum += (i % 2 == 0) ? term : -term;
    }
    return 4 * sum;
}

int main() {
    int n;

    cin >> n;
    cout << pi(n);

    return 0;
}
