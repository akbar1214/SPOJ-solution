#include <bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {

        int n, u;
        scanf("%d%d", &n, &u);
        vector<int> curr(n + 1);
        int l, r, v;
        for (int i = 0; i < u; i++) {
            scanf("%d %d %d", &l, &r, &v);
            curr[l] += v;
            curr[r + 1] += -v;
        }
        for (int i = 1; i <= n; i++)
            curr[i] += curr[i - 1];
        int q;
        scanf("%d", &q);
        while (q--) {

            scanf("%d", &u);
            printf("%d\n", curr[u]);
        }
    }
}
