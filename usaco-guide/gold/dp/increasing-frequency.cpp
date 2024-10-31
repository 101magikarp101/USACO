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

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define MOD2 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int N, C;
int arr[500005];
unordered_map<int, vector<int>> m;
unordered_map<int, int> cnt;

int main() {
    cin >> N >> C;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] = C-arr[i];
        if (arr[i] == 0) {
            ans++;
        }
        cnt[arr[i]] = 0;
    }
    int z = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) {
            z++;
        } else {
            if (i == 0 || arr[i-1] != arr[i]) {
                m[arr[i]].push_back(cnt[arr[i]]-z);
            }
            cnt[arr[i]]++;
            m[arr[i]].push_back(cnt[arr[i]]-z);
        }
    }
    int res = 0;
    for (auto i : m) {
        int mi = INT_MAX;
        // cout << "i.first: " << i.first << endl;
        for (int j = 0; j < i.second.size(); j++) {
            mi = min(mi, i.second[j]);
            // cout << i.second[j] << " ";
            res = max(res, i.second[j]-mi);
        }
    }
    cout << ans + res << endl;
}