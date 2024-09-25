#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'

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

int T, N, Q;
set<int> b;
int M = 1<<21;
MaxSegTree<int> st(M);

void add(int x) {
    auto it = b.lower_bound(--x);
    int l = it==b.begin()?-1:*prev(it);
    int r = it==b.end()?(M<<1):*it;
    st.set(l+1, x-l-1);
    st.set(x+1, r-x-1);
    b.insert(x);
}

void remove(int x) {
    b.erase(--x);
    auto it = b.lower_bound(x);
    int l = it==b.begin()?-1:*prev(it);
    int r = it==b.end()?(M<<1):*it;
    st.set(l+1, r-l-1);
    st.set(x+1, 0);
}

int query(int x) {
    int l = 0, r = M-1;
    while (l < r) {
        int m = (l+r)/2;
        if (st.range_max(0, m+1) >= x) {
            r = m;
        } else {
            l = m+1;
        }
    }
    return l+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            add(x);
        }
        cin >> Q;
        while (Q--) {
            char c; int x; cin >> c >> x;
            if (c=='+') {
                add(x);
            } else if (c=='-') {
                remove(x);
            } else {
                cout << query(x) << " ";
            }
        }
        cout << endl;
        while (!b.empty()) {
            remove(*b.begin()+1);
        }
    }
    return 0;
}