#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    int arr[200000], apartments[200000];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> apartments[i];
    }
    sort(arr, arr + N);
    sort(apartments, apartments + M);
    int i = 0, j = 0;
    int ans = 0;
    while (i < N && j < M) {
        if (abs(arr[i] - apartments[j]) <= K) {
            ans++;
            i++;
            j++;
        } else if (arr[i] < apartments[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << ans << endl;
}