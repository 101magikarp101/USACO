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
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define LLONG_MAX 9223372036854775807
#define LLONG_MIN -9223372036854775808
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

int N;
pll A[100005];
pll B[100005];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        A[i] = {x*(i+1)*(N-i), i};
    }
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        B[i] = {x, i};
    }
    sort(A, A+N, greater<pll>());
    sort(B, B+N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i].first*B[i].first;
    }
    cout << ans << endl;
}