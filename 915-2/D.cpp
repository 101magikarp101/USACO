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

int T, N;
int arr[1000000];
map<int, int> drops;
pii ord[1000000];

int left(int idx) {
    if (drops.size() == 0) {
        return -1;
    }
    if (idx < drops.begin()->first) {
        return drops.rbegin()->first;
    }
    auto it = drops.lower_bound(idx);
    return prev(it)->first;
}

int right(int idx) {
    if (drops.size() == 0) {
        return -1;
    }
    if (idx > drops.rbegin()->first) {
        return drops.begin()->first;
    }
    auto it = drops.upper_bound(idx);
    return it->first;
}

int plusone(int idx) {
    if (idx == N-1) {
        return 0;
    } else {
        return idx+1;
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            ord[i] = {arr[i], i};
        }
        sort(ord, ord+N);
        drops.clear();
        int ans = 0;
        int sum = N;
        for (int i = 0; i < N; i++) {
            int idx = ord[i].second;
            int l = left(idx);
            int r = right(idx);
            int d;
            int d1;
            cout << "idx: " << idx << " l: " << l << " r: " << r << endl;
            if (l == -1 && r == -1) {
                drops.insert({idx, N});
            } else {
                if (l > idx) {
                    d = N-l+idx;             
                } else {
                    d = idx-l;
                }
                sum += d*i;
                if (r < idx) {
                    d1 = N-idx+r;
                } else {
                    d1 = r-idx;
                }
                sum -= drops[r]*arr[r];
                drops[r] = d1;
                sum += drops[r]*arr[r];
            }
            ans = max(ans, sum);
            cout << "sum: " << sum << endl;
            if (arr[idx] < arr[plusone(idx)]) {
                drops.insert({idx, d});
            } else if (l != -1 && r != -1) {
                sum -= d*i;
            }
            cout << "drops: " << endl;
            for (auto it = drops.begin(); it != drops.end(); it++) {
                cout << it->first << " " << it->second << endl;
            }
            cout << endl;
        }
        cout << ans << endl;
    }
}