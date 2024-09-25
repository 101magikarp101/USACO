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
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007
#define INT_MAX 2147483647

using namespace std;

ll N, M;
vector<pll> good;
string a[20];

ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll sub(ll a, ll b) {
    return (a - b + MOD) % MOD;
}

ll run(ll x) {
    ll sum = 1;
    ll res = 1;
    for (ll i = x; i >= 1; i--) {
        res = mult(res, i);
        sum = add(sum, res);
    }
    return sum;
}

int check(int x, int y) {
    bool HE = false;
    bool EH = false;
    for (int i = 0; i < M; i++) {
        if (a[i][x] == 'E' && a[i][y] == 'H') {
            EH = true;
        } else if (a[i][x] == 'H' && a[i][y] == 'E') {
            HE = true;
        }
    }
    if (HE && EH) {
        return 0;
    } else if (HE) {
        return -1;
    } else if (EH) {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    cin >> N >> M;
    ll E, H;
    for (int i = 0; i < M; i++) {
        E = 0;
        H = 0;
        string s;
        cin >> s;
        a[i] = s;
        // for (int j = 0; j < s.length(); j++) {
        //     if (s[j] == 'E') {
        //         E++;
        //     } else {
        //         H++;
        //     }
        // }
        // ll res = sub(mult(run(E), run(H)), 1);
        // cout << res << endl;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int res = check(i, j);
            if (res == 1) {
                good.push_back({i, j});
            } else if (res == -1) {
                good.push_back({j, i});
            } else if (res == 2) {
                good.push_back({i, j});
                good.push_back({j, i});
            }
        }
    }
    sort(good.begin(), good.end());
    cout << "good: " << endl;
    for (auto i : good) {
        cout << i.first << " " << i.second << endl;
    }
}