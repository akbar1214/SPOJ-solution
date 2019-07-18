#include<bits/stdc++.h>

using namespace std;

const int con = static_cast<int>(1e6 + 5);
const int INF = static_cast<int>(1e9 + 99);

long long combination(long long n, long long r) {
    r = min(r,n-r);

    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        long long n, k;
        cin >> n >> k;
        cout << combination(n-1,k-1) << '\n';
    }
}
