#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    cin >> T;
    while (T--) {

        long long n;
        cin >> n;
        bool found = false;
        for (long long i = 1; i * i <= n; i++) {

            if (sqrt(n - i * i) == ceil(sqrt(n - i * i))) {
                cout << "Yes\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "No\n";
    }
}
