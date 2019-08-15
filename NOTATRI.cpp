#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    for (cin >> n; n > 0; cin >> n) {

        vector<int> input(n);
        for (int &x : input) scanf("%d", &x);
        sort(input.begin(), input.end());
        int ans = 0;
        for (int i = 0; (int)i < input.size() - 2; i++) {

            for (int j = i + 1;(int) j < input.size() - 1; j++) {

                int sum = input[i] + input[j];
                int rec = upper_bound(input.begin(), input.end(), sum) - input.begin();
                if (sum <= input[rec]) {
                    ans += n - rec;
                }
            }
        }
        cout << ans << '\n';
    }
}
