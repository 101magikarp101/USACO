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
    int arr[200000];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int mid = arr[N / 2];
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(arr[i] - mid);
    }
    cout << ans << endl;
}