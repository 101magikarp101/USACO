#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>

#define ll long long

using namespace std;

int N, K;
int arr[50000];

bool check (int val) {
    int total = 1;
    int last = arr[0];
    for (int i = 0; i < N; i++) {
        if (arr[i] - last > 2*val) {
            total++;
            last = arr[i];
        }
    }
    //cout << "val: " << val << " total: " << total << endl;
    return total <= K;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int low = 0;
    int high = 1000000000;
    while (low < high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
}