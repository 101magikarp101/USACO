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
#define uset unordered_set
#define umap unordered_map
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

// struct Suffix {
//     const int A = 256;
//     vt<int> sa, lcp;
//     int n;
//     Suffix(string &s) {
//         n = sz(s);
//         build_sa(s);
//         // build_lcp(s);
//     }
//     void build_sa(string &s) {
//         vt<int> p(n), c(n), cnt(max(A, n), 0);
//         each(ch,s) cnt[ch]++;
//         rep(i,1,A) cnt[i] += cnt[i-1];
//         rep(i,0,n) p[--cnt[s[i]]] = i;
//         c[p[0]] = 0;
//         int cs = 1;
//         rep(i,1,n) {
//             if (s[p[i]] != s[p[i-1]]) cs++;
//             c[p[i]] = cs-1;
//         }
//         vt<int> pn(n), cn(n);
//         for (int h = 0; (1<<h) < n; h++) {
//             rep(i,0,n) {
//                 pn[i] = p[i]-(1<<h);
//                 if (pn[i] < 0) pn[i] += n;
//             }
//             fill(cnt.begin(), cnt.begin()+cs, 0);
//             each(x,pn) cnt[c[x]]++;
//             rep(i,1,cs) cnt[i] += cnt[i-1];
//             rrep(i,n-1,0) p[--cnt[c[pn[i]]]] = pn[i];
//             cn[p[0]] = 0;
//             cs = 1;
//             rep(i,1,n) {
//                 int m1 = (p[i] + (1<<h)) % n;
//                 int m2 = (p[i-1] + (1<<h)) % n;
//                 if (c[p[i]] != c[p[i-1]] || c[m1] != c[m2]) cs++;
//                 cn[p[i]] = cs-1;
//             }
//             c.swap(cn);
//         }
//         sa = p;
//     }
//     void build_lcp(string &s) {

//     }
// };

struct Suffix {
	vt<int> sa, lcp;
	Suffix(string s, int lim=256) { // or vector<int>
		s.push_back(0); int n = sz(s), k = 0, a, b;
		vt<int> x(all(s)), y(n), ws(max(n, lim));
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
			for (k && k--, j = sa[x[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    string s; cin >> s;
    Suffix suffix(s);
    int n = sz(s);
    rep(i,1,n+1) {
        cout << suffix.sa[i] << " ";
    }
    cout << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}