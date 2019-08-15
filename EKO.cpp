#include <bits/stdc++.h>

using namespace std;

const int con = 1e6 + 4;

long long sum[con];
vector<int> input;

long long getWood(long long height) {

    int pos = lower_bound(input.begin(), input.end(), height) - input.begin();
    long long total_wood = sum[input.size() - 1] - (sum[pos - 1] + (input.size() - pos) * height);
    return total_wood;
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    
    input.resize(n);
    for (int &x:input) scanf("%d", &x);
    
    sort(input.begin(), input.end());
    sum[0] = input[0];
    
    for (int i = 1; i < n; i++) {
        sum[i] = input[i];
        sum[i] += sum[i - 1];
    }

    long long low = input[0], high = input[n - 1];
    while (low <= high) {

        long long mid = (low + high) / 2;
        long long total_wood = getWood(mid);
        if (total_wood == m) {
            cout << mid;
            return 0;
        }
        if (total_wood > m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << (low + high)/2;
    return 0;
}
