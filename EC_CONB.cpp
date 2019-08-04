#include <bits/stdc++.h>

using namespace std;

int get_first_set_bit(int n) {
    return 32 - __builtin_clz(n);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {

        int n;
        scanf("%d", &n);
        if (n % 2) {
            printf("%d\n", n);
            continue;
        }
        bitset<32> bi(n);
        int limit = get_first_set_bit(n) - 1;
        for (int i = 0; i < limit; i++, limit--) {

            bool ii = bi.test(i);
            bool jj = bi.test(limit);
            if (ii and !bi.test(limit)) {
                bi.flip(limit);
            }
            if (jj and !bi.test(i)) {
                bi.flip(i);
            }
            if (!ii and bi.test(limit)) {
                bi.flip(limit);
            }
            if (!jj and bi.test(i)) {
                bi.flip(i);
            }
        }
        cout << bi.to_ulong() << '\n';
    }
}
