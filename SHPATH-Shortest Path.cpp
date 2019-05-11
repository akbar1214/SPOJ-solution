#include <bits/stdc++.h>
#include <fstream>


#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define pb push_back
//#define _online_judge


using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef pair<int, int> iPair;
const int con = static_cast<const int>(1e5 + 2);
const int MOD = 1000000007;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

int shortestPath(vector<vector<pii>> &input,int src,int dest){

    vector<int> distance(input.size(),INT_MAX);
    distance[src] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,src}); //weight and src first;
    while(!pq.empty()){

        int u = pq.top().ss;pq.pop();
        for(auto j:input[u]){
            int v = j.ss;
            int weight = j.ff;

            if(distance[v] > distance[u] + weight){
                distance[v] = distance[u] + weight;
                pq.push({distance[v],v});
            }
        }
    }
    return distance[dest];
}

int main (){
	FASTIO
#ifdef _online_judge
	freopen("input.txt" , "r", stdin);
	//freopen("gift1.out", "w", stdout);
#endif

    int tt;cin >> tt;
    while(tt--){

        int cities;cin >> cities;//no of cities
        map<string,int> mp;
        vector<vector<pii>> input(cities+1);
        FOR(i,1,cities+1){

            string name;cin >> name;
            mp[name] = i;
            int roads;cin >> roads;
            FOR(j,0,roads){ //taking the input
                int dest,weight;
                cin >> dest >> weight;
                input[i].pb({weight,dest});
                input[dest].pb({weight,i});
            }

        }
        int queries;cin >> queries;
        while(queries--){
            string src,dest;cin >> src >> dest;
            cout << shortestPath(input,mp[src],mp[dest]) << "\n";
        }
    }
}
