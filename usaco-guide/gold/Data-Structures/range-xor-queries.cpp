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

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class T> class SegTree {
    //MUST BE 0-INDEXED
  private:
    const T DEFAULT = 0;
    vector<T> segtree;
    int len;
  public:
    SegTree(int len) : len(len), segtree(len * 2, DEFAULT) {}
    void build() {
        for (int i = len - 1; i > 0; i--) {
            segtree[i] = segtree[i * 2] ^ segtree[i * 2 + 1];
        }
    }
    void set(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = segtree[ind] ^ segtree[ind ^ 1];
        }
    }
    T range_xor(int start, int end) {
        T xo = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { xo ^= segtree[start++]; }
            if (end % 2 == 1) { xo ^= segtree[--end]; }
        }
        return xo;
    }
};

int N, Q;

int main () {
    cin >> N >> Q;
    SegTree<int> seg(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        seg.set(i, a);
    }
    seg.build();
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        cout << seg.range_xor(a - 1, b) << endl;
    }
}