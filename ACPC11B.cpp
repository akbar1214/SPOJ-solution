#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    cin >> T;
    while (T--) {

        int n1, n2;
        cin >> n1;
        vector<int> se1(n1);
        for (int i = 0; i < n1; i++) {
            cin >> se1[i];
        }
        cin >> n2;
        vector<int> se2(n2);
        for (int i = 0; i < n2; i++) {
            cin >> se2[i];
        }
        sort(begin(se1), end(se1));
        sort(begin(se2), end(se2));
        int ans = INT_MAX;
        for (int i = 0, j = 0; i < n1 && j < n2;) {

            ans = min(ans, abs(se1[i] - se2[j]));

            if (se1[i] < se2[j]) ++i;

            else ++j;
        }
        cout << ans << '\n';
    }
}
