#include<bits/stdc++.h>

using namespace std;

const int con = static_cast<int>(1e6 + 5);

int block_size;

struct Query {
    int left, right, id;

    bool operator<(const Query &rhs) const {

        return make_pair(left / block_size, right) < make_pair(rhs.left / block_size, rhs.right);
    }
};

vector<int> input;

void mo_algo(vector<Query> query) {

    vector<int> ans(query.size());
    sort(query.begin(), query.end());
    int freq[con];memset(freq,0, sizeof(freq));
    int cur_l = query[0].left;
    int cur_r = cur_l-1;
    int cnt = 0;
    for (Query q:query) {

        while (cur_r > q.right) {
            freq[input[cur_r]]--;
            if (freq[input[cur_r]] == 0) --cnt;
            cur_r--;
        }

        while (cur_r < q.right) {
            cur_r++;
            freq[input[cur_r]]++;
            if (freq[input[cur_r]] == 1) ++cnt;
        }

        while (cur_l > q.left) {
            cur_l--;
            freq[input[cur_l]]++;
            if (freq[input[cur_l]] == 1) ++cnt;
        }

        while (cur_l < q.left) {
            freq[input[cur_l]]--;
            if (freq[input[cur_l]] == 0) --cnt;
            cur_l++;
        }
        ans[q.id] = cnt;
    }
    for (int &x:ans) cout << x << '\n';
}

int main() {

    int n;
    scanf("%d", &n);
    block_size = sqrt(n) + 1;

    input.resize(n+1);
    for(int i=0;i<n;i++) cin >> input[i];

    int q;
    scanf("%d", &q);
    vector<Query> query(q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &query[i].left, &query[i].right);
        query[i].left--;query[i].right--;
        query[i].id = i;
    }
    mo_algo(query);
}
