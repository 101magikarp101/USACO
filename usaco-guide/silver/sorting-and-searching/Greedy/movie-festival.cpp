#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    pair<int, int> arr[200000];
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr, arr + N, [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    int ans = 0;
    int time = 0;
    for (int i = 0; i < N; i++) {
        if (time <= arr[i].first) {
            time = arr[i].second;
            ans++;
        }
    }
    cout << ans << endl;
}