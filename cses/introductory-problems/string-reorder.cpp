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

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    vt<int> a(26,0);
    string s; cin >> s;
    N = sz(s);
    int n = N;
    rep(i,0,N) a[s[i]-'A']++;
    string ans = "";
    mset<pii, greater<pii>> st;
    rep(i,0,26) {
        st.insert({a[i], i});
    }
    if (st.begin()->x > (N+1)/2) {
        cout << -1 << endl;
        return 0;
    }
    rep(i,0,N) {
        n--;
        rep(j,0,26) {
            if (i && ans[i-1] == j + 'A') continue;
            // cout << "i: " << i << " j: " << j << endl;
            if (a[j]) {
                st.erase({a[j], j});
                a[j]--;
                st.insert({a[j], j});
                int x = st.begin()->x;
                int y = st.begin()->y;
                if (x <= (n+1)/2) {
                    if (n%2 && x == (n+1)/2 && j == y) {
                        st.erase({a[j], j});
                        a[j]++;
                        st.insert({a[j], j});
                        continue;
                    } else {
                        ans += (char)(j + 'A');
                        break;
                    }
                } else {
                    st.erase({a[j], j});
                    a[j]++;
                    st.insert({a[j], j});
                    continue;
                }
            }
        }
    }

    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}