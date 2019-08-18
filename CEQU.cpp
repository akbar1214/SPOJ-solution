#include<bits/stdc++.h>
using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for (int tt = 1; tt <= T; ++tt) {
        cout << "Case " << tt << ": ";
        int a, b, c;
        cin >> a >> b >> c;
        a = __gcd(a, b);
        cout << (c % a == 0 ? "Yes\n" : "No\n");
    }
}
