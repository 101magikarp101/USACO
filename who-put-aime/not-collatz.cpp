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
#include <unordered_map>
#include <deque>
#include <climits>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string ones = "03354435543668877988";
string tens = "0066555766";
int hun = 7;
int tho = 8;

int calc(int x) {
    int res = 0;
    if (x/100000 > 0) {
        res += ones[x/100000]-'0';
        res += hun;
    }
    if ((x/1000)%100 >= 20) {
        res += tens[(x/1000)%100/10]-'0';
        res += ones[(x/1000)%100%10]-'0';
        res += tho;
    } else if ((x/1000)%100 > 0) {
        res += ones[(x/1000)%100]-'0';
        res += tho;
    }
    if (x%1000 >= 100) {
        res += ones[x%1000/100]-'0';
        res += hun;
    }
    if (x%100 >= 20) {
        res += tens[x%100/10]-'0';
        res += ones[x%10]-'0';
    } else {
        res += ones[x%100]-'0';
    }
    return res;
}

int main () {
    ll ans = 0;
    for (int i = 1; i < 1000000; i++) {
        // cout << i << " " << calc(i) << endl;
        ans += calc(i);
    }
    ans += 10;
    cout << ans << endl;
}