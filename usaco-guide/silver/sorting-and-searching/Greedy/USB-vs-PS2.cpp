#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int M;
    cin >> M;
    pair<int, int> arr[300000];
    for (int i = 0; i < M; i++) {
        int a;
        string b;
        cin >> a >> b;
        if (b == "USB") {
            arr[i] = {a, 0};
        } else {
            arr[i] = {a, 1};
        }
    }
    sort(arr, arr + M, [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    int num = 0;
    long long cost = 0;
    for (int i = 0; i < M; i++) {
        if (arr[i].second == 0) {
            if (A > 0) {
                A--;
                num++;
                cost += arr[i].first;
            } else if (C > 0) {
                C--;
                num++;
                cost += arr[i].first;
            }
        } else {
            if (B > 0) {
                B--;
                num++;
                cost += arr[i].first;
            } else if (C > 0) {
                C--;
                num++;
                cost += arr[i].first;
            }
        }
    }
    cout << num << " " << cost << endl;
}