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

struct rect {
    int x1, y1, x2, y2;
};

int T, N, M;
rect a[100005];
set<pii> s;

void add(int x, int y) {
    if (s.empty()) {
        s.insert({x, y});
        return;
    }
    auto it = s.lower_bound({x, y});
    if (it != s.begin() && prev(it)->y <= y) {
        return;
    }
    // maintain monotonicity
    while (it != s.end() && it->y >= y) {
        it = s.erase(it);
    }
    s.insert({x, y});
}

bool query(int x, int y) {
    if (s.empty()) {
        return 1;
    }
    auto it = s.lower_bound({x, y});
    if (it != s.begin() && prev(it)->y <= y) {
        return 0;
    }
    return 1;
}

void remove(int x, int y) {
    if (s.count({x, y})) {
        s.erase({x, y});
    }   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T >> M;
    if (M == 2) {
        while (T--) {
            s.clear();
            cin >> N;
            rep(i,0,N) {
                cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
            }
            vt<bool> ans(N);
            rrep(i,N-1,0) {
                ans[i] = query(a[i].x2, a[i].y2);
                add(a[i].x1, a[i].y1);
            }
            rep(i,0,N) {
                cout << ans[i];
            }
            cout << endl;
        }
    } else {
        while (T--) {
            s.clear();
            cin >> N;
            rep(i,0,N) {
                cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
            }
            rep(i,0,N) {
                add(a[i].x1, a[i].y1);
            }
            vt<bool> vis(N,0);
            vt<int> ans;
            rep(i,0,N) {
                rep(j,0,N) {
                    if (vis[j]) continue;
                    remove(a[j].x1, a[j].y1);
                    bool ok = query(a[j].x2, a[j].y2);
                    if (ok) {
                        vis[j] = 1;
                        ans.pb(j+1);
                        remove(a[j].x1, a[j].y1);
                        break;
                    } else {
                        add(a[j].x1, a[j].y1);
                    }
                }
                rep(j,0,N) {
                    if (vis[j]) continue;
                    add(a[j].x1, a[j].y1);
                }
            }
            rep(i,0,sz(ans)) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}