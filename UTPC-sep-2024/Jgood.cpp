#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

ll ad(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

struct dp {
    vt<ll> v;
    dp() {
        v = vt<ll>(13, 0);
    }
    dp(int val) {
        v = vt<ll>(13, 0);
        v[val] = 1;
    }
    dp operator+(const dp &a) const {
        dp res;
        for (int i = 0; i < 13; i++) {
            res.v[i] = ad(res.v[i], ad(v[i], a.v[i]));
        }
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                res.v[(i*j)%13] = ad(res.v[(i*j)%13], mul(v[i], a.v[j]));
            }
        }
        return res;
    }
};

template <class T> class SumSegTree {
    //MUST BE 0-INDEXED
  private:
    const T DEFAULT = 0;
    vector<T> segtree;
    int len;
  public:
    SumSegTree(int l) : len(l), segtree(l * 4, DEFAULT) {}
    void build() {
        for (int i = len - 1; i > 0; i--) {
            segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
        }
    }
    //set the value at index ind to val
    void set(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
        }
    }
    //add val to the value at index ind
    void add(int ind, T val) {
        ind += len;
        segtree[ind] += val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
        }
    }
    //add val to all elements in the range [l, r]
    //v: index of current node
    //tl: left bound of current node
    //tr: right bound of current node
    //l: left bound of range to update
    //r: right bound of range to update
    //add: value to add to all elements in the range [l, r]
    void update(int v, int tl, int tr, int l, int r, T add) {
        if (l > r) return;
        if (l == tl && tr == r) {
            segtree[v] = segtree[v] + add;
        } else {
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), add);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
        }
    }
    //get the value at index pos 
    //v: index of current node
    //tl: left bound of current node
    //tr: right bound of current node
    //pos: index of element to get
    T get(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            return segtree[v];
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return segtree[v] + get(v * 2, tl, tm, pos);
        } else {
            return segtree[v] + get(v * 2 + 1, tm + 1, tr, pos);
        }
    }
    /** @return the sum of the elements in the range [start, end) */
    T range_sum(int start, int end) {
        T sum = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { sum = sum + segtree[start++]; }
            if (end % 2 == 1) { sum = sum + segtree[--end]; }
        }
        return sum;
    }
};

int N, Q;
int a[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    SumSegTree<dp> st(N+1);
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        st.set(i, dp(x%13));
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx, val; cin >> idx >> val;
            val %= 13;
            st.set(idx, dp(val));
        } else {
            int l, r; cin >> l >> r;
            dp res = st.range_sum(l, r+1);
            cout << res.v[5] << endl;
        }
    }
    return 0;
}