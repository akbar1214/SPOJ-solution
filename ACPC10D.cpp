#include <bits/stdc++.h>
using namespace std;

const int con = static_cast<int>(1e5 + 3);

int main() {

    int n, cnt = 1;
    while (scanf("%d", &n), n > 0) {

        long long arr[n][3];
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld %lld", &arr[i][0], &arr[i][1], &arr[i][2]);
        }
        arr[1][0] += arr[0][1];
        arr[0][2] += arr[0][1];
        arr[1][1] += min({arr[1][0], arr[0][1], arr[0][2]});
        arr[1][2] += min({arr[0][1], arr[0][2], arr[1][1]});
        for (int i = 2; i < n; i++) {

            arr[i][0] += min(arr[i - 1][0], arr[i - 1][1]);
            arr[i][1] += min({arr[i - 1][0], arr[i - 1][1], arr[i - 1][2], arr[i][0]});
            arr[i][2] += min({arr[i - 1][1], arr[i - 1][2], arr[i][1]});
        }
        printf("%d. %lld\n", cnt++, arr[n - 1][1]);
    }
}
