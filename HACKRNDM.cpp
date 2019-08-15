#include <bits/stdc++.h>

using namespace std;
const int con = 1e5 + 3;
int arr[con];
int main() {

    int n, k;
    scanf("%d %d", &n, &k);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        mp[arr[i]]++;
    }
    long ans = 0;
    for (int i = 0; i < n; i++) {

        if (mp.count(arr[i] + k)) {
            ans += mp[arr[i] + k];
        }
        if (mp.count(arr[i] - k)) {
            ans += mp[arr[i] - k];
        }
    }
    printf("%ld", ans / 2);
}
