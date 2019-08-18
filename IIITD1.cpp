#include<bits/stdc++.h>
using namespace std;

int len(long n) {
    int ans = 0;
    while (n) {
        ++ans;
        n /= 10;
    }
    return ans;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {

        long n;
        cin >> n;
        if (n == 0) {
            cout << 1 << '\n';
            continue;
        }
        cout << fixed;
        bool negative = n < 0;
        n = abs(n);
        int length = len(n);
        long ans = 1;
        for (int i = 0; i < length - 1; ++i) ans *= 10;
        cout << (negative ? 2 * n + ans : ans) << '\n';
    }
}
