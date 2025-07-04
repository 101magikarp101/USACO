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
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int T, N, Q;
ll a[100005];
vector<ll> b;

ll conv(ll x) {
    for (int i = 0; i < b.size(); i++) {
        if (x%(1<<b[i]) == 0) {
            x += (1<<(b[i]-1));
        }
    }
    return x;
}

int main() {
    cin >> T;
    while (T--) {
        b.clear();
        cin >> N >> Q;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < Q; i++) {
            ll x;
            cin >> x;
            if (b.empty()) {
                b.push_back(x);
            } else {
                if (x < b.back()) {
                    b.push_back(x);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            a[i] = conv(a[i]);
        }
        for (int i = 0; i < N; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}