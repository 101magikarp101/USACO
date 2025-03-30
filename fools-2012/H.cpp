#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
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

template<class T> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

int T, N;
int a[200005];

// once counterclockwise
pii rot1(pii p, int a) {
	return {(1<<a)-1-p.y, p.x};
}

pii flipy(pii p, int a) {
	return {p.x, (1<<a)-1-p.y};
}

pii rotate(pii p, int rot, int a, bool flip) {
	rot = (rot%4+4)%4;
	while (rot--) {
		p = rot1(p, a);
	}
	if (flip) {
		p = flipy(p, a);
	}
	return p;
}

pii solve(int a, int b, int rot, bool flip) {
	// cout << "a: " << a << " b: " << b << " rot: " << rot << " flip: " << flip << endl;
	if (a == 1) {
		pii p;
		if (b == 0) p = {0, 0};
		else if (b == 1) p = {0, 1};
		else if (b == 2) p = {1, 1};
		else p = {1, 0};
		p = rotate(p, rot, a, flip);
		return p;
	}
	int q = b>>(2*(a-1));
	int r = b-(q<<(2*(a-1)));
	int nrot = 0;
	bool nflip = 0;
	if (q == 0) {
		nrot = 3;
		nflip = 1;
	} else if (q == 1) {
		nrot = 0;
		nflip = 0;
	} else if (q == 2) {
		nrot = 0;
		nflip = 0;
	} else {
		nrot = 1;
		nflip = 1;
	}
	pii ans = solve(a-1, r, nrot, nflip);
	// cout << ans.x << " " << ans.y << endl;
	if (q == 1) {
		ans.y += (1<<(a-1));
	} else if (q == 2) {
		ans.x += (1<<(a-1));
		ans.y += (1<<(a-1));
	} else if (q == 3) {
		ans.x += (1<<(a-1));
	}
	ans = rotate(ans, rot, a, flip);
	// cout << "ans: " << ans.x << " " << ans.y << endl;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifdef MAGIKARP
	auto start_time = chrono::high_resolution_clock::now();
	#endif

	int a, b; cin >> a >> b;
	pii ans = solve(a, b, 0, 0);
	cout << ans.x << " " << ans.y << endl;

	#ifdef MAGIKARP
	auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
	cerr << "Time: " << duration << "ms" << endl;
	#endif
	return 0;
}