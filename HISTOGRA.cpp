#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    while (scanf("%d", &n) && n > 0) {

        vector<long long> input(n + 1);

        for (int i = 0; i < n; i++) cin >> input[i];
        input[n] = -1;

        long long ans = 0;
        stack<long long> st;
        for (int i = 0; i <= n;) {

            if (st.empty() || input[st.top()] <= input[i]) {
                st.push(i++);
            } else {

                int top = st.top();
                st.pop();

                long long area = input[top] * (st.empty() ? i : i - st.top() - 1);

                ans = max(ans, area);
            }
        }
        cout << ans << '\n';
    }
}
