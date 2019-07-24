#include <bits/stdc++.h>

using namespace std;

const int con = static_cast<int>(1e3 + 3);

struct Road {
    int source, destination, length;

    bool operator<(const Road &rhs) const {
        return length < rhs.length;
    }
};

int number_of_buildings, number_of_streets;
int parent[con];

int get_parent(int src) {

    if (parent[src] == src) return src;
    return parent[src] = get_parent(parent[src]);
}

vector<Road> solve(Road input[]) {

    for (int i = 0; i < con; i++) { parent[i] = i; }
    vector<Road> ans;
    int parent_a, parent_b;
    int cnt = 0;
    for (int i = 0; i < number_of_streets && cnt != number_of_buildings - 1; i++) {

        parent_a = get_parent(input[i].source);
        parent_b = get_parent(input[i].destination);

        if (parent_a == parent_b) continue;
        ++cnt;
        parent[parent_a] = parent_b;
        ans.emplace_back(input[i]);
    }
    return ans;
}

int main() {

    int T;
    cin >> T;
    while (T--) {

        int unit_price;
        cin >> unit_price;
        cin >> number_of_buildings;
        cin >> number_of_streets;
        Road input[number_of_streets];
        for (int i = 0; i < number_of_streets; i++) {
            cin >> input[i].source >> input[i].destination >> input[i].length;
        }
        sort(input, input + number_of_streets);

        vector<Road> ans = solve(input);
        int total = 0;
        for (Road road:ans) total += road.length;
        total *= unit_price;
        cout << total << '\n';
    }
}
