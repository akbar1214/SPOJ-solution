void bfs(int u,int v){

    vector<int> dist(110,INT_MAX);
    vector<bool> visited(110,false);
    vector<int> no_paths(110);

    queue<int> qe;
    qe.push(u);
    no_paths[u] = 1;
    bool canAdd = true;
    visited[u] = true;
    dist[u] = 0;
    while(!qe.empty()){

        int x = qe.front();qe.pop();

        for(int i:input[x]){

            if(!visited[i]){
                qe.push(i);
                visited[i] = true;
            }

            if(dist[i] > 1 + dist[x]){
                dist[i] = 1 + dist[x];
                no_paths[i] = no_paths[x];
            }

            else if(dist[i] == 1 + dist[x]){
                no_paths[i] += no_paths[x];
            }
        }
    }
    cout  << no_paths[v] << "\n";
}


int main (){
	FASTIO

    int n,m;cin >> n >> m;
    int u,v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        input[u].push_back(v);
        input[v].pb(u);
    }
    int q;cin >> q;
    while(q--){
        cin >> u >> v;
        bfs(u,v);
    }
}
