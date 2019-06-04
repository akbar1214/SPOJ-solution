#include<bits/stdc++.h>


using namespace std;

class Edge{
public:
	
	int source;
	int dest;
	long long weight;
};

int findParent(int u,vector<int> &parent){

	if(u == parent[u]){
		return u;
	}
	return findParent(parent[u],parent);
}



long long kruskal(vector<Edge> &input,int n){
	
	//sort the edges according to there weight
	
	sort(input.begin(),input.end(),[](auto &e1,auto &e2){
		
		return e1.weight < e2.weight;
	});
	
	vector<int> parent(n);
	
	for(int i=0;i<n;i++) parent[i] = i;
	
	int i = 0,cnt=0; 
	vector<Edge> ans(n-1);
	while(cnt != n-1){
		
		Edge currentEdge = input[i];
		int sourceEdge = currentEdge.source;
		int destEdge = currentEdge.dest;
		
		int sourceParent = findParent(sourceEdge,parent);
		int destParent = findParent(destEdge,parent);
		
		if(sourceParent != destParent){
			parent[sourceParent] = destParent; 
			ans[cnt++] = currentEdge;
		}
		++i;
	}
	
	long long total = 0;
	for(auto &curr:ans) total += curr.weight;
	return total;
}


int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	int n,m; cin >> n >> m;
	
	vector<Edge> input(m);
	
	for(int i=0;i<m;i++){
		
		cin >> input[i].source;
		cin >> input[i].dest;
		cin >> input[i].weight;
	}
	
	cout << kruskal(input,n);
	
}
