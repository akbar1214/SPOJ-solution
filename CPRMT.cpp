#include <bits/stdc++.h>

using namespace std;

int main() {

    string s1, s2;
    while (cin >> s1 >> s2) {

        vector<int> freq1(26), freq2(26);
        for (char &c : s1) {
            freq1[c - 'a']++;
        }
        for (char &c : s2) {
            freq2[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {

            while (freq1[i] && freq2[i]) {
                cout << (char) ('a' + i);
                freq1[i]--;
                freq2[i]--;
            }
        }
        cout << '\n';
    }
}
