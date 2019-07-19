#include<bits/stdc++.h>

using namespace std;


int main() {

    int T;
    cin >> T;
    while (T--) {

        int number_of_heroes, number_of_tower, damage;
        cin >> number_of_heroes >> number_of_tower >> damage;

        int x;
        priority_queue<int> pq;
        for (int i = 0; i < number_of_heroes; i++) {
            cin >> x;
            pq.push(x);
        }
        bool isPossible = true;
        for (int i = 0; i < number_of_tower; i++) {
            int curr = pq.top();
            pq.pop();
            if (curr - damage <= 0) {
                isPossible = false;
                break;
            }
            pq.push(curr - damage);
        }
        cout << (isPossible ? "YES\n" : "NO\n");
    }
}
