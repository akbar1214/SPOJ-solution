#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second


using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
const int con = static_cast<const int>(2e5 + 5);
const int MOD = 1e9 + 7;

vector<int> prime;
vector<vector<int>> li(10002);


void sieve(){

    bool arr[10002];
    memset(arr,0,sizeof arr);
    arr[0] = arr[1] = true;
    for(int i=2;i<10002;i++){

        if(!arr[i]){
            for(int j = 2*i;j < 10002;j += i){
                arr[j] = true;
            }
        }
    }
    FOR(i,1000,10001){
        if(!arr[i])  prime.push_back(i);
    }
}

bool difference_of_one_digit(int x,int y){

    string s1 = to_string(x),s2 = to_string(y);
    int cnt = 0;
    for(int i=0;i<s1.size();i++){

        if(s1[i] != s2[i]) ++cnt;
    }
    return cnt == 1;
}

void create_list(){

    for(int i=0;i<prime.size();i++){

        for(int j=i+1;j<prime.size();j++){

            if(difference_of_one_digit(prime[i],prime[j])){
                li[prime[i]].push_back(prime[j]);
                li[prime[j]].push_back(prime[i]);
            }
        }
    }
}


int main (){

    //for fast IO
    FASTIO
    //for creating prime no array
    sieve();
    //for creating a graph of connected components
    create_list();


    int T;cin >> T;
    while(T--){

        int x,y; cin >> x >> y;
        queue<pii> qe;
        qe.push({x,0});
        bool visited[10005];memset(visited,false,sizeof visited);
        visited[x] = true;
        int ans = INT_MAX;
        while(!qe.empty()){

            auto curr = qe.front();qe.pop();
            if(curr.ff == y){
                ans = min(ans,curr.ss);
            }

            for(int j:li[curr.ff]){

                if(!visited[j]){
                    qe.push({j,curr.ss+1});
                    visited[j] = true;
                }
            }
        }
        if(ans == INT_MAX) cout << "Impossible\n";
        else cout << ans << "\n";

    }
}
