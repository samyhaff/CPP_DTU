#include <bits/stdc++.h>

using namespace std;


class Fibonacii {
public:
    Fibonacii() {
        dp[0] = 1;
    }
    unordered_map<int, int> dp;
    int operator()(int n) {
        if (n < 0) return 0;
        if (dp.find(n) != dp.end()) return dp[n];
        int res = (*this)(n - 1) + (*this)(n - 2);
        dp[n] = res;
        return res;
    }
};

int main() {
    int n;
    Fibonacii fibonacii;

    while (cin >> n)
        cout << fibonacii(n) << " ";

    return 0;
}
