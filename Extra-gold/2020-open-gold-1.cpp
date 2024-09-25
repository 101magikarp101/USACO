#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

template <class T> class SumSegTree {
    //MUST BE 1-INDEXED WHEN USING (FOR V)
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
    //eg: update(1, 0, n-1, 2, 4, 10) will add 10 to the values at indices 2, 3, and 4
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
            if (start % 2 == 1) { sum += segtree[start++]; }
            if (end % 2 == 1) { sum += segtree[--end]; }
        }
        return sum;
    }
};

int N;
int a[100005];

int main() {
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    SumSegTree<int> sst(N+1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vt<ll> dp(N+5);
    for (int i = 0; i < N; i++) {
        ll sum = sst.range_sum(a[i]+1, N+1);
        dp[a[i]+1]+=sum;
        // cout << "sum: " << sum << endl;
        sst.add(a[i], 1);
        // cout << "sst.get(" << a[i] << "): " << sst.get(1, 0, N, a[i]) << endl;
    }
    // for (int i = 0; i <= N; i++) {
    //     cout << "sst.get(" << i << "): " << sst.get(1, 0, N, i) << endl;
    // }
    for (int i = 1; i <= N; i++) {
        dp[i] += dp[i-1];
    }
    for (int i = 0; i < N; i++) {
        cout << dp[i] << endl;
    }
    return 0;
}