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
#define MOD 998244353

using namespace std;

ll a, b;

int main() {
    cout << "? 0 0" << endl;
    ll x = 0, y = 0;
    int res;
    cin >> res;
    for (int i = 29; i >= 0; i--) {
        cout << "? " << (x | (1 << i)) << " " << y << endl;
        int res1;
        cin >> res1;
        cout << "? " << x << " " << (y | (1 << i)) << endl;
        int res2;
        cin >> res2;
        flush(cout);
        if (res1 == res2) {
            if (res == 1) {
                a |= (1 << i);
                x |= (1 << i);
            } else if (res == -1) {
                b |= (1 << i);
                y |= (1 << i);
            }
            res = res1;
        } else {
            if (res1 == -1) {
                a |= (1 << i);
                b |= (1 << i);
                x |= (1 << i);
                y |= (1 << i);
            }
        }
    }
    cout << "! " << a << " " << b << endl;
}