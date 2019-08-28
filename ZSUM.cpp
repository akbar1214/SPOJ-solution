#include <bits/stdc++.h>

using namespace std;

const int mod = 10000007;
long long power(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {

    long long n, k;
    while (true) {
        scanf("%lld %lld", &n, &k);
        if (n == 0 and k == 0) break;
        long long a, b, c, d;
        a = power(n, k, mod);
        b = power(n - 1, k, mod) * 2;
        c = power(n - 1, n - 1, mod) * 2;
        d = power(n, n, mod);
        printf("%lld\n", (a % mod + b % mod + c % mod + d % mod) % mod);
    }
}
