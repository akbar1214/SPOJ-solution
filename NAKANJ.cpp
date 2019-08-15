#include <bits/stdc++.h>

using namespace std;

bool checker(pair<int, int> x) {
    return x.first > 0
        and x.second <= 8
        and x.first <= 8
        and x.second > 0;
}

int X[] = {2, 1, -1, -2, -2, -1, 1, 2};
int Y[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(pair<int, int> &source, pair<int, int> destination) {

    vector<vector<bool>> visited(10, vector<bool>(10, false));

    queue<pair<pair<int, int>, int>> qe;

    qe.push({source, 0});
    visited[source.first][source.second] = true;
    while (!qe.empty()) {

        auto curr = qe.front();
        qe.pop();

        if (curr.first == destination) {
            return curr.second;
        }

        for (int i = 0; i < 8; i++) {

            int xx = curr.first.first + X[i];
            int yy = curr.first.second + Y[i];

            if (checker(make_pair(xx, yy)) and !visited[xx][yy]) {
                visited[xx][yy] = true;
                qe.push(make_pair(make_pair(xx, yy), curr.second + 1));
            }
        }
    }
    return -1;
}

int main() {

    int T;
    cin >> T;

    while (T--) {

        string s, d;
        cin >> s >> d;
        pair<int, int> source, destination;
        source.second = s[1] - '0';
        source.first = s[0] - 'a' + 1;
        destination.second = d[1] - '0';
        destination.first = d[0] - 'a' + 1;
        cout << bfs(source, destination) << '\n';

    }
}
