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

int N, K;
map<int,int> a[13];
int ncards[13];
bool w[13];
map<char,int> c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string vals = "A23456789DQJK";
    for (int i = 0; i < 13; i++) {
        c[vals[i]] = i;
    }
    cin >> N >> K;
    K--;
    w[K] = 1;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < 4; j++) {
            a[i][c[s[j]]]++;
        }
        ncards[i] = 4;
    }
    ncards[K]++;
    int wval = 100;
    int widx = -1;
    for (int i = 0; i < N; i++) {
        if (ncards[i] == 4) {
            for (auto x : a[i]) {
                if (x.second == 4) {
                    if (x.first < wval) {
                        wval = x.first;
                        widx = i;
                    }
                }
            }
        }
    }
    if (wval != 100) {
        cout << widx+1 << endl;
        return 0;
    }
    bool wild = 1;
    int turn = K;
    while (true) {
        if (!wild && w[turn]) {
            w[turn] = 0;
            ncards[turn]--;
            if (ncards[turn] == 4) {
                for (auto x : a[turn]) {
                    if (x.second == 4) {
                        cout << turn+1 << endl;
                        return 0;
                    }
                }
            }
            turn = (turn+1)%N;
            ncards[turn]++;
            w[turn] = 1;
            wild = 1;
            continue;
        }
        int cnt = 5;
        int val = -1;
        for (auto x : a[turn]) {
            if (x.second < cnt) {
                cnt = x.second;
                val = x.first;
            }
        }
        a[turn][val]--;
        if (a[turn][val] == 0) {
            a[turn].erase(val);
        }
        ncards[turn]--;
        int prev = turn;
        int winval = 100;
        if (ncards[turn] == 4) {
            for (auto x : a[turn]) {
                if (x.second == 4) {
                    winval = min(winval,x.first);
                }
            }
        }
        turn = (turn+1)%N;
        a[turn][val]++;
        ncards[turn]++;
        int winval2 = 100;
        if (ncards[turn] == 4) {
            for (auto x : a[turn]) {
                if (x.second == 4) {
                    winval2 = min(winval2,x.first);
                }
            }
        }
        if (winval != 100 && winval2 == 100) {
            cout << prev+1 << endl;
            return 0;
        } else if (winval == 100 && winval2 != 100) {
            cout << turn+1 << endl;
            return 0;
        } else if (winval != 100 && winval2 != 100) {
            if (winval < winval2) {
                cout << prev+1 << endl;
            } else {
                cout << turn+1 << endl;
            }
            return 0;
        }
        wild = 0;
    }
    return 0;
}