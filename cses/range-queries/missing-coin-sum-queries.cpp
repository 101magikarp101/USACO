#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200000;
const int MAXNODE = 5500000;  // ~ n * (log₂n + a small constant)

struct Node {
    ll sum;
    int l, r;
} seg[MAXNODE];

int nodeCnt = 1;  // seg[0] is the “null” node with sum=0, l=r=0

// Create a new node by copying seg[prev]
int newNode(int prev) {
    int cur = nodeCnt++;
    seg[cur] = seg[prev];
    return cur;
}

// Persistent update: add `val` at position `pos` in [l..r], based on version `prev`.
int update(int prev, int l, int r, int pos, ll val) {
    int cur = newNode(prev);
    seg[cur].sum += val;
    if (l < r) {
        int m = (l + r) >> 1;
        if (pos <= m) {
            seg[cur].l = update(seg[prev].l, l, m, pos, val);
        } else {
            seg[cur].r = update(seg[prev].r, m+1, r, pos, val);
        }
    }
    return cur;
}

// Find the smallest-value leaf where the “gap” occurs.
// R = root[b], L = root[a-1], [l..r] is the current value-domain range.
// `reach` is passed by reference: the maximum sum we can form so far.
int findGap(int R, int L, int l, int r, ll &reach) {
    if (l == r) {
        // At a leaf, we’re at a single coin-value.
        return l;
    }
    int m = (l + r) >> 1;
    // Sum of all coins whose compressed-index ∈ [l..m] in the subarray [a..b]:
    ll leftSum = seg[ seg[R].l ].sum - seg[ seg[L].l ].sum;
    // If that block’s total > reach+1, the gap is inside it:
    if (leftSum > reach + 1) {
        return findGap(seg[R].l, seg[L].l, l, m, reach);
    } else {
        // Otherwise absorb them and go right
        reach += leftSum;
        return findGap(seg[R].r, seg[L].r, m+1, r, reach);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Coordinate compression of coin-values
    vector<ll> vals = x;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int M = vals.size();

    auto getIdx = [&](ll v){
        return int(lower_bound(vals.begin(), vals.end(), v) - vals.begin()) + 1;
    };

    // Build the array of version‐roots. root[0] = empty; root[i] = includes x[0..i-1]
    vector<int> root(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int idx = getIdx(x[i-1]);
        root[i] = update(root[i-1], 1, M, idx, x[i-1]);
    }

    // Process queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        ll reach = 0;
        // find the compressed-index of the coin where the first gap appears
        findGap(root[b], root[a-1], 1, M, reach);
        // the answer is the first sum we cannot form
        cout << (reach + 1) << "\n";
    }

    return 0;
}
