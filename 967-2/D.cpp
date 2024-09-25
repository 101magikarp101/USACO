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

template <class T> class MinSegTree {
//MUST BE 0-INDEXED
  private:
    const T DEFAULT = std::numeric_limits<T>().max();
    vector<T> segtree;
    int len;
  public:
    MinSegTree(int len) : len(len), segtree(len * 4, DEFAULT) {}
    void build() {
        for (int i = len - 1; i > 0; i--) {
            segtree[i] = std::min(segtree[i * 2], segtree[i * 2 + 1]);
        }
    }
    void set(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = std::min(segtree[ind], segtree[ind ^ 1]);
        }
    }
    // @return the minimum element in the range [start, end)
    T range_min(int start, int end) {
        T min = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { min = std::min(min, segtree[start++]); }
            if (end % 2 == 1) { min = std::min(min, segtree[--end]); }
        }
        return min;
    }
};

int T, N;
int a[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        MaxSegTree<int> st(N);
        MinSegTree<int> st2(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            st.set(i, a[i]);
            st2.set(i, a[i]);
        }
        map<int,set<int>> m;
        for (int i = 0; i < N; i++) {
            m[a[i]].insert(i);
        }
        vt<int> ans;
        set<int> s;
        for (auto x : m) {
            s.insert(*x.second.rbegin());
        }
        int l = -1;
        bool turn = 1;
        while (!s.empty()) {
            // cout << "turn: " << turn << endl;
            int r = *s.begin();
            if (turn) {
                int x = st.range_max(l+1, r+1);
                // cout << "l: " << l << " r: " << r << endl;
                // cout << "x: " << x << endl;
                ans.pb(x);
                bool c = 0;
                for (auto y : m[x]) {
                    if (!c && y > l) {
                        l = y;
                        c = 1;
                    }
                    st.set(y, 0);
                    st2.set(y, INT_MAX);
                }
                s.erase(*m[x].rbegin());
                m.erase(x);
            } else {
                int x = st2.range_min(l, r+1);
                // cout << "l: " << l << " r: " << r << endl;
                // cout << "x: " << x << endl;
                ans.pb(x);
                bool c = 0;
                for (auto y : m[x]) {
                    if (!c && y > l) {
                        l = y;
                        c = 1;
                    }
                    st.set(y, 0);
                    st2.set(y, INT_MAX);
                }
                s.erase(*m[x].rbegin());
                m.erase(x);
            }
            turn = !turn;
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}