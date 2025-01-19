#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define each(i,a) for(auto &i:a)
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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

struct dat {
    int mi1, ma1, ans1, mi2, ma2, ans2;
    dat() : mi1(1e9), ma1(-1e9), ans1(0), mi2(1e9), ma2(-1e9), ans2(0) {}
    dat operator+ (const dat &a) {
        dat res;
        res.mi1 = min(mi1, a.mi1);
        res.ma1 = max(ma1, a.ma1);
        res.ans1 = max({ans1, a.ans1, a.ma1 - mi1});
        res.mi2 = min(mi2, a.mi2);
        res.ma2 = max(ma2, a.ma2);
        res.ans2 = max({ans2, a.ans2, ma2 - a.mi2});
        return res;
    }
};

template <class T> class SegTree {
private:
    vector<dat> tree;
    int len;
public:
    SegTree(int len) : len(len), tree(len * 4) {}
    void set(int node, int s, int e, int idx, T v1, T v2) {
        if (s == e) {
            tree[node].mi1 = tree[node].ma1 = v1;
            tree[node].mi2 = tree[node].ma2 = v2;
            return;
        }
        int m = (s + e) / 2;
        if (idx <= m) {
            set(node * 2, s, m, idx, v1, v2);
        } else {
            set(node * 2 + 1, m + 1, e, idx, v1, v2);
        }
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    dat query(int node, int s, int e, int l, int r) {
        if (s > r || e < l) return dat();
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) / 2;
        dat left = query(node * 2, s, m, l, r);
        dat right = query(node * 2 + 1, m + 1, e, l, r);
        return left + right;
    }
};

int T, N, Q;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N >> Q;
        SegTree<int> st(N);
        rep(i,0,N) {
            cin >> a[i];
            st.set(1,0,N-1,i,a[i]-i,a[i]-(N-i-1));
        }
        auto q1 = st.query(1,0,N-1,0,N-1);
        int ans = max(q1.ans1, q1.ans2);
        cout << ans << endl;
        while (Q--) {
            int l, v; cin >> l >> v;
            l--;
            a[l] = v;
            st.set(1,0,N-1,l,a[l]-l,a[l]-(N-l-1));
            auto q2 = st.query(1,0,N-1,0,N-1);
            int res = max(q2.ans1, q2.ans2);
            cout << res << endl;
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}