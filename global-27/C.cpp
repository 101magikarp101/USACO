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
#define mset multiset
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

int T, N;
int a[200005];

int solve(vt<int> &v) {
    int tot = 0;
    for (int i = 0; i < sz(v); i++) {
        if (i%2==0) {
            tot &= v[i];
        } else {
            tot |= v[i];
        }
    }
    return tot;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        if (N <= 5) {
            vt<int> v(N);
            for (int i = 0; i < N; i++) {
                v[i] = i+1;
            }
            vt<int> perm;
            int best = -1;
            do {
                int tot = solve(v);
                if (tot > best) {
                    best = tot;
                    perm = v;
                }
            } while (next_permutation(all(v)));
            cout << best << endl;
            for (int i = 0; i < N; i++) {
                cout << perm[i] << " ";
            }
            cout << endl;
            continue;
        }
        vt<bool> used(N+1,0);
        vt<int> ans;
        int h = -1;
        for (int i = 20; i >= 0; i--) {
            if (N&(1<<i)) {
                h = i;
                break;
            }
        }
        if (N%2==1) {
            ans.pb(N);
            used[N] = 1;
            N--;
        }
        if (N%2 == 0) {
            ans.pb(N);
            used[N] = 1;
            int hm = (1<<(h+1))-1;
            hm ^= N;
            if (hm+1 == N) {
                hm--;
                ans.pb(hm+1);
                used[hm+1] = 1;
                ans.pb(hm);
                used[hm] = 1;
                ans.pb(3);
                used[3] = 1;
                ans.pb(1);
                used[1] = 1;
            } else {
                int l = -1;
                for (int i = 0; i <= h; i++) {
                    if (!(hm&(1<<i))) {
                        l = i;
                        break;
                    }
                }
                ans.pb(hm+(1<<l));
                used[hm+(1<<l)] = 1;
                ans.pb(hm);
                used[hm] = 1;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (!used[i]) {
                ans.pb(i);
            }
        }
        int tot = 0;
        reverse(all(ans));
        for (int i = 0; i < sz(ans); i++) {
            if (i%2==0) {
                tot &= ans[i];
            } else {
                tot |= ans[i];
            }
        }
        cout << tot << endl;
        for (int i = 0; i < sz(ans); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}