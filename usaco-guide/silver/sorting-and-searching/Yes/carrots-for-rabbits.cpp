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
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int N, K;
priority_queue<part, vector<part>, greater<part>> pq;

struct part{
    ll val, n, m;
};

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        pq.push(new part{x*x, x, 1});
    }
    ll ans = 0;
    for (int i = N; i < K; i++) {
        part p = pq.top();
        pq.pop();
        pq.push(new part{p.val+p.n*p.n, p.n, p.m+1});
    }
}