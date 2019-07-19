#include<bits/stdc++.h>

using namespace std;

const int con = static_cast<int>(1e8 + 5);

int main() {

    int T;
    cin >> T;
    while (T--) {

        int number_of_heroes, number_of_tower, damage;
        cin >> number_of_heroes >> number_of_tower >> damage;

        int x, total = 0;
        for (int i = 0; i < number_of_heroes; i++) {
            cin >> x;
            total += (x - 1) / damage;
        }

        if (total >= number_of_tower) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
}
