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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxN = 1e6 + 5;

struct demand {
    ll m, b;
};

ll D;
demand ds[200005];

struct state {
    ll x, v;
    bool operator<(const state& s) const {
        return x < s.x;
    }
};

struct node {
	ll val;
	ll lzAdd;
	ll lzSet;
	node(){};
};

#define lc p << 1
#define rc (p << 1) + 1

template <class T> class SumSegTree {
	//MUST BE 0-INDEXED
  private:
	const T DEFAULT = 0;
	node tree[maxN << 2];
	int len;
  public:

inline void pushup(int p) {
	tree[p].val = tree[lc].val + tree[rc].val;
	return;
}

void pushdown(int p, int l, int mid, int r) {
	// lazy: range set
	if (tree[p].lzSet != 0) {
		tree[lc].lzSet = tree[rc].lzSet = tree[p].lzSet;
		tree[lc].val = (mid - l + 1) * tree[p].lzSet;
		tree[rc].val = (r - mid) * tree[p].lzSet;
		tree[lc].lzAdd = tree[rc].lzAdd = 0;
		tree[p].lzSet = 0;
	} else if (tree[p].lzAdd != 0) {  // lazy: range add
		if (tree[lc].lzSet == 0) tree[lc].lzAdd += tree[p].lzAdd;
		else {
			tree[lc].lzSet += tree[p].lzAdd;
			tree[lc].lzAdd = 0;
		}
		if (tree[rc].lzSet == 0) tree[rc].lzAdd += tree[p].lzAdd;
		else {
			tree[rc].lzSet += tree[p].lzAdd;
			tree[rc].lzAdd = 0;
		}
		tree[lc].val += (mid - l + 1) * tree[p].lzAdd;
		tree[rc].val += (r - mid) * tree[p].lzAdd;
		tree[p].lzAdd = 0;
	}
	return;
}
// build segment tree
// p is the current node, l and r are the range
// void build(int p, int l, int r) {
// 	tree[p].lzAdd = tree[p].lzSet = 0;
// 	if (l == r) {
// 		tree[p].val = a[l];
// 		return;
// 	}
// 	int mid = (l + r) >> 1;
// 	build(lc, l, mid);
// 	build(rc, mid + 1, r);
// 	pushup(p);
// 	return;
// }
// add val to range [a, b]
void add(int p, int l, int r, int a, int b, ll val) {
	if (a > r || b < l) return;
	if (a <= l && r <= b) {
		tree[p].val += (r - l + 1) * val;
		if (tree[p].lzSet == 0) tree[p].lzAdd += val;
		else tree[p].lzSet += val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	add(lc, l, mid, a, b, val);
	add(rc, mid + 1, r, a, b, val);
	pushup(p);
	return;
}
// set range [a, b] to val
void setit(int p, int l, int r, int a, int b, ll val) {
	if (a > r || b < l) return;
	if (a <= l && r <= b) {
		tree[p].val = (r - l + 1) * val;
		tree[p].lzAdd = 0;
		tree[p].lzSet = val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	setit(lc, l, mid, a, b, val);
	setit(rc, mid + 1, r, a, b, val);
	pushup(p);
	return;
}

// get sum of range [a, b]
ll query(int p, int l, int r, int a, int b) {
	if (a > r || b < l) return 0;
	if (a <= l && r <= b) return tree[p].val;
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	return query(lc, l, mid, a, b) + query(rc, mid + 1, r, a, b);
}
};


// signed main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cin >> N >> Q;
// 	for (int i = 1; i <= N; ++i) cin >> a[i];
// 	build(1, 1, N);
// 	for (int i = 1; i <= Q; ++i) {
// 		int k;
// 		cin >> k;
// 		int a, b, x;
// 		if (k == 1) {
// 			cin >> a >> b >> x;
// 			add(1, 1, N, a, b, x);
// 		}
// 		if (k == 2) {
// 			cin >> a >> b >> x;
// 			set(1, 1, N, a, b, x);
// 		}
// 		if (k == 3) {
// 			cin >> a >> b;
// 			ll res = query(1, 1, N, a, b);
// 			cout << res << '\n';
// 		}
// 	}
// 	return 0;
// }

ll add(ll a, ll b) {
    return (a + b) % MOD2;
}

ll sub(ll a, ll b) {
    return (a - b + MOD2) % MOD2;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD2;
}

ll binpow(ll a, ll b) {
    if (b==0) return 0;
    b--;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int main () {
    cin >> D;
    for (int i = 0; i < D; i++) {
        cin >> ds[i].m >> ds[i].b;
    }
    int MAX = ds[D-1].m;
    SumSegTree<ll> st;
    SumSegTree<ll> st2;
    set<state> ss;
    for (int i = 0; i < D; i++) {
        ll m = ds[i].m;
        ll b = ds[i].b;
        ll sum = st2.query(1, 1, MAX, 1, m);
        if (b <= sum) {
            cout << st.query(1, 1, MAX, 1, MAX)%MOD2 << endl;
            continue;
        }
        b-=sum;
        cout << "m: " << m << " b: " << b << endl;
        while (b>0) {
            if (ss.empty()) {
                b+=st2.query(1, 1, MAX, 1, 1)*(m);
                if (b%m!=0) {
                    ss.insert({b%m, b/m+1});
                    st.setit(1, 1, MAX, 1, b%m, binpow(3, b/m+1));
                    st2.setit(1, 1, MAX, 1, b%m, b/m+1);
                }
                ss.insert({m, b/m});
                st.setit(1, 1, MAX, b%m+1, m, binpow(3, b/m));
                st2.setit(1, 1, MAX, b%m+1, m, b/m);
                cout << "setit: " << b%m+1 << " " << m << " " << b/m << endl;
                break;
            }
            cout << "ss: " << endl;
            for (auto s : ss) {
                cout << s.x << " " << s.v << endl;
            }
            auto it = prev(ss.upper_bound({m, -1}));
            state s = *it;
            ll x = s.x;
            ll v = s.v;
            b+=st2.query(1, 1, MAX, x+1, x+1)*(m-x);
            cout << "x: " << x << " v: " << v << " m: " << m << " b: " << b << endl;
            if (b <= (m-x)*v) {
                ll hm = ceil((double)b/(m-x));
                ll d_ = b%(m-x);
                if (hm == v) {
                    ss.erase(s);
                }
                if (d_!=0) {
                    ss.insert({x+d_, hm});
                    st.setit(1, 1, MAX, x+1, x+d_, binpow(3, hm));
                    st2.setit(1, 1, MAX, x+1, x+d_, hm);
                }
                ss.insert({m, b/(m-x)});
                st.setit(1, 1, MAX, x+d_+1, m, binpow(3, b/(m-x)));
                st2.setit(1, 1, MAX, x+d_+1, m, b/(m-x));
                b = 0;
            } else {
                b-=(m-x)*(v);
                if (x<m) {
                    st.setit(1, 1, MAX, x+1, m, binpow(3, v));
                    st2.setit(1, 1, MAX, x+1, m, v);
                    // cout << "setit: " << x+1 << " " << m << " " << binpow(3, v) << endl;
                }
                ss.erase(s);
                // cout << "b: " << b << endl;
            }
        }
        ll ans = st.query(1, 1, MAX, 1, MAX)%MOD2;
        cout << ans << endl;
    }
}