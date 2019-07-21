#include<bits/stdc++.h>

using namespace std;

const int con = static_cast<int>(1e5 + 3);

struct SegmentTreeNode {

    int max_num, second_max_num;

    SegmentTreeNode() = default;

    SegmentTreeNode(int x, int y) {
        max_num = x;
        second_max_num = y;
    }

    void assignLeaf(int num) {
        this->max_num = num;
        this->second_max_num = -1;
    }

    void merge(SegmentTreeNode &x, SegmentTreeNode &y) {

        this->max_num = max(max(x.max_num, y.second_max_num), max(x.second_max_num, y.max_num));
        this->second_max_num = min(max(x.max_num, y.second_max_num), max(x.second_max_num, y.max_num));
    }

    int getvalue() {

        return this->max_num + this->second_max_num;
    }
};

template<class T, class V>
class SegmentTree {

    SegmentTreeNode *node;
    int N{};
 public:

    SegmentTree(T arr[], int N) {
        this->N = N;
        node = new SegmentTreeNode[getSegmentTreeSize(N)];
        build(arr, 1, 1, N);
    }

    int getValue(int low, int high) {

        SegmentTreeNode res = getValue(1, 1, N, low, high);
        return res.getvalue();
    }

    void update(int t_index, int low, int high, int index, T value) {

        if (low == high) {
            node[t_index].assignLeaf(value);
            return;
        }

        int mid = (low + high) / 2;
        if (index <= mid) update(2 * t_index, low, mid, index, value);
        else update(2 * t_index + 1, mid + 1, high, index, value);
        node[t_index].merge(node[2 * t_index], node[2 * t_index + 1]);
    }

 private:
    int getSegmentTreeSize(int n) {

        int size = 1;
        while (N > size) size <<= 1;
        return size << 1;
    }

    void build(V arr[], int t_index, int low, int high) {

        if (low == high) {
            node[t_index].assignLeaf(arr[low]);
            return;
        }

        int mid = (low + high) / 2;

        build(arr, 2 * t_index, low, mid);
        build(arr, 2 * t_index + 1, mid + 1, high);
        node[t_index].merge(node[2 * t_index], node[2 * t_index + 1]);
    }

    SegmentTreeNode getValue(int t_index, int low, int high, int qlow, int qhigh) {

        if (low > qhigh || high < qlow) {
            return SegmentTreeNode(0, 0);
        }

        if (low >= qlow && high <= qhigh) {
            return node[t_index];
        }
        int mid = (low + high) / 2;

        auto lr = getValue(2 * t_index, low, mid, qlow, qhigh);
        auto rr = getValue(2 * t_index + 1, mid + 1, high, qlow, qhigh);

        SegmentTreeNode res{};
        res.merge(lr, rr);
        return res;
    }
};

int main() {

    int arr[con];
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    SegmentTree<int, int> st(arr, n);
    int q;
    cin >> q;
    char ch[3];
    int l, r;
    while (q--) {
        scanf("%s %d %d", ch, &l, &r);
        if (ch[0] == 'U') {
            st.update(1, 1, n, l, r);
        } else {
            cout << st.getValue(l, r) << '\n';
        }
    }
}
