#include <bits/stdc++.h>

using namespace std;
const int con = 1e5 + 3;

int dijkstra(vector<vector<pair<int, int>>> &input, int source, int destination) {

    vector<int> distance(input.size() + 1,INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});
    distance[source] = 0;
    while (!pq.empty()) {

        auto u = pq.top();
        pq.pop();

        if(u.second == destination) {
            return distance[destination];
        }

        for(auto & v : input[u.second]) {

            if(distance[v.first] > distance[u.second] + v.second) {

                distance[v.first] = distance[u.second] + v.second;
                pq.push({distance[v.first],v.first});
            }
        }
    }
    return -1;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {

        int cities, roads, source, destination;
        scanf("%d%d%d%d", &cities, &roads, &source, &destination);
        vector<vector<pair<int, int>>> input(cities);
        int u, v, cost;
        for (int i = 0; i < roads; i++) {
            scanf("%d %d %d", &u, &v, &cost);
            u--;
            v--;
            input[u].emplace_back(v, cost);
            input[v].emplace_back(u, cost);
        }
        int ans = dijkstra(input, source - 1, destination - 1);
        if (ans == -1) {
            printf("NONE\n");
        } else {
            printf("%d\n", ans);
        }
    }
}
