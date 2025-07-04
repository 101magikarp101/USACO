#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>

#define ll long long

using namespace std;

int T, N, Q;
int arr[100005];
set<int> ones;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        ones.clear();
        int sum = 0;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            if (arr[i] == 1) {
                ones.insert(i);
            }
            sum += arr[i];
        }
        for (int i = 0; i < Q; i++) {
            int x;
            cin >> x;
            // cout << "sum: " << sum << endl;
            if (x==1) {
                int t;
                cin >> t;
                t = sum-t;
                if (t < 0) {
                    cout << "NO" << endl;
                    continue;
                }
                if (ones.size() == 0) {
                    if (t % 2 == 0) {
                        cout << "YES" << endl;
                    } else {
                        cout << "NO" << endl;
                    }
                    continue;
                }
                int diff = min((*ones.begin()-1)*2, (N-*ones.rbegin())*2);
                // cout << "diff: " << diff << endl;
                if (t <= diff) {
                    if (t % 2 == 0) {
                        cout << "YES" << endl;
                    } else {
                        cout << "NO" << endl;
                    }
                } else {
                    cout << "YES" << endl;
                }
            } else {
                int it, val;
                cin >> it >> val;
                sum += val-arr[it];
                arr[it] = val;
                if (val == 1) {
                    ones.insert(it);
                } else {
                    ones.erase(it);
                }
            }
        }
    }
}