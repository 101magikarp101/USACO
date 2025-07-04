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
            segtree[i] = ad(segtree[i * 2], segtree[i * 2 + 1]);
        }
    }
    //set the value at index ind to val
    void set(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = ad(segtree[ind], segtree[ind ^ 1]);
        }
    }
    //add val to the value at index ind
    void add(int ind, T val) {
        ind += len;
        segtree[ind] += val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = ad(segtree[ind], segtree[ind ^ 1]);
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
            segtree[v] += add;
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
            if (start % 2 == 1) { sum = ad(sum, segtree[start++]); }
            if (end % 2 == 1) { sum = ad(sum, segtree[--end]); }
        }
        return sum;
    }
};

ll T, N;
ll a[200005];
pll b[200005];
map<ll,ll> m, m2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    SumSegTree<ll> st(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        b[i] = {a[i], i};
    }
    sort(b, b+N);
    for (int i = 0; i < N; i++) {
        m[b[i].x] = i;
        m2[i] = b[i].x;
    }
    for (int i = 0; i < N; i++) {
        a[i] = m[a[i]];
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll res = st.range_sum(0, a[i]);
        ans = ad(ans, res+1);
        st.add(a[i], res+1);
    }
    cout << ans << endl;
    return 0;
}