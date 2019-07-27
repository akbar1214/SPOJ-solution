#include <bits/stdc++.h>

using namespace std;
int main() {

    int T;
    scanf("%d", &T);
    while (T--) {

        int n;
        scanf("%d", &n);
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        vector<int> ind(10, -1);
        ind[arr[n - 1]] = n - 1;
        bool found = false;
        for (int i = n - 2; i >= 0; i--) {
            ind[arr[i]] = i;
            if (arr[i] < arr[i + 1]) {
                found = true;
                int pos;
                for (int j = arr[i] + 1; j < 10; j++) {

                    if (ind[j] != -1) {
                        pos = ind[j];
                        break;
                    }
                }
                swap(arr[i], arr[pos]);
                sort(arr.begin() + i + 1, arr.end());
                break;
            }
        }
        if (found) {
            for (int &x:arr) cout << x;
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }
}
