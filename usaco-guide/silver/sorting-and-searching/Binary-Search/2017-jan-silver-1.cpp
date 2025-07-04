#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>

#define ll long long

using namespace std;

int N, T;
int arr[10000];

bool check (int val) {
    multiset<int> s;
    for (int i = 0; i < val; i++) {
        s.insert(arr[i]);
    }
    for (int i = val; i < N; i++) {
        int min = *s.begin();
        s.erase(s.begin());
        if (arr[i] + min > T) {
            return false;
        }
        s.insert(arr[i] + min);
    }
    return true;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int low = 1;
    int high = N;
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