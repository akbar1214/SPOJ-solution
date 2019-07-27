#include <bits/stdc++.h>
using namespace std;

int main() {

    int q, k;
    scanf("%d %d", &q, &k);
    map<string, long long> mp;
    string s;
    long long x;
    while (q--) {
        cin >> s >> x;
        mp[s] += x;
    }
    vector<pair<string, long long>> arr(mp.begin(), mp.end());
    sort(arr.begin(), arr.end(), [&](auto &x, auto &y) {
        return x.second > y.second;
    });
    x = 0;
    k = min(k, (int) arr.size());
    for (int i = 0; i < k; i++) {
        x += arr[i].second;
    }
    cout << x;
}
