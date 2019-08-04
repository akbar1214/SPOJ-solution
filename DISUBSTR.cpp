#include <bits/stdc++.h>
 
using namespace std;
 
int lcp(string &a,string &b) {
 
    for(int i=0;i<a.length() and b.length();i++){
        if(a[i] != b[i]) return i;
    }
    return 0;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
 
        string s;
        cin >> s;
        vector<string> arr(s.size());
        for(int i=0;i<s.size();i++) arr[i] = s.substr(i);;
        sort(arr.begin(),arr.end());
        string prev = "";
        long long ans = 0;
        for(int i=0;i<arr.size();i++) {
 
            ans += arr[i].size() - lcp(arr[i],prev);
            prev = arr[i];
        }
        cout << ans << '\n';
    }
} 
