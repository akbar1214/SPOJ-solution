#include <bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {

        long long row, col;
        scanf("%lld %lld", &row, &col);
        if (col >= row) {

            if (row & 1) {
                printf("R\n");
            } else {
                printf("L\n");
            }
        } else {
            if (col & 1) {
                printf("D\n");
            } else {
                printf("U\n");
            }
        }
    }
}
