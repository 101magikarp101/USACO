#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

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

template <class T> class MinSegTree {
//MUST BE 0-INDEXED
  private:
    const T DEFAULT = std::numeric_limits<T>().max();
    vector<T> segtree;
    int len;
  public:
    MinSegTree(int len) : len(len), segtree(len * 4, DEFAULT) {}
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
    // @return the minimum element in the range [start, end)
    T range_min(int start, int end) {
        T min = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { min = std::min(min, segtree[start++]); }
            if (end % 2 == 1) { min = std::min(min, segtree[--end]); }
        }
        return min;
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

template <class T> class BIT {
public:
    vector<T> bit;
    vector<T> a;
    ll size;

    BIT(ll n) {
        size = n;
        bit.resize(n + 1);
        a.resize(n + 1);
    }

    void add(ll i, T x) {
        a[i] += x;
        for (ll k = i; k <= size; k += k & -k) {
            bit[k] += x;
        }
    }

    void set(ll i, T x) {
        add(i, x - a[i]);
    }

    T sum(ll i) {
        if (i <= 0) return 0;
        if (i > size) i = size;
        T s = 0;
        for (ll k = i; k > 0; k -= k & -k) {
            s += bit[k];
        }
        return s;
    }
};

struct point{
    ll x, y;
    bool operator<(const point &p) const{if(x==p.x)return y<p.y;return x<p.x;}
    bool operator>(const point &p) const{if(x==p.x)return y>p.y;return x>p.x;}
    bool operator==(const point &p) const{return x==p.x&&y==p.y;}
    bool operator!=(const point &p) const{return x!=p.x||y!=p.y;}
    bool operator<=(const point &p) const{if(x==p.x)return y<=p.y;return x<=p.x;}
    bool operator>=(const point &p) const{if(x==p.x)return y>=p.y;return x>=p.x;}
};
struct line{
    point a, b;
};
struct polygon{
    ll n;
    vt<point> v;
};
ll area(polygon p){
    ll res = 0;
    for (int i = 0; i < p.n; i++){
        res += (p.v[i].x*p.v[(i+1)%p.n].y-p.v[i].y*p.v[(i+1)%p.n].x);
    }
    return abs(res);
}
ll cross(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int signum(ll x){
    return (x > 0) - (x < 0);
}
bool intersect1(line a, line b) {
    int res1 = signum(cross(a.a, a.b, b.a))*signum(cross(a.a, a.b, b.b));
    int res2 = signum(cross(b.a, b.b, a.a))*signum(cross(b.a, b.b, a.b));
    if (res1 == 0 && res2 == 0) {
        if (a.a > a.b) swap(a.a, a.b);
        if (b.a > b.b) swap(b.a, b.b);
        return a.a <= b.b && b.a <= a.b;
    } else return res1 <= 0 && res2 <= 0;
}
bool intersect(line a, line b) {
    return signum(cross(a.a, a.b, b.a))*signum(cross(a.a, a.b, b.b)) <= 0 && signum(cross(b.a, b.b, a.a))*signum(cross(b.a, b.b, a.b)) <= 0;
}
int in(point p, polygon po) {
    int cnt = 0;
    for (int i = 0; i < po.n; i++) {
        line side = {po.v[i], po.v[(i+1)%po.n]};
        if (cross(side.a, side.b, p) == 0) {
            if (min(side.a, side.b) <= p && p <= max(side.a, side.b)) return 2;
        }
        int j = (i+1)%po.n;
        if (side.a.y <= p.y && p.y < side.b.y) {
            if (cross(side.a, side.b, p) > 0) cnt++;
        }
        if (side.b.y <= p.y && p.y < side.a.y) {
            if (cross(side.b, side.a, p) > 0) cnt++;
        }
    }
    return cnt%2;
} // 0 = outside, 1 = inside, 2 = on edge

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll sub(ll a, ll b) {
    return (a-b+MOD)%MOD;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}