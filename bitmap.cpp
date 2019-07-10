// In the name of ALLAH

#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;


char arr[200][200];



int main() {
    FASTIO

    int T;cin >> T;
    while(T--){
        int lx,ly;cin >> lx >> ly;
        vector<vector<int>> ans(200,vector<int>(200));
        for(int i=0;i<lx;i++){

            for(int j=0;j<ly;j++){
                cin >> arr[i][j];
                if(arr[i][j]=='1') ans[i][j] = 0;
                else ans[i][j] = 10000;
            }
        }
        for(int i=0;i<lx;i++){

            for(int j=0;j<ly;j++){

                if(arr[i][j] == '1') continue;
                int a=100000,b=100000,c=100000;
                if(i-1 >= 0)
                   a = min(ans[i-1][j]+1,10000);
                if(i-1 >= 0 && j-1 >= 0)
                    b = min(ans[i-1][j-1]+2,10000);
                if(j-1 >= 0)
                    c = min(ans[i][j-1]+1,10000);

                ans[i][j] = min({ans[i][j],a,b,c});
            }
        }

        for(int i=lx-1;i >= 0;i--){

            for(int j=ly-1;j>=0;j--){

                if(arr[i][j]=='1') continue;
                int a=100000,b=100000,c=100000;
                if(i+1 < lx)
                    a = min(ans[i+1][j]+1,10000);
                if(i+1 < lx && j+1 < ly)
                    b = min(ans[i+1][j+1]+2,10000);
                if(j+1 < ly)
                    c = min(ans[i][j+1]+1,10000);

                ans[i][j] = min({ans[i][j],a,b,c});
            }
        }

        for(int i=0;i<lx;i++) {
            for (int j = 0; j < ly; j++) cout << ans[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }

}
