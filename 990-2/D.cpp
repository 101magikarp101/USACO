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
#define rrep(i,a,b) for(int i=a;i>=b;i--)
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

struct state {
    mset<int> s;
    int v;
};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        deque<state> dq;
        mset<int> s;
        rep(i,0,N) {
            cin >> a[i];
            s.insert(a[i]);
            dq.pb({{a[i]},0});
        }
        vt<int> ans;
        int cnt = N;
        while (!s.empty()) {
            int tar = *s.begin();
            s.erase(s.begin());
            // cout << "tar: " << tar << endl;
            vt<state> v;
            while (!dq.empty() && dq.front().v+*(dq.front().s.begin()) > tar) {
                s.erase(s.find(dq.front().v+*(dq.front().s.begin())));
                v.pb({dq.front().s,dq.front().v+1});
                dq.pop_front();
            }
            auto cur = dq.front();
            ans.pb(*(cur.s.begin()) + cur.v);
            // cout << "cur: " << *(cur.s.begin()) << " " << cur.v << " " << cur.i << endl;
            dq.pop_front();
            if (sz(cur.s) > 1) {
                cur.s.erase(cur.s.begin());
                dq.push_front(cur);
                s.insert(cur.v+*(cur.s.begin()));
            }
            if (v.empty()) continue;
            sort(all(v),[](state a, state b) {
                return sz(a.s) > sz(b.s);
            });
            rep(i,1,sz(v)) {
                each(j,v[i].s) {
                    v[0].s.insert(j+v[i].v-v[0].v);
                }
            }
            dq.push_back({v[0].s,v[0].v});
            // cout << "insert: " << v[0].v+*(v[0].s.begin()) << " " << cnt << endl;
            s.insert(v[0].v+*(v[0].s.begin()));
        }
        each(i,ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}