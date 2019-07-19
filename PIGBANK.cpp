#include<bits/stdc++.h>

using namespace std;

const int con = static_cast<int>(1e8 + 5);

int main() {

    int T;
    cin >> T;
    while (T--) {

        int empty_weight, filled_weight;
        cin >> empty_weight >> filled_weight;

        int number_of_coins;
        cin >> number_of_coins;

        int weight[number_of_coins], value[number_of_coins];

        for (int i = 0; i < number_of_coins; i++) {
            cin >> value[i] >> weight[i];
        }

        vector<int> ans(filled_weight + 3, con);
        int siz = filled_weight - empty_weight;
        ans[0] = 0;
        for (int i = 0; i <= siz; i++) {

            for (int j = 0; j < number_of_coins; j++) {

                if (i >= weight[j])
                    ans[i] = min(ans[i], ans[i - weight[j]] + value[j]);
            }
        }
        if (ans[siz] == con) {
            cout << "This is impossible.\n";
        } else {
            cout << "The minimum amount of money in the piggy-bank is " << ans[siz] << ".\n";
        }
    }
}
