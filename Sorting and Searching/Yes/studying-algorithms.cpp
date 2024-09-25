#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    int arr[100];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        X -= arr[i];
        if (X < 0) {
            break;
        }
        ans++;
    }
    cout << ans << endl;
}