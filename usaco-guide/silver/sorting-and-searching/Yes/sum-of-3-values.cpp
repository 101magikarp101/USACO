#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<long long, vector<long long>> m;
    long long n, x;
    cin >> n >> x;
    long long arr[5001];
    for (long long i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        m[a].push_back(i);
        arr[i-1] = a;
    }
    sort(arr, arr + n);
    // cout << "arr: ";
    // for (long long i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    long long ans[3];
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            long long sum = arr[i] + arr[l] + arr[r];
            if (sum == x) {
                ans[0] = m[arr[i]][0];
                m[arr[i]].erase(m[arr[i]].begin());
                ans[1] = m[arr[l]][0];
                m[arr[l]].erase(m[arr[l]].begin());
                ans[2] = m[arr[r]][0];
                m[arr[r]].erase(m[arr[r]].begin());
                sort(ans, ans + 3);
                cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
                return 0;
            } else if (sum < x) {
                l++;
            } else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}