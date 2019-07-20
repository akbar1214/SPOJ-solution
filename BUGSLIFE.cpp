#include<bits/stdc++.h>

using namespace std;

bool isBipartite(vector<int> v[2005], int src, int color[2005]) {

    queue<int> qe;
    qe.push(src);
    color[src] = 1;

    while (!qe.empty()) {

        int u = qe.front();
        qe.pop();

        for (int i = 0; i < v[u].size(); i++) {

            if (color[v[u][i]] == color[u] || v[u][i] == u) {
                return false;
            } else if (color[v[u][i]] == -1) {
                color[v[u][i]] = 1 - color[u];
                qe.push(v[u][i]);
            }
        }

    }

    return true;
}

int main() {

    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {

        int no_bugs, no_interaction;
        cin >> no_bugs >> no_interaction;

        vector<int> v[2005];

        for (int i = 0; i < no_interaction; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        int color[2005];
        for (int &i : color)
            i = -1;

        bool answer = true;

        for (int i = 1; i <= no_bugs; i++) {

            if (color[i] == -1 && !v[i].empty() && answer) {
                answer = isBipartite(v, i, color);
            }
        }

        cout << "Scenario #" << k << ":\n";
        cout << (!answer ? "Suspicious bugs found!" : "No suspicious bugs found!");
        cout << endl;
    }
}
