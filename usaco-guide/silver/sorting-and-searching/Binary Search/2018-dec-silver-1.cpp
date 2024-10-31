#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>

#define ll long long

using namespace std;

int N, M, C;
int arr[100000];

bool check (int val) {
    int total = 0;
    int count = 0;
    int last = 0;
    for (int i = 0; i < N; i++) {
        if (count == 0) {
            last = arr[i];
        }
        count++;
        if (arr[i] - last > val) {
            total++;
            count = 1;
            last = arr[i];
        } else if (arr[i] - last == val) {
            total++;
            count = 0;
            last = -1;
        } else if (count == C) {
            total++;
            count = 0;
            last = -1;
        } 
        //cout << "i: " << i << " arr[i]: " << arr[i] << " last: " << last << " count: " << count << " total: " << total << endl;
    }
    if (count > 0) {
        total++;
    }
    //cout << "val: " << val << " total: " << total << endl;
    return total <= M;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> N >> M >> C;
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