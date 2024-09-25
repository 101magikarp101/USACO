#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, Q;
int a[1001][1001];

// template <class T, int SZ> class MaxSegTree2D {
//     int n, t[4*SZ][4*SZ];
//     void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, T val) {
//         if (ly == ry) {
//             if (lx == rx) t[vx][vy] = val;
//             else t[vx][vy] = max(t[vx*2][vy], t[vx*2+1][vy]);
//         } else {
//             int my = (ly + ry) / 2;
//             if (y <= my) update_y(vx, lx, rx, vy*2, ly, my, x, y, val);
//             else update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, val);
//             t[vx][vy] = max(t[vx][vy*2], t[vx][vy*2+1]);
//         }
//     }
//     void update_x(int vx, int lx, int rx, int x, int y, T val) {
//         if (lx != rx) {
//             int mx = (lx + rx) / 2;
//             if (x <= mx) update_x(vx*2, lx, mx, x, y, val);
//             else update_x(vx*2+1, mx+1, rx, x, y, val);
//         }
//         update_y(vx, lx, rx, 1, 0, n-1, x, y, val);
//     }
//     T max_y(int vx, int vy, int tly, int try_, int ly, int ry) {
//         if (ly > ry) return -1;
//         if (ly == tly && try_ == ry) return t[vx][vy];
//         int tmy = (tly + try_) / 2;
//         return max(max_y(vx, vy*2, tly, tmy, ly, min(ry, tmy)), max_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry));
//     }
//     T max_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
//         if (lx > rx) return -1;
//         if (lx == tlx && trx == rx) return max_y(vx, 1, 0, n-1, ly, ry);
//         int tmx = (tlx + trx) / 2;
//         return max(max_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry), max_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry));
//     }
// };

// template <class T, int SZ> class SumSegTree2D {
//     int n, t[4*SZ][4*SZ];
//     void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, T val) {
//         if (ly == ry) {
//             if (lx == rx) t[vx][vy] = val;
//             else t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
//         } else {
//             int my = (ly + ry) / 2;
//             if (y <= my) update_y(vx, lx, rx, vy*2, ly, my, x, y, val);
//             else update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, val);
//             t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
//         }
//     }
//     void update_x(int vx, int lx, int rx, int x, int y, T val) {
//         if (lx != rx) {
//             int mx = (lx + rx) / 2;
//             if (x <= mx) update_x(vx*2, lx, mx, x, y, val);
//             else update_x(vx*2+1, mx+1, rx, x, y, val);
//         }
//         update_y(vx, lx, rx, 1, 0, n-1, x, y, val);
//     }
//     T sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
//         if (ly > ry) return 0;
//         if (ly == tly && try_ == ry) return t[vx][vy];
//         int tmy = (tly + try_) / 2;
//         return sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy)) + sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
//     }
//     T sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
//         if (lx > rx) return 0;
//         if (lx == tlx && trx == rx) return sum_y(vx, 1, 0, n-1, ly, ry);
//         int tmx = (tlx + trx) / 2;
//         return sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry) + sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
//     }
// };

// template <class T> class SparseSumSegTree {
//     //MUST BE 0-INDEXED
//     public:
//     struct node {
//         node *l, *r;
//         T x;
//     };
//     node vals[2*100005*18*18];
//     int t = 0;
//     node* st[262144];

//     void update2(node*& n, int i, int x, int lo=0, int hi=-1) {
//     	if (hi == -1) hi = N - 1;
//     	if (hi < i || lo > i) return;
//     	if (!n) n = &vals[t++];
//     	if (lo == hi) {
//     		n->x += x;
//     		return;
//     	}
//     	int mid = (lo + hi) / 2;
//     	if (i <= mid) update2(n->l, i, x, lo, mid);
//     	else update2(n->r, i, x, mid + 1, hi);
//     	n->x += x;
//     }

//     void update(int i, int j, int x, int lo=0, int hi=-1, int node=0) {
// 	    if (hi == -1) hi = N - 1;
//     	if (hi < i || lo > i) return;
//     	if (lo == hi) {
//     		update2(st[node], j, x);
//     		return;
//     	}
//     	int mid = (lo + hi) / 2;
//     	update(i, j, x, lo, mid, 2 * node + 1);
//     	update(i, j, x, mid + 1, hi, 2 * node + 2);
//     	update2(st[node], j, x);
//     }   

//     T query2(node* n, int s, int e, int lo=0, int hi=-1) {
//     	if (hi == -1) hi = N - 1;
//     	if (hi < s || lo > e || !n) return 0;
//     	if (s <= lo && hi <= e) return n->x;
//     	int mid = (lo + hi) / 2;
//     	return query2(n->l, s, e, lo, mid) + query2(n->r, s, e, mid + 1, hi);
//     }

//     T query(int s, int e, int s2, int e2, int lo=0, int hi=-1, int node=0) {
//     	if (hi == -1) hi = N - 1;
//     	if (hi < s || lo > e) return 0;
//     	if (s <= lo && hi <= e) return query2(st[node], s2, e2);
//     	int mid = (lo + hi) / 2;
//     	return query(s, e, s2, e2, lo, mid, 2 * node + 1)
//     			+ query(s, e, s2, e2, mid + 1, hi, 2 * node + 2);
//     }
// };

struct node {
    node *l, *r;
    int x;
};
node vals[2*100005*18*18];
int t = 0;
node* st[262144];
void update2(node*& n, int i, int x, int lo=0, int hi=-1) {
	if (hi == -1) hi = N - 1;
	if (hi < i || lo > i) return;
	if (!n) n = &vals[t++];
	if (lo == hi) {
		n->x += x;
		return;
	}
	int mid = (lo + hi) / 2;
	if (i <= mid) update2(n->l, i, x, lo, mid);
	else update2(n->r, i, x, mid + 1, hi);
	n->x += x;
}
void update(int i, int j, int x, int lo=0, int hi=-1, int node=0) {
    if (hi == -1) hi = N - 1;
	if (hi < i || lo > i) return;
	if (lo == hi) {
		update2(st[node], j, x);
		return;
	}
	int mid = (lo + hi) / 2;
	update(i, j, x, lo, mid, 2 * node + 1);
	update(i, j, x, mid + 1, hi, 2 * node + 2);
	update2(st[node], j, x);
}   
int query2(node* n, int s, int e, int lo=0, int hi=-1) {
	if (hi == -1) hi = N - 1;
	if (hi < s || lo > e || !n) return 0;
	if (s <= lo && hi <= e) return n->x;
	int mid = (lo + hi) / 2;
	return query2(n->l, s, e, lo, mid) + query2(n->r, s, e, mid + 1, hi);
}
int query(int s, int e, int s2, int e2, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (hi < s || lo > e) return 0;
	if (s <= lo && hi <= e) return query2(st[node], s2, e2);
	int mid = (lo + hi) / 2;
	return query(s, e, s2, e2, lo, mid, 2 * node + 1)
			+ query(s, e, s2, e2, mid + 1, hi, 2 * node + 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto start = chrono::high_resolution_clock::now();
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        for (int j = 1; j <= N; j++) {
            a[i][j] = s[j-1] == '*';
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            update(i-1, j-1, a[i][j]);
        }
    }
    while (Q--) {
        int q; cin >> q;
        if (q==1) {
            int x, y; cin >> x >> y;
            a[x][y] ^= 1;
            update(x-1, y-1, a[x][y] ? 1 : -1);
        } else {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            // for (int i = x1; i <= x2; i++) {
            //     for (int j = y1; j <= y2; j++) {
            //         cout << a[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";
            // for (int i = x1; i <= x2; i++) {
            //     for (int j = y1; j <= y2; j++) {
            //         cout << query(i-1, i-1, j-1, j-1) << " ";
            //     }
            //     cout << "\n";
            // }
            cout << query(x1-1, x2-1, y1-1, y2-1) << "\n";
        }
    }
    auto end = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms\n";
    return 0;
}