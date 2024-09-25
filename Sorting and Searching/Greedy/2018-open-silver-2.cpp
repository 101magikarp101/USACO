#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int N;
    cin >> N;
    int arr[100000];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N, greater<int>());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (ans <= arr[i]) {
            ans++;
        }
    }
    cout << ans << endl;
}