#include<bits/stdc++.h>

using namespace std;

char arr[60][60];
int visited[60][60];

int x[] = {1, -1, 0, 0, 1, -1, -1, 1};
int y[] = {0, 0, 1, -1, 1, 1, -1, -1};

int r, c;

bool isValid(int x, int y) {
    return x >= 0 and x < r and y >= 0 and y < c;
}

void dfs(int row, int col, int co) {

    visited[row][col] = co;
    for (int i = 0; i < 8; i++) {

        int rr = row + x[i];
        int cc = col + y[i];

        if (!isValid(rr, cc)) continue;

        if (arr[rr][cc] == 1 + arr[row][col] && visited[rr][cc] < visited[row][col]) {
            dfs(rr, cc, co + 1);
        }
    }
}

int main() {

    for (int ii = 1;; ii++) {

        for (int kk = 0; kk < 60; kk++) {

            for (int jj = 0; jj < 60; jj++) {
                visited[kk][jj] = 0;
            }
        }

        scanf("%d %d", &r, &c);
        if (r == 0 && c == 0) return 0;
        for (int i = 0; i < r; i++) scanf("%s", arr[i]);
        int ans = 0;
        for (int i = 0; i < r; i++) {

            for (int j = 0; j < c; j++) {

                if (arr[i][j] == 'A' && visited[i][j] == 0) {
                    dfs(i, j, 1);
                }
            }
        }

        for (int kk = 0; kk < 60; kk++) {

            for (int jj = 0; jj < 60; jj++) {
                ans = max(ans, visited[kk][jj]);
            }
        }

        cout << "Case " << ii << ": " << ans << '\n';
    }
}
