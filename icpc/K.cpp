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

int N;
int a[200001];

int main () {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]%=2;
    }
    int z = 0, o = 0;
    bool b00 = false, b01 = false, b10 = false, b11 = false;
    ll d00[200001], d01[200001], d10[200001], d11[200001];
    for (int i = 0; i < N; i++) {
        if (a[i] == 0) z++;
        else o++;
        if (!b00 && z == 3) {
            b00 = true;
            d00[i] = 1;
        }
        if (!b01 && z == 1 && o == 2 && a[i] == 1) {
            b01 = true;
            d01[i] = 1;
        }
        if (!b10 && z == 1 && o == 2 && a[i] == 0) {
            b10 = true;
            d10[i] = 1;
        }
        if (!b11 && z == 1 && o == 2) {
            b11 = true;
            d11[i] = 1;
        }
    }
}