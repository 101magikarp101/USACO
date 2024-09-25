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

template <class T> class SumSegTree {
	//MUST BE 0-INDEXED
  private:
	const T DEFAULT = 0;
	vt<T> tree;
	int len;
    
  public:
	SumSegTree(int l) : len(l), tree(l * 4, DEFAULT) {}
	void build() {
		for (int i = len - 1; i > 0; i--) {
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		}
	}
    //set the value at index ind to val
	void set(int i, T v) {
		i += len;
		tree[i] = v;
		for (; i > 1; i /= 2) {
			tree[i / 2] = tree[i] + tree[i ^ 1];
		}
	}
    //add val to all elements in the range [l, r]
    //v: index of current node
    //tl: left bound of current node
    //tr: right bound of current node
    //l: left bound of range to update
    //r: right bound of range to update
    //add: value to add to all elements in the range [l, r]
    void update(int v, int tl, int tr, int l, int r, T add) {
        if (l > r) return;
        if (l == tl && tr == r) {
            tree[v] += add;
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
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return tree[v] + get(v * 2, tl, tm, pos);
        } else {
            return tree[v] + get(v * 2 + 1, tm + 1, tr, pos);
        }
    }
	/** @return the sum of the elements in the range [l, r) */
	T range_sum(int l, int r) {
		T sum = DEFAULT;
		for (l += len, r += len; l < r; l /= 2, r /= 2) {
			if (l % 2 == 1) { sum += tree[l++]; }
			if (r % 2 == 1) { sum += tree[--r]; }
		}
		return sum;
	}
};

int N, Q;

int main () {
    cin >> N >> Q;
    SumSegTree<ll> seg(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        seg.update(1, 0, N - 1, i, i, a);
    }
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            ll u;
            cin >> a >> b >> u;
            seg.update(1, 0, N - 1, a - 1, b - 1, u);
        } else {
            int k;
            cin >> k;
            cout << seg.get(1, 0, N - 1, k - 1) << endl;
        }
    }
}