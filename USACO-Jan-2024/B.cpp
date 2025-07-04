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
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct state {
    int h,a,d;
};

int N, Q, C;
state arr[105];
state arr2[105];
ll dp[10005][105];
ll pre[10005][105];

ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binpow(a, b/2);
    if (b%2) return mul(mul(res, res), a);
    else return mul(res, res);
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

int main () {
    cin >> N >> Q >> C;
    for (int i = 1; i <= Q; i++) {
        cin >> arr[i].a >> arr[i].h;
    }
    sort(arr+1, arr+Q+1, [](state a, state b) {
        if (a.h == b.h) return a.a < b.a;
        return a.h < b.h;
    });
    arr[Q+1].a = N;
    arr[Q+1].h = N+1;
    int cnt = 0;
    for (int i = 1; i <= Q+1; i++) {
        if (arr[i-1].h != arr[i].h) {
            cnt++;
            arr2[cnt] = arr[i];
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (i == 1) {
            arr2[i].d = arr2[i].a;
        } else {
            arr2[i].d = arr2[i].a - arr2[i-1].h+1;
        }
    }
    for (int i = 0; i <= C; i++) {
        pre[0][i] = 1;
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = i; j <= C; j++) {
            ll res = sub(binpow(j, arr2[i].d), binpow(j-1, arr2[i].h));
            res = mul(res, binpow(j, arr2[i].h-arr2[i].a-1));
            dp[i][j] = mul(pre[i-1][j-1], res);
            pre[i][j] = add(pre[i][j-1], dp[i][j]);
        }
    }
    cout << pre[Q][C] << endl;
}