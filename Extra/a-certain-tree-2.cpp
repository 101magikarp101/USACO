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
#define MOD 1000000007

using namespace std;

ll T, N;

ll binexp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}

ll mult(ll a, ll b) {return (a*b)%MOD;}

ll add(ll a, ll b) {return (a+b)%MOD;}

ll sub(ll a, ll b) {return ((a-b)%MOD+MOD)%MOD;}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        ll res = binexp(2, N);
        cout << mult(add(mult(add(N, 3), res), mult(sub(N, 3), mult(res, res))), 2) << endl;
    }
}

//cout<<m(a(m(a(N,3),r),m(s(N,3),m(r,r))),2)<<endl;