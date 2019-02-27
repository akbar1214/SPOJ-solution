#incldue<bits/stdc++.h>


using namespace std;


int n;



void bfs(int src,vector<int> &distance,vector<pair<int,int>> ma[]){

    distance[src] = 0;
    queue<pair<int,int>> qe;
    qe.push({src,0});
    while(!qe.empty()){

        auto x = qe.front();qe.pop();

        for(auto i:ma[x.first]){

            if(distance[i.first] == -1){

                distance[i.first] = i.second + distance[x.first];
                qe.push({i.first,distance[i.first]});
            }

        }
    }
}




int main(){

    int T,val;cin >> T;
    int u,v;
    while (T--){

        vector<pair<int,int>> ma[50005];
        cin >> n;
        for(int i=0;i<n-1;i++){

            cin >> u >> v >> val;
            ma[u].push_back({v,val});
            ma[v].push_back({u,val});
        }
        vector<int> distance(50005,-1);

        bfs(1,distance,ma);
        int dis = -1,src = -1;


        for(int i=0;i<=n;i++){

            if(distance[i] > dis){
                dis = distance[i];
                src = i;
            }
        }


        for(int i=0;i<50005;i++)
            distance[i] = -1;

        bfs(src,distance,ma);

        dis = -1;
        for(int i=0;i<=n;i++)
            dis = max(dis,distance[i]);

        cout << dis << endl;
    }
}