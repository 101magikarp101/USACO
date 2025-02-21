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
//163 game

bool solve(vt<string> &v) {
    vt<double> st;
    for (string s : v) {
        if (s == "+") {
            if (st.size() < 2) return 0;
            double a = st.back(); st.pop_back();
            double b = st.back(); st.pop_back();
            st.pb(a + b);
        } else if (s == "-") {
            if (st.size() < 2) return 0;
            double a = st.back(); st.pop_back();
            double b = st.back(); st.pop_back();
            st.pb(b - a);
        } else if (s == "*") {
            if (st.size() < 2) return 0;
            double a = st.back(); st.pop_back();
            double b = st.back(); st.pop_back();
            st.pb(a * b);
        } else if (s == "/") {
            if (st.size() < 2) return 0;
            double a = st.back(); st.pop_back();
            double b = st.back(); st.pop_back();
            if (abs(a) < 1e-9) return 0;
            st.pb(b / a);
        } else {
            st.pb(stod(s));
        }
    }
    // for (string s : v) {
    //     cout << s << " ";
    // }
    // cout << " = " << st.back() << endl;
    return abs(st.back() - 163) < 1e-9;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    N = 6;
    string ops = "+-*/";
    vt<int> nums;
    rep(i,0,N) {
        cin >> a[i];
        nums.pb(a[i]);
    }
    sort(all(nums));
    vt<int> perm(N+N-1,0);
    rep(i,0,N-1) {
        perm[i] = -1;
    }
    rep(i,N-1,N+N-1) {
        perm[i] = nums[i-N+1];
    }
    do {
        // cout << "perm: ";
        // rep(i,0,2*N-1) {
        //     cout << perm[i] << " ";
        // }
        // cout << endl;
        for (int m = 0; m < (1 << (2*(N-1))); m++) {
            vt<string> v;
            int cnt = 0;
            for (int i = 0; i < 2*N-1; i++) {
                if (perm[i] == -1) v.pb(string(1,ops[(m >> (2*cnt)) & 3])), cnt++;
                else v.pb(to_string(perm[i]));
            }
            if (solve(v)) {
                rep(i,0,2*N-1) {
                    cout << v[i] << " ";
                }
                cout << endl;
                // return 0;
            }
        }
    } while (next_permutation(all(perm)));
    cout << "No solution" << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}