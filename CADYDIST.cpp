#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;
    while (true) {
        cin >> N;
        if (N == 0) break;
        long long student[N], price[N];
        for (int i = 0; i < N; ++i) scanf("%lld", &student[i]);
        for (int i = 0; i < N; ++i) scanf("%lld", &price[i]);
        sort(student, student + N);
        sort(price, price + N, greater<long long>());
        unsigned long long ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += price[i] * student[i];
        }
        cout << ans << '\n';
    }
}
