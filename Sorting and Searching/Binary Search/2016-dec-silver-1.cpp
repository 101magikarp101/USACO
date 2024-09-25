#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>

#define ll long long

using namespace std;

int N, Q;
int arr[100000];

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        auto it = lower_bound(arr, arr + N, l);
        auto it2 = upper_bound(arr, arr + N, r);
        cout << it2 - it << endl;
    }
}