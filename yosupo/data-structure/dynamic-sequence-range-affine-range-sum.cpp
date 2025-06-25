#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
template <class T> using vvt = vt<vt<T>>;
template <class T> using vvvt = vt<vvt<T>>;
template <class T> using vvvvt = vt<vvvt<T>>;
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
#define each(i,a) for(auto &i:a)
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
    void operator+=(const pii &a) { x += a.x; y += a.y; }
    void operator-=(const pii &a) { x -= a.x; y -= a.y; }
    void operator*=(const int &a) { x *= a; y *= a; }
    void operator/=(const int &a) { x /= a; y /= a; }
    friend ostream& operator<<(ostream &os, const pii &p) {return os << "(" << p.x << ", " << p.y << ")";}
    friend istream& operator>>(istream &is, pii &p) {return is >> p.x >> p.y;}
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
    void operator+=(const pll &a) { x += a.x; y += a.y; }
    void operator-=(const pll &a) { x -= a.x; y -= a.y; }
    void operator*=(const ll &a) { x *= a; y *= a; }
    void operator/=(const ll &a) { x /= a; y /= a; }
    friend ostream& operator<<(ostream &os, const pll &p) {return os << "(" << p.x << ", " << p.y << ")";}
    friend istream& operator>>(istream &is, pll &p) {return is >> p.x >> p.y;}
};
static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x^(x>>30))*0xbf58476d1ce4e5b9;
    x = (x^(x>>27))*0x94d049bb133111eb;
    return x^(x>>31);
}
struct custom_hash {
    static const uint64_t FIXED_RANDOM;
    size_t operator()(uint64_t x) const {return splitmix64(x + FIXED_RANDOM);}
    template<typename T> size_t operator()(const T& t) const {return splitmix64(uint64_t(std::hash<T>{}(t)) + FIXED_RANDOM);}
};
const uint64_t custom_hash::FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(custom_hash::FIXED_RANDOM);
template<typename K, typename V> using umap = unordered_map<K, V, custom_hash>;
template<typename K> using uset = unordered_set<K, custom_hash>;
template<typename T> using umset = unordered_multiset<T, custom_hash>;
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

int ad(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD);
}

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

struct Node {
    Node *l = 0, *r = 0;
    int val, sum;
    int y, c = 1;
    bool lz = 0;
    int lza = 1, lzb = 0;
    Node(int val) : val(val), sum(val), y(rand()) {}
    void recalc();
    void push();
    void merge(int a, int b);
};

inline int cnt(Node* n) { return n ? n->c : 0; }
inline int sa(Node* n) { return n ? n->sum : 0; }
void Node::recalc() { c = cnt(l) + cnt(r) + 1; sum = ad(sa(l), ad(val, sa(r))); }
void Node::merge(int a, int b) {
    lza = mul(lza, a);
    lzb = ad(mul(lzb, a), b);
    val = ad(mul(val, a), b);
    sum = ad(mul(sum, a), mul(cnt(this), b));
}
void Node::push() {
    if (lz) {
        if (l) l->lz ^= 1;
        if (r) r->lz ^= 1;
        swap(l, r);
        lz = 0;
    }
    if (lza!=1 || lzb!=0) {
        if (l) l->merge(lza, lzb);
        if (r) r->merge(lza, lzb);
        lza = 1;
        lzb = 0;
    }
}

// L -> [:k], R -> [k+1:]
pair<Node*, Node*> split(Node* n, int k) {
    if (!n) return {};
    n->push();
    if (cnt(n->l) >= k) { // "n->val >= k" for lower_bound(k)
        auto [L,R] = split(n->l, k);
        n->l = R;
        n->recalc();
        return {L, n};
    } else {
        auto [L,R] = split(n->r,k - cnt(n->l) - 1); // and just "k"
        n->r = L;
        n->recalc();
        return {n, R};
    }
}

Node* merge(Node* l, Node* r) {
    if (!l) return r;
    if (!r) return l;
    l->push();
    r->push();
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        return l->recalc(), l;
    } else {
        r->l = merge(l, r->l);
        return r->recalc(), r;
    }
}

// Insert n at position pos in t, 0-based index
Node* ins(Node* t, Node* n, int pos) {
    auto [l,r] = split(t, pos);
    return merge(merge(l, n), r);
}

// Erase n at position pos in t, 0-based index
Node* erase(Node* t, int pos) {
    auto [L,R] = split(t, pos);
    auto [M,R2] = split(R, 1);
    delete M;
    return merge(L, R2);
}

int N, Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> Q;
    Node* root = 0;
    rep(i,0,N) {
        ll x; cin >> x;
        root = merge(root, new Node(x));
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 0) { // insert
            int i, x; cin >> i >> x;
            root = ins(root, new Node(x), i);
        } else if (t == 1) { // erase
            int i; cin >> i;
            root = erase(root, i);
        } else if (t == 2) { // reverse
            int l, r; cin >> l >> r;
            auto [L,R] = split(root, l);
            auto [M,R2] = split(R, r - l);
            M->lz ^= 1;
            root = merge(merge(L, M), R2);
        } else if (t == 3) { // affine
            int l, r, a, b; cin >> l >> r >> a >> b;
            auto [L,R] = split(root, l);
            auto [M,R2] = split(R, r - l);
            M->merge(a, b);
            root = merge(merge(L, M), R2);
        } else if (t == 4) { // range sum
            int l, r; cin >> l >> r;
            auto [L,R] = split(root, l);
            auto [M,R2] = split(R, r - l);
            cout << sa(M) << endl;
            root = merge(merge(L, M), R2);
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}