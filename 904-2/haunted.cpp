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

int T, N;

int main(){
    cin >> T;
    while (T--) {
        cin >> N;
        string s;
        cin >> s;
        ll ans[100001];
        memset(ans, -1, sizeof(ans));
        ans[0] = 0;
        ll sum = 0;
        ll cnt = 1;
        for (int i = 0; i < N; i++) {
            if (s[N-i-1] == '1') {
                sum++;
            } else {
                ans[cnt] = ans[cnt-1] + sum;
                cnt++;
            }
        }
        for (int i = 1; i <= N; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}