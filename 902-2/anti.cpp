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

int N;
pair<ll, ll> a[100002];
bool vis[100002];
ll MOD = 998244353;
ll pow2[100002];
set<ll> s;

int main() {
    pow2[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        pow2[i] = (pow2[i-1]*2)%MOD;
    }
    cin >> N;
    for (int i = 1; i <= N; i++) {
        ll x;
        cin >> x;
        a[i] = make_pair(x, i);
    }
    sort(a+1, a+N+1, greater<pair<ll, ll>>());
    cout << "a: ";
    for (int i = 1; i <= N; i++) {
        cout << a[i].first << " " << a[i].second << endl;
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ll temp = 0;
        for (int j = 1; j*j <= a[i].second; j++) {
            if (a[i].second % j == 0) {
                if (!vis[j]) {
                    temp++;
                    vis[j] = true;
                    s.insert(j);
                }
                if (j*j != a[i].second) {
                    if (!vis[a[i].second/j]) {
                        temp++;
                        vis[a[i].second/j] = true;
                        s.insert(a[i].second/j);
                    }
                }
            }
        }
        cout << temp << endl;
        ll res = (pow2[temp]-1)*a[i].first;
        res %= MOD;
        int id = find(s.begin(), s.end(), a[i].second)
        res *= pow2[N-a[i].second];
        res %= MOD;
        res *= pow2[a[i].second-temp];
        res %= MOD;
        ans += res;
        ans %= MOD;
        cout << ans << endl;
    }
    cout << ans%MOD << endl;
}