#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};
#define PI 3.14159265358979323846

ll N;
pll a[100005];
ll b[100005];
map<ll, ll> m;

template <class T> class MaxSegTree {
	//MUST BE 0-INDEXED
  private:
	const T DEFAULT = 0;
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
	/** @return the maximum element in the range [start, end) */
	T range_max(int start, int end) {
		T max = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { max = std::max(max, segtree[start++]); }
			if (end % 2 == 1) { max = std::max(max, segtree[--end]); }
		}
		return max;
	}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    MaxSegTree<ll> st(N);
    for (int i = 0; i < N; i++) {
        ll r, h; cin >> r >> h;
        a[i] = {r*r*h, r*r*h};
        b[i] = r*r*h;
    }
    sort(b, b+N);
    for (int i = 0; i < N; i++) {
        m[b[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        a[i].x = m[a[i].x];
    }
    st.build();
    for (int i = N-1; i >= 0; i--) {
        st.set(a[i].x, a[i].y + st.range_max(a[i].x+1, N));
        // cout << st.range_max(0, N) << endl;
    }
    cout << fixed << setprecision(10) << PI*st.range_max(0, N) << endl;
    return 0;
}