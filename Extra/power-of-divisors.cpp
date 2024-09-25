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
#define LLONG_MAX 9223372036854775807

using namespace std;

ll MAX = LLONG_MAX;
ll X;
vector<pll> fac;

ll gcd(ll a, ll b) {
    if (b==0) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    cin >> X;
    ll ans = MAX;
    ll temp = (ll)sqrt(X);
    bool prime = true;
    for (ll i = 2; i*i <= temp; i++) {
        if (temp%i==0) {
            prime = false;
            break;
        }
    }
    if (temp*temp==X && prime) {
        ans = temp;
    }
    ll x = X;
    for (ll i = 2; i*i <= x && i <= 1e6; i++) {
        if (x%i==0) {
            ll cnt = 0;
            while (x%i==0) {
                x/=i;
                cnt++;
            }
            fac.push_back({i, cnt});
        }
    }
    // cout << "fac: " << endl;
    // for (int i = 0; i < fac.size(); i++) {
    //     cout << fac[i].first << " " << fac[i].second << endl;
    // }
    // cout << endl;
    if (x!=1) {
        fac.push_back({x, 1});
    }
    if (x == X) {
        if (ans==MAX) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
        return 0;
    }
    ll curr = fac[0].second;
    for (int i = 1; i < fac.size(); i++) {
        curr = gcd(curr, fac[i].second);
    }
    // cout << curr << endl;
    for (ll i = 1; i*i <= curr; i++) {
        if (curr%i==0) {
            ll temp = 1;
            for (int j = 0; j < fac.size(); j++) {
                temp *= (fac[j].second/(i)+1);
            }
            // cout << "i: " << i << " temp: " << temp << endl;
            if (temp==i) {
                ans = min(ans, i);
            }
            temp = 1;
            for (int j = 0; j < fac.size(); j++) {
                temp *= (fac[j].second/(curr/i)+1);
            }
            // cout << "i: " << curr/i << " temp: " << temp << endl;
            if (temp==curr/i) {
                ans = min(ans, curr/i);
            }
        }
    }
    if (ans==MAX) {
        cout << -1 << endl;
    } else {
        ll temp = 1;
        for (int i = 0; i < fac.size(); i++) {
            temp *= pow(fac[i].first, fac[i].second/ans);
        }
        cout << temp << endl;
    }
    return 0;
}