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

ll R, C;

int dist2(int x1, int y1, int x2, int y2) {
    return abs(x1-x2)+abs(y1-y2);
}

int dist(int x, int y) {
    int ans = 1e9;
    rep(i,(R-1)/2, 1+R/2) {
        rep(j,(C-1)/2, 1+C/2) {
            ckmin(ans, dist2(x, y, i, j));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> R >> C;
    int P = -1;
    int X = -1, Y = -1;
    int S = -1;
    repl(p,0,C) {
        ll start = 0;
        int cnt1 = 0;
        while (1) {
            cnt1++;
            int next = (p*R+start)/C;
            if (next == start) break;
            start = next;
        }
        ll end = R-1;
        int cnt2 = 0;
        while (1) {
            cnt2++;
            int next = (p*R+end)/C;
            if (next == end) break;
            end = next;
        }
        if (start != end) continue;
        int d = dist((p*R+start)/C, (p*R+start)%C);
        if (d < dist(X, Y)) {
            X = (p*R+start)/C;
            Y = (p*R+start)%C;
            P = p+1;
            S = max(cnt1, cnt2);
        }
    }
    cout << P << " " << X+1 << " " << Y+1 << " " << S << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}