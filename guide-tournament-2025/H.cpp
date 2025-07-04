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
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
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

template <class T> class MinSegTree {
private:
    const T DEFAULT = std::numeric_limits<T>().max();
    vector<T> tree;
    int len;
public:
    MinSegTree(int len) : len(len), tree(len * 4, DEFAULT) {}
    void build() {
        for (int i = len - 1; i > 0; i--) {
            tree[i] = std::min(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    void set(int node, int s, int e, int idx, T val) {
        if (s == e) {
            tree[node] = val;
            return;
        }
        int m = (s + e) / 2;
        if (idx <= m) {
            set(node * 2, s, m, idx, val);
        } else {
            set(node * 2 + 1, m + 1, e, idx, val);
        }
        tree[node] = std::min(tree[node * 2], tree[node * 2 + 1]);
    }
    // [l, r]
    T query(int node, int s, int e, int l, int r) {
        if (l > r) return DEFAULT;
        if (s > r || e < l) return DEFAULT;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) / 2;
        T left = query(node * 2, s, m, l, r);
        T right = query(node * 2 + 1, m + 1, e, l, r);
        return std::min(left, right);
    }
};

int T, N;
int a[300005], dp[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N;
        MinSegTree<int> st(N);
        map<int,int> mp;
        rep(i,0,N) {
            cin >> a[i];
            if (!mp.count(a[i])) {
                mp[a[i]] = sz(mp);
            }
            a[i] = mp[a[i]];
            dp[i] = -1;
        }
        // cout << "a: ";
        // rep(i,0,N) cout << a[i] << ' ';
        // cout << endl;
        rrep(i,N-1,0) {
            if (a[i] == sz(mp)-1) {
                dp[i] = i;
            } else {
                int mi = st.query(1,0,N-1,a[i]+2,sz(mp)-1);
                int j = st.query(1,0,N-1,a[i]+1,a[i]+1);
                // cout << "i: " << i << " mi: " << mi << " j: " << j << endl;
                if (mi > j) {
                    dp[i] = dp[j];
                }
            }
            // cout << "i: " << i << " dp[i]: " << dp[i] << endl;
            st.set(1,0,N-1,a[i],i);
        }
        int ans = INT_MAX;
        rep(i,0,N) {
            if (a[i] == 0 && dp[i] != -1) {
                ckmin(ans,dp[i]-i+1);
            }
        }
        cout << ans << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}