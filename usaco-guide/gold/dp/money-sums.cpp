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

int N;
int a[105];
set<int> sums;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sums.insert(0);
    for (int i = 0; i < N; i++) {
        vector<int> toAdd;
        for (auto j : sums) {
            toAdd.push_back(j + a[i]);
        }
        for (auto j : toAdd) {
            sums.insert(j);
        }
    }
    cout << sums.size() - 1 << endl;
    for (auto i : sums) {
        if (i != 0) {
            cout << i << " ";
        }
    }
}