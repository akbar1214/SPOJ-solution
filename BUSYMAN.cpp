#include<bits/stdc++.h>

using namespace std;


int main() {

    int T;
    cin >> T;
    while (T--) {

        int no_of_activities;
        cin >> no_of_activities;
        vector<pair<int, int>> input(no_of_activities);

        for (auto &x : input) {
            cin >> x.first >> x.second;
        }

        sort(input.begin(), input.end(), [&](const auto &x, const auto &y) {

            if (x.second != y.second) return x.second < y.second;
            return x.first < y.first;
        });

        int curr_time = 0, cnt = 0;
        for (int i = 0; i < no_of_activities; i++) {

            if (input[i].first >= curr_time) {
                curr_time = input[i].second;
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
}
