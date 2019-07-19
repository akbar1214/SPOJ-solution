#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << b / __gcd(a, b) << " " << a / __gcd(a, b) << '\n';
    }
}
