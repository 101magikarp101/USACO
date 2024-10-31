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

int N;
int a[200005];
vector<vector<int>> v;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    v.push_back({a[0]});
    for (int i = 1; i < N; i++) {
        int l = 0, r = v.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (v[mid].back() < a[i]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        // cout << "i: " << i << " l: " << l << endl;
        if (v[l].back() > a[i]) {
            v.push_back({a[i]});
        } else {
            v[l].push_back(a[i]);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}