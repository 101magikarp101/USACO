#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int N, M, R;
    cin >> N >> M >> R;
    long long n[100000], r[100000];
    pair<long long, long long> m[100000];
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        m[i] = {a, b};
    }
    for (int i = 0; i < R; i++) {
        cin >> r[i];
    }
    sort(n, n + N, greater<int>());
    sort(m, m + M, [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first > b.first;
        } else {
            return a.second > b.second;
        }
    });
    sort(r, r + R);
    long long prefix[100000], prefix1[100000];
    int index = 0;
    for (int i = 0; i < N; i++) {
        long long profit = 0;
        long long milk = n[i];
        while (milk > 0) {
            long long temp = min(milk, m[index].first);
            milk -= temp;
            m[index].first -= temp;
            profit += temp * m[index].second;
            if (m[index].first == 0) {
                index++;
            }
            if (index >= M) {
                break;
            }
        }
        prefix[i] = profit;
        // cout << "prefix: ";
        // for (int i = 0; i < N; i++) {
        //     cout << prefix[i] << " ";
        // }
        // cout << endl;
        if (i > 0) {
            prefix[i] += prefix[i - 1];
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        if (R-N+i < 0) {
            prefix1[i] = 0;
        } else {
            prefix1[i] = r[R - N + i];
        }
        if (i < N - 1) {
            prefix1[i] += prefix1[i + 1];
        }
    }
    // cout << "prefix: ";
    // for (int i = 0; i < N; i++) {
    //     cout << prefix[i] << " ";
    // }
    // cout << endl;
    // cout << "prefix1: ";
    // for (int i = 0; i < N; i++) {
    //     cout << prefix1[i] << " ";
    // }
    // cout << endl;
    long long max = 0;
    for (int i = 0; i <= N; i++) {
        long long temp = 0;
        if (i >= 1) {
            temp += prefix[i-1];
        }
        if (i < N) {
            temp += prefix1[i];
        }
        if (temp > max) {
            max = temp;
        }
    }
    cout << max << endl;
}