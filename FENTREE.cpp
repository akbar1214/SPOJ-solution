#include <bits/stdc++.h>
using namespace std;

const int con = static_cast<int>(1e6 + 4);

long long tree[con];

void update(int ind, int val) {

    while (ind < con) {
        tree[ind] += val;
        ind += (ind & -ind);
    }
}

long long sum(int ind) {

    long long total = 0;
    while (ind > 0) {

        total += tree[ind];
        ind -= (ind & -ind);
    }
    return total;
}

int main() {

    int n;
    scanf("%d", &n);
    vector<int> input(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &input[i]);
        update(i, input[i]);
    }
    int q;
    scanf("%d", &q);
    int l, r;
    char c[4];
    while (q--) {

        scanf("%s %d %d", c, &l, &r);
        if (c[0] == 'q') {
            cout << sum(r) - sum(l - 1) << '\n';
        } else {
            update(l, r);
        }
    }
}
