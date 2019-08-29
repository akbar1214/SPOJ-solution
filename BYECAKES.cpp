#include <bits/stdc++.h>

using namespace std;

const int con = (int) 1e5 + 5;

int main() {

    vector<int> has(4), req(4);
    while (true) {

        for (int &x : has) cin >> x;
        for (int &x : req) cin >> x;
        if (has[0] == -1) return 0;

        int cakes_to_make{0};
        for (int i = 0; i < 4; ++i) {
            cakes_to_make = max(cakes_to_make, (has[i] + req[i] - 1) / req[i]);
        }
        for (int i = 0; i < 4; ++i) {
            cout << cakes_to_make * req[i] - has[i] << ' ';
        }
        cout << '\n';
    }
}
