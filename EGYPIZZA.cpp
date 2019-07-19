#include<bits/stdc++.h>

using namespace std;

const int con = static_cast<int>(1e8 + 5);
const int INF = static_cast<int>(1e9 + 99);

int main() {

    int n;
    cin >> n;
    string s;
    map<string, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> s;
        mp[s]++;
    }

    int total = mp["3/4"];
    mp["1/4"] -= mp["3/4"];
    mp["1/4"] = max(mp["1/4"], 0);
    total += mp["1/2"] / 2;
    mp["1/2"] %= 2;
    
    if (mp["1/2"]) {
        total++;
        mp["1/4"] -= 2;
    }
    
    mp["1/4"] = max(mp["1/4"], 0);
    total += (mp["1/4"] + 3) / 4;
    cout << total + 1;

}
