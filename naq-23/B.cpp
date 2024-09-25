#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 9302023
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

int N;
pll dp[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s; N = sz(s);
    vt<string> num = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    dp[0] = {0,1};
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i-1];
        for (int j = 0; j < 10; j++) {
            if (i >= sz(num[j]) && s.substr(i-sz(num[j]), sz(num[j])) == num[j]) {
                pll p = dp[i-sz(num[j])];
                p.x += sz(num[j])-1;
                if (p.x > dp[i].x) {
                    dp[i] = p;
                } else if (p.x == dp[i].x) {
                    dp[i].y += p.y;
                    dp[i].y %= MOD;
                }
            }
        }
    }
    cout << N-dp[N].x << endl;
    cout << dp[N].y << endl;
    return 0;
}