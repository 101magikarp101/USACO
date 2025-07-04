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

using namespace std;

int N, M;
string s;
ll MOD = 998244353;

ll facmod(ll n) {
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
        res %= MOD;
    }
    return res;
}

int main() {
    cin >> N >> M;
    cin >> s;
    ll ma = N;
    ll mi = 1;
    ll cnt = 1;
    ll cnt1 = 0; // <
    ll cnt2 = 0; // >
    for (int i = N - 2; i >= 0; i--) {
        if (s[i] == '<') {
            cnt1++;
            mi++;
        }
        else if (s[i] == '>') {
            cnt2++;
            ma--;
        }
        else {
            cnt++;
        }
    }
    ll diff = ma - mi;
    if (s[0] == '?') {
        cout << 0 << endl;
    }
    else {
        ll res;
        if (cnt == 1) {
            res = diff + 1;
            res %= MOD;
            cout << res << endl;
        }
        else if (cnt == 2) {
            res = (diff) * (diff + 1) / 2;
            res %= MOD;
            cout << res << endl;
        }
        else {
            res = (diff) * (diff + 1) / 2;
            res %= MOD;
            res *= facmod(diff - 1);
            res %= MOD;
            cout << res << endl;
        }
    }
    for (int i = 0; i < M; i++) {
        ll x;
        char c;
        cin >> x >> c;
        if ((c == '>' || c == '<') && s[x - 1] == '?') {
            cnt--;
            diff--;
        }
        else if (c == '?' && s[x - 1] != '?') {
            cnt++;
            diff++;
        }
        if (s[x - 1] == '<') {
            cnt1--;
        }
        else if (s[x - 1] == '>') {
            cnt2--;
        }
        if (c == '<') {
            cnt1++;
        }
        else if (c == '>') {
            cnt2++;
        }
        s[x - 1] = c;
        if (s[0] == '?') {
            cout << 0 << endl;
            continue;
        }
        if (cnt1 == 0 || cnt2 == 0) {
            ll res = facmod(cnt-1);
            res %= MOD;
            cout << res << endl;
            continue;
        }
        ll res;
        if (cnt == 1) {
            res = diff + 1;
            res %= MOD;
            cout << res << endl;
        }
        else if (cnt == 2) {
            res = (diff) * (diff + 1) / 2;
            res %= MOD;
            cout << res << endl;
        }
        else {
            res = (diff) * (diff + 1) / 2;
            res %= MOD;
            res *= facmod(diff - 1);
            res %= MOD;
            cout << res << endl;
        }
    }
}