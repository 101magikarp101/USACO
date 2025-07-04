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

int N, K;
bool vis[500005];
int a[500005], b[500005];
int ans = -1;

int num_match(int n) {
    int cnt = 0;
    for (int i = 0; i < K; i++) {
        if (a[i] == b[(i+n)%K]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> a[i];
        vis[a[i]] = true;
    }
    for (int i = 0; i < K; i++) {
        cin >> b[i];
        vis[b[i]] = true;
    }
    for (int i = 0; i < K; i++) {
        ans = max(ans, num_match(i));
    }
    reverse(b, b+K);
    for (int i = 0; i < K; i++) {
        ans = max(ans, num_match(i));
    }
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            ans++;
        }
    }
    cout << ans << endl;
}