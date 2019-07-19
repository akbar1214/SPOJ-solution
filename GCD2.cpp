#include<bits/stdc++.h>

using namespace std;

const int con = static_cast<int>(1e8 + 5);

int gcd(int a, int b) {

    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main() {

    int T;
    cin >> T;
    while (T--) {

        int a;
        char b[300];
        scanf("%d", &a);
        scanf("%s", b);
        if (a == 0) {
            printf("%s\n", b);
            continue;
        }
        int mod = 0;
        for (int i = 0; i < strlen(b); i++) {
            mod = (mod * 10 + b[i] - '0') % a;
        }
        printf("%d\n", gcd(mod, a));
    }
    return 0;
}
