// In the name of ALLAH

#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int fp(vector<vector<int>> &dp){

    int row = dp.size()-1, col = dp[0].size() - 1;
    while (dp[row][col] == dp[row][col-1]) --col;
    return col;
}

int main() {
    FASTIO

    int weight,number;cin >> weight >> number;
    while(weight && number){

        vector<int> cost(number),fun(number);
        FOR(i,0,number){
            cin >> cost[i] >> fun[i];
        }

        vector<vector<int>> happiness(number+1,vector<int>(weight+1));
        FOR(i,0,number+1){

            FOR(j,0,weight+1){

                if(i == 0 || j == 0){
                    happiness[i][j] = 0;
                }
                else if(j >= cost[i-1]){
                    happiness[i][j] = max(happiness[i-1][j],fun[i-1] + happiness[i-1][j-cost[i-1]]);
                }else{
                    happiness[i][j] = happiness[i-1][j];
                }
            }
        }

        cout << fp(happiness) << ' ' << happiness[number][weight] << '\n';
        cin >> weight >> number;
    }

    return 0;
}
