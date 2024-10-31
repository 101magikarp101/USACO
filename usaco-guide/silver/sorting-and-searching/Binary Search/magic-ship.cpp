#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

pll operator+(pll a, pll b) {
    return {a.first+b.first, a.second+b.second};
}

pll operator-(pll a, pll b) {
    return {a.first-b.first, a.second-b.second};
}

pll operator*(ll a, pll b) {
    return {a*b.first, a*b.second};
}

ll x1, y1, x2, y2;
int N;
pll a[100005];
map<char, pll> m;
pll en;
pll fin;

bool check(ll t) {
    pll pos = {0, 0};
    ll x = t/N;
    ll y = t%N;
    pos = pos + x*fin + a[y];
    pll diff = en-pos;
    ll time = abs(diff.first)+abs(diff.second);
    return time <= t;
}

int main () {
    m['U'] = {0, 1};
    m['D'] = {0, -1};
    m['L'] = {-1, 0};
    m['R'] = {1, 0};
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> N;
    string s;
    cin >> s;
    a[0] = {0, 0};
    for (int i = 1; i <= N; i++) {
        a[i] = m[s[i-1]];
    }
    for (int i = 1; i <= N; i++) {
        a[i] = a[i]+a[i-1];
    }
    x2 -= x1;
    y2 -= y1;
    en = {x2, y2};
    fin = a[N];
    ll low = 1;
    ll high = 1e18;
    ll mid;
    //min
    while (low < high) {
        mid = (low+high)/2;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid+1;
        }
    }
    if (low == 1e18) {
        cout << -1 << endl;
    } else {
        cout << low << endl;
    }
}