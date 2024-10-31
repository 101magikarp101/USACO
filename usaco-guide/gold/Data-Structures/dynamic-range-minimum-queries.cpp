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

template <class T> class MinSegTree {
	//MUST BE 0-INDEXED
  private:
	const T DEFAULT = std::numeric_limits<T>().max();
	vector<T> segtree;
	int len;
  public:
	MinSegTree(int len) : len(len), segtree(len * 2, DEFAULT) {}
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
	/** @return the minimum element in the range [start, end) */
	T range_min(int start, int end) {
		T min = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { min = std::min(min, segtree[start++]); }
			if (end % 2 == 1) { min = std::min(min, segtree[--end]); }
		}
		return min;
	}
};

int N, Q;

int main () {
    cin >> N >> Q;
    MinSegTree<int> seg(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        seg.set(i, a);
    }
    for (int i = 0; i < Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            seg.set(b - 1, c);
        } else {
            cout << seg.range_min(b - 1, c) << endl;
        }
    }
}