#include <bits/stdc++.h>

using namespace std;

const int con = 1e6 + 100;
vector<int> visited(con);
bool isCorrect;
void dfs(vector<vector<int>> &input, int curr_city, int total) {

    if (visited[curr_city] >= total || total < 0) {
        return;
    }
    visited[curr_city] = total;

    for (int &city : input[curr_city]) {
        dfs(input, city, total - 1);
    }
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        fill(visited.begin(), visited.end(), -1);
        isCorrect = true;
        int n, r, m;
        scanf("%d %d %d", &n, &r, &m);
        vector<vector<int>> input(n + 1);
        vector<pair<int, int>> strength(m);
        int u, v;
        for (int i = 0; i < r; i++) {
            scanf("%d %d", &u, &v);
            input[u].emplace_back(v);
            input[v].emplace_back(u);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            strength[i] = {u, v};
        }
        for (auto &xx:strength) {

            if (visited[xx.first] != -1) {
                isCorrect = false;
                break;
            }
            dfs(input, xx.first, xx.second);
        }
        for (int i = 1; i <= n; i++) {

            if (visited[i] < 0) {
                isCorrect = false;
                break;
            }
        }
        cout << (isCorrect ? "Yes\n" : "No\n");
    }
}
