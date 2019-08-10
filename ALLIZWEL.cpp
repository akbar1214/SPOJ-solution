#include <bits/stdc++.h>

using namespace std;

const string req = "ALLIZZWELL";
bool isPresent = false;

int x[] = {1, -1, 0, 0, 1, 1, -1, -1};
int y[] = {0, 0, 1, -1, 1, -1, 1, -1};

char arr[110][110];
int c_x, c_y;
bool visited[110][110];

bool check(int i, int j) {
    return i >= 0 and j >= 0 and i < c_x and j < c_y;
}

bool dfs(int index, int i, int j) {

    if (index == 9) {
        return true;
    }
    visited[i][j] = true;
    for (int ii = 0; ii < 8; ii++) {

        int xx = i + x[ii];
        int yy = j + y[ii];

        if (check(xx, yy)) {

            if (arr[xx][yy] == req[index + 1] and !visited[xx][yy]) {
                visited[xx][yy] = true;

                if (dfs(index + 1, xx, yy)) {
                    return true;
                }
                visited[xx][yy] = false;
            }
        }
    }
    visited[i][j] = false;
    return false;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        isPresent = false;
        scanf("%d%d", &c_x, &c_y);
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < c_x; i++) scanf("%s", arr[i]);

        for (int i = 0; i < c_x; i++) {

            for (int j = 0; j < c_y; j++) {

                if (arr[i][j] == 'A' and dfs(0, i, j)) {
                    isPresent = true;
                    break;
                }
            }
        }
        cout << (isPresent ? "YES" : "NO") << endl;
    }
}
