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

ll T, N, M, Q;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> Q;
        ll seg1 = 0;
        pll seg2 = {M,M};
        ll seg3 = N+1;
        while (Q--) {
            int x; cin >> x;
            if (seg1 != 0) {
                if (x>seg1) {
                    seg1 = min(N, seg1+1);
                }
            }
            if (seg3 != N+1) {
                if (x<seg3) {
                    seg3 = max(1LL, seg3-1);
                }
            }
            if (seg2.x == -1) {

            } else if (x<seg2.x) {
                seg2.x = max(1LL,seg2.x-1);
            } else if (x>seg2.y) {
                seg2.y = min(N, seg2.y+1);
            } else {
                if (seg1 == 0) seg1++;
                if (seg3 == N+1) seg3--;
                if (seg2.x == seg2.y) {
                    seg2 = {-1,-1};
                }
            }
            // cout << "seg1: " << seg1 << " seg2: " << seg2.x << " " << seg2.y << " seg3: " << seg3 << endl;
            ll res = seg1 + N-seg3+1;
            pll s3 = {seg3, seg1};
            ll siz = s3.y-s3.x+1;
            if (siz > 0) {
                res -= siz;
            } else if (seg2.x != -1) {
                res += seg2.y-seg2.x+1;
                pll s1 = {seg2.x, min(seg2.y,seg1)};
                res -= max(0LL, s1.y-s1.x+1);
                pll s2 = {max(seg2.x,seg3), seg2.y};
                res -= max(0LL, s2.y-s2.x+1);
            }
            cout << res << " ";
        }
        cout << endl;
    }
    return 0;
}