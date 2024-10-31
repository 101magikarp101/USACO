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
ll a[200005];

int main () {
    cin >> N;
    SumSegTree<ll> seg(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        x--;
        int l = 0, r = N - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (m-seg.range_sum(0, m + 1) >= x) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        seg.add(l, 1);
        cout << a[l] << " ";
    }
    cout << endl;
}