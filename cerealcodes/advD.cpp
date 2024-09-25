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
string s, t;
int dp[1000005][4];
bool a[1000005][4];

int rev(int x) {
    return 25-x;
}

int op(int x) {
    return (x+13)%26;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> s >> t;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 1; i <= sz(s); i++) {
        int c = s[i-1]-'a';
        int d = t[i-1]-'a';
        int cnt = 0;
        if (c==d) cnt+=a[i][0] = 1;
        if (rev(c)==d) cnt+=a[i][1] = 1;
        if (op(c)==d) cnt+=a[i][2] = 1;
        if (rev(op(c))==d) cnt+=a[i][3] = 1;
        if (cnt==0) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 4; j++) {
            if (!a[i][j]) continue;
            for (int k = 0; k < 4; k++) {
                int c = 0;
                if ((j&1) && !(k&1)) c++;
                if ((j&2) && !(k&2)) c++;
                dp[i][j] = min(dp[i][j], dp[i-1][k]+c);
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, dp[N][i]);
    }
    cout << (ans==1e9?-1:ans) << endl;
    return 0;
}