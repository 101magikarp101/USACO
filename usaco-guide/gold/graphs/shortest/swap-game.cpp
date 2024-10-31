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
struct pii {int x, y;};
struct pll {int x, y;};

int T, N;
unordered_map<ll, int> dp;
ll po[10];

int main() {
    po[0] = 1;
    for (int i = 1; i < 10; i++) {
        po[i] = po[i-1]*10;
    }
    ll s = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x; cin >> x;
            s += x*((ll)pow(10, 3*i+j));
        }
    }
    dp[s] = 0;
    queue<ll> q;
    q.push(s);
    while (!q.empty()) {
        ll cur = q.front();
        q.pop();
        // cout << "cur: " << cur << " " << dp[cur] << endl;
        if (cur==987654321) break;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                ll a = cur/po[3*i+j]%10;
                ll b = cur/po[3*i+j+1]%10;
                a*=po[3*i+j];
                b*=po[3*i+j+1];
                ll n = cur-a-b+10*a+b/10;
                // cout << "n: " << n << " a: " << a << " b: " << b << endl;
                if (dp.find(n)==dp.end()) {
                    dp[n] = dp[cur]+1;
                    q.push(n);
                }
                a = cur/po[3*j+i]%10;
                b = cur/po[3*(j+1)+i]%10;
                a*=po[3*j+i];
                b*=po[3*(j+1)+i];
                n = cur-a-b+1000*a+b/1000;
                if (dp.find(n)==dp.end()) {
                    dp[n] = dp[cur]+1;
                    q.push(n);
                }
            }
        }
    }
    cout << dp[987654321] << endl;
    return 0;
}