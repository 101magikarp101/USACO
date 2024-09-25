#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>

#define ll long long

using namespace std;

int N, M;
pair<ll, ll> arr[100000];

bool check (ll val) {
    //cout << "val: " << val << endl;
    int index = 0;
    ll prev = arr[0].first;
    for (int i = 1; i < N; i++) {
        ll next = prev + val;
        if (next <= arr[index].second) {
            prev = next;
        } else {
            while (index < M && arr[index].second < next) {
                index++;
            }
            if (index == M) {
                return false;
            } else {
                prev = max(arr[index].first, next);
            }
        }
        //cout << "i: " << i << " prev: " << prev << endl;
    }
    return true;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr, arr + M);
    ll low = 1;
    ll high = 1000000000000000000;
    while (low < high) {
        ll mid = (low + high + 1) / 2;
        //cout << "low: " << low << " high: " << high << " mid: " << mid << endl;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << low << endl;
}