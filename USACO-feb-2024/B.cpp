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

int N;
ll a[500005];
ll r[500005];
ll l[500005];

int main() {
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum+=a[i];
    }
    memset(r, -1, sizeof(r));
    memset(l, -1, sizeof(l));
    deque<ll> dq;
    dq.push_back(0);
    for (int i = 1; i < N; i++) {
        while (!dq.empty() && a[dq.back()] >= a[i]) {
            r[dq.back()] = i;
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = 0; i < N; i++) {
        while (!dq.empty() && a[dq.back()] >= a[i]) {
            r[dq.back()] = i;
            dq.pop_back();
        }
        dq.push_back(i);
    }
    dq.clear();
    dq.push_back(N-1);
    for (int i = N-2; i >= 0; i--) {
        while (!dq.empty() && a[dq.back()] > a[i]) {
            l[dq.back()] = i;
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = N-1; i >= 0; i--) {
        while (!dq.empty() && a[dq.back()] > a[i]) {
            l[dq.back()] = i;
            dq.pop_back();
        }
        dq.push_back(i);
    }
    // cout << "L: ";
    // for (int i = 0; i < N; i++) {
    //     cout << l[i] << " ";
    // }
    // cout << endl;
    // cout << "R: ";
    // for (int i = 0; i < N; i++) {
    //     cout << r[i] << " ";
    // }
    // cout << endl;
    ll dp[500005];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) {
        int dist;
        if (r[i]>i) {
            dist = r[i]-i-1;
        } else {
            dist = N-i-1+r[i];
        }
        dp[0]+=a[i];
        dp[dist]-=a[i];
        // cout << "i: " << i << " dist: " << dist << endl;
        if (l[i]==-1) continue;
        int dist2;
        if (l[i]<i) {
            dist2 = i-l[i]-1;
        } else {
            dist2 = i+N-l[i]-1;
        }
        dp[dist2]-=a[i];
        dp[dist2+dist+1]+=a[i];
        // cout << "i: " << i << " dist2: " << dist2 << endl;
        // cout << "DP: ";
        // for (int i = 0; i < N; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
    }
    // cout << "DP: ";
    // for (int i = 0; i < N; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i < N; i++) {
        dp[i]+=dp[i-1];
    }
    for (int i = 1; i < N; i++) {
        dp[i]+=dp[i-1];
    }
    // cout << "DP: ";
    // for (int i = 0; i < N; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < N; i++) {
        cout << sum+dp[i] << endl;
    }
}