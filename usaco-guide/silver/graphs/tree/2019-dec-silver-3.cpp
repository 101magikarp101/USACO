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

struct cat{
    int a, b; //region, type
};

int N, M;
cat c[100005];
vector<int> adj[100005];
int arr[100005];

void fill (int n, int r, int t) {
    c[n] = {r, t};
    for (int i : adj[n]) {
        if (c[i].a == -1 && arr[i] == t) {
            fill(i, r, t);
        }
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> N >> M;
    string s;
    cin >> s;
    for (int i = 1; i <= N; i++) {
        arr[i] = s[i-1]-'G';
    }
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        c[i] = {-1, -1};
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (c[i].a == -1) {
            fill(i, cnt, arr[i]);
            cnt++;
        }
    }
    // cout << "c: ";
    // for (int i = 1; i <= N; i++) {
    //     cout << c[i].a << " " << c[i].b << endl;
    // }
    for (int i = 0; i < M; i++) {
        int x, y;
        char z;
        cin >> x >> y >> z;
        int a = z-'G';
        if (c[x].a == c[y].a) {
            if (c[x].b == a && c[y].b == a) {
                cout << 1;
            } else {
                cout << 0;
            }
        } else {
            cout << 1;
        }
    }
    cout << endl;
}