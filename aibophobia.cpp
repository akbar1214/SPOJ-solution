// In the name of ALLAH

#include<bits/stdc++.h>

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main() {
    FASTIO

    int T;cin >> T;
    while(T--){

        vector<vector<int>> dp(6103,vector<int>(6103));
        string s1,s2;cin >> s1;
        s2 = s1;
        reverse(s1.begin(),s1.end());
        int siz = s1.size();
        FOR(i,0,siz+1){

            FOR(j,0,siz+1){

                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout << (siz - dp[siz][siz]) << '\n';
    }

    return 0;
}
