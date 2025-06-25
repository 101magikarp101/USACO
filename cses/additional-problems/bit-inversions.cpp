#include <bits/stdc++.h>
using namespace std;

struct Node {
    int len, lv, rv;
    int pref, suf, best;
};

vector<Node> seg;
string S;

// merge L and R into P
Node merge(const Node &L, const Node &R){
    Node P;
    P.len  = L.len + R.len;
    P.lv   = L.lv;
    P.rv   = R.rv;

    // prefix
    P.pref = L.pref;
    if (L.pref == L.len && L.rv == R.lv)
        P.pref = L.len + R.pref;

    // suffix
    P.suf  = R.suf;
    if (R.suf == R.len && L.rv == R.lv)
        P.suf = R.len + L.suf;

    // best
    P.best = max(L.best, R.best);
    if (L.rv == R.lv)
        P.best = max(P.best, L.suf + R.pref);

    return P;
}

void build(int idx, int l, int r){
    if (l == r){
        int b = S[l] - '0';
        seg[idx] = {1, b, b, 1, 1, 1};
        return;
    }
    int mid = (l + r) >> 1;
    build(idx<<1, l, mid);
    build(idx<<1|1, mid+1, r);
    seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
}

void update(int idx, int l, int r, int pos){
    if (l == r){
        // flip bit
        int b = 1 - seg[idx].lv;
        seg[idx] = {1, b, b, 1, 1, 1};
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(idx<<1, l, mid, pos);
    else            update(idx<<1|1, mid+1, r, pos);
    seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // read initial string
    cin >> S;
    int n = S.size();

    // build segment tree
    seg.assign(4*n, Node());
    build(1, 0, n-1);

    int m;
    cin >> m;
    while (m--){
        int x;
        cin >> x;
        --x;                 // 0-indexed
        update(1, 0, n-1, x);
        cout << seg[1].best << "\n";
    }
    return 0;
}
