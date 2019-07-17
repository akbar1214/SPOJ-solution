#include<bits/stdc++.h>

using namespace std;

const int con = static_cast<int>(3e5 + 5);
const int INF = static_cast<int>(1e9 + 99);

int input[con];
int seg[4*con + 4];

void build(int l,int r,int index) {

    if(l == r) {
        seg[index] = input[l];
        return;
    }
    int mid = (l+r) / 2;
    build(l,mid,2*index);
    build(mid+1,r,2*index+1);
    seg[index] = max(seg[2*index],seg[2*index+1]);
}


int query(int l,int r,int ql,int qr,int index) {

    if(l > qr || r < ql) return INT_MIN;

    if(l >= ql && r <= qr) {
        return seg[index];
    }
    int mid = (l+r) / 2;
    return max(query(l,mid,ql,qr,2*index),query(mid+1,r,ql,qr,2*index+1));
}

int main() {

    int n;cin >> n;
    for(int i=1;i <= n;i++) {
        cin >> input[i];
    }
    build(1,n,1);
    int k;cin >> k;
    for(int i=k;i<=n;i++){
        cout << query(1,n,i-k+1,i,1) << ' ';
    }
    return 0;
}
