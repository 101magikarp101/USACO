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

ll T;
string N;

ll op(ll n) {
    return (n+2)*(n+1)/2;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        ll ans = 1;
        for (int i = 0; i < N.length(); i++) {
            ans *= op(N[i]-'0');
        }
        cout << ans << endl;
    }
}