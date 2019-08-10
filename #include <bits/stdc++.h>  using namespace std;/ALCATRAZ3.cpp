#include <bits/stdc++.h>

using namespace std;

int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};

char arr[110][110];
int n, m, k;
int sx, sy;
bool visited[110][110];
bool foundPath = false;
bool check(int i, int j) {
    return i >= 0 and j >= 0 and i < n and j < m;
}

void dfs(int i, int j, int current_length) {
    if (foundPath) return;
    if (i == sx and j == sy and current_length >= k) {
        foundPath = true;
        return;
    }
    visited[i][j] = true;
    for (int ii = 0; ii < 4; ii++) {

        int xx = i + x[ii];
        int yy = j + y[ii];

        if (check(xx, yy) and arr[xx][yy] == '.' and !visited[xx][yy]) {
            visited[xx][yy] = true;
            dfs(xx, yy, current_length + 1);
            visited[xx][yy] = false;
        }
    }
    visited[i][j] = false;
}

int main() {

    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    scanf("%d %d", &sx, &sy);
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    sx--;
    sy--;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < 4; i++) {
        int xx = x[i] + sx;
        int yy = y[i] + sy;
        if (check(xx, yy)) {
            dfs(xx, yy, 1);
        }
    }
    cout << (foundPath ? "YES" : "NO");
    return 0;
}
