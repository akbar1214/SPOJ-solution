#include<bits/stdc++.h>

using namespace std;


int main() {

    int n, ans{0};
    cin >> n;
    int arr[n];
    for (int &x:arr) cin >> x;

    unordered_map<int,int> mp;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            for (int k = 0; k < n; k++) {

                mp[arr[i] * arr[j] + arr[k]]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            for (int k = 0; k < n; k++) {

                if (arr[i] == 0) continue;

                if (mp.count((arr[j] + arr[k]) * arr[i])) {

                    ans += mp[(arr[j]+arr[k])*arr[i]];
                }
            }
        }
    }

    cout << ans;
}
