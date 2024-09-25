#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {
    int x, y;
    bool operator<(const pii &p) const {
        return x < p.x;
    }
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

int T, N;
pii a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    MaxSegTree<int> st(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i].x >> a[i].y;
    }
    vt<int> ans(N);
    for (int i = N-1; i >= 0; i--) {
        pii p = {a[i].x+a[i].y,0};
        int it = prev(upper_bound(a,a+N,p))-a;
        st.set(i,i);
        int res = st.range_max(i,it+1)-i+1;
        ans[i] = res;
        st.set(i,res+i-1);
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}