#include <bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {

        long long n, x;
        cin >> n;
        long long ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            ans += abs(sum - x * i);
            sum += x;
        }
        cout << ans << '\n';
    }
}
