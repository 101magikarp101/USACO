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

template <class T> class SumSegTree {
    //MUST BE 0-INDEXED
  private:
    const T DEFAULT = 0;
    vector<T> tr;
    vector<T> lz;
    int len;
  public:
    SumSegTree(int l) : len(l), tr(l*4, DEFAULT), tr(l*4, DEFAULT) {}
    void build() {
        for (int i = len - 1; i > 0; i--) {
            tr[i] = tr[i*2] + tr[i*2+1];
        }
    }
    void set(int ind, T val) {
        ind += len;
        tr[ind] = val;
        for (; ind > 1; ind /= 2) {
            tr[ind / 2] = tr[ind] + tr[ind ^ 1];
        }
    }
    void add(int ind, T val) {
        ind += len;
        tr[ind] += val;
        for (; ind > 1; ind /= 2) {
            tr[ind / 2] = tr[ind] + tr[ind ^ 1];
        }
    }
    void update(int v, int tl, int tr, int l, int r, T add) {
        if (l > r) return;
        if (l == tl && tr == r) {
            tr[v] += add;
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
            return tr[v];
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return tr[v] + get(v * 2, tl, tm, pos);
        } else {
            return tr[v] + get(v * 2 + 1, tm + 1, tr, pos);
        }
    }
    /** @return the sum of the elements in the range [start, end) */
    T range_sum(int start, int end) {
        T sum = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { sum += tr[start++]; }
            if (end % 2 == 1) { sum += tr[--end]; }
        }
        return sum;
    }
};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}