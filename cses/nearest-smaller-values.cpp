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

template <class T> class MaxSegTree {
//MUST BE 0-INDEXED
  private:
    const T DEFAULT = std::numeric_limits<T>().min();
    vector<T> segtree;
    int len;
  public:
    MaxSegTree(int len) : len(len), segtree(len * 4, DEFAULT) {}
    void build() {
        for (int i = len - 1; i > 0; i--) {
            segtree[i] = std::max(segtree[i * 2], segtree[i * 2 + 1]);
        }
    }
    void set(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = std::max(segtree[ind], segtree[ind ^ 1]);
        }
    }
    // @return the maximum element in the range [start, end) 
    T range_max(int start, int end) {
        T max = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { max = std::max(max, segtree[start++]); }
            if (end % 2 == 1) { max = std::max(max, segtree[--end]); }
        }
        return max;
    }
};

ll N;
ll a[200005];
pll b[200005];
map<ll, ll> m, m2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b+1, b+N+1);
    for (int i = 1; i <= N; i++) {
        m[b[i].x] = i;
        m2[i] = b[i].x;
    }
    for (int i = 1; i <= N; i++) {
        a[i] = m[a[i]];
    }
    MaxSegTree<ll> st(N+1);
    st.set(0, 0);
    for (ll i = 1; i <= N; i++) {
        ll res = st.range_max(0, a[i]);
        cout << res << " ";
        st.set(a[i], i);
    }
    cout << endl;
    return 0;
}