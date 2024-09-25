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

ll T, P;
string S;

int main() {
    cin >> T;
    while (T--) {
        bool vis[1000005];
        memset(vis, false, sizeof(vis));
        cin >> S;
        cin >> P;
        deque<int> dq;
        ll N = S.length();
        ll n = S.length();
        ll sum = 0;
        bool flag = false;
        for (int i = 0; i < N; i++) {
            while (!dq.empty() && S[i] < S[dq.front()]) {
                if (sum + n >= P) {
                    flag = true;
                    break;
                }
                vis[dq.front()] = true;
                sum += n;
                n--;
                dq.pop_front();
            }
            if (flag) {
                break;
            }
            dq.push_front(i);
            // for (int j = 0; j < dq.size(); j++) {
            //     cout << dq[j] << " ";
            // }
            // cout << endl;
        }
        // cout << "vis: ";
        // for (int i = 0; i < N; i++) {
        //     cout << vis[i] << " ";
        // }
        // cout << endl;
        if (!flag) {
            while (!dq.empty()) {
                if (sum + n >= P) {
                    break;
                }
                vis[dq.front()] = true;
                sum += n;
                n--;
                dq.pop_front();
            }
        }
        // cout << "vis: ";
        // for (int i = 0; i < N; i++) {
        //     cout << vis[i] << " ";
        // }
        // cout << endl;
        // cout << "sum: " << sum << " n: " << n << endl;
        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                cnt++;
                if (cnt == P-sum) {
                    cout << S[i];
                    break;
                }
            }
        }
    }
}